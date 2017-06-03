#include <GL/glut.h>

GLsizei winWidth = 640, winHeight = 480;
struct wcPt2D{ 
public:
    wcPt2D(int inX, int inY): x(inX), y(inY) {}
    float x, y;
};

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

void linePlot(wcPt2D dataPts[5])
{
    int k;
    glBegin(GL_LINE_STRIP);
	for(k = 0; k < 5; k++) {
	    glVertex2f(dataPts[k].x, dataPts[k].y);
	}
    glEnd();
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.4, 0.2);

    wcPt2D dataPts[5] = {wcPt2D(100, 100), wcPt2D(200, 200), wcPt2D(300, 150), wcPt2D(400, 250), wcPt2D(500, 450)};
    wcPt2D dataPts1[5] = {wcPt2D(100, 200), wcPt2D(200, 300), wcPt2D(300, 250), wcPt2D(400, 350), wcPt2D(500, 200)};
    wcPt2D dataPts2[5] = {wcPt2D(100, 150), wcPt2D(200, 250), wcPt2D(300, 300), wcPt2D(400, 450), wcPt2D(500, 350)};
    glEnable(GL_LINE_STIPPLE);

    glLineStipple(1, 0x1C47);
    linePlot(dataPts);

    glColor3f(0.4, 0.0, 0.2);
    glLineStipple(1, 0x00FF);
    glLineWidth(2.0);
    linePlot(dataPts1);

    glColor3f(0.0, 0.2, 0.4);
    glLineStipple(1, 0x0101);
    glLineWidth(3.0);
    linePlot(dataPts2);
    glDisable(GL_LINE_STIPPLE);
}
 
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Line Stipple Example");

	init();
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}

