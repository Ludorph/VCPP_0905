#include <windows.h>
#include <stdio.h>
#include <cmath>
#include "yuhanCG.h"

extern POINT ptStart, ptEnd, ptOffset, ptMoveStart;


void DrawBonobono(HWND hWnd, HDC hdc, int blink)
{
    HBRUSH hSkinBrush = CreateSolidBrush(RGB(127, 200, 255));
    SelectObject(hdc, hSkinBrush);
    Ellipse(hdc, ptStart.x - 100, ptEnd.y - 100, ptStart.x + 100, ptEnd.y + 100);

    HBRUSH hMouthBrush = CreateSolidBrush(RGB(255, 150, 255));
    SelectObject(hdc, hMouthBrush);
    Ellipse(hdc, ptStart.x - 15, ptEnd.y + 10, ptStart.x + 15, ptEnd.y + 50);

    HBRUSH hNoseBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hNoseBrush);
    Ellipse(hdc, ptStart.x - 1, ptEnd.y - 10, ptStart.x + 33, ptEnd.y + 23);
    Ellipse(hdc, ptStart.x - 33, ptEnd.y - 10, ptStart.x + 1, ptEnd.y + 23);

    HBRUSH hBeardBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBeardBrush);
    Ellipse(hdc, ptStart.x - 15, ptEnd.y - 25, ptStart.x + 15, ptEnd.y + 2);
    MoveToEx(hdc, ptStart.x + 20, ptEnd.y, NULL);
    LineTo(hdc, ptStart.x + 45, ptEnd.y - 8);
    MoveToEx(hdc, ptStart.x + 20, ptEnd.y + 10, NULL);
    LineTo(hdc, ptStart.x + 47, ptEnd.y + 14);
    MoveToEx(hdc, ptStart.x - 20, ptEnd.y, NULL);
    LineTo(hdc, ptStart.x - 45, ptEnd.y - 8);
    MoveToEx(hdc, ptStart.x - 20, ptEnd.y + 10, NULL);
    LineTo(hdc, ptStart.x - 47, ptEnd.y + 14);


    HBRUSH hEyeBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hEyeBrush);
    if (!blink) {
        Ellipse(hdc, ptStart.x - 80, ptEnd.y - 30, ptStart.x - 65, ptEnd.y - 15);
        Ellipse(hdc, ptStart.x + 65, ptEnd.y - 30, ptStart.x + 80, ptEnd.y - 15);

        HBRUSH hEyeBallBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hEyeBallBrush);
        Ellipse(hdc, ptStart.x - 78, ptEnd.y - 20, ptStart.x - 70, ptEnd.y - 27);
        Ellipse(hdc, ptStart.x + 70, ptEnd.y - 27, ptStart.x + 78, ptEnd.y - 20);

        DeleteObject(hEyeBallBrush);
    }
    else {
        MoveToEx(hdc, ptStart.x - 70, ptEnd.y - 20, NULL);
        LineTo(hdc, ptStart.x - 80, ptEnd.y - 28);
        MoveToEx(hdc, ptStart.x - 70, ptEnd.y - 18, NULL);
        LineTo(hdc, ptStart.x - 80, ptEnd.y - 10);

        MoveToEx(hdc, ptStart.x + 80, ptEnd.y - 28, NULL);
        LineTo(hdc, ptStart.x + 70, ptEnd.y - 18);
        MoveToEx(hdc, ptStart.x + 80, ptEnd.y - 10, NULL);
        LineTo(hdc, ptStart.x + 70, ptEnd.y - 18);
    }
    DeleteObject(hSkinBrush);
    DeleteObject(hEyeBrush);
    DeleteObject(hNoseBrush);
    DeleteObject(hMouthBrush);
    DeleteObject(hBeardBrush);
}

