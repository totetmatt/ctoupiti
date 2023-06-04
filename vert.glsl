#version 460
layout (location = 0) in vec3 aPos;
out vec4 vColor;
void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   vColor=vec4(1.0,1.0,1.0,1.);
}