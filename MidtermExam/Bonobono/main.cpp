#include <windows.h>

// 전역 변수, 전방선언
HINSTANCE hInst; //핸들러 인스턴스
HWND hWnd; //핸들러 윈도우
HWND hButtonBox, hButtonCircle, hButtonTriangle, hButtonBono, hButtonRyan;

enum ShapeType { NONE, BOX, CIRCLE, TRIANGLE, BONO, BONO2, RYAN }; //enum 타입의 구조체 선언 ShapeType
ShapeType currentShape = NONE; // ShapeType 구조체 currentShape 변수 선언, NONE으로 초기화

POINT ptStart, ptEnd; //포인트  구조체 두 개 선언, 각각 {x좌표, y좌표}를 가지고 있음
//ptTemp를 호출하는 함수에는 값 대신 포인터로 전달해주기?

bool isDragging = false; //드래그 중이냐 판단하는 불리언 변수 isDragging


void DrawBonobono(HWND hWnd, HDC hdc, int x, int y) {
    HBRUSH hBrush = CreateSolidBrush(RGB(80, 188, 223));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x - 60, y - 60, x + 60, y + 60);

    HBRUSH hMouthB = CreateSolidBrush(RGB(255, 150, 255));
    SelectObject(hdc, hMouthB);
    Ellipse(hdc, x - 10, y + 5, x + 10, y + 30);

    HBRUSH hMouthB2 = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hMouthB2);
    Ellipse(hdc, x - 1, y - 5, x + 23, y + 15);
    Ellipse(hdc, x - 23, y - 5, x + 1, y + 15);

    HBRUSH hNoseB = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hNoseB);
    Ellipse(hdc, x - 7, y - 10, x + 7, y + 5);
    MoveToEx(hdc, x + 15, y, NULL);
    LineTo(hdc, x + 35, y - 5);
    MoveToEx(hdc, x + 15, y + 5, NULL);
    LineTo(hdc, x + 37, y + 8);
    MoveToEx(hdc, x - 15, y, NULL);
    LineTo(hdc, x - 35, y - 5);
    MoveToEx(hdc, x - 15, y + 5, NULL);
    LineTo(hdc, x - 37, y + 8);

    HBRUSH hCloseB = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hCloseB);
    MoveToEx(hdc, x - 35, y - 30, NULL);
    LineTo(hdc, x - 20, y - 20);
    MoveToEx(hdc, x - 40, y - 10, NULL);
    LineTo(hdc, x - 20, y - 20);
    MoveToEx(hdc, x + 35, y - 30, NULL);
    LineTo(hdc, x + 20, y - 20);
    MoveToEx(hdc, x + 40, y - 10, NULL);
    LineTo(hdc, x + 20, y - 20);

}

void DrawBono2(HDC hdc, int x, int y) {


    HBRUSH hBrush = CreateSolidBrush(RGB(80, 188, 223));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x - 60, y - 60, x + 60, y + 60);

    HBRUSH hMouthB = CreateSolidBrush(RGB(255, 150, 255));
    SelectObject(hdc, hMouthB);
    Ellipse(hdc, x - 10, y + 5, x + 10, y + 30);

    HBRUSH hMouthB2 = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hMouthB2);
    Ellipse(hdc, x - 1, y - 5, x + 23, y + 15);
    Ellipse(hdc, x - 23, y - 5, x + 1, y + 15);

    HBRUSH hNoseB = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hNoseB);
    Ellipse(hdc, x - 7, y - 10, x + 7, y + 5);
    MoveToEx(hdc, x + 15, y, NULL);
    LineTo(hdc, x + 35, y - 5);
    MoveToEx(hdc, x + 15, y + 5, NULL);
    LineTo(hdc, x + 37, y + 8);
    MoveToEx(hdc, x - 15, y, NULL);
    LineTo(hdc, x - 35, y - 5);
    MoveToEx(hdc, x - 15, y + 5, NULL);
    LineTo(hdc, x - 37, y + 8);

    HBRUSH hEyeB = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hEyeB);
    Ellipse(hdc, x - 50, y - 10, x - 40, y - 20);
    Ellipse(hdc, x + 50, y - 10, x + 40, y - 20);

    HBRUSH hEyeBallB = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hEyeBallB);
    Ellipse(hdc, x - 48, y - 13, x - 42, y - 18);
    Ellipse(hdc, x + 48, y - 13, x + 42, y - 18);

}

