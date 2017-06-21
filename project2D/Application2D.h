#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "StateMachine.h"
#include "Font.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	StateMachine*		m_pStateMachine;
	Texture*			m_pShipTexture;
	aie::Font*			m_pFont;

	float m_cameraX, m_cameraY;
	float m_timer;
};