#version 410

uniform mat3 normal;
uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;

uniform sampler2D fTexture0;

in vec3 vPosition;
//in vec4 vColor;
in vec3 vNormal;
in vec2 vTexCoord;

out vec2 fUv = vTexCoord;
out vec4 fPosition;
out vec3 fNormal;

void main(void)
{
    mat4 modelView = view * model;
    mat4 inverseModelView = inverse(modelView);
    mat3 normal = mat3(transpose(inverseModelView));
    
    fPosition = modelView * vec4(vPosition.xyz, 1.0);
    fNormal = normalize(normal * vNormal);
    gl_Position =  projection * fPosition;
}
