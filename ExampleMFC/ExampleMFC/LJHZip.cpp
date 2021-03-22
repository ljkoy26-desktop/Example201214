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

	// ���� ��θ� ����� �ٷ��� ���丮 ���� ���ϱ� ���� ȣ���Ѵ� ( D:\GitHub\Example201214 ) �������
	TCHAR szFolder[MAX_PATH];
	GetModuleFileName(NULL, szFolder, MAX_PATH); // D:\GitHub\Example201214\ExampleMFC\Debug\ExampleMFC.exe ���� ��� ��ȯ

	PathRemoveFileSpec(szFolder);
	PathRemoveFileSpec(szFolder);
	PathRemoveFileSpec(szFolder);

	CString strFolder(szFolder);
	CString strZipPath(strFolder);
	CTime time = GetCurrentTime();
	TRACE(_T("%d : %d : %d\n"), time.GetHour(), time.GetMinute(), time.GetSecond());
	CString strTarget(_T("�׽�Ʈ.xlsx"));
	CString strTarget2(_T("�׽�Ʈ.txt"));

	CString strTargetPath(strFolder);
	CString strTargetPath2(strFolder);

	CString strRes(_T(""));
#ifdef UNICODE
	strZipPath += _T("\\�׽�Ʈ ����(�����ڵ�).zip");
#else 
	strZipPath += _T("\\�׽�Ʈ ����(��Ƽ����Ʈ).zip");
#endif

	// ����ȭ�� ��ο� ���� ������ �����Ѵ�.
	m_hZip = CreateZip(strZipPath, NULL); // 2���� ���ڴ� �н�����

	if (m_hZip == NULL)
	{
		AfxMessageBox(_T("Error: Failed to create Zip"));
		return;
	}

	// �ѱ� ���ϸ� ���� ó�� �ʿ� ( ��ο� �ѱۿ� ���� �����ɼ� �ִ� ) -> zip �ҽ����� ��Ƽ����Ʈ, �����ڵ� �κ� CP_ACP �������� ������
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
	// 1 : zip ��ü
	// 2 : �����Ϸ��� ���ϸ� 3������ �߰��� ������ �н���
	// 3 : �߰��Ϸ��� ������ Ǯ Path�� 

	GetZipErrorMsg(CloseZip(m_hZip));
	time = GetCurrentTime();
	TRACE(_T("%d : %d : %d\n"), time.GetHour(), time.GetMinute(), time.GetSecond());

	//if (DeleteFile(strTargetPath2) == TRUE)
	//	AfxMessageBox(_T("������"));
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