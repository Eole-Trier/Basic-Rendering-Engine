#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "LowRenderer/Camera.h"
#include "Core/Debug/Log.h"
#include "Core/Maths/Matrix4x4.h"
#include "Ressources/Shader.h"
#include "Ressources/ResourceManager.h"
#include "Core/Object.h"

class Application
{
public:

	static Object* world;
	Application();
	~Application();

	static void ResizeCallback(GLFWwindow* window, int width, int height);
	static void MouseCallback(GLFWwindow* window, double xposIn, double yposIn);
	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	void ProcessInput(GLFWwindow* window, float deltaTime);

	void Update();

	ResourceManager resourceManager;

	static Camera camera;
	static float lastX, lastY;
	static float yaw, pitch;
	static bool firstMouse;
	static Vector3 cameraFront;

	static float deltaTime;
	static float lastFrame;

	static unsigned int cubeVBO, cubeVAO;
	static unsigned int lightCubeVAO;

	static Vector3 cubePositions[];
	static Vector3 pointLightPositions[];
	
	static Vector3 lightPos;

	static float Width, Height;
	static GLFWwindow* window;

private:
};