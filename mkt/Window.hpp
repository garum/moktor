#pragma once
#define GLEW_STATIC
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
		GLFWwindow* get();
		void setKeycallback(void (*f)(GLFWwindow* window,int key, int scancode, int action, int mods));

	private:
		int height, width;
		GLFWwindow* glWindow = NULL;


		static void framer_buffer_callback(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}


	};

}