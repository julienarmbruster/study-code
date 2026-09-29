#ifndef BIB_HPP
#define BIB_HPP

#include <string>
#include <vector>
#include <set>
#include <memory>
#include <cstddef>

// Vorwaertsdeklaration, damit Media einen Member* halten kann und
// umgekehrt Member ein Media* verarbeiten kann (zyklische Abhaengigkeit).
class Member;

// =====================================================================
//  Media  (abstrakte Basisklasse)
// =====================================================================
class Media {
protected:
    static int nextId;            // statisches Attribut -> vergibt eindeutige IDs
    const int id;                 // eindeutig, wird nur einmal gesetzt (readonly)
    std::string title;
    bool available;               // true = verfuegbar, false = ausgeliehen
    std::string requiredAccess;   // z. B. "Standard", "Fachbereich", "Premium"
    Member* activeCustomer;       // nicht-besitzender Beobachter-Zeiger (kann nullptr sein)

    // Gemeinsamer Teil der Tabellenausgabe (Available / Required Access / Borrowed By).
    void printFooter() const;

public:
    Media(const std::string& title, const std::string& requiredAccess);
    virtual ~Media() = default;   // virtueller Destruktor -> korrekte Zerstoerung ueber Basiszeiger

    virtual void printInfo() const = 0;  // rein virtuell -> Media ist abstrakt

    // --- Getter (const-korrekt) ---
    int getId() const { return id; }
    const std::string& getTitle() const { return title; }
    bool isAvailable() const { return available; }
    const std::string& getRequiredAccess() const { return requiredAccess; }
    Member* getActiveCustomer() const { return activeCustomer; }

    // --- Setter ---
    void setAvailable(bool value) { available = value; }
    void setActiveCustomer(Member* customer) { activeCustomer = customer; }
};

// =====================================================================
//  EBook
// =====================================================================
class EBook : public Media {
private:
    double fileSizeMb;

public:
    EBook(const std::string& title, const std::string& requiredAccess, double fileSizeMb);
    void printInfo() const override;

    double getFileSizeMb() const { return fileSizeMb; }
    void setFileSizeMb(double value) { fileSizeMb = value; }
};

// =====================================================================
//  Audiobook (frueher "Hearbook")
// =====================================================================
class Audiobook : public Media {
private:
    double durationMin;

public:
    Audiobook(const std::string& title, const std::string& requiredAccess, double durationMin);
    void printInfo() const override;

    double getDurationMin() const { return durationMin; }
    void setDurationMin(double value) { durationMin = value; }
};

// =====================================================================
//  Member
// =====================================================================
class Member {
private:
    static int nextId;                  // statisches Attribut
    const int id;                       // eindeutig, readonly
    std::string name;
    std::set<std::string> accessRights; // geordnet + effizient durchsuchbar (O(log n))
    bool hasBorrowedItem;               // true, wenn aktuell ein Medium ausgeliehen ist

public:
    explicit Member(const std::string& name);

    // --- Berechtigungen ---
    void addRight(const std::string& right);
    void removeRight(const std::string& right);
    bool hasRight(const std::string& right) const;

    // --- Ausleih-Logik ---
    // Prueft alle Bedingungen; gibt true bei Erfolg, false bei Verletzung zurueck.
    bool rentMedia(Media* media);
    bool returnMedia(Media* media);

    // --- Getter ---
    int getId() const { return id; }
    const std::string& getName() const { return name; }
    bool hasBorrowed() const { return hasBorrowedItem; }
};

// =====================================================================
//  Administration<T>  (generische, wiederverwendbare Verwaltungsklasse)
//  Voraussetzung an T: besitzt eine Methode  int getId() const
// =====================================================================
template <typename T>
class Administration {
private:
    std::vector<std::unique_ptr<T>> elements;  // Smart Pointer -> kein manuelles delete

public:
    // Hinzufuegen eines neuen Elements (Eigentum geht an die Verwaltung ueber).
    void add(std::unique_ptr<T> element) {
        elements.push_back(std::move(element));
    }

    // Anzahl der gespeicherten Elemente.
    std::size_t count() const {
        return elements.size();
    }

    // Suchen anhand der ID. Liefert einen Beobachter-Zeiger oder nullptr.
    T* findById(int id) const {
        for (const auto& element : elements) {
            if (element->getId() == id) {
                return element.get();
            }
        }
        return nullptr;
    }

    // Zugriff fuer die Iteration (z. B. um alle Elemente auszugeben).
    const std::vector<std::unique_ptr<T>>& getAll() const {
        return elements;
    }
};

#endif // BIB_HPP
