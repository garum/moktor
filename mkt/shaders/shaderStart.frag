#version 400

in vec3 colour;
in vec2 passTexture;

out vec4 fragmentColour;
uniform sampler2D textureSampler;

void main() {
    fragmentColour = texture(textureSampler, passTexture); 

}