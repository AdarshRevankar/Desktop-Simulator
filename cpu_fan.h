#ifndef CPU_FAN
#define CPU_FAN
#include "parameter.h"
#include "dragHandler.h"

class  cpu_fan {
private:GLfloat c_center[3] = { 0.0075, 0.0075, 0.0075};
		GLfloat c_meshCylinder[3] = { 0.0075, 0.0075, 0.0075 };
		GLfloat c_meshBlade[3] = { 0.015, 0.015, 0.015 };
		GLfloat c_rim[3] = { 0., 0., 0. };
		GLfloat c_blade[3] = { .0 , .0, .0 };
		GLfloat fan_spin_theta = 0, y_spin = 0;
		GLuint fan_no_blades = 6;
		int sides = 30;
		float rim_start = 0., rim_end = -0.9;
		float mesh_start = rim_end - 0.05, mesh_end = mesh_start - 3.;
		int meshCount = 50;
		GLfloat v_blade[30][3] = { {0.5, 0., -0.6},
							{4.05, 0.9, 0.},
							{4.9, 2., 0.},
							{5.5, 3., 0.},
							{6.15, 4., 0.},
							{6.73, 5., 0.},
							{7.23, 6., 0.},
							{7.55, 7., 0.},
							{8.1, 8., 0.},
							{8.5, 9., 0.},
							{8.8, 10., 0.},
							{9.1, 11., 0.},
							{9.28, 12., -0.1},
							{9.47, 13., -0.15},
							{9.51, 14., -0.2},
							{9.4, 15., -0.25},
							{9., 15.8, -0.3},
							{8., 16.72, -0.35},
							{7., 17.3, -0.4},
							{6., 17.60, -0.45},
							{5., 17.70, -0.5},
							{4., 17.57, -0.55},
							{3., 17.4, -0.6},
							{2., 16.46, -0.65},
							{1.3, 16., -0.7},
							{1., 15.46, -0.75},
							{0.5, 15., -0.8},
							{0.15, 14., -0.85},
							{0.123, 13., -0.9},
							{0.12, 12., -0.95} };
		point3D move;
		GLfloat viewTheta = 0.;

		bool visible = true;
		bool objMove = false;

		void draw_fan_blades();
		void draw_fan_center();
		void draw_fan_rim();
		void draw_cooler_grills();
		void showDescrpiton();
		void motionHandle();
public: void render();
};

void cpu_fan::showDescrpiton() {
	GLfloat diff = 1.5;

	glPushMatrix();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	//	Transperent Glass Frame
	glColor4f(0., 0., 0., .7);
	glBegin(GL_POLYGON);
		glVertex3f(-10., -10., objLoc.z - diff);
		glVertex3f(-10., 10., objLoc.z - diff);
		glVertex3f(10., 10., objLoc.z - diff);
		glVertex3f(10., -10., objLoc.z - diff);
	glEnd();	
	glPopMatrix();
}

