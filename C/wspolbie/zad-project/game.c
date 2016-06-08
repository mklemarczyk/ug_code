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
