#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define ESC 27


 int main()
{
	 char ch;

	 printf("202114040\n");
	 printf("���Ѽ�\n");
	 printf("Application\n");



	 while (true)
	 {
		 printf("Command> ");

		 ch = _getch(); //scanf ��� getch() ���

		 if (ESC == ch)
		 {
			printf("��ҵǾ����ϴ�.\n");
			break;
		 }
			


		 

		 if (ch == 'p')
		 {
			 printf("p\n");
			 printf("���� ������ �̳� ���ϴ� �л��̴�.\n");
		 }

		 else if (ch == 'f')
		 {
			 printf("f\n");
			 printf("���� ������ �ʹ� ��̴�\n");
		 }

		 else if (ch == 'j')
		 {
			 printf("j\n");
			 printf("������ ���� �� ���ּ���\n");
		 }

		 else
		 {
			 printf("p, f, j �� �ٽ� �Է��ϼ���\n");
		 }

	 }
	 return 0;
}


/*
* char �����θ�
1. ���α׷� ����

2. ���ڿ� ��� (printf��)
"202114040"
"���Ѽ�"
"Application"

3. Ŀ�� �Է� �ޱ�

command?

4.p �Է½�
-> ������ ���ϴ� �л��̴�

f -> ������ �ʹ� ��̴�

j -> ������ ���� �� ���ּ���

esc ������ ���� ����



*/