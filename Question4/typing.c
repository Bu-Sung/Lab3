#include <stdio.h>
#include <termios.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#ifndef LINUX_KBHIT_H_
#define LINUX_KBHIT_H_

#define PASSWORDSIZE 12

int linux_kbhit(void) // 키보드 입력이 있을 시 사용하는 함수
{
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();

    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

 

#endif
int main(void)
{
	int fd;
	int nread, cnt=0, errcnt=0, input=0;//타수 계산 변수
	char ch, text[] = "system programing is good!";
	struct termios init_attr, new_attr;
	fd = open(ttyname(fileno(stdin)), O_RDWR);
	tcgetattr(fd, &init_attr);
	new_attr = init_attr;
	new_attr.c_lflag &= ~ICANON;
	new_attr.c_lflag &= ~ECHO; /* ~(ECHO | ECHOE | ECHOK | ECHONL); */
	new_attr.c_cc[VMIN] = 1;
	new_attr.c_cc[VTIME] = 0;
	time_t start, end; //분당 타수 계산을 위한 변수

	if (tcsetattr(fd, TCSANOW, &new_attr) != 0) {
		fprintf(stderr, "터미널 속성을 설정할 수 없음.\n");
	}
	printf("다음 문장을 그대로 입력하세요.\n%s\n", text);
	if(linux_kbhit!=-1){ // 키보드 입력이 있을 시 사용하는 함수
		time(&start); //타이핑이 시작되면 시작 시간 저장
	}
	while ((nread=read(fd, &ch, 1)) > 0 && ch != '\n') {
		input++;
		if (ch == text[cnt++])
			write(fd, &ch, 1);
		else {
			write(fd, "*", 1);
			errcnt++;
		}
	}
	time(&end); //타이핑이 끝나면 끝나는 시간 저장
	printf("\n타이핑 오류의 횟수는 %d\n", errcnt);
	printf("분당 타수는 %ld\n", input*60/(end - start));
	tcsetattr(fd, TCSANOW, &init_attr);
	close(fd);
}

