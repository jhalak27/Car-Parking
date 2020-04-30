#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void drawcar()
{
    glTranslatef(.0, 0.8, 0.0);
    glEnable(GL_BLEND);           //TRANCPARENCY1
    glBlendFunc(GL_ONE, GL_ZERO); //TRANCPARENCY2
    glBegin(GL_LINE_LOOP);
    glVertex3f(-1.12, -.48, 0.7); //a
    glVertex3f(-0.86, -.48, 0.7); //b
    glVertex3f(-.74, -0.2, 0.7);  //c
    glVertex3f(-.42, -.2, 0.7);   //d
    glVertex3f(-0.3, -.48, 0.7);  //e
    glVertex3f(.81, -0.48, 0.7);  //fglVertex3f(.94,-0.2,0.7);//g
    glVertex3f(1.24, -.2, 0.7);   //h
    glVertex3f(1.38, -.48, 0.7);  //i
    glVertex3f(1.52, -.44, 0.7);  //j
    glVertex3f(1.52, .14, 0.7);   //k
    glVertex3f(1.14, 0.22, 0.7);  //l
    glVertex3f(0.76, .22, 0.7);   //m
    glVertex3f(.52, 0.56, 0.7);   //n
    glVertex3f(-0.1, 0.6, 0.7);   //0
    glVertex3f(-1.02, 0.6, 0.7);  //p
    glVertex3f(-1.2, 0.22, 0.7);  //q
    glVertex3f(-1.2, -.28, 0.7);  //r
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-1.12, -.48, -0.7); //a'
    glVertex3f(-0.86, -.48, -0.7); //b'
    glVertex3f(-.74, -0.2, -0.7);  //c'
    glVertex3f(-.42, -.2, -0.7);   //d'
    glVertex3f(-0.3, -.48, -0.7);  //e'
    glVertex3f(.81, -0.48, -0.7);  //f'
    glVertex3f(.94, -0.2, -0.7);   //g'
    glVertex3f(1.24, -.2, -0.7);   //h'
    glVertex3f(1.38, -.48, -0.7);  //i'
    glVertex3f(1.52, -.44, -0.7);  //j'
    glVertex3f(1.52, .14, -0.7);   //k'
    glVertex3f(1.14, 0.22, -0.7);  //l'
    glVertex3f(0.76, .22, -0.7);   //m'
    glVertex3f(.52, 0.56, -0.7);   //n'
    glVertex3f(-0.1, 0.6, -0.7);   //o'
    glVertex3f(-1.02, 0.6, -0.7);  //p'
    glVertex3f(-1.2, 0.22, -0.7);  //q'
    glVertex3f(-1.2, -.28, -0.7);  //r'
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-1.12, -.48, 0.7);  //a
    glVertex3f(-1.12, -.48, -0.7); //a'
    glVertex3f(-0.86, -.48, 0.7);  //b
    glVertex3f(-0.86, -.48, -0.7); //b'
    glVertex3f(-.74, -0.2, 0.7);   //c
    glVertex3f(-.74, -0.2, -0.7);  //c'
    glVertex3f(-.42, -.2, 0.7);    //d
    glVertex3f(-.42, -.2, -0.7);   //d'
    glVertex3f(-0.3, -.48, 0.7);   //e
    glVertex3f(-0.3, -.48, -0.7);  //e'
    glVertex3f(.81, -0.48, 0.7);   //f
    glVertex3f(.81, -0.48, -0.7);  //f'
    glVertex3f(.94, -0.2, 0.7);    //g
    glVertex3f(.94, -0.2, -0.7);   //g'
    glVertex3f(1.24, -.2, 0.7);    //h
    glVertex3f(1.24, -.2, -0.7);   //h'
    glVertex3f(1.38, -.48, 0.7);   //i
    glVertex3f(1.38, -.48, -0.7);  //i'
    glVertex3f(1.52, -.44, 0.7);   //j
    glVertex3f(1.52, -.44, -0.7);  //j'
    glVertex3f(1.52, .14, 0.7);    //k
    glVertex3f(1.52, .14, -0.7);   //k'
    glVertex3f(1.14, 0.22, 0.7);   //l
    glVertex3f(1.14, 0.22, -0.7);  //l'
    glVertex3f(0.76, .22, 0.7);    //m
    glVertex3f(0.76, .22, -0.7);   //m'
    glVertex3f(.52, 0.56, 0.7);    //n
    glVertex3f(.52, 0.56, -0.7);   //n'
    glVertex3f(-0.1, 0.6, 0.7);    //0
    glVertex3f(-0.1, 0.6, -0.7);   //o'
    glVertex3f(-1.02, 0.6, 0.7);   //p
    glVertex3f(-1.02, 0.6, -0.7);  //p'
    glVertex3f(-1.2, 0.22, 0.7);   //q
    glVertex3f(-1.2, 0.22, -0.7);  //q'
    glVertex3f(-1.2, -.28, 0.7);   //r
    glVertex3f(-1.2, -.28, -0.7);  //r'
    glEnd();
    glBegin(GL_POLYGON);          // top filling
    glVertex3f(-0.1, 0.6, 0.7);   //o
    glVertex3f(-0.1, 0.6, -0.7);  //o'
    glVertex3f(-1.02, 0.6, -0.7); //p'
    glVertex3f(-1.02, 0.6, 0.7);  //p
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.1, 0.6, 0.7);  //o
    glVertex3f(-0.1, 0.6, -0.7); //o'
    glVertex3f(.52, 0.56, -0.7); //n'
    glVertex3f(.52, 0.56, 0.7);  //n
    glEnd();
    glBegin(GL_POLYGON);          //back filling
    glVertex3f(-1.2, 0.22, 0.7);  //q
    glVertex3f(-1.2, 0.22, -0.7); //q'
    glVertex3f(-1.2, -.28, -0.7); //r'
    glVertex3f(-1.2, -.28, 0.7);  //r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.52, .14, 0.7);   //k
    glVertex3f(1.14, 0.22, 0.7);  //l
    glVertex3f(1.14, 0.22, -0.7); //l'
    glVertex3f(1.52, .14, -0.7);  //k'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.76, .22, 0.7);   //m
    glVertex3f(0.76, .22, -0.7);  //m'
    glVertex3f(1.14, 0.22, -0.7); //l'
    glVertex3f(1.14, 0.22, 0.7);  //l
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12, -.48, 0.7); //a
    glVertex3f(-0.86, -.48, 0.7); //b
    glVertex3f(-.74, -0.2, 0.7);  //c
    glVertex3f(-0.64, 0.22, 0.7); //cc
    glVertex3f(-1.08, 0.22, 0.7); //dd
    glVertex3f(-1.2, 0.22, 0.7);  //q
    glVertex3f(-1.2, -.28, 0.7);  //r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74, -0.2, 0.7);  //c
    glVertex3f(-0.64, 0.22, 0.7); //cc
    glVertex3f(-0.5, 0.22, 0.7);  //hh
    glVertex3f(-0.5, -0.2, 0.7);  //pp
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.22, 0.7);  //gg
    glVertex3f(1.14, 0.22, 0.7); //l
    glVertex3f(1.24, -.2, 0.7);  //h
    glVertex3f(0.0, -0.2, 0.7);  //oo
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12, -.48, -0.7); //a'
    glVertex3f(-0.86, -.48, -0.7); //b'
    glVertex3f(-.74, -0.2, -0.7);  //c'
    glVertex3f(-0.64, 0.22, -0.7); //cc'
    glVertex3f(-1.08, 0.22, -0.7); //dd'
    glVertex3f(-1.2, 0.22, -0.7);  //q'
    glVertex3f(-1.2, -.28, -0.7);  //r'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74, -0.2, -0.7);  //c'
    glVertex3f(-0.64, 0.22, -0.7); //cc'
    glVertex3f(-0.5, 0.22, -0.7);  //hh'
    glVertex3f(-0.5, -0.2, -0.7);  //pp'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.22, -0.7);  //gg'
    glVertex3f(1.14, 0.22, -0.7); //l'
    glVertex3f(1.24, -.2, -0.7);  //h'
    glVertex3f(0.0, -0.2, -0.7);  //oo'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2, 0.22, 0.7);  //q
    glVertex3f(-1.08, 0.22, 0.7); //dd
    glVertex3f(-0.98, 0.5, 0.7);  //aa
    glVertex3f(-1.02, 0.6, 0.7);  //p
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02, 0.6, 0.7); //p
    glVertex3f(-0.98, 0.5, 0.7); //aa
    glVertex3f(0.44, 0.5, 0.7);  //jj
    glVertex3f(.52, 0.56, 0.7);  //n
    glVertex3f(-0.1, 0.6, 0.7);  //0
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64, 0.5, 0.7);  //bb
    glVertex3f(-0.64, 0.22, 0.7); //cc
    glVertex3f(-0.5, 0.22, 0.7);  //hh
    glVertex3f(-0.5, 0.5, 0.7);   //ee
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.5, 0.7);   //ff
    glVertex3f(0.0, 0.22, 0.7);  //gg
    glVertex3f(0.12, 0.22, 0.7); //ll
    glVertex3f(0.12, 0.5, 0.7);  //ii
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52, 0.56, 0.7);  //n
    glVertex3f(0.44, 0.5, 0.7);  //jj
    glVertex3f(0.62, 0.22, 0.7); //kk
    glVertex3f(0.76, .22, 0.7);  //m
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42, -.2, 0.7);  //d
    glVertex3f(.94, -0.2, 0.7);  //g
    glVertex3f(.81, -0.48, 0.7); //f
    glVertex3f(-0.3, -.48, 0.7); //e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14, 0.22, 0.7); //l
    glVertex3f(1.52, .14, 0.7);  //k
    glVertex3f(1.52, -.44, 0.7); //j
    glVertex3f(1.38, -.48, 0.7); //i
    glVertex3f(1.24, -.2, 0.7);  //h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2, 0.22, -0.7);  //q'
    glVertex3f(-1.08, 0.22, -0.7); //dd'
    glVertex3f(-0.98, 0.5, -0.7);  //aa'
    glVertex3f(-1.02, 0.6, -0.7);  //p'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02, 0.6, -0.7); //p'
    glVertex3f(-0.98, 0.5, -0.7); //aa'
    glVertex3f(0.44, 0.5, -0.7);  //jj'
    glVertex3f(.52, 0.56, -0.7);  //n'
    glVertex3f(-0.1, 0.6, -0.7);  //0'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64, 0.5, -0.7);  //bb'
    glVertex3f(-0.64, 0.22, -0.7); //cc'
    glVertex3f(-0.5, 0.22, -0.7);  //hh'
    glVertex3f(-0.5, 0.5, -0.7);   //ee'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.5, -0.7);   //ff'
    glVertex3f(0.0, 0.22, -0.7);  //gg'
    glVertex3f(0.12, 0.22, -0.7); //ll'
    glVertex3f(0.12, 0.5, -0.7);  //ii'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52, 0.56, -0.7);  //n'
    glVertex3f(0.44, 0.5, -0.7);  //jj'
    glVertex3f(0.62, 0.22, -0.7); //kk'
    glVertex3f(0.76, .22, -0.7);  //m'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42, -.2, -0.7);  //d'
    glVertex3f(.94, -0.2, -0.7);  //g'
    glVertex3f(.81, -0.48, -0.7); //f'
    glVertex3f(-0.3, -.48, -0.7); //e'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14, 0.22, -0.7); //l'
    glVertex3f(1.52, .14, -0.7);  //k'
    glVertex3f(1.52, -.44, -0.7); //j'
    glVertex3f(1.38, -.48, -0.7); //i'
    glVertex3f(1.24, -.2, -0.7);  //h'
    glEnd();
    glBegin(GL_POLYGON);
    // door1 body- rear, near
    glVertex3f(-0.5, 0.22, 0.7); //hh
    glVertex3f(0.0, 0.22, 0.7);  //gg
    glVertex3f(0.0, -0.2, 0.7);  //oo
    glVertex3f(-0.5, -0.2, 0.7); //pp
    glEnd();
    glBegin(GL_POLYGON);          // door body- rear, far
    glVertex3f(-0.5, 0.22, -0.7); //hh'
    glVertex3f(0.0, 0.22, -0.7);  //gg'
    glVertex3f(0.0, -0.2, -0.7);  //oo'
    glVertex3f(-0.5, -0.2, -0.7); //pp'
    glEnd();
    glBegin(GL_POLYGON);         // door2 body- near, driver
    glVertex3f(0.12, 0.22, 0.7); //ll
    glVertex3f(0.62, 0.22, 0.7); //kk
    glVertex3f(0.62, -0.2, 0.7); //mm
    glVertex3f(0.12, -0.2, 0.7); //nn
    glEnd();
    glBegin(GL_POLYGON);          // door2 body- far, driver
    glVertex3f(0.12, 0.22, -0.7); //ll'
    glVertex3f(0.62, 0.22, -0.7); //kk'
    glVertex3f(0.62, -0.2, -0.7); //mm'
    glVertex3f(0.12, -0.2, -0.7); //nn'
    glEnd();
    glBegin(GL_POLYGON);          //front**
    glVertex3f(1.52, .14, 0.7);   //k
    glVertex3f(1.52, .14, -0.7);  //k'
    glVertex3f(1.52, -.44, -0.7); //j'
    glVertex3f(1.52, -.44, 0.7);  //j
    glEnd();
    glTranslatef(-.58, -.52, 0.7); //translate to 1st tyre
    glColor3f(0.09, 0.09, 0.09);
    // tyre color********
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(1.68, 0.0, 0.0); //translate to 2nd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(0.0, 0.0, -1.4); //translate to 3rd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(-1.68, 0.0, 0.0); //translate to 4th tyre which is behind 1st tyre rearback
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(.58, .52, 0.7); //translate to origin
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glTranslatef(0.0, 0.0, -1.40);
    glutSolidTorus(0.2f, .2f, 10, 25);
    glTranslatef(0.0, 0.0, 1.40);
    glRotatef(270.0, 0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    //bottom fillingglColor3f(0.25,0.25,0.25);
    glVertex3f(-0.3, -.48, 0.7);  //e
    glVertex3f(-0.3, -.48, -0.7); //e'
    glVertex3f(.81, -0.48, -0.7); //f'
    glVertex3f(.81, -0.48, 0.7);  //f
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42, -.2, 0.7);   //d
    glVertex3f(-.42, -.2, -0.7);  //d'
    glVertex3f(-0.3, -.48, -0.7); //e'
    glVertex3f(-0.3, -.48, 0.7);  //e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2, -.28, 0.7);   //r
    glVertex3f(-1.2, -.28, -0.7);  //r'
    glVertex3f(-1.12, -.48, -0.7); //a'
    glVertex3f(-1.12, -.48, 0.7);  //a
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12, -.48, 0.7);  //a
    glVertex3f(-1.12, -.48, -0.7); //a'
    glVertex3f(-0.86, -.48, -0.7); //b'
    glVertex3f(-0.86, -.48, 0.7);  //b
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.86, -.48, 0.7);  //b
    glVertex3f(-0.86, -.48, -0.7); //b'
    glVertex3f(-.74, -0.2, -0.7);  //c'
    glVertex3f(-.74, -0.2, 0.7);   //c
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74, -0.2, 0.7);  //c
    glVertex3f(-.74, -0.2, -0.7); //c'
    glVertex3f(-.42, -.2, -0.7);  //d'
    glVertex3f(-.42, -.2, 0.7);   //d
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.81, -0.48, 0.7);  //f
    glVertex3f(.81, -0.48, -0.7); //f'
    glVertex3f(.94, -0.2, -0.7);  //g'
    glVertex3f(.94, -0.2, 0.7);   //g
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.94, -0.2, 0.7);  //g
    glVertex3f(.94, -0.2, -0.7); //g'
    glVertex3f(1.24, -.2, -0.7); //h'
    glVertex3f(1.24, -.2, 0.7);  //h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.24, -.2, 0.7);   //h
    glVertex3f(1.24, -.2, -0.7);  //h'
    glVertex3f(1.38, -.48, -0.7); //i'
    glVertex3f(1.38, -.48, 0.7);  //i
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.38, -.48, 0.7);  //i
    glVertex3f(1.38, -.48, -0.7); //i'
    glVertex3f(1.52, -.44, -0.7); //j'
    glVertex3f(1.52, -.44, 0.7);  //j
    glEnd();
    glBegin(GL_LINE_LOOP); // door outline- rear, front
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.5, 0.22, 0.7); //hh
    glVertex3f(0.0, 0.22, 0.7);  //gg
    glVertex3f(0.0, -0.2, 0.7);  //oo
    glVertex3f(-0.5, -0.2, 0.7); //pp
    glEnd();
    glBegin(GL_LINE_LOOP);       // door2 outline- near, driver
    glVertex3f(0.12, 0.22, 0.7); //ll
    glVertex3f(0.62, 0.22, 0.7); //kk
    glVertex3f(0.62, -0.2, 0.7); //mm
    glVertex3f(0.12, -0.2, 0.7); //nn
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);        // door2 outline- far, driver
    glVertex3f(0.12, 0.22, -0.7); //ll'
    glVertex3f(0.62, 0.22, -0.7); //kk'
    glVertex3f(0.62, -0.2, -0.7); //mm'
    glVertex3f(0.12, -0.2, -0.7); //nn'
    glEnd();
    glBegin(GL_LINE_LOOP);        // door outline- rear, far
    glVertex3f(-0.5, 0.22, -0.7); //hh'
    glVertex3f(0.0, 0.22, -0.7);  //gg'
    glVertex3f(0.0, -0.2, -0.7);  //oo'
    glVertex3f(-0.5, -0.2, -0.7); //pp'
    glEnd();
    glBegin(GL_POLYGON);
    //front**
    glVertex3f(1.52, .14, 0.7);   //k
    glVertex3f(1.52, .14, -0.7);  //k'
    glVertex3f(1.52, -.44, -0.7); //j'
    glVertex3f(1.52, -.44, 0.7);  //j
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    // transparent objects are placed next ..
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //TRANCPARENCY3
    //windscreen
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 0.0, 0.7);
    //COLOR =WHITE TRANSPARENT
    glVertex3f(0.562, .5, .6); //AAA
    glVertex3f(.562, .5, -.6); //AAA'
    glVertex3f(.76, .22, -.6); //MMM'
    glVertex3f(.76, .22, .6);  //MMM
    glEnd();
    glBegin(GL_POLYGON);
    //rear window
    //COLOR =WHITE TRANSPARENT
    glVertex3f(-1.068, 0.5, 0.6);  //pp
    glVertex3f(-1.068, 0.5, -0.6); //pp'
    glVertex3f(-1.2, 0.22, -0.6);  //qq'
    glVertex3f(-1.2, 0.22, 0.6);   //qq
    glEnd();
    glBegin(GL_POLYGON);          //leftmost window front
    glVertex3f(-0.98, 0.5, 0.7);  //aa
    glVertex3f(-0.64, 0.5, 0.7);  //bb
    glVertex3f(-0.64, 0.22, 0.7); //cc
    glVertex3f(-1.08, 0.22, 0.7); //dd
    glEnd();
    glBegin(GL_POLYGON);           //leftmost window back
    glVertex3f(-0.98, 0.5, -0.7);  //aa
    glVertex3f(-0.64, 0.5, -0.7);  //bb
    glVertex3f(-0.64, 0.22, -0.7); //cc
    glVertex3f(-1.08, 0.22, -0.7); //dd
    glEnd();
    glBegin(GL_POLYGON); //middle window front
    glVertex3f(-0.5, 0.5, 0.7);
    glVertex3f(0.0, 0.5, 0.7);
    glVertex3f(0.0, 0.22, 0.7);
    glVertex3f(-0.5, 0.22, 0.7);
    glEnd();
    glBegin(GL_POLYGON);
    //middle window back
    glVertex3f(-0.5, 0.5, -0.7);
    glVertex3f(0.0, 0.5, -0.7);
    glVertex3f(0.0, 0.22, -0.7);
    glVertex3f(-0.5, 0.22, -0.7);
    glEnd();
    glBegin(GL_POLYGON);
    //rightmost window front
    glVertex3f(0.12, 0.5, 0.7);  //ii
    glVertex3f(0.44, 0.5, 0.7);  //jj
    glVertex3f(0.62, 0.22, 0.7); //kk
    glVertex3f(0.12, 0.22, 0.7); //ll
    glEnd();
    glBegin(GL_POLYGON);
    //rightmost window back
    glVertex3f(0.12, 0.5, -0.7);  //ii'
    glVertex3f(0.44, 0.5, -0.7);  //jj'
    glVertex3f(0.62, 0.22, -0.7); //kk'
    glVertex3f(0.12, 0.22, -0.7); //ll'
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
}

void drawhouse()
{
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
    glBegin(GL_LINES);
    glVertex3f(1.59, -0.84, 2.5);  //s
    glVertex3f(-1.59, -0.84, 2.5); //v
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-2.6, -.84, -2.5);   //m'
    glVertex3f(-2.6, 0.84, -2.5);   //n'
    glVertex3f(-3.04, 0.84, -2.8);  //o'
    glVertex3f(0, 1.95, -2.8);      //p'
    glVertex3f(3.04, 0.84, -2.8);   //w'
    glVertex3f(2.6, 0.84, -2.5);    //q'
    glVertex3f(2.6, -0.84, -2.5);   //r'
    glVertex3f(1.59, -0.84, -2.5);  //s'
    glVertex3f(1.59, 0.16, -2.5);   //t'
    glVertex3f(-1.59, 0.16, -2.5);  //u'
    glVertex3f(-1.59, -0.84, -2.5); //v'
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
    glColor3ub(255, 185, 1); //*************
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
    glColor3ub(255, 102, 0); //***********top color
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