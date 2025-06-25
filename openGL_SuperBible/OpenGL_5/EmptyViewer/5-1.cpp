#include<windows.h>
#include<GL/gl.h>
#include<GL/GLU.h>
#include<GL/glut.h>

GLfloat rsize = 25;
//x,y ���� �̵��ӵ�
GLfloat lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };  // �¾� ��ġ (���� ��ǥ)

GLfloat windowWidth;
GLfloat windowHeight;




//2-3 openGL, GLUT�� ����� �ִϸ��̼�
void RenderScene(void)
{
	// Earth and moon angle of revolution
	static float fMoonRot = 0.0f;
	static float fEarthRot = 0.0f;
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Save the matrix state and do the rotations
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	// Translate the whole scene out and into view
	glTranslatef(0.0f, 0.0f, -300.0f);
	// Set material color, to yellow
	// Sun
	glColor3ub(255, 255, 0);
	glDisable(GL_LIGHTING);
	glutSolidSphere(15.0f, 15, 15);
	glEnable(GL_LIGHTING);
	// Position the light after we draw the Sun!
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	// Rotate coordinate system
	glRotatef(fEarthRot, 0.0f, 1.0f, 0.0f);
	// Draw the earth
	glColor3ub(0, 0, 255);
	glTranslatef(105.0f, 0.0f, 0.0f);
	glutSolidSphere(15.0f, 15, 15);
	// Rotate from Earth-based coordinates and draw moon
	glColor3ub(200, 200, 200);
	glRotatef(fMoonRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(30.0f, 0.0f, 0.0f);
	fMoonRot += 15.0f;
	if (fMoonRot > 360.0f)
		fMoonRot = 0.0f;
	glutSolidSphere(6.0f, 15, 15);
	// Restore the matrix state
	glPopMatrix(); // Modelview matrix
	// Step Earth orbit 5 degrees
	fEarthRot += 5.0f;
	if (fEarthRot > 360.0f)
		fEarthRot = 0.0f;
	glutSwapBuffers();
}


void TimerFunction(int value)
{
	//�ٽ� �׸���
	glutPostRedisplay();
	glutTimerFunc(50, TimerFunction, 1);
}


void SetupRC(void)
{
	glEnable(GL_DEPTH_TEST);              // ���� ���� ���
	glEnable(GL_LIGHTING);               // ���� ���
	glEnable(GL_LIGHT0);                 // 0�� ���� Ȱ��ȭ
	glEnable(GL_COLOR_MATERIAL);         // ���� ���� Ȱ��ȭ

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); // ���� �Ӽ� ����
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);              // ��� ����glEnable(GL_DEPTH_TEST);              // ���� ���� ���
    glEnable(GL_LIGHTING);               // ���� ���
    glEnable(GL_LIGHT0);                 // 0�� ���� Ȱ��ȭ
    glEnable(GL_COLOR_MATERIAL);         // ���� ���� Ȱ��ȭ

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); // ���� �Ӽ� ����
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);              // ��� ����
}


//â ũ�Ⱑ ���Ҷ� GLUT�� ���� ȣ��
void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat fAspect;

	if (h == 0)
	{
		h = 1;
	}

	glViewport(0, 0, w, h); // ����Ʈ ���� (x,y, �ʺ�, ����) -> ���� Ŭ���� ������ �ش� ������ ����
	fAspect = (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION); // gl ��ǥ�� �ʱ�ȭ
	glLoadIdentity();

	gluPerspective(45.0f, fAspect, 1.0f, 425.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	// sing buffer â�� �ǹ�, �����带 RGBA�� ����

	glutCreateWindow("Solar");
	glutDisplayFunc(RenderScene); // renderScene �Լ��� ����ݹ��Լ��� �����
	glutReshapeFunc(ChangeSize);

	glutTimerFunc(33, TimerFunction, 1);

	SetupRC(); //������ �� �ʱ�ȭ

	glutMainLoop();
}