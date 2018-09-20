const GLchar* VertexShader::SPRITE_SHADER_VERT = "#version 300 es " STRINGIFY(
in vec4 pos;
void main() {
   gl_Position = pos;
});