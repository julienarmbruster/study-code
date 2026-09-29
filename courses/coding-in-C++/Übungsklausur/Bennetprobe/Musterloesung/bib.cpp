#include "bib.hpp"

#include <iostream>
#include <iomanip>

// Definition der statischen Attribute (genau einmal, in der .cpp).
int Media::nextId = 0;
int Member::nextId = 0;

namespace {
    // Einheitliche Spaltenbreite fuer die zweispaltige Tabelle.
    constexpr int kLabelWidth = 16;
}

// ---------------------------------------------------------------------
//  Media
// ---------------------------------------------------------------------
Media::Media(const std::string& title, const std::string& requiredAccess)
    : id(++nextId),
      title(title),
      available(true),          // neu erstellte Medien sind verfuegbar
      requiredAccess(requiredAccess),
      activeCustomer(nullptr) {} // und haben kein ausleihendes Mitglied

void Media::printFooter() const {
    std::cout << std::left << std::setw(kLabelWidth) << "Available"
              << (available ? "Yes" : "No") << '\n';
    std::cout << std::left << std::setw(kLabelWidth) << "Required Access"
              << requiredAccess << '\n';
    std::cout << std::left << std::setw(kLabelWidth) << "Borrowed By"
              << (activeCustomer ? activeCustomer->getName() : "None") << '\n';
    std::cout << std::string(50, '-') << '\n';
}

// ---------------------------------------------------------------------
//  EBook
// ---------------------------------------------------------------------
EBook::EBook(const std::string& title, const std::string& requiredAccess, double fileSizeMb)
    : Media(title, requiredAccess), fileSizeMb(fileSizeMb) {}

void EBook::printInfo() const {
    std::cout << std::left << std::setw(kLabelWidth) << "Type" << "E-Book" << '\n';
    std::cout << std::left << std::setw(kLabelWidth) << "Title" << title << '\n';
    std::cout << std::left << std::setw(kLabelWidth) << "File Size"
              << fileSizeMb << " MB" << '\n';
    printFooter();
}

// ---------------------------------------------------------------------
//  Audiobook
// ---------------------------------------------------------------------
Audiobook::Audiobook(const std::string& title, const std::string& requiredAccess, double durationMin)
    : Media(title, requiredAccess), durationMin(durationMin) {}

void Audiobook::printInfo() const {
    std::cout << std::left << std::setw(kLabelWidth) << "Type" << "Audiobook" << '\n';
    std::cout << std::left << std::setw(kLabelWidth) << "Title" << title << '\n';
    std::cout << std::left << std::setw(kLabelWidth) << "Duration"
              << durationMin << " min" << '\n';
    printFooter();
}

// ---------------------------------------------------------------------
//  Member
// ---------------------------------------------------------------------
Member::Member(const std::string& name)
    : id(++nextId), name(name), hasBorrowedItem(false) {}

void Member::addRight(const std::string& right) {
    accessRights.insert(right);
}

void Member::removeRight(const std::string& right) {
    accessRights.erase(right);
}

bool Member::hasRight(const std::string& right) const {
    return accessRights.count(right) > 0;
}

bool Member::rentMedia(Media* media) {
    if (media == nullptr) {
        return false;
    }
    // Bedingung 1: Medium muss verfuegbar sein.
    if (!media->isAvailable()) {
        return false;
    }
    // Bedingung 2: Mitglied darf noch kein anderes Medium ausgeliehen haben.
    if (hasBorrowedItem) {
        return false;
    }
    // Bedingung 3: Mitglied muss die erforderliche Zugriffsberechtigung besitzen.
    if (!hasRight(media->getRequiredAccess())) {
        return false;
    }

    media->setActiveCustomer(this);
    media->setAvailable(false);
    hasBorrowedItem = true;
    return true;
}

bool Member::returnMedia(Media* media) {
    // Rueckgabe nur moeglich, wenn dieses Mitglied das Medium ausgeliehen hat.
    if (media == nullptr || media->getActiveCustomer() != this) {
        return false;
    }
    media->setActiveCustomer(nullptr);
    media->setAvailable(true);
    hasBorrowedItem = false;
    return true;
}
