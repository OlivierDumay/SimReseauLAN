#include "reseau.h"

void initReseau(reseau* r)
{
    // initialise les champs
    r-> nb_machine = 0;
    r -> nb_lien = 0;
    r -> lien_capacite = 8;
    r -> machine_capacite = 8;
    r -> tabLien = malloc (sizeof(lien) * r->lien_capacite);
    r -> tabMachine = malloc (sizeof(machine_t) * r->machine_capacite);
}
void deinitReseau(reseau* r)
{
    free (r->tabLien);
    free (r->tabMachine);
}
void affichageReseau(reseau* r)
{
    printf("%u %u", r->nb_machine, r->nb_lien); // entete

    // afficher les switchs (2)
    for (int i =0; i < r->nb_machine; i++) //mac, nbport, prio
    {
        if (r->tabMachine[i].type == TYPE_SWITCH)
        {
            char ligne[64]; // a voir si taille cohérente
            strcat(ligne, "2;");
            strcat(ligne, ecrireMAC(r->tabMachine[i].donnee.switchs.adrMac));
            strcat(ligne, ";");
            char buffer[8];
            sprintf(buffer, "%u", r->tabMachine[i].donnee.switchs.nbPort);
            strcat(ligne, buffer);
            sprintf(buffer, "%u", r->tabMachine[i].donnee.switchs.priorite);
            strcat(ligne, buffer);
            printf("%s", ligne);
            continue;
        }
    }
    // afficher les station (1)
    for (int i =0; i < r->nb_machine; i++) //mac, ip
    {
        if (r->tabMachine[i].type == TYPE_STATION)
        {
            char ligne[64]; // a voir si taille cohérente
            strcat(ligne, "1;");
            strcat(ligne, ecrireMAC(r->tabMachine[i].donnee.station.adrMac));
            strcat(ligne, ";");
            strcat(ligne, ecrireIP(r->tabMachine[i].donnee.station.adrIp));
            printf("%s", ligne);
            continue;
        }
    }


    //afficher les liens
    bool lienPasse[r->nb_lien]; // creation d'un tableau qui verifie si on a deja afficher le lien ( a cause des croisement)
    for (int i =0; i < r->nb_lien; i++) { lienPasse[i] = false; }

    machine_t* tMach = r->tabMachine; // QUESTION PROF, COPIE PROFONDE OU PAS?
    lien* tLien = r->tabLien;

    uint8_t compteurDesSwitchs = -1;
    for (int i =0; i < r->nb_machine; i++) // on parcours toutes les machines de type switch d'abord
    {
        if (tMach[i].type == TYPE_SWITCH) // selection des switch
        {
            compteurDesSwitchs ++; // index des switch seulement, pour avoir le meme index que le fichier de configuration
            for (int j = 0; j < r->nb_lien; j++) // parcours de tous les liens, pour chercher si le switch y est 
            {
                if (machineEquals(tMach[i], tLien->machine_1)) 
                {
                    machine_t MachAChercher = tLien->machine_2;
                    uint8_t compteurMachAChercher = 0;
                    for (int k =0; k < tMach; k++) // on parcours encore les machine pour trouver l'index de la machine, index du fichier de configuration, pas index de tabMachine
                    {
                        if (machineEqualsType(tMach[k], MachAChercher)) // increment du compteur le l'index selon le type
                        {
                            compteurMachAChercher++;
                            if(machineEquals(tMach[k], MachAChercher)){break;} // si on a trouver la machine, on stop la boucle ( cest un tant que en fait)
                        }
                    }
                    // maintenant qu'on à l'index suivant le type, si l'autre machine du lien est une station, il faut ajouter le nombre de switch
                    if (MachAChercher.type == TYPE_STATION)
                    {
                        compteurMachAChercher+= compteurDesSwitchs;
                    }

                    printf ("%u;%u;%u", compteurDesSwitchs, compteurMachAChercher, tLien[j].poids);
                }
                if (machineEquals(tMach[i], tLien->machine_2)) // idem sauf que la machine a chercher est differente
                 {
                    machine_t MachAChercher = tLien->machine_1; // ici la différence
                    uint8_t compteurMachAChercher = 0;
                    for (int k =0; k < tMach; k++) // on parcours encore les machine pour trouver l'index de la machine, index du fichier de configuration, pas index de tabMachine
                    {
                        if (machineEqualsType(tMach[k], MachAChercher)) // increment du compteur le l'index selon le type
                        {
                            compteurMachAChercher++;
                            if(machineEquals(tMach[k], MachAChercher)){break;} // si on a trouver la machine, on stop la boucle ( cest un tant que en fait)
                        }
                    }
                    // maintenant qu'on à l'index suivant le type, si l'autre machine du lien est une station, il faut ajouter le nombre de switch
                    if (MachAChercher.type == TYPE_STATION)
                    {
                        compteurMachAChercher+= compteurDesSwitchs;
                    }

                    printf ("%u;%u;%u", compteurDesSwitchs, compteurMachAChercher, tLien[j].poids);
                }
            }
        }
    }

}


machine_t initMachineStation (station s) // la station doit etre initialisé avant
{
    machine_t m;
    m.type = TYPE_STATION;
    m.donnee.station = s;
    return m;
}
machine_t initMachineSwitch (switch_t s) // la station doit etre initialisé avant
{
    machine_t m;
    m.type = TYPE_SWITCH;
    m.donnee.switchs = s;
    return m;
}
uint8_t getNombreMachine(reseau* const r)
{
    return r->nb_machine;
}
void ajouterMachine (reseau* r, machine_t m) // manque l'augementation de tabMachine au besoin
{
    r->tabMachine[r->nb_machine] = m;
    r->nb_machine++;
}
bool machineEquals (machine_t m1, machine_t m2)
{
    if (machineEqualsType(m1, m2))
    {
        if (m1.type = TYPE_STATION)
        {
            if (m1.donnee.station.adrMac == m2.donnee.station.adrMac) {return true;}   
        }
        if (m1.type == TYPE_SWITCH)
        {
            if (m1.donnee.switchs.adrMac == m2.donnee.switchs.adrMac) {return true;}
        }
    }
    return false;
}
bool machineEqualsType (machine_t m1, machine_t m2)
{
        if (m1.type != m2.type) {return false;}
        return true;
}


lien initLien(machine_t m1, machine_t m2, uint8_t poids)
{
    lien l;
    l.machine_1 = m1;
    l.machine_2 = m2;
    l.poids = poids;
    return l;
}
uint8_t getNombreConnexion(reseau* const r)
{
    return r->nb_lien;
}
bool existeLien (reseau* const r, lien l)
{
    for (size_t i =0; i < r ->nb_lien; i++)
    {
        if (lienEquals(r->tabLien[i], l)) {return true;}
    }
    return false;
}
void ajouterLien (reseau* const r, lien l) // manque l'augementation de tabLien au besoin
{
    r->tabLien[r->nb_lien] = l;
    r->nb_lien ++; 
}
bool lienEquals (lien l1, lien l2)
{
    machine_t l1m1 = l1.machine_1;
    machine_t l1m2 = l1.machine_2;
    machine_t l2m1 = l2.machine_1;
    machine_t l2m2 = l2.machine_2;

    // cas 1: l1.m1 == l2.m1 et l1.m2 == l2.m2
    if (machineEquals(l1m1, l2m1) && machineEquals(l1m2, l2m2)) {return true;}
    // cas 2: l1.m1 == l2.m2 et l1.m2 == l2.m1
    if (machineEquals(l1m1, l2m2) && machineEquals(l1m2, l2m1)) {return true;}
    return false;
}
