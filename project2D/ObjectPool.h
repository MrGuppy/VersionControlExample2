#pragma once

class Entity;

class ObjectPool
{
	ObjectPool(int nMaxSize);
	~ObjectPool();
	Entity* Allocate();
	void Deallocate(Entity* Object);

private:
	Entity** m_pPool;
	int m_nMaxSize;
};
