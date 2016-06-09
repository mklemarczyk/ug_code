#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void main(){
	
	printf("Witaj\n");

	int ip4addrSize;
	ip4addrSize = sizeof(struct sockaddr_in);

	int s;
	s = socket(PF_INET, SOCK_DGRAM, 0x0);

	struct sockaddr_in ip4addr;
	bzero((char *) &ip4addr, sizeof(ip4addr));
	ip4addr.sin_family = AF_INET;
	ip4addr.sin_port = htons((ushort) 5000);
	inet_pton(AF_INET, "192.168.1.143", &ip4addr.sin_addr);

	bind(s, (struct sockaddr*) &ip4addr, ip4addrSize);

	int msg;
	printf("Podaj liczbe: ");
	scanf("%d", &msg);

	int buff = htonl(msg);
	sendto(s, (char *)&buff, sizeof(buff), 0x0, (struct sockaddr*) &ip4addr, ip4addrSize);

	printf("Wiadomosc wyslana: [%d]\n", msg);

	int byte_count;
	byte_count = recvfrom(s, (char *)&buff, sizeof(buff), 0x0, (struct sockaddr*) &ip4addr, &ip4addrSize);
	buff = ntohl(buff);
	
	printf("Liczba: %d\n", buff);
}           
       






