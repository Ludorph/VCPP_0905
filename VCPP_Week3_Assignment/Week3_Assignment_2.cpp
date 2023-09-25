#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
//H, K, P, M

int main(void) {
    const char ESC = 27;     // ESC 키의 ASCII 값 상수 선언
    const char UP = 72;      // 방향키 '↑'의 ASCII 값 상수 선언
    const char LEFT = 75;    // 방향키 '←'의 ASCII 값 상수 선언
    const char RIGHT = 77;   // 방향키 '→'의 ASCII 값 상수 선언
    const char DOWN = 80;    // 방향키 '↓'의 ASCII 값 상수 선언
    const char A = 97;
    //상수로 선언하지 않고 하면 if(c == -32)를 받아줘야지 정상적으로 방향키 인식

    char c;
    char cBuffer[100] = { 0, };

    while (1) {
        if (_kbhit()) {               // 2. while문안에서 키보드 눌렸을 시 if문이 실행된다.
            int i = 0;

            while (1)
            {    

                c = _getch();           // 3. 방향키가 입력됬을 때 224 00 이 버퍼에 있다. 224부터 빼준다.

                if (c == 27)
                {
                    return 0;
                }

                //if (c == -32) {           // 4. -32로 입력되면
                c = _getch();        // 5. 뒤의 값 00을 판별하여 좌우상하 출력



                    if (c == LEFT )
                    {
                        printf("좌로 이동\n");
                        printf("%s", cBuffer);
                    }
                    else if (c == RIGHT)
                    {
                        printf("우로 이동\n");
                        printf("%s", cBuffer);
                    }
                    else if (c == UP)
                    {
                        printf("위로 이동\n");
                        printf("%s", cBuffer);
                    }
                    else if (c == DOWN)
                    {
                        printf("아래로 이동\n");
                        printf("%s", cBuffer);
                    }
                    cBuffer[i] = c;
                    i++;
                    

                    if (cBuffer[0] == DOWN && cBuffer[1] == RIGHT)
                    {
                        printf("아도겐");
                        cBuffer[100] = { 0, };
                        break;
                    }

                    std::this_thread::sleep_for(std::chrono::milliseconds(300));  // 0.3초(300ms) 시간 지연
                }
            
        }
    }
    return 0;
}

/*
kbhit를 하면 크로노 안의 메소드를 이용해서 0.3초동안 입력을 받고, 끝나면 버퍼 지우고 break; getch 입력 반복
0.3초 동안 getch 입력을 받고 그 받은 값을 다른 버퍼 배열에 넣어놓음 + 인덱스 i++, 0.3초가 끝나면 지우기

*/