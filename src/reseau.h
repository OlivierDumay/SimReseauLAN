
enum type_machine{
  TYPE_STATION ,
  TYPE_SWITCH 
}

union machine {
    station station;
    sWitch switch;
}

struct element_tabMachine{
    type_machine type;
    machine donnee;
}
struct reseau{
    element_tabMachine tabSommet[];
    // tab[0].type = TYPE_STATION
    // tab[0].adrMac =...
    // tab[0].adrIP=...
    //
    // tab[1].type = TYPE_SWITCH;
    // tab[1].adrMac = ...;
    // tab[1].nbPort = ...;
    // tab[1].priorite = ..;
    // tab[1].tabCommu = .. ;
    

}



getNombreMachine()
getNombreConnexion()