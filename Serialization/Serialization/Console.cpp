#include "Console.h"
#include <windows.h>
#include <stdio.h>
#include <wchar.h>
#define dfSCREEN_HEIGHT 30
#define dfSCREEN_WIDTH  100

// 콘솔 제어 준비 작업
HANDLE hConsole;
wchar_t szScreenBuffer[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];

void cs_Initial(void) {
	system("mode con cols=120 lines=30");

	CONSOLE_CURSOR_INFO stConsoleCursor;

	stConsoleCursor.bVisible = FALSE;
	stConsoleCursor.dwSize = 1;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &stConsoleCursor);

}

bool cs_MoveCursor(int iPosX, int iPosY) {

	COORD stCoord;
	stCoord.X = iPosX; //(좌우	 열)
	stCoord.Y = iPosY; //(위아래	 행)

	bool result = SetConsoleCursorPosition(hConsole, stCoord);
	return result;
}

void Buffer_Clear(void) {

	for (int i = 0; i < dfSCREEN_HEIGHT;i++) {
		wmemset(szScreenBuffer[i], L' ', dfSCREEN_WIDTH);
		szScreenBuffer[i][dfSCREEN_WIDTH - 1] = L'\0';
	}

}

// 버퍼 mouse 커서 0,0 은 버퍼 0,0 을 가르키는데, 스크롤로 인해 버퍼가 갱신될때마다 그 시점 뷰포트 기준으로 버퍼 0,0 이 갱신됨. 고로 스크롤 할 상황을 만들면 안됨. 뒤로 돌아갈수없음.
void Buffer_Flip(void) {

	// 매 프레임 뷰포트 강제 고정

	for (int i = 0; i < dfSCREEN_HEIGHT; i++) {
		cs_MoveCursor(0, i);
		wprintf(L"%s", szScreenBuffer[i]);

	}

}

void DrawLayout(void) {

	swprintf_s(szScreenBuffer[0], sizeof(szScreenBuffer[0]) / sizeof(wchar_t), L"%s", L"╔══════════════════════════════════════════════╗");

	swprintf_s(szScreenBuffer[1], sizeof(szScreenBuffer[1]) / sizeof(wchar_t), L"%s",
		L"║         직렬화 검증 자동 테스트 프로그램	"
	);
	swprintf_s(szScreenBuffer[2], sizeof(szScreenBuffer[2]) / sizeof(wchar_t), L"%s",
		L"╠══════════════════════════════════════════════"
	);
	swprintf_s(szScreenBuffer[3], sizeof(szScreenBuffer[3]) / sizeof(wchar_t), L"%s",
		L"║ 연산(함수명):"
	);
	swprintf_s(szScreenBuffer[4], sizeof(szScreenBuffer[4]) / sizeof(wchar_t), L"%s",
		L"║ 타입:"
	);
	swprintf_s(szScreenBuffer[5], sizeof(szScreenBuffer[5]) / sizeof(wchar_t), L"%s",
		L"║ 크기:"
	);
	swprintf_s(szScreenBuffer[6], sizeof(szScreenBuffer[6]) / sizeof(wchar_t), L"%s",
		L"║ : 테스트 값:"
	);
	swprintf_s(szScreenBuffer[7], sizeof(szScreenBuffer[7]) / sizeof(wchar_t), L"%s",
		L"║ : 논리 값:"
	);
	swprintf_s(szScreenBuffer[8], sizeof(szScreenBuffer[8]) / sizeof(wchar_t), L"%s",
		L"║  PASS:       FAIL:"
	);
	swprintf_s(szScreenBuffer[9], sizeof(szScreenBuffer[9]) / sizeof(wchar_t), L"%s",
		L"╠══════════════════════════════════════════════╣"
	);
	swprintf_s(szScreenBuffer[10], sizeof(szScreenBuffer[10]) / sizeof(wchar_t), L"%s",
		L"║ 상태:"
	);
	swprintf_s(szScreenBuffer[11], sizeof(szScreenBuffer[11]) / sizeof(wchar_t), L"%s",
		L"╚══════════════════════════════════════════════╝");





}