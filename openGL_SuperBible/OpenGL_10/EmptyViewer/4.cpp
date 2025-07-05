/********************************************************************/
/*  GLU NURBS Surface Demo (4��4 control points, order 4)            */
/*  Build(MinGW) : g++ nurbs.cpp -o nurbs.exe                       */
/*                     -lopengl32 -lglu32 -lfreeglut               */
/********************************************************************/
#define _USE_MATH_DEFINES
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

/* ---------- ���� ---------- */
GLfloat xRot = 25.0f, yRot = -30.0f;
GLUnurbsObj* theNurb = nullptr;

/* 4��4 ������ (���� �����ᡱ ���·� ��ġ) */
GLfloat ctlPts[4][4][3];

void InitCtrlPoints()
{
    for (int u = 0; u < 4; ++u)
        for (int v = 0; v < 4; ++v)
        {
            ctlPts[u][v][0] = 2.0f * (u - 1.5f);           // X
            ctlPts[u][v][1] = 2.0f * (v - 1.5f);           // Y
            /* Z ���̸� �������� */
            ctlPts[u][v][2] = ((u == 1 || u == 2) && (v == 1 || v == 2)) ? 1.5f : 0.0f;
        }
}

/* ---------- ���� ---------- */
void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -8.0f);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);

    /* ---- NURBS ��� ---- */
    gluBeginSurface(theNurb);
    /* U �Ķ���� & V �Ķ���� knot ���� (���� 4 �� ��� 8) */
    GLfloat knots[8] = { 0,0,0,0, 1,1,1,1 };
    gluNurbsSurface(theNurb,
        8, knots,                // U ���
        8, knots,                // V ���
        4 * 3,                     // �� V step �� float stride
        3,                       // �� point �� stride
        &ctlPts[0][0][0],        // ������ �迭
        4, 4,                    // U, V ����(Order) = 4
        GL_MAP2_VERTEX_3);
    gluEndSurface(theNurb);

    /* ---- ���� �׸��� (��� ��) ---- */
    glDisable(GL_LIGHTING);
    glColor3f(1, 1, 0);
    for (int u = 0; u < 4; ++u) {            // U-���� ��
        glBegin(GL_LINE_STRIP);
        for (int v = 0; v < 4; ++v) glVertex3fv(ctlPts[u][v]);
        glEnd();
    }
    for (int v = 0; v < 4; ++v) {            // V-���� ��
        glBegin(GL_LINE_STRIP);
        for (int u = 0; u < 4; ++u) glVertex3fv(ctlPts[u][v]);
        glEnd();
    }
    glEnable(GL_LIGHTING);

    glPopMatrix();
    glutSwapBuffers();
}

/* ---------- ����Ű ---------- */
void SpecialKeys(int key, int, int) {
    if (key == GLUT_KEY_UP)   xRot -= 5;
    if (key == GLUT_KEY_DOWN) xRot += 5;
    if (key == GLUT_KEY_LEFT) yRot -= 5;
    if (key == GLUT_KEY_RIGHT)yRot += 5;
    glutPostRedisplay();
}

/* ---------- �ʱ�ȭ ---------- */
void SetupRC()
{
    glClearColor(0.2f, 0.3f, 0.5f, 1);
    glEnable(GL_DEPTH_TEST);

    /* ����Ʈ */
    glEnable(GL_LIGHTING); glEnable(GL_LIGHT0);
    GLfloat pos[] = { 0,0,10,1 }, dif[] = { 0.9f,0.9f,0.9f,1 };
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);

    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);

    /* NURBS ������ */
    theNurb = gluNewNurbsRenderer();
    gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 25.0f);
    gluNurbsProperty(theNurb, GLU_DISPLAY_MODE, GLU_FILL);

    InitCtrlPoints();
}

/* ---------- �������� ---------- */
void ChangeSize(int w, int h) {
    if (!h)h = 1; float asp = (float)w / h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    gluPerspective(45, asp, 1, 50);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
}

/* ---------- main ---------- */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("GLU NURBS Surface Demo");

    SetupRC();
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutMainLoop();
    return 0;
}
