#include "PauseScreen.h"
#include "Dialog.h"
#include "Game.h"

PauseScreen::PauseScreen(): UIScreen()
{
	Game::instance().setState(GameState::Pause);
	Game::instance().getInputSystem().setMouseRelativeMode(false);
	setTitle("PauseTitle");
	addButton("ResumeButton", [this]() { close(); });
	addButton("QuitButton", [this]() {
		new DialogBox("QuitText", [this]() { Game::instance().setState(GameState::Quit); }); 
	});
}

PauseScreen::~PauseScreen() 
{
	Game::instance().setState(GameState::Gameplay);
	Game::instance().getInputSystem().setMouseRelativeMode(true);
}
void PauseScreen::processInput(const InputState& inputState)
{
	UIScreen::processInput(inputState);
	if (inputState.keyboard.getKeyState(SDL_SCANCODE_ESCAPE) == ButtonState::Released)
	{
		close();
	}
}
