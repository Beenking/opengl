#include <GL/glut.h>
#include <math.h>
#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#define Pi 3.1416
void Init(void)
{
	glClearColor(0.5, 0.5, 0.5, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
}

void paint()
{
	glViewport(0, 0, 1000, 200);

	//�Ȼ��ָ���
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(5.0f);
	glBegin(GL_LINES);
	glVertex2f(-0.6f, -1.0f);    glVertex2f(-0.6f, 1.0f);
	glVertex2f(0.2f, -1.0f);    glVertex2f(0.2f, 1.0f);
	glEnd();

	GLfloat a = 1 / (4 - 4 * cos(72 * Pi / 180));
	GLfloat bx = a * cos(18 * Pi / 180);
	GLfloat by = a * sin(18 * Pi / 180);
	GLfloat cy = -a * cos(18 * Pi / 180);
	GLfloat
		PointA[2] = { 0, a },
		PointB[2] = { bx , by },
		PointC[2] = { 0.25, cy },
		PointD[2] = { -0.25, cy },
		PointE[2] = { -bx, by };
	/*
	              o(A)
				o    o(B)
			     o  o(C)
 					
	*/

	//ͼ1,Ϊֻ������������ƶ���
	glViewport(0, 0, 200, 200);
	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);//ǰ��ͺ����Ϊ�Զ���ķ�ʽ����
	glColor3f(1.0f, 1.0f, 0.0f); glPointSize(5.0f);//��ɫ�Ķ���
	glBegin(GL_POLYGON);
	glVertex2fv(PointA);
	glVertex2fv(PointC);
	glVertex2fv(PointE);
	glVertex2fv(PointB);
	glVertex2fv(PointD);
	glEnd();

	//�����ͼ����Ϊ������䣬��������
	glPolygonMode(GL_FRONT, GL_FILL);// ��������Ϊ���ģʽ
	glPolygonMode(GL_BACK, GL_LINE);// ���÷���Ϊ����ģʽ
	glPointSize(2.0f);
	//ͼ2��ͼ���γɶԱȣ�һ�����������棬һ�������Ƿ���
	//ͼ2
	glViewport(200, 0, 200, 200);
	glFrontFace(GL_CCW);//�л�������
	glColor3f(0.0, 1.0, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2fv(PointA);
	glVertex2fv(PointC);
	glVertex2fv(PointE);
	glVertex2fv(PointB);
	glVertex2fv(PointD);
	glEnd();
	//ͼ3
	glViewport(400, 0, 200, 200);
	glColor3f(0.0, 1.0, 1.0f);
	glFrontFace(GL_CW);//�л�������
	glBegin(GL_POLYGON);
	glVertex2fv(PointA);
	glVertex2fv(PointC);
	glVertex2fv(PointE);
	glVertex2fv(PointB);
	glVertex2fv(PointD);
	glEnd();
	//ͼ4��ͼ5�γɶԱȣ�һ�����������棬һ�������Ƿ���
	//ͼ4
	glViewport(600, 0, 200, 200);
	glFrontFace(GL_CCW);//�л�������
	glColor3f(0.0, 0.0, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2fv(PointA);
	glVertex2fv(PointB);
	glVertex2fv(PointC);
	glVertex2fv(PointD);
	glVertex2fv(PointE);
	glEnd();
	//ͼ5
	glViewport(800, 0, 200, 200);
	glFrontFace(GL_CW);//�л�������
	glColor3f(0.0, 0.0, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2fv(PointA);
	glVertex2fv(PointB);
	glVertex2fv(PointC);
	glVertex2fv(PointD);
	glVertex2fv(PointE);
	glEnd();
	//ͼ6
	glViewport(1000, 0, 200, 200);
	glFrontFace(GL_CW);//�л�������
	glColor3f(0.0, 0.0, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2fv(PointE);
	glVertex2fv(PointD);
	glVertex2fv(PointC);
	glVertex2fv(PointB);
	glVertex2fv(PointA);
	glEnd();
	//ͼ5��ͼ6�γɶԱȣ�����ͬ����˳����ƣ�������Ķ��岻ͬ��
	glFlush();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	Init();
	glutInitWindowSize(1200, 200);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("��ͬ��ͼģʽ�µĶԱȺͷ�ת�ĶԱ�");
	glutDisplayFunc(paint);
	glutMainLoop();
}