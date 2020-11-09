#pragma once
#include "Shader.hpp"


namespace mkt {
	class Renderer {


		public:
			Renderer();
			~Renderer();
			void init();
			void renderScene();


		private:
			unsigned int VBO;
			unsigned int VAO;
	
	};
}