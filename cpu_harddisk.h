#ifndef HARDDISK
#define HARDDISK

#include "parameter.h"

class cpu_harddisk {
	point3D move;
	bool visible = true;
	bool objMove = false;

	void motionHandle();
public:void render();
};

void cpu_harddisk::motionHandle() {

	if (((enterPressed && objIndex == REMOVE_HDD) || objMove == true) && !assemble)
	{
		objMove = true;
		if (move.z < -1.)
			move.x -= 0.007;
		else
			move.z -= 0.007;

		if (move.x < disapphereLimit)
		{
			enterPressed = false;
			objMove = false;
			visible = false;
		}
	}
	else if (((enterPressed && objIndex == REMOVE_HDD-1) || objMove == true) && assemble)
	{
		objMove = true;
		visible = true;
		if (move.x < 0.)
			move.x += 0.007;
		else
			move.z += 0.007;

		if (move.x >= 0. && move.z >= 0.)
		{
			enterPressed = false;
			objMove = false;
		}
	}
}

void cpu_harddisk::render() {
	GLfloat scaleFactor = 0.4;
	
	motionHandle();
	if (!visible) return;
	glPushMatrix();
	glTranslatef(move.x, move.y, move.z);
	glScalef(scaleFactor, scaleFactor, scaleFactor);
	glTranslatef(8./scaleFactor, 3.86/scaleFactor, -3.2/scaleFactor);
	glRotatef(-90., 0., 1., 0);

	glColor3f(0.05, 0.05, 0.05);
	//back face
	glBegin(GL_POLYGON);
	glVertex3f(-1, 0.2, 0);
	glVertex3f(-1, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 0.2, 0);
	glEnd();

	//side face right

	glBegin(GL_POLYGON);
	glVertex3f(1, 0.2, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 0, 0.8);
	glVertex3f(1, 0.2, 0.8);
	glEnd();


	//back
	glBegin(GL_POLYGON);
	glVertex3f(1, 0.2, 0.8);
	glVertex3f(1, 0, 0.8);
	glVertex3f(-1, 0, 0.8);
	glVertex3f(-1, 0.2, 0.8);
	glEnd();

	//side left face
	glBegin(GL_POLYGON);
	glVertex3f(-1, 0.2, .8);
	glVertex3f(-1, 0, 0.8);
	glVertex3f(-1, 0, 0);
	glVertex3f(-1, 0.2, 0);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[HDD_TOP]);


	//top
	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);   glVertex3f(-1, 0.2, 0);
	glTexCoord2f(0., 1);    glVertex3f(1, 0.2, 0);
	glTexCoord2f(1, 1);     glVertex3f(1, 0.2, 0.8);
	glTexCoord2f(1., 0);    glVertex3f(-1, 0.2, 0.8);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	//bottom
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 0, 0.8);
	glVertex3f(-1, 0, 0.8);
	glEnd();

	glPopMatrix();

}

#endif HARDDISK