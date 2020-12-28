#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.hpp"
#include "Camera.hpp"
#include "Texture.hpp"
#include "Sprite.hpp"



namespace mkt {
	

	class Renderer {


		public:
			Renderer();
			~Renderer();
			void init();
			void initRenderSprite();
			void renderScene();
			void renderSprite(Sprite sprite,Camera camera);


		private:
			unsigned int VBO;
			unsigned int VAO;
	
	};
}