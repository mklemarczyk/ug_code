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

#include <errno.h>

#define LOOP_INTERVAL 15*1000
#define UNIT1_PORT 5535
#define COMM1_PORT 5536

Display *mydisplay;
Window mywindow;
GC mygc;

// Find game server
void findserver();

// Init as game server
void createserver();

// Handle update with new position from client
void *handleSetNewPosition();

// Handle update request for new position from client
void *handleGetNewPosition();

// Interval client draw
void *draw();

// Mouse handler
void mousehandle();

// Send update with new position to the server
void *setNewPosition();

// Send update request for new position to the server
void *getNewPosition();

// Init program
void main();
