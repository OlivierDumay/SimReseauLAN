# Simulation de réseau LAN en C

Projet d'étude - 1ère année BUT Info, encadré par des enseignants et codé dans un cadre scolaire, réalisé en trinôme.



Concevoir en C un réséau d'objets connectés et s'échangeant des messages (avec des caractéristique de machine emmeteur/récepteur ou de switch).
Pour y appliquer un protocole Ethernet et STP.

Voir [sujet.pdf](documents/sujet.pdf)

Les information d'un réseau sont dans un fichier texte, au format de [mylan.lan](documents/mylan.lan) ou [mylan_nocycle.lan](documents/mylan_nocycle.lan)

## Statut du projet

Le réseau virtuel peut être construit mais il manque les protocoles. 

# Comment éxécuter le code

### Cloner le depot sur sa machine:

```bash
    git clone https://github.com/OlivierDumay/SimReseauLAN.git
```

Dans le fichier src/main.c, ligne 37, écrire l'emplacement de son fichier d'information du réseau

- Compiler: 
```bash
make
```
- Executer: 
```bash
./sae21
```

###
