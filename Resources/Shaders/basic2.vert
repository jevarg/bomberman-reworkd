#version 410

in vec4 coord3d;
in vec3 v_color;

uniform mat4 mvp;

out vec3 f_color;

void main(void)
{
    gl_Position = mvp * coord3d;
	f_color = v_color;
}
