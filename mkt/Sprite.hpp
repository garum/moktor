#pragma once
#include "Texture.hpp"

namespace mkt {
	class  Sprite
	{
	public:
		Sprite();
		 Sprite(Texture2D texture);
		 Sprite(Texture2D texture,glm::vec2 position,glm::vec2 size);
		~ Sprite();
		glm::mat4 getModelMatrix();
		void rotate(float angle);
		void move(glm::vec2 direction);
		void scale(float scale);
		void setTexture2D(Texture2D texture);
		Texture2D getTexture();
	private:
		Texture2D  texture;
		glm::vec2 position;
		glm::vec2 size;
		glm::vec4 color;
		float angle=0;
	};

};