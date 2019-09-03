#include "oepch.h"
#include "Transform.h"

namespace OE {

	Transform::Transform()
	{
		transform = mat4(1);
	}


	Transform::~Transform()
	{
	}

	void Transform::setPosition(vector3 _position)
	{
		position = _position;

		transform = glm::translate(transform, position);
	}

	void Transform::setRotation(vector3 _rotation)
	{
		rotation = _rotation;

		transform = glm::rotate(transform, glm::radians(_rotation.x), vector3(1.0f, 0.0f, 0.0f));
		transform = glm::rotate(transform, glm::radians(_rotation.y), vector3(0.0f, 1.0f, 0.0f));
		transform = glm::rotate(transform, glm::radians(_rotation.z), vector3(0.0f, 0.0f, 1.0f));
	}

	void Transform::setScale(vector3 _scale)
	{
		scale = _scale;

		transform = glm::scale(transform, _scale);
	}

}