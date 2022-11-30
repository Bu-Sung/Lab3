#include <unistd.h>
#include <stdio.h>

void main(int argc, char *argv[]){
	char path[256];
	sprintf(path,"%s%s", "/bin/", argv[1]);
	execl(path, argv[1],argv[2],NULL);
}
