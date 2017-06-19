#include "Application2D.h"
#include "Texture.h"
#include "StateMachine.h"
#include "SplashState.h"
#include "MenuState.h"
#include "GameState.h"
#include "ResourceManager.h"
using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();
	m_pStateMachine = new StateMachine();

	m_pStateMachine->AddState(0, new SplashState());
	m_pStateMachine->AddState(1, new MenuState());
	m_pStateMachine->AddState(2, new GameState());

	//add data to stateMachine to rid error
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	delete m_2dRenderer;
	delete m_pStateMachine;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;
	m_pStateMachine->Update(deltaTime);
}

void Application2D::draw() 
{
	clearScreen();

	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	m_2dRenderer->begin();

	m_pStateMachine->Draw(m_2dRenderer);

	m_2dRenderer->end();
}