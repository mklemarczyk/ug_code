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

// Find game server
findserver();

// Init as game server
createserver();

// DONE - Recieve request from client
recieverequest();

// Send interval update to all clients
sendupdate();

// DONE - Interval client draw
draw();

// Mouse handler
mousehandle();

// DONE - Send update request to server
sendrequest();

// Recieve update position from server
recieveupdate();

// Init program
main();
