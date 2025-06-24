#include<windows.h>
#include<GL/gl.h>
#include<GL/GLU.h>
#include<GL/glut.h>
#include <math.h>

#define GL_PI 3.1415f

//2-3 openGL, GLUT�� ����� �ִϸ��̼�
void RenderScene(void)
{
	GLfloat x, y, z, angle;
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	
	
	glBegin(GL_LINES);
	z = 0.0f;
	for (angle = 0.0f; angle <= GL_PI; angle += (GL_PI/20.0f))
	{
		x = 50.0f * sin(angle);
		y = 50.0f * cos(angle);
		glVertex3f(x, y, z);

		x = 50.0f * sin(angle + GL_PI);
		y = 50.0f * cos(angle + GL_PI);
		glVertex3f(x, y, z);
	}
	glEnd();
	
	/*
	glBegin(GL_LINE_STRIP);
	glVertex3f(90.0f, 90.0f, 0.0f);
	glVertex3f(95.0f, 95.0f, 0.0f);
	glVertex3f(95.0f, 100.0f, 0.0f);
	glEnd();
	*/
	
	glPopMatrix();
	glFlush();
}



void SetupRC(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
}


//â ũ�Ⱑ ���Ҷ� GLUT�� ���� ȣ��
void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio = 1;

	if (h == 0)
	{
		h = 1;
	}

	GLfloat nRange = 100.0f;


	glViewport(0, 0, w, h); // ����Ʈ ���� (x,y, �ʺ�, ����) -> ���� Ŭ���� ������ �ش� ������ ����

	glMatrixMode(GL_PROJECTION); // gl ��ǥ�� �ʱ�ȭ
	glLoadIdentity();

	// Ŭ���� ����, l, r, b, t, n, f ����

	if (w <= h)
	{
		glOrtho(-nRange, nRange, -nRange * h / w, nRange * h / w, -nRange, nRange);
	}
	else
	{
		glOrtho(-nRange * h / w, nRange * h / w, -nRange, nRange, -nRange, nRange);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// sing buffer â�� �ǹ�, �����带 RGBA�� ����

	glutCreateWindow("LINES");
	glutDisplayFunc(RenderScene); // renderScene �Լ��� ����ݹ��Լ��� �����
	glutReshapeFunc(ChangeSize);

	SetupRC(); //������ �� �ʱ�ȭ

	glutMainLoop();
}