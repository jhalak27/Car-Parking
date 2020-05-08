#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "car.cpp"
using namespace std;

static float angle = 0.0, ratio;
static float x = 0.0f, y = 3.00f, z = 100.0f;
static float lx = 0.10f, ly = 0.10f, lz = -1.0f;
float theta = 0.01, fxincr = 0.1, fzincr = 0, temp, theta1, fx = -10, fz = 80;
static GLint carr_display_list;
int xxxx = 0, yyyy = 0, movecarvar = 0;

// For colour of cars
int a[3] = {55, 97, 44};
int b[3] = {102, 194, 127};
int c[3] = {159, 243, 133};

void changeSize(int w, int h)
{
	if (h == 0)
		h = 1;
	ratio = 1.0f * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

GLuint createDL()
{
	GLuint carDL;
	carDL = glGenLists(1);		  // Create the id for the list
	glNewList(carDL, GL_COMPILE); // start list
	drawcar();					  // call the function that contains the rendering commands
	glEndList();				  // endList
	return (carDL);
}

GLuint createDL2() //******************
{
	GLuint houseDL;
	houseDL = glGenLists(1);		// Create the id for the list
	glNewList(houseDL, GL_COMPILE); // start list
	drawhouse();					// call the function that contains the rendering commands
	glEndList();					// endList
	return (houseDL);
}

void initScene()
{
	glEnable(GL_DEPTH_TEST);
	carr_display_list = createDL();
}

void renderScene(void)
{
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(.7, 0.85, 1.0, 1.0);
	glColor3f(0.25f, 0.25f, 0.25f); // Draw ground
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			glPushMatrix();
			glTranslatef((2 * i) * 10.0, 0, (2 * j) * 10.0);
			glColor3ub(a[i + 1], b[j + 1], c[i + 1]);
			glCallList(carr_display_list);
			glPopMatrix();
		}
	}
	if (fxincr != 0)
		theta1 = (atan(fzincr / fxincr) * 180) / 3.141;
	else if (fzincr > 0)
		theta1 = -90.0;
	else
		theta1 = 90.0;
	if (fxincr > 0 && fzincr < 0)
	{
		theta1 = -theta1;
	}
	else if (fxincr < 0 && fzincr < 0)
	{
		theta1 = 180 - theta1;
	}
	else if (fxincr < 0 && fzincr > 0)
	{
		theta1 = -180 - theta1;
	}
	else if (fxincr > 0 && fzincr > 0)
	{
		theta1 = -theta1;
	}
	glPushMatrix();
	glTranslatef(fx, 0, fz);
	glRotatef(theta1, 0, 1, 0);
	glColor3f(0.8, 0.8, 0);
	glCallList(carr_display_list);
	glPopMatrix();
	glutSwapBuffers();
}
void orientMe(float ang)
{
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}
void moveMeFlat(int i)
{
	if (xxxx == 1)
		y = y + i * (lz)*0.1;

	if (yyyy == 1)
	{
		x = x + i * (lz)*.1;
	}
	else
	{
		z = z + i * (lz)*0.5;
		x = x + i * (lx)*0.5;
	}
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void inputKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		angle -= 0.05f;
		orientMe(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.05f;
		orientMe(angle);
		break;
	case GLUT_KEY_UP:
		moveMeFlat(2);
		xxxx = 0, yyyy = 0;
		break;
	case GLUT_KEY_DOWN:
		moveMeFlat(-2);
		xxxx = 0, yyyy = 0;
		break;
	}
}
void moveCar(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		temp = fxincr;
		fxincr = fxincr * cos(theta) + fzincr * sin(theta);
		fzincr = -temp * sin(theta) + fzincr * cos(theta);
		fx += fxincr;
		fz += fzincr;
		break;
	case GLUT_KEY_RIGHT:
		temp = fxincr;
		fxincr = fxincr * cos(-theta) + fzincr * sin(-theta);
		fzincr = -temp * sin(-theta) + fzincr * cos(-theta);
		fx += fxincr;
		fz += fzincr;
		break;
	case GLUT_KEY_UP:
		fx += fxincr;
		fz += fzincr;
		break;
	case GLUT_KEY_DOWN:
		fx -= fxincr;
		fz -= fzincr;
		break;
	}
	glutPostRedisplay();
}

void processNormalKeys(unsigned char key, int x, int y)
{

	if (key == 'm')
	{
		if (movecarvar == 0)
		{
			glutSpecialFunc(moveCar);
			movecarvar = 1;
		}
		else
		{
			glutSpecialFunc(inputKey);
			movecarvar = 0;
		}
	}
	// glLoadIdentity();
	if (key == 'q')
		exit(0);
	if (key == 't')
		gluLookAt(0, 190, 40, 0, 0, -10, 0.0, 1.0, .0);
	if (key == 'a')
		moveMeFlat(4);
	xxxx = 1, yyyy = 0;
	if (key == 's')
		moveMeFlat(-4);
	xxxx = 1, yyyy = 0;
	if (key == 'w')
		moveMeFlat(4);
	yyyy = 1;
	xxxx = 0;
	if (key == 'd')
		moveMeFlat(-4);
	yyyy = 1;
	xxxx = 0;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("Car");
	initScene();
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(inputKey);
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

	glutMainLoop();
	return (0);
}