#include "game.h"

Display *mydisplay;
Window mywindow;
GC mygc;
XColor mycolorm, mycolorm1, dummy;

pthread_t tid, tid1;
int p;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int klucz = 5535;
int* sharedPosition;
int pamiec;

void end(){
	printf("Usuwanie powiazan\n");
	shmdt(sharedPosition);
	shmctl(pamiec, IPC_RMID, 0);
	pthread_mutex_destroy(&lock);
}

void intHandler(int dummy) {
	end();
}

void *draw(void *argum){
	int xr,yr;
	int* isCancel = (int*)argum;
  
	while(*isCancel == 0){  
        pthread_mutex_lock(&lock);
        xr = *(sharedPosition+0);
        yr = *(sharedPosition+1);
        XClearArea(mydisplay, mywindow, 0, 0, 500, 500, 0);
		XSetForeground(mydisplay, mygc, mycolorm.pixel);
		XFillArc(mydisplay, mywindow, mygc, xr-(40/2), yr-(40/2), 40, 40, 0, 360*64);
		XFlush(mydisplay);
		pthread_mutex_unlock(&lock);
		usleep(15 * 1000);
	}
}

void main(){
	signal(SIGINT, intHandler);
	p = getpid();

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

	pamiec = shmget(klucz, sizeof(int) *2, 0777 | IPC_CREAT);
	sharedPosition = shmat(pamiec, 0, 0);

	int cancelDraw = 0;
	int* cancelArg = &cancelDraw;
	pthread_create(&tid1, NULL, draw, cancelArg);

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
					XCloseDisplay(mydisplay);
					end();
					exit(0);
				}
				break;
		}
	}
}
