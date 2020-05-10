#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// GLuint makeaTree;
// float x, y, z;

void makeCylinder(float height, float base)
{
    GLUquadric *obj = gluNewQuadric();
    //gluQuadricDrawStyle(obj, GLU_LINE);
    glColor3f(0.139, 0.069, 0.019);
    glPushMatrix();
    glRotatef(-90, 1.0, 0.0, 0.0);
    gluCylinder(obj, base, base - (0.2 * base), height, 20, 20);
    glPopMatrix();
    glutSwapBuffers();
}

void makeTree(float height, float base)
{

    float angle;
    makeCylinder(height, base);
    glTranslatef(0.0, height, 0.0);
    height -= height * .2;
    base -= base * 0.3;
    for (int a = 0; a < 3; a++)
    {
        angle = rand() % 50 + 20;
        if (angle > 48)
            angle = -(rand() % 50 + 20);
        if (height > 1)
        {
            glPushMatrix();
            glRotatef(angle, 1, 0.0, 1);
            makeTree(height, base);
            glPopMatrix();
        }
        else
        {
            glColor3f(0.25, 0.41, 0.15);
            glutSolidSphere(.2, 10, 10);
        }
        //add like fruits...
    }
}
