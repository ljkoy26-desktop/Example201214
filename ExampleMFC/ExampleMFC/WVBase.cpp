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
		case LJHBase::BASE:			strtype = _T("BASE");	break;
		case LJHBase::A:			strtype = _T("A");		break;
		case LJHBase::B:			strtype = _T("B");		break;
		case LJHBase::C:			strtype = _T("C");		break;
		case LJHBase::D:			strtype = _T("D");		break;
		default:					strtype.Format(_T("%d"), pItem->m_nType); break;
		}

		str.Format(_T("pItemÅ¸ÀÔ ==> (%s)\n"), strtype);
		TRACE(str);
		delete pItem;
	}
	m_aItem.RemoveAll();
}
