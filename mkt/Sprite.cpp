#include "Sprite.hpp"


namespace mkt{
	Sprite::Sprite()
	{
		this->model = glm::mat4(1.0f);
		this->position = glm::vec2(100.0f, 200.0f);
		this->model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));
		model = glm::scale(model, glm::vec3(100.0f, 100.0f, 1.0f));
	}

	Sprite::Sprite(Texture2D texture)
	{
		/*this->texture = texture;
		this->model = glm::mat4(1.0f);
		this->position = glm::vec2(200.0f, 200.0f);
		this->model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));
		model = glm::scale(model, glm::vec3(400.0f,400.0f, 1.0f));*/
	}

	Sprite::Sprite(Texture2D texture,glm::vec2 position)
	{

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
		model= glm::translate(model, glm::vec3(direction.x, direction.y, 0.0f));
	}
	void Sprite::rotate(float angle)
	{
		////model = glm::translate(model, glm::vec3(position.x, position.y, 0.0f));
		//model = glm::translate(model, glm::vec3(0.5f, 0.5f, 0.0f));
		//this->model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0, 1.0f));
		//model = glm::translate(model, glm::vec3(-0.5f, -0.5f, 0.0f));
		////model = glm::translate(model, glm::vec3(-position.x, -position.y, 0.0f));

	}
	glm::mat4 Sprite::getModelMatrix()
	{
		return this->model;
	}
	Texture2D Sprite::getTexture()
	{
		return this->texture;
	}
}