void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom) {
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hBrush);
    /*크기를 ptStart, ptEnd로 받아서 그리게 ?
    * 보노보노처럼 얼굴 맨 가운데를 (0,0)으로 잡고, 드래그해서 그릴때의 늘어나는 정도(좌표값)를 상대값으로 늘어나게 계산
    int radius = min(abs(ptEnd.x - ptStart.x), abs(ptEnd.y - ptStart.y)) / 2;
    Ellipse(hdc, ptStart.x - radius, ptStart.y - radius, ptStart.x + ptEnd.x - ptStart.x, ptStart.y + ptEnd.y - ptStart.y); */


}


// 모양 그리기 함수
void DrawShape(HWND hWnd, HDC hdc) {
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0)); // 브러쉬 구조체 변수 hBrush 선언, 빨간색
    SelectObject(hdc, hBrush);

    if (!isDragging) {
        switch (currentShape) {
        case BOX:
            Rectangle(hdc, ptStart.x, ptStart.y, ptEnd.x, ptEnd.y);
            break;
        case CIRCLE: {
            int radius = min(abs(ptEnd.x - ptStart.x), abs(ptEnd.y - ptStart.y)) / 2;
            Ellipse(hdc, ptStart.x - radius, ptStart.y - radius, ptStart.x + ptEnd.x - ptStart.x, ptStart.y + ptEnd.y - ptStart.y);
            //Ellipse(hdc, ptStart.x - radius, ptStart.y - radius, ptStart.x + radius, ptStart.y + radius);
            break;
        }
        case TRIANGLE: {
            POINT pts[3] = { 0 };
            pts[0].x = (ptStart.x + ptEnd.x) / 2;
            pts[0].y = ptStart.y;
            pts[1].x = ptStart.x;
            pts[1].y = ptEnd.y;
            pts[2].x = ptEnd.x;
            pts[2].y = ptEnd.y;
            Polygon(hdc, pts, 3);
            break;
        }
        case BONO: {
            DrawBonobono(hWnd, hdc, ptStart.x + (ptStart.y - ptStart.x) / 2, ptStart.y + (ptStart.y - ptStart.x) / 2);
            break;
        }

        case BONO2: {
            DrawBono2(hdc, ptStart.x + (ptStart.y - ptStart.x) / 2, ptStart.y + (ptStart.y - ptStart.x) / 2);
            break;
        }

        case RYAN: {
            //DrawRyan(hWnd, hdc, ptStart.x + (ptStart.y - ptStart.x) / 2, ptStart.y + (ptStart.y - ptStart.x) / 2);
            break;
        }


        default:
            break;
        }
    }

    DeleteObject(hBrush);
}



