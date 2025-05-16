typedef int8_t ip[8];

void afficherIP(ip adr)
{
  printf("%x,%x,%x,%x,%x,%x,%x,%x",adr[0],adr[1],adr[2],adr[3],adr[4],adr[5],adr[6],adr[7]);
}

ip lireIP(char* ligne)

char* ecrireIP(ip adr)

bool equals(ip, ip)