# Part 1 Classic OpenGL
## Color, Materials, Lighting : The Basic


색상 얘기 블라블라..
1) 눈의 원리
2) CRT 원리
3) 색상 모드(4비트, 8비트, 16비트, 32비트) - 색상의 역사

멀티 미디어 공학에서 배운 내용들~~



## OpenGL에서의 색상
- R
- G
- B
- A
8비트씩 각각, 총 32비트


### 드로잉 색 결정

```c
void glColor<x><t>(R,G,B,A);
x -> 인자 수 결정
t -> 인자의 데이터타입
```


```cpp
glColcor3ub(0,255,128);
```

### 쉐이딩
glColor는 현재 드로잉의 색상을 지정하는것이다.
즉 이 명령 뒤에 드로잉되는 모든 버텍스에 적용되는 색상을 지정하는 것이다.

즉 삼각형(버텍스 3개)의 각 버텍스의 색상을 모두 다르게 지정하면?
-> 보간된 색상이 나타나게됨.

### Code 5-1
![image](https://github.com/user-attachments/assets/656fc98f-0c90-4cd4-bd31-810b5ac52238)


```cpp

    glShadeModel(GL_SMOOTH); // 색상 보간

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);     // 빨강
    glVertex3f(0.0f, 200.0f, 0.0f);
    glColor3ub(0, 255, 0);     // 초록
    glVertex3f(200.0f, -70.0f, 0.0f);
    glColor3ub(0, 0, 255);     // 파랑
    glVertex3f(-200.0f, -70.0f, 0.0f);
    glEnd();

```



# 실제 세계의 색상(Color in the Real World)

- Diffuse(분산광)
- Specular(반사광)
- ambient(주변광)

### 이 세 개의 RBGA Color 값을 합한 것이 그 지점의 색상!


# 실제 세계의 재질(Material in the Real World) 

### emission property
- ka(ambient에 대한 재질 속성)
- kd(diffuse에 대한 재질 속성)
- ks(specular에 대한 재질 속성)

위에서 나온 각 광에 대한 값에 이걸 곱해주면된다.

즉 I = ka * ia + ks * is + ka * ia


주변광 ambient는 단지 그냥 ka와 ia를 곱하면 끝이지만..

분산광과 반사광은
표면과 광원 사이의 가곧, 광원 거리, 기타요소 들도 정해져야한다.


즉 I = ka * ia + ks * is * max(0, n'h)^p + kd * id * max(0,n'l)
