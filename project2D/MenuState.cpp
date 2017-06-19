#include "MenuState.h"
#include <iostream>
using namespace std;

MenuState::MenuState()
{
}

MenuState::~MenuState()
{
}

void MenuState::OnEnter(StateMachine* pMachine)
{

}

void MenuState::OnUpdate(float dt, StateMachine* pMachine)
{

}

void MenuState::OnDraw(Renderer2D* m_2dRenderer)
{
	cout << "xcv" << endl;
}

void MenuState::OnExit(StateMachine* pMachine)
{

}