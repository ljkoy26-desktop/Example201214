#include "stdafx.h"
#include "CreateDump.h"
#include <DbgHelp.h>
#include <vector>

CCreateDump::CCreateDump()
{
}

CCreateDump::~CCreateDump()
{
}

typedef BOOL(WINAPI* MINIDUMPWRITEDUMP)( // Callback 함수의 원형
	HANDLE hProcess,
	DWORD dwPid,
	HANDLE hFile,
	MINIDUMP_TYPE DumpType,
	CONST PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
	CONST PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,
	CONST PMINIDUMP_CALLBACK_INFORMATION CallbackParam);

LPTOP_LEVEL_EXCEPTION_FILTER m_PreviousExceptionFilter = NULL;

LONG WINAPI UnHandledExceptionFilter(struct _EXCEPTION_POINTERS* exceptionInfo)
{
	// Windows 2000 이전에는 따로 DBGHELP를 배포해서 설정해 주어야 한다.

	HMODULE    DllHandle = NULL;	
	DllHandle = LoadLibrary(_T("DBGHELP.DLL"));

	if (DllHandle)
	{
		MINIDUMPWRITEDUMP Dump = (MINIDUMPWRITEDUMP)GetProcAddress(DllHandle, "MiniDumpWriteDump");
		if (Dump)
		{
			TCHAR        DumpPath[MAX_PATH] = { 0, };
			SYSTEMTIME    SystemTime;

			GetLocalTime(&SystemTime);

			_sntprintf(DumpPath, MAX_PATH, _T("%04d-%02d-%02d %02d_%02d_%02d.dmp"),
				SystemTime.wYear,
				SystemTime.wMonth,
				SystemTime.wDay,
				SystemTime.wHour,
				SystemTime.wMinute,
				SystemTime.wSecond);

			HANDLE FileHandle = CreateFile(
				DumpPath,
				GENERIC_WRITE,
				FILE_SHARE_WRITE,
				NULL, CREATE_ALWAYS,
				FILE_ATTRIBUTE_NORMAL,
				NULL);

			if (FileHandle != INVALID_HANDLE_VALUE)
			{
				_MINIDUMP_EXCEPTION_INFORMATION MiniDumpExceptionInfo;

				MiniDumpExceptionInfo.ThreadId = GetCurrentThreadId();
				MiniDumpExceptionInfo.ExceptionPointers = exceptionInfo;
				MiniDumpExceptionInfo.ClientPointers = NULL;

				BOOL Success = Dump(
					GetCurrentProcess(),
					GetCurrentProcessId(),
					FileHandle,
					MiniDumpWithProcessThreadData,
					&MiniDumpExceptionInfo,
					NULL,
					NULL);

				if (Success)
				{
					CloseHandle(FileHandle);

					return EXCEPTION_EXECUTE_HANDLER;
				}
			}

			CloseHandle(FileHandle);
		}
	}

	return EXCEPTION_CONTINUE_SEARCH;
}

BOOL CCreateDump::Begin(VOID)
{
	SetErrorMode(SEM_FAILCRITICALERRORS);
	m_PreviousExceptionFilter = SetUnhandledExceptionFilter(UnHandledExceptionFilter);
	return true;
}

BOOL CCreateDump::End(VOID)
{
	SetUnhandledExceptionFilter(m_PreviousExceptionFilter);
	return true;
}


void CCreateDump::TestDump1()
{
	// 덤프가 만들어지는 예외가 아닙니다.
	//int nZero(0);
	//int i = 1 / nZero;
}
void CCreateDump::TestDump2()
{
	// 덤프가 만들어지는 예외가 아닙니다.
	//int *n = new int;
	//delete n;
	//delete n;
}
void CCreateDump::TestDump3()
{
	CTestObject* m_obj = new CTestObject;
	m_obj = NULL;
	m_obj->m_bOpen = false;
}
void CCreateDump::TestDump4()
{
	//std::out_of_range

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.at(3);
}
