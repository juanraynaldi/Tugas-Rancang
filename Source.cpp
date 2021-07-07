#include <Windows.h>
#include <stdlib.h>
#include <GL/glut.h>

void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1600, 1200);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("3D");
	init();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);

	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);

	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void tampil(void)
{
	/* if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT); */

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glPushMatrix();

	//Diamond A1
		//East
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex3f(-40.0, -20.0, -20.0);
	glVertex3f(-50.0, 5.0, -15.0);
	glVertex3f(-25.0, 10.0, -15.0);
	glVertex3f(-25.0, -20.0, -20.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex3f(-46.0, 2.0, -15.0);
	glVertex3f(-34.0, 2.0, -15.0);
	glVertex3f(-32.0, -4.0, -15.0);
	glVertex3f(-39.0, -10.0, -15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex3f(-40.0, -14.0, -15.0);
	glVertex3f(-30.0, -10.0, -15.0);
	glVertex3f(-28.0, -16.0, -15.0);
	glVertex3f(-30.0, -18.0, -15.0);
	glVertex3f(-38.0, -18.0, -15.0);
	glEnd();


	//East Roof
	glBegin(GL_POLYGON);
	glColor3ub(255, 250, 205);
	glVertex3f(-50.0, 5.0, -15.0);
	glVertex3f(-30.0, 20.0, -30.0);
	glVertex3f(-25.0, 10.0, -15.0);
	glEnd();

	//North
	glBegin(GL_POLYGON);
	glColor3ub(250, 250, 210);
	glVertex3f(-25.0, 10.0, -15.0);
	glVertex3f(-25.0, 15.0, -45.0);
	glVertex3f(-25.0, -20.0, -30.0);
	glVertex3f(-25.0, -20.0, -20.0);
	glEnd();

	//West-North
	glBegin(GL_POLYGON);
	glColor3ub(218, 165, 32);
	glVertex3f(-25.0, 15.0, -45.0);
	glVertex3f(-25.0, -20.0, -30.0);
	glVertex3f(-40.0, -20.0, -40.0);
	glEnd();

	//North Roof
	glBegin(GL_POLYGON);
	glColor3ub(255, 239, 213);
	glVertex3f(-25.0, 10.0, -15.0);
	glVertex3f(-30.0, 20.0, -30.0);
	glVertex3f(-25.0, 15.0, -45.0);
	glEnd();

	//West
	glBegin(GL_POLYGON);
	glColor3ub(255, 228, 181);
	glVertex3f(-25.0, 15.0, -45.0);
	glVertex3f(-50.0, 10.0, -45.0);
	glVertex3f(-40.0, -20.0, -40.0);
	glVertex3f(-25.0, -20.0, -30.0);
	glEnd();

	//West Roof
	glBegin(GL_POLYGON);
	glColor3ub(255, 218, 185);
	glVertex3f(-25.0, 15.0, -45.0);
	glVertex3f(-30.0, 20.0, -30.0);
	glVertex3f(-50.0, 10.0, -45.0);
	glEnd();

	//South
	glBegin(GL_POLYGON);
	glColor3ub(238, 232, 170);
	glVertex3f(-50.0, 10.0, -45.0);
	glVertex3f(-50.0, 5.0, -15.0);
	glVertex3f(-40.0, -20.0, -20.0);
	glVertex3f(-40.0, -20.0, -40.0);
	glEnd();

	//South Roof
	glBegin(GL_POLYGON);
	glColor3ub(240, 230, 140);
	glVertex3f(-50.0, 10.0, -45.0);
	glVertex3f(-30.0, 20.0, -30.0);
	glVertex3f(-50.0, 5.0, -15.0);
	glEnd();

	//Diamond A2
	//Roof North-West
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(10.0, 15.0, -20.0);
	glVertex3f(50.0, 10.0, -20.0);
	glVertex3f(50.0, 15.0, -45.0);

	//Roof East-South
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(10.0, 15.0, -45.0);
	glVertex3f(10.0, 15.0, -20.0);
	glVertex3f(50.0, 15.0, -45.0);

	//East
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(30.0, -20.0, -15.0);
	glVertex3f(10.0, 15.0, -20.0);
	glVertex3f(50.0, 10.0, -20.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0.0, 0.0, 0.0);
	glVertex3f(20.0, 8, -17);
	glVertex3f(36, 8, -17);
	glVertex3f(22, 4, -17);
	glVertex3f(38, 7, -17);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0.0, 0.0, 0.0);
	glVertex3f(32, 2.0, -17);
	glVertex3f(42, 2, -17);
	glVertex3f(41, 1, -17);
	glVertex3f(30, 0, -17);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0.0, 0.0, 0.0);
	glVertex3f(24, 2.0, -17);
	glVertex3f(30, 2, -17);
	glVertex3f(29, 0, -17);
	glVertex3f(25, 0, -17);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0.0, 0.0, 0.0);
	glVertex3f(32, -4, -17);
	glVertex3f(38, -4, -17);
	glVertex3f(36, -6, -17);
	glVertex3f(30, -6, -17);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0.0, 0.0, 0.0);
	glVertex3f(26, -8.0, -17);
	glVertex3f(36, -8, -17);
	glVertex3f(34, -10, -17);
	glVertex3f(28, -10, -17);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(0.0, 0.0, 0.0);
	glVertex3f(30.0, -20.0, -15.0);
	glVertex3f(50.0, 10.0, -20.0);
	glVertex3f(45.0, -20.0, -25.0);
	glEnd();

	//East-North
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(30.0, -20.0, -15.0);
	glVertex3f(50.0, 10.0, -20.0);
	glVertex3f(45.0, -20.0, -25.0);
	glEnd();

	//North
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(50.0, 10.0, -20.0);
	glVertex3f(45.0, -20.0, -25.0);
	glVertex3f(50.0, 15.0, -45.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(0.0, 0.0, 0.0);
	glVertex3f(45.0, -20.0, -25.0);
	glVertex3f(50.0, 15.0, -45.0);
	glVertex3f(40.0, -20.0, -40.0);
	glEnd();

	//North-West
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(45.0, -20.0, -25.0);
	glVertex3f(50.0, 15.0, -45.0);
	glVertex3f(40.0, -20.0, -40.0);
	glEnd();

	//West
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex3f(50.0, 15.0, -45.0);
	glVertex3f(40.0, -20.0, -40.0);
	glVertex3f(20.0, -20.0, -40.0);
	glVertex3f(10.0, 15.0, -45.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(0.0, 0.0, 0.0);
	glVertex3f(15.0, -20.0, -25.0);
	glVertex3f(10.0, 15.0, -45.0);
	glVertex3f(20.0, -20.0, -40.0);
	glEnd();

	//South-West
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(15.0, -20.0, -25.0);
	glVertex3f(10.0, 15.0, -45.0);
	glVertex3f(20.0, -20.0, -40.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(0.0, 0.0, 0.0);
	glVertex3f(10.0, 15.0, -20.0);
	glVertex3f(30.0, -20.0, -15.0);
	glVertex3f(15.0, -20.0, -25.0);
	glEnd();


	//East-South
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(10.0, 15.0, -20.0);
	glVertex3f(30.0, -20.0, -15.0);
	glVertex3f(15.0, -20.0, -25.0);
	glEnd();

	//South
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(15.0, -20.0, -25.0);
	glVertex3f(10.0, 15.0, -20.0);
	glVertex3f(10.0, 15.0, -45.0);
	glEnd();
        //gedung belakang
	glBegin(GL_POLYGON);
	glColor3f(225.0,228.0,181.0);
	glVertex3f(50.0,-20.0,-50.0);
	glVertex3f(50.0,30.0,-50.0);
	glVertex3f(-50.0,30.0,-50.0);
	glVertex3f(-50.0,-20.0,-50.0);
	glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.435, 0.568, 0.701);
        glVertex3f(20.0-70, 30.0, -10.0-70);
        glVertex3f(20.0-70, -20.0, -10.0-70);
        glVertex3f(20.0-70, -20.0, -50.0);
        glVertex3f(20.0-70, 30.0, -50.0);
        glEnd(); 
	
        glBegin(GL_POLYGON);
        glColor3f(225.0,228.0,181.0);
        glVertex3f(50.0,-20.0,-80.0);
        glVertex3f(50.0,30.0,-80.0);
        glVertex3f(-50.0,30.0,-80.0);
        glVertex3f(-50.0,-20.0,-80.0);
        glEnd();
	
        glBegin(GL_POLYGON);
        glColor3f(0.435, 0.568, 0.701);
        glVertex3f(10.0+40, 30.0, -10.0-70);
        glVertex3f(10.0+40, -20.0, -10.0-70);
        glVertex3f(10.0+40, -20.0, -50.0);
        glVertex3f(10.0+40, 30.0, -50.0);
        glEnd();
	
        //garis
        glLineWidth(2);
   	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-45.0, 30.0, -49.0);
	glVertex3f(-45.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-48.0, 30.0, -49.0);
	glVertex3f(-48.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-42.0, 30.0, -49.0);
	glVertex3f(-42.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-39.0, 30.0, -49.0);
	glVertex3f(-39.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-36.0, 30.0, -49.0);
	glVertex3f(-36.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-33.0, 30.0, -49.0);
	glVertex3f(-33.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-30.0, 30.0, -49.0);
	glVertex3f(-30.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-27.0, 30.0, -49.0);
	glVertex3f(-27.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-24.0, 30.0, -49.0);
	glVertex3f(-24.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-21.0, 30.0, -49.0);
	glVertex3f(-21.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-18.0, 30.0, -49.0);
	glVertex3f(-18.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-15.0, 30.0, -49.0);
	glVertex3f(-15.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-12.0, 30.0, -49.0);
	glVertex3f(-12.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-9.0, 30.0, -49.0);
	glVertex3f(-9.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-6.0, 30.0, -49.0);
	glVertex3f(-6.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(-3.0, 30.0, -49.0);
	glVertex3f(-3.0, -20.0, -49.0);
	glEnd();
	
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(48.0, 30.0, -49.0);
	glVertex3f(48, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(45.0, 30.0, -49.0);
	glVertex3f(45.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(42.0, 30.0, -49.0);
	glVertex3f(42.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(39.0, 30.0, -49.0);
	glVertex3f(39.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(36.0, 30.0, -49.0);
	glVertex3f(36.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(33.0, 30.0, -49.0);
	glVertex3f(33.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(30.0, 30.0, -49.0);
	glVertex3f(30.0, -20.0, -49.0);
	glEnd();
		
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(27.0, 30.0, -49.0);
	glVertex3f(27.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(24.0, 30.0, -49.0);
	glVertex3f(24.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(21.0, 30.0, -49.0);
	glVertex3f(21.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(18.0, 30.0, -49.0);
	glVertex3f(18.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(15.0, 30.0, -49.0);
	glVertex3f(15.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(12.0, 30.0, -49.0);
	glVertex3f(12.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(9.0, 30.0, -49.0);
	glVertex3f(9.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(6.0, 30.0, -49.0);
	glVertex3f(6.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(3.0, 30.0, -49.0);
	glVertex3f(3.0, -20.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f(0.0, 30.0, -49.0);
	glVertex3f(0.0, -20.0, -49.0);
	glEnd();
	//garis vertikal
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f( 50.0, 27.0, -49.0);
	glVertex3f(-50.0, 27.0, -49.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f( 50.0, 23.0, -49.0);
	glVertex3f(-50.0, 23.0, -49.0);
	glEnd();	
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f( 50.0, 19.0, -49.0);
	glVertex3f(-50.0, 19.0, -49.0);
	glEnd();
		glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f( 50.0, 15.0, -49.0);
	glVertex3f(-50.0, 15.0, -49.0);
	glEnd();
		glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f( 50.0, 11.0, -49.0);
	glVertex3f(-50.0, 11.0, -49.0);
	glEnd();
		glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f( 50.0,7.0, -49.0);
	glVertex3f(-50.0, 7.0, -49.0);
	glEnd();
		glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f( 50.0, 3.0, -49.0);
	glVertex3f(-50.0, 3.0, -49.0);
	glEnd();
		glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f( 50.0, -1.0, -49.0);
	glVertex3f(-50.0, -1.0, -49.0);
	glEnd();
	
		glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f( 50.0, -19.0, -49.0);
	glVertex3f(-50.0, -19.0, -49.0);
	glEnd();
		glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f( 50.0, -15.0, -49.0);
	glVertex3f(-50.0, -15.0, -49.0);
	glEnd();
		glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f( 50.0, -11.0, -49.0);
	glVertex3f(-50.0, -11.0, -49.0);
	glEnd();
		glBegin(GL_LINE_LOOP);
	glColor3f(0.435, 0.568, 0.701);
	glVertex3f( 50.0,-7.0, -49.0);
	glVertex3f(-50.0, -7.0, -49.0);
	glEnd();

	



	glPushMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}
