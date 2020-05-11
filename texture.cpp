#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "external_files/RgbImage.cpp"
#include "external_files/RgbImage.h"
using namespace std;

GLuint floortexture, roadtexture, cloud, cloud1, sky, nightcloud, nightcloud1, nightsky;

//Loading and returning texture for the filname
GLuint loadTextureFromFile(const char *filename)
{
    GLuint temp = 0;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    RgbImage theTexMap(filename);

    glGenTextures(1, &temp);
    glBindTexture(GL_TEXTURE_2D, temp);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
    return temp;
}

void textures()
{
    //change the night photos from here
    nightcloud = loadTextureFromFile("textures/bg2.bmp");
    nightcloud1 = loadTextureFromFile("textures/bg5.bmp");
    nightsky = loadTextureFromFile("textures/sky.bmp");
    //dont disturb anything down here
    cloud = loadTextureFromFile("textures/bg2.bmp");
    cloud1 = loadTextureFromFile("textures/bg5.bmp");
    sky = loadTextureFromFile("textures/sky.bmp");
    roadtexture = loadTextureFromFile("textures/road.bmp");
    floortexture = loadTextureFromFile("textures/greengrass.bmp");
}

//sky vertices
float sVert[4][3] = {
    {-200.0, 180.0, -250.0},
    {-200.0, 180.0, +250.0},
    {+200.0, 180.0, +250.0},
    {+200.0, 180.0, -250.0}};

void drawSky()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, sky);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(sVert[0]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(sVert[1]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(sVert[2]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(sVert[3]);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void drawNightSky()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, nightsky);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(sVert[0]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(sVert[1]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(sVert[2]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(sVert[3]);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

//Background Vertices
float bVert[12][3] = {
    {-200.0, 0.0, +250.0},
    {-200.0, 0.0, -250.0},
    {-200.0, 180.0, -250.0},
    {-200.0, 180.0, +250.0},
    {+200.0, 0.0, -250.0},
    {+200.0, 0.0, +250.0},
    {+200.0, 180.0, +250.0},
    {+200.0, 180.0, -250.0},
    {-200.0, 0.0, -250.0},
    {+200.0, 0.0, -250.0},
    {+200.0, 180.0, -250.0},
    {-200.0, 180.0, -250.0}};

void drawClouds()
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, cloud);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(bVert[0]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(bVert[1]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(bVert[2]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(bVert[3]);
    glEnd();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(bVert[4]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(bVert[5]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(bVert[6]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(bVert[7]);
    glEnd();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(bVert[8]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(bVert[9]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(bVert[10]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(bVert[11]);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void drawNightClouds()
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, nightcloud);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(bVert[0]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(bVert[1]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(bVert[2]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(bVert[3]);
    glEnd();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(bVert[4]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(bVert[5]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(bVert[6]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(bVert[7]);
    glEnd();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(bVert[8]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(bVert[9]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(bVert[10]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(bVert[11]);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

float bVert1[4][3] = {
    {+200.0, 0.0, +250.0},
    {-200.0, 0.0, +250.0},
    {-200.0, 180.0, +250.0},
    {+200.0, 180.0, +250.0}};

void drawClouds1()
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, cloud1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(bVert1[0]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(bVert1[1]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(bVert1[2]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(bVert1[3]);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void drawNightClouds1()
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, nightcloud1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(bVert1[0]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(bVert1[1]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(bVert1[2]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(bVert1[3]);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

//Floor Vertices
float fVert[8][3] = {

    {-200.0, 0.0, -250.0},
    {-200.0, 0.0, +250.0},
    {-10.0, 0.0, +250.0},
    {-10.0, 0.0, -250.0},
    {+10.0, 0.0, -250.0},
    {+10.0, 0.0, +250.0},
    {+200.0, 0.0, +250.0},
    {+200.0, 0.0, -250.0}};

void drawFloor()
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, floortexture);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(fVert[0]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(fVert[1]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(fVert[2]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(fVert[3]);
    glEnd();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(fVert[4]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(fVert[5]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(fVert[6]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(fVert[7]);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

//Road Vertices
float rVert[4][3] = {
    {-10.0, 0.0, -250.0},
    {-10.0, 0.0, +250.0},
    {+10.0, 0.0, +250.0},
    {10.0, 0.0, -250.0}};

void drawRoad()
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, roadtexture);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(rVert[0]);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(rVert[1]);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(rVert[2]);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(rVert[3]);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
