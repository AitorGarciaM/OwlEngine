#pragma once
#include "Core.h"
#include "SDL.h"

namespace OE {

	enum Key
	{
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		Shift, LControl, RControl,
		UpArrow, LeftArrow, RightArrow, DownArrow,
		LastKey
	};

#define LASTKEY			Key::LastKey
	
	class OWL_API Input
	{
	private:
		static Input* instance;
		SDL_Event e;

		bool keys[LASTKEY];
		bool keysDown[LASTKEY];
		bool keysUp[LASTKEY];

		bool out;
	protected:
		Input();
	public:
		static Input* getInstance();

		void update();

		bool getKey(Key _value) { return keys[_value]; }
		bool getKeyDown(Key _value) { return keysDown[_value]; }
		bool getKeyUp(Key _value) { return keysUp[_value]; }

		bool getExit() { return out; }
		~Input();
	};

}


