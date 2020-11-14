#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.hpp"
#include "Camera.hpp"
#include "Texture.hpp"



namespace mkt {
	

	class Renderer {


		public:
			Renderer();
			~Renderer();
			void init();
			void initRenderSprite();
			void renderScene();
			void renderSprite(Texture2D texture,Camera camera);


		private:
			unsigned int VBO;
			unsigned int VAO;
	
	};
}