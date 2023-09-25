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
    //매크로 함수 대신 상수 선언, 방향키와 a

    char cmd;               // 커맨드
    char cmd2 = 0;      // 이전에 입력된 커맨드
    int st = 0;          // 상태를 나타내는 변수

    std::cout << "커맨드 입력\n";

    while (1)
    {
        cmd = _getch();  

        if (cmd == UP)  // 방향키 위
        {
            st = 0;  // 초기 상태 0

            std::cout << "↑";  // 방향키 위 출력
            if (cmd2 == DOWN)  // 이전 입력
            {
                st = 4;  // 4번 기술이 가능한 상태
            }
            cmd2 = UP;  // 이전에 입력 '↑'로 설정
        }

        else if (cmd == LEFT)  // 입력 '←'일 경우
        {
            st = 0;
            std::cout << "←";  // 화면에 '←' 출력
            cmd2 = LEFT;  // 이전에 입력 '←'로 설정
        }
        else if (cmd == RIGHT)  // 입력'→'일 경우
        {
            st = 0;
            std::cout << "→";  // 화면에 '→' 출력
            if (cmd2 == DOWN)  // 이전에 입력 '↓'일 경우
            {
                st = 1;  // 상태를 1(아도겐)으로 설정
            }
            else if (cmd2 == LEFT)  // 이전에 입력'←'일 경우
            {
                st = 3;  // 상태를 3(붕권)으로 설정
            }
            cmd2 = RIGHT;  // 이전에 입력 '→'로 설정
        }
        else if (cmd == DOWN)  // 입력 '↓'일 경우
        {
            st = 0;
            std::cout << "↓";  // 화면에 '↓' 출력
            if (cmd2 == RIGHT)  // 이전에 입력 '→'일 경우
            {
                st = 2;  // 상태를 2(하단)로 설정
            }
            cmd2 = DOWN;  // 이전에 입력'↓'로 설정 
        }
        else if (cmd == A)  // 입력 'a'일 경우
        {
            std::cout << "a";  // 화면에 'a' 출력
            if (st == 1)  // 1번 아도겐
            {
                std::cout << "\n아도겐! =o\n";  // "아도겐! =o"
            }
            else if (st == 2)  // 2번 하단
            {
                std::cout << "\n하단!\n";  // "하단!"
            }
            else if (st == 3)  // 3번 붕권
            {
                std::cout << "\n붕권!\n";  // "붕권"
            }
            else if (st == 4)  //4번 상단
            {
                std::cout << "\n상단!\n";  // "상단"
            }
            st = 0;
            cmd2 = A;  // 이전에 입력된 커맨드를 방향키 'a'로 설정
        }

        else if (cmd == ESC)  
        {
            return 0;
        }

        else if (cmd == -32)  // 특수키 입력을 처리
        {
            continue;  // 다음 커맨드로 컨티뉴
        }

        else
        {
            st = 0;
            std::cout << cmd; 
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(300));  // 0.3초(300ms) 시간 지연
    }

    return 0;
}