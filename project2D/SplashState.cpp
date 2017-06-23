#include "SplashState.h"
#include <iostream>
using namespace std;

SplashState::SplashState()
{
	m_pFont = new Font("./font/consolas.ttf", 25);
}

SplashState::~SplashState()
{
	delete m_pFont;
}

void SplashState::OnEnter(StateMachine* pMachine)
{
	m_fAlpha = 0.0f;
	m_fTimer = 0.0f;
}

void SplashState::OnUpdate(float deltaTime, StateMachine* pMachine)
{
	//change onupdate command 
	m_fTimer += deltaTime;

	if (m_fTimer <= 3.0f)
	{
		m_fAlpha += deltaTime;
	}

	if (m_fAlpha >= 1.0f)
	{
		m_fAlpha = 1.0f;
	}

	if (m_fTimer >= 3.0f)
	{
		m_fAlpha -= deltaTime;
	}

	if (m_fTimer >= 5.0f)
	{
		pMachine->PushState(1);
	}
}

void SplashState::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 1, 1, m_fAlpha);
 	m_2dRenderer->drawText(m_pFont, "Loading ...", 500, 400);
}

void SplashState::OnExit(StateMachine* pMachine)
{
	m_fAlpha = 0.0f;
	m_fTimer = 0.0f;
}