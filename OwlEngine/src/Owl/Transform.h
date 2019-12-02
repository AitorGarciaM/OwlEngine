#pragma once
#include "Core.h"

namespace OE {

	/**
	* @class Transform
	* @brief Nos permite cambiar la posicion, rotacion y escalado de una maya.
	*/
	class OWL_API Transform
	{
		mat4 transform;
		vector3 position;
		vector3 rotation;
		vector3 scale;
	public:
		Transform();
		~Transform();
		/**
		* Nos devuebe la posición.
		*/
		vector3 getPosition()		{ return position; }
		/**
		* Nos devuelbe la rotación.
		*/
		vector3 getRotation()		{ return rotation; }
		/**
		* Nos devuelbe el escalado.
		*/
		vector3 getScale()			{ return scale;    }
		/**
		* Nos devuelbe la matriz del transform.
		*/
		mat4 getTransform()			{ return transform; }

		/**
		* Configura la posición.
		*/
		void setPosition(vector3 _position);
		/**
		* Configura la rotación.
		*/
		void setRotation(vector3 _rotation);
		/**
		* Configura el escalado.
		*/
		void setScale(vector3 _scale);
		/**
		* Reinicia la matriz.
		*/
		void resetTransform() { transform = mat4(1); }
	};

}