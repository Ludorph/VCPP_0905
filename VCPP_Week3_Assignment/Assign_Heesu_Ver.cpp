#include <iostream>  
#include <conio.h>   
#include <chrono>    
#include <thread>    

int main()
{
    const char ESC = 27;     
    const char UP = 72;      
    const char LEFT = 75;    
    const char RIGHT = 77;   
    const char DOWN = 80;    
    const char A = 97;       
    //��ũ�� �Լ� ��� ��� ����, ����Ű�� a

    char cmd;               // Ŀ�ǵ�
    char cmd2 = 0;      // ������ �Էµ� Ŀ�ǵ�
    int st = 0;          // ���¸� ��Ÿ���� ����

    std::cout << "Ŀ�ǵ� �Է�\n";

    while (1)
    {
        cmd = _getch();  

        if (cmd == UP)  // ����Ű ��
        {
            st = 0;  // �ʱ� ���� 0

            std::cout << "��";  // ����Ű �� ���
            if (cmd2 == DOWN)  // ���� �Է�
            {
                st = 4;  // 4�� ����� ������ ����
            }
            cmd2 = UP;  // ������ �Է� '��'�� ����
        }

        else if (cmd == LEFT)  // �Է� '��'�� ���
        {
            st = 0;
            std::cout << "��";  // ȭ�鿡 '��' ���
            cmd2 = LEFT;  // ������ �Է� '��'�� ����
        }
        else if (cmd == RIGHT)  // �Է�'��'�� ���
        {
            st = 0;
            std::cout << "��";  // ȭ�鿡 '��' ���
            if (cmd2 == DOWN)  // ������ �Է� '��'�� ���
            {
                st = 1;  // ���¸� 1(�Ƶ���)���� ����
            }
            else if (cmd2 == LEFT)  // ������ �Է�'��'�� ���
            {
                st = 3;  // ���¸� 3(�ر�)���� ����
            }
            cmd2 = RIGHT;  // ������ �Է� '��'�� ����
        }
        else if (cmd == DOWN)  // �Է� '��'�� ���
        {
            st = 0;
            std::cout << "��";  // ȭ�鿡 '��' ���
            if (cmd2 == RIGHT)  // ������ �Է� '��'�� ���
            {
                st = 2;  // ���¸� 2(�ϴ�)�� ����
            }
            cmd2 = DOWN;  // ������ �Է�'��'�� ���� 
        }
        else if (cmd == A)  // �Է� 'a'�� ���
        {
            std::cout << "a";  // ȭ�鿡 'a' ���
            if (st == 1)  // 1�� �Ƶ���
            {
                std::cout << "\n�Ƶ���! =o\n";  // "�Ƶ���! =o"
            }
            else if (st == 2)  // 2�� �ϴ�
            {
                std::cout << "\n�ϴ�!\n";  // "�ϴ�!"
            }
            else if (st == 3)  // 3�� �ر�
            {
                std::cout << "\n�ر�!\n";  // "�ر�"
            }
            else if (st == 4)  //4�� ���
            {
                std::cout << "\n���!\n";  // "���"
            }
            st = 0;
            cmd2 = A;  // ������ �Էµ� Ŀ�ǵ带 ����Ű 'a'�� ����
        }

        else if (cmd == ESC)  
        {
            return 0;
        }

        else if (cmd == -32)  // Ư��Ű �Է��� ó��
        {
            continue;  // ���� Ŀ�ǵ�� ��Ƽ��
        }

        else
        {
            st = 0;
            std::cout << cmd; 
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(300));  // 0.3��(300ms) �ð� ����
    }

    return 0;
}