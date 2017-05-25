#include<GL/glut.h>
#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

//绘制立方体的八个立体空间中的坐标值，原点即其中点
GLfloat vertexNum[][3] = {
	{ 1.0, -1.0, -1.0 },
	{ 1.0, -1.0,  1.0 },
	{ 1.0,  1.0,  1.0 },
	{ 1.0,  1.0, -1.0 },
	{ -1.0, -1.0, -1.0 },
	{ -1.0, -1.0,  1.0 },
	{ -1.0,  1.0,  1.0 },
	{ -1.0,  1.0, -1.0 }
};
GLfloat colors[][3] = {
	{ 1.0, 0.0, 0.0 },//红色
	{ 1.0, 1.0, 0.0 },//黄色
	{ 0.0, 1.0, 0.0 },//绿色
	{ 0.0, 1.0, 1.0 },//青色
	{ 1.0, 0.0, 1.0 },//品红色
	{ 0.0, 0.0, 1.0 },//淡蓝色
	{ 0.0, 0.5, 0.0 },//淡绿色
	{ 0.0, 0.5, 0.5 },//淡青色

};

float angle = 0;

void polygon(int a, int b, int c, int d)
{   //4个点组成一个面
	glBegin(GL_QUADS);//绘制多组独立的填充四边形
	glColor3fv(colors[a]);
	glVertex3fv(vertexNum[a]);
	glColor3fv(colors[a]);
	glVertex3fv(vertexNum[b]);
	glColor3fv(colors[a]);
	glVertex3fv(vertexNum[c]);
	glColor3fv(colors[a]);
	glVertex3fv(vertexNum[d]);
	glEnd();
}

void cube(void)
{
	polygon(0, 3, 2, 1);
	polygon(2, 3, 7, 6);
	polygon(3, 0, 4, 7);
	polygon(1, 2, 6, 5);
	polygon(4, 5, 6, 7);
	polygon(5, 4, 0, 1);
}

void paint(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{
		glRotatef(angle, 0, 1, 0);
		glColor3f(1, 0, 0);
		glutWireCube(2.0);//绘制边长为2的线框
		cube();
	}
	glPopMatrix();
	glutSwapBuffers();
}

void IdleFunction()
{
	angle += 0.02;
	if (angle > 36000)
		angle = 0;
	glutPostRedisplay();
}

void reshapeFunction(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -8.0, 8.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void Init()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.3, 0.3, 0.3, 1.0f);
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(500, 500);
	glutCreateWindow("RotateCube");
	Init();

	glutReshapeFunc(reshapeFunction);
	glutIdleFunc(IdleFunction);
	glutDisplayFunc(paint);
	glutMainLoop();
	return 0;

}