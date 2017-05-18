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

	//先画分割线
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

	//图1,为只无论正反面绘制顶点
	glViewport(0, 0, 200, 200);
	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);//前面和后面均为以顶点的方式绘制
	glColor3f(1.0f, 1.0f, 0.0f); glPointSize(5.0f);//黄色的顶点
	glBegin(GL_POLYGON);
	glVertex2fv(PointA);
	glVertex2fv(PointC);
	glVertex2fv(PointE);
	glVertex2fv(PointB);
	glVertex2fv(PointD);
	glEnd();

	//其余的图，均为正面填充，反面线形
	glPolygonMode(GL_FRONT, GL_FILL);// 设置正面为填充模式
	glPolygonMode(GL_BACK, GL_LINE);// 设置反面为线形模式
	glPointSize(2.0f);
	//图2和图三形成对比，一个看得是正面，一个看得是反面
	//图2
	glViewport(200, 0, 200, 200);
	glFrontFace(GL_CCW);//切换正反面
	glColor3f(0.0, 1.0, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2fv(PointA);
	glVertex2fv(PointC);
	glVertex2fv(PointE);
	glVertex2fv(PointB);
	glVertex2fv(PointD);
	glEnd();
	//图3
	glViewport(400, 0, 200, 200);
	glColor3f(0.0, 1.0, 1.0f);
	glFrontFace(GL_CW);//切换正反面
	glBegin(GL_POLYGON);
	glVertex2fv(PointA);
	glVertex2fv(PointC);
	glVertex2fv(PointE);
	glVertex2fv(PointB);
	glVertex2fv(PointD);
	glEnd();
	//图4和图5形成对比，一个看得是正面，一个看得是反面
	//图4
	glViewport(600, 0, 200, 200);
	glFrontFace(GL_CCW);//切换正反面
	glColor3f(0.0, 0.0, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2fv(PointA);
	glVertex2fv(PointB);
	glVertex2fv(PointC);
	glVertex2fv(PointD);
	glVertex2fv(PointE);
	glEnd();
	//图5
	glViewport(800, 0, 200, 200);
	glFrontFace(GL_CW);//切换正反面
	glColor3f(0.0, 0.0, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2fv(PointA);
	glVertex2fv(PointB);
	glVertex2fv(PointC);
	glVertex2fv(PointD);
	glVertex2fv(PointE);
	glEnd();
	//图6
	glViewport(1000, 0, 200, 200);
	glFrontFace(GL_CW);//切换正反面
	glColor3f(0.0, 0.0, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2fv(PointE);
	glVertex2fv(PointD);
	glVertex2fv(PointC);
	glVertex2fv(PointB);
	glVertex2fv(PointA);
	glEnd();
	//图5和图6形成对比，按不同顶点顺序绘制，正反面的定义不同。
	glFlush();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	Init();
	glutInitWindowSize(1200, 200);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("不同绘图模式下的对比和反转的对比");
	glutDisplayFunc(paint);
	glutMainLoop();
}