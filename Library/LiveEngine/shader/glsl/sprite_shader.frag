const GLchar* FragmentShader::SPRITE_SHADER_FRAG = "#version 300 es " STRINGIFY(
out mediump vec4 fragColor;
void main() {
    fragColor = vec4(1.0f, 0.0f, 0.0f, 0.0f);
});