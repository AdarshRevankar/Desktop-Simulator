#ifndef CPU_GPU
#define CPU_GPU

#include "parameter.h"

class cpu_gpu {
		point3D move;
		bool visible = true;
		bool objMove = false;
		void lower_render();
		void motionHandle();
public: void render();
		
};

void cpu_gpu::motionHandle() {
	if (((enterPressed && objIndex == REMOVE_GPU) || objMove == true) && !assemble)
	{
		objMove = true;
		move.x -= 0.007;
		if (move.x < disapphereLimit)
		{
			enterPressed = false;
			visible = false;
			objMove = false;
		}
	}	
	else if (((enterPressed && objIndex == REMOVE_GPU) || objMove == true) && assemble)
	{
		objMove = true;
		visible = true;

		move.x += 0.007;
		if (move.x >= 0.)
		{
			enterPressed = false;
			objMove = false;
		}
	}
}

void cpu_gpu::render() {

	motionHandle();
	if (!visible) return;
	glPushMatrix();
	glTranslatef(move.x, move.y, move.z);

	glTranslatef(7.55, 4.2, -4.65);
	glRotatef(-90., 0., 1., 0.);
	glRotatef(-90.,1., 0., 0.);


	glScalef(0.3, 0.3, 0.3);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[GPU_FRONT]);

	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);   glVertex3f(-1.75, 0, 0.2);
	glTexCoord2f(1., 0);    glVertex3f(1.5, 0, 0.2);
	glTexCoord2f(1, 1);     glVertex3f(1.5, 1.5, 0.2);
	glTexCoord2f(0., 1);    glVertex3f(-1.75, 1.5, 0.2);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	//back
	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[GPU_LEFT]);


	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);   glVertex3f(-1.75, 1.5, 0);
	glTexCoord2f(1., 0.);  glVertex3f(1.5, 1.5, 0);
	glTexCoord2f(1., 1.);  glVertex3f(1.5, 0, 0);
	glTexCoord2f(0., 1.);  glVertex3f(-1.75, 0, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);



	//side

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[GPU_BACK]);
	glBegin(GL_POLYGON);

	glTexCoord2f(0., 0.);  glVertex3f(-1.75, 0, 0.0);
	glTexCoord2f(1., 0.);   glVertex3f(-1.75, 1.5, 0.0);
	glTexCoord2f(1., 1.);     glVertex3f(-1.75, 1.5, 0.3);
	glTexCoord2f(0., 1.);  glVertex3f(-1.75, 0, 0.3);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	//side
	glColor3f(0.2, 0.2, 0.2);
	
	glBegin(GL_POLYGON);
	glVertex3f(1.5, 0, 0.0);
	glVertex3f(1.5, 1.5, 0.0);
	glVertex3f(1.5, 1.5, 0.2);
	glVertex3f(1.5, 0, 0.2);
	glEnd();

	//bottom
	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[GPU_SIDE]);
	glBegin(GL_POLYGON);
	glTexCoord2i(1, 0);
	glVertex3f(1.5, 0, 0.0);
	glTexCoord2i(1, 1);
	glVertex3f(1.5, 0, 0.2);
	glTexCoord2i(0, 1);
	glVertex3f(-1.5, 0, 0.2);
	glTexCoord2i(0, 0);
	glVertex3f(-1.5, 0, 0.0);
	glEnd();

	//top

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[GPU_SIDE]);
	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.); glVertex3f(-1.75, 1.5, 0.0);
	glTexCoord2f(1., 1.); glVertex3f(-1.75, 1.5, 0.2);
	glTexCoord2f(0., 1.); glVertex3f(1.5, 1.5, 0.2);
	glTexCoord2f(0., 0.); glVertex3f(1.5, 1.5, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//glPushMatrix();
	//lower_render();
	//glPopMatrix();
	glPopMatrix();




}

void cpu_gpu::lower_render() {

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(0.5, 0.5, 0.5);
	glBindTexture(GL_TEXTURE_2D, textures[GPU_LOWER]);

	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);   glVertex3f(-1.2, 0, 0.1);
	glTexCoord2f(1, 0);    glVertex3f(0.4, 0, 0.1);
	glTexCoord2f(1, -1);     glVertex3f(0.4, -0.15, 0.1);
	glTexCoord2f(0, -1);    glVertex3f(-1.2, -0.15, 0.1);
	glEnd();

	glDisable(GL_TEXTURE_2D);



	glEnable(GL_TEXTURE_2D);
	glColor3f(0.5, 0.5, 0.5);
	glBindTexture(GL_TEXTURE_2D, textures[GPU_LOWER]);

	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);   glVertex3f(-1.2, 0, 0);
	glTexCoord2f(1, 0);    glVertex3f(0.4, 0, 0);
	glTexCoord2f(1, -1);     glVertex3f(0.4, -0.15, 0);
	glTexCoord2f(0, -1);    glVertex3f(-1.2, -0.15, 0);
	glEnd();

	glDisable(GL_TEXTURE_2D);


	glColor3f(0.5, 0.5, 0.5);
	//side
	glBegin(GL_POLYGON);
	glVertex3f(-1.2, 0, 0.1);
	glVertex3f(-1.2, -0.15, 0.1);
	glVertex3f(-1.2, -0.15, 0);
	glVertex3f(-1.2, 0, 0);
	glEnd();

	//side

	glBegin(GL_POLYGON);
	glVertex3f(0.4, 0, 0.1);
	glVertex3f(0.4, -0.15, 0.1);
	glVertex3f(0.4, -0.15, 0);
	glVertex3f(0.4, 0, 0);
	glEnd();

	//bottom
	glBegin(GL_POLYGON);
	glVertex3f(0.4, 0, 0.1);
	glVertex3f(0.4, 0, 0);
	glVertex3f(-1.2, 0, 0);
	glVertex3f(-1.2, 0, 0.1);
	glEnd();
	//top
	glBegin(GL_POLYGON);
	glVertex3f(0.4, -0.15, 0.1);
	glVertex3f(0.4, -0.15, 0);
	glVertex3f(-1.2, -0.15, 0);
	glVertex3f(-1.2, -0.15, 0.1);
	glEnd();

	glPopMatrix();

}

#endif CPU_GPU
