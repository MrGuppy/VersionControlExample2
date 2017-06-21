#pragma once
#include "Entity.h"
#include "State.h"
class GameState : public State 
{
public:
	GameState();
	~GameState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float dt, StateMachine* pMachine);
	void OnExit(StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
};

