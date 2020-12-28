#pragma once

#include "Texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture2D::Texture2D()
{
	this->width = 0;
	this->height = 0;
	this->data = nullptr;
	nrChannels = 0;

	WRAP_S = GL_REPEAT;
	WRAP_T = GL_REPEAT;
	MIN_FILTER = GL_LINEAR;
	MAX_FILTER = GL_LINEAR;
	INTERNAL_FORMAT = GL_RGBA;
	FORMAT = GL_RGBA;

}

Texture2D::~Texture2D()
{

}

void Texture2D::loadTexture(const char* image)
{
	stbi_set_flip_vertically_on_load(true);
	this->data = stbi_load(image, &this->width, &this->height, &this->nrChannels, 0);
}

void Texture2D::bind() {
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture2D::generate(const char* imagePath)
{
	// load texture
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object

	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, WRAP_S);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, WRAP_T);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, MIN_FILTER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, MAX_FILTER);


	//exture2D textureImg = Texture2D();
	this->loadTexture(imagePath);
	if (this->data == nullptr)
	{
		fprintf(stderr, "error: could not load texture");
	}
	glTexImage2D(GL_TEXTURE_2D, 0, INTERNAL_FORMAT, this->width, this->height, 0, FORMAT, GL_UNSIGNED_BYTE, this->data);
	glGenerateMipmap(GL_TEXTURE_2D);
	delete this->data;
	this->data = nullptr;
}