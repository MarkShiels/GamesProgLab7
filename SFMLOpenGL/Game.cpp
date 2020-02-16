#include <Game.h>

bool updatable = false;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	mF1 = Matrix3(MyVector3(1.0f, 1.0f, -5.0f),
			      MyVector3(-1.0f, 1.0f, -5.0f),	
			      MyVector3(-1.0f, -1.0f, -5.0f));

	mF2 = Matrix3(MyVector3(1.0f, 1.0f, -5.0f),
				  MyVector3(-1.0f, -1.0f, -5.0f),
				  MyVector3(1.0f, -1.0f, -5.0f));

	mB1 = Matrix3(MyVector3(1.0f, 1.0f, -15.0f),
				  MyVector3(-1.0f, 1.0f, -15.0f),
				  MyVector3(-1.0f, -1.0f, -15.0f));

	mB2 = Matrix3(MyVector3(1.0f, 1.0f, -15.0f),
				  MyVector3(-1.0f, -1.0f, -15.0f),
				  MyVector3(1.0f, -1.0f, -15.0f));

	mT1 = Matrix3(MyVector3(1.0f, 1.0f, -5.0f),
				  MyVector3(-1.0f, 1.0f, -5.0f),
				  MyVector3(-1.0f, 1.0f, -15.0f));

	mT2 = Matrix3(MyVector3(1.0f, 1.0f, -5.0f),
				  MyVector3(-1.0f, 1.0f, -15.0f),
				  MyVector3(1.0f, 1.0f, -15.0f));

	mU1 = Matrix3(MyVector3(-1.0f, -1.0f, -15.0f),
				  MyVector3(-1.0f, -1.0f, -5.0f),
				  MyVector3(1.0f, -1.0f, -5.0f));

	mU2 = Matrix3(MyVector3(1.0f, -1.0f, -15.0f),
				  MyVector3(-1.0f, -1.0f, -15.0f),
				  MyVector3(1.0f, -1.0f, -5.0f));

	mR1 = Matrix3(MyVector3(1.0f, 1.0f, -5.0f),
				  MyVector3(1.0f, 1.0f, -15.0f),
				  MyVector3(1.0f, -1.0f, -15.0f));

	mR2 = Matrix3(MyVector3(1.0f, -1.0f, -15.0f),
				  MyVector3(1.0f, -1.0f, -5.0f),
				  MyVector3(1.0f, 1.0f, -5.0f));

	mL1 = Matrix3(MyVector3(-1.0f, 1.0f, -5.0f),
				  MyVector3(-1.0f, 1.0f, -15.0f),
				  MyVector3(-1.0f, -1.0f, -15.0f));

	mL2 = Matrix3(MyVector3(-1.0f, -1.0f, -15.0f),
				  MyVector3(-1.0f, -1.0f, -5.0f),
				  MyVector3(-1.0f, 1.0f, -5.0f));


	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml

	

	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);

		glVertex3f(mF1.row(1).m_x, mF1.row(1).m_y, mF1.row(1).m_z); 	
		glVertex3f(mF1.row(2).m_x, mF1.row(2).m_y, mF1.row(2).m_z);	
		glVertex3f(mF1.row(3).m_x, mF1.row(3).m_y, mF1.row(3).m_z);	

		glVertex3f(mF2.row(1).m_x, mF2.row(1).m_y, mF2.row(1).m_z); 
		glVertex3f(mF2.row(2).m_x, mF2.row(2).m_y, mF2.row(2).m_z);	
		glVertex3f(mF2.row(3).m_x, mF2.row(3).m_y, mF2.row(3).m_z); 

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);

		glVertex3f(mB1.row(1).m_x, mB1.row(1).m_y, mB1.row(1).m_z);
		glVertex3f(mB1.row(2).m_x, mB1.row(2).m_y, mB1.row(2).m_z);
		glVertex3f(mB1.row(3).m_x, mB1.row(3).m_y, mB1.row(3).m_z);

		glVertex3f(mB2.row(1).m_x, mB2.row(1).m_y, mB2.row(1).m_z);
		glVertex3f(mB2.row(2).m_x, mB2.row(2).m_y, mB2.row(2).m_z);
		glVertex3f(mB2.row(3).m_x, mB2.row(3).m_y, mB2.row(3).m_z);

		//Right Face
		glColor3f(1.0f, 1.0f, 0.0f);

		glVertex3f(mR1.row(1).m_x, mR1.row(1).m_y, mR1.row(1).m_z);
		glVertex3f(mR1.row(2).m_x, mR1.row(2).m_y, mR1.row(2).m_z);
		glVertex3f(mR1.row(3).m_x, mR1.row(3).m_y, mR1.row(3).m_z);

		glVertex3f(mR2.row(1).m_x, mR2.row(1).m_y, mR2.row(1).m_z);
		glVertex3f(mR2.row(2).m_x, mR2.row(2).m_y, mR2.row(2).m_z);
		glVertex3f(mR2.row(3).m_x, mR2.row(3).m_y, mR2.row(3).m_z);

		//Left Face
		glColor3f(1.0f, 1.0f, 0.0f);

		glVertex3f(mL1.row(1).m_x, mL1.row(1).m_y, mL1.row(1).m_z);
		glVertex3f(mL1.row(2).m_x, mL1.row(2).m_y, mL1.row(2).m_z);
		glVertex3f(mL1.row(3).m_x, mL1.row(3).m_y, mL1.row(3).m_z);

		glVertex3f(mL2.row(1).m_x, mL2.row(1).m_y, mL2.row(1).m_z);
		glVertex3f(mL2.row(2).m_x, mL2.row(2).m_y, mL2.row(2).m_z);
		glVertex3f(mL2.row(3).m_x, mL2.row(3).m_y, mL2.row(3).m_z);

		//Top Face
		glColor3f(0.0f, 1.0f, 1.0f);

		glVertex3f(mT1.row(1).m_x, mT1.row(1).m_y, mT1.row(1).m_z);
		glVertex3f(mT1.row(2).m_x, mT1.row(2).m_y, mT1.row(2).m_z);
		glVertex3f(mT1.row(3).m_x, mT1.row(3).m_y, mT1.row(3).m_z);

		glVertex3f(mT2.row(1).m_x, mT2.row(1).m_y, mT2.row(1).m_z);
		glVertex3f(mT2.row(2).m_x, mT2.row(2).m_y, mT2.row(2).m_z);
		glVertex3f(mT2.row(3).m_x, mT2.row(3).m_y, mT2.row(3).m_z);

		//Bottom Face
		glColor3f(0.0f, 1.0f, 1.0f);

		glVertex3f(mU1.row(1).m_x, mU1.row(1).m_y, mU1.row(1).m_z);
		glVertex3f(mU1.row(2).m_x, mU1.row(2).m_y, mU1.row(2).m_z);
		glVertex3f(mU1.row(3).m_x, mU1.row(3).m_y, mU1.row(3).m_z);

		glVertex3f(mU2.row(1).m_x, mU2.row(1).m_y, mU2.row(1).m_z);
		glVertex3f(mU2.row(2).m_x, mU2.row(2).m_y, mU2.row(2).m_z);
		glVertex3f(mU2.row(3).m_x, mU2.row(3).m_y, mU2.row(3).m_z);
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle = 0.05f;
		translateX = 0.0001f;
		translateY = 0.0001f;
		if (rotationAngle >1.0f)
		{
			rotationAngle -= 1.0f;
		}

		updateMatrix();
	}
	
	

	//cout << "Update up" << endl;
}


