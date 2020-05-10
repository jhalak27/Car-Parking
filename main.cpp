#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "car.cpp"
#include "house.cpp"
#include "tree.cpp"
#include "texture.cpp"
using namespace std;

static float angle = 0.0, ratio;
static float x = 0.0f, y = 3.00f, z = 180.0f;
static float lx = 0.0f, ly = 0.03f, lz = -1.0f;
float theta = 0.01, fxincr = 0.1, fzincr = 0, temp, theta1, fx = -10, fz = 100;
static GLint car_display_list, house_display_list, tree_display_list, tree1_display_list;
int xxxx = 0, yyyy = 0, housevisible = 1, movecarvar = 0, treevisible = 1;
int instruct = 1, movei = 0, showi = 1, initial = 1;

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

void PrintString(string s, int x, int y, int r, int g, int b)
{
	int next_line = 0;
	glRasterPos2i(x, y);
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		char c = s[i];
		if (c == '\n')
		{
			next_line += 20;
			glRasterPos2i(x, y - next_line);
		}
		else
		{
			glColor3d(r, g, b);
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
		}
	}
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

GLuint createDL3() //******************
{
	GLuint treeDL;
	treeDL = glGenLists(1);		   // Create the id for the list
	glNewList(treeDL, GL_COMPILE); // start list
	makeTree(4, 0.5);			   // call the function that contains the rendering commands
	glEndList();				   // endList
	return (treeDL);
}

GLuint createDL4() //******************
{
	GLuint treeDL;
	treeDL = glGenLists(1);		   // Create the id for the list
	glNewList(treeDL, GL_COMPILE); // start list
	makeTree1(4, 0.5);			   // call the function that contains the rendering commands
	glEndList();				   // endList
	return (treeDL);
}

void initScene()
{
	glEnable(GL_DEPTH_TEST);
	car_display_list = createDL();
	house_display_list = createDL2();
	tree_display_list = createDL3();
	tree1_display_list = createDL4();
}

