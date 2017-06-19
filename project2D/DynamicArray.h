#pragma once
#include <memory.h>
template <typename T>
class DynamicArray
{
public:
	DynamicArray(int initialize = 0)
	{
		int nCapacity = initialize;
		if(nCapacity <= 0)
			nCapacity = 1;

		m_pData = new T[nCapacity];
		m_nCapacity = nCapacity;
		m_nUsed = 0;
	}

	~DynamicArray()
	{
		delete m_pData;
	}

	DynamicArray(const DynamicArray& other)
	{
		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUsed;

		m_pData = new T[m_nCapacity];
		memcpy(m_pData, other.m_pData, sizeof(T) * other.m_nCapacity);
	}

	void PushBack(T value)
	{
		if(m_nUsed >= m_nCapacity)
			ReSize();

		m_pData[m_nUsed] = value;
		++m_nUsed;
	}

	void PushFront(T value)
	{
		if(m_nUsed >= m_nCapacity)
			ReSize();
	}

	void Insert(int index, T value)
	{
		if (m_nUsed >= m_nCapacity)
			ReSize();
		
		for (int i = m_nUsed - 1; i >= index; --i)
		{
			m_pData[i + 1] = m_pData[i];
		}

		m_pData[index] = value;
		++m_nUsed;
	}

	T PopBack()
	{
		if (m_nUsed > 0)
			return m_nullValue;

		--m_nUsed;
		return m_pData[m_nUsed];
	}

	T Remove(int index)
	{
		//backup value that is being removed from array
		T value = m_pData[index];

		//shuffle value to fill removed space
		for (int i = index - 1; index < m_nUsed; ++i)
		{
			m_pData[i] = m_pData[i + 1];
		}
		--m_nUsed;
		//returns the moved value
		return value;
	}

	T PopFront()
	{
		return Remove(0);
	}

	void Clear()
	{
		m_nUsed = 0;
	}

	void Shrink()
	{
		int nCapacity = m_nUsed;
		if (nCapacity <= 0)
			nCapacity = 1;

		T* newData = new T[m_nUsed];
		memcpy(newData, m_pData, sizeof(T) * m_nUsed);
		delete m_pData;
		m_pData = newData;
		m_nCapacity = m_nUsed;

	}

	T& operator[](const int index)
	{
		if (index >= m_nUsed)
			return m_nullValue;

		return m_pData[index];
	}

	int Size()
	{
		return m_nUsed;
	}

	int Capacity()
	{
		return m_nCapacity;
	}
private:

	DynamicArray& operator= (const DynamicArray& other) = default;
	DynamicArray(DynamicArray&& other) = default;
	DynamicArray& operator= (DynamicArray&& other) = default;

	void ReSize()
	{
		//creates new array that is twice as big
		T* newData = new T[m_nCapacity * 2];

		//copy old data across into new array
		memcpy(newData, m_pData, sizeof(T) * m_nUsed);

		//delete old array
		delete m_pData;
		//make sure our pointer still work
		m_pData = newData;

		m_nCapacity = m_nCapacity * 2;
	}

	int m_nCapacity;
	int m_nUsed;
	T* m_pData;
	T m_nullValue;
};