#include <windows.h>
#include <stdio.h>
#include "yuhanCG.h"


// 도형을 나타내는 변수
bool isShapeVisible = 0;
enum ShapeType { NONE, BOX, CIRCLE, BONOBONO, RYAN, CUBE };
ShapeType currentShape = NONE;
POINT ptStart, ptEnd, ptOffset, ptMoveStart;
HWND hDrawingArea;
int isMouseRButtonPressed = 0;

HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0)); // 빨간색 박스
HBRUSH clear = CreateSolidBrush(RGB(255, 255, 255)); // 흰색

RECT rect;
bool isEyesClosed = 0;


void DrawShape(HWND hWnd, HDC hdc) {
    // 박스 그리기
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0)); // 빨간색 박스
    SelectObject(hdc, hBrush);
    switch (currentShape) {
    case BOX:
        Rectangle(hdc, ptStart.x, ptStart.y, ptEnd.x, ptEnd.y);
        break;
    case CIRCLE:
        Ellipse(hdc, ptStart.x, ptStart.y, ptEnd.x, ptEnd.y);
        break;
    case BONOBONO: {
        DrawBonobono(hWnd, hdc, isEyesClosed);
        break;
    }
    case RYAN: {
        RECT rect1 = { 0, 0, 800, 480 };
        FillRect(hdc, &rect1, clear);
        DrawRyan(hWnd, hdc, ptStart.x, ptStart.y, ptEnd.x, ptEnd.y);
        break;
    }

    case CUBE: {
        Drawcube(hWnd, hdc, ptStart, ptEnd);
        break;
    }
    }
        

    DeleteObject(hBrush);
}

// 윈도우 프로시저
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case 1: // 첫 번째 버튼 클릭
            currentShape = BOX;
            break;
        case 2: // 두 번째 버튼 클릭
            currentShape = CIRCLE;
            break;
        case 3:
            currentShape = BONOBONO;
            ptStart.x = 400;
            ptStart.y = 240;
            ptEnd.x = 400;
            ptEnd.y = 240;

            isShapeVisible = 0;	// 도형 그리기 종료
            InvalidateRect(hDrawingArea, NULL, 1);
            SetFocus(hDrawingArea);
            break;
        case 4:
            currentShape = RYAN;
            break;
        case 5:
            currentShape = CUBE;
            SetFocus(hDrawingArea);
            InvalidateRect(hDrawingArea, NULL, 1);
            break;
        }
        break;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        //DrawShape(hWnd, hdc);
        EndPaint(hWnd, &ps);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK DrawingProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch (Msg)
    {
    case WM_KEYDOWN:
        // 보노보노 눈감기 뜨기 로직
        if (wParam == VK_SPACE && !isEyesClosed) {
            isEyesClosed = 1;

            InvalidateRect(hWnd, NULL, 1);
        }
        break;

    case WM_KEYUP:
        if (wParam == VK_SPACE && isEyesClosed) {
            isEyesClosed = 0;

            InvalidateRect(hWnd, NULL, 1);
        }
        break;

    case WM_LBUTTONDOWN:	
        ptStart.x = LOWORD(lParam);
        ptStart.y = HIWORD(lParam);
        isShapeVisible = 1;	// 도형 그리기 시작
        break;

    case WM_MOUSEMOVE: {
        int mouseX = LOWORD(lParam);
        int mouseY = HIWORD(lParam);

        if (isMouseRButtonPressed) {
            int offsetX = mouseX - ptMoveStart.x;
            int offsetY = mouseY - ptMoveStart.y;
            static int sumX = 0;
            static int sumY = 0;
            sumX += offsetX;
            sumY += offsetY;

            rect = { ptStart.x, ptStart.y, ptEnd.x, ptEnd.y };

            if (currentShape == CIRCLE) {
                rect.right += offsetX;
                rect.bottom += offsetY;

                ptStart.y += 4;
                ptEnd.y += 4;

                sumX = 0; sumY = 0;
                
            }
            else {
                OffsetRect(&rect, offsetX, offsetY);
            }
            ptMoveStart.x = LOWORD(lParam);
            ptMoveStart.y = HIWORD(lParam);

            InvalidateRect(hDrawingArea, NULL, 1);
        }
        else {

            if (isShapeVisible) {
                ptEnd.x = mouseX;
                ptEnd.y = mouseY;

                InvalidateRect(hDrawingArea, NULL, 1);
            }
        }
        break;
    }
    case WM_LBUTTONUP:
        ptEnd.x = LOWORD(lParam);
        ptEnd.y = HIWORD(lParam);

        if (isShapeVisible)
            isShapeVisible = 0;	// 도형 그리기 종료
        InvalidateRect(hDrawingArea, NULL, 1);
        break;

    case WM_RBUTTONDOWN:
    {
        int mouseX = LOWORD(lParam);
        int mouseY = HIWORD(lParam);

        if (mouseX >= ptStart.x && mouseX <= ptEnd.x && mouseY >= ptStart.y && mouseY <= ptEnd.y) {
            isMouseRButtonPressed = 1;
            ptMoveStart.x = mouseX;
            ptMoveStart.y = mouseY;
        }
    }
    break;

    case WM_RBUTTONUP:
    {
        isMouseRButtonPressed = 0;
        InvalidateRect(hWnd, NULL, 1);
    }
    break;

    case WM_PAINT:
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        if (!isMouseRButtonPressed) {
            DrawShape(hWnd, hdc);

        }
        else {

            RECT rect1 = { 0, 0, 800, 480 };
            FillRect(hdc, &rect1, clear);
            if (currentShape == CIRCLE)
                Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom);
            else {
                Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
            }
            ptStart.x = rect.left;
            ptStart.y = rect.top;
            ptEnd.x = rect.right;
            ptEnd.y = rect.bottom;
        }
        EndPaint(hWnd, &ps);
        break;
    }
    return DefWindowProc(hWnd, Msg, wParam, lParam); // Call Default Window Procedure.
}

