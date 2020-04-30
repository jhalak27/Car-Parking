#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
static float angle = 0.0, ratio;
static float x = 0.0f, y = 3.00f, z = 100.0f;
static float lx = 0.10f, ly = 0.10f, lz = -1.0f;
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
void drawcar()
{
	glTranslatef(.0, 0.8, 0.0);
	glEnable(GL_BLEND);			  //TRANCPARENCY1
	glBlendFunc(GL_ONE, GL_ZERO); //TRANCPARENCY2
	glBegin(GL_LINE_LOOP);
	glVertex3f(-1.12, -.48, 0.7); //a
	glVertex3f(-0.86, -.48, 0.7); //b
	glVertex3f(-.74, -0.2, 0.7);  //c
	glVertex3f(-.42, -.2, 0.7);	  //d
	glVertex3f(-0.3, -.48, 0.7);  //e
	glVertex3f(.81, -0.48, 0.7);  //fglVertex3f(.94,-0.2,0.7);//g
	glVertex3f(1.24, -.2, 0.7);	  //h
	glVertex3f(1.38, -.48, 0.7);  //i
	glVertex3f(1.52, -.44, 0.7);  //j
	glVertex3f(1.52, .14, 0.7);	  //k
	glVertex3f(1.14, 0.22, 0.7);  //l
	glVertex3f(0.76, .22, 0.7);	  //m
	glVertex3f(.52, 0.56, 0.7);	  //n
	glVertex3f(-0.1, 0.6, 0.7);	  //0
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
	glVertex3f(-.42, -.2, 0.7);	   //d
	glVertex3f(-.42, -.2, -0.7);   //d'
	glVertex3f(-0.3, -.48, 0.7);   //e
	glVertex3f(-0.3, -.48, -0.7);  //e'
	glVertex3f(.81, -0.48, 0.7);   //f
	glVertex3f(.81, -0.48, -0.7);  //f'
	glVertex3f(.94, -0.2, 0.7);	   //g
	glVertex3f(.94, -0.2, -0.7);   //g'
	glVertex3f(1.24, -.2, 0.7);	   //h
	glVertex3f(1.24, -.2, -0.7);   //h'
	glVertex3f(1.38, -.48, 0.7);   //i
	glVertex3f(1.38, -.48, -0.7);  //i'
	glVertex3f(1.52, -.44, 0.7);   //j
	glVertex3f(1.52, -.44, -0.7);  //j'
	glVertex3f(1.52, .14, 0.7);	   //k
	glVertex3f(1.52, .14, -0.7);   //k'
	glVertex3f(1.14, 0.22, 0.7);   //l
	glVertex3f(1.14, 0.22, -0.7);  //l'
	glVertex3f(0.76, .22, 0.7);	   //m
	glVertex3f(0.76, .22, -0.7);   //m'
	glVertex3f(.52, 0.56, 0.7);	   //n
	glVertex3f(.52, 0.56, -0.7);   //n'
	glVertex3f(-0.1, 0.6, 0.7);	   //0
	glVertex3f(-0.1, 0.6, -0.7);   //o'
	glVertex3f(-1.02, 0.6, 0.7);   //p
	glVertex3f(-1.02, 0.6, -0.7);  //p'
	glVertex3f(-1.2, 0.22, 0.7);   //q
	glVertex3f(-1.2, 0.22, -0.7);  //q'
	glVertex3f(-1.2, -.28, 0.7);   //r
	glVertex3f(-1.2, -.28, -0.7);  //r'
	glEnd();
	glBegin(GL_POLYGON);		  // top filling
	glVertex3f(-0.1, 0.6, 0.7);	  //o
	glVertex3f(-0.1, 0.6, -0.7);  //o'
	glVertex3f(-1.02, 0.6, -0.7); //p'
	glVertex3f(-1.02, 0.6, 0.7);  //p
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 0.6, 0.7);	 //o
	glVertex3f(-0.1, 0.6, -0.7); //o'
	glVertex3f(.52, 0.56, -0.7); //n'
	glVertex3f(.52, 0.56, 0.7);	 //n
	glEnd();
	glBegin(GL_POLYGON);		  //back filling
	glVertex3f(-1.2, 0.22, 0.7);  //q
	glVertex3f(-1.2, 0.22, -0.7); //q'
	glVertex3f(-1.2, -.28, -0.7); //r'
	glVertex3f(-1.2, -.28, 0.7);  //r
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(1.52, .14, 0.7);	  //k
	glVertex3f(1.14, 0.22, 0.7);  //l
	glVertex3f(1.14, 0.22, -0.7); //l'
	glVertex3f(1.52, .14, -0.7);  //k'
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.76, .22, 0.7);	  //m
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
	glVertex3f(0.0, 0.22, 0.7);	 //gg
	glVertex3f(1.14, 0.22, 0.7); //l
	glVertex3f(1.24, -.2, 0.7);	 //h
	glVertex3f(0.0, -0.2, 0.7);	 //oo
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
	glVertex3f(0.44, 0.5, 0.7);	 //jj
	glVertex3f(.52, 0.56, 0.7);	 //n
	glVertex3f(-0.1, 0.6, 0.7);	 //0
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.64, 0.5, 0.7);  //bb
	glVertex3f(-0.64, 0.22, 0.7); //cc
	glVertex3f(-0.5, 0.22, 0.7);  //hh
	glVertex3f(-0.5, 0.5, 0.7);	  //ee
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.5, 0.7);	 //ff
	glVertex3f(0.0, 0.22, 0.7);	 //gg
	glVertex3f(0.12, 0.22, 0.7); //ll
	glVertex3f(0.12, 0.5, 0.7);	 //ii
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(.52, 0.56, 0.7);	 //n
	glVertex3f(0.44, 0.5, 0.7);	 //jj
	glVertex3f(0.62, 0.22, 0.7); //kk
	glVertex3f(0.76, .22, 0.7);	 //m
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-.42, -.2, 0.7);	 //d
	glVertex3f(.94, -0.2, 0.7);	 //g
	glVertex3f(.81, -0.48, 0.7); //f
	glVertex3f(-0.3, -.48, 0.7); //e
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(1.14, 0.22, 0.7); //l
	glVertex3f(1.52, .14, 0.7);	 //k
	glVertex3f(1.52, -.44, 0.7); //j
	glVertex3f(1.38, -.48, 0.7); //i
	glVertex3f(1.24, -.2, 0.7);	 //h
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
	glVertex3f(0.0, 0.5, -0.7);	  //ff'
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
	glVertex3f(0.0, 0.22, 0.7);	 //gg
	glVertex3f(0.0, -0.2, 0.7);	 //oo
	glVertex3f(-0.5, -0.2, 0.7); //pp
	glEnd();
	glBegin(GL_POLYGON);		  // door body- rear, far
	glVertex3f(-0.5, 0.22, -0.7); //hh'
	glVertex3f(0.0, 0.22, -0.7);  //gg'
	glVertex3f(0.0, -0.2, -0.7);  //oo'
	glVertex3f(-0.5, -0.2, -0.7); //pp'
	glEnd();
	glBegin(GL_POLYGON);		 // door2 body- near, driver
	glVertex3f(0.12, 0.22, 0.7); //ll
	glVertex3f(0.62, 0.22, 0.7); //kk
	glVertex3f(0.62, -0.2, 0.7); //mm
	glVertex3f(0.12, -0.2, 0.7); //nn
	glEnd();
	glBegin(GL_POLYGON);		  // door2 body- far, driver
	glVertex3f(0.12, 0.22, -0.7); //ll'
	glVertex3f(0.62, 0.22, -0.7); //kk'
	glVertex3f(0.62, -0.2, -0.7); //mm'
	glVertex3f(0.12, -0.2, -0.7); //nn'
	glEnd();
	glBegin(GL_POLYGON);		  //front**
	glVertex3f(1.52, .14, 0.7);	  //k
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
	glVertex3f(-.42, -.2, 0.7);	  //d
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
	glVertex3f(-.42, -.2, 0.7);	  //d
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(.81, -0.48, 0.7);  //f
	glVertex3f(.81, -0.48, -0.7); //f'
	glVertex3f(.94, -0.2, -0.7);  //g'
	glVertex3f(.94, -0.2, 0.7);	  //g
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(.94, -0.2, 0.7);	 //g
	glVertex3f(.94, -0.2, -0.7); //g'
	glVertex3f(1.24, -.2, -0.7); //h'
	glVertex3f(1.24, -.2, 0.7);	 //h
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(1.24, -.2, 0.7);	  //h
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
	glVertex3f(0.0, 0.22, 0.7);	 //gg
	glVertex3f(0.0, -0.2, 0.7);	 //oo
	glVertex3f(-0.5, -0.2, 0.7); //pp
	glEnd();
	glBegin(GL_LINE_LOOP);		 // door2 outline- near, driver
	glVertex3f(0.12, 0.22, 0.7); //ll
	glVertex3f(0.62, 0.22, 0.7); //kk
	glVertex3f(0.62, -0.2, 0.7); //mm
	glVertex3f(0.12, -0.2, 0.7); //nn
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);		  // door2 outline- far, driver
	glVertex3f(0.12, 0.22, -0.7); //ll'
	glVertex3f(0.62, 0.22, -0.7); //kk'
	glVertex3f(0.62, -0.2, -0.7); //mm'
	glVertex3f(0.12, -0.2, -0.7); //nn'
	glEnd();
	glBegin(GL_LINE_LOOP);		  // door outline- rear, far
	glVertex3f(-0.5, 0.22, -0.7); //hh'
	glVertex3f(0.0, 0.22, -0.7);  //gg'
	glVertex3f(0.0, -0.2, -0.7);  //oo'
	glVertex3f(-0.5, -0.2, -0.7); //pp'
	glEnd();
	glBegin(GL_POLYGON);
	//front**
	glVertex3f(1.52, .14, 0.7);	  //k
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
	glBegin(GL_POLYGON);		  //leftmost window front
	glVertex3f(-0.98, 0.5, 0.7);  //aa
	glVertex3f(-0.64, 0.5, 0.7);  //bb
	glVertex3f(-0.64, 0.22, 0.7); //cc
	glVertex3f(-1.08, 0.22, 0.7); //dd
	glEnd();
	glBegin(GL_POLYGON);		   //leftmost window back
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
	glVertex3f(0.12, 0.5, 0.7);	 //ii
	glVertex3f(0.44, 0.5, 0.7);	 //jj
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

GLuint createDL()
{
	GLuint carDL;
	carDL = glGenLists(1);		  // Create the id for the list
	glNewList(carDL, GL_COMPILE); // start list
	drawcar();					  // call the function that contains the rendering commands
	glEndList();				  // endList
	return (carDL);
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
	glPushMatrix();
	glTranslatef(-10, 0, 40);
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

void processNormalKeys(unsigned char key, int x, int y)
{
	glLoadIdentity();
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
	glutCreateWindow("car lot");
	initScene();
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(inputKey);
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutMainLoop();
	return (0);
}