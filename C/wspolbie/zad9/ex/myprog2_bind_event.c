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
unsigned long i;

main()

{
   mydisplay = XOpenDisplay("");
   myscreen = DefaultScreen(mydisplay);
   myvisual = DefaultVisual(mydisplay,myscreen);
   mydepth = DefaultDepth(mydisplay,myscreen);
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
   
                 XSetForeground(mydisplay,mygc,i);
   
                 XFillRectangle(mydisplay,mywindow,mygc,20*i,20,20*(i+1),20);
  
                 XFlush(mydisplay);

              }

              break;

         case KeyPress:
          
              XCloseDisplay(mydisplay);
   
              exit(0); 
              
      }
      
  }
              
}
                                             