// 윈도우 프로시저
/* 메세지 처리하는 콜백함수. 함수를 값으로 전달
WndProc 함수는 WinMain함수 보다 위쪽에 선언

#include <Windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, UINT wparam, LPARAM lparam)
{}
메시지 처리를 스위치로 해도 되고 if문으로 해도 됨

*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) { //콜백 : 전형적인 함수 포인터를 넘겨주는
    switch (message) {
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case 1:
            currentShape = BOX;
            break;
        case 2:
            currentShape = CIRCLE;
            break;
        case 3:
            currentShape = BONO;
            break;
        case 4:
            currentShape = RYAN;
            break;
        }
        /*
        BOOL InvalidateRect(
        HWND hWnd(무효화 할 윈도우, 다시 그려야할 윈도우의 핸들),
        CONST RECT *lpRect(무효화 할 영역 지정, NULL인 경우 윈도우 전체 무효화),
        BOOL bErase(무효화 되기 전 배경을 모두 지울 것인지 놔두고 그릴것인지 지정하는 값, True : 배경 지우고 다시 그림, False : 배경 놔두고 다시 그림
        );

        WM_CHAR 메시지나 WM_KEYDOWN 메시지가 발생하여 문자나 키가 입력되고 나서 InvalidateRect 함수를 호출, WM_PAINT메시지를 발생시켜 새로 윈도우를 부름
        쉽게 말해 두개의 윈도우가 겹쳐있다가 이동하였을때 뒤에 가려져 있어 보이지 않던 부분이 바로 무효화 영역
        InvalidateRect 함수를 이용하여 WM_PAINT메시지를 해당 윈도우에 보내 새롭게 윈도우를 그려 무효화 영역을 유효화 시키는 것
        */
        InvalidateRect(hWnd, NULL, TRUE);
        break;

        //스페이스바를 눌렀을때 만약 currentShape이 현재 BONO라면 BONO2로 변경
    case VK_SPACE:
        if (currentShape == BONO) {
            currentShape = BONO2;
        }
        break;
        

    case WM_LBUTTONDOWN:
        ptStart.x = LOWORD(lParam); //눌렀을때의 위치를 x에 저장
        ptStart.y = HIWORD(lParam); //눌렀을때의 위치를 y에 저장
        ptEnd = ptStart;
        isDragging = true;
        break;

    case WM_LBUTTONUP:
        if (isDragging) {
            ptEnd.x = LOWORD(lParam);
            ptEnd.y = HIWORD(lParam);
            isDragging = false;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;

    case WM_MOUSEMOVE:
        if (isDragging) {
            ptEnd.x = LOWORD(lParam);
            ptEnd.y = HIWORD(lParam);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;

    case WM_ERASEBKGND:
    {
        HDC hdc = (HDC)wParam;
        RECT rc;
        GetClientRect(hWnd, &rc);
        HBRUSH hBackgroundBrush = CreateSolidBrush(RGB(255, 240, 200));
        FillRect(hdc, &rc, hBackgroundBrush);
        DeleteObject(hBackgroundBrush);
        return (LRESULT)1;
    }

    //윈도우에 그릴때
    case WM_PAINT: {
        PAINTSTRUCT ps; //페인트  구조체
        HDC hdc = BeginPaint(hWnd, &ps); //(hdc 변수 선언 생략), 그리기 시작
        DrawShape(hWnd, hdc); //도형 그리기 부분
        EndPaint(hWnd, &ps); //그리기 해제
        break;
    }
    case WM_DESTROY: // 윈도우가 파괴될 때
        PostQuitMessage(0); //프로그램 종료
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam); //기본적인 메세지(최대, 최소화 등)를 윈도우가 모두 해주는 함수
    }
    return 0;
}

