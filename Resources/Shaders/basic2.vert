#version 410

uniform    mat4 projection;
uniform    mat4 view;
uniform    mat4 model;

uniform sampler2D fTexture0;

in vec3 vPosition;
in vec4 vColor;
in vec3 vNormal;
in vec2 vTexCoord;

out vec4 fColor;
out vec3 fNormal;
out vec2 fUv;
out vec4 fEyePos;
out vec3 fPosition;

struct Light
{
    int type;
    vec3    pos;
    vec3    color;
    float    power;
};

uniform int nbLight;
uniform Light light[20];

mat4 inverse_mat(mat4 mat)
{
    mat4 ret;
    
    ret[0][0] = mat[1][1] * mat[2][2] * mat[3][3] -
    mat[1][1] * mat[2][3] * mat[3][2] -
    mat[2][1] * mat[1][2] * mat[3][3] +
    mat[2][1] * mat[1][3] * mat[3][2] +
    mat[3][1] * mat[1][2] * mat[2][3] -
    mat[3][1] * mat[1][3] * mat[2][2];
    
    ret[0][1] = -mat[0][1]  * mat[2][2] * mat[3][3] +
    mat[0][1]  * mat[2][3] * mat[3][2] +
    mat[2][1]  * mat[0][2] * mat[3][3] -
    mat[2][1]  * mat[0][3] * mat[3][2] -
    mat[3][1] * mat[0][2] * mat[2][3] +
    mat[3][1] * mat[0][3] * mat[2][2];
    
    ret[0][2] = mat[0][1]  * mat[1][2] * mat[3][3] -
    mat[0][1]  * mat[1][3] * mat[3][2] -
    mat[1][1]  * mat[0][2] * mat[3][3] +
    mat[1][1]  * mat[0][3] * mat[3][2] +
    mat[3][1] * mat[0][2] * mat[1][3] -
    mat[3][1] * mat[0][3] * mat[1][2];
    
    ret[0][3] = -mat[0][1] * mat[1][2] * mat[2][3] +
    mat[0][1] * mat[1][3] * mat[2][2] +
    mat[1][1] * mat[0][2] * mat[2][3] -
    mat[1][1] * mat[0][3] * mat[2][2] -
    mat[2][1] * mat[0][2] * mat[1][3] +
    mat[2][1] * mat[0][3] * mat[1][2];
    
    ret[1][0] = -mat[1][0]  * mat[2][2] * mat[3][3] +
    mat[1][0]  * mat[2][3] * mat[3][2] +
    mat[2][0]  * mat[1][2]  * mat[3][3] -
    mat[2][0]  * mat[1][3]  * mat[3][2] -
    mat[3][0] * mat[1][2]  * mat[2][3] +
    mat[3][0] * mat[1][3]  * mat[2][2];
    
    ret[1][1] = mat[0][0]  * mat[2][2] * mat[3][3] -
    mat[0][0]  * mat[2][3] * mat[3][2] -
    mat[2][0]  * mat[0][2] * mat[3][3] +
    mat[2][0]  * mat[0][3] * mat[3][2] +
    mat[3][0] * mat[0][2] * mat[2][3] -
    mat[3][0] * mat[0][3] * mat[2][2];
    
    ret[1][2] = -mat[0][0]  * mat[1][2] * mat[3][3] +
    mat[0][0]  * mat[1][3] * mat[3][2] +
    mat[1][0]  * mat[0][2] * mat[3][3] -
    mat[1][0]  * mat[0][3] * mat[3][2] -
    mat[3][0] * mat[0][2] * mat[1][3] +
    mat[3][0] * mat[0][3] * mat[1][2];
    
    ret[1][3] = mat[0][0] * mat[1][2] * mat[2][3] -
    mat[0][0] * mat[1][3] * mat[2][2] -
    mat[1][0] * mat[0][2] * mat[2][3] +
    mat[1][0] * mat[0][3] * mat[2][2] +
    mat[2][0] * mat[0][2] * mat[1][3] -
    mat[2][0] * mat[0][3] * mat[1][2];
    
    ret[2][0] = mat[1][0]  * mat[2][1] * mat[3][3] -
    mat[1][0]  * mat[2][3] * mat[3][1] -
    mat[2][0]  * mat[1][1] * mat[3][3] +
    mat[2][0]  * mat[1][3] * mat[3][1] +
    mat[3][0] * mat[1][1] * mat[2][3] -
    mat[3][0] * mat[1][3] * mat[2][1];
    
    ret[2][1] = -mat[0][0]  * mat[2][1] * mat[3][3] +
    mat[0][0]  * mat[2][3] * mat[3][1] +
    mat[2][0]  * mat[0][1] * mat[3][3] -
    mat[2][0]  * mat[0][3] * mat[3][1] -
    mat[3][0] * mat[0][1] * mat[2][3] +
    mat[3][0] * mat[0][3] * mat[2][1];
    
    ret[2][2] = mat[0][0]  * mat[1][1] * mat[3][3] -
    mat[0][0]  * mat[1][3] * mat[3][1] -
    mat[1][0]  * mat[0][1] * mat[3][3] +
    mat[1][0]  * mat[0][3] * mat[3][1] +
    mat[3][0] * mat[0][1] * mat[1][3] -
    mat[3][0] * mat[0][3] * mat[1][1];
    
    ret[2][3] = -mat[0][0] * mat[1][1] * mat[2][3] +
    mat[0][0] * mat[1][3] * mat[2][1] +
    mat[1][0] * mat[0][1] * mat[2][3] -
    mat[1][0] * mat[0][3] * mat[2][1] -
    mat[2][0] * mat[0][1] * mat[1][3] +
    mat[2][0] * mat[0][3] * mat[1][1];
    
    ret[3][0] = -mat[1][0]  * mat[2][1] * mat[3][2] +
    mat[1][0]  * mat[2][2] * mat[3][1] +
    mat[2][0]  * mat[1][1] * mat[3][2] -
    mat[2][0]  * mat[1][2] * mat[3][1] -
    mat[3][0] * mat[1][1] * mat[2][2] +
    mat[3][0] * mat[1][2] * mat[2][1];
    
    ret[3][1] = mat[0][0]  * mat[2][1] * mat[3][2] -
    mat[0][0]  * mat[2][2] * mat[3][1] -
    mat[2][0]  * mat[0][1] * mat[3][2] +
    mat[2][0]  * mat[0][2] * mat[3][1] +
    mat[3][0] * mat[0][1] * mat[2][2] -
    mat[3][0] * mat[0][2] * mat[2][1];
    
    ret[3][2] = -mat[0][0]  * mat[1][1] * mat[3][2] +
    mat[0][0]  * mat[1][2] * mat[3][1] +
    mat[1][0]  * mat[0][1] * mat[3][2] -
    mat[1][0]  * mat[0][2] * mat[3][1] -
    mat[3][0] * mat[0][1] * mat[1][2] +
    mat[3][0] * mat[0][2] * mat[1][1];
    
    ret[3][3] = mat[0][0] * mat[1][1] * mat[2][2] -
    mat[0][0] * mat[1][2] * mat[2][1] -
    mat[1][0] * mat[0][1] * mat[2][2] +
    mat[1][0] * mat[0][2] * mat[2][1] +
    mat[2][0] * mat[0][1] * mat[1][2] -
    mat[2][0] * mat[0][2] * mat[1][1];
    
    int i;
    int j;
    float determinant;
    
    determinant = mat[0][0] * ret[0][0] + mat[0][1] * ret[1][0] +
    mat[0][2] * ret[2][0] + mat[0][3] * ret[3][0];
    
    if (determinant == 0)
        return mat4(1.0);
    
    determinant = 1.0 / determinant;
    
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4;j++)
            ret[i][j] = ret[i][j] * determinant;
    
    return (ret);
}

void main(void)
{
    vec4 transformedNormal = inverse_mat(transpose(model)) * vec4(vNormal.xyz, 0.0);
    
    fPosition = vPosition;
    fEyePos = view * model * vec4(vPosition.xyz, 1.0);
    fColor = vColor;
    fUv = vTexCoord;
    fNormal = normalize(transformedNormal.xyz);
    
    gl_Position =  projection * fEyePos;
}

