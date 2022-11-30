#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t pid; // 프로세스 식별번호 저장 
	printf("프로세스 생성하기 \n");
	pid = fork(); // 새로운 프로세스 생성
	if (pid == 0)
		printf("pid = %d : 자식 프로세스입니다.\n", pid);
	else if (pid > 0)
		printf("pid = %d : 부모 프로세스입니다.\n", pid);
	else
		printf("fork에 실패하였습니다.\n");
} 