void renderStrings()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, 1080, 0.0, 700);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	PrintString("IITI CG project", 10, 660, 1.0, 0.0, 1.0);
	PrintString("Students:\nAshwini Jha\nJhalak Gupta", 10, 640, 1.0, 0.0, 1.0);

	if (instruct == 1 && showi == 1)
		PrintString("Instructions \nm - to move car \nUp key - to move camera forward\nDown key - to move camera backward\nLeft key - to rotate camera to the left\nRight key - to rotate camera to the right\nt - top view\na - to move left\nd - to move right\nw - to zoom in\ns - to zoom out\ni - to show or hide instructions\nq - quit", 750, 660, 0.53, 0.16, 0.32);

	if (movei == 1 && showi == 1)
		PrintString("If you wish to move the car, \nUp key - to move car forwards\nDown key - to move car backwards\nLeft key - to rotate car to the left\nRight key - to rotate car to the right \nm - to stop car movement\ni - to show or hide instructions", 750, 660, 1.0, 0.5, 0.5);
	if (showi == 0)
		PrintString("Press 'i' to show instructions", 750, 690, 1.0, 1.0, 0.5);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void renderScene(void)
{
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(.7, 0.85, 1.0, 1.0);
	glPushMatrix();
	glColor4f(0.8, 0.8, 0.8, 1.0);
	drawClouds();
	drawClouds1();
	drawSky();
	glPopMatrix();
	glPushMatrix();
	glColor4f(0.2, 0.35, 0.5, 1.0);
	drawFloor();
	glPopMatrix();
	glPushMatrix();
	glColor4f(0.3, 0.3, 0.3, 1.0);
	drawRoad();
	glPopMatrix();
	glPushMatrix();
	glColor4f(0.2, 0.35, 0.5, 0.5);

	glPopMatrix();
	renderStrings();
	if (housevisible)
	{
		glPushMatrix();
		glScalef(2.0, 2.0, 2.0);
		glTranslatef(-8.0, 1.0, 70.0);
		glRotatef(90, 0, 1, 0);
		glCallList(house_display_list);

		glPopMatrix();
	}
	if (treevisible)
	{
		glPushMatrix();
		glTranslatef(-10.0, 0.0, 80.0);
		glRotatef(170, 0, 1, 0);
		glCallList(tree_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-11.0, 0.0, 100.0);
		glRotatef(180, 0, 1, 0);
		glCallList(tree_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-14.0, 0.0, 90.0);
		glRotatef(190, 0, 1, 0);
		glCallList(tree1_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-12.0, 0.0, -50.0);
		glRotatef(180, 0, 1, 0);
		glCallList(tree1_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-14.0, 0.0, -60.0);
		glRotatef(195, 0, 1, 0);
		glCallList(tree_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-12.0, 0.0, -20.0);
		glRotatef(180, 0, 1, 0);
		glCallList(tree1_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-14.0, 0.0, -10.0);
		glRotatef(175, 0, 1, 0);
		glCallList(tree_display_list);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(11.0, 0.0, -10.0);
		glRotatef(200, 0, 1, 0);
		glCallList(tree1_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(15.0, 0.0, 0.0);
		glRotatef(190, 0, 1, 0);
		glCallList(tree_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(12.0, 0.0, 10.0);
		glRotatef(180, 0, 1, 0);
		glCallList(tree1_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(14.0, 0.0, 20.0);
		glRotatef(160, 0, 1, 0);
		glCallList(tree_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(14.0, 0.0, 80.0);
		glRotatef(160, 0, 1, 0);
		glCallList(tree_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(11.0, 0.0, 100.0);
		glRotatef(180, 0, 1, 0);
		glCallList(tree_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(15.0, 0.0, 120.0);
		glRotatef(190, 0, 1, 0);
		glCallList(tree_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(12.0, 0.0, 130.0);
		glRotatef(170, 0, 1, 0);
		glCallList(tree1_display_list);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(11.0, 0.0, 155.0);
		glRotatef(175, 0, 1, 0);
		glCallList(tree_display_list);
		glPopMatrix();
	}

	for (i = -1; i <= 1; i = i + 2)
	{
		for (j = -1; j <= 1; j++)
		{
			glPushMatrix();
			glScalef(1.5, 1.5, 1.5);
			glTranslatef((i)*3.0, 0, (3 * j) * 10.0);
			if (i == -1)
			{
				glRotatef(90, 0, 1, 0);
			}
			else
			{
				glRotatef(-90, 0, 1, 0);
			}
			glColor3ub(a[i + 1], b[j + 1], c[i + 1]);
			glCallList(car_display_list);
			glPopMatrix();
		}
	}
	if (fxincr != 0)
	{
		theta1 = (atan(fzincr / fxincr) * 180) / 3.141;
	}

	else if (fzincr > 0)
	{
		theta1 = -90.0;
	}

	else
	{
		theta1 = 90.0;
	}

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
	glScalef(1.5, 1.5, 1.5);
	glTranslatef(fx, 0, fz);
	glRotatef(theta1, 0, 1, 0);
	glColor3f(0.8, 0.7, 0.1);
	glCallList(car_display_list);
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
			movei = 1;
			instruct = 0;
			showi = 1;
			glutSpecialFunc(moveCar);
			movecarvar = 1;
		}
		else
		{
			movei = 0;
			instruct = 1;
			showi = 1;
			glutSpecialFunc(inputKey);
			movecarvar = 0;
		}
	}
	if (key == 'q')
		exit(0);
	if (key == 'i')
	{
		if (showi == 1)
			showi = 0;
		else
		{
			showi = 1;
		}
		glutPostRedisplay();
	}
	if (key == 't')
	{
		glLoadIdentity();
		gluLookAt(0, 190, 30, 0, 0, 0, 0.0, 1.0, .0);
	}
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
	textures();
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

	glutMainLoop();
	return (0);
}