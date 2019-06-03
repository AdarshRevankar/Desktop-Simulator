#ifndef ENV_TABLE
#define ENV_TABLE

#include "parameter.h"

class env_table {
public:void render();
};

void env_table::render() {
	
	glPushMatrix();
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 3, -9.9);
	glVertex3f(0, 3, -7);
	glVertex3f(1, 3, -7);
	glVertex3f(1, 3, -9.9);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0, 0, -9.9);
	glVertex3f(0, 0, -7);
	glVertex3f(1, 0, -7);
	glVertex3f(1, 0, -9.9);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0, 3, -9.9);
	glVertex3f(0, 3, -7);
	glVertex3f(0, 0, -7);
	glVertex3f(0, 0, -9.9);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(1, 3, -9.9);
	glVertex3f(1, 3, -7);
	glVertex3f(1, 0, -7);
	glVertex3f(1, 0, -9.9);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0, 3, -7);
	glVertex3f(0, 0, -7);
	glVertex3f(1, 0, -7);
	glVertex3f(1, 3, -7);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(0, 3, -9.9);
	glVertex3f(0, 0, -9.9);
	glVertex3f(1, 0, -9.9);
	glVertex3f(1, 3, -9.9);
	glEnd();


	//fourth(6,10)
	glBegin(GL_POLYGON);
	glVertex3f(5, 3, -9.9);
	glVertex3f(5, 3, -7);
	glVertex3f(6, 3, -7);
	glVertex3f(6, 3, -9.9);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(5, 0, -9.9);
	glVertex3f(5, 0, -7);
	glVertex3f(6, 0, -7);
	glVertex3f(6, 0, -9.9);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(5, 3, -9.9);
	glVertex3f(5, 3, -7);
	glVertex3f(5, 0, -7);
	glVertex3f(5, 0, -9.9);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(6, 3, -9.9);
	glVertex3f(6, 3, -7);
	glVertex3f(6, 0, -7);
	glVertex3f(6, 0, -9.9);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(5, 3, -7);
	glVertex3f(5, 0, -7);
	glVertex3f(6, 0, -7);
	glVertex3f(6, 3, -7);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(5, 3, -9.9);
	glVertex3f(5, 0, -9.9);
	glVertex3f(6, 0, -9.9);
	glVertex3f(6, 3, -9.9);
	glEnd();


	//fifth


	glBegin(GL_POLYGON);
	glVertex3f(6, 3, -7);
	glVertex3f(6, 3, -6);
	glVertex3f(9.9, 3, -6);
	glVertex3f(9.9, 3, -7);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(6, 0, -7);
	glVertex3f(6, 0, -6);
	glVertex3f(9.9, 0, -6);
	glVertex3f(9.9, 0, -7);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(6, 3, -7);
	glVertex3f(6, 3, -6);
	glVertex3f(6, 0, -6);
	glVertex3f(6, 0, -7);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(9.9, 3, -7);
	glVertex3f(9.9, 3, -6);
	glVertex3f(9.9, 0, -6);
	glVertex3f(9.9, 0, -7);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(6, 3, -6);
	glVertex3f(6, 0, -6);
	glVertex3f(9.9, 0, -6);
	glVertex3f(9.9, 3, -6);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(6, 3, -7);
	glVertex3f(6, 0, -7);
	glVertex3f(9.9, 0, -7);
	glVertex3f(9.9, 3, -7);
	glEnd();

	//seventh
	glBegin(GL_POLYGON);
	glVertex3f(6, 3, -2);
	glVertex3f(6, 3, -1);
	glVertex3f(9.9, 3, -1);
	glVertex3f(9.9, 3, -2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(6, 0, -2);
	glVertex3f(6, 0, -1);
	glVertex3f(9.9, 0, -1);
	glVertex3f(9.9, 0, -2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(6, 3, -2);
	glVertex3f(6, 3, -1);
	glVertex3f(6, 0, -1);
	glVertex3f(6, 0, -2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(9.9, 3, -2);
	glVertex3f(9.9, 3, -1);
	glVertex3f(9.9, 0, -1);
	glVertex3f(9.9, 0, -2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(6, 3, -2);
	glVertex3f(6, 0, -1);
	glVertex3f(9.9, 0, -1);
	glVertex3f(9.9, 3, -2);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(6, 3, -2);
	glVertex3f(6, 0, -2);
	glVertex3f(9.9, 0, -2);
	glVertex3f(9.9, 3, -2);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[TABLE]);
	//first
	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(1, 3, -9.9);
	glTexCoord2f(0., 0.);	glVertex3f(1, 3, -7);
	glTexCoord2f(0., 1.);	glVertex3f(5, 3, -7);
	glTexCoord2f(1., 1.);	glVertex3f(5, 3, -9.9);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(1, 0, -9.9);
	glTexCoord2f(0., 0.);	glVertex3f(1, 0, -7);
	glTexCoord2f(0., 1.);	glVertex3f(5, 0, -7);
	glTexCoord2f(1., 1.);	glVertex3f(5, 0, -9.9);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(1, 3, -9.9);
	glTexCoord2f(0., 0.);	glVertex3f(1, 3, -7);
	glTexCoord2f(0., 1.);	glVertex3f(1, 0, -7);
	glTexCoord2f(1., 1.);	glVertex3f(1, 0, -9.9);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(5, 3, -9.9);
	glTexCoord2f(0., 0.);	glVertex3f(5, 3, -7);
	glTexCoord2f(0., 1.);	glVertex3f(5, 0, -7);
	glTexCoord2f(1., 1.);	glVertex3f(5, 0, -9.9);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(1, 3, -9.9);
	glTexCoord2f(0., 0.);	glVertex3f(1, 0, -9.9);
	glTexCoord2f(0., 1.);	glVertex3f(5, 0, -9.9);
	glTexCoord2f(1., 1.);	glVertex3f(5, 3, -9.9);
	glEnd();
	//second(6,10)
	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(6, 3, -9.9);
	glTexCoord2f(0., 0.);	glVertex3f(6, 3, -7);
	glTexCoord2f(0., 1.);	glVertex3f(9.9, 3, -7);
	glTexCoord2f(1., 1.);	glVertex3f(9.9, 3, -9.9);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(6, 3, -9.9);
	glTexCoord2f(0., 0.);	glVertex3f(6, 3, -7);
	glTexCoord2f(0., 1.);	glVertex3f(9.9, 3, -7);
	glTexCoord2f(1., 1.);	glVertex3f(9.9, 3, -9.9);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(6, 0, -9.9);
	glTexCoord2f(0., 0.);	glVertex3f(6, 0, -7);
	glTexCoord2f(0., 1.);	glVertex3f(9.9, 0, -7);
	glTexCoord2f(1., 1.);	glVertex3f(9.9, 0, -9.9);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(6, 3, -9.9);
	glTexCoord2f(0., 0.);	glVertex3f(6, 3, -7);
	glTexCoord2f(0., 1.);	glVertex3f(6, 0, -7);
	glTexCoord2f(1., 1.);	glVertex3f(6, 0, -9.9);
	glEnd();  glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(9.9, 3, -9.9);
	glTexCoord2f(0., 0.);	glVertex3f(9.9, 3, -7);
	glTexCoord2f(0., 1.);	glVertex3f(9.9, 0, -7);
	glTexCoord2f(1., 1.);	glVertex3f(9.9, 0, -9.9);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(6, 3, -7);
	glTexCoord2f(0., 0.);	glVertex3f(6, 0, -7);
	glTexCoord2f(0., 1.);	glVertex3f(9.9, 0, -7);
	glTexCoord2f(1., 1.);	glVertex3f(9.9, 3, -7);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(6, 3, -6);
	glTexCoord2f(0., 0.);	glVertex3f(6, 3, -2);
	glTexCoord2f(0., 1.);	glVertex3f(9.9, 3, -2);
	glTexCoord2f(1., 1.);	glVertex3f(9.9, 3, -6);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(6, 0, -6);
	glTexCoord2f(0., 0.);	glVertex3f(6, 0, -2);
	glTexCoord2f(0., 1.);	glVertex3f(9.9, 0, -2);
	glTexCoord2f(1., 1.);	glVertex3f(9.9, 0, -6);
	glEnd();


	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(9.9, 3, -6);
	glTexCoord2f(0., 0.);	glVertex3f(9.9, 3, -2);
	glTexCoord2f(0., 1.);	glVertex3f(9.9, 0, -2);
	glTexCoord2f(1., 1.);	glVertex3f(9.9, 0, -6);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(6, 3, -2);
	glTexCoord2f(0., 0.);	glVertex3f(6, 0, -2);
	glTexCoord2f(0., 1.);	glVertex3f(9.9, 0, -2);
	glTexCoord2f(1., 1.);	glVertex3f(9.9, 3, -2);
	glEnd();


	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(6, 3, -6);
	glTexCoord2f(0., 0.);	glVertex3f(6, 0, -6);
	glTexCoord2f(0., 1.);	glVertex3f(9.9, 0, -6);
	glTexCoord2f(1., 1.);	glVertex3f(9.9, 3, -6);
	glEnd();



	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, textures[DRAWERS]);
	//first(1,5)

	glBegin(GL_POLYGON);
	glTexCoord2f(0., 1.);	glVertex3f(1, 3, -7);
	glTexCoord2f(0., 0.);	glVertex3f(1, 0, -7);
	glTexCoord2f(1., 0.);	glVertex3f(5, 0, -7);
	glTexCoord2f(1., 1.);	glVertex3f(5, 3, -7);
	glEnd();

	//third
	glBegin(GL_POLYGON);
	glTexCoord2f(1., 0.);	glVertex3f(6, 3, -6);
	glTexCoord2f(0., 0.);	glVertex3f(6, 3, -2);
	glTexCoord2f(0., 1.);	glVertex3f(6, 0, -2);
	glTexCoord2f(1., 1.);	glVertex3f(6, 0, -6);
	glEnd();



	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

}

#endif ENV_TABLE