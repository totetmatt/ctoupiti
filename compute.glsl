#version 430
//[
layout(local_size_x = 2, local_size_y = 2) in;
layout(rgba32f, binding = 0) uniform image2D img_output;
//]
void main() {
  // base pixel colour for image
  vec4 pixel = vec4(0.0, 0.0, 0.0, 1.0);
  // get index in global work group i.e x,y position
  ivec2 pixel_coords = ivec2(gl_GlobalInvocationID.xy);
  
  //
  // interesting stuff happens here later
  //
    vec2 uv = pixel_coords.xy/512.-.5;
    pixel = vec4(vec3(length(uv)-.25),1.);
  // output to a specific pixel in the image
  imageStore(img_output, pixel_coords, pixel);
}