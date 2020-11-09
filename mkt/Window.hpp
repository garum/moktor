#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>



namespace mkt {
	class Window
	{
	public:
		Window(int height, int width);
		~Window();

		void terminate();
		void run(void (*gameloop)());

	private:
		int height, width;
		GLFWwindow* glWindow = NULL;


	};

}