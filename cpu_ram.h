#ifndef CPU_RAM
#define CPU_RAM

#include "parameter.h"

class cpu_ramstick {
	point3D move;
	bool visible = true;
	bool objMove = false;
	void motionHandle();
public:void render(GLfloat, GLfloat, GLfloat);
};

void cpu_ramstick::motionHandle() {
	// RAM REMOVAL
	if (((enterPressed && objIndex == REMOVE_RAM_STICK) || objMove == true) && !assemble)
	{
		objMove = true;
		/// Disassembly of The RAM
		move.x -= 0.007;
		if (move.x < disapphereLimit)
		{
			/// Last reached
			objMove = false;
			enterPressed = false;
			visible = false;
		}
	}
	else if (((enterPressed && objIndex == REMOVE_RAM_STICK -1 ) || objMove == true) && assemble)
	{
		objMove = true;
		visible = true;
		/// Assembly of The RAM
		move.x += 0.007;
		if (move.x >= 0.)
		{
			/// Last reached
			objMove = false;
			enterPressed = false;
		}
	}
}

void cpu_ramstick::render(GLfloat tx, GLfloat ty, GLfloat tz) {
	
	motionHandle();
	if (!visible) return;
	glPushMatrix();
	glTranslatef(move.x, move.y, move.z);

	glTranslatef(tx,ty,tz);
	glRotatef(90., 0., 0., 1.);
	glScalef(0.35, 0.35, 0.35);

	glColor3f(1., 1., 1.);

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[RAMSTICK]);

	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);   glVertex3f(-1, 0, 0.02);
	glTexCoord2f(1., 0);    glVertex3f(1, 0, 0.02);
	glTexCoord2f(1, 1);     glVertex3f(1, 0.5, 0.02);
	glTexCoord2f(0., 1);    glVertex3f(-1, 0.5, 0.02);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[RAMSTICK]);

	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);   glVertex3f(-1, 0, 0);
	glTexCoord2f(1., 0);    glVertex3f(1, 0, 0);
	glTexCoord2f(1, 1);     glVertex3f(1, 0.5, 0);
	glTexCoord2f(0., 1);    glVertex3f(-1, 0.5, 0);
	glEnd();

	glDisable(GL_TEXTURE_2D);


	glColor3f(0, .2, 0);

	glBegin(GL_POLYGON);
	glVertex3f(-1, 0, 0.0);
	glVertex3f(-1, 0.5, 0.0);
	glVertex3f(-1, 0.5, 0.02);
	glVertex3f(-1, 0, 0.02);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(1, 0, 0.0);
	glVertex3f(1, 0.5, 0.0);
	glVertex3f(1, 0.5, 0.02);
	glVertex3f(1, 0, 0.02);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(1, 0, 0.0);
	glVertex3f(1, 0, 0.02);
	glVertex3f(-1, 0, 0.02);
	glVertex3f(-1, 0, 0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(1, 0.5, 0.0);
	glVertex3f(1, 0.5, 0.02);
	glVertex3f(-1, 0.5, 0.02);
	glVertex3f(-1, 0.5, 0.0);
	glEnd();

	glPopMatrix();


}

#endif CPU_RAM

