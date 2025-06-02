    #pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "station.h"
#include "switch.h"
#include "ip.h"
#include "mac.h"
#include "traduction.h"

// def enumeration de machine, pour test le type de l'union machine_u
typedef enum machine_e{
  TYPE_STATION ,
  TYPE_SWITCH 
} machine_e;

// def union de type station et type switch
typedef union machine_u {
    station station;
    switch_t switchs;
}machine_u ;

//def structure qui joint les types station et switch
typedef struct machine_t{
    machine_e type;
    machine_u donnee;
}machine_t;


// def de lien entre les machines (arete)
typedef struct lien {   // est-ce qu'il faut mettre le poids du lien en attribut?
    machine_t machine_1;
    machine_t machine_2;
    uint8_t poids; // 4,19 ou 100
}lien;

// def reseau (graphe)
typedef struct reseau{
    uint8_t nb_machine;
    uint8_t nb_lien;
    uint8_t lien_capacite;
    uint8_t machine_capacite;
    lien* tabLien;
    machine_t* tabMachine;
    // tab[0].type = TYPE_STATION
    // tab[0].donnee.station.adrMac =...
    // tab[0].donnee.station.adrIP=...
    //
    // tab[1].type = TYPE_SWITCH;
    // tab[1].donnee.switch.adrMac = ...;
    // tab[1].donnee.switch.nbPort = ...;
    // tab[1].donnee.switch.priorite = ..;
    // tab[1].donnee.switch.tabCommu = .. ;
    

}reseau;

void initReseau(reseau* r);
void deinitReseau(reseau* r);
void affichageReseau(reseau* r);

machine_t initMachineStation (station s); 
machine_t initMachineSwitch (switch_t s);
uint8_t getNombreMachine(reseau* const r);
void ajouterMachine (reseau* const r, machine_t m);
bool machineEquals (machine_t m1, machine_t m2);
bool machineEqualsType (machine_t m1, machine_t m2);

lien initLien(machine_t m1, machine_t m2, uint8_t poids);
uint8_t getNombreConnexion(reseau* const r);
bool existeLien (reseau* const r, lien l);
void ajouterLien (reseau* const r, lien l);
bool lienEquals (lien l1, lien l2);


/*Question prof:
-pour lienEquals, est ce que l'argment lien doit etre un lien*
idem pour machineEquals et initMachine...
*/