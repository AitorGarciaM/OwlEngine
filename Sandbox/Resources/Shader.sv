#version 330 core

layout (location = 0) in vec3 aPos;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	vec4 model = transform * vec4(aPos.x, aPos.y, aPos.z, 1);
    gl_Position = projection * view * model;
}