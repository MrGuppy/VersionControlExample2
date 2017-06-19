#pragma once
#include "Entity.h"
class GameState
{
public:
	GameState();
	~GameState();

	void Updtate(float dt);
	void Draw(aie::Renderer2D* m_Renderer2D);
};

