#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

// ȸ�� ����
GLfloat xRot = 47.0f;
GLfloat yRot = 0.0f;

// �䷯�� �׸��� �Լ�
void DrawTorus(GLfloat innerRadius, GLfloat outerRadius, GLint sides, GLint rings)
{
    float ringDelta = 2.0f * 3.14159265f / rings;
    float sideDelta = 2.0f * 3.14159265f / sides;

    for (int i = 0; i < rings; ++i) {
        float theta = i * ringDelta;
        float cosTheta = cos(theta);
        float sinTheta = sin(theta);

        float nextTheta = (i + 1) * ringDelta;
        float cosNextTheta = cos(nextTheta);
        float sinNextTheta = sin(nextTheta);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= sides; ++j) {
            float phi = j * sideDelta;
            float cosPhi = cos(phi);
            float sinPhi = sin(phi);
            float dist = outerRadius + innerRadius * cosPhi;

            float x = cosTheta * dist;
            float y = -sinPhi * innerRadius;
            float z = -sinTheta * dist;
            glNormal3f(cosTheta * cosPhi, -sinPhi, -sinTheta * cosPhi);
            glVertex3f(x, y, z);

            x = cosNextTheta * dist;
            y = -sinPhi * innerRadius;
            z = -sinNextTheta * dist;
            glNormal3f(cosNextTheta * cosPhi, -sinPhi, -sinNextTheta * cosPhi);
            glVertex3f(x, y, z);
        }
        glEnd();
    }
}

// ������
void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -2.5f);  // �ڷ� �̵�
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // Y�� ȸ��
    glColor3f(0.7f, 0.4f, 1.0f);

    DrawTorus(0.2f, 0.5f, 30, 30);

    glPopMatrix();

    glutSwapBuffers();

    yRot += 0.5f;
    if (yRot >= 360.0f) yRot = 0.0f;
}

// Ÿ�̸�
void TimerFunction(int value)
{
    glutPostRedisplay();
    glutTimerFunc(33, TimerFunction, 1);
}

// �ʱ�ȭ
void SetupRC(void)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// ������ ��������
void ChangeSize(GLsizei w, GLsizei h)
{
    if (h == 0) h = 1;
    GLfloat fAspect = (GLfloat)w / (GLfloat)h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, fAspect, 1.0f, 425.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// main �Լ�
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rotating Torus");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutTimerFunc(33, TimerFunction, 1);

    SetupRC();

    glutMainLoop();
    return 0;
}
