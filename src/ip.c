#include "ip.h"

#include <string.h>

void lireIP(const char* ligne)
{


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