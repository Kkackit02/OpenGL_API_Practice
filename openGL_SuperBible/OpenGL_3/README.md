# Part 1 Classic OpenGL


# 3-1
  
  ![image](https://github.com/user-attachments/assets/ce53af0f-ba45-44ba-b5d6-4c6ae54ee67b)



# 3-3 

  [각 vertex의 크기도 다르게할수있음!]
  
  ![image](https://github.com/user-attachments/assets/443a6d98-1aa9-4f14-876a-a02c2ff49047)

   너무 큰 값은 알아서 최대 크기로 지정해준다.
   근데 만약 1픽셀보다 작아지면? -> 
   
   glPointSizr 내의 지정된 점의 크기는 픽셀의 정확한 크기가 아니라
픽셀 전체를 감싸는 원의 직경에 가장 가까운 값이라는걸 알아둬야함.
