/*
This project was made by :
Adarsh Revankar, Akshaya M.
As Mini-Project for the course 'Computer Graphics Laboratory' under VTU.

This project was made with high effort from team, please do approciate the work.
I expect you guys to take few code snippets from this code & not the whole project.
Any improvements made will be accepted, mail the code to : adarshrevankar0123@gmail.com
*/
#include <GL/glut.h>
#include <iostream>

#include "parameter.h"
#include "motion.h"
#include "objects.h"
#include "bitmap.h"
#include "light.h"

/* TEXTURE HANDLING */
void loadTexture(GLuint texture, const char* filename) {
	BmpLoader image(filename);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, image.iWidth, image.iHeight, GL_RGB, GL_UNSIGNED_BYTE, image.data);
}

void textureInit() {
	// Create Texture.
	textures = new GLuint[NUM_TEXTURE];
	glGenTextures(NUM_TEXTURE, textures);

	// Load the Texture.
	for (int i = 0; i < NUM_TEXTURE; i++)
		loadTexture(textures[i], texPath[i]);
}

/* REDNDERING HANDLING */
void change_size(int w, int h) {
	// Update global parameters
	width = w;
	hight = h;
	// Do reshape
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float ratio = 0.0f;
	h = h == 0 ? 1 : h;
	ratio = (float)w / (float)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0f, ratio, 0.7f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, 5.0f, z,
		x + lx, y, z + lz,
		0.0f, 1.0f, 0.0f);

	if (page == 1) {
		drawGround();
		drawCube();
		cpuView();
		drawCPU();
	}
	else if(page == 0) {
		front_page();
		progress_wheel();
	}
	glutSwapBuffers();
}

void opengl_init(void) {
	glEnable(GL_DEPTH_TEST);
	textureInit();
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(change_size);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutPassiveMotionFunc(mouse_follow);
	show_light_effect();

}

void setDeltaTime() {
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = (timeSinceStart - oldTimeSinceStart) * 0.2f;
	oldTimeSinceStart = timeSinceStart;
}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, hight);
	glutCreateWindow("Graphical Simulation of Desktop & it's Components");
	opengl_init();
	glutFullScreen();
	setDeltaTime();
	glutMainLoop();
	getchar();
	return 0;
}
