#ifndef CPU_CHIPSET
#define CPU_CHIPSET

#include "parameter.h"

class cpu_chipset {
	point3D move;
	bool visible = true;
	bool objMove = false;
	void motionHandle();
public:void render();
};

void cpu_chipset::motionHandle() {
	if (((enterPressed && objIndex == REMOVE_PROCESSOR) || objMove == true) && !assemble)
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
	else if (((enterPressed && objIndex == REMOVE_PROCESSOR-1) || objMove == true) && assemble)
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

void cpu_chipset::render() {
	
	motionHandle();
	if (!visible) return;
	glPushMatrix();
	glTranslatef(move.x, move.y, move.z);
	glColor3f(1, 1, 1);
	glTranslatef(8., 4.77, -4.7);
	glRotatef(-90., 0., 1., 0.);
	glScalef(0.2, 0.2, 0.2);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[CHIPSET]);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);   glVertex3f(0, 0, 0.05);
	glTexCoord2f(1., 0);    glVertex3f(1, 0, 0.05);
	glTexCoord2f(1, 1);     glVertex3f(1, 1, 0.05);
	glTexCoord2f(0., 1);    glVertex3f(0, 1, 0.05);
	glEnd();

	glDisable(GL_TEXTURE_2D);



	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, textures[CHIPSET_BACK]);

	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);   glVertex3f(0, 0, 0);
	glTexCoord2f(1., 0);    glVertex3f(1, 0, 0);
	glTexCoord2f(1, 1);     glVertex3f(1, 1, 0.0);
	glTexCoord2f(0., 1);    glVertex3f(0, 1, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glColor3f(0, .1, 0);

	glBegin(GL_POLYGON);
	glVertex3f(0, 1, 0.0);
	glVertex3f(1, 1, 0.0);
	glVertex3f(1, 1, 0.05);
	glVertex3f(0, 1, 0.05);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0.0);
	glVertex3f(1, 0, 0.0);
	glVertex3f(1, 0, 0.05);
	glVertex3f(0, 0, 0.05);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0.0);
	glVertex3f(0, 1, 0.0);
	glVertex3f(0, 1, 0.05);
	glVertex3f(0, 0, 0.05);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(1, 0, 0.0);
	glVertex3f(1, 1, 0.0);
	glVertex3f(1, 1, 0.05);
	glVertex3f(1, 0, 0.05);
	glEnd();

	glPopMatrix();

}

#endif CPU_CHIPSET


