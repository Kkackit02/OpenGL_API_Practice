#include<windows.h>
#include<GL/gl.h>
#include<GL/GLU.h>
#include<GL/glut.h>
#include <math.h>

#define GL_PI 3.1415f

GLfloat xRot = 120.0f;
GLfloat yRot = 30.0f;

//2-3 openGL, GLUT�� ����� �ִϸ��̼�
void RenderScene(void)
{
	GLfloat x, y, angle;
	GLboolean bCull = true;
	GLboolean bDepth = true;
	GLboolean bOutline = true;
	int iPivot = 1;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (bCull) //�ĸ� �߷����� BACKFACE CULLING(��ü �ĸ� ���ֱ�), 
		// ���̿� ���� ������ ��ü�� �������� ������ ��ü�� BackFace Culling�� �����ؼ��� �ȵȴ�.
		glEnable(GL_CULL_FACE);
	else
		glDisable(GL_CULL_FACE);

	if (bDepth) //z���� ���� �ָ��ִ°� �տ��ִ°Ϳ� ��������� ����
		glEnable(GL_DEPTH_TEST);
	else
		glDisable(GL_DEPTH_TEST);

	if (bOutline)
		glPolygonMode(GL_BACK, GL_LINE);
	else
		glPolygonMode(GL_BACK, GL_FILL);

	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(0.0f, 0.0f, 75.0f); // ���� vertex

	for (angle = 0.0f; angle < (2.0f * GL_PI); angle += (GL_PI / 8.0f))
	{
		x = 50.0f * sin(angle);
		y = 50.0f * cos(angle);

		if ((iPivot % 2) == 0)
			glColor3f(0.0f, 1.0f, 0.0f);
		else
			glColor3f(1.0f, 0.0f, 0.0f);

		iPivot++; //���� �ﰢ������ �ٸ� ���� ����

		glVertex2f(x, y);
	}
	glEnd();
	
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f);
	for (angle = 0.0f; angle < (2.0f * GL_PI); angle += (GL_PI / 8.0f))
	{
		x = 50.0f * sin(angle);
		y = 50.0f * cos(angle);

		if ((iPivot % 2) == 0)
			glColor3f(0.0f, 1.0f, 0.0f);
		else
			glColor3f(1.0f, 0.0f, 0.0f);

		iPivot++; //���� �ﰢ������ �ٸ� ���� ����

		glVertex2f(x, y);
	}
	glEnd();
	
	glPopMatrix();
	glFlush();
}



void SetupRC(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glShadeModel(GL_FLAT);
	glFrontFace(GL_CCW); // �ﰢ�� ���϶��� �ð� �������� ���ε��� ����� �������� ����
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