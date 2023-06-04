// Generated with Shader Minifier 1.3.6 (https://github.com/laurentlb/Shader_Minifier/)
#ifndef SHADERS_H_
# define SHADERS_H_

const char *vert_glsl =
 "#version 460\n"
 "layout(location=0) in vec3 aPos;"
 "out vec4 vColor;"
 "void main()"
 "{"
   "gl_Position=vec4(aPos.xyz,1);"
   "vColor=vec4(1);"
 "}";

const char *frag_glsl =
 "#version 460\n"
 "uniform float fGlobalTime;"
 "out vec4 FragColor;"
 "in vec4 vColor;"
 "void main()"
 "{"
   "FragColor=vec4(vColor)*sin(fGlobalTime);"
 "}";

#endif // SHADERS_H_
