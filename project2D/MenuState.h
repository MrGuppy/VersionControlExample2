#pragma once
#include "Entity.h"
class MenuState
{
public:
	MenuState();
	~MenuState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float dt, StateMachine* pMachine);
	void OnExit(StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
};

