#ifndef CPU_PSU
#define CPU_PSU

#include "parameter.h"
#include "bitmap.h"

class cpu_psu {
		point3D move;
		bool visible = true;
		bool objMove = false;
		void motionHandle();
public:void render();
};

void cpu_psu::motionHandle() {

	if (((enterPressed && objIndex == REMOVE_PSU) || objMove == true) && !assemble)
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
	else if (((enterPressed && objIndex == REMOVE_PSU - 1) || objMove == true) && assemble)
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

void cpu_psu::render() {
	
	motionHandle();

	if (!visible) return;

	glPushMatrix();
	
	glTranslatef(move.x, move.y, move.z);

	glTranslatef(8., 3.4, -4.79);
	glRotatef(-90., 0., 1., 0.);
	glScalef(0.4, 0.4, 0.8);

	glColor3f(1., 1., 1.);
	//front face
	glBegin(GL_POLYGON);
	glVertex3f(-1, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(-1, 1, 0);
	glEnd();

	//back face
	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[PSU_FRONT]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);   glVertex3f(-1, 0, 1);
	glTexCoord2f(1., 0);   glVertex3f(1, 0, 1);
	glTexCoord2f(1, 1);   glVertex3f(1, 1, 1);
	glTexCoord2f(0., 1); glVertex3f(-1, 1, 1);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//side left
	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[PSU_LEFT]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);        glVertex3f(-1, 0, 0);
	glTexCoord2f(1., 0);         glVertex3f(-1, 0, 1);
	glTexCoord2f(1, 1);          glVertex3f(-1, 1, 1);
	glTexCoord2f(0., 1);         glVertex3f(-1, 1, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//side face right
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 0, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, 0);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[PSU_TOP]);

	//top face
	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);    glVertex3f(-1, 1, 0);
	glTexCoord2f(1., 0);     glVertex3f(1, 1, 0);
	glTexCoord2f(1, 1);      glVertex3f(1, 1, 1);
	glTexCoord2f(0., 1);     glVertex3f(-1, 1, 1);




	glEnd();
	glDisable(GL_TEXTURE_2D);

	glColor3f(0.2, 0.2, 0.2);

	//bottom face
	glBegin(GL_POLYGON);
	glVertex3f(-1, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 0, 1);
	glVertex3f(-1, 0, 1);
	glEnd();

	glPopMatrix();

}

#endif CPU_PSU