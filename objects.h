#ifndef OBJECTS 
#define OBJECTS 

#include <GL/glut.h>
#include <GL/freeglut.h> 
#include "bmpLoader.h"

#include "cpu_fan.h"
#include "cpu_motherboard.h"
#include "cpu_case.h"
#include "cpu_ram.h"
#include "cpu_chipset.h"
#include "cpu_gpu.h"
#include "cpu_psu.h"
#include "cpu_harddisk.h"
#include "environment_objects.h"
#include "env_table.h"
#include "cpu_cable.h"

cpu_fan fan_;
cpu_motherboard motherboard_;
cpu_case case_;
cpu_ramstick ram_;
cpu_chipset chipset_;
cpu_gpu gpu_;
cpu_psu psu_;
cpu_harddisk harddisk_;
env env_;
env_table envTable_;
cable sata_;

void drawCube() {

	glPushMatrix();

	GLfloat wallHeight = 9.;

	glColor3f(0.792f + 0.1f, 0.561f + 0.1f, 0.258f + 0.1f);
	glBegin(GL_POLYGON);
	glVertex3f(-10.0f, 0.0f, -10.0f);
		glVertex3f(-10.0f, 0.0f, 10.0f);
		glVertex3f(-10.0f, wallHeight, 10.0f);
		glVertex3f(-10.0f, wallHeight, -10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(10.f, 0.0f, -10.0f);
	glVertex3f(10.f, 0.0f, 10.f);
	glVertex3f(10.f, wallHeight, 10.f);
	glVertex3f(10.f, wallHeight, -10.0f);
	glEnd();

	//front face
	glBegin(GL_POLYGON);
	glVertex3f(-10.0f, 0.0f, -10.0f);
		glVertex3f(10.f, 0.0f, -10.0f);
		glVertex3f(10.f, wallHeight, -10.0f);
		glVertex3f(-10.0f, wallHeight, -10.0f);
	glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-10.0f, 0.0f, 10.f);
		glVertex3f(10.f, 0.0f, 10.f);
		glVertex3f(10.f, wallHeight, 10.f);

		glVertex3f(-10.0f, wallHeight, 10.0f);
	glEnd();

	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[WALL]);
	/////fill
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, textures[CEILING]);

	glBegin(GL_POLYGON);
	glTexCoord2f(3., 3.);	glVertex3f(-10.0f, wallHeight, -10.0f);
	glTexCoord2f(3., 0.);	glVertex3f(10.1f, wallHeight, -10.0f);
	glTexCoord2f(0., 3.);	glVertex3f(10.1f, wallHeight, 10.0f);
	glTexCoord2f(0., 0.);   glVertex3f(-10.0f, wallHeight, 10.0f);

	glEnd();

	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();
}

void drawGround() {

	glColor3f(1., 1., 1.);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[WOODEN_FINISH]);
	glColor3f(1., 1., 1.);
		glBegin(GL_QUADS);
			glTexCoord2f(3., 3.);	glVertex3f(-15., -0.3f, -15.f);
			glTexCoord2f(3., 0.);	glVertex3f(-15.f, -0.3f, 15.f);
			glTexCoord2f(0., 0.);	glVertex3f(15.f, -0.3f, 15.f);
			glTexCoord2f(0., 3.);	glVertex3f(15.f, -0.3f, -15.f);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void drawCPU() {
	fan_.render();	//Renders Fan
	motherboard_.render();
	ram_.render(8., 4.845, -4.296);
	ram_.render(8., 4.845, -4.268);
	ram_.render(8., 4.845, -4.235);
	chipset_.render();
	gpu_.render();
	psu_.render();
	harddisk_.render();
	env_.render();
	envTable_.render();
	sata_.render();
	case_.render();
	

}

#endif OBJECTS