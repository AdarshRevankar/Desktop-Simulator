#ifndef MOTION
#define MOTION

#include "parameter.h"
#include "objects.h"


int prev_x = 0, prev_y = 0;
bool escape_pressed = false;
bool reposition = false;

void processSpecialKeys(int key, int xx, int yy)
{
	float fraction = 0.001f;
	float fraction_rotate = 0.001f;
	
	if (!motion_present)
		return;
	switch (key) {
	case GLUT_KEY_LEFT:
		x -= cos(angle) * deltaTime * fraction;
		z -= sin(angle) * deltaTime * fraction;
		break;
	case GLUT_KEY_RIGHT:
		x += cos(angle) * deltaTime * fraction;
		z += sin(angle) * deltaTime * fraction;

		break;
	case GLUT_KEY_UP:

		x += lx * deltaTime * fraction;
		z += lz * deltaTime * fraction;

		break;
	case GLUT_KEY_DOWN:
		x -= lx * deltaTime * fraction;
		z -= lz * deltaTime * fraction;

		break;
	case GLUT_KEY_HOME:
		angle -= deltaTime * fraction_rotate;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_END:
		angle += deltaTime * fraction_rotate;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_PAGE_UP:
		y < 1.4f ? y += deltaTime * fraction_rotate * 0.5 : y = 1.4f;
		break;
	case GLUT_KEY_PAGE_DOWN:
		y > -0.8f ? y -= deltaTime * fraction_rotate * 0.5 : y = -0.8f;
		break;
	}
}

void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key) {
	case 13:if (page == 0) 
				motion_present = true;
			if (page == 1) {
				enterPressed = true;
				assemble = false;
				objIndex > REMOVE_MOTHERBOARD? objIndex:objIndex++;
			}
			 page = 1;			 
			 break;
	case 8:if (page == 1) {
			enterPressed = true;
			assemble = true;
			objIndex < -1 ? objIndex : objIndex--;
		   }
		   break;
	case 'y':
	case 'Y':choice = 'y'; break;

	case 'n':
	case 'N':choice = 'n'; break;
	case 27:escape_pressed = true;
			if (!motion_present && choice == 'y') {
				motion_present = true;
			}
			else
				exit(0);
	}
}

void mouse_follow(int new_x, int new_y) {
	float fraction = 0.0001f;		//For the rotation tuner.
	float fast_fraction = 0.001;	//For the fast rotation around edges.
	float fast_move_percentage = 0.01; // What percentile of area has to be used to move fast from mouse.

	if (motion_present == false)
		return;

	//How much is varied
	int variation_x = prev_x - new_x;
	int variation_y = prev_y - new_y;

	// X - Rotation
	if (variation_x < 0)
	{
		if (new_x > width * (1-fast_move_percentage)) //appox. > 1200
			angle += abs(variation_x) * fast_fraction ;
		angle += deltaTime * fraction;
		lx = sin(angle);
		lz = -cos(angle);
	}
	else if (variation_x > 0)
	{
		if (new_x < width * fast_move_percentage) // appox. 400s
			angle -= abs(variation_x) * fast_fraction ;
		angle -= deltaTime * fraction;
		lx = sin(angle);
		lz = -cos(angle);
	}
	prev_x = new_x;

	// Y - Rotation
	fast_move_percentage = 0.35;

	if (variation_y < 0)
	{
		float fastMoveY=0;
		if (new_y < hight* fast_move_percentage)
			fastMoveY = abs(variation_y) * fast_fraction * 0.4;
		y - deltaTime * fraction - fastMoveY > LOWER_Y ? y -= deltaTime * fraction -fastMoveY : y = LOWER_Y;
	}
	else if (variation_y > 0)
	{
		float fastMoveY=0;
		if (new_y > hight * (1-fast_move_percentage))
			fastMoveY = abs(variation_y) * fast_fraction * 0.4;
		y + deltaTime * fraction + fastMoveY < UPPER_Y ? y += deltaTime * fraction + fastMoveY: y = UPPER_Y;
	}
	prev_y = new_y;
}

void printMsg(char * message,GLfloat mX, GLfloat mY, GLfloat mZ) {
	glRasterPos3f(mX, mY, mZ);
	for (char* c = message; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

void cpuView() {

	// For CPU View
	GLfloat baseX = 2., baseY = 1., baseZ = -2.;
	//GLfloat baseWidth = 8.;
	//glColor3f(1., 0., 0.);
	//glBegin(GL_POLYGON);
	//glVertex3f(baseX, baseY, baseZ);
	//glVertex3f(baseX + baseWidth, baseY, baseZ);
	//glVertex3f(baseX + baseWidth, baseY, baseZ - baseWidth);
	//glVertex3f(baseX, baseY, baseZ - baseWidth);
	//glEnd();


	if (x >= baseX && z <= baseZ){	// Inside ?
		glColor3f(1., 1., 1.);
		if (choice == '1') {
			printMsg((char*)"Do you want to Disassemble ? Enter Y / N", 3., 5., -6.);
			reposition = true;
		}
		else if (choice == 'n')
		{	/// Set camera position
			enterPressed = false;
		}
		else if (choice == 'y') {
	
			if (!escape_pressed) {
				printMsg((char*)"Press Enter to disassemble / Backspace to assemble", 5.24, 4.1, -4.275);
				printMsg((char*)"Esc to exit view", 5.24, 3.8, -5.35);
			}
			if (reposition == true) {
				x = disXYZ[0];	lx = disLxLyLz[0];	
				z = disXYZ[2];	lz = disLxLyLz[2];
				reposition = false;
				motion_present = false;
			}
		}
	}
	else {
		choice = '1';
		enterPressed = false;
		escape_pressed = false;
	}
}
#endif MOTION