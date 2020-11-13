#pragma once
#include <gl/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Texture2D {

	public:
		Texture2D();
		~Texture2D();
		void loadTexture(const char * image);
		void bind();
		void generate();

		unsigned char* data;
		int width, height,nrChannels;
		unsigned int ID;
		unsigned int WRAP_S, WRAP_T, MIN_FILTER, MAX_FILTER;
		unsigned int INTERNAL_FORMAT, FORMAT;

};