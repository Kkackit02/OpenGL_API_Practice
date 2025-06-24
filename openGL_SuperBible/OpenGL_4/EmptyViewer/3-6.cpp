#include<windows.h>
#include<GL/gl.h>
#include<GL/GLU.h>
#include<GL/glut.h>
#include <math.h>

#define GL_PI 3.1415f

GLfloat xRot = 30.0f;
GLfloat yRot = 60.0f;

//2-3 openGL, GLUT�� ����� �ִϸ��̼�
void RenderScene(void)
{
	GLfloat y;
	GLfloat fsizes[2];
	GLfloat fCurrSize;


	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();


	glGetFloatv(GL_LINE_WIDTH_RANGE, fsizes);
	fCurrSize = fsizes[0];

	glBegin(GL_LINE_STRIP);

	
	for (y = -90.0f; y < 90.0f; y += 20.0f)
	{
		glLineWidth(fCurrSize);
		glBegin(GL_LINES);
		glVertex2f(-80.0f, y);
		glVertex2f(80.0f, y);
		glEnd();

		fCurrSize += 1.0f;
	}

	glEnd();
	glPopMatrix();
	glFlush();
}



void SetupRC(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
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

	glutCreateWindow("vertex");
	glutDisplayFunc(RenderScene); // renderScene �Լ��� ����ݹ��Լ��� �����
	glutReshapeFunc(ChangeSize);

	SetupRC(); //������ �� �ʱ�ȭ

	glutMainLoop();
}