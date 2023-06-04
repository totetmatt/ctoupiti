#version 460
uniform float fGlobalTime;
out vec4 FragColor;
    
in vec4 vColor;
void main()
{
  FragColor = vec4(vColor)*sin(fGlobalTime);
}