// 윈도우 초기화 함수
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
    hInst = hInstance;

    /*
    HWND CreateWindowA(
    클래스 이름(이름 붙인 것), 윈도우 타이틀(창 제목), 윈도우 스타일(크기 변경 가능한 윈도우),
    윈도우 위치 x 좌표, y 좌표,
    윈도우의 너비, 윈도우의 높이
    (CW_USEDEFAULT 윈도우의 위치와 크기 알아서 정해줌, 일반 정수로도 기입 가능),
    부모 윈도우 핸들, 메뉴,
    핸들 인스턴스, 윈도우 정보(핸들 인스턴스 빼고 다 0이나 NULL));
    */
    hWnd = CreateWindow(
        L"ButtonWindowClass", L"Win32 Shapes Drawing", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, 800, 480, NULL, NULL, hInstance, NULL);

    if (!hWnd) {
        return FALSE;
    }

    hButtonBox = CreateWindow(
        L"BUTTON", L"Draw Box", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        0, 20, 160, 64, hWnd, (HMENU)1, hInstance, NULL);

    hButtonCircle = CreateWindow(
        L"BUTTON", L"Draw Circle", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        160, 20, 160, 64, hWnd, (HMENU)2, hInstance, NULL);

    hButtonBono = CreateWindow(
        L"BUTTON", L"Draw BonoBono", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        320, 20, 160, 64, hWnd, (HMENU)3, hInstance, NULL);

    hButtonRyan = CreateWindow(
        L"BUTTON", L"Draw Ryan", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        480, 20, 160, 64, hWnd, (HMENU)4, hInstance, NULL);

    hButtonTriangle = CreateWindow(
        L"BUTTON", L"Cube", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        640, 20, 160, 64, hWnd, (HMENU)5, hInstance, NULL);

    /* 윈도우 보여주게 하는 함수. 
    ShowWindow(
    HWND(창에대한 핸들),
    int(ShowWindow가 처음 호출될 때 값은 해당 nCmdShow 매개 변수에서 WinMain 함수에서 가져온 값이어야함)
    ) */
    ShowWindow(hWnd, nCmdShow);

    /* 메세지를 전송함으로써 무효화된 영역을 다시 그려주는 함수. BOOL UpdateWindow(HWND hWnd);
    성공하면 0이 아닌 값을 리턴하며 에러 발생시 0을 리턴한다.

    이 함수는 윈도우 프로시저로 WM_PAINT 메시지를 보내 작업영역을 강제로 그리도록 한다.
    WM_PAINT 메시지는 우선 순위가 늦기 때문에 무효 영역이 있더라도 먼저 처리해야할 다른 메시지가 있으면 즉시 처리되지 않는다.
    만약 다른 어떤 메시지보다도 WM_PAINT를 먼저 처리해야 할 필요가 있다면 이 함수를 호출하여 즉시 작업영역을 다시 그리도록 할 수 있다.

    이 함수는 메시지 큐를 통하지 않고 윈도우 프로시저로 곧바로 WM_PAINT 메시지를 전달하므로 메시지 대기 순서에 상관없이 즉시 작업영역을 다시 그리도록 한다.
    그러나 작업영역에 무효영역이 없으면 이 함수를 호출한다하더라도 WM_PAINT 메시지는 보내지지 않는다.
    작업영역을 완전히 다시 즉시 그리려면    teRect 함수로 작업영역을 무효화한 후 이 함수를 호출하면 된다.
    */
    UpdateWindow(hWnd);

    return TRUE;
}

