#ifndef IP_H
#define IP_H

// Definition d'une adresse IP
#include <stdint.h> // Pour int8_t
#include <stdio.h>  // Pour printf
#include <stdbool.h> // Pour bool

#include "traduction.h"

typedef int8_t ip[4];

// Affiche l'adresse IP (format : a.b.c.d)
void afficherIP(ip adr);

// Affichage sans possibilité de modification grâce à const
void lireIP(const char* ligne);

// Retourne une chaîne (char*) représentant l'adresse IP (à libérer par l'appelant)
char* ecrireIP(ip adr);

// Compare deux adresses IP, retourne true si elles sont identiques
bool ip_equals(ip a, ip b);

#endif // IP_H