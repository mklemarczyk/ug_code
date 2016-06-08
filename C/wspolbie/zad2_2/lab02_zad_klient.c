#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define D_WFILE "dane.txt"
#define D_RFILE "wyniki.txt"
char message[255];

void storemsg(){
	int wfile = open(D_WFILE, O_CREAT | O_WRONLY | O_APPEND, 0711);

	if(wfile != -1){
		int write_result = write(wfile, message, strlen(message));
		if (write_result == -1) {
			write(2, "There was an error writing to " D_WFILE "\n", 39);
		}
		close(wfile);
		write(2, "Saved\n", 6);
	}else{
		write(2, "There was an error opening to " D_WFILE "\n", 39);
	}
}

void readmsg(){
	int rfile = open(D_RFILE, O_CREAT | O_RDONLY, 0711);

	if(rfile != -1){
		int read_result = read(rfile, message, 255);
		if (read_result == -1) {
			write(2, "There was an error reading to " D_RFILE "\n", 39);
		}
		close(rfile);
		write(2, "Readed\n", 7);
	}else{
		write(2, "There was an error opening to " D_RFILE "\n", 39);
	}
}

int main(){
	int lockfile = 0;
	while((lockfile = open("lockfile.txt", O_CREAT | O_EXCL, 0)) == -1) {
		write(1, "Serwer is busy, hang on\n", 24);
		sleep(2);
	}

	write(1, "Type message\n", 13);
	read(1, message, 255);

	storemsg();
	
	close(lockfile);

    return 0;
}

