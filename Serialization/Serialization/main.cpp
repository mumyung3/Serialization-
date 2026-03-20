#include "main.h"
#include "Serialization.h"
#include "Console.h"
#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "windows.h"

// 직렬화 검증 프로그램.
int main()
{

	(void)_setmode(_fileno(stdout), _O_U16TEXT);
	cs_Initial();
	CPacket cPacket{};

	while (1) {

		// 랜덤 입력 


		// 로직
		// 렌더
		Buffer_Clear();
		DrawLayout();
		Buffer_Flip();
		Sleep(1000);
	}

	return 0;
}