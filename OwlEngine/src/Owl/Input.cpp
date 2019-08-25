#include "oepch.h"
#include "Input.h"

namespace OE {

	Input* Input::instance = NULL;

	Input::Input()
	{
		out = false;
	}

	Input * Input::getInstance()
	{
		if (instance == NULL)
		{
			instance = new Input();
		}

		return instance;
	}

	void Input::update()
	{
		for (int i = 0; i < LASTKEY; i++)
		{
			keysDown[i] = false;
			keysUp[i] = false;
		}

		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				out = true;
				break;
			case SDL_KEYDOWN:
				if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) 
				{
					out = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_A)
				{
					keys[A] = true;
					keysDown[A] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_B)
				{
					keys[B] = true;
					keysDown[B] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_C)
				{
					keys[C] = true;
					keysDown[C] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_D)
				{
					keys[D] = true;
					keysDown[D] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_E)
				{
					keys[E] = true;
					keysDown[E] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_F)
				{
					keys[F] = true;
					keysDown[F] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_G)
				{
					keys[G] = true;
					keysDown[G] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_H)
				{
					keys[H] = true;
					keysDown[H] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_I)
				{
					keys[I] = true;
					keysDown[I] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_J)
				{
					keys[J] = true;
					keysDown[J] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_K)
				{
					keys[K] = true;
					keysDown[K] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_L)
				{
					keys[L] = true;
					keysDown[L] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_M)
				{
					keys[M] = true;
					keysDown[M] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_N)
				{
					keys[N] = true;
					keysDown[N] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_O)
				{
					keys[O] = true;
					keysDown[O] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_P)
				{
					keys[P] = true;
					keysDown[P] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_Q)
				{
					keys[Q] = true;
					keysDown[Q] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_R)
				{
					keys[R] = true;
					keysDown[R] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_S)
				{
					keys[S] = true;
					keysDown[S] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_T)
				{
					keys[T] = true;
					keysDown[T] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_U)
				{
					keys[U] = true;
					keysDown[U] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_V)
				{
					keys[V] = true;
					keysDown[V] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_W)
				{
					keys[W] = true;
					keysDown[W] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_X)
				{
					keys[X] = true;
					keysDown[X] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_Y)
				{
					keys[Y] = true;
					keysDown[Y] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_Z)
				{
					keys[Z] = true;
					keysDown[Z] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
				{
					keys[Shift] = true;
					keysDown[Shift] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_LCTRL)
				{
					keys[LControl] = true;
					keysDown[LControl] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_RCTRL)
				{
					keys[RControl] = true;
					keysDown[RControl] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_UP)
				{
					keys[UpArrow] = true;
					keysDown[UpArrow] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_LEFT)
				{
					keys[LeftArrow] = true;
					keysDown[LeftArrow] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT)
				{
					keys[RightArrow] = true;
					keysDown[RightArrow] = true;
				}
				if (e.key.keysym.scancode == SDL_SCANCODE_DOWN)
				{
					keys[DownArrow] = true;
					keysDown[DownArrow] = true;
				}
				break;
				case SDL_KEYUP:
					if (e.key.keysym.scancode == SDL_SCANCODE_A)
					{
						keys[A] = false;
						keysUp[A] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_B)
					{
						keys[B] = false;
						keysUp[B] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_C)
					{
						keys[C] = false;
						keysUp[C] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_D)
					{
						keys[D] = false;
						keysUp[D] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_E)
					{
						keys[E] = false;
						keysUp[E] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_F)
					{
						keys[F] = false;
						keysUp[F] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_G)
					{
						keys[G] = false;
						keysUp[G] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_H)
					{
						keys[H] = false;
						keysUp[H] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_I)
					{
						keys[I] = false;
						keysUp[I] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_J)
					{
						keys[J] = false;
						keysUp[J] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_K)
					{
						keys[K] = false;
						keysUp[K] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_L)
					{
						keys[L] = false;
						keysUp[L] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_M)
					{
						keys[M] = false;
						keysUp[M] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_N)
					{
						keys[N] = false;
						keysUp[N] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_O)
					{
						keys[O] = false;
						keysUp[O] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_P)
					{
						keys[P] = false;
						keysUp[P] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_Q)
					{
						keys[Q] = false;
						keysUp[Q] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_R)
					{
						keys[R] = false;
						keysUp[R] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_S)
					{
						keys[S] = false;
						keysUp[S] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_T)
					{
						keys[T] = false;
						keysUp[T] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_U)
					{
						keys[U] = false;
						keysUp[U] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_V)
					{
						keys[V] = false;
						keysUp[V] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_W)
					{
						keys[W] = false;
						keysUp[W] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_X)
					{
						keys[X] = false;
						keysUp[X] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_Y)
					{
						keys[Y] = false;
						keysUp[Y] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_Z)
					{
						keys[Z] = false;
						keysUp[Z] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
					{
						keys[Shift] = false;
						keysUp[Shift] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_LCTRL)
					{
						keys[LControl] = false;
						keysUp[LControl] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_RCTRL)
					{
						keys[RControl] = false;
						keysUp[RControl] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_UP)
					{
						keys[UpArrow] = false;
						keysUp[UpArrow] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_LEFT)
					{
						keys[LeftArrow] = false;
						keysUp[LeftArrow] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					{
						keys[RightArrow] = false;
						keysUp[RightArrow] = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_DOWN)
					{
						keys[DownArrow] = false;
						keysUp[DownArrow] = true;
					}
					break;
			default:
				break;
			}
		}
	}

	Input::~Input()
	{
	}

}