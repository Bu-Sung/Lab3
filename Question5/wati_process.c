#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int status, exit_status;
	if ((pid = fork()) < 0)
		perror ("프로세스 생성 실패");
	if (pid == 0) {
		sleep(3); // 3초간 정지
		exit(5);
	}
	// 부모는 자식이 퇴장(exit)할 때까지 대기
	if ((pid = wait(&status)) == -1) {
		perror("wait failed");
		exit(2);
	}	
	if (WIFEXITED(status)) {
		exit_status = WEXITSTATUS(status);
		printf("Exit status from %d was %d\n",pid, exit_status);
	}
	exit(0);
}
