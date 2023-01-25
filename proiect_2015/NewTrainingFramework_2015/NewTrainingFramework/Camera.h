#pragma once
#include "Math.h"
#include "../Utilities/utilities.h"

class Camera
{
private:
	char* type;
	
	Vector3 position, target;
	Vector3 up;
	GLfloat translationSpeed = 40.0f, rotationSpeed = 0.7f;
	GLfloat nearC = 0.02f, farC = 2000.0f ,fov = 0.25f;
	GLfloat deltaTime = 0.05f;
	Vector3 zAxis;
	Vector3 yAxis;
	Vector3 xAxis;
	Matrix viewMatrix, worldMatrix, perspectiveMatrix;
public:
	// constructors 
	Camera();
	Camera(Vector3 position, Vector3 target, Vector3 up);
	Camera(Vector3 position, Vector3 target, Vector3 up, GLfloat translationSpeed, GLfloat rotationSpeed, GLfloat nearC, GLfloat farC, GLfloat fov);

	Vector3 getPosition();
	void setPosition(Vector3 position);

	Vector3 getTarget();
	void setTarget();

	Vector3 getUp();
	void setUp();

	GLfloat getTranslationSpeed();
	void setTranslationSpeed(GLfloat translationSpeed);

	GLfloat getRotationSpeed();
	void setRotationSpeed(GLfloat rotationSpeed);

	GLfloat getNear();
	void setNear(GLfloat nearC);

	GLfloat getFar();
	void setFar(GLfloat farC);

	GLfloat getFov();
	void setFov(GLfloat fov);

	GLfloat getDeltaTime();
	void setDeltaTime(GLfloat deltaTime);

	Matrix getWorldMatrix();

	Matrix getViewMatrix();

	Matrix getPerspectiveMatrix();
	void setPerspectiveMatrix();

	void moveOx(GLint directie);
	void moveOy(GLint directie);
	void moveOz(GLint directie);
	void rotateOx(GLint directie);
	void rotateOy(GLint directie);
	void rotateOz(GLint directie);
	void updateWorldView();
	void updateAxis();
};