void cpu_fan::motionHandle() {

	if (((enterPressed && objIndex == REMOVE_FAN) || objMove == true) && !assemble)
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
	else if (((enterPressed && objIndex == REMOVE_FAN-1) || objMove == true) && assemble)
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

void cpu_fan::render() {
	motionHandle();
	if (!visible) return;
	glPushMatrix();
	glTranslatef(move.x, move.y, move.z);
	glRotatef(viewTheta, 0., 1., 0.);
	glColor3f(.001, 0.001, .001);
	glTranslatef(-0.974, .52, -0.745);
	glTranslatef(8.72, 4.321, -3.821);
	/// Remove this to stop rotate
	//glRotatef(y_spin * 0.5, 0., 1., 0.); //Rotate whole on Y axis
	//y_spin += 2.;
	//if (y_spin >= 720.) y_spin = 0;
	glRotatef(-90., 0., 1., 0.);
	glScalef(0.009375, 0.009375, 0.046875);
	draw_fan_blades();
	draw_fan_center();
	draw_fan_rim();
	draw_cooler_grills();
	glPopMatrix();
}

void cpu_fan::draw_fan_blades() {
	/*	This produces blades.
		Number of blades = 'fan_no_blades'
		Co-ordinates are given in class 'v_blade'
		'fan_spin_theta' - incremented for rotation for blades.
	*/
	glPushMatrix();
	glRotatef(fan_spin_theta, 0, 0, 1);
	for (int i = 0; i < fan_no_blades; i++) {
		glPushMatrix();
		glColor3fv(c_blade);
		glRotatef(i * 360.0 / (float)fan_no_blades, 0.0, 0.0, 1.);
		glBegin(GL_POLYGON);
		for (int j = 0; j < 30; j++)
			glVertex3fv(v_blade[j]);
		glEnd();
		glPopMatrix();
	}
	fan_spin_theta += deltaTime * 0.1;
	if (fan_spin_theta >= 360)
		fan_spin_theta = 0;
	glPopMatrix();

}

void cpu_fan::draw_fan_center() {
	/*	Draws the center cylinder of fan
		Draws circle using 'GL_TRIANGLE_FAN' using sin() & cos() function
		Draws multiple circles one behind another
	*/
	glPushMatrix();
	//For the width of cylinder
	float centerScale = 4;
	glPushMatrix();
	glRotatef(fan_spin_theta, 0, 0, 1);
	//Center Front Circle
	glColor3fv(c_center);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0., 0., rim_start);
	for (int i = 0; i <= sides; i++)
		glVertex3f(sin(rad(i * 360 / sides)) * centerScale, cos(rad(i * 360 / sides)) * centerScale, rim_start);
	glEnd();

	
	float diff = 1.2;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[FAN_LOGO]);
	glColor3f(1., 1., 1.);
	glBegin(GL_POLYGON);
		glTexCoord2i(1, 1);		glVertex3f(centerScale - diff, centerScale - diff, 0.01);
		glTexCoord2i(1, 0);		glVertex3f(centerScale - diff, -centerScale+ diff, 0.01);
		glTexCoord2i(0, 0);		glVertex3f(-centerScale + diff, -centerScale + diff, 0.01);
		glTexCoord2i(0, 1);		glVertex3f(-centerScale + diff, centerScale - diff, 0.01);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Center Rear Circle
	glColor3fv(c_center);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0., 0., rim_end);
	for (int i = 0; i <= sides; i++)
		glVertex3f(sin(rad(i * 360 / sides)) * centerScale, cos(rad(i * 360 / sides)) * centerScale, rim_end);
	glEnd();

	//Center Cover
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= sides; i++) {
		glVertex3f(sin(rad(i * 360 / sides)) * centerScale, cos(rad(i * 360 / sides)) * centerScale, rim_start);
		glVertex3f(sin(rad(i * 360 / sides)) * centerScale, cos(rad(i * 360 / sides)) * centerScale, rim_end);
	}
	glEnd();
	glPopMatrix();

	//Center Rear Props
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	float prop_thickness = 0.8;
	for (int i = 0; i < 4; i++) {
		glRotatef(i * 90, 0., 0., 1.);
		glBegin(GL_POLYGON);
		glVertex3f(-prop_thickness, 0., rim_end + 0.1);
		glVertex3f(prop_thickness, 0., rim_end + 0.1);
		glVertex3f(prop_thickness, 19., rim_end + 0.1);
		glVertex3f(-prop_thickness, 19., rim_end + 0.1);
		glEnd();
	}
	glPopMatrix();
}

