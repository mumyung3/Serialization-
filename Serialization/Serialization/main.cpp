#include "main.h"
#include "Serialization.h"
#include "Console.h"
#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "windows.h"
#include "cstdlib"
#include "ctime"

CPacket cPacket{};
// 연산(함수명)
const wchar_t* operatorName;
// 타입
const wchar_t* typeName;
wchar_t TypesNames[50]{};

// 크기
int compareSize;
// 테스트 값
wchar_t testValStr[50];
// 논리 값
wchar_t logicValStr[50];
// PASS 누적
int cntPass;
// FAIL 누적
int cntFail;
// 상태 bIsPass
bool bIsPass = true;
// 직렬화 검증 프로그램.
int main()
{
	// 창 초기화
	(void)_setmode(_fileno(stdout), _O_U16TEXT);
	cs_Initial();
	// 랜덤 시드 초기화
	srand((unsigned)time(NULL));


	while (1) {

		// 랜덤 입력 
		//int random = rand() % 3;
		int random = 2;

		switch (random) {

		case 0:
			// 1. 각 타입별 정상 케이스
			Test_Serializae_EachType();


			break;
		case 1:
			// 2. 체이닝
			Test_Serializae_Chaining();
			break;
		case 2:
			// 3. Put/GetData
			Test_Serializae_RawData();

			break;
		case 3:
			// 4. 경계값 (버퍼 다 찼을때)
			Test_Serializae_Boundary();

			break;

		}


		// 로직
		cPacket.Clear();
		bIsPass = true;

		// 렌더
		Buffer_Clear();
		DrawLayout();
		Buffer_Flip();
		//Sleep(1000);




	}

	return 0;
}
void Test_Serializae_EachType() {

	int randomType = rand() % 9;
	switch (randomType) {

	case 0:
	{//unsigned char
		unsigned char temp = (unsigned char)(rand() % 256);

		// 이전 rear 저장
		int oldrear = cPacket.rear;
		// << 검증 단계
		cPacket << temp;
		unsigned char compareResult{ 0xcc };
		memcpy(&compareResult, cPacket.GetBufferPtr() + oldrear, sizeof(unsigned char));

		if (compareResult != temp) { bIsPass = false; }

		// >> 검증 단계
		unsigned char recvtemp{ 0xcc };
		cPacket >> recvtemp;
		if (recvtemp != temp) { bIsPass = false; }


		// 연산(함수명)
		operatorName = g_function;

		// 타입
		typeName = L"unsigned char";
		// 크기
		compareSize = sizeof(unsigned char);
		// 테스트 값
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L" << 값 : %c", compareResult);
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L"%s >> 값 : %c", testValStr, recvtemp);
		// 논리 값
		swprintf_s(logicValStr, sizeof(logicValStr) / sizeof(wchar_t), L"%c", temp);
		// PASS 누적
		if (bIsPass)	cntPass++;
		// FAIL 누적
		else cntFail++;
		// 상태 bIsPass

		break;
	}
	case 1:
	{
		// char
		char temp = (char)(rand() % 256);

		// 이전 rear 저장
		int oldrear = cPacket.rear;
		// << 검증 단계
		cPacket << temp;
		char compareResult{ (char)0xcc };
		memcpy(&compareResult, cPacket.GetBufferPtr() + oldrear, sizeof(char));

		if (compareResult != temp) { bIsPass = false; }

		// >> 검증 단계
		char recvtemp{ (char)0xcc };
		cPacket >> recvtemp;
		if (recvtemp != temp) { bIsPass = false; }


		// 연산(함수명)
		operatorName = g_function;

		// 타입
		typeName = L"char";
		// 크기
		compareSize = sizeof(char);
		// 테스트 값
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L" << 값 : %c", compareResult);
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L"%s >> 값 : %c", testValStr, recvtemp);
		// 논리 값
		swprintf_s(logicValStr, sizeof(logicValStr) / sizeof(wchar_t), L"%c", temp);
		// PASS 누적
		if (bIsPass)	cntPass++;
		// FAIL 누적
		else cntFail++;
		// 상태 bIsPass
		break;
	}
	case 2:
	{
		// short
		short temp = (short)(rand() % 65536);

		// 이전 rear 저장
		int oldrear = cPacket.rear;
		// << 검증 단계
		cPacket << temp;
		short compareResult{ (short)0xcccc };
		memcpy(&compareResult, cPacket.GetBufferPtr() + oldrear, sizeof(short));

		if (compareResult != temp) { bIsPass = false; }

		// >> 검증 단계
		short recvtemp{ (short)0xcccc };
		cPacket >> recvtemp;
		if (recvtemp != temp) { bIsPass = false; }


		// 연산(함수명)
		operatorName = g_function;

		// 타입
		typeName = L"short";
		// 크기
		compareSize = sizeof(short);
		// 테스트 값
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L" << 값 : %d", compareResult);
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L"%s >> 값 : %d", testValStr, recvtemp);
		// 논리 값
		swprintf_s(logicValStr, sizeof(logicValStr) / sizeof(wchar_t), L"%d", temp);
		// PASS 누적
		if (bIsPass)	cntPass++;
		// FAIL 누적
		else cntFail++;
		// 상태 bIsPass
		break;
	}
	case 3:
	{
		// short
		unsigned short temp = (unsigned short)(rand() % 65536);

		// 이전 rear 저장
		int oldrear = cPacket.rear;
		// << 검증 단계
		cPacket << temp;
		unsigned short compareResult{ (unsigned short)0xcccc };
		memcpy(&compareResult, cPacket.GetBufferPtr() + oldrear, sizeof(unsigned short));

		if (compareResult != temp) { bIsPass = false; }

		// >> 검증 단계
		unsigned short recvtemp{ (unsigned short)0xcccc };
		cPacket >> recvtemp;
		if (recvtemp != temp) { bIsPass = false; }


		// 연산(함수명)
		operatorName = g_function;

		// 타입
		typeName = L"unsigned short";
		// 크기
		compareSize = sizeof(unsigned short);
		// 테스트 값
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L" << 값 : %u", compareResult);
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L"%s >> 값 : %u", testValStr, recvtemp);
		// 논리 값
		swprintf_s(logicValStr, sizeof(logicValStr) / sizeof(wchar_t), L"%u", temp);
		// PASS 누적
		if (bIsPass)	cntPass++;
		// FAIL 누적
		else cntFail++;
		// 상태 bIsPass
		break;
	}
	case 4:
	{
		// int
		int temp = (rand() << 16) | rand();

		// 이전 rear 저장
		int oldrear = cPacket.rear;
		// << 검증 단계
		cPacket << temp;
		int compareResult{ (int)0xcccccccc };
		memcpy(&compareResult, cPacket.GetBufferPtr() + oldrear, sizeof(int));

		if (compareResult != temp) { bIsPass = false; }

		// >> 검증 단계
		int recvtemp{ (int)0xcccccccc };
		cPacket >> recvtemp;
		if (recvtemp != temp) { bIsPass = false; }


		// 연산(함수명)
		operatorName = g_function;

		// 타입
		typeName = L"int";
		// 크기
		compareSize = sizeof(int);
		// 테스트 값
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L" << 값 : %d", compareResult);
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L"%s >> 값 : %d", testValStr, recvtemp);
		// 논리 값
		swprintf_s(logicValStr, sizeof(logicValStr) / sizeof(wchar_t), L"%d", temp);
		// PASS 누적
		if (bIsPass)	cntPass++;
		// FAIL 누적
		else cntFail++;
		// 상태 bIsPass
		break;
	}
	case 5:
	{
		// long
		long temp = (rand() << 16) | rand();

		// 이전 rear 저장
		int oldrear = cPacket.rear;
		// << 검증 단계
		cPacket << temp;
		long compareResult{ (long)0xcccccccc };
		memcpy(&compareResult, cPacket.GetBufferPtr() + oldrear, sizeof(long));

		if (compareResult != temp) { bIsPass = false; }

		// >> 검증 단계
		long recvtemp{ (long)0xcccccccc };
		cPacket >> recvtemp;
		if (recvtemp != temp) { bIsPass = false; }


		// 연산(함수명)
		operatorName = g_function;

		// 타입
		typeName = L"long";
		// 크기
		compareSize = sizeof(long);
		// 테스트 값
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L" << 값 : %ld", compareResult);
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L"%s >> 값 : %ld", testValStr, recvtemp);
		// 논리 값
		swprintf_s(logicValStr, sizeof(logicValStr) / sizeof(wchar_t), L"%ld", temp);
		// PASS 누적
		if (bIsPass)	cntPass++;
		// FAIL 누적
		else cntFail++;
		// 상태 bIsPass
		break;
	}
	case 6:
	{
		// float
		float temp = (float)rand() / RAND_MAX * 3.14159f;  // 소수점 포함
		// 이전 rear 저장
		int oldrear = cPacket.rear;
		// << 검증 단계
		cPacket << temp;
		float compareResult{ (float)0.0f };
		memcpy(&compareResult, cPacket.GetBufferPtr() + oldrear, sizeof(float));

		if (compareResult != temp) { bIsPass = false; }

		// >> 검증 단계
		float recvtemp{ (float)0.0f };
		cPacket >> recvtemp;
		if (recvtemp != temp) { bIsPass = false; }


		// 연산(함수명)
		operatorName = g_function;

		// 타입
		typeName = L"float";
		// 크기
		compareSize = sizeof(float);
		// 테스트 값
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L" << 값 : %f", compareResult);
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L"%s >> 값 : %f", testValStr, recvtemp);
		// 논리 값
		swprintf_s(logicValStr, sizeof(logicValStr) / sizeof(wchar_t), L"%f", temp);
		// PASS 누적
		if (bIsPass)	cntPass++;
		// FAIL 누적
		else cntFail++;
		// 상태 bIsPass
		break;
	}
	case 7:
	{
		// __int64
		__int64 temp = ((__int64)rand() << 32) | rand();

		// 이전 rear 저장
		int oldrear = cPacket.rear;
		// << 검증 단계
		cPacket << temp;
		__int64 compareResult{ (__int64)0xccccccccccccccccULL };
		memcpy(&compareResult, cPacket.GetBufferPtr() + oldrear, sizeof(__int64));

		if (compareResult != temp) { bIsPass = false; }

		// >> 검증 단계
		__int64 recvtemp{ (__int64)0xccccccccccccccccULL };
		cPacket >> recvtemp;
		if (recvtemp != temp) { bIsPass = false; }


		// 연산(함수명)
		operatorName = g_function;

		// 타입
		typeName = L"__int64";
		// 크기
		compareSize = sizeof(__int64);
		// 테스트 값
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L" << 값 : %lld", compareResult);
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L"%s >> 값 : %lld", testValStr, recvtemp);
		// 논리 값
		swprintf_s(logicValStr, sizeof(logicValStr) / sizeof(wchar_t), L"%lld", temp);
		// PASS 누적
		if (bIsPass)	cntPass++;
		// FAIL 누적
		else cntFail++;
		// 상태 bIsPass
		break;
	}
	case 8:
	{
		// double
		double temp = (double)rand() / RAND_MAX * 3.14159;  // 소수점 포함
		// 이전 rear 저장
		int oldrear = cPacket.rear;
		// << 검증 단계
		cPacket << temp;
		double compareResult{ (double)0.0 };
		memcpy(&compareResult, cPacket.GetBufferPtr() + oldrear, sizeof(double));

		if (compareResult != temp) { bIsPass = false; }

		// >> 검증 단계
		double recvtemp{ (double)0.0 };
		cPacket >> recvtemp;
		if (recvtemp != temp) { bIsPass = false; }


		// 연산(함수명)
		operatorName = g_function;

		// 타입
		typeName = L"double";
		// 크기
		compareSize = sizeof(double);
		// 테스트 값
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L" << 값 : %lf", compareResult);
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L"%s >> 값 : %lf", testValStr, recvtemp);
		// 논리 값
		swprintf_s(logicValStr, sizeof(logicValStr) / sizeof(wchar_t), L"%lf", temp);
		// PASS 누적
		if (bIsPass)	cntPass++;
		// FAIL 누적
		else cntFail++;
		// 상태 bIsPass
		break;
	}
	}
}
void Test_Serializae_Chaining() {

	__int64 values[3]{};
	int types[3]{};

	// 초기화
	memset(TypesNames, 0, sizeof(TypesNames));
	compareSize = 0;

	for (int i = 0; i < 3; i++) {
		types[i] = rand() % 3;
		switch (types[i]) {
		case 0:	values[i] = ((__int64)rand() << 32) | rand();
			cPacket << (unsigned char)values[i];
			swprintf_s(TypesNames, sizeof(TypesNames) / sizeof(wchar_t), L"%s %s", TypesNames, L"unsigned char");
			compareSize += sizeof(unsigned char);
			break;
		case 1:	values[i] = ((__int64)rand() << 32) | rand();
			cPacket << (char)values[i];
			swprintf_s(TypesNames, sizeof(TypesNames) / sizeof(wchar_t), L"%s %s", TypesNames, L"char");
			compareSize += sizeof(char);

			break;
		case 2:	values[i] = ((__int64)rand() << 32) | rand();
			cPacket << (short)values[i];
			swprintf_s(TypesNames, sizeof(TypesNames) / sizeof(wchar_t), L"%s %s", TypesNames, L"short");
			compareSize += sizeof(short);


			break;
		case 3:	values[i] = ((__int64)rand() << 32) | rand();
			cPacket << (unsigned short)values[i];
			swprintf_s(TypesNames, sizeof(TypesNames) / sizeof(wchar_t), L"%s %s", TypesNames, L"unsigned short");
			compareSize += sizeof(unsigned short);

			break;
		case 4:	values[i] = ((__int64)rand() << 32) | rand();
			cPacket << (int)values[i];
			swprintf_s(TypesNames, sizeof(TypesNames) / sizeof(wchar_t), L"%s %s", TypesNames, L"int");
			compareSize += sizeof(int);

			break;
		case 5:	values[i] = ((__int64)rand() << 32) | rand();
			cPacket << (long)values[i];
			swprintf_s(TypesNames, sizeof(TypesNames) / sizeof(wchar_t), L"%s %s", TypesNames, L"long");
			compareSize += sizeof(long);

			break;
		case 6: {
			values[i] = ((__int64)rand() << 32) | rand();
			float f;
			memcpy(&f, &values[i], sizeof(float));
			cPacket << f;
			swprintf_s(TypesNames, sizeof(TypesNames) / sizeof(wchar_t), L"%s %s", TypesNames, L"float");
			compareSize += sizeof(float);


			break;
		}
		case 7:	values[i] = ((__int64)rand() << 32) | rand();
			cPacket << (__int64)values[i];
			swprintf_s(TypesNames, sizeof(TypesNames) / sizeof(wchar_t), L"%s %s", TypesNames, L"__int64");
			compareSize += sizeof(__int64);

			break;
		case 8: {
			values[i] = ((__int64)rand() << 32) | rand();
			double d;
			memcpy(&d, &values[i], sizeof(double));
			cPacket << d;
			swprintf_s(TypesNames, sizeof(TypesNames) / sizeof(wchar_t), L"%s %s", TypesNames, L"double");
			compareSize += sizeof(double);

			break;
		}

		}
	}

	for (int i = 0; i < 3; i++) {
		switch (types[i]) {
		case 0: {
			unsigned char r;
			cPacket >> r;
			if (r != (unsigned char)values[i]) bIsPass = false;

			break;
		}
		case 1: {
			char r;
			cPacket >> r;
			if (r != (char)values[i]) bIsPass = false;

			break;
		}
		case 2: {
			short r;
			cPacket >> r;
			if (r != (short)values[i]) bIsPass = false;

			break;
		}
		case 3: {
			unsigned short r;
			cPacket >> r;
			if (r != (unsigned short)values[i]) bIsPass = false;
			break;
		}
		case 4: {
			int r;
			cPacket >> r;
			if (r != (int)values[i]) bIsPass = false;

			break;
		}
		case 5: {
			long r;
			cPacket >> r;
			if (r != (long)values[i]) bIsPass = false;

			break;
		}
		case 6: {
			float r;
			cPacket >> r;
			float f;
			memcpy(&f, &values[i], sizeof(float));
			if (r != f) bIsPass = false;

			break;
		}
		case 7: {
			__int64 r;
			cPacket >> r;
			if (r != values[i]) bIsPass = false;

			break;
		}
		case 8: {
			double r;
			cPacket >> r;
			double d;
			memcpy(&d, &values[i], sizeof(double));
			if (r != d) bIsPass = false;

			break;
		}

		}
	}
	wchar_t temp[100]{};
	swprintf_s(temp, sizeof(temp) / sizeof(wchar_t), L"%S", __FUNCTION__);
	operatorName = temp;

	typeName = TypesNames;
	swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L"디버깅 확인...");
	swprintf_s(logicValStr, sizeof(logicValStr) / sizeof(wchar_t), L"콘솔창 길이 문제로 디버깅 확인...");



	if (bIsPass == true) {
		cntPass++;
	}
	else {
		cntFail++;
	}


}
void Test_Serializae_Boundary() {}
void Test_Serializae_RawData() {

	// 랜덤 문자열, 크기
	int size = rand() % 50 + 1;

	char srcBuf[50] = {};
	for (int i = 0; i < size; i++) {
		srcBuf[i] = (char)(rand() % 256);
	}

	cPacket.PutData(srcBuf, size);

	char destBuf[50] = {};
	cPacket.GetData(destBuf, size);

	if (memcmp(srcBuf, destBuf, size) != 0) bIsPass = false;

	if (bIsPass) cntPass++;
	else cntFail++;

	operatorName = L"Put/GetData()";
	typeName = L"char*";
	compareSize = size;
	int limitstr = 20;
	if (compareSize > limitstr) {

		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L"%.10s...", (wchar_t*)destBuf);
		swprintf_s(logicValStr, sizeof(logicValStr) / sizeof(wchar_t), L"%.10s...", (wchar_t*)srcBuf);
	}
	else {
		swprintf_s(testValStr, sizeof(testValStr) / sizeof(wchar_t), L"%s", (wchar_t*)destBuf);
		swprintf_s(logicValStr, sizeof(logicValStr) / sizeof(wchar_t), L"%s", (wchar_t*)srcBuf);

	}

}