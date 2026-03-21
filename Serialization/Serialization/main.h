#pragma once
// 연산(함수명)
extern const wchar_t* operatorName;
// 타입
extern const wchar_t* typeName;
// 크기
extern int compareSize;
// 테스트 값
extern wchar_t testValStr[50];
// 논리 값
extern wchar_t logicValStr[50];
// PASS 누적
extern int cntPass;
// FAIL 누적
extern int cntFail;
// 상태 bIsPass
extern bool bIsPass;

void Test_Serializae_EachType();
void Test_Serializae_Chaining();
void Test_Serializae_Boundary();
void Test_Serializae_RawData();