#ifndef GLUT_DISABLE_ATEXIT_HACK  
#define GLUT_DISABLE_ATEXIT_HACK 
#endif

#include <GL\glut.h>
#include <GL\GL.h>
#include <stdio.h>

void oglDisplay();

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Viewport");
	glutDisplayFunc(oglDisplay);

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	glutMainLoop();

	return 0;
}

void oglDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Left-Bottom
	glViewport(0, 0, 100, 200);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, 100.0f, -100.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(-1.0f, 1.0f, 1.0f, -1.0f);

	// Right-Bottom
	glViewport(200, 0, 200, 200);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, 100.0f, -100.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(-100.0f, 100.0f, 100.0f, -100.0f);

	// Left-Top
	glViewport(0, 200, 200, 200);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, 100.0f, -100.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glRectf(-100.0f, 100.0f, 100.0f, -100.0f);

	// Right-Top
	glViewport(200, 200, 200, 200);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, 100.0f, -100.0f);

	glColor3f(1.0f, 1.0f, 0.0f);
	glRectf(-100.0f, 100.0f, 100.0f, -100.0f);

	glFlush();
}