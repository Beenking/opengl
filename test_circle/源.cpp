#include <cmath>

#ifndef GLUT_DISABLE_ATEXIT_HACK  
#define GLUT_DISABLE_ATEXIT_HACK 
#endif

#include <GL\glut.h>

const int n = 1000;
const GLfloat R = 0.5f;
const GLfloat PI = 3.14159265f;

void myDisplayCircle()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	for (int i = 0; i < n; ++i)
	{
		glVertex2f(R*cos(2 * PI / n*i), R*sin(2 * PI / n*i));
	}
	glEnd();

	glPointSize(50.0f);
	glBegin(GL_POINTS);
	
		glVertex2f(0.9, 0.9);
	
	glEnd();
	glFlush();
}

void myDisplayFivePonitStar(void)
{
	GLfloat a = 1 / (2 - 2 * cos(72 * PI / 180));
	GLfloat bx = a * cos(18 * PI / 180);
	GLfloat by = a * sin(18 * PI / 180);
	GLfloat cy = -a * cos(18 * PI / 180);
	GLfloat
		PointA[2] = { 0, a },
		PointB[2] = { bx, by },
		PointC[2] = { 0.5, cy },
		PointD[2] = { -0.5, cy },
		PointE[2] = { -bx, by };

	glClear(GL_COLOR_BUFFER_BIT);
	// 按照A->C->E->B->D->A的顺序，可以一笔将五角星画出
	glBegin(GL_LINE_LOOP);
	glVertex2fv(PointA);
	glVertex2fv(PointC);
	glVertex2fv(PointE);
	glVertex2fv(PointB);
	glVertex2fv(PointD);
	glEnd();
	glFlush();
}

float const factor = 0.1f;
void myDisplaySin(void)
{
	GLfloat x;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(1.0f, 0.0f);         // 以上两个点可以画x轴
	glVertex2f(0.0f, -1.0f);
	glVertex2f(0.0f, 1.0f);         // 以上两个点可以画y轴
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (x = -1.0f / factor; x<1.0f / factor; x += 0.01f)
	{
		glVertex2f(x*factor, sin(x)*factor);
	}
	glEnd();
	glFlush();
}

void myRectDisplay()
{
	//glClearColor(1, 0, 0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 1, 0);
	glRectf(-0.5, -0.5, 0.5, 0.5);
	glFlush();
}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(400, 400);
	glutCreateWindow("GL_CIRCLE");
	glutDisplayFunc(&myRectDisplay);

	glClearColor(0, 0, 1, 1.0f);

	glutMainLoop();

	return 0;
}