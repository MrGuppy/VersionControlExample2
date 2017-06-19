#include "Entity.h"

Entity::Entity()
{
	m_bActive = false;
}

Entity::~Entity()
{
}

void Entity::Draw(aie::Renderer2D* m_Renderer2D)
{

}

void Entity::Update(float dt)
{

}

void Entity::SetActive(bool bActive)
{
	m_bActive = bActive;
}

bool Entity::GetActive()
{
	return m_bActive;
}