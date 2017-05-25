#include <gl/glut.h>
#include <stdlib.h>

static int leftFirst = GL_TRUE;

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(0.0, 1.0, 0.0, 1.0*(GLfloat)h / (GLfloat)w);
	else
		gluOrtho2D(0.0, 1.0*(GLfloat)w / (GLfloat)h, 0.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 't':
	case 'T':
		leftFirst = !leftFirst;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}


void drawLeftTriangle(void)
{
	/* draw yellow triangle on LHS of screen */

	glBegin(GL_TRIANGLES);
	glColor4f(1.0, 0.0, 0.0, 0.5);
	glVertex3f(0.1, 0.9, 0.0);
	glVertex3f(0.1, 0.1, 0.0);
	glVertex3f(0.7, 0.5, 0.0);
	glEnd();
}

void drawRightTriangle(void)
{
	/* draw cyan triangle on RHS of screen */

	glBegin(GL_TRIANGLES);
	glColor4f(0.0, 1.0, 0.0, 0.5);
	glVertex3f(0.9, 0.9, 0.0);
	glVertex3f(0.3, 0.5, 0.0);
	glVertex3f(0.9, 0.1, 0.0);
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (leftFirst) {
		drawLeftTriangle();
		drawRightTriangle();
	}
	else {
		drawRightTriangle();
		drawLeftTriangle();
	}

	glFlush();
}


void init()
{
	glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glBlendFunc(GL_ONE, GL_ONE);
	//glBlendFunc(GL_ONE, GL_ZERO);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Blend Test");

	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}