#include "ip.h"
#include "mac.h"
#include "reseau.h"
#include "station.h"
#include "switch.h"
#include <string.h>
#include <stdio.h>

int main() {
    
    reseau reseau1;
    initReseau(&reseau1);

    station station1;
    mac mac1 = {10,2,30,4,50,6};
    memcpy(station1.adrMac, mac1, sizeof(mac));
    machine_t machine1;
    machine1.type = TYPE_STATION;
    machine1.donnee.station = station1;

    station station2;
    mac mac2 = {1,20,3,40,5,60};
    memcpy(station2.adrMac, mac2, sizeof(mac));
    machine_t machine2;
    machine2.type = TYPE_STATION;
    machine2.donnee.station = station2;
    lien l = initLien(machine1, machine2, 4);
    

    ajouterMachine(&reseau1, machine1);
    ajouterMachine(&reseau1, machine2);
    ajouterLien(&reseau1, l);

    affichageReseau(&reseau1);

    deinitReseau(&reseau1);



    return 0;
}