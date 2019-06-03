#ifndef CPU_CABLE
#define CPU_CABLE

#include <GL/glut.h>

class cable {
		bool visible = true;
		void draw_sata(); 
		void draw_cpu_power();
		void desktop_power_cable();
public: void render();
};

void cable::desktop_power_cable() {
	
	glPushMatrix();
	glTranslatef(3.45, 2.8, -8.8);
	glColor3f(0.05, 0.05, 0.05);
	glLineWidth(8.0);
	glBegin(GL_LINES);
	glVertex3f(0., 1., 0.);
	glVertex3f(0., 0., 0.);
	glEnd();
	glPopMatrix();
}

void cable::draw_cpu_power() {
	glPushMatrix();
	glTranslatef(7.35, 2.6, -5.2);
	glRotatef(90., 0., 1., 0.);
	glScalef(.3, 0.5, .6);
	glColor3f(0.05, 0.05, 0.05);
	glLineWidth(8.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 90; i = i + 5) {
		glVertex3f((GLfloat)i / 180. * 3., cos(rad(i)) * 2., -0.01);
	}
	glEnd();
	glPopMatrix();
}

void cable::render() {
	if (enterPressed && objIndex == REMOVE_HDD)
		visible = assemble ? true : false;
	if (!visible) return;
	glPushMatrix();
	draw_sata();
	draw_cpu_power();
	desktop_power_cable();
	glPopMatrix();
}

void cable::draw_sata() {

	glPushMatrix();
	glTranslatef(7.95, 4.2, -4.015);
	glRotatef(-90., 0., 1., 0.);
	glScalef(.2, 0.34, .6);
	// SATA Cable
	/// Middle Part
	glColor3f(.56, 0.2, 0.2);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= 180; i = i + 5) {
		glVertex3f((GLfloat)i / 180. * 2., cos(rad(i)), -0.01);
		glVertex3f((GLfloat)i / 180. * 2 + 0.05, cos(rad(i)) + .05, -0.);
	}
	glEnd();

	/// TOP LEFT Ends
	glColor3f(0., 0., 0.);
	glBegin(GL_POLYGON);
	glVertex3f(-0.01, 0.99, 0.);
	glVertex3f(0.06, 0.99, 0.);
	glVertex3f(0.06, 1.06, 0.);
	glVertex3f(-0.01, 1.06, 0.);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.01, 0.99, -0.03);
	glVertex3f(0.06, 0.99, -0.03);
	glVertex3f(0.06, 1.06, -0.03);
	glVertex3f(-0.01, 1.06, -0.03);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.01, 0.99, 0.);
	glVertex3f(-0.01, 0.99, -0.03);
	glVertex3f(-0.01, 1.06, -0.03);
	glVertex3f(-0.01, 1.06, 0.);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.01, 0.99, 0.);
	glVertex3f(-0.01, 0.99, -0.03);
	glVertex3f(-0.01, 1.06, -0.03);
	glVertex3f(-0.01, 1.06, 0.);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.01, 0.99, 0.);
	glVertex3f(0.06, 0.99, 0.);
	glVertex3f(0.06, 0.99, -0.03);
	glVertex3f(-0.01, 0.99, -0.03);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.01, 1.06, 0.);
	glVertex3f(0.06, 1.06, 0.);
	glVertex3f(0.06, 1.06, -0.03);
	glVertex3f(-0.01, 1.06, -0.03);
	glEnd();

	/// TOP RIGHT End R
	glColor3f(0., 0., 0.);
	glBegin(GL_POLYGON);
	glVertex3f(1.99, -1.01, 0.);
	glVertex3f(2.06, -1.01, 0.);
	glVertex3f(2.06, -0.94, 0.);
	glVertex3f(1.99, -0.94, 0.);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(1.99, -1.01, -0.03);
	glVertex3f(2.06, -1.01, -0.03);
	glVertex3f(2.06, -0.94, -0.03);
	glVertex3f(1.99, -0.94, -0.03);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(1.99, -1.01, 0.);
	glVertex3f(1.99, -1.01, -0.03);
	glVertex3f(1.99, -0.94, -0.03);
	glVertex3f(1.99, -0.94, 0.);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(1.99, -1.01, 0.);
	glVertex3f(1.99, -1.01, -0.03);
	glVertex3f(1.99, -0.94, -0.03);
	glVertex3f(1.99, -0.94, 0.);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(1.99, -1.01, 0.);
	glVertex3f(2.06, -1.01, 0.);
	glVertex3f(2.06, -1.01, -0.03);
	glVertex3f(1.99, -1.01, -0.03);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(1.99, -0.94, 0.);
	glVertex3f(2.06, -0.94, 0.);
	glVertex3f(2.06, -0.94, -0.03);
	glVertex3f(1.99, -0.94, -0.03);
	glEnd();
	glPopMatrix();
}
#endif CPU_CABLE