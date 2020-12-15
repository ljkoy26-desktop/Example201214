#include "stdafx.h"
#include "LJHBase.h"


LJHBase::LJHBase()
{
}


LJHBase::~LJHBase()
{
	int nSize(m_aItem.GetSize());
	CString strtype;
	CString str;

	for (int i = 0; i < nSize; ++i)
	{
		LJHBase* pItem = m_aItem.GetAt(i);

		switch (pItem->m_nType)
		{
		case 0:			strtype = _T("BASE");		break;
		case 1:			strtype = _T("A	");		break;
		case 2:			strtype = _T("B	");		break;
		case 3:			strtype = _T("C	");		break;
		case 4:			strtype = _T("D	");		break;
		default:		strtype.Format(_T("%d"), pItem->m_nType); break;
		}

		str.Format(_T("pItemÅ¸ÀÔ ==> (%s)\n"), strtype);
		TRACE(str);
		delete pItem;
	}
	m_aItem.RemoveAll();
}
