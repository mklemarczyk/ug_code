#define _REENTRANT
#include <fcntl.h>
#include <math.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // for usleep
#include <X11/X.h>
#include <X11/Xlib.h>

#define LOOP_INTERVAL 15*1000

Display *mydisplay;
Window mywindow;
GC mygc;

// Find game server
void findserver();

// Init as game server
void createserver();

// Recieve request from client
void recieverequest();

// Send interval update to all clients
void sendupdate();

// Interval client draw
void *draw();

// Mouse handler
void mousehandle();

// Send update request to server
void sendrequest();

// Recieve update position from server
void recieveupdate();

// Init program
void main();
