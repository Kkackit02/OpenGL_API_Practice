![image](https://github.com/user-attachments/assets/8b765cc6-d728-4e84-a727-4d62a2f2e084)# Part 1 Classic OpenGL
## Curve & Surface

![image](https://github.com/user-attachments/assets/7c5f0325-cd22-439e-9633-af81e3b98ee0)
### 이차 곡면
2차 곡면은 객체로 사용된다.

GLUQuadricObj 데이터 타입에 대한 포인트를 만들어서 사용.

GLUquadric *q = gluNewQuadric();   
gluQuadricDrawStyle(q,  …);        
gluSphere(q, …);                   
gluDeleteQuadric(q);               

![image](https://github.com/user-attachments/assets/395e6fc1-8ff2-46d3-a2e2-5cc7e65a0d6b)
