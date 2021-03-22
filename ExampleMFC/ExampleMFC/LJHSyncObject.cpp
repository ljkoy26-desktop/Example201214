#include "stdafx.h"
#include "LJHSyncObject.h"

CLJHSyncObject::CLJHSyncObject()
{
	m_hMutex = nullptr;
}


CLJHSyncObject::~CLJHSyncObject()
{
}


int CLJHSyncObject::testMutex()
{
	// 1. 뮤텍스의 특징은 크리티컬 섹션과는 다르게, 명시적으로 뮤텍스의 명칭을 정해주면 프로세스 간에도 
	m_hMutex = ::CreateMutex(nullptr, TRUE, _T("MutexTest"));

	// 처음 프로그램이 켜지게 되면 종료되기 전까지 뮤텍스가 존재하게 됩니다.
	// 하위 ERROR_ALREADY_EXISTS 부분을 처리하지 않고, 다중 프로세스 실행을 할수있도록 만들기도 합니다. (하지만 그럴꺼라면 뮤텍스를 굳이 쓰는 이유가 있을까??? )
	// 간단한 실용 사례 에시로는 게임의 다중 클라이언트 실행방지 입니다.

	if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		std::cout << "Already Ruuning" << std::endl;
		::CloseHandle(m_hMutex);

		return 0;
	}


	Sleep(10000); // 10초 동안 프로세스 유지
	::CloseHandle(m_hMutex);

	return 0;
}
int CLJHSyncObject::testCriticalSection()
{
	return 0;
}