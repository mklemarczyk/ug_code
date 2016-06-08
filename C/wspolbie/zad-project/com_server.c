#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void main(){
	
	printf("Witaj\n");
	
	struct sockaddr_in ip4addr;
	bzero((char *) &ip4addr, sizeof(ip4addr));
	ip4addr.sin_family = AF_INET;
	ip4addr.sin_port = htons((ushort) 5000);
	ip4addr.sin_addr.s_addr=htonl(INADDR_ANY);

	int fromlen;
	fromlen = sizeof(struct sockaddr_in);

	int s;
	s = socket(PF_INET, SOCK_DGRAM, 0x0);

	bind(s, (struct sockaddr*) &ip4addr, fromlen);

	while(1){
		int buff;
		int byte_count;
		
		byte_count = recvfrom(s, (char *)&buff, sizeof(buff), 0x0, (struct sockaddr*) &ip4addr, &fromlen);
		buff = ntohl(buff);
		
		printf("Liczba: %d\n", buff);

		int bb = (buff & 0x1);
		printf("Wiadomosc wyslana: [%d]\n", bb);

		buff = (buff << 0x1) - ((buff << 0x1F) >> 0x1F);// x*2 + 1 + (x+1)%2

		printf("Wiadomosc wyslana: [%d]\n", buff);
		
		buff = htonl(buff);
		sendto(s, (char *)&buff, sizeof(buff), 0x0, (struct sockaddr*) &ip4addr, fromlen);
	}
}           
       






