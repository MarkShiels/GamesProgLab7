#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Matrix3.h"
#include "Vector3.h""


using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;

	Matrix3 mF1;
	Matrix3 mF2;
	Matrix3 mB1;
	Matrix3 mB2;
	Matrix3 mT1;
	Matrix3 mT2;
	Matrix3 mU1;
	Matrix3 mU2;
	Matrix3 mR1;
	Matrix3 mR2;
	Matrix3 mL1;
	Matrix3 mL2;

	void updateMatrix();

	float translateX;
	float translateY;
};