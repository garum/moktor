#include "Camera.hpp"

namespace mkt {

    //Camera constructor
    Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 cameraUp) {
        //TODO
        this->cameraPosition = cameraPosition;
        this->cameraTarget = cameraTarget;
        glm::vec3 cameraDirection = glm::normalize(cameraPosition - cameraTarget);
        this->cameraFrontDirection = cameraDirection;
        this->cameraRightDirection = glm::normalize(glm::cross(cameraUp, cameraDirection));
        this->cameraUpDirection =  glm::cross(cameraDirection, cameraRightDirection);
       
    }

    //return the view matrix, using the glm::lookAt() function
    glm::mat4 Camera::getViewMatrix() {
        //TODO
        /*return glm::lookAt(cameraPosition, cameraTarget, this->cameraUpDirection);*/
        glm::mat4 view=glm::mat4(1.0);
        view = glm::translate(view, cameraPosition);
        return view;

    }

    //update the camera internal parameters following a camera move event
    void Camera::move(MOVE_DIRECTION direction, float speed) {
        if (direction == MOVE_FORWARD)
            cameraPosition -= speed * cameraFrontDirection;
        if (direction == MOVE_BACKWARD)
            cameraPosition += speed * cameraFrontDirection;
        if (direction == MOVE_LEFT)
            cameraPosition += speed * cameraRightDirection;
        if (direction == MOVE_RIGHT)
            cameraPosition -= speed * cameraRightDirection;
        if(direction == MOVE_UP)
            cameraPosition += speed * cameraUpDirection;
        if (direction == MOVE_DOWN)
            cameraPosition -= speed * cameraUpDirection;

        //TODO
    }

    //update the camera internal parameters following a camera rotate event
    //yaw - camera rotation around the y axis
    //pitch - camera rotation around the x axis
    void Camera::rotate(float pitch, float yaw) {
        //TODO
    }

    glm::mat4 Camera::getProjectionMatrix() {
        glm::mat4 proj = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -10.0f, 10.0f);

        return proj;
    }
}