// Generated with Shader Minifier 1.3.6 (https://github.com/laurentlb/Shader_Minifier/)
#ifndef SHADERS_H_
# define SHADERS_H_

const char *vert_glsl =
 "#version 460\n"
 "layout(location=0) in vec3 aPos;"
 "layout(location=1) in vec3 aColor;"
 "layout(location=2) in vec2 aTexCoord;"
 "out vec3 ourColor;"
 "out vec2 TexCoord;"
 "void main()"
 "{"
   "gl_Position=vec4(aPos,1);"
   "ourColor=aColor;"
   "TexCoord=aTexCoord;"
 "}";

const char *frag_glsl =
 "#version 460\n"
 "uniform float fGlobalTime;"
 "out vec4 FragColor;"
 "in vec3 ourColor;"
 "in vec2 TexCoord;"
 "uniform sampler2D checker,cs_text;"
 "void main()"
 "{"
   "FragColor=mix(texture(checker,TexCoord),texture(cs_text,TexCoord),fract(fGlobalTime));"
 "}";

const char *compute_glsl =
 "#version 430\n"
 "layout(local_size_x=2,local_size_y=2)in;\nlayout(rgba32f,binding=0)uniform image2D img_output;\n"
 "void main()"
 "{"
   "vec4 pixel=vec4(0,0,0,1);"
   "ivec2 pixel_coords=ivec2(gl_GlobalInvocationID.xy);"
   "pixel=vec4(vec3(length(pixel_coords.xy/512.-.5)-.25),1);"
   "imageStore(img_output,pixel_coords,pixel);"
 "}";

#endif // SHADERS_H_
