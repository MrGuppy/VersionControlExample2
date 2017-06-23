// # defines that allow access to other classes
#include "Application2D.h"
#include "Texture.h"
#include "StateMachine.h"
#include "SplashState.h"
#include "MenuState.h"
#include "GameState.h"
#include "ResourceManager.h"
#include <crtdbg.h>
#include "Font.h"
using namespace aie;


//---------------------------------------
//
//---------------------------------------
Application2D::Application2D() 
{
}

//---------------------------------------
//
//---------------------------------------
Application2D::~Application2D() 
{
}

//---------------------------------------
//
//---------------------------------------
bool Application2D::startup() 
{
	_ASSERT(m_2dRenderer);
	m_2dRenderer = new Renderer2D();

	ResourceManager<Texture>::Create();

	ResourceManager<Texture>* pManageTexture = ResourceManager<Texture>::GetInstance();

	_ASSERT(m_pStateMachine);
	m_pStateMachine = new StateMachine();

	m_pStateMachine->AddState(0, new SplashState());
	m_pStateMachine->AddState(1, new MenuState());
	m_pStateMachine->AddState(2, new GameState());


	m_pStateMachine->PushState(0);

	m_timer = 0;

	return true;
}

//---------------------------------------
//
//---------------------------------------
void Application2D::shutdown() 
{
	delete m_2dRenderer;

	//for (int i = 0; i < 4; ++i)
	//{
		delete m_pStateMachine;
	//}
}

//---------------------------------------
//
//
//
//---------------------------------------
void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;
	m_pStateMachine->Update(deltaTime);
}

//---------------------------------------
//
//---------------------------------------
void Application2D::draw() 
{
	clearScreen();

	m_2dRenderer->begin();

	m_pStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->end();
}