void Game::updateMatrix()
{
	//glDeleteLists(index, 1);

	mF1 = mF1 * mF1.rotationY(rotationAngle);
	mF2 = mF2 * mF2.rotationY(rotationAngle);
	mB1 = mB1 * mB1.rotationY(rotationAngle);
	mB2 = mB2 * mB2.rotationY(rotationAngle);
	mT1 = mT1 * mT1.rotationY(rotationAngle);
	mT2 = mT2 * mT2.rotationY(rotationAngle);
	mU1 = mU1 * mU1.rotationY(rotationAngle);
	mU2 = mU2 * mU2.rotationY(rotationAngle);
	mR1 = mR1 * mR1.rotationY(rotationAngle);
	mR2 = mR2 * mR2.rotationY(rotationAngle);
	mL1 = mL1 * mL1.rotationY(rotationAngle);
	mL2 = mL2 * mL2.rotationY(rotationAngle);

	/*mF1 = mF1 * mF1.translate(translateX, translateY);
	mF2 = mF2 * mF2.translate(translateX, translateY);
	mB1 = mB1 * mB1.translate(translateX, translateY);
	mB2 = mB2 * mB2.translate(translateX, translateY);
	mT1 = mT1 * mT1.translate(translateX, translateY);
	mT2 = mT2 * mT2.translate(translateX, translateY);
	mU1 = mU1 * mU1.translate(translateX, translateY);
	mU2 = mU2 * mU2.translate(translateX, translateY);
	mR1 = mR1 * mR1.translate(translateX, translateY);
	mR2 = mR2 * mR2.translate(translateX, translateY);
	mL1 = mL1 * mL1.translate(translateX, translateY);
	mL2 = mL2 * mL2.translate(translateX, translateY);*/

	/*float scaleAmount = -101.0f;

	mF1 = mF1 * mF1.scale3D(scaleAmount);
	mF2 = mF2 * mF2.scale3D(scaleAmount);
	mB1 = mB1 * mB1.scale3D(scaleAmount);
	mB2 = mB2 * mB2.scale3D(scaleAmount);
	mT1 = mT1 * mT1.scale3D(scaleAmount);
	mT2 = mT2 * mT2.scale3D(scaleAmount);
	mU1 = mU1 * mU1.scale3D(scaleAmount);
	mU2 = mU2 * mU2.scale3D(scaleAmount);
	mR1 = mR1 * mR1.scale3D(scaleAmount);
	mR2 = mR2 * mR2.scale3D(scaleAmount);
	mL1 = mL1 * mL1.scale3D(scaleAmount);
	mL2 = mL2 * mL2.scale3D(scaleAmount);*/

	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);

		glVertex3f(mF1.row(1).m_x, mF1.row(1).m_y, mF1.row(1).m_z);
		glVertex3f(mF1.row(2).m_x, mF1.row(2).m_y, mF1.row(2).m_z);
		glVertex3f(mF1.row(3).m_x, mF1.row(3).m_y, mF1.row(3).m_z);

		glVertex3f(mF2.row(1).m_x, mF2.row(1).m_y, mF2.row(1).m_z);
		glVertex3f(mF2.row(2).m_x, mF2.row(2).m_y, mF2.row(2).m_z);
		glVertex3f(mF2.row(3).m_x, mF2.row(3).m_y, mF2.row(3).m_z);

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);

		glVertex3f(mB1.row(1).m_x, mB1.row(1).m_y, mB1.row(1).m_z);
		glVertex3f(mB1.row(2).m_x, mB1.row(2).m_y, mB1.row(2).m_z);
		glVertex3f(mB1.row(3).m_x, mB1.row(3).m_y, mB1.row(3).m_z);

		glVertex3f(mB2.row(1).m_x, mB2.row(1).m_y, mB2.row(1).m_z);
		glVertex3f(mB2.row(2).m_x, mB2.row(2).m_y, mB2.row(2).m_z);
		glVertex3f(mB2.row(3).m_x, mB2.row(3).m_y, mB2.row(3).m_z);

		//Right Face
		glColor3f(1.0f, 1.0f, 0.0f);

		glVertex3f(mR1.row(1).m_x, mR1.row(1).m_y, mR1.row(1).m_z);
		glVertex3f(mR1.row(2).m_x, mR1.row(2).m_y, mR1.row(2).m_z);
		glVertex3f(mR1.row(3).m_x, mR1.row(3).m_y, mR1.row(3).m_z);

		glVertex3f(mR2.row(1).m_x, mR2.row(1).m_y, mR2.row(1).m_z);
		glVertex3f(mR2.row(2).m_x, mR2.row(2).m_y, mR2.row(2).m_z);
		glVertex3f(mR2.row(3).m_x, mR2.row(3).m_y, mR2.row(3).m_z);

		//Left Face
		glColor3f(1.0f, 1.0f, 0.0f);

		glVertex3f(mL1.row(1).m_x, mL1.row(1).m_y, mL1.row(1).m_z);
		glVertex3f(mL1.row(2).m_x, mL1.row(2).m_y, mL1.row(2).m_z);
		glVertex3f(mL1.row(3).m_x, mL1.row(3).m_y, mL1.row(3).m_z);

		glVertex3f(mL2.row(1).m_x, mL2.row(1).m_y, mL2.row(1).m_z);
		glVertex3f(mL2.row(2).m_x, mL2.row(2).m_y, mL2.row(2).m_z);
		glVertex3f(mL2.row(3).m_x, mL2.row(3).m_y, mL2.row(3).m_z);

		//Top Face
		glColor3f(0.0f, 1.0f, 1.0f);

		glVertex3f(mT1.row(1).m_x, mT1.row(1).m_y, mT1.row(1).m_z);
		glVertex3f(mT1.row(2).m_x, mT1.row(2).m_y, mT1.row(2).m_z);
		glVertex3f(mT1.row(3).m_x, mT1.row(3).m_y, mT1.row(3).m_z);

		glVertex3f(mT2.row(1).m_x, mT2.row(1).m_y, mT2.row(1).m_z);
		glVertex3f(mT2.row(2).m_x, mT2.row(2).m_y, mT2.row(2).m_z);
		glVertex3f(mT2.row(3).m_x, mT2.row(3).m_y, mT2.row(3).m_z);

		//Bottom Face
		glColor3f(0.0f, 1.0f, 1.0f);

		glVertex3f(mU1.row(1).m_x, mU1.row(1).m_y, mU1.row(1).m_z);
		glVertex3f(mU1.row(2).m_x, mU1.row(2).m_y, mU1.row(2).m_z);
		glVertex3f(mU1.row(3).m_x, mU1.row(3).m_y, mU1.row(3).m_z);

		glVertex3f(mU2.row(1).m_x, mU2.row(1).m_y, mU2.row(1).m_z);
		glVertex3f(mU2.row(2).m_x, mU2.row(2).m_y, mU2.row(2).m_z);
		glVertex3f(mU2.row(3).m_x, mU2.row(3).m_y, mU2.row(3).m_z);
	}
	glEnd();
	glEndList();
	
}

void Game::draw()
{
	//cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//cout << "Drawing Cube " << endl;
	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis

	glCallList(1);

	window.display();

}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}

