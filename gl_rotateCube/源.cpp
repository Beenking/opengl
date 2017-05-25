#include<GL/glut.h>
#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

//����������İ˸�����ռ��е�����ֵ��ԭ�㼴���е�
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
	{ 1.0, 0.0, 0.0 },//��ɫ
	{ 1.0, 1.0, 0.0 },//��ɫ
	{ 0.0, 1.0, 0.0 },//��ɫ
	{ 0.0, 1.0, 1.0 },//��ɫ
	{ 1.0, 0.0, 1.0 },//Ʒ��ɫ
	{ 0.0, 0.0, 1.0 },//����ɫ
	{ 0.0, 0.5, 0.0 },//����ɫ
	{ 0.0, 0.5, 0.5 },//����ɫ

};

float angle = 0;

void polygon(int a, int b, int c, int d)
{   //4�������һ����
	glBegin(GL_QUADS);//���ƶ������������ı���
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
		glutWireCube(2.0);//���Ʊ߳�Ϊ2���߿�
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