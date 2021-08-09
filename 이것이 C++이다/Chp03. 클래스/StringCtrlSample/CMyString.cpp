#include "CMyString.h"
#include "stdafx.h"

CMyString::CMyString() : m_pszData(NULL), m_nLength(0)
{

}

CMyString::~CMyString() {
	Release();
}

int CMyString::SetString(const char* pszParam)
{
	// ���ο� ���ڿ� �Ҵ翡 �ռ� ���� ������ �����Ѵ�.
	Release();

	if (pszParam == NULL) { return 0; }

	//���̰� 0�� ���ڿ��� �ʱ�ȭ�� �ν��ϰ� ó���Ѵ�.
	int nLength = strlen(pszParam);

	if (nLength == 0) { return 0; }
	
	//���ڿ� ���� NULL���ڰ� ������
	m_pszData = new char[nLength + 1];

	//���� �Ҵ��� �޸𸮿� ���ڿ��� �����Ѵ�.
	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam);
	m_nLength = nLength;

	return nLength;
}


const char* CMyString::GetString() const
{
	return m_pszData;
}


void CMyString::Release()
{
	if (m_pszData != NULL) {
		delete[] m_pszData;
	}

	m_pszData = NULL;
	m_nLength = 0;
}
