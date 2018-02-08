#version 410

uniform	mat4 projection;
uniform	mat4 view;
uniform	mat4 model;

uniform sampler2D fTexture0;

//in vec3 vPosition;
in vec4 fEyePos;
in vec3 fNormal;

out vec4 FragColor;

//out vec3 fPosition;
//out vec4 fColor;

//struct Light
//{
//  int type;
//  vec3    pos;
//  vec3    color;
//  float    power;
//};

//uniform int nbLight;
//uniform Light light[20];

/* Fog Exp2 */
//float getFog(float z, float density)
//{
//  return (1 - clamp(exp(-pow(density * z, 2.0)), 0.0, 1.0));
//}
//
//vec3 getLight(vec3 Color, vec3 Normal)
//{
//  int i;
//  vec3 ret = vec3(1.0, 1.0, 1.0);
//
//  for (i = 0;i < nbLight;i++)
//    {
//      vec3 l = (view * vec4(light[i].pos.xyz, 1.0)).xyz + (vec3(0.0, 0.0, 0.0) - fEyePos.xyz);
//      float d = length(l);
//      l = normalize(l);
//      vec3 n = normalize(Normal);
//
//      vec3 fAmbient = vec3(0.1, 0.1, 0.1) * Color;
//      float fDiffuse = clamp(dot(n, l), 0, 1);
//      float fSpec = clamp(dot(normalize(fEyePos.xyz), reflect(-l, n)), 0,1);
//      ret *= fAmbient + (Color * light[i].color * light[i].power * fDiffuse)
//    + (Color * light[i].color * light[i].power * pow(fSpec, 5));
//    }
//  return (ret);
//}

//void main(void)
//{
//  /* Density of the fog */
//  float density = 0.09;
//
//  vec4 fOutColor = texture(fTexture0, fUv);
//  vec3 color = vec3(fOutColor.xyz);
//  float factor = getFog(abs(fEyePos.z / fEyePos.w), density);
//
//  if (isLight == 1)
//    color = getLight(fOutColor.xyz, fNormal);
//
//  /* Color Fog = vec4(0.7, 0.7, 0.7, 1.0) => grey */
//  if (isFog == 1)
//    gl_FragColor = mix(vec4(color.xyz, fOutColor.w),
//               vec4(0.7, 0.7, 0.7, fOutColor.w), factor);
//  else
//    gl_FragColor = vec4(color.xyz, fOutColor.w);
//}

struct LightInfo {
    vec3 position;
    vec3 Ld; // diffuse
    vec3 La; // ambient
    vec3 Ls; // specular
};

struct MaterialInfo {
    vec3    Kd; // diffuse
    vec3    Ka; // ambient
    vec3    Ks; // specular
    float   shininess; // p specular coefficient
};

void main()
{
    
    LightInfo       light;
    MaterialInfo    material;

    light.position = vec3(3.0f, 5.0f, 3.0f);
    light.Ld = vec3(0.8f);
    light.La = vec3(0.8f);
    light.Ls = vec3(0.8f);

    material.shininess = 1.0f;
    material.Kd = vec3(0.8f, 0.2f, 0.2f);
    material.Ka = vec3(0.4f);
    material.Ks = vec3(0.8f);

    float dotLN;
    float dotRV;

    vec3 diffuse;
    vec3 specular;

    vec3 ambient = material.Ka * light.La;

    vec3 L = normalize(light.position - fEyePos.xyz);
    vec3 V = normalize(-fEyePos.xyz);
    vec3 R = normalize(reflect(-L, fNormal));

    dotLN = dot(L, fNormal);
    dotRV = dot(R, V);

    diffuse = material.Kd * light.Ld * max(dotLN, 0.0);
    specular = material.Ks * light.Ls * pow(max(dotRV, 0.0), material.shininess);

    FragColor = vec4(diffuse + specular + ambient, 1.0f);
//    FragColor = vec4(1.0);
}
