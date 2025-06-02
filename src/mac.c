#include "mac.h"

#include <string.h>

void lireMAC(const char* ligne)
{

}

char* ecrireMAC(mac adr)
{
    char ret[15];
    for (int i = 0; i<6; i++)
    {
        char buffer[3];
        uint8versStringHexadecimal(adr[i], &buffer);
        strcat(ret, buffer);
        if (i < 4) {strcat(ret, ";");}
    }
}