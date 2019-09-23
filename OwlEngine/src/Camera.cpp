#include "oepch.h"
#include "Camera.h"

Camera::Camera()
{
	transform = new OE::Transform();
	view = mat4(1);
	projection = mat4(1);
}

Camera::~Camera()
{
	delete transform;
}

void Camera::init(Projection _proj)
{
	if (_proj == Ortho)
	{
		projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
	}
	else if(_proj == Perpective)
	{
		projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);
	}

	transform->setPosition({ 0,0,3 });
}

void Camera::update()
{
	view = glm::lookAt(transform->getPosition(), transform->getPosition() + forward, vector3UP);
}


