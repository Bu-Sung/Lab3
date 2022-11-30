#include <unistd.h>
#include <stdio.h>

void main(int argc, char *argv[]){
	char path[256];
	sprintf(path,"%s%s", "/bin/", argv[1]); //경로 저장하기
	execl(path, argv[1],argv[2],NULL); //경로에 있는 기본 명령어 실행하기
}
