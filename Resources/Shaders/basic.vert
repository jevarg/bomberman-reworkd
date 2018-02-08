#version 410

uniform mat3 normal;
uniform mat4 modelView;
uniform mat4 projection;

uniform sampler2D fTexture0;

in vec3 vPosition;
//in vec4 vColor;
in vec3 vNormal;
in vec2 vTexCoord;

//out vec4 fColor;
//out vec3 fNormal;
//out vec2 fUv;
out vec4 fEyePos;
out vec3 fNormal;
//out vec3 fPosition;

void main(void)
{
    
    fEyePos = modelView * vec4(vPosition.xyz, 1.0);
    fNormal = normalize(normal * vNormal);
    gl_Position =  projection * fEyePos;
}