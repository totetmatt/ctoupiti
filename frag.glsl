#version 460
uniform float fGlobalTime;
out vec4 FragColor;
    
in vec3 ourColor;
in vec2 TexCoord;

 uniform sampler2D checker;

 uniform sampler2D cs_text;
void main()
{
   FragColor = mix(texture(checker, TexCoord),texture(cs_text, TexCoord),fract(fGlobalTime));  

}