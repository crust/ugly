#version 410

uniform mat4 projection;
uniform mat4 modelview;

in vec4 position;
in vec2 texcoord_in;
out vec2 texcoord;

void main() {

  texcoord = texcoord_in;
  gl_Position = projection * modelview * position;

}
