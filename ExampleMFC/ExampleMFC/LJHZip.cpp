#include "stdafx.h"
#include "LJHZip.h"

CLJHZip::CLJHZip()
{
}
CLJHZip::~CLJHZip()
{
}
void CLJHZip::CreateZipFile() // ZIP
{
	ZRESULT zResult;

	// 하위 경로를 깃허브 바로위 디렉토리 까지 구하기 위해 호출한다 ( D:\GitHub\Example201214 ) 최종경로
	TCHAR szFolder[MAX_PATH];
	GetModuleFileName(NULL, szFolder, MAX_PATH); // D:\GitHub\Example201214\ExampleMFC\Debug\ExampleMFC.exe 실행 경로 반환

	PathRemoveFileSpec(szFolder);
	PathRemoveFileSpec(szFolder);
	PathRemoveFileSpec(szFolder);

	CString strFolder(szFolder);
	CString strZipPath(strFolder);
	CTime time = GetCurrentTime();
	TRACE(_T("%d : %d : %d\n"), time.GetHour(), time.GetMinute(), time.GetSecond());
	CString strTarget(_T("테스트.xlsx"));
	CString strTarget2(_T("테스트.txt"));

	CString strTargetPath(strFolder);
	CString strTargetPath2(strFolder);

	CString strRes(_T(""));
#ifdef UNICODE
	strZipPath += _T("\\테스트 알집(유니코드).zip");
#else 
	strZipPath += _T("\\테스트 알집(멀티바이트).zip");
#endif

	// 바탕화면 경로에 알집 파일을 생성한다.
	m_hZip = CreateZip(strZipPath, NULL); // 2번쨰 인자는 패스워드

	if (m_hZip == NULL)
	{
		AfxMessageBox(_T("Error: Failed to create Zip"));
		return;
	}

	// 한글 파일명에 대한 처리 필요 ( 경로에 한글에 들어가도 문제될수 있다 ) -> zip 소스내의 멀티바이트, 유니코드 부분 CP_ACP 설정으로 수정됨
	strTargetPath = strFolder + _T("\\") + strTarget;
	zResult = ZipAdd(m_hZip, strTarget, strTargetPath);
	if (ZR_OK != zResult)
	{
		strRes = GetZipErrorMsg(zResult);
		AfxMessageBox(strRes);
		return;
	}

	strTargetPath2 = strFolder + _T("\\") + strTarget2;
	zResult = ZipAdd(m_hZip, strTarget2, strTargetPath2);
	if (ZR_OK != zResult)
	{
		strRes = GetZipErrorMsg(zResult);
		AfxMessageBox(strRes);
		return;
	}

	/* fn : ZipAdd */
	// 1 : zip 객체
	// 2 : 생성하려는 파일명 3번으로 추가한 파일의 패스명
	// 3 : 추가하려는 파일의 풀 Path명 

	GetZipErrorMsg(CloseZip(m_hZip));
	time = GetCurrentTime();
	TRACE(_T("%d : %d : %d\n"), time.GetHour(), time.GetMinute(), time.GetSecond());

	//if (DeleteFile(strTargetPath2) == TRUE)
	//	AfxMessageBox(_T("삭제함"));
}
CString CLJHZip::GetZipErrorMsg(ZRESULT zResult)
{
	CString sReturn(_T(""));

	TCHAR szMsg[256];
	FormatZipMessage(zResult, szMsg, 256);
	sReturn = szMsg;
	return sReturn;
}
BOOL CLJHZip::AddFile(CString strFileName, CString strTargetPath)
{
	BOOL bReturn(true);
	ZRESULT zResult = ZipAdd(m_hZip, strFileName, strTargetPath);
	if (ZR_OK != zResult)
	{
		AfxMessageBox(GetZipErrorMsg(zResult));
		bReturn = false;
	}
	return bReturn;
}