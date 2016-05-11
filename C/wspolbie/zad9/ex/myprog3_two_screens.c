#include <X11/Xlib.h>
#include <X11/X.h>
#include <stdio.h>

Display *mydisplay,*mydisplay1;
Window mywindow,mywindow1;
XSetWindowAttributes mywindowattributes,mywindowattributes1;
XGCValues mygcvalues;
GC mygc;
Visual *myvisual, *myvisual1;
int mydepth;
int myscreen,myscreen1;
Colormap mycolormap;
XColor mycolor,mycolor1,dummy;
XEvent myevent,myevent1;

main()

{
   mydisplay = XOpenDisplay("localhost:0");
   mydisplay1 = XOpenDisplay("localhost:0");
   myscreen = DefaultScreen(mydisplay);
   myscreen1 = DefaultScreen(mydisplay1);
   myvisual = DefaultVisual(mydisplay,myscreen);
   myvisual1 = DefaultVisual(mydisplay1,myscreen1);
   mydepth = DefaultDepth(mydisplay,myscreen);
   mywindowattributes.background_pixel = XWhitePixel(mydisplay,myscreen);
   mywindowattributes1.background_pixel = XWhitePixel(mydisplay1,myscreen1);
   mywindowattributes.override_redirect = False;
   mywindowattributes1.override_redirect = True;
   
   mywindow = XCreateWindow(mydisplay,XRootWindow(mydisplay,myscreen),
                            100,100,500,500,10,mydepth,InputOutput,
                            myvisual,CWBackPixel|CWOverrideRedirect,
                            &mywindowattributes);
                            
   mywindow1 = XCreateWindow(mydisplay1,XRootWindow(mydisplay1,myscreen1),
                             100,100,500,500,10,mydepth,InputOutput,
                             myvisual1,CWBackPixel|CWOverrideRedirect,
                             &mywindowattributes1);                         

   XSelectInput(mydisplay,mywindow,ExposureMask|KeyPressMask);
                    
   mycolormap = DefaultColormap(mydisplay,myscreen);                 
                            
   XAllocNamedColor(mydisplay,mycolormap,"cyan",&mycolor,&dummy);
                    
   XAllocNamedColor(mydisplay,mycolormap,"red",&mycolor1,&dummy);                 
                    
   XMapWindow(mydisplay,mywindow);
   
   XMapWindow(mydisplay1,mywindow1);
   
   mygc = DefaultGC(mydisplay,myscreen);

   while (1)
   
   {
   
      XNextEvent(mydisplay,&myevent);
      
      switch (myevent.type)
      
      {
         
         case Expose:
   
              XSetForeground(mydisplay,mygc,mycolor.pixel);
   
              XFillRectangle(mydisplay,mywindow,mygc,100,100,300,300);
  
              XSetForeground(mydisplay,mygc,mycolor1.pixel);
   
              XSetFunction(mydisplay,mygc,GXcopy);
 
              XSetLineAttributes(mydisplay,mygc,10,LineSolid,CapProjecting,JoinMiter);
   
              XDrawLine(mydisplay,mywindow,mygc,100,100,400,400);

              XDrawLine(mydisplay,mywindow,mygc,100,400,400,100);
   
              XFlush(mydisplay);

              break;

         case KeyPress:
          
              XCloseDisplay(mydisplay);
              
              XCloseDisplay(mydisplay1);
   
              exit(0); 
              
      }
      
  }
              
}
                                             