// 프로그램 진입점, main함수 역할, 4개의 매개변수
/*
int WINAPI WinMain / wWinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);

CALLBACK = WINAPI = APIENTRY
CALLBACK과 APIENTRY는 가독성의 의미로 다를뿐이고 CALLBACK은 같다.

hInstance 는 인스턴스에 대한 핸들 이거나 모듈에 대한 핸들입니다. 운영 체제는 이 값을 사용하여 메모리에 로드될 때 실행 파일 또는 EXE를 식별합니다.
특정 Windows 함수에는 인스턴스 핸들이 필요합니다(예: 아이콘 또는 비트맵 로드).
hPrevInstance는 의미가 없습니다. 16비트 Windows에서 사용되었지만 이제는 항상 0입니다.
pCmdLine에는 명령줄 인수가 유니코드 문자열로 포함되어 있습니다.
nCmdShow 는 기본 애플리케이션 창이 최소화, 최대화 또는 정상적으로 표시되는지 여부를 나타내는 플래그입니다.
*/
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) {
    WNDCLASSEX wcex = { 0, }; //윈도우 클래스 선언 (0으로 초기화)

    wcex.cbSize = sizeof(WNDCLASSEX); // 윈도우 구조체 크기 설정함
    wcex.style = CS_HREDRAW | CS_VREDRAW; //윈도우 스타일 설정, 크기가 변하면 다시 그린다
    wcex.lpfnWndProc = WndProc; // 윈도우 프로시저
    wcex.cbClsExtra = 0; //클래스, 윈도우 메모리 지정
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance; //핸들 인스턴스 설정
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION); //아이콘 변경
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW); //커서 변경
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); //여기선 GetStockObject 함수가 안쓰임, 흰색 배경화면 불러옴. (HBRUSH)GetStockObject(WHITE_BRUSH); 가능
    wcex.lpszMenuName = NULL; //메뉴 이름
    wcex.lpszClassName = L"ButtonWindowClass"; //WCHAR형 문자열의 값을 가지기 때문에 L(라터럴)"~"을 사용하여 값을 셋팅, 윈도우 클래스 이름 설정
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION); //작은 아이콘
    //RegisterClassExA(&wcex);

    if (!RegisterClassEx(&wcex)) {
        return 1;
    }

    if (!InitInstance(hInstance, nCmdShow)) {
        return 1;
    }

    /*
    메세지 처리는 프로그램이 끝날 때 까지 계속됩니다.
    그 동안 GetMessageA함수로 메세지를 받습니다.
    이 함수의 반환값은 MSG(메세지 변수)

    + 메세지 처리하고 반복하는 과정 필요
    */
    MSG msg; //메시지 구조체 변수 선언
    while (GetMessage(&msg, NULL, 0, 0)) { //while로 메세지 받기 반복 
        TranslateMessage(&msg); //메세지 번역
        DispatchMessage(&msg); //메세지 처리
    }

    return (int)msg.wParam;
}


