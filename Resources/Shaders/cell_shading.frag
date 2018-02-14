#version 410

uniform sampler2D fTexture0;

in vec3 fNormal;
in vec4 fPosition;
in vec2 fUv;

out vec4 FragColor;


// Background color
vec3 background(vec3 rd)
{
    return mix(vec3(0.4, 0.3, 0.0), vec3(0.7, 0.8, 1.0), rd.y * 0.5 + 0.5);
}

// Shading and lighting
// p : point,
// n : normal at point
vec3 Shade(vec3 p, vec3 n)
{
    // point light
    vec3 lightPos = vec3(20.0, 10.0, 30.0);
    const vec3 lightColor = vec3(0.5, 0.2, 0.5);
    
    // Color of the object comes from background !
    vec3 c = 0.25 * background(n);
    
    vec3 l = normalize(lightPos - p);
    
    // Not even Phong shading, use weighted cosine instead for smooth transitions
    float diff = 0.5 * (1.0 + dot(n, l));

    if (diff <= 0.33) {
        diff = 0.0;
    } else if (diff > 0.33 && diff <= 0.50) {
        diff = 0.33;
    } else if (diff > 0.50 && diff <= 0.73) {
        diff = 0.50;
    } else if (diff > 0.73 && diff <= 0.99) {
        diff = 0.73;
    } else if (diff > 0.99) {
        diff = 0.99;
    }
    
    c += diff * lightColor;
    
    return c;
}

void main()
{
//    FragColor = texture(fTexture0, fUv);
    FragColor = vec4(Shade(fPosition.xyz, fNormal), 1.0f);
}
