#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int fd;
	struct flock testlock;
	int pid;

	testlock.l_type = F_WRLCK;
	testlock.l_whence = SEEK_SET;
	testlock.l_start = 0;
	testlock.l_len = 10;
	
	fd = open ("lock", O_RDWR | O_CREAT,0666); //파일 열기
	if (fcntl (fd, F_SETLKW, &testlock) == -1) {
		perror ("부모프로세스: locking");
		exit (1);
	}
	printf ("부모프로세스: locked record\n");
	pid = fork();
	if (pid == 0) { // 자식 프로세스
		testlock.l_len = 5;
		if (fcntl (fd, F_SETLKW, &testlock) == -1) {
			perror ("자식프로세스: locking");
			exit (1);
		}
		printf ("자식프로세스: locked\n");
		sleep(5);
		printf ("자식프로세스: exiting\n");
	}else if (pid > 0) {
		sleep(5);
		printf ("부모프로세스: exiting\n");
	}else
		perror ("fork 실패");
}
