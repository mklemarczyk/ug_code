#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

XColor mycolorm, mycolorm1, dummy;

pthread_t tid1, tid2, tid3, tid4, tid5;
int p;
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock3 = PTHREAD_MUTEX_INITIALIZER;

int klucz = 5535;
int memPosition;
int memVector;
int* sharedPosition;
double* sharedVector;

int ip4addrSize;
int s1;
struct sockaddr_in ip4addr1;
int s2;
struct sockaddr_in ip4addr2;

void end(){
	printf("Usuwanie powiazan\n");
	close(s1);
	close(s2);
	shmdt(sharedPosition);
	shmctl(memPosition, IPC_RMID, 0);
	shmdt(sharedVector);
	shmctl(memVector, IPC_RMID, 0);
	pthread_mutex_destroy(&lock1);
	pthread_mutex_destroy(&lock2);
	pthread_mutex_destroy(&lock3);
}

void intHandler(int dummy) {
	end();
}

void *handleMySetNewPosition(void *argum){
	int xr, yr, cxr, cyr;
	double xv, yv;

	int* isCancel = (int*)argum;

	int oldX, oldY;

	while(*isCancel == 0){
		pthread_mutex_lock(&lock3);
		xr = *(sharedPosition +0);
		yr = *(sharedPosition +1);
		pthread_mutex_unlock(&lock3);
		if(xr != oldX && yr != oldY){
			pthread_mutex_lock(&lock2);
			cxr = *(sharedPosition +2);
			cyr = *(sharedPosition +3);
			xv = xr - cxr;
			yv = yr - cyr;
			*(sharedVector +0) += xv / 2.0;
			*(sharedVector +1) += yv / 2.0;
			pthread_mutex_unlock(&lock2);
		}
		oldX = xr;
		oldY = yr;
		usleep(LOOP_INTERVAL);
	}
	printf("End my upload\n");
}

void *handleSetNewPosition(void *argum){
	int xr, yr, cxr, cyr;
	double xv, yv;
	int* isCancel = (int*)argum;

	int arr[2];
	int* buff = arr;

	while(*isCancel == 0){
		recvfrom(s1, (char *)buff, sizeof(buff) *2, 0, (struct sockaddr*) &ip4addr1, &ip4addrSize);
		xr = *(buff+0);
		yr = *(buff+1);
		xr = ntohl(xr);
		yr = ntohl(yr);
		pthread_mutex_lock(&lock2);
		cxr = *(sharedPosition +2);
		cyr = *(sharedPosition +3);
		xv = xr - cxr;
		yv = yr - cyr;
		*(sharedVector +0) += xv / 2.0;
		*(sharedVector +1) += yv / 2.0;
		pthread_mutex_unlock(&lock2);
	}
	printf("End upload\n");
}

void *handleGetNewPosition(void *argum){
	int xr, yr;
	int* isCancel = (int*)argum;

	int arr[2];
	int* buff = arr;

	while(*isCancel == 0){
		recvfrom(s2, (char *)buff, sizeof(buff) *2, 0, (struct sockaddr*) &ip4addr2, &ip4addrSize);
		pthread_mutex_lock(&lock2);
        xr = *(sharedPosition +2);
        yr = *(sharedPosition +3);
		pthread_mutex_unlock(&lock2);
		xr = htonl(xr);
		yr = htonl(yr);
		*(buff+0) = xr;
		*(buff+1) = yr;
		sendto(s2, (char *)buff, sizeof(buff) *2, 0, (struct sockaddr*) &ip4addr2, ip4addrSize);
	}
	printf("End download\n");
}
void *computePosition(void *argum){
	int xr, yr;
	double xv, yv;
	int* isCancel = (int*)argum;

	while(*isCancel == 0){
		pthread_mutex_lock(&lock2);
        xr = *(sharedPosition +2);
        yr = *(sharedPosition +3);
		xv = *(sharedVector +0);
		yv = *(sharedVector +1);
		*(sharedVector +0) = 0.0;
		*(sharedVector +1) = 0.0;
		xr += (int)xv;
		yr += (int)yv;
		*(sharedPosition +2) = xr;
		*(sharedPosition +3) = yr;
		pthread_mutex_unlock(&lock2);
		usleep(LOOP_INTERVAL);
	}
	printf("End compute\n");
}

