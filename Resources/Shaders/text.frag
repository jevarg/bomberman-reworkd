#version 410

uniform	mat4 projection;
uniform	mat4 view;

uniform sampler2D fTexture0;

in vec4 fColor;
in vec2 fUv;

out vec4 FragColor;

void main(void)
{
  FragColor = texture(fTexture0, fUv);
}