void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom)
{
    POINT minPoint = { 0, };
    POINT maxPoint = { 0, };
    POINT centerPoint = { 0, };

    minPoint.x = min(left, right);
    minPoint.y = min(top, bottom);
    maxPoint.x = max(left, right);
    maxPoint.y = max(top, bottom);

    int width = abs(minPoint.x - maxPoint.x);
    int height = abs(minPoint.y - maxPoint.y);
    int centerX = width / 2;
    int centerY = height / 2;
    centerPoint.x = minPoint.x + centerX;
    centerPoint.y = minPoint.y + centerY;

    HBRUSH hSkinBrush = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hSkinBrush);

    // ±Í,¾ó±¼
    Ellipse(hdc, minPoint.x, minPoint.y, minPoint.x + width / 3, minPoint.y + height / 3);
    Ellipse(hdc, maxPoint.x, minPoint.y, maxPoint.x - width / 3, minPoint.y + height / 3);
    Ellipse(hdc, minPoint.x, minPoint.y, maxPoint.x, maxPoint.y);


    HBRUSH hEyeBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hEyeBrush);

    // ¿ÞÂÊ ´«½ç
    MoveToEx(hdc, minPoint.x + centerX / 4, minPoint.y + centerY / 3 * 2, NULL);
    LineTo(hdc, minPoint.x + (centerX / 4 * 3), minPoint.y + (centerY / 3 * 2));
    MoveToEx(hdc, minPoint.x + centerX / 4, minPoint.y + centerY / 3 * 2 + 2, NULL);
    LineTo(hdc, minPoint.x + (centerX / 4 * 3), minPoint.y + (centerY / 3 * 2) + 2);
    MoveToEx(hdc, minPoint.x + centerX / 4, minPoint.y + centerY / 3 * 2 + 4, NULL);
    LineTo(hdc, minPoint.x + (centerX / 4 * 3), minPoint.y + (centerY / 3 * 2) + 4);
    // ¿À¸¥ÂÊ ´«½ç
    MoveToEx(hdc, maxPoint.x - centerX / 4, minPoint.y + centerY / 3 * 2, NULL);
    LineTo(hdc, maxPoint.x - (centerX / 4 * 3), minPoint.y + (centerY / 3 * 2));
    MoveToEx(hdc, maxPoint.x - centerX / 4, minPoint.y + centerY / 3 * 2 + 2, NULL);
    LineTo(hdc, maxPoint.x - (centerX / 4 * 3), minPoint.y + (centerY / 3 * 2) + 2);
    MoveToEx(hdc, maxPoint.x - centerX / 4, minPoint.y + centerY / 3 * 2 + 4, NULL);
    LineTo(hdc, maxPoint.x - (centerX / 4 * 3), minPoint.y + (centerY / 3 * 2) + 4);

    // ´«µ¿ÀÚ
    POINT lEyePoint = { minPoint.x + centerX / 2, minPoint.y + (centerY / 6 * 5) };
    POINT rEyePoint = { maxPoint.x - centerX / 2, minPoint.y + (centerY / 6 * 5) };
    Ellipse(hdc, lEyePoint.x, lEyePoint.y, lEyePoint.x + width / 20, lEyePoint.y + height / 20);
    Ellipse(hdc, rEyePoint.x, rEyePoint.y, rEyePoint.x - width / 20, rEyePoint.y + height / 20);


    HBRUSH hNoseBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hNoseBrush);

    // ÄÚ
    Ellipse(hdc, centerPoint.x - centerX / 5, centerPoint.y, centerPoint.x, centerPoint.y + centerY / 5);
    Ellipse(hdc, centerPoint.x, centerPoint.y, centerPoint.x + centerX / 5, centerPoint.y + centerY / 5);

    DeleteObject(hSkinBrush);
    DeleteObject(hEyeBrush);
    DeleteObject(hNoseBrush);
}

