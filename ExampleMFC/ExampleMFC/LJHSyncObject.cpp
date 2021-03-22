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
	// 1. ���ؽ��� Ư¡�� ũ��Ƽ�� ���ǰ��� �ٸ���, ��������� ���ؽ��� ��Ī�� �����ָ� ���μ��� ������ 
	m_hMutex = ::CreateMutex(nullptr, TRUE, _T("MutexTest"));

	// ó�� ���α׷��� ������ �Ǹ� ����Ǳ� ������ ���ؽ��� �����ϰ� �˴ϴ�.
	// ���� ERROR_ALREADY_EXISTS �κ��� ó������ �ʰ�, ���� ���μ��� ������ �Ҽ��ֵ��� ����⵵ �մϴ�. (������ �׷������ ���ؽ��� ���� ���� ������ ������??? )
	// ������ �ǿ� ��� ���÷δ� ������ ���� Ŭ���̾�Ʈ ������� �Դϴ�.

	if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		std::cout << "Already Ruuning" << std::endl;
		::CloseHandle(m_hMutex);

		return 0;
	}


	Sleep(10000); // 10�� ���� ���μ��� ����
	::CloseHandle(m_hMutex);

	return 0;
}
int CLJHSyncObject::testCriticalSection()
{
	return 0;
}