void *setNewPosition(void *argum){
	int xr,yr;
	int* isCancel = (int*)argum;

	int arr[2];
	int* buff = arr;

	int oldX, oldY;

	while(*isCancel == 0){  
		pthread_mutex_lock(&lock3);
        xr = *(sharedPosition +0); // Hardware input
        yr = *(sharedPosition +1); // Hardware input
		pthread_mutex_unlock(&lock3);
		if(xr != oldX && yr != oldY){
			xr = htonl(xr);
			yr = htonl(yr);
			*(buff +0) = xr;
			*(buff +1) = yr;
			sendto(s1, (char *)buff, sizeof(buff) *2, 0, (struct sockaddr*) &ip4addr1, ip4addrSize);
		}
		oldX = xr;
		oldY = yr;
		usleep(LOOP_INTERVAL);
	}
	printf("End upload\n");
}

void *getNewPosition(void *argum){
	int xr,yr;
	int* isCancel = (int*)argum;

	int arr[2];
	int* buff = arr;

	while(*isCancel == 0){
		sendto(s2, (char *)buff, sizeof(buff) *2, 0, (struct sockaddr*) &ip4addr2, ip4addrSize);
		recvfrom(s2, (char *)buff, sizeof(buff) *2, 0, (struct sockaddr*) &ip4addr2, &ip4addrSize);
		xr = *(buff +0);
		yr = *(buff +1);
		xr = ntohl(xr);
		yr = ntohl(yr);
		pthread_mutex_lock(&lock2);
        *(sharedPosition +2) = xr;
        *(sharedPosition +3) = yr;
		pthread_mutex_unlock(&lock2);
		usleep(LOOP_INTERVAL);
	}
	printf("End download\n");
}

void *draw(void *argum){
	int xr,yr;
	int* isCancel = (int*)argum;
  
	while(*isCancel == 0){  
        pthread_mutex_lock(&lock1);
		pthread_mutex_lock(&lock2);
        xr = *(sharedPosition +2);
        yr = *(sharedPosition +3);
		pthread_mutex_unlock(&lock2);
        XClearArea(mydisplay, mywindow, 0, 0, 500, 500, 0);
		XSetForeground(mydisplay, mygc, mycolorm.pixel);
		XFillArc(mydisplay, mywindow, mygc, xr-(40/2), yr-(40/2), 40, 40, 0, 360*64);
		XFlush(mydisplay);
		pthread_mutex_unlock(&lock1);
		usleep(LOOP_INTERVAL);
	}
	printf("End draw\n");
}

int cancelDraw = 0;
int cancelUp = 0;
int cancelDown = 0;
int cancelComput = 0;
int cancelMyUpdate = 0;

void mousehandle(){
	XInitThreads();
	mydisplay = XOpenDisplay("");

	int myscreen;
	myscreen = DefaultScreen(mydisplay);

	Visual *myvisual;
	myvisual = DefaultVisual(mydisplay, myscreen);

	int mydepth;
	mydepth = DefaultDepth(mydisplay, myscreen);
	XSetWindowAttributes mywindowattributes;
	mywindowattributes.background_pixel = XWhitePixel(mydisplay, myscreen);
	mywindowattributes.override_redirect = False;
	mywindowattributes.backing_store = Always;
	mywindowattributes.bit_gravity = NorthWestGravity;

	mywindow = XCreateWindow(mydisplay, XRootWindow(mydisplay, myscreen),
		0, 0, 500, 500, 10, mydepth, InputOutput,
		myvisual, CWBackingStore | CWBackingPlanes| CWBitGravity |
		CWBackPixel | CWOverrideRedirect, &mywindowattributes);

	XSelectInput(mydisplay, mywindow, KeyPressMask | ButtonPressMask | ButtonMotionMask);

	Colormap mycolormap;
	mycolormap = DefaultColormap(mydisplay, myscreen);                 

	XAllocNamedColor(mydisplay, mycolormap, "red", &mycolorm, &dummy);

	XAllocNamedColor(mydisplay, mycolormap, "blue", &mycolorm1, &dummy);

	XMapWindow(mydisplay, mywindow);

	mygc = DefaultGC(mydisplay, myscreen);

	pthread_create(&tid1, NULL, draw, &cancelDraw);

	XEvent myevent;
	int xw, yw;
	while (1){
		XNextEvent(mydisplay, &myevent);
		switch (myevent.type){
			case ButtonPress:
				xw = myevent.xbutton.x;
				yw = myevent.xbutton.y;
				pthread_mutex_lock(&lock3);
				*(sharedPosition +0) = xw;
				*(sharedPosition +1) = yw;
				pthread_mutex_unlock(&lock3);
				break;
			case MotionNotify:
				xw = myevent.xmotion.x;
				yw = myevent.xmotion.y;
				pthread_mutex_lock(&lock3);
				*(sharedPosition +0) = xw;
				*(sharedPosition +1) = yw;
				pthread_mutex_unlock(&lock3);
				break;
			case KeyPress:
				// Only Esc close window
				if(myevent.xkey.keycode == 9){
					cancelDraw = 1;
					cancelUp = 1;
					cancelDown = 1;
					cancelComput = 1;
					cancelMyUpdate = 1;
					XCloseDisplay(mydisplay);
					end();
					exit(0);
				}
				break;
		}
	}
}