HRGN Drawcube(HWND hWnd, HDC hdc, POINT startPoint, POINT endPoint) {
	// Áß¾Ó¼± ³ªÁß¿¡ Áö¿ï°Í
	/*
	MoveToEx(hdc, 376, 0, NULL);
	LineTo(hdc, 376, 480);
	MoveToEx(hdc, 0, 188, NULL);
	LineTo(hdc, 800, 188);
	*/

	int width = abs(startPoint.x - endPoint.x);
	int height = abs(startPoint.y - endPoint.y);
	int centerX = width / 2;
	int centerY = height / 2;

	POINT MINPOINT = { 0 };
	POINT MAXPOINT = { 0 };

	MINPOINT.x = min(startPoint.x, endPoint.x);
	MINPOINT.y = min(startPoint.y, endPoint.y);
	MAXPOINT.x = max(startPoint.x, endPoint.x);
	MAXPOINT.y = max(startPoint.y, endPoint.y);

	POINT centerPoint = { MINPOINT.x + centerX, MINPOINT.y + centerY };

	if (MINPOINT.x <= 376 && MINPOINT.y < 188) {//ÁÂ»ó
		MoveToEx(hdc, MINPOINT.x, MAXPOINT.y, NULL); //¹Ø¸é ¹Ý½Ã°è¼ø
		LineTo(hdc, MAXPOINT.x - centerX / 2, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x, MAXPOINT.y - centerY / 2);
		LineTo(hdc, MINPOINT.x + centerX / 2, MAXPOINT.y - centerY / 2);
		LineTo(hdc, MINPOINT.x, MAXPOINT.y);

		MoveToEx(hdc, MAXPOINT.x, MAXPOINT.y - centerY / 2, NULL); // ¾Õ¸é ¹Ý½Ã°è¼ø
		LineTo(hdc, MAXPOINT.x, MINPOINT.y);
		LineTo(hdc, MINPOINT.x + centerX / 2, MINPOINT.y);
		LineTo(hdc, MINPOINT.x + centerX / 2, MAXPOINT.y - centerY / 2);

		MoveToEx(hdc, MINPOINT.x + centerX / 2, MINPOINT.y, NULL); // ¿·¸é ¿ìÇÏ½ÃÀÛ ¹Ý½Ã°è
		LineTo(hdc, MINPOINT.x, MINPOINT.y + centerY / 2);
		LineTo(hdc, MINPOINT.x, MAXPOINT.y);

		POINT hexaPoints[6] = {
		   {MINPOINT.x, MAXPOINT.y}, // 1¹ø ²ÀÁþÁ¡
		   {MAXPOINT.x - centerX / 2, MAXPOINT.y}, // 2¹ø ²ÀÁþÁ¡
		   {MAXPOINT.x, MAXPOINT.y - centerY / 2}, // 3¹ø ²ÀÁþÁ¡
		   {MAXPOINT.x, MINPOINT.y}, // 4¹ø ²ÀÁþÁ¡
		   {MINPOINT.x + centerX / 2, MINPOINT.y}, // 5¹ø ²ÀÁþÁ¡
		   {MINPOINT.x, MINPOINT.y + centerY / 2}  // 6¹ø ²ÀÁþÁ¡
		};
		HRGN Hexa = CreatePolygonRgn(hexaPoints, 6, WINDING);
		return Hexa;
	}
	if (MINPOINT.x <= 376 && MINPOINT.y >= 188) {//ÁÂÇÏ
		MoveToEx(hdc, MINPOINT.x, MINPOINT.y, NULL); //¹Ø¸é
		LineTo(hdc, MINPOINT.x + centerX / 2, MINPOINT.y + centerY / 2);
		LineTo(hdc, MAXPOINT.x, MINPOINT.y + centerY / 2);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MINPOINT.y);
		LineTo(hdc, MINPOINT.x, MINPOINT.y);//º¹±Í

		MoveToEx(hdc, MINPOINT.x + centerX / 2, MINPOINT.y + centerY / 2, NULL); // ¾Õ¸é
		LineTo(hdc, MINPOINT.x + centerX / 2, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x, MINPOINT.y + centerY / 2);
		LineTo(hdc, MINPOINT.x + centerX / 2, MINPOINT.y + centerY / 2);//ÇÏ³ª´Â ÀÌ¹Ì À§¿¡¼­ ±×·Á¼­ »ý·«

		MoveToEx(hdc, MINPOINT.x, MINPOINT.y, NULL); // ¿·¸é
		LineTo(hdc, MINPOINT.x, MAXPOINT.y - centerY / 2);
		LineTo(hdc, MINPOINT.x + centerX / 2, MAXPOINT.y);

		POINT hexaPoints[6] = {
		   {MINPOINT.x, MINPOINT.y}, // 1¹ø ²ÀÁþÁ¡
		   {MINPOINT.x, MAXPOINT.y - centerY / 2}, // 2¹ø ²ÀÁþÁ¡
		   {MINPOINT.x + centerX / 2, MAXPOINT.y}, // 3¹ø ²ÀÁþÁ¡
		   {MAXPOINT.x, MAXPOINT.y}, // 4¹ø ²ÀÁþÁ¡
		   {MAXPOINT.x, MINPOINT.y + centerY / 2}, // 5¹ø ²ÀÁþÁ¡
		   {MAXPOINT.x - centerX / 2, MINPOINT.y}  // 6¹ø ²ÀÁþÁ¡
		};
		HRGN Hexa = CreatePolygonRgn(hexaPoints, 6, WINDING);
		return Hexa;
	}
	if (MINPOINT.x > 376 && MINPOINT.y < 188) {//¿ì»ó
		MoveToEx(hdc, MINPOINT.x, MAXPOINT.y - centerY / 2, NULL); //¹Ø¸é ¹Ý½Ã°è¼ø
		LineTo(hdc, MINPOINT.x + centerX / 2, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MAXPOINT.y - centerY / 2);
		LineTo(hdc, MINPOINT.x, MAXPOINT.y - centerY / 2);

		MoveToEx(hdc, MAXPOINT.x - centerX / 2, MAXPOINT.y - centerY / 2, NULL); // ¾Õ¸é ¹Ý½Ã°è¼ø
		LineTo(hdc, MAXPOINT.x - centerX / 2, MINPOINT.y);
		LineTo(hdc, MINPOINT.x, MINPOINT.y);
		LineTo(hdc, MINPOINT.x, MAXPOINT.y - centerY / 2);

		MoveToEx(hdc, MAXPOINT.x, MAXPOINT.y, NULL); // ¿·¸é ¿ìÇÏ½ÃÀÛ ¹Ý½Ã°è
		LineTo(hdc, MAXPOINT.x, MINPOINT.y + centerY / 2);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MINPOINT.y);

		POINT hexaPoints[6] = {
		   {MINPOINT.x, MINPOINT.y}, // 1¹ø ²ÀÁþÁ¡
		   {MINPOINT.x, MAXPOINT.y - centerY / 2}, // 2¹ø ²ÀÁþÁ¡
		   {MINPOINT.x + centerX / 2, MAXPOINT.y}, // 3¹ø ²ÀÁþÁ¡
		   {MAXPOINT.x, MAXPOINT.y}, // 4¹ø ²ÀÁþÁ¡
		   {MAXPOINT.x, MINPOINT.y + centerY / 2}, // 5¹ø ²ÀÁþÁ¡
		   {MAXPOINT.x - centerX / 2, MINPOINT.y}  // 6¹ø ²ÀÁþÁ¡
		};
		HRGN Hexa = CreatePolygonRgn(hexaPoints, 6, WINDING);
		return Hexa;
	}
	if (MINPOINT.x > 376 && MINPOINT.y >= 188) {//¿ìÇÏ
		MoveToEx(hdc, MINPOINT.x + centerX / 2, MINPOINT.y, NULL); //¹Ø¸é
		LineTo(hdc, MINPOINT.x, MINPOINT.y + centerY / 2);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MINPOINT.y + centerY / 2);
		LineTo(hdc, MAXPOINT.x, MINPOINT.y);
		LineTo(hdc, MINPOINT.x + centerX / 2, MINPOINT.y);

		MoveToEx(hdc, MINPOINT.x, MINPOINT.y + centerY / 2, NULL); // ¾Õ¸é
		LineTo(hdc, MINPOINT.x, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MAXPOINT.y);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MINPOINT.y + centerY / 2);//ÇÏ³ª´Â ÀÌ¹Ì À§¿¡¼­ ±×·Á¼­ »ý·«

		MoveToEx(hdc, MAXPOINT.x, MINPOINT.y, NULL); // ¿·¸é
		LineTo(hdc, MAXPOINT.x, MAXPOINT.y - centerY / 2);
		LineTo(hdc, MAXPOINT.x - centerX / 2, MAXPOINT.y);

		POINT hexaPoints[6] = {
		   {MINPOINT.x + centerX / 2, MINPOINT.y}, // 1¹ø ²ÀÁþÁ¡
		   {MINPOINT.x, MINPOINT.y + centerY / 2}, // 2¹ø ²ÀÁþÁ¡
		   {MINPOINT.x, MAXPOINT.y}, // 3¹ø ²ÀÁþÁ¡
		   {MAXPOINT.x - centerX / 2, MAXPOINT.y}, // 4¹ø ²ÀÁþÁ¡
		   {MAXPOINT.x, MAXPOINT.y - centerY / 2}, // 5¹ø ²ÀÁþÁ¡
		   {MAXPOINT.x, MINPOINT.y}  // 6¹ø ²ÀÁþÁ¡
		};
		HRGN Hexa = CreatePolygonRgn(hexaPoints, 6, WINDING);
		return Hexa;
	}


}

//void Movecube(POINT* MINPOINT, POINT* MAXPOINT, int deltaX, int deltaY) {
	MINPOINT->x += deltaX; // MINPOINTÀÇ X ÁÂÇ¥ ÀÌµ¿
	MINPOINT->y += deltaY; // MINPOINTÀÇ Y ÁÂÇ¥ ÀÌµ¿
	MAXPOINT->x += deltaX; // MAXPOINTÀÇ X ÁÂÇ¥ ÀÌµ¿
	MAXPOINT->y += deltaY; // MAXPOINTÀÇ Y ÁÂÇ¥ ÀÌµ¿
	;
}