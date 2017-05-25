#include <GL/glut.h>
#include <stdlib.h>

void init(void)
{
	glClearColor(0.0, 1.0, 1.0, 0.0);
	//glShadeModel(GL_SMOOTH);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(2.f);
	glLoadIdentity();
	gluLookAt(1.0, 1.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//glutWireCube(2);
	glBegin(GL_QUADS); // of the color cube
		// Top-face
		glColor3f(0.0f, 1.0f, 0.0f); // green
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		// Bottom-face
		glColor3f(1.0f, 0.5f, 0.0f); // orange
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		// Front-face
		glColor3f(1.0f, 0.0f, 0.0f); // red
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		// Back-face
		glColor3f(1.0f, 1.0f, 0.0f); // yellow
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		// Left-face
		glColor3f(0.0f, 0.0f, 1.0f); // blue
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		// Right-face
		glColor3f(1.0f, 0.0f, 1.0f); // magenta
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd(); // of the color cube


	glFlush();
}
//此函数能在窗口被拉伸时按比例拉伸我们画的立方体框架
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2.0, 2.0, -2.0, 2.0, 3.0, 20.0);
	glMatrixMode(GL_MODELVIEW);

}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	//glutInitWindowPosition(300, 100);
	//glutCreateWindow(argv[0]);argv[0]为默认的应用程序文件所在的路径
	glutCreateWindow("用直线画立方体");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}