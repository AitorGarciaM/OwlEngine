#pragma once
#include "Core.h"

namespace OE
{
	class Texture
	{
		
		int h;
		int w;
		std::string path;
	public:
		unsigned int id;

		void setHeight(int _h) { h = _h; }
		void setWidth(int _w) { w = _w; }

		int getHeight() { return h; }
		int getWidth() { return w; }
		Texture();
		~Texture();
	};
}
