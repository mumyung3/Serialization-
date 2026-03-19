#include "Console.h"
#include <windows.h>
#include <stdio.h>
#define dfSCREEN_HEIGHT 100
#define dfSCREEN_WIDTH  100

// 콘솔 제어 준비 작업
HANDLE hConsole;
wchar_t szScreenBuffer[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];

void cs_Initial(void) {

	CONSOLE_CURSOR_INFO stConsoleCursor;

	stConsoleCursor.bVisible = FALSE;
	stConsoleCursor.dwSize = 1;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &stConsoleCursor);

}

void cs_MoveCursor(int iPosX, int iPosY) {

	COORD stCoord;
	stCoord.X = iPosX; //(좌우	 열)
	stCoord.Y = iPosY; //(위아래	 행)

	SetConsoleCursorPosition(hConsole, stCoord);

}

void Buffer_Clear(void) {
	memset(szScreenBuffer, ' ', dfSCREEN_HEIGHT * dfSCREEN_WIDTH);

	for (int i = 0; i < dfSCREEN_HEIGHT;i++) {
		szScreenBuffer[i][dfSCREEN_WIDTH - 1] = L'\0';
	}

}

void Buffer_Flip(void) {

	for (int i = 0; i < dfSCREEN_HEIGHT; i++) {
		cs_MoveCursor(0, i);
		wprintf(L"%s", szScreenBuffer[i]);
	}
}

void DrawLayout(void) {

	swprintf_s(szScreenBuffer[0], sizeof(szScreenBuffer[0]), L"%s", L"╔══════════════════════════════════════════════╗");
}