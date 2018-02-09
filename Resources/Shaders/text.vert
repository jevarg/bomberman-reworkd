#version 410

uniform float winX;
uniform float winY;

uniform sampler2D fTexture0;

in vec2 vPosition;
in vec4 vColor;
in vec3 vNormal;
in vec2 vTexCoord;

out vec4 fColor;
out vec2 fUv;

void main(void)
{
  float x = winX / 2, y = winY / 2;

  fColor = vColor;
  fUv = vTexCoord;

  vec2 pos = vPosition - vec2(x, y);
  pos /= vec2(x, y);

  gl_Position = vec4(pos, 0, 1);
}
