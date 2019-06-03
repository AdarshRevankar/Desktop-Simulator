#include <GL/glut.h>

GLfloat lamp1[4] = { 0., 0.4, 0., 1. };
GLfloat lamp2[4] = { 0., 0., -10., 1. };
GLfloat white[4] = { 1., 1., 1., 1. };
GLfloat black[4] = { .0, 0., 0., 0. };
GLfloat dir[3] = { 0., -1., 0.1 };


void show_light_effect() {
	
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, lamp1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, black);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black);
}