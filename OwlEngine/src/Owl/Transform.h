#pragma once
#include "Core.h"

namespace OE {

	class OWL_API Transform
	{
		mat4 transform;
		vector3 position;
		vector3 rotation;
		vector3 scale;
	public:
		Transform();
		~Transform();

		vector3 getPosition()		{ return position; }
		vector3 getRotation()		{ return rotation; }
		vector3 getScale()			{ return scale;    }
		mat4 getTransform()			{ return transform; }

		void setPosition(vector3 _position);
		void setRotation(vector3 _rotation);
		void setScale(vector3 _scale);

		void resetTransform() { transform = mat4(1); }
	};

}