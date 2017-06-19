#include "StateMachine.h"
#include "Renderer2D.h"
#include <crtdbg.h>
using namespace aie;

StateMachine::StateMachine()
{
	//initializes backUpdate to false
	backUpdate = false;
}

StateMachine::~StateMachine()
{
	while (m_CurrentStack.Size() > 0)
		PopState();

	for (int i = 0; i < m_StateList.Size(); ++i)
	{
		delete m_StateList[i];
	}
}

void StateMachine::Update(float deltaTime)
{
	_ASSERT(m_CurrentStack.Size() > 0);
	if (m_CurrentStack.Size() <= 0)
		return;

	//Update in background
	/*if (backUpdate)
	m_CurrentStack.SecondLast()->onUpdate(deltaTime, this);*/

	m_CurrentStack.Top()->OnUpdate(deltaTime, this);
}


void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	_ASSERT(m_CurrentStack.Size() > 0);
	if (m_CurrentStack.Size() <= 0)
		return;

	if (backUpdate)
		m_CurrentStack.SecondLast()->OnDraw(m_2dRenderer);

	m_CurrentStack.Top()->OnDraw(m_2dRenderer);
}

void StateMachine::PushState(int nStateIndex)
{
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnExit(this);

	m_CurrentStack.PushBack(m_StateList[nStateIndex]);
	m_CurrentStack.Top()->OnEnter(this);
}

void StateMachine::PopState()
{
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnExit(this);

	m_CurrentStack.Pop();

	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnEnter(this);
}

void StateMachine::AddState(int nStateIndex, State* pState)
{
	m_StateList.Insert(nStateIndex, pState);
}

void StateMachine::SetBackgroundUpdate(bool on_off)
{
	backUpdate = on_off;
}