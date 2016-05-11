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
int i;

main()

{
// Open connection to X11 server
   mydisplay = XOpenDisplay("");
   // Get default configuration X11 server
   myscreen = DefaultScreen(mydisplay);
   myvisual = DefaultVisual(mydisplay,myscreen);
   mydepth = DefaultDepth(mydisplay,myscreen);
   // Set attributes for new window
   mywindowattributes.background_pixel = XWhitePixel(mydisplay,myscreen);
   mywindowattributes.override_redirect = True;
   // Create new window for display
   mywindow = XCreateWindow(mydisplay,XRootWindow(mydisplay,myscreen),
                            0,0,500,500,10,mydepth,InputOutput,
                            myvisual,CWBackPixel|CWOverrideRedirect,
                            &mywindowattributes);
   // Get default color map for creating colors           
   mycolormap = DefaultColormap(mydisplay,myscreen);                 
   // Create color structs
   XAllocNamedColor(mydisplay,mycolormap,"cyan",&mycolor,&dummy);
   XAllocNamedColor(mydisplay,mycolormap,"red",&mycolor1,&dummy);                 
   // ??
   XMapWindow(mydisplay,mywindow);
   // ??
   mygc = DefaultGC(mydisplay,myscreen);
   // Set draw color
   XSetForeground(mydisplay,mygc,mycolor.pixel);
   // Draw rectangle with fill
   XFillRectangle(mydisplay,mywindow,mygc,100,100,300,300);
   // Set draw color
   XSetForeground(mydisplay,mygc,mycolor1.pixel);
   // ??
   XSetFunction(mydisplay,mygc,GXcopy);
   // Set line storke
   XSetLineAttributes(mydisplay,mygc,10,LineSolid,CapProjecting,JoinMiter);
   // Draw lines
   XDrawLine(mydisplay,mywindow,mygc,100,100,400,400);
   XDrawLine(mydisplay,mywindow,mygc,100,400,400,100);
   
   // Send graphics to window
   XFlush(mydisplay);
   
   sleep(10);
   
   // Close window
   XCloseDisplay(mydisplay);
   
   exit(0);
}
