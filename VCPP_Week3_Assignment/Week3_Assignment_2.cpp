#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
//H, K, P, M

int main(void) {
    const char ESC = 27;     // ESC Ű�� ASCII �� ��� ����
    const char UP = 72;      // ����Ű '��'�� ASCII �� ��� ����
    const char LEFT = 75;    // ����Ű '��'�� ASCII �� ��� ����
    const char RIGHT = 77;   // ����Ű '��'�� ASCII �� ��� ����
    const char DOWN = 80;    // ����Ű '��'�� ASCII �� ��� ����
    const char A = 97;
    //����� �������� �ʰ� �ϸ� if(c == -32)�� �޾������ ���������� ����Ű �ν�

    char c;
    char cBuffer[100] = { 0, };

    while (1) {
        if (_kbhit()) {               // 2. while���ȿ��� Ű���� ������ �� if���� ����ȴ�.
            int i = 0;

            while (1)
            {    

                c = _getch();           // 3. ����Ű�� �Է��� �� 224 00 �� ���ۿ� �ִ�. 224���� ���ش�.

                if (c == 27)
                {
                    return 0;
                }

                //if (c == -32) {           // 4. -32�� �ԷµǸ�
                c = _getch();        // 5. ���� �� 00�� �Ǻ��Ͽ� �¿���� ���



                    if (c == LEFT )
                    {
                        printf("�·� �̵�\n");
                        printf("%s", cBuffer);
                    }
                    else if (c == RIGHT)
                    {
                        printf("��� �̵�\n");
                        printf("%s", cBuffer);
                    }
                    else if (c == UP)
                    {
                        printf("���� �̵�\n");
                        printf("%s", cBuffer);
                    }
                    else if (c == DOWN)
                    {
                        printf("�Ʒ��� �̵�\n");
                        printf("%s", cBuffer);
                    }
                    cBuffer[i] = c;
                    i++;
                    

                    if (cBuffer[0] == DOWN && cBuffer[1] == RIGHT)
                    {
                        printf("�Ƶ���");
                        cBuffer[100] = { 0, };
                        break;
                    }

                    std::this_thread::sleep_for(std::chrono::milliseconds(300));  // 0.3��(300ms) �ð� ����
                }
            
        }
    }
    return 0;
}

/*
kbhit�� �ϸ� ũ�γ� ���� �޼ҵ带 �̿��ؼ� 0.3�ʵ��� �Է��� �ް�, ������ ���� ����� break; getch �Է� �ݺ�
0.3�� ���� getch �Է��� �ް� �� ���� ���� �ٸ� ���� �迭�� �־���� + �ε��� i++, 0.3�ʰ� ������ �����

*/