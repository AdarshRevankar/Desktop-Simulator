#ifndef BITMAP  
#define BITMAP

#include <GL/glut.h>

void* times10 = GLUT_BITMAP_TIMES_ROMAN_10;
void* helv18 = GLUT_BITMAP_HELVETICA_18;
void* helv12 = GLUT_BITMAP_HELVETICA_12;

float prog;

void renderBitmapString(
	float x,
	float y,
	float z,
	void* font,
	char* string) {

	char* c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void front_page()
{
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0., 3.5, 0.);
	renderBitmapString(-3.4f, 3.0f, -0.1f, (void*)helv18, (char*)"MANGALORE INSTITUTE OF TECHNOLOGY AND ENGINEERING, MOODABIDRI");
	renderBitmapString(-2.6f, 2.6f, -0.1f, (void*)helv18, (char*)"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	renderBitmapString(-0.6f, 2.3f, -0.1f, (void*)helv12, (char*)"A MINI PROJECT ON");
	renderBitmapString(-2.85f, 2.0f, -0.1f, (void*)helv18, (char*)"GRAPHICAL SIMULATION OF DESKTOP AND ITS COMPONENTS");

	renderBitmapString(-1.5f, 1.5f, -0.1f, (void*)times10, (char*)"BY:");
	renderBitmapString(-2.4f, 1.3f, -0.1f, (void*)helv12, (char*)"ADARSH REVANKAR   4MT16CS003");
	renderBitmapString(-2.4f, 1.1f, -0.1f, (void*)helv12, (char*)"AKSHAYA M.              4MT16CS007");

	renderBitmapString(1.2f, 1.5f, -0.1f, (void*)times10, (char*)"GUIDS:");
	renderBitmapString(0.7f, 1.3f, -0.1f, (void*)helv12, (char*)"Mr. PRASHANTH B.S.");
	renderBitmapString(0.7f, 1.1f, -0.1f, (void*)helv12, (char*)"Ms. SHARANYA BABU");

	glPopMatrix();
}

void progress_wheel(void)
{
	double i;
	glPushMatrix();
	glTranslatef(0., 3.5, 0.);
	if (prog > 6.284f)
		prog = 0.0f;
	prog += 0.015f;
	glPointSize(5.0);
	glBegin(GL_POINTS);
	for (i = 0; i < prog; i = i + 0.08f) {
		glColor3f( GLfloat(i / 6.284f), 0.0f, 0.0f);
		glVertex3f( GLfloat(sin(i) * 0.2f), GLfloat(0.45f + cos(i) * 0.2f), -0.1f);
	}
	glEnd();

	renderBitmapString(-0.24f, 0.0f, -0.1f, (void*)helv12, (char*)"Loading...");
	glColor3f(1.0, 1.0, 1.0);
	renderBitmapString(-0.68f, -0.4f, -0.2f, (void*)helv12, (char*)"Press ENTER to continue...");

	glPopMatrix();
}

#endif BITMAP