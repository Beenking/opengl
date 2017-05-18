#include<GL/glut.h>

static int spin = 0;
void init()
{
	glClearColor(0.3, 0.3, 0.3, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };
	//OpenGL�е�ģ����ͼ�任����ȫ���ҳ˵�ǰ�任����
	glPushMatrix(); //1.�������״̬
					//�Ȼ���
	glTranslatef(0.0, 0.0, -5.0);
	glPushMatrix();//2.�����Ⱥ󻭵�����ʹ��ͬһ����������ϵ�����������ջ�������β������´β�����Ӱ�� 
				   //��0�Ź�Դ�;����߿������һ��
	glRotated((GLdouble)spin, 1.0, 0.0, 0.0);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glTranslated(0.0, 0.0, 1.5);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(2.0f);
	glutWireCube(0.1);
	glEnable(GL_LIGHTING);
	//�ٻ���������
	glPopMatrix();
	//ֱ�ӻ��������������(0,0,0)λ��
	glutSolidSphere(0.5, 40, 40);

	glPopMatrix(); //ȡ������״̬�����ص���λ����
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluLookAt(1.0, 0, 0, 0, 0, 0, 0, 1, 10);��仰ȡ��ע�ͺ�������ͼ�������תͼ��
	gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 3, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON://����������¼�
		if (state == GLUT_DOWN)
		{
			spin = (spin + 30) % 360;
			glutPostRedisplay();//�������»���
		}
		break;
	default:
		break;
	}
}
int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("�����ջ����");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}