# Part 1 Classic OpenGL

# 3D 그래픽과 OpenGL

즉시 모드와 보류 모드

### 보류 모드(retained mode)

물체, 장면 정보를 API에 제공하면, 내부적인 처리를 거쳐 화면에 출력

모든 물체를 씬그래프에 넣어두고, 추가적인 정보만 제공해 화면을 그려냄.

### 즉시모드(immediate mode)

API가 이 방식으로 이루어져있으며, 그래픽 프로세서에 직접적인 명령을 전달해 그 상태를 변경하고, 이어지는 모든 명령에 영향을 준다.

이미 실행된 명령에 대해서는 그 후 내린 명령이 아무런 영향을 주지 못한다.

### 뷰포트(ViewPort)

클리핑 영역과 창의 픽셀수가 정확히 맞아떨어지지않기때문에

논리적 직교 좌표를 물리적인 화면 픽셀 좌표로 전환하는 과정에 쓰는 것이 뷰포트

### 투영(Projection)

3D 좌표계에서 만들어진 지오메트리를 편평한 2D 공간으로 옮기는것

## OpenGL

그래픽 하드웨어 제어를 위한 소프트웨어 인터페이스

모태는 실리콘그래픽스의 IRIS GL

하드웨어의 3D 가속 기능을 사용한 Implementation , 그렇지 않은 implementation으로 나눠짐

## DirectX

보다 openGL이 훨씬 편리하다

opengl32.dll에 들어있음.(System Directory) (3D 렌더링 등 지원)

glu32.dll(GLU 오픈gl 유틸리티 라이브러리)(행렬계산, 여러 기능 지원)

gl.h (모든 openGL 함수, 타입, 매크로)

| GLbyte | 8비트 정수 |
| --- | --- |
| GLshort | 16비트 정수 |
| GLint, GLsizei | 32비트 정수 |
| GLfloat, GLclampf | 32비트 실수 |
| GLdouble, GLclampd | 64비트 실수 |
| GLubyte, GLboolean | 8비트 부호없는 정수 |
| GLushort | 16비트 부호없는 정수 |
| GLunit, GLenum, GLbitfield | 32비트 부호없는 정수 |

### openGL 함수 이름짓기 규칙

<라이브러리 접두어><루트명령어>선택적인 인자수><선택적인 인자타입>

gl - Color - 3f - (….)

glColor3f()

3개의 float 인자를 가지는 Color

### float와 double

많은 c/c++ 컴파일러들이 float를 double로 인식

float 타입임을 명확히 지정해주자

어차피 openGL은 내부적으로 float를 쓰므로..

두배 메모리 사용을 막기 위해서 명시해주자

## 플랫폼 독립성

openGL은 창, 화면관리를 위한 함수나 명령어가 한개도없음

키보드 입력, 마우스 제어 함수도 전혀없다.

→ openGL 디자이너의 최종 목표가 플랫폼 독립성이기때문

### GLUT(OpenGL Utility Toolkit)

GLU는 OpenGl Utility Library이니 헷갈리지 말 것

팜업메뉴, 창 관리 등… 윈도우에 맞게 쓸수있는 툴!!



--------------------------------------
# 실습
![image](https://github.com/user-attachments/assets/8db4f374-c187-4b29-9b10-f51b30476193)


# 2-2
resize Squere (set aspect Ratio) 
![image](https://github.com/user-attachments/assets/fe0657ea-5b52-4f77-9820-e245052124ee)

![image](https://github.com/user-attachments/assets/cc2a7431-b2b3-4b72-bce5-d51130522aad)


## 만약 Resize와 동시에 좌표계를 변경하지않는다면..
![image](https://github.com/user-attachments/assets/e1d2a228-50ea-493a-ad27-3a3f55ac04f6)




## Move BOX!


	glutTimerFunc(33, TimerFunction, 1);  <- 시간 호출로 움직이게 구현


### 싱글 버퍼
https://github.com/user-attachments/assets/58eecfa6-113a-4cf9-b576-ea38bb5fb130

### DOUBLE BUFFER
https://github.com/user-attachments/assets/9807b107-5b55-4aae-bffc-d8f2ec8cc345

## 더블 버퍼링?
스크린 버퍼에 렌더링이 이루어지는동안 드로잉 코드를 실행하는 것

1) 렌더링 시간이 걸릴때 : 이미지가 그려지는 모습을 사용자에게 보여주지않고 한번에 보여주기위해서
2) 애니메이션 : 프레임을 그려두었다가 프레임을 바꾸어가며 애니메이션 효과 내기


glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
->>>
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

이때, 버퍼가 교체될때 드로잉 결과가 출력되므로 간접적으로 glFlush가 이뤄지고있음!!
