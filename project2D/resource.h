#pragma once
#include <string.h>
template <typename T>
class Resource
{
public:
	Resource(char* szFilename)
	{
		int length = strlen(szFilename);
		m_szFilename = new char[length + 1];
		strcpy_s(m_szFilename, length, szFilename);
		m_Data = new T(szFilename);
	}

	~Resource()
	{
		delete[] m_szFilename;
		delete[] m_Data;
	}

	char* m_szFilename;
	T m_Data;
};