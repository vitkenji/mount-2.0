#pragma once
#include "std.h"

namespace States
{
	class StateMachine;

	enum State_ID
	{
		unknown = -1,
		mainMenu = 0,
		newGame,
		playing,
		pauseMenu,
		settings,
		leaderboard,
		gameover
	};

	class State
	{
	private:
		StateMachine* pStateMachine;
		State_ID id;

	public:
		State(StateMachine* pSM, State_ID id);
		~State();
		void setStateMachine(StateMachine* pSM);
		void changeState(State_ID state);
		State_ID getID() const;
		virtual void update(const float dt) = 0;
		virtual void render() = 0;
		virtual void resetState() = 0;

	};
}