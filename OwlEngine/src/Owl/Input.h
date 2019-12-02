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
	
	/**
	* @class Input
	* @brief detecta entradas de teclado y raton.
	*/
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

		/**
		* nos devuelve la instancia de la clase.
		*/
		static Input* getInstance();

		/**
		* Actualiza la cola de detección de teclas.
		*/
		void update();
		/**
		* Nos debuelve si una tecla está pulsada.
		*/
		bool getKey(Key _value) { return keys[_value]; }
		/**
		* Nos debuelve si una tecla se ha pulsado.
		*/
		bool getKeyDown(Key _value) { return keysDown[_value]; }
		/**
		* Nos debuelve si una tecla se ha liberado.
		*/
		bool getKeyUp(Key _value) { return keysUp[_value]; }
		/**
		* Nos devuelve si se ha salido de la aplicación.
		*/
		bool getExit() { return out; }
		~Input();
	};

}


