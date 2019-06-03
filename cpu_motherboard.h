#ifndef CPU_MOTHERBOARD
#define CPU_MOTHERBOARD

#include <GL/glut.h>
#include "dragHandler.h"
#include "parameter.h"

class cpu_motherboard {
private:GLfloat boardThickness = 0.025;
		point3D move;
		bool visible = true;
		bool objMove = false;
		void draw_surface();
		void motionHandle();
		void draw_components(GLfloat, GLfloat, GLfloat, GLfloat,int);
public:void render();
};

void cpu_motherboard::motionHandle() {
	if (((enterPressed && objIndex == REMOVE_MOTHERBOARD) || objMove == true) && !assemble)
	{
		objMove = true;
		move.x -= 0.007;
		if (move.x < disapphereLimit)
		{
			objMove = false;
			enterPressed = false;
			visible = false;
		}
	}
	else if (((enterPressed && objIndex == REMOVE_MOTHERBOARD -1) || objMove == true) && assemble)
	{
		objMove = true;
		visible = true;
		move.x += 0.007;
		if (move.x >= 0.)
		{
			objMove = false;
			enterPressed = false;
		}
	}
}

void cpu_motherboard::render() {

	motionHandle();
	if (!visible) return;
	glPushMatrix();
	glTranslatef(move.x, move.y, move.z);
	glTranslatef(9., 3.55, -3.7);
	glTranslatef(move.x-1., 1.1+move.y, move.z - .9);
	glRotatef(-90., 0., 1., 0.);
	glScalef(.6, .6, .7);
	draw_surface();
	draw_components(0., 0.7, 0.3, 0.4, MOTHERBOARD_USB);
	draw_components(-.2, 0.7, 0.3, 0.2, MOTHERBOARD_USB);
	draw_components(-.65, 1.1, 0.15, 0.25, MOTHERBOARD_VGA);
	glPopMatrix();
}

void cpu_motherboard::draw_surface() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	// Motherboard front
	glBindTexture(GL_TEXTURE_2D, textures[MOTHERBOARD_FRONT]);
	glBegin(GL_QUADS);
		glTexCoord2f(0., 0.);	glVertex3f(-1., -1., 0.);
		glTexCoord2f(0., 1.); glVertex3f(-1., 1., 0.);
		glTexCoord2f(1., 1.); glVertex3f(1., 1., 0.);
		glTexCoord2f(1., 0.); glVertex3f(1., -1., 0.);
	glEnd();
	
	// Motherboard back
	glBindTexture(GL_TEXTURE_2D, textures[MOTHERBOARD_BACK]);
	glBegin(GL_QUADS);
		glTexCoord2f(0., 0.);	glVertex3f(-1., -1., -boardThickness);
		glTexCoord2f(0., 1.); glVertex3f(-1., 1., -boardThickness);
		glTexCoord2f(1., 1.); glVertex3f(1., 1., -boardThickness);
		glTexCoord2f(1., 0.); glVertex3f(1., -1., -boardThickness);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	// Thicknes Sides (fillings)
	glColor3f(0., 0.06, 0.05);
	glBegin(GL_QUAD_STRIP);
		glVertex3f(-1., -1., 0.);	glVertex3f(-1., -1., -boardThickness);
		glVertex3f(-1., 1., 0.);	glVertex3f(-1., 1., -boardThickness);
		glVertex3f(1., 1., 0.);	glVertex3f(1., 1., -boardThickness);
		glVertex3f(1., -1., 0.);	glVertex3f(1., -1., -boardThickness);
		glVertex3f(-1., -1., 0.);	glVertex3f(-1., -1., -boardThickness);
	glEnd();

	glPopMatrix();
}

void cpu_motherboard::draw_components(GLfloat xCord, GLfloat scaleX, GLfloat scaleY, GLfloat scaleZ, int id) {
	glPushMatrix();
	glRotatef(-90., 0., 1., 0.);
	glRotatef(-90., 0., 0., 1.);
	glTranslatef(xCord, 0., 1.);
	glScalef(scaleX, scaleY, scaleZ);
	glColor3f(1., 1., 1.);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[id]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);
		glVertex3f(0., 0., .001);
	glTexCoord2f(0., 1.);
		glVertex3f(0., .4, .001);
	glTexCoord2f(1., 1.);
		glVertex3f(.2, .4, .001);
	glTexCoord2f(1., 0.);
		glVertex3f(.2, 0., .001);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textures[STEEL_FINISH]);
	glColor3f(1., 1., 1.);
	glRotatef(90., 0., 1., 0.);
	glTranslatef(0., 0., .2);
	glBegin(GL_QUAD_STRIP);
	glTexCoord2f(0., 0.); glVertex3f(0., 0., 0.);
	glTexCoord2f(0., 1.); glVertex3f(0., .4, 0.);
	glTexCoord2f(1., 0.); glVertex3f(.6, 0., 0.);
	glTexCoord2f(1., 1.); glVertex3f(.6, .4, 0.);

	glTexCoord2f(1., 0.); glVertex3f(.6, 0., -.2);
	glTexCoord2f(1., 1.); glVertex3f(.6, .4, -.2);

	glTexCoord2f(0., 0.); glVertex3f(.0, .0, -.2);
	glTexCoord2f(0., 1.); glVertex3f(.0, .4, -.2);

	glTexCoord2f(0., 0.); glVertex3f(.0, .0, 0.);
	glTexCoord2f(0., 1.); glVertex3f(.0, .4, 0.);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0., 0., 0.);
	glVertex3f(.6, .0, 0.);
	glVertex3f(.6, .0, -.2);
	glVertex3f(.0, 0., -.2);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0., .4, 0.);
		glVertex3f(.6, .4, 0.);
		glVertex3f(.6, .4, -.2);
		glVertex3f(.0, .4, -.2);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

#endif CPU_MOTHERBOARD