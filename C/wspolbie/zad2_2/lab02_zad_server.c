#include<fcntl.h>
#include<unistd.h>

#define D_RFILE "dane.txt"
#define D_WFILE "wyniki.txt"
char message[255];

void storemsg(){
	int wfile = open(D_WFILE, O_CREAT | O_WRONLY | O_APPEND, 0711);

	if(wfile != -1){
		int write_result = write(wfile, message, 255);
		if (write_result != -1) {
			write(2, "There was an error writing to dane.txt\n", 39);
		}
		close(wfile);
	}
}

void readmsg(){
	int rfile = open(D_RFILE, O_CREAT | O_RDONLY, 0711);

	if(rfile != -1){
		int read_result = read(rfile, message, 255);
		if (read_result != -1) {
			write(2, "There was an error reading to dane.txt\n", 39);
		}
		close(rfile);
	}
}

int main(){
	//while(1){
		write(1, "Opening dane.txt\n", 17);
	    int filedesc = open("tmp/dane.txt", O_CREAT | O_RDONLY, 0711);
		if (filedesc < 0) {
			write(2, "Can not open dane.txt\n", 22);
			return -1;
		}
		
		write(1, "Reading dane.txt\n", 17);
		if(read(filedesc, data, 128) < 0){
			write(2, "There was an error reading dane.txt\n", 36);
			close(filedesc);
			return -1;
		}

		write(1, "Closing data.txt\n", 17);
		close(filedesc);
		
		strToInt();
		num = num * num;
		intToStr();
		
		write(1, "Opening wyniki.txt\n", 19);
	    int filedesc2 = open("tmp/wyniki.txt", O_CREAT | O_WRONLY | O_APPEND, 0711);
		if (filedesc2 < 0) {
			write(2, "Can not open wyniki.txt\n", 24);
			return -1;
		}
		
		write(1, "Writing wyniki.txt\n", 19);
		if (write(filedesc2, "14", 2) != 2) {
			write(2, "There was an error writing to wyniki.txt\n", 41);
			close(filedesc2);
			return -1;
		}
		
		write(1, "Closing wyniki.txt\n", 19);
		close(filedesc2);
	//}

    return 0;
}
