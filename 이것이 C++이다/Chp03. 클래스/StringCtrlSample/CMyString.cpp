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
	// 새로운 문자열 할당에 앞서 기존 정보를 해제한다.
	Release();

	if (pszParam == NULL) { return 0; }

	//길이가 0인 문자열도 초기화로 인식하고 처리한다.
	int nLength = strlen(pszParam);

	if (nLength == 0) { return 0; }
	
	//문자열 끝은 NULL문자가 존재함
	m_pszData = new char[nLength + 1];

	//새로 할당한 메모리에 문자열을 저장한다.
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
