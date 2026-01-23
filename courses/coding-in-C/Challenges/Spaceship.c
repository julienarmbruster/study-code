#include <stdio.h>
char Klasse[100];
int Besatzung, Missionstage;
long long Kilometer = 574635873268;
float ProzentLicht = 67.1, Reichweite = 123456.789;

int main() {
    printf("Bitte Klasse eingeben:\n");
    scanf("%s", Klasse);
    printf("\nBitte Anzahl der Besatzung eingeben:\n");
    scanf("%d", &Besatzung);
    printf("\nBitte Anzahl der Missionstage eingeben:\n");
    scanf("%d", &Missionstage);


    printf("Name                 Value\n");
    printf("---------------------------------\n");
    printf("Klasse               %s\n", Klasse);
    printf("Besatzung            %d\n", Besatzung);
    printf("Missionstage         %d\n", Missionstage);
    printf("Kilometer            %lld\n", Kilometer);
    printf("%% of Lightspeed      %2.1f\n", ProzentLicht);
    printf("Reichweite           %8.3f\n", Reichweite);

}
