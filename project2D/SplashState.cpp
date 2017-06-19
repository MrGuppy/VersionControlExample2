#include "SplashState.h"
#include <iostream>
using namespace std;

SplashState::SplashState()
{
	m_fAlpha = 1.0f;
	m_fTimer = 1.0f;
}

SplashState::~SplashState()
{
}

void SplashState::OnEnter(StateMachine* pMachine)
{

}

void SplashState::OnUpdate(float dt, StateMachine* pMachine)
{
	
}

void SplashState::OnDraw(Renderer2D* m_2dRenderer)
{
	cout << "Jezus" << endl;
	system("pause");
}

void SplashState::OnExit(StateMachine* pMachine)
{

}