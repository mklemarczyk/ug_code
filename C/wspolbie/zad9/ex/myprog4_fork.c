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
XColor mycolor,mycolor1,dummy;
XEvent myevent;
int p;
char *myname;

main()

{  
   p=fork();
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
     
   if (p==0)  
            
      {      
                            
         XAllocNamedColor(mydisplay,mycolormap,"cyan",&mycolor,&dummy);
                    
         XAllocNamedColor(mydisplay,mycolormap,"red",&mycolor1,&dummy);                 
         
         myname="Pierwszy";
         
      }   
       
   else
   
      {
      
         XAllocNamedColor(mydisplay,mycolormap,"yellow",&mycolor,&dummy);
         
         XAllocNamedColor(mydisplay,mycolormap,"green",&mycolor1,&dummy);
         
         myname="Drugi";
         
      }    
      
   XStoreName(mydisplay,mywindow,myname);   
                    
   XMapWindow(mydisplay,mywindow);
   
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
   
              exit(0); 
              
      }
      
  }
              
}
                                             