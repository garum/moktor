#pragma once
#include "Renderer.hpp"
#include "stdio.h"


unsigned int texture;


namespace mkt{
	Shader myShader;

	Renderer::Renderer()
	{
	
	}

	void Renderer::init()
	{
		//load shader

		float vertices[9] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f };


		myShader.loadShader("shaders/shaderStart.vert", "shaders/shaderStart.vert");
		myShader.useShaderProgram();

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}

	void Renderer::initRenderSprite()
	{
		myShader.loadShader("D:\\Project\\game_engine\\moktor\\moktor\\mkt\\shaders\\shaderStart.vert", 
			"D:\\Project\\game_engine\\moktor\\moktor\\mkt\\shaders\\shaderStart.frag");
		myShader.useShaderProgram();

		float vertices[] = {
			// pos      // tex
			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,

			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f
		};

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindVertexArray(VAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);



	}

	void Renderer::renderScene()
	{
		myShader.useShaderProgram();
		glViewport(0, 0, 640, 480);
		//glm::mat4 view = myCamera.getViewMatrix();
		GLint  viewLocation = glGetUniformLocation(myShader.shaderProgram, "view");
		//glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));


		//std::cout << glm::to_string(view);
		//myCamera.move(mkt::MOVE_LEFT, 0.1f);
		glm::mat4 model = glm::mat4(1.0f);

		GLint modelLocation = glGetUniformLocation(myShader.shaderProgram, "model");
		//glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(model));

		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(VAO);

	}

	void Renderer::renderSprite(Sprite sprite,Camera camera)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		Texture2D texture = sprite.getTexture();

		glBindTexture(GL_TEXTURE_2D, texture.ID);
		myShader.useShaderProgram();
		
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.5f , 0.5f , 0.0f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::translate(model, glm::vec3(-0.5f , -0.5f , 0.0f));

		GLint modelLoc=glGetUniformLocation(myShader.shaderProgram, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE ,glm::value_ptr(sprite.getModelMatrix()));

		GLint viewLoc = glGetUniformLocation(myShader.shaderProgram, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.getViewMatrix()));
		//glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
		glm::mat4 proj = glm::ortho(0.0f,800.0f, 0.0f, 600.0f, -10.0f, 10.0f);

		GLint projLoc = glGetUniformLocation(myShader.shaderProgram, "projection");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}

	Renderer::~Renderer()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		
	}
}