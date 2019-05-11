#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

constexpr float WINSIZE_WID = 640.0;
constexpr float WINSIZE_HEI = 360.0;

void drawTriangle();
void handleKey(int key, int x, int y);

static int posx = 0;
static int posy = 0;
static int hei = 100;
static int wid = 200;

int main(int argc, char *argv[])
{
	using namespace std;
	glutInit(&argc, argv);
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		exit;
	}
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(WINSIZE_WID, WINSIZE_HEI);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL - Test");
	glClearColor(0.3, 0.3, 0.3, 0.3);

	glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	glOrtho(0, WINSIZE_WID, 0, WINSIZE_HEI, -1.0, 1.0);
	// glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(drawTriangle);
	glutSpecialFunc(handleKey);
	glutMainLoop();
}

void drawTriangle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// glutSwapBuffers();

	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_TRIANGLES);
	glVertex2i(posx, posy);
	glVertex2i(posx + wid/2, posy + hei);
	glVertex2i(posx + wid, posy);
	glEnd();

	// glBegin(GL_TRIANGLES);
	// glVertex3f(0.7, 0.7, 0);
	// glVertex3f(0, -1, 0);
	// glVertex3f(-0.7, 0.7, 0);
	// glEnd();

	glFlush();
}

void handleKey(int key, int x, int y)
{
	bool exitReq = false;
	switch(key)
	{
	case GLUT_KEY_RIGHT:
		posx += 10;
		break;
	case GLUT_KEY_LEFT:
		posx -= 10;
		break;
	case GLUT_KEY_UP:
		posy += 10;
		break;
	case GLUT_KEY_DOWN:
		posy -= 10;
		break;
	case GLUT_KEY_HOME:
		exitReq = true;
		break;
	}
	if (exitReq)
	{
		glutLeaveMainLoop();
	}
	else
	{
		glutPostRedisplay();
	}
	
}