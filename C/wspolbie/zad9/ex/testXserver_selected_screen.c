#include <X11/Xlib.h>
#include <X11/X.h>
#include <stdio.h>

Display *mydisplay;
Window mywindow;
XSetWindowAttributes mywindowattributes;
XGCValues mygcvalues;
GC mygc;
Visual *myvisual;
int mydepth;
int myscreen;
Colormap mycolormap;
XEvent myevent;
unsigned long i,j;

main(int argc, char *argv[])

{
   if (argc==1)
      mydisplay = XOpenDisplay("");
   else if (argc==2)
      mydisplay = XOpenDisplay(argv[1]);
   else {printf("Too many arguments\n");
         exit(1);}   

   printf("Parametry ekranu - wartosci domyslne:\n");  
   printf("\n");    

   myscreen = DefaultScreen(mydisplay);
   myvisual = DefaultVisual(mydisplay,myscreen);
   mydepth = DefaultDepth(mydisplay,myscreen);

   printf("liczba bitow na pixel: %10d\n",mydepth);
   printf("liczba kolorow:        %10d\n",DisplayCells(mydisplay,myscreen));
   printf("szerokosc ekranu:      %10d\n",DisplayWidth(mydisplay,myscreen));
   printf("wysokosc ekranu:       %10d\n",DisplayHeight(mydisplay,myscreen));

   mywindowattributes.background_pixel = XWhitePixel(mydisplay,myscreen);
   mywindowattributes.override_redirect = False;
   
   mywindow = XCreateWindow(mydisplay,XRootWindow(mydisplay,myscreen),
                            100,100,500,500,10,mydepth,InputOutput,
                            myvisual,CWBackPixel|CWOverrideRedirect,
                            &mywindowattributes);

   XSelectInput(mydisplay,mywindow,ExposureMask|KeyPressMask);
                    
   mycolormap = DefaultColormap(mydisplay,myscreen);                 
                            
   XMapWindow(mydisplay,mywindow);
   
   mygc = DefaultGC(mydisplay,myscreen);

   while (1)
   
   {
   
      XNextEvent(mydisplay,&myevent);
      
      switch (myevent.type)
      
      {
         
         case Expose:

              for (i=0;i<16;i++)
              
              {
   
                 for (j=0;j<16;j++)
                 
                 {
   
                    XSetForeground(mydisplay,mygc,500*i+10*j);
   
                    XFillRectangle(mydisplay,mywindow,mygc,20*i,20*j,20*(i+1),20*(j+1));
  
                    XFlush(mydisplay);

                 }

              }

              break;

         case KeyPress:
          
              XCloseDisplay(mydisplay);
   
              exit(0); 
              
      }
      
  }
              
}
                                             