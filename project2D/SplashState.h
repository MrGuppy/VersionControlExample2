#pragma once
#include "Entity.h"
#include "State.h"
class SplashState : public State
{
public:
	SplashState();
	~SplashState();

void OnEnter(StateMachine* pMachine);
void OnUpdate(float deltaTime, StateMachine* pMachine);
void OnExit(StateMachine* pMachine);
void OnDraw(Renderer2D* m_2dRenderer);

private:

float m_fTimer;
float m_fAlpha;

aie::Font* m_pFont;
};