void main(){
	signal(SIGINT, intHandler);
	p = getpid();

    int zarodek = time(NULL);
    srand(zarodek); // za zarodek wstawiamy pobrany czas w sekundach
	klucz += (int)(rand() / (RAND_MAX + 1.0) * 50.0);

	ip4addrSize = sizeof(struct sockaddr_in);

	s1 = socket(PF_INET, SOCK_DGRAM, 0x0);
	s2 = socket(PF_INET, SOCK_DGRAM, 0x0);

	struct sockaddr_in ip4addr_any1;
	bzero((char *) &ip4addr_any1, sizeof(ip4addr_any1));
	ip4addr_any1.sin_family = AF_INET;
	ip4addr_any1.sin_port = htons((ushort) UNIT1_PORT);
	ip4addr_any1.sin_addr.s_addr = htonl(INADDR_ANY);

	struct sockaddr_in ip4addr_any2;
	bzero((char *) &ip4addr_any2, sizeof(ip4addr_any2));
	ip4addr_any2.sin_family = AF_INET;
	ip4addr_any2.sin_port = htons((ushort) COMM1_PORT);
	ip4addr_any2.sin_addr.s_addr = htonl(INADDR_ANY);

	struct sockaddr_in ip4addr_my1;
	bzero((char *) &ip4addr_my1, sizeof(ip4addr_my1));
	ip4addr_my1.sin_family = AF_INET;
	ip4addr_my1.sin_port = htons((ushort) UNIT1_PORT);
	inet_pton(AF_INET, SERVE_ADDR, &ip4addr_my1.sin_addr);

	struct sockaddr_in ip4addr_my2;
	bzero((char *) &ip4addr_my2, sizeof(ip4addr_my2));
	ip4addr_my2.sin_family = AF_INET;
	ip4addr_my2.sin_port = htons((ushort) COMM1_PORT);
	inet_pton(AF_INET, SERVE_ADDR, &ip4addr_my2.sin_addr);

	int error = 0;

	if((error = bind(s1, (struct sockaddr*) &ip4addr_any1, ip4addrSize)) >=0){
		bind(s2, (struct sockaddr*) &ip4addr_any2, ip4addrSize);
		// I'm a server
		ip4addr1 = ip4addr_any1;
		ip4addr2 = ip4addr_any2;
		printf("I'm a server\n");
		printf("Klucz to: %d\n", klucz);
		memPosition = shmget(klucz, sizeof(int) *6, 0777 | IPC_CREAT);
		sharedPosition = shmat(memPosition, 0, 0);
		memVector = shmget(klucz-1, sizeof(double) *3, 0777 | IPC_CREAT);
		sharedVector = shmat(memVector, 0, 0);
		pthread_create(&tid2, NULL, handleSetNewPosition, &cancelUp);
		pthread_create(&tid3, NULL, handleGetNewPosition, &cancelDown);
		pthread_create(&tid4, NULL, computePosition, &cancelComput);
		pthread_create(&tid5, NULL, handleMySetNewPosition, &cancelMyUpdate);
	}else{
		printf("Error: %d, %d", error, errno);
		// I'm a client
		ip4addr1 = ip4addr_my1;
		ip4addr2 = ip4addr_my2;
		bind(s1, (struct sockaddr*) &ip4addr_my1, ip4addrSize);
		bind(s2, (struct sockaddr*) &ip4addr_my2, ip4addrSize);
		printf("I'm a client\n");
		printf("Klucz to: %d\n", klucz);
		memPosition = shmget(klucz+1, sizeof(int) *6, 0777 | IPC_CREAT);
		sharedPosition = shmat(memPosition, 0, 0);
		pthread_create(&tid2, NULL, setNewPosition, &cancelUp);
		pthread_create(&tid3, NULL, getNewPosition, &cancelDown);
		printf("Error: %d, %d", error, errno);
	}

	mousehandle();
}
