#pragma once
#include "Entity.h"
#include "State.h"
class SplashState : public State
{
public:
	SplashState();
	~SplashState();

void OnEnter(StateMachine* pMachine);
void OnUpdate(float dt, StateMachine* pMachine);
void OnExit(StateMachine* pMachine);
void OnDraw(Renderer2D* m_2dRenderer);

float m_fTimer;
float m_fAlpha;
};

