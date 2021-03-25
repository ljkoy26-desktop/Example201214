#include "stdafx.h"
#include "LJHBase.h"


CLJHBase::CLJHBase()
{
}


CLJHBase::~CLJHBase()
{
	int nSize(m_aItem.GetSize());
	CString strtype;
	CString str;

	for (int i = 0; i < nSize; ++i)
	{
		CLJHBase* pItem = m_aItem.GetAt(i);
		switch (pItem->m_nType)
		{
		case CLJHBase::BASE:		strtype = _T("BASE");	break;
		case CLJHBase::A:			strtype = _T("A");		break;
		case CLJHBase::B:			strtype = _T("B");		break;
		case CLJHBase::C:			strtype = _T("C");		break;
		case CLJHBase::D:			strtype = _T("D");		break;
		default:					strtype.Format(_T("%d"), pItem->m_nType); break;
		}

		str.Format(_T("pItemÅ¸ÀÔ ==> (%s)\n"), strtype);
		TRACE(str);
		delete pItem;
	}
	m_aItem.RemoveAll();
}