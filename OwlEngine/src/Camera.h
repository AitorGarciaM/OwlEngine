#pragma once
#include "Owl/Core.h"
#include "Owl/Transform.h"

enum Projection
{
	Ortho,
	Perpective
};

/**
*@class Camera
*@brief Dibuja en pantalla lo que enfoca.
*/
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

	/**
	* Inicializa la camara.
	*/
	void init(Projection _proj);

	/**
	* Actualiza la camara cada vuelta de proceso.
	*/
	void update();

	/**
	*@return Nos devuelve la matriz de proyección de la camara.
	*/
	mat4 getProjection() { return projection; }
	/**
	* @return nos devuelve la matriz de la vista de la camara.
	*/
	mat4 getView() { return view; }

	/**
	* @return Nos devuelve la matríz de posición, rotación y escalado de la camara. 
	*/
	OE::Transform* getTransform() { return transform; }
};