// 프로그램 진입점
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) {

    HWND hWnd;
    HWND hButtonBox, hButtonCircle, hButtonTriangle, hButtonLine, hButtonStop;
    HBRUSH hBrush[2] = { 0,0 };
    hBrush[0] = CreateSolidBrush(RGB(255, 240, 200));
    hBrush[1] = CreateSolidBrush(RGB(255, 255, 255));

    //여기랑 / 부모 윈도우
    WNDCLASSEX wcex = { 0 };
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = hBrush[0];
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"ButtonWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex)) {
        return 1;
    }

    //여기랑 뭔 차이지?? / 자식 윈도우?
    wcex.lpfnWndProc = DrawingProc;
    wcex.hbrBackground = hBrush[1];
    wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
    wcex.lpszClassName = TEXT("DrawingWindow");

    if (!RegisterClassEx(&wcex)) {
        return 1;
    }

    hWnd = CreateWindow(
        L"ButtonWindowClass", L"Midterm Exam", WS_OVERLAPPED | WS_SYSMENU,
        CW_USEDEFAULT, 0, 912, 628, NULL, NULL, hInstance, NULL);

    if (!hWnd) {
        return 0;
    }


    hButtonBox = CreateWindow(
        L"BUTTON", L"Box", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        16, 16, 160, 64, hWnd, (HMENU)1, hInstance, NULL);

    hButtonCircle = CreateWindow(
        L"BUTTON", L"Circle", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        192, 16, 160, 64, hWnd, (HMENU)2, hInstance, NULL);

    hButtonTriangle = CreateWindow(
        L"BUTTON", L"Bonobono", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        368, 16, 160, 64, hWnd, (HMENU)3, hInstance, NULL);

    hButtonLine = CreateWindow(
        L"BUTTON", L"Ryan", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        544, 16, 160, 64, hWnd, (HMENU)4, hInstance, NULL);

    hButtonStop = CreateWindow(
        L"BUTTON", L"Cube", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        720, 16, 160, 64, hWnd, (HMENU)5, hInstance, NULL);

    hDrawingArea = CreateWindow(
        L"DrawingWindow", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
        16, 96, 800, 480, hWnd, NULL, hInstance, NULL);


    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    DeleteObject(hBrush[0]);
    DeleteObject(hBrush[1]);

    return (int)msg.wParam;
}
