#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "ip.h"
#include "mac.h"

typedef struct data{ // 46 octets minimum
    uint8_t* data; // 0 à 1500 octets
    uint8_t* bourrage; // 0 à 46 octets
} data;

typedef struct trameEthernet {
    uint8_t* preambule; // 7 octets (10101010)
    uint8_t sfd; // 1 octet (10101011)
    mac destination; // adrMac 6 octet
    mac source; // adrMac 6 octet
    uint8_t* type; // 2 octets (ipv4, ipv6, ARP)
    uint8_t* data; // 0 à 1500 octets
    uint8_t* bourrage; // 0 à 46 octets
    uint8_t* fcs; // 4 octets
}trameEthernet;

void affichageTrame (trameEthernet trame);