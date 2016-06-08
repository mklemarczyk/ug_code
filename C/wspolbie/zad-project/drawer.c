#define _REENTRANT
#include <X11/Xlib.h>
#include <X11/X.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <math.h>

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

void end(){
	pthread_mutex_destroy(&lock);
}

void *reader(void *argum){
   struct buffer *buf;
   int xr,yr,xr1,yr1;
   int fd;

   buf=(struct buffer *) malloc(bufsize);
   printf("Zglasza sie reader\n");   
   while (!(fd=open("rysunek",O_RDONLY,0700)));
   printf("Plik otwarty do odczytu\n");
	  XClearArea(mydisplay, mywindow, 0, 0, 500, 500, 0);
   while (1)
   {  

      if (read(fd,buf,bufsize)>0)
      {
         printf("Odczytano wspolrzedne: %5d, %5d\n",buf->x,buf->y);
         printf("pid= %5d p= %5d argum= %8d\n",buf->pid,p,argum);
         if (((buf->pid==p)&&(argum!=NULL))||((buf->pid!=p)&&(argum==NULL)))
         {
printf("Probujemy zablokowac\n");
            pthread_mutex_lock(&lock);
            XSetForeground(mydisplay,mygc,(argum!=NULL)?mycolorm.pixel:mycolorm1.pixel);
printf("KOLOR\n");
            if (buf->prev==0){
               xr=buf->x;
               yr=buf->y;
			   XFillArc(mydisplay, mywindow, mygc, xr-(40/2), yr-(40/2), 40, 40, 0, 360*64);
			   XFlush(mydisplay);
            }
            pthread_mutex_unlock(&lock);
         }
      }
   }
}

main(){
	int xw,yw,xw1,yw1;
	int fdw;
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

	fdw=open("rysunek",O_WRONLY|O_CREAT|O_APPEND,0700);
	printf("Plik otwarty do zapisu\n");
	pthread_create(&tid,NULL,reader,(void *) &p);
	printf("Moj czytelnik utworzony\n");
	pthread_create(&tid1,NULL,reader,NULL);
	printf("Jego czytelnik utworzony\n");

	while (1){
		XNextEvent(mydisplay,&myevent);
		printf("event no. %5d\n",myevent.type);
		switch (myevent.type){
		 case ButtonPress:

			  xw1=myevent.xbutton.x;
			  
			  yw1=myevent.xbutton.y;

			  printf("button: %3d  %3d\n",xw1,yw1);

			  bufw->x=xw1;
			  bufw->y=yw1;
			  bufw->prev=0;
			  bufw->pid=p;
			  write(fdw,bufw,bufsize);
			  break;

		 case MotionNotify:
		 
			  xw=myevent.xmotion.x;
			  
			  yw=myevent.xmotion.y;

			  printf("motion: %3d  %3d\n",xw,yw);

			  bufw->x=xw;
			  bufw->y=yw;
			  bufw->prev=1;
			  bufw->pid=p;
			  write(fdw,bufw,bufsize);

			  xw1=xw;
			  
			  yw1=yw;
			  
			  break;

		 case KeyPress:
		  
			  XCloseDisplay(mydisplay);

			  end();   
			  close(fdw);
			  exit(0); 
		}
	}
}
