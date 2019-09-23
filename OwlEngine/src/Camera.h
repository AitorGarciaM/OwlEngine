#pragma once
//#include "Owl.h"
#include "Owl/Core.h"
#include "Owl/Transform.h"

enum Projection
{
	Ortho,
	Perpective
};

class OWL_API Camera
{
	OE::Transform* transform;
	vector3 forward = { 0.0f ,0.0f, -1.0f };
	mat4 projection;
	mat4 view;

	float fov = 45;
public:
	Camera();
	~Camera();

	void init(Projection _proj);
	void update();

	mat4 getProjection() { return projection; }
	mat4 getView() { return view; }
	OE::Transform* getTransform() { return transform; }
};