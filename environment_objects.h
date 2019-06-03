#ifndef ENV_COUCH
#define ENV_COUCH

#include "parameter.h"
#include <math.h>

class env {
	GLfloat stdHight = 2.4f, stdThickness = .1f, stdWidth = .15;	/// Stand Parameters
	void desktop();
	void keyboard();
public:void render();
};

void env::keyboard() {
	glPushMatrix();
	glTranslatef(3.3, 2.2, -7.);
	glColor3f(1., 1., 1.);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[KEYBOARD]);
	glBegin(GL_POLYGON);
		glTexCoord2f(0., 0.);	glVertex3f(-1., .95, 0.);
		glTexCoord2f(0., 1.);	glVertex3f(-1., 1., -0.7);
		glTexCoord2f(1., 1.);	glVertex3f(1., 1., -0.7);
		glTexCoord2f(1., 0.);	glVertex3f(1., .95, 0.);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_POLYGON);
		glVertex3f(-1., 0.9, 0.);
		glVertex3f(-1., 0.9, -0.7);
		glVertex3f(1., 0.9, -0.7);
		glVertex3f(1., 0.9, 0.);
	glEnd();

	glBegin(GL_QUAD_STRIP);
		glVertex3f(-1., .95, 0.);
		glVertex3f(-1., 0.9, 0.);

		glVertex3f(-1., 1., -0.7);
		glVertex3f(-1., 0.9, -0.7);

		glVertex3f(1., 1., -0.7);
		glVertex3f(1., 0.9, -0.7);

		glVertex3f(1., .95, 0.);
		glVertex3f(1., 0.9, 0.);

		glVertex3f(-1., .95, 0.);
		glVertex3f(-1., 0.9, 0.);
	glEnd();

	glPopMatrix();
}

void env::desktop() {

	glPushMatrix();
	glTranslatef(0., 2.6, -7.7);
	glColor3f(1., 1., 1.);
	// Screen
	/// Flat Screen
	glEnable(GL_TEXTURE_2D);
	if (objIndex < REMOVE_RAM_STICK)
		glBindTexture(GL_TEXTURE_2D, DESK_WALLPAPER);
	else
		glBindTexture(GL_TEXTURE_2D, DESK_WALLPAPER_BLANK);
	
	GLfloat monXmax = 135. / 180. * 6.5, monXmin = 45. / 180. * 6.5;
	glBegin(GL_POLYGON);
	glTexCoord2i(0, 0);	glVertex3f(monXmin, 1., -sin(rad(45)));
	glTexCoord2i(1, 0); glVertex3f(monXmax, 1., -sin(rad(45)));
	glTexCoord2i(1, 1); glVertex3f(monXmax, 2.5, -sin(rad(45)));
	glTexCoord2i(0, 1); glVertex3f(monXmin, 2.5, -sin(rad(45)));
	glEnd();

	glDisable(GL_TEXTURE_2D);

	/// Curve Behind
	glColor3f(0., 0., 0.);
	glBegin(GL_QUAD_STRIP);
	for (int i = 45; i <= 135; i = i + 1)
	{	
		glVertex3f(i/180. * 6.5, 1.,-sin(rad(i)));
		glVertex3f(i/180. * 6.5, 2.5,-sin(rad(i)));
	}
	glEnd();

	/// Bottom edge Screen
	glColor3f(0., 0., 0.);
	glBegin(GL_QUAD_STRIP);
	for (int i = 45; i <= 135; i = i + 1)
	{
		glVertex3f(i / 180. * 6.5, 1., -sin(rad(45)));
		glVertex3f(i / 180. * 6.5, 1., -sin(rad(i)));
	}
	glEnd();
	
	/// Top edge Screen
	glColor3f(0., 0., 0.);
	glBegin(GL_QUAD_STRIP);
	for (int i = 45; i <= 135; i = i + 1)
	{
		glVertex3f(i / 180. * 6.5, 2.5, -sin(rad(45)));
		glVertex3f(i / 180. * 6.5, 2.5, -sin(rad(i)));
	}
	glEnd();
	
	// Stand
	/// Front Face
	glBegin(GL_POLYGON);
		glVertex3f(3.25 - stdWidth, 0., -1.);
		glVertex3f(3.25 + stdWidth, 0., -1.);
		glVertex3f(3.25 + stdWidth, stdHight, -1.);
		glVertex3f(3.25 - stdWidth, stdHight, -1.);
	glEnd();

	/// Back face
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex3f(3.25 - stdWidth , 0., -1. - stdThickness);
	glVertex3f(3.25 + stdWidth, 0., -1. - stdThickness);
	glVertex3f(3.25 + stdWidth, stdHight, -1. - stdThickness);
	glVertex3f(3.25 - stdWidth, stdHight, -1. - stdThickness);
	glEnd();

	/// Left Side face
	glBegin(GL_POLYGON);
	glVertex3f(3.25 - stdWidth, 0., -1.);
	glVertex3f(3.25 - stdWidth, 1., -1.);
	glVertex3f(3.25 - stdWidth, 1., -1. - stdThickness);
	glVertex3f(3.25 - stdWidth, 0., -1. - stdThickness);
	glEnd();

	/// Right Side face
	glBegin(GL_POLYGON);
	glVertex3f(3.25 + stdWidth, 0., -1.);
	glVertex3f(3.25 + stdWidth, stdHight, -1.);
	glVertex3f(3.25 + stdWidth, stdHight, -1. - stdThickness);
	glVertex3f(3.25 + stdWidth, 0., -1. - stdThickness);
	glEnd();
	
	/// Bottom Surface
	glPushMatrix();
	glColor3f(0.05, 0.05, 0.05);
	glTranslatef(1.5, 0., 0.15);
	glBegin(GL_QUAD_STRIP);
	for (int i = 45; i <= 135; i = i + 1)
	{
		glVertex3f(i / 180. * 3.5, .42, -sin(rad(i)));
		glVertex3f(i / 180. * 3.5, .42, -1.5*sin(rad(i)));
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void env::render() {

	glPushMatrix();

	desktop();
	keyboard();
	//back face
	glBegin(GL_POLYGON);
	glVertex3f(-9.9, 1.5, 8);
	glVertex3f(-9.9, 0.3, 8);
	glVertex3f(-9.9, 0.3, 4);
	glVertex3f(-9.9, 1.5, 4);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1, 1);
	glBindTexture(GL_TEXTURE_2D, textures[COUCH_SEAT]);

	glBegin(GL_POLYGON);
	glTexCoord2f(1., 1.);	glVertex3f(-8.2, 1.5, 8);
	glTexCoord2f(1., 0.);	glVertex3f(-8.2, 0.3, 8);
	glTexCoord2f(0., 0.);	 glVertex3f(-8.2, 0.3, 4);
	glTexCoord2f(0., 1.);    glVertex3f(-8.2, 1.5, 4);




	glEnd();
	//

	  // glDisable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
	glVertex3f(-9.9, 1.5, 8);
	glVertex3f(-8.2, 1.5, 8);
	glVertex3f(-8.2, 0.3, 8);
	glVertex3f(-9.9, 0.3, 8);
	glEnd();

	(1., 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-9.9, 1.5, 4);
	glVertex3f(-8.2, 1.5, 4);
	glVertex3f(-8.2, 0.3, 4);
	glVertex3f(-9.9, 0.3, 4);
	glEnd();
	//      glColor3f(0., 1, 1);

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[COUCH_PILLOW]);

	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.);	 glVertex3f(-9.9, 1.5, 8);
	glTexCoord2f(0., 1.);	glVertex3f(-8.2, 1.5, 8);
	glTexCoord2f(1., 1.);	 glVertex3f(-8.2, 1.5, 4);
	glTexCoord2f(1., 0.);   glVertex3f(-9.9, 1.5, 4);




	glEnd();
	glDisable(GL_TEXTURE_2D);
	//glColor3f(1., 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-9.9, 0.3, 8);
	glVertex3f(-8.2, 0.3, 8);
	glVertex3f(-8.2, 0.3, 4);
	glVertex3f(-9.9, 0.3, 4);
	glEnd();

	//pillow


	glBegin(GL_POLYGON);
	glVertex3f(-9.9, 2.2, 8);
	glVertex3f(-9.9, 1.5, 8);
	glVertex3f(-9.9, 1.5, 4);
	glVertex3f(-9.9, 2.2, 4);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[COUCH_PILLOW]);

	glBegin(GL_POLYGON);
	glTexCoord2f(1., 1.);	 glVertex3f(-9.2, 2.2, 8);
	glTexCoord2f(1., 0.);	 glVertex3f(-9.2, 1.5, 8);
	glTexCoord2f(0., 0.);	 glVertex3f(-9.2, 1.5, 4);
	glTexCoord2f(0., 1.);    glVertex3f(-9.2, 2.2, 4);



	glEnd();

	glDisable(GL_TEXTURE_2D);


	//SIDE LEFT
	//glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex3f(-9.9, 2.2, 8);
	glVertex3f(-8.2, 2.2, 8);
	glVertex3f(-8.2, 1.5, 8);
	glVertex3f(-9.9, 1.5, 8);
	glEnd();
	//SIDE RIGHT
	//glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(-9.9, 2.2, 4);
	glVertex3f(-8.2, 2.2, 4);
	glVertex3f(-8.2, 1.5, 4);
	glVertex3f(-9.9, 1.5, 4);
	glEnd();
	//TOP
	glBegin(GL_POLYGON);
	glVertex3f(-9.9, 2.2, 8);
	glVertex3f(-9.2, 2.2, 8);
	glVertex3f(-9.2, 2.2, 4);
	glVertex3f(-9.9, 2.2, 4);
	glEnd();
	//glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(-9.9, 1.5, 8);
	glVertex3f(-9.2, 1.5, 8);
	glVertex3f(-9.2, 1.5, 4);
	glVertex3f(-9.9, 1.5, 4);
	glEnd();

	//base
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-8.2, 0.3, 8);
	glVertex3f(-8.2, 0, 8);
	glVertex3f(-8.2, 0, 7.9);
	glVertex3f(-8.2, 0.3, 7.9);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-8.25, 0.3, 8);
	glVertex3f(-8.25, 0, 8);
	glVertex3f(-8.25, 0, 7.9);
	glVertex3f(-8.25, 0.3, 7.9);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-8.25, 0.3, 8);
	glVertex3f(-8.2, 0.3, 8);
	glVertex3f(-8.2, 0, 8);
	glVertex3f(-8.25, 0, 8);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-8.25, 0.3, 7.9);
	glVertex3f(-8.2, 0.3, 7.9);
	glVertex3f(-8.2, 0, 7.9);
	glVertex3f(-8.25, 0, 7.9);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-8.2, 0.3, 8);
	glVertex3f(-8.2, 0.3, 7.9);
	glVertex3f(-8.25, 0.3, 7.9);
	glVertex3f(-8.25, 0.3, 8);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-8.2, 0, 8);
	glVertex3f(-8.2, 0, 7.9);
	glVertex3f(-8.25, 0, 7.9);
	glVertex3f(-8.25, 0, 8);
	glEnd();

	//end base
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-8.2, 0.3, 4);
	glVertex3f(-8.2, 0, 4);
	glVertex3f(-8.2, 0, 4.1);
	glVertex3f(-8.2, 0.3, 4.1);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-8.25, 0.3, 4);
	glVertex3f(-8.25, 0, 4);
	glVertex3f(-8.25, 0, 4.1);
	glVertex3f(-8.25, 0.3, 4.1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-8.25, 0.3, 4);
	glVertex3f(-8.2, 0.3, 4);
	glVertex3f(-8.2, 0, 4);
	glVertex3f(-8.25, 0, 4);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-8.25, 0.3, 4.1);
	glVertex3f(-8.2, 0.3, 4.1);
	glVertex3f(-8.2, 0, 4.1);
	glVertex3f(-8.25, 0, 4.1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-8.2, 0.3, 4);
	glVertex3f(-8.2, 0.3, 4.1);
	glVertex3f(-8.25, 0.3, 4.1);
	glVertex3f(-8.25, 0.3, 4);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-8.2, 0, 4);
	glVertex3f(-8.2, 0, 4.1);
	glVertex3f(-8.25, 0, 4.1);
	glVertex3f(-8.25, 0, 4);
	glEnd();

	glPushMatrix();
	glTranslatef(0., 2., 0.);
	//tv
	//glColor3f(211/255,211/255,211/255);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[TV_FRONT]);

	glBegin(GL_POLYGON);
	glTexCoord2f(0., 0.); glVertex3f(9.5, 3, 1);
	glTexCoord2f(1., 0.); glVertex3f(9.5, 3, 6);
	glTexCoord2f(1., 1.); glVertex3f(9.5, 5, 6);
	glTexCoord2f(1., 0.); glVertex3f(9.5, 5, 1);
	glEnd();


	glDisable(GL_TEXTURE_2D);

	glColor3f(192 / 255, 192 / 255, 192 / 255);
	glBegin(GL_POLYGON);
	glVertex3f(9.95, 3, 2);
	glVertex3f(9.95, 3, 5);
	glVertex3f(9.95, 5, 5);
	glVertex3f(9.95, 5, 2);

	glEnd();

	// glColor3f(0,1,0);
   // glColor3f(211/255,211/255,211/255);
	glBegin(GL_POLYGON);
	glVertex3f(9.5, 3, 1);
	glVertex3f(9.5, 3, 6);
	glVertex3f(9.5, 5, 6);
	glVertex3f(9.5, 5, 1);
	glEnd();

	//  glColor3f(0,0,1);
	glBegin(GL_POLYGON);
	glVertex3f(9.95, 5, 2);
	glVertex3f(9.95, 3, 2);
	glVertex3f(9.5, 3, 1);
	glVertex3f(9.5, 5, 1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(9.95, 5, 5);
	glVertex3f(9.95, 3, 5);
	glVertex3f(9.5, 3, 6);
	glVertex3f(9.5, 5, 6);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(9.95, 5, 2);
	glVertex3f(9.95, 5, 5);
	glVertex3f(9.5, 5, 6);
	glVertex3f(9.5, 5, 1);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(9.95, 3, 2);
	glVertex3f(9.95, 3, 5);
	glVertex3f(9.5, 3, 6);
	glVertex3f(9.5, 3, 1);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	glBindTexture(GL_TEXTURE_2D, textures[PIC]);
	glBegin(GL_POLYGON);
	glTexCoord2f(1., 1.);	 glVertex3f(-9.95, 5, -3);
	glTexCoord2f(1., 0.);	 glVertex3f(-9.95, 5, 1);
	glTexCoord2f(0., 0.);	 glVertex3f(-9.95, 3, 1);
	glTexCoord2f(0., 1.);    glVertex3f(-9.95, 3, -3);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	

	//tv table
	glBegin(GL_POLYGON);
	glVertex3f(9.9, 1.5, 6);
	glVertex3f(9.9, 0.0, 6);
	glVertex3f(9.9, 0.0, 1);
	glVertex3f(9.9, 1.5, 1);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1, 1);
	glBindTexture(GL_TEXTURE_2D, textures[TV_TABLE]);

	glBegin(GL_POLYGON);
	glTexCoord2f(1., 1.);	glVertex3f(8.2, 1.5, 6);
	glTexCoord2f(1., 0.);	glVertex3f(8.2, 0.0, 6);
	glTexCoord2f(0., 0.);	 glVertex3f(8.2, 0.0, 1);
	glTexCoord2f(0., 1.);    glVertex3f(8.2, 1.5, 1);




	glEnd();
	glDisable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
	glVertex3f(9.9, 1.5, 6);
	glVertex3f(8.2, 1.5, 6);
	glVertex3f(8.2, 0.0, 6);
	glVertex3f(9.9, 0.0, 6);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(9.9, 1.5, 1);
	glVertex3f(8.2, 1.5, 1);
	glVertex3f(8.2, 0.0, 1);
	glVertex3f(9.9, 0.0, 1);
	glEnd();
	//      glColor3f(0., 1, 1);

		//   glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1., 1.);
	//glBindTexture(GL_TEXTURE_2D, textures[COUCH_PILLOW]);

	glBegin(GL_POLYGON);
	// glTexCoord2f(0.,0.);
	glVertex3f(9.9, 1.5, 6);
	// glTexCoord2f(0., 1.);
	glVertex3f(8.2, 1.5, 6);
	//glTexCoord2f(1., 1.);
	glVertex3f(8.2, 1.5, 1);
	//glTexCoord2f(1., 0.);
	glVertex3f(9.9, 1.5, 1);




	glEnd();
	glDisable(GL_TEXTURE_2D);
	//glColor3f(1., 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(9.9, 0.0, 6);
	glVertex3f(8.2, 0.0, 6);
	glVertex3f(8.2, 0.0, 1);
	glVertex3f(9.9, 0.0, 1);
	glEnd();



	//speaker
	glColor3f(0, 0, 0);

	glBegin(GL_POLYGON);
	glVertex3f(9.9, 2.9, 5);
	glVertex3f(9.9, 0.0, 5);
	glVertex3f(9.9, 0.0, 4.2);
	glVertex3f(9.9, 2.9, 4.2);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glColor3f(1., 1, 1);
	glBindTexture(GL_TEXTURE_2D, textures[SPEAKER]);

	glBegin(GL_POLYGON);
	glTexCoord2f(1., 1.);	glVertex3f(8.5, 2.9, 5);
	glTexCoord2f(1., 0.);	glVertex3f(8.5, 0.0, 5);
	glTexCoord2f(0., 0.);	 glVertex3f(8.5, 0.0, 4.2);
	glTexCoord2f(0., 1.);    glVertex3f(8.5, 2.9, 4.2);




	glEnd();
	glDisable(GL_TEXTURE_2D);

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(9.9, 2.9, 5);
	glVertex3f(8.5, 2.9, 5);
	glVertex3f(8.5, 0.0, 5);
	glVertex3f(9.9, 0.0, 5);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(9.9, 2.9, 4.2);
	glVertex3f(8.5, 2.9, 4.2);
	glVertex3f(8.5, 0.0, 4.2);
	glVertex3f(9.9, 0.0, 4.2);
	glEnd();
	//      glColor3f(0., 1, 1);

		//   glEnable(GL_TEXTURE_2D);

		//glBindTexture(GL_TEXTURE_2D, textures[COUCH_PILLOW]);

	glBegin(GL_POLYGON);
	// glTexCoord2f(0.,0.);
	glVertex3f(9.9, 2.9, 5);
	// glTexCoord2f(0., 1.);
	glVertex3f(8.5, 2.9, 5);
	//glTexCoord2f(1., 1.);
	glVertex3f(8.5, 2.9, 4.2);
	//glTexCoord2f(1., 0.);
	glVertex3f(9.9, 2.9, 4.2);




	glEnd();
	glDisable(GL_TEXTURE_2D);
	//glColor3f(1., 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(9.9, 0.0, 5);
	glVertex3f(8.5, 0.0, 5);
	glVertex3f(8.5, 0.0, 4.2);
	glVertex3f(9.9, 0.0, 4.2);
	glEnd();

	glPopMatrix();

}

#endif ENV_COUCH

