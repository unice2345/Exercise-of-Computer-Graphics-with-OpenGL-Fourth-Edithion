#include <GL/glut.h>

GLsizei winWidth = 400, winHeight = 300;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0, winWidth, 0.0, winHeight, 0.0, 1.0);
}

void lineSegment()
{
    glClear(GL_COLOR_BUFFER_BIT);
   
    glColor3f(0.0, 0.4, 0.2);
    glBegin(GL_LINES);
        glVertex2i(180, 15);
	glVertex2i(10, 145);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Draw Line Example");

	init();
	glutDisplayFunc(lineSegment);

	glutMainLoop();

	return 0;
}

