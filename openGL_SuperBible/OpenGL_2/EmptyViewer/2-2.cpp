#include<windows.h>
#include<GL/gl.h>
#include<GL/GLU.h>
#include<GL/glut.h>

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);

	glRectf(-25.0f, 25.0f, 25.0f, -25.0f);


	glFlush(); // ���ݱ��� ���� ��� ��ɾ ���ۿ��� ������鼭 ��� ����� �����Ű��
}

void SetupRC(void)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); //����� ���� û������ ����
}


//â ũ�Ⱑ ���Ҷ� GLUT�� ���� ȣ��
void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio = 1;

	if (h == 0)
	{
		h = 1;
	}

	glViewport(0, 0, w, h); // ����Ʈ ���� (x,y, �ʺ�, ����) -> ���� Ŭ���� ������ �ش� ������ ����

	glMatrixMode(GL_PROJECTION); // gl ��ǥ�� �ʱ�ȭ
	glLoadIdentity();

	// Ŭ���� ����, l, r, b, t, n, f ����
	aspectRatio = (GLfloat)w / (GLfloat)h;


	//glOrtho�� �۵� ����� ���� Ŭ���� ������ ����� ���� ���� ���ο� Ŭ���� �������� ������ 
	//���� ��ܿ��� glMatrixMode�� �ʱ�ȭ �ʿ�
	//(Model -> camera -> perspective -> orthograph -> viewport)
	if (w <= h)
		glOrtho(-100.0f, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else
		glOrtho(-100.0f * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// sing buffer â�� �ǹ�, �����带 RGBA�� ����

	glutCreateWindow("GLRECT");
	glutDisplayFunc(RenderScene); // renderScene �Լ��� ����ݹ��Լ��� �����
	glutReshapeFunc(ChangeSize);
	SetupRC(); //������ �� �ʱ�ȭ

	glutMainLoop();
}