#include<windows.h>
#include<GL/gl.h>
#include<GL/GLU.h>
#include<GL/glut.h>

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);

	glRectf(-25.0f, 25.0f, 25.0f, -25.0f);


	glFlush(); // 지금까지 받은 모든 명령어를 버퍼에서 비워내면서 모든 명령을 실행시키기
}

void SetupRC(void)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// sing buffer 창을 의미, 색상모드를 RGBA를 쓸것

	glutCreateWindow("Simple");
	glutDisplayFunc(RenderScene); // renderScene 함수를 출력콜백함수로 만들기
	SetupRC(); //렌더링 전 초기화

	glutMainLoop();
}