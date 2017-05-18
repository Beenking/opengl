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
	//OpenGL中的模型视图变换矩阵全是右乘当前变换矩阵
	glPushMatrix(); //1.保存矩阵状态
					//先画灯
	glTranslatef(0.0, 0.0, -5.0);
	glPushMatrix();//2.由于先后画的物体使用同一个世界坐标系，因此这里入栈消除本次操作对下次操作的影响 
				   //将0号光源和矩形线框绘制在一起
	glRotated((GLdouble)spin, 1.0, 0.0, 0.0);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glTranslated(0.0, 0.0, 1.5);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(2.0f);
	glutWireCube(0.1);
	glEnable(GL_LIGHTING);
	//再画被照物体
	glPopMatrix();
	//直接绘制在世界坐标的(0,0,0)位置
	glutSolidSphere(0.5, 40, 40);

	glPopMatrix(); //取出矩阵状态，返回到单位矩阵
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluLookAt(1.0, 0, 0, 0, 0, 0, 0, 1, 10);这句话取消注释后是左视图，俯瞰旋转图。
	gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 3, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON://鼠标左键点击事件
		if (state == GLUT_DOWN)
		{
			spin = (spin + 30) % 360;
			glutPostRedisplay();//场景重新绘制
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
	glutCreateWindow("矩阵堆栈操作");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}