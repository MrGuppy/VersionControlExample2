#pragma once
#include "Renderer2D.h"
class StateMachine;
using namespace aie;

class State
{
public:
	State();
	~State();

	virtual void OnEnter(StateMachine* pMachine) = 0;
	virtual void OnUpdate(float dt, StateMachine* pMachine) = 0;
	virtual void OnExit(StateMachine* pMachine) = 0;
	virtual void OnDraw(Renderer2D* m_2dRenderer) = 0;
};

