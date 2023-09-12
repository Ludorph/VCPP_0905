#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define ESC 27


 int main()
{
	 char ch;

	 printf("202114040\n");
	 printf("김한서\n");
	 printf("Application\n");



	 while (true)
	 {
		 printf("Command> ");

		 ch = _getch(); //scanf 대신 getch() 사용

		 if (ESC == ch)
		 {
			printf("취소되었습니다.\n");
			break;
		 }
			


		 

		 if (ch == 'p')
		 {
			 printf("p\n");
			 printf("나는 과제를 겁나 잘하는 학생이다.\n");
		 }

		 else if (ch == 'f')
		 {
			 printf("f\n");
			 printf("나는 과제가 너무 즐겁다\n");
		 }

		 else if (ch == 'j')
		 {
			 printf("j\n");
			 printf("교수님 과제 더 내주세요\n");
		 }

		 else
		 {
			 printf("p, f, j 중 다시 입력하세요\n");
		 }

	 }
	 return 0;
}


/*
* char 형으로만
1. 프로그램 시작

2. 문자열 출력 (printf로)
"202114040"
"김한서"
"Application"

3. 커서 입력 받기

command?

4.p 입력시
-> 과제를 잘하는 학생이다

f -> 과제가 너무 즐겁다

j -> 교수님 과제 더 내주세요

esc 누르는 순간 종료



*/