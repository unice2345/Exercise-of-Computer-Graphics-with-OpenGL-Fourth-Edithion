/*
 * sample_display_list.cpp
 *
 *  Created on: 2017年4月20日
 *      Author: lcy
 */

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

const double TWO_PI = 6.2831853;
GLsizei winWidth = 400, winHeight = 400;
GLuint regHex;

static void init()
{
	GLint center_x = winWidth / 2;
	GLint center_y = winHeight / 2;
	GLdouble theta;
	GLint k;

	glClearColor(1.0, 1.0, 1.0, 1.0);

	regHex = glGenLists(1);
	glNewList(regHex, GL_COMPILE);
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
			for(k = 0; k < 6; k++) {
				theta = TWO_PI * k / 6.0;
				glVertex2i(center_x + 150 * cos(theta), center_y + 150 * sin(theta));
			}
		glEnd();

	glEndList();
}

void regHexagon()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glCallList(regHex);
	glFlush();
}

void winReshapeFunc(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, newWidth, 0, newHeight, -1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Display List Example");

	init();
	glutDisplayFunc(regHexagon);
	glutReshapeFunc(winReshapeFunc);

	glutMainLoop();

	return 0;
}

