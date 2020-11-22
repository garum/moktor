#pragma once
#include "mkt/Texture.hpp"

namespace mkt {
	class  Sprite
	{
	public:
		Sprite();
		 Sprite(Texture2D texture);
		 Sprite(Texture2D texture,glm::vec2 position);
		~ Sprite();
		glm::mat4 getModelMatrix();
		void rotate(float angle);
		void move(glm::vec2 direction);
		void scale(float size);
		void setTexture2D(Texture2D texture);
		Texture2D getTexture();
	private:
		Texture2D  texture;
		glm::mat4 model;
		glm::vec2 position;
	};

};