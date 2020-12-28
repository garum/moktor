#include "Sprite.hpp"
#include <iostream>

namespace mkt{
	Sprite::Sprite()
	{
		this->position = glm::vec2(100.0f, 200.0f);
		this->size = glm::vec2(100.0f, 100.0f);

	}

	Sprite::Sprite(Texture2D texture)
	{
		Sprite();
		this->texture = texture;
		
	}

	Sprite::Sprite(Texture2D texture,glm::vec2 position,glm::vec2 size)
	{
		this->texture = texture;
		this->texture = texture;
		this->position = position;
		this->size = size;
	}

	Sprite::~Sprite()
	{

	}
	void Sprite::setTexture2D(Texture2D texture)
	{
		this->texture = texture;
	}
	void Sprite::move(glm::vec2 direction)
	{
		this->position += direction;
	
	}
	void Sprite::rotate(float angle)
	{
		this->angle = angle;

		

	}
	void Sprite::scale(float scale)
	{
		this->size *= scale;

	}

	glm::mat4 Sprite::getModelMatrix()
	{
		glm::mat4 model = glm::mat4(1.0f);

		std ::cout <<position.x  <<" " << position.y << "\n";
		
		model = glm::translate(model, glm::vec3(this->position, 0.0f));
	

	
	
		model = glm::translate(model, glm::vec3(size.x * 0.5f, size.y * 0.5f, 0.0f));
		model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0, 1.0f));
		model = glm::translate(model, glm::vec3(-size.x * 0.5f, -size.y * 0.5f, 0.0f));
		

		model = glm::scale(model, glm::vec3(this->size, 1.0f));
		return model;
	}
	Texture2D Sprite::getTexture()
	{
		return this->texture;
	}
}