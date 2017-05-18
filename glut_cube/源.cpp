#include <GL/glut.h>
#include <stdlib.h>
#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
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
	//gluLookAt(1.0, 1.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glutWireCube(2);
	glFlush();
}
//�˺������ڴ��ڱ�����ʱ�������������ǻ�����������
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
	//glutCreateWindow(argv[0]);argv[0]ΪĬ�ϵ�Ӧ�ó����ļ����ڵ�·��
	glutCreateWindow("��ֱ�߻�������");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}