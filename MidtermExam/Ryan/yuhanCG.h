#pragma once

void DrawShape(HWND hWnd, HDC hdc);

void DrawBonobono(HWND hWnd, HDC hdc, int blink);

void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom);

HRGN Drawcube(HWND hWnd, HDC hdc, POINT ptStart, POINT ptEnd);
//void Movecube(POINT* minPoint, POINT* maxPoint, int deltaX, int deltaY);
