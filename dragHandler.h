//#ifndef DRAG_HANDLER
//#define DRAG_HANDLER
//#include <GL/glut.h>
//#include <math.h>
//#include "parameter.h"
//
//class dragHandler {
//private:double matModelView[16], matProjection[16];
//		int viewport[4];
//		point2D winCoord;
//		
//		void init(double, double);
//public:	point3D start, end; 
//		point3D objCenter;
//		double calcDistance();
//};
//
//void dragHandler::init(double mx, double my) 
//{	
//	// Mouse point init
//	point2D mousePoint;
//	mousePoint.assign(mx, my);
//
//
//	// Matrix init
//	glGetDoublev(GL_MODELVIEW_MATRIX, matModelView);
//	glGetDoublev(GL_PROJECTION_MATRIX, matProjection);
//	glGetIntegerv(GL_VIEWPORT, viewport);
//
//	// WinCoord init
//	winCoord.x = mousePoint.x;
//	winCoord.y = viewport[3] - mousePoint.y;
//
//	// Line : Near -> Far : Points
//	/// Get the values from gluProjection
//	float nearPlane = 0.7, farPlane = 100.0;
//	/// start points
//	gluUnProject(winCoord.x, winCoord.y, nearPlane, matModelView, matProjection,
//		viewport, &start.x, &start.y, &start.z);
//	/// end points
//	gluUnProject(winCoord.x, winCoord.y, farPlane, matModelView, matProjection,
//		viewport, &end.x, &end.y, &end.z);
//}
//
//double dragHandler::calcDistance( ) {
//	// Distance between point and line
//	point3D AB, AP, objPos;
//
//	init(currentMousePointer.x, currentMousePointer.y);
//
//	AB.x = pow(-start.x + end.x, 2); /// AB = A - B
//	AB.y = pow(-start.y + end.y, 2);
//	AB.z = pow(-start.z + end.z, 2);
//
//	double ab_dot_ab_sqr = AB.x * AB.x + AB.y * AB.y + AB.z + AB.z;
//
//	AP.x = -start.x + objCenter.x;	/// AP = P - A
//	AP.y = -start.y + objCenter.y;
//	AP.z = -start.z + objCenter.z;
//
//	double ab_dot_ap = AP.x * AB.x + AP.y * AB.y + AP.z + AB.z;
//
//	double t = ab_dot_ab_sqr / ab_dot_ap;				/// T = AB / AP
//	
//	objPos.x = start.x + AB.x* t; /// Perpendicular Point = A + AB * T 
//	objPos.y = start.y+ AB.y* t;
//	objPos.z = start.z+ AB.z* t;
//
//	objCenter.assign(objPos.x, objPos.y, objPos.z);
//
//	return sqrt(pow(objPos.x - x, 2) * pow(objPos.y - y, 2) * pow(objPos.z - z, 2));
//}
//
//#endif DRAG_HANDLER