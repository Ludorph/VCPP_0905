#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <chrono>

int main()
{
    printf("����� �ູ�� VC++");
    Sleep(3000);
    system("cls");

    char cmd;
    char buffer[100] = { 0, };

    while (1)
    {
        int i = 0;
        printf("command>");

        while (1)
        {
            cmd = _getch();

            if (cmd == 27)
            {
                return 0;
            }
            else if (cmd == 13)
            {
                buffer[i] = '\0';
                break;
            }
            else
            {
                buffer[i] = cmd;
                printf("%c", cmd);
                i++;
            }
        }

        if (strcmp(buffer, "q") == 0)
        {
            printf("\nqwer ȭ����\n");
        }
        else if (strcmp(buffer, "w") == 0)
        {
            printf("\n���� �ʹ� ����\n");
        }
        else if (strcmp(buffer, "e") == 0)
        {
            printf("\n���ֺ��� ������ 3���\n");
        }
        else if (strcmp(buffer, "r") == 0)
        {
            printf("\n�ູ�մϴ�.\n");
        }
        else
        {
            printf("\n�߸��� Ŀ�ǵ��Դϴ� (q, w, e, r, �߿� �Է��� �ּ���)\n");
        }
    }

    return 0;
}