#pragma once
#include <string.h>
template <typename T>
class Resource
{
public:
	Resource(char* szFilename)
	{
		int length = strlen(szFilename) + 1;
		_ASSERT(m_szFilename);
		m_szFilename = new char[length];
		strcpy_s(m_szFilename, length, szFilename);
		m_pData = new T(szFilename);
	}

	~Resource()
	{
		delete[] m_szFilename;
		delete[] m_pData;
	}

	char* m_szFilename;
	T* m_pData;
};