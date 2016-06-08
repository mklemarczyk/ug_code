#include <game.h>

Display *mydisplay;
Window mywindow;
XSetWindowAttributes mywindowattributes;
XGCValues mygcvalues;
GC mygc;
Visual *myvisual;
int mydepth;
int myscreen;
Colormap mycolormap;
XColor mycolorm,mycolorm1,dummy;
XEvent myevent;
pthread_t tid,tid1;
struct buffer {int x; int y; int pid; int prev; };
int bufsize;
int p;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int klucz = 5535;
int* planszaW;
int pamiec;

void end(){
	shmdt(planszaW);
	shmctl(pamiec, IPC_RMID, 0);
	pthread_mutex_destroy(&lock);
}

void intHandler(int dummy) {
	end();
}

void *reader(void *argum){
   struct buffer *buf;
   int xr,yr,xr1,yr1;
   int fd;

   buf = (struct buffer *) malloc(bufsize);
   printf("Zglasza sie reader\n");   
   while (1)
   {  
        pthread_mutex_lock(&lock);
        xr = *(planszaW+0);
        yr = *(planszaW+1);
			  //printf("draw: %3d  %3d\n",xr,yr);
        XClearArea(mydisplay, mywindow, 0, 0, 500, 500, 0);
            XSetForeground(mydisplay,mygc,mycolorm.pixel);
			       XFillArc(mydisplay, mywindow, mygc, xr-(40/2), yr-(40/2), 40, 40, 0, 360*64);
			       XFlush(mydisplay);
            pthread_mutex_unlock(&lock);
            usleep(15 * 1000);
   }
}

main(){
	signal(SIGINT, intHandler);
	int xw,yw;
	struct buffer *bufw;

	bufsize=sizeof(struct buffer);
	printf("Rozmiar bufora: %5d\n",bufsize);
	bufw=(struct buffer *) malloc(bufsize);
	p=getpid();

	XInitThreads();
	mydisplay = XOpenDisplay("");
	myscreen = DefaultScreen(mydisplay);
	myvisual = DefaultVisual(mydisplay,myscreen);
	mydepth = DefaultDepth(mydisplay,myscreen);
	mywindowattributes.background_pixel = XWhitePixel(mydisplay,myscreen);
	mywindowattributes.override_redirect = False;
	mywindowattributes.backing_store = Always;
	mywindowattributes.bit_gravity = NorthWestGravity;

	mywindow = XCreateWindow(mydisplay,XRootWindow(mydisplay,myscreen),
							0,0,500,500,10,mydepth,InputOutput,
							myvisual,CWBackingStore|CWBackingPlanes|CWBitGravity|
							CWBackPixel|CWOverrideRedirect,&mywindowattributes);

	XSelectInput(mydisplay,mywindow,KeyPressMask|ButtonPressMask|ButtonMotionMask);
					
	mycolormap = DefaultColormap(mydisplay,myscreen);                 
							
	XAllocNamedColor(mydisplay,mycolormap,"red",&mycolorm,&dummy);

	XAllocNamedColor(mydisplay,mycolormap,"blue",&mycolorm1,&dummy);

	XMapWindow(mydisplay,mywindow);

	mygc = DefaultGC(mydisplay,myscreen);

	pamiec = shmget(klucz, 256, 0777 | IPC_CREAT);
	planszaW = shmat(pamiec, 0, 0);

	printf("Plik otwarty do zapisu\n");
	pthread_create(&tid,NULL,reader,(void *) &p);
	printf("Moj czytelnik utworzony\n");
	pthread_create(&tid1,NULL,reader,NULL);
	printf("Jego czytelnik utworzony\n");

	while (1){
		XNextEvent(mydisplay,&myevent);
		//printf("event no. %5d\n",myevent.type);
		switch (myevent.type){
		 case ButtonPress:
			  xw=myevent.xbutton.x;
			  yw=myevent.xbutton.y;
			  printf("button: %3d  %3d\n",xw,yw);
        *(planszaW+0) = xw;
        *(planszaW+1) = yw;
			  break;
		 case MotionNotify:
			  xw=myevent.xmotion.x;
			  yw=myevent.xmotion.y;
			  //printf("motion: %3d  %3d\n",xw,yw);
        *(planszaW+0) = xw;
        *(planszaW+1) = yw;
			  break;
		 case KeyPress:
			  XCloseDisplay(mydisplay);
			  end();
			  exit(0); 
		}
	}
}
