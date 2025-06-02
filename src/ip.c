#include "ip.h"

#include <string.h>

// adresse contient maintenant {a, b, c, d}
void lireIP(const char* ligne, ip adr)
{
    int a, b, c, d;
    sscanf(ligne, "%d.%d.%d.%d", &a, &b, &c, &d);
    adr[0] = a;
    adr[1] = b;
    adr[2] = c;
    adr[3] = d;
}

char* ecrireIP(ip adr)
{
    char* ret;

    strcat(ret, adr[0]);
    strcat(ret, ";");
    strcat(ret, adr[1]);
    strcat(ret, ";");
    strcat(ret, adr[2]);
    strcat(ret, ";");
    strcat(ret, adr[3]);
    strcat(ret, ";");

    return ret;
}

bool ip_equals(ip a, ip b)
{
    for (int i = 0; i < 4; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void afficherIP(ip adr)
{
    printf("%d.%d.%d.%d", adr[0], adr[1], adr[2], adr[3]);
}
