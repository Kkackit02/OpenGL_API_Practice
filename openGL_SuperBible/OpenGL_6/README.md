# Part 1 Classic OpenGL
## Color and Materials
![image](https://github.com/user-attachments/assets/8c64f5aa-7374-4244-849a-165850f8ad45)

1) 색상의 블렌딩(투명, 자연스러운 색상 설정)

### 투명성?
투명을 만들기 위해...
1) 배경을 먼저 그리고
2) 앞쪽에 있는 물체와 이미 색상 버퍼 내에 있는 내용을 블렌딩
a(알파) 값을 사용해보자!


## 블렌딩
openGL에서의 렌더링은 색상 버퍼 내에 색상값을 넣는 것을 의미한다.
또한 깊이 값도 depth buffer에 넣어, 깊이 테스팅에 사용한다.

근데 glEnable(GL_BLENDING)을 키는 순간
새로 지정되는 색이 기존 색에 결합된다. (색 버퍼, 깊이 버퍼 다 의미 X)

### 색상 결합
표준적인 블렌딩 공식은
Cf = (Cs * S) + (Cd * D)
source, destination

glBlendFunc(GLenum S, GLenum D);

이때 아무거나 인자로 넣을수있는건 아니고, 
![image](https://github.com/user-attachments/assets/63a36523-0734-4428-b843-44a846e8705b)

사전 정의된 위 값들만 사용 가능


### 자주 쓰는 블렌딩 함수 조합

1) glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   
source 색상을 받아, RGB값을 A 값에 곱한 다음,

destination 색상의 RGB값을 (1-source의 Alpha 값)과 곱한 값에 더하는 연산 수행

-> Interpolation!!



![image](https://github.com/user-attachments/assets/79b14516-5184-45a7-b7ae-9ae9f330a77f)