void cpu_fan::draw_fan_rim() {
	/*	Draws fan rim to hold and fit the fan
		Also the cylinder to fit the 'Screws'
	*/
	glPushMatrix();
	glLineWidth(4.0);

	/*Inner circle*/
	glColor3fv(c_rim);
	float rimScale = 19.;
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < sides; i++) {
		glVertex3f(sin(rad(i * 360 / sides)) * rimScale, cos(rad(i * 360 / sides)) * rimScale, rim_start);
		glVertex3f(sin(rad(i * 360 / sides)) * rimScale, cos(rad(i * 360 / sides)) * rimScale, rim_end);
	}
	glEnd();

	/*Outer circle*/
	rimScale = 19.8;		///This is more for outer one
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= sides; i++) {
		glVertex3f(sin(rad(i * 360 / sides)) * rimScale, cos(rad(i * 360 / sides)) * rimScale, rim_start);
		glVertex3f(sin(rad(i * 360 / sides)) * rimScale, cos(rad(i * 360 / sides)) * rimScale, rim_end);
	}
	glEnd();

	/*Front and Back Plates*/
	float rimScale_out = 19.8, rimScale_in = 19.;		///This is more for outer one
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= sides; i++) {
		glVertex3f(sin(rad(i * 360 / sides)) * rimScale_out, cos(rad(i * 360 / sides)) * rimScale_out, rim_start);
		glVertex3f(sin(rad(i * 360 / sides)) * rimScale_in, cos(rad(i * 360 / sides)) * rimScale_in, rim_start);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= sides; i++) {
		glVertex3f(sin(rad(i * 360 / sides)) * rimScale_out, cos(rad(i * 360 / sides)) * rimScale_out, rim_end);
		glVertex3f(sin(rad(i * 360 / sides)) * rimScale_in, cos(rad(i * 360 / sides)) * rimScale_in, rim_end);
	}
	glEnd();


	/*Screw Holder*/
	glPushMatrix();
	glColor3f(0., 0., 0.);
	float screw_x = 0.03, screw_y = 2.;
	for (int k = 0; k < 4; k++) {
		glRotatef(90 * k, 0., 0., 1.);
		//Front Face of screw holder
		glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i <= 180; i = i + 10) {
			glVertex3f(i * screw_x - 90. * screw_x, screw_y * sin(rad(i)) + rimScale_in + 0.05, rim_start - 0.2);
		}
		glEnd();
		//Back Face of screw holder
		glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i <= 180; i = i + 10) {
			glVertex3f(i * screw_x - 90. * screw_x, screw_y * sin(rad(i)) + rimScale_in + 0.05, rim_end);
		}
		glEnd();
		//Outer Cover of screw holder
		glBegin(GL_QUAD_STRIP);
		for (int i = 0; i <= 180; i = i + 10) {
			glVertex3f(i * screw_x - 90. * screw_x, sin(rad(i)) * screw_y + rimScale_in + 0.05, rim_start - 0.2);
			glVertex3f(i * screw_x - 90. * screw_x, sin(rad(i)) * screw_y + rimScale_in + 0.05, rim_end + 0.01);
		}
		glEnd();
	}

	/* 4. SCREW */
	for (int k = 0; k < 4; k++) {
		glRotatef(90 * k, 0., 0., 1.);
		//Front Face of screw 
		glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i <= 270; i = i + 10) {
			///Sine function ie. y = cos(x) is used.
			glVertex3f(i * screw_x * cos(rad(i)) + 2, screw_y * sin(rad(i)) + rimScale_in + 0.05, mesh_start);
		}
		glEnd();
		//Back Face of Screw
		glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i <= 270; i = i + 10) {
			glVertex3f(i * screw_x * cos(rad(i)) + 2, screw_y * sin(rad(i)) + rimScale_in + 0.05, mesh_end);
		}
		glEnd();
		//Outer Cover of Screw
		glBegin(GL_QUAD_STRIP);
		for (int i = 0; i <= 270; i = i + 10) {
			glVertex3f(i * screw_x * cos(rad(i)) + 2, sin(rad(i)) * screw_y + rimScale_in + 0.05, mesh_start);
			glVertex3f(i * screw_x * cos(rad(i)) + 2, sin(rad(i)) * screw_y + rimScale_in + 0.05, mesh_end);
		}
		glEnd();
	}

	glPopMatrix();
}

void cpu_fan::draw_cooler_grills() {
	//Mesh that cooles the cpu

	/* 1. MESH CYLINDER */
	glPushMatrix();

	float meshCylinderScale = 10.;

	//Mesh Cylinder Front Circle 
	glColor3fv(c_meshCylinder);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0., 0., mesh_start + 0.1);
	for (int i = 0; i <= sides; i++)
		glVertex3f(sin(rad(i * 360 / sides)) * meshCylinderScale, cos(rad(i * 360 / sides)) * meshCylinderScale, mesh_start + 0.1);
	glEnd();

	//Mesh Cylinder Rear Circle
	glColor3fv(c_meshCylinder);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0., 0., mesh_end - 0.1);
	for (int i = 0; i <= sides; i++)
		glVertex3f(sin(rad(i * 360 / sides)) * meshCylinderScale, cos(rad(i * 360 / sides)) * meshCylinderScale, mesh_end - 0.1);
	glEnd();

	//Mesh Cylinder Cover
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= sides; i++) {
		glVertex3f(sin(rad(i * 360 / sides)) * meshCylinderScale, cos(rad(i * 360 / sides)) * meshCylinderScale, mesh_start + 0.1);
		glVertex3f(sin(rad(i * 360 / sides)) * meshCylinderScale, cos(rad(i * 360 / sides)) * meshCylinderScale, mesh_end - 0.1);
	}
	glEnd();

	/*-------------------------------------------------------*/
	/* 2. MESH WINGS */
	float meshWingScale_x = 3.;
	float meshWingScale_y = 19.;

	float val = 15;
	glPushMatrix();
	glColor3fv(c_meshBlade);
	for (int i = 0; i < meshCount; i++) {
		glPushMatrix();
		glRotatef(i * 360 / meshCount, 0., 0., 1.);
		glBegin(GL_QUAD_STRIP);
		for (float y = 0; y <= 180; y = y + 10) {
			///Here the x = A. sin(y) function is used
			glVertex3f(sin(rad(y)) * meshWingScale_x, y / 180 * meshWingScale_y, mesh_start);
			glVertex3f(sin(rad(y)) * meshWingScale_x, y / 180 * meshWingScale_y, mesh_end);
		}
		glEnd();
		glPopMatrix();
	}
	glPopMatrix();

}

#endif CPU_FAN