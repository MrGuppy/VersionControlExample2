#pragma once
#include "Application2D.h"
#include "Texture.h"

class Entity
{
public:
	Entity();
	~Entity();
	

	void SetActive(bool bActive);
	bool GetActive();

	void Update(float dt);
	void Draw(aie::Renderer2D* m_Renderer2D);
private:
	bool m_bActive;

};

