#ifndef PARAM
#define PARAM

#include <math.h>
#include <GL/glut.h>

class point3D {
public:	double x, y, z;
		point3D() {
			x = 0., y = 0., z = 0.;
		}
		point3D(double a, double b, double c) {
			x = a, y = b, z = c;
		}
		void assign(double a, double b, double c) {
			x = a, y = b, z = c;
		}
};

class point2D {

public:double x, y;
	   point2D() {
		   x = 0., y = 0.;
	   }
	   point2D(double a, double b) {
		   x = a, y = b;
	   }
	   void assign(double a, double b) {
		   x = a, y = b;
	   }
};

// WINDOW & PAGE PARAMETERS
int width = 1920, hight = 1080;
int page = 0;


// MOTION PARAMETERS
#define UPPER_Y 7.0
#define LOWER_Y	-0.8

float lx = 0.0f, lz = -1.0f;
float zx = 0.0f, zz = 0.0f;
double x = .0f, z = 5.0f, y = 5.0;
bool motion_present = false;
float angle = 0.0f;
int oldTimeSinceStart = 0, deltaTime;
float fraction = 0.3f;
float xmin = -8.5, xmax = 8.5,	/// MOTION RESTRICTION PARAMETERS
zmin = -8.5, zmax = 8.5, bounceVal = 1.;
float motion_gap = 0.0001;

// Texture count
GLuint* textures;
#define NUM_TEXTURE 40

#define WOODEN_FINISH 2	/// TEXTURE MAPPING NUMBER
#define MOTHERBOARD_BACK 0
#define MOTHERBOARD_FRONT 1
#define MOTHERBOARD_USB 3
#define STEEL_FINISH 4
#define RAZOR_LOGO 5
#define CPU_CASE_SIDEBAR 6
#define CPU_INSIDE_WALL 7
#define MOTHERBOARD_VGA 8
#define FAN_LOGO 9
#define CASE_RIM_RIGHT 10
#define CASE_RIM_LEFT 11
#define CASE_RIM_TOP 12
#define CASE_RIM_BOTTOM 13
#define CASE_BEHIND 14

// Other parts
#define HDD_TOP 15
#define RAMSTICK 16
#define PSU_FRONT 17
#define PSU_TOP 18
#define PSU_LEFT 19
#define CHIPSET 20
#define CHIPSET_BACK 21
#define GPU_FRONT 22
#define GPU_LOWER 23
#define GPU_BACK 24
#define GPU_LEFT 25
#define GPU_SIDE 26
#define WALL 27
#define TABLE 28
#define DRAWERS 29
#define CEILING 30
#define COUCH_SEAT 31
#define COUCH_PILLOW 32
#define TV_FRONT 33
#define PIC 34
#define TV_TABLE 35
#define SPEAKER 36
#define KEYBOARD 37
#define DESK_WALLPAPER 39
#define DESK_WALLPAPER_BLANK 40

const char* texPath[] = {			"data/motherboard_back.bmp",
									"data/motherboard_front.bmp",
									"data/wooden_finsih.bmp",
									"data/motherboard_usb.bmp",
									"data/steel_texture.bmp",
									"data/razor_logo.bmp",
									"data/case_side_bar.bmp",
									"data/inside_wall.bmp",
									"data/motherboard_vga.bmp",
									"data/fan_logo.bmp",
									"data/rim_right.bmp",
									"data/rim_left.bmp",
									"data/rim_top.bmp",
									"data/rim_bottom.bmp",
									"data/case_behind.bmp",
									"data/hdd.bmp",
									"data/ramstick.bmp",
									"data/psu_front.bmp",
									"data/psu_top.bmp",
									"data/psu_left.bmp" ,
									"data/Chipset.bmp",
									"data/chipset_back.bmp",
									"data/gpu_front.bmp",
									"data/gpu_lower.bmp",
									"data/gpu_left.bmp",
									"data/gpu_back.bmp",
									"data/gpu_side.bmp",
									"data/wall.bmp",
									"data/table.bmp",
									"data/drawers.bmp",
									"data/ceiling.jpg",
									"data/couch_seat.bmp",
									"data/couch_pillow.bmp",
									"data/tv.bmp",
									"data/pic.bmp",
									"data/tv_table.bmp",
									"data/speaker.bmp",
									"data/keyboard.bmp",
									"data/acer_wallpaper.bmp",
									"data/acer_wallpaper_blankscreen.bmp"
};



// COMMON METHODS
float deg(float radians) {
	return radians * (180.0 / M_PI);
}

float rad(float degree) {
	return degree * (M_PI / 180);
}

// OBJECT REMOVAL
int objIndex = -1;
bool enterPressed = false;
bool assemble = false;
char choice = '1';
float disXYZ[3] = { 4., 5.,-3.5 }, disLxLyLz[3] = { 1., 0., 0. };
float disapphereLimit = -4.;

#define REMOVE_SIDE_PANEL	0
#define REMOVE_RAM_STICK	2
#define REMOVE_FAN			4
#define REMOVE_PROCESSOR	6
#define REMOVE_PSU			8
#define REMOVE_HDD			10
#define REMOVE_GPU			12
#define REMOVE_MOTHERBOARD	14

point3D objLoc(0., 5., -2.);
point3D viewerLoc(0., 5., 0.);

point3D prevViewerLoc;
point3D prevObjLoc;

/// Dissassmbly choice


#endif PARAM