/* 주석 정리

윈도우가 만들어지는 과정

    1.윈도우 속성 설정
    2.윈도우 생성
    3.메세지 계속 처리 (반복)


윈도우 클래스

    윈도우의 속성은 WNDCLASSEXA라는 해괴한 구조체로 설정

    멤버 / 타입 / 설명

    cbSize / unsigned int / 구조체의 크기 결정

    style / unsigned int / 출력 형태

    lpfnWndProc / WNDPROC / 프로시저 함수

    cbClsExtra / int / 클래스, 윈도우 메모리 지정, 딱히 쓸데 없음

    hInstance / HANDLE / 윈도우 인스턴스

    hIcon / HICON / 아이콘 변경

    hCursor / HCURSOR / 커서 변경

    hbrBackground / HBRUSH / 배경 색

    lpszMenuName / const char* / 메뉴 이름, 필요 없음

    lpszClassName / const char* / 클래스 이름

    hIconSm / HICON / 작은 아이콘, 필요없음


HWND = 윈도우 핸들
    프로그램마다 고유의 ID = 핸들 인스턴스
    윈도우에서의 프로그램 고유 ID = 윈도우 핸들 = 윈도우 고유 ID


WndProc 함수가 가지는 4가지 매개변수
    이름 / 타입 / 설명
    hwnd / HWND / 윈도우 핸들

    msg / unsigned int (UINT) / 윈도우 메세지

    wparam / unsigned int (UINT)
    lparam / long (32비트)
    / 키 입력, 마우스 입력 등, 이벤트가 발생할 때 전달되는 변수


    윈도우 창은 메시지 기반으로 작동.
    마우스, 키보드, 버튼 입력 등은 운영체제 내부에 시스템 메시지 큐에 쌓이게 됨.
    메시지들이 쌓여서 각각의 프로그램에 있는 윈도우 창들이 윈도우 메시지 큐를 갖고 있고
    운영체제는 이 메시지들을 응용프로그램 메시지큐에 전송해주는 역할
    딱 전달만 해줌


메시지 처리
    윈도우는 실행 되는 동안 지속적으로 메시지 받음
    창 실행, 닫힘 등등 특정 시점에서 보내짐
    윈도우 메세지는 WndProc 함수의 msg 변수가 받습니다. (unsigned int형)
    WM_~~

    1. WM_CREATE
    윈도우가 생성되면 나오는 메세지입니다.
    메세지를 처음 처리할 때, 이 메세지를 받습니다.

    2. WM_DESTROY
    윈도우가 종료되면 (X버튼 누르면) 나오는 메세지입니다.

    3. WM_PAINT
    윈도우의 그래픽을 발생하는 메세지입니다.

    4. WM_KEYDOWN, WM_KEYUP
    키보드의 특수 키(shift, enter 등)를 누르거나(DOWM) 떼면(UP) 생기는 메세지입니다.

    5. WM_CHAR
    일반적인 문자 키(영어 등)를 누르면 생기는 메세지입니다.

    6. WM_COMMAND
    윈도우의 메뉴 등을 누르면 생기는 메세지입니다.

    7. WM_LBUTTONDOWN, WM_LBUTTONUP
    왼쪽 마우스를 누르거나 뗄 떼 발생하는 메세지

    8. WM_RBUTTONDOWN, WM_RBUTTONUP
    오른쪽 마우스를 누르거나 뗄 떼 발생하는 메세지


디바이스 콘텍스트(DC)
    1.DC 얻기
    2.도형, 텍스트 얻기
    3.DC 해제

    일반적으로 dc는 HDC 타입에 저장,
    BeginPaint 함수로 얻어야 함
    EndPaint 함수로 해제

    또한 페인트 구조체(PAINTSTRUCT)라는게 필요

    PAINTSTRUCT ps; //이거 먼저 선언
    HDC hdc = BeginPaint(&ps); //dc 얻기
    EndPaint(윈도우 핸들, &ps); //dc

    그림을 그릴 영역을 BeginPaint로 얻은 뒤, EndPaint로 해제


GDI오브젝트
    그래픽 출력에 사용되는 도구
    펜, 브러시, 비트맵, 폰트 등등
    GDI 오브젝트를 모아놓은 것이 DC


SelectObject(),
    DC에 GDI 오브젝트를 선택하는 함수. 반환형은 기존에 가지고있던 오브젝트의 핸들.

DeleteObject()
    GetStockObject로 받은 오브젝트를 제외한 오브젝트는 사용하고 난 오브젝트는 삭제해주어야 한다.
    왜냐하면 메모리를 잡아먹기 때문


화면에 도형 그리기
    MoveToEx(HDC, x1, y1, NULL)
        커서의 위치를 변경시킨다.
        NULL은 0과 같음
    LineTo(HDC, x2, y2)
        기존 커서의 위치부터 넘겨주는 위치까지 선을 그린다.
    Rectangle(HDC, x1, y1, x2, y2)
        사각형을 그려주는 함수
    Ellipse(HDC, x1, y1, x2, y2)
        원을 그려주는 함수


hMenu
    메뉴의 핸들 혹은 자식 윈도우(컨트롤)의 식별자(ID)입니다
    팝업 윈도우의 경우 윈도우에서 이 인수는 사용될 메뉴를 의미하며 NULL 값을 가질 수 있습니다.
    자식 윈도우(컨트롤)의 경우 이 인수는 자식 윈도우의 ID를 의미하며 ID는 다른 컨트롤과 중복되지 않는 정수 값을 가져야 합니다.


WPARAM, LPARAM, HIWORD, LOWORD
    WPARAM
        쉽게 말하지만, 논리형이며 키값이 눌러졌는지 상태를 확인한다.

    LPARAM
        좌표의 의미를 가지며, 4바이트로 이루어져있다.
        2바이트씩 잘라서 x,y  좌표 값으로 사용

    HIWORD
        Y의 값
    LOWORD
        X의 값﻿


피크 메세지

*/