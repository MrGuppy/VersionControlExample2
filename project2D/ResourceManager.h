#pragma once
#include "DynamicArray.h"
#include "Resource.h"
#include <string.h>

template <typename T>
class ResourceManager
{
public:
	ResourceManager() {};
	~ResourceManager()
	{
		UnloadAllResources();
	}
	T LoadResource(char* szFilename)
	{
		//check if resource is loaded
		//if it is, return resource
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			if (strcmp(m_ResourceList[i]->m_szFilename, szFilename) == 0)
			{
				return m_ResourceList[i]->m_Data
			}
		}

		//resource is not loaded, so loads resource
		Resource* pResource = new Resource(szFilename);
		m_ResourceList->PushBack(pResource);
		return pResource;
	}
	//destroy resources
	void UnloadAllResources()
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}
		m_ResourceList.Clear();
	}

	DynamicArray<Resource<T>*> m_ResourceList;
};
