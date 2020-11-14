#include "Window.hpp"

namespace mkt {
	Window::Window(int height, int width)
	{
		this->height = height;
		this->width = width;

		if (!glfwInit()) {
			fprintf(stderr, "ERROR: could not start GLFW3\n");
		}

		glWindow = glfwCreateWindow(height, width, "Hello Window", NULL, NULL);
		if (!glWindow) {
			fprintf(stderr, "ERROR: could not open window with GLFW3\n");
			glfwTerminate();

		}

		glfwMakeContextCurrent(glWindow);

		// start GLEW extension handler
		glewExperimental = GL_TRUE;
		glewInit();

		glfwSetFramebufferSizeCallback(this->glWindow, Window::framer_buffer_callback);

		// get version info
		const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
		const GLubyte* version = glGetString(GL_VERSION); // version as a string
		printf("Renderer: %s\n", renderer);
		printf("OpenGL version supported %s\n", version);


	}

	Window::~Window()
	{
		glfwDestroyWindow(this->glWindow);
		glfwTerminate();
	}

	void Window::terminate()
	{
		glfwTerminate();
	}

	void Window::setKeycallback(void (*f)(GLFWwindow* window,int key, int scancode, int action, int mods))
	{
		glfwSetKeyCallback(this->glWindow, f);
		
	}

	void Window::run(void (*gameloop)())
	{
		while (!glfwWindowShouldClose(this->glWindow))
		{
			glfwGetFramebufferSize(this->glWindow, &width, &height);
			

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			(*gameloop)();

			glfwPollEvents();
			glfwSwapBuffers(this->glWindow);
		}
	}

	GLFWwindow* Window::get()
	{
		return this->glWindow;
	}
	

}