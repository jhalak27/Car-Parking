#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//house

void drawhouse()
{
    glColor3ub(122, 87, 46);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-2.6, -.84, 2.5);   //m
    glVertex3f(-2.6, 0.84, 2.5);   //n
    glVertex3f(-3.04, 0.84, 2.8);  //o
    glVertex3f(0, 1.95, 2.8);      //p
    glVertex3f(3.04, 0.84, 2.8);   //w
    glVertex3f(2.6, 0.84, 2.5);    //q
    glVertex3f(2.6, -0.84, 2.5);   //r
    glVertex3f(1.59, -0.84, 2.5);  //s
    glVertex3f(1.59, 0.16, 2.5);   //t
    glVertex3f(-1.59, 0.16, 2.5);  //u
    glVertex3f(-1.59, -0.84, 2.5); //v
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(-2.6, -.84, -2.5);  //m'
    glVertex3f(-2.6, 0.84, -2.5);  //n'
    glVertex3f(-3.04, 0.84, -2.8); //o'
    glVertex3f(0, 1.95, -2.8);     //p'
    glVertex3f(3.04, 0.84, -2.8);  //w'
    glVertex3f(2.6, 0.84, -2.5);   //q'

    glVertex3f(2.6, -0.84, -2.5);   //r'
    glVertex3f(1.59, -0.84, -2.5);  //s'
    glVertex3f(1.59, 0.16, -2.5);   //t'
    glVertex3f(-1.59, 0.16, -2.5);  //u'
    glVertex3f(-1.59, -0.84, -2.5); //v'
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(1.59, -0.84, 2.5);  //s
    glVertex3f(-1.59, -0.84, 2.5); //v
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-2.6, -.84, 2.5);    //m
    glVertex3f(-2.6, -.84, -2.5);   //m'
    glVertex3f(-2.6, 0.84, 2.5);    //n
    glVertex3f(-2.6, 0.84, -2.5);   //n'
    glVertex3f(-3.04, 0.84, 2.8);   //o
    glVertex3f(-3.04, 0.84, -2.8);  //o'
    glVertex3f(0, 1.95, 2.8);       //p
    glVertex3f(0, 1.95, -2.8);      //p'
    glVertex3f(3.04, 0.84, 2.8);    //w
    glVertex3f(3.04, 0.84, -2.8);   //w'
    glVertex3f(2.6, 0.84, 2.5);     //q
    glVertex3f(2.6, 0.84, -2.5);    //q'
    glVertex3f(2.6, -0.84, 2.5);    //r
    glVertex3f(2.6, -0.84, -2.5);   //r'
    glVertex3f(1.59, -0.84, 2.5);   //s
    glVertex3f(1.59, -0.84, -2.5);  //s'
    glVertex3f(-1.59, -0.84, 2.5);  //v
    glVertex3f(-1.59, -0.84, -2.5); //v'
    glEnd();
    glColor3ub(178, 130, 76); //*************
    glBegin(GL_QUADS);
    glVertex3f(-2.6, -.84, 2.5);    //m
    glVertex3f(-2.6, 0.16, 2.5);    //uu
    glVertex3f(-1.59, 0.16, 2.5);   //u
    glVertex3f(-1.59, -0.84, 2.5);  //v
    glVertex3f(-2.6, 0.16, 2.5);    //uu
    glVertex3f(-2.6, 0.84, 2.5);    //n
    glVertex3f(2.6, 0.84, 2.5);     //q
    glVertex3f(2.6, 0.16, 2.5);     //tt
    glVertex3f(1.59, -0.84, 2.5);   //s
    glVertex3f(1.59, 0.16, 2.5);    //t
    glVertex3f(2.6, 0.16, 2.5);     //tt
    glVertex3f(2.6, -0.84, 2.5);    //r
    glVertex3f(-2.6, -.84, -2.5);   //m'
    glVertex3f(-2.6, 0.16, -2.5);   //uu'
    glVertex3f(-1.59, 0.16, -2.5);  //u'
    glVertex3f(-1.59, -0.84, -2.5); //v'
    glVertex3f(-2.6, 0.16, -2.5);   //uu'
    glVertex3f(-2.6, 0.84, -2.5);   //n'
    glVertex3f(2.6, 0.84, -2.5);    //q'
    glVertex3f(2.6, 0.16, -2.5);    //tt'
    glVertex3f(1.59, -0.84, -2.5);  //s'
    glVertex3f(1.59, 0.16, -2.5);   //t'
    glVertex3f(2.6, 0.16, -2.5);    //tt'
    glVertex3f(2.6, -0.84, -2.5);   //r'
    glVertex3f(-2.6, -.84, 2.5);    //m
    glVertex3f(-2.6, -.84, -2.5);   //m'
    glVertex3f(-2.6, 0.84, -2.5);   //n'
    glVertex3f(-2.6, 0.84, 2.5);    //n
    glVertex3f(2.6, 0.84, 2.5);     //q
    glVertex3f(2.6, 0.84, -2.5);    //q'
    glVertex3f(2.6, -0.84, -2.5);   //r'
    glVertex3f(2.6, -0.84, 2.5);    //r
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 1.95, 2.5);      //p
    glVertex3f(3.04, 0.84, 2.5);   //w
    glVertex3f(-3.04, 0.84, 2.5);  //o
    glVertex3f(0, 1.95, -2.5);     //p'
    glVertex3f(3.04, 0.84, -2.5);  //w'
    glVertex3f(-3.04, 0.84, -2.5); //o'
    glEnd();
    glColor3ub(122, 87, 46); //***********top color
    glBegin(GL_QUADS);
    glVertex3f(0, 1.95, 2.8);      //p
    glVertex3f(0, 1.95, -2.8);     //p'
    glVertex3f(3.04, 0.84, -2.8);  //w'
    glVertex3f(3.04, 0.84, 2.8);   //w
    glVertex3f(-3.04, 0.84, 2.8);  //o
    glVertex3f(-3.04, 0.84, -2.8); //o'
    glVertex3f(0, 1.95, -2.8);     //p'
    glVertex3f(0, 1.95, 2.8);      //p
    glEnd();
    glColor3ub(116, 18, 0);
    //*******base color
    glBegin(GL_QUADS);
    glVertex3f(-2.6, -.84, 2.5);  //m
    glVertex3f(2.6, -0.84, 2.5);  //r
    glVertex3f(2.6, -0.84, -2.5); //r'
    glVertex3f(-2.6, -.84, -2.5); //m'
    glEnd();
}