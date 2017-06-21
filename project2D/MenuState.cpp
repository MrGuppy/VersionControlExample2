#include "MenuState.h"
#include <iostream>
using namespace std;

MenuState::MenuState()
{
	m_pFont = new Font("./font/consolas.ttf", 25);
}

MenuState::~MenuState()
{
	delete m_pFont;
}

void MenuState::OnEnter(StateMachine* pMachine)
{
	m_fAlpha = 0.0f;
	m_fTimer = 0.0f;
}

void MenuState::OnUpdate(float deltaTime, StateMachine* pMachine)
{
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
		pMachine->PushState(2);
	}
}

void MenuState::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 1, 1, m_fAlpha);
	m_2dRenderer->drawText(m_pFont, "qqqqqqqqqqqqq", 1250, 1250);
}

void MenuState::OnExit(StateMachine* pMachine)
{
	m_fAlpha = 0.0f;
	m_fTimer = 0.0f;
}