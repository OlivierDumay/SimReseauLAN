#include "traduction.h"



void uint8versStringHexadecimal (uint8_t octet, char buffer[3])
{
    sprintf(buffer, "%02X", octet);

}