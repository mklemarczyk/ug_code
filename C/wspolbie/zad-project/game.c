#include "game.h"

XColor mycolorm, mycolorm1, dummy;

pthread_t tid1, tid2, tid3;
int p;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int klucz = 5535;
int* sharedPosition;
int pamiec;

int ip4addrSize;
int s;
struct sockaddr_in ip4addr;

void end(){
	printf("Usuwanie powiazan\n");
	shmdt(sharedPosition);
	shmctl(pamiec, IPC_RMID, 0);
	pthread_mutex_destroy(&lock);
}

void intHandler(int dummy) {
	end();
}

void *handleSetNewPosition(void *argum){
	int xr,yr;
	int* isCancel = (int*)argum;
  
	while(*isCancel == 0){  
        xr = *(sharedPosition +0);
        yr = *(sharedPosition +1);
        *(sharedPosition +4) = xr;
        *(sharedPosition +5) = yr;
		usleep(LOOP_INTERVAL);
	}
	printf("End upload\n");
}

void *handleGetNewPosition(void *argum){
	int xr,yr;
	int* isCancel = (int*)argum;
  
	while(*isCancel == 0){  
        xr = *(sharedPosition +4);
        yr = *(sharedPosition +5);
        *(sharedPosition +2) = xr;
        *(sharedPosition +3) = yr;
		usleep(LOOP_INTERVAL);
	}
	printf("End download\n");
}

void *setNewPosition(void *argum){
	int xr,yr;
	int* isCancel = (int*)argum;
  
	while(*isCancel == 0){  
        xr = *(sharedPosition +0);
        yr = *(sharedPosition +1);
        *(sharedPosition +4) = xr;
        *(sharedPosition +5) = yr;
		usleep(LOOP_INTERVAL);
	}
	printf("End upload\n");
}

void *getNewPosition(void *argum){
	int xr,yr;
	int* isCancel = (int*)argum;
  
	while(*isCancel == 0){  
        xr = *(sharedPosition +4);
        yr = *(sharedPosition +5);
        *(sharedPosition +2) = xr;
        *(sharedPosition +3) = yr;
		usleep(LOOP_INTERVAL);
	}
	printf("End download\n");
}

void *draw(void *argum){
	int xr,yr;
	int* isCancel = (int*)argum;
  
	while(*isCancel == 0){  
        pthread_mutex_lock(&lock);
        xr = *(sharedPosition +2);
        yr = *(sharedPosition +3);
        XClearArea(mydisplay, mywindow, 0, 0, 500, 500, 0);
		XSetForeground(mydisplay, mygc, mycolorm.pixel);
		XFillArc(mydisplay, mywindow, mygc, xr-(40/2), yr-(40/2), 40, 40, 0, 360*64);
		XFlush(mydisplay);
		pthread_mutex_unlock(&lock);
		usleep(LOOP_INTERVAL);
	}
	printf("End draw\n");
}

int cancelDraw = 0;
int cancelUp = 0;
int cancelDown = 0;

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
				*(sharedPosition +0) = xw;
				*(sharedPosition +1) = yw;
				break;
			case MotionNotify:
				xw = myevent.xmotion.x;
				yw = myevent.xmotion.y;
				*(sharedPosition +0) = xw;
				*(sharedPosition +1) = yw;
				break;
			case KeyPress:
				// Only Esc close window
				if(myevent.xkey.keycode == 9){
					cancelDraw = 1;
					cancelUp = 1;
					cancelDown = 1;
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

	pamiec = shmget(klucz, sizeof(int) *6, 0777 | IPC_CREAT);
	sharedPosition = shmat(pamiec, 0, 0);

int ip4addrSize;
ip4addrSize = sizeof(struct sockaddr_in);

int s;
s = socket(PF_INET, SOCK_DGRAM, 0x0);

struct sockaddr_in ip4addr_any;
bzero((char *) &ip4addr_any, sizeof(ip4addr_any));
ip4addr_any.sin_family = AF_INET;
ip4addr_any.sin_port = htons((ushort) 5535);
ip4addr_any.sin_addr.s_addr = htonl(INADDR_ANY);

struct sockaddr_in ip4addr_my;
bzero((char *) &ip4addr_my, sizeof(ip4addr_my));
ip4addr_my.sin_family = AF_INET;
ip4addr_my.sin_port = htons((ushort) 5535);
inet_pton(AF_INET, "192.168.1.181", &ip4addr_my.sin_addr);

if(bind(s, (struct sockaddr*) &ip4addr_any, ip4addrSize) >=0){
	// I'm a server
	ip4addr = ip4addr_any;
	printf("I'm a server\n");
	pthread_create(&tid2, NULL, handleSetNewPosition, &cancelUp);
	pthread_create(&tid3, NULL, handleGetNewPosition, &cancelDown);
}else{
	// I'm a client
	ip4addr = ip4addr_my;
	bind(s, (struct sockaddr*) &ip4addr_my, ip4addrSize);
	printf("I'm a client\n");
	klucz++;
	pthread_create(&tid2, NULL, setNewPosition, &cancelUp);
	pthread_create(&tid3, NULL, getNewPosition, &cancelDown);
}

	mousehandle();
}
