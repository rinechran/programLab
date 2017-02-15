## 선형대수학 2

# 행렬

행렬 고등학교떄 배워본적이 있을것이다.

그당시 근데 언제 써먹지라고 생각을 자주하였다.

그건바로 행렬이 벡터와 선형변환을 행렬로 표현할수있다는 점이다.

![행렬 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrix.png)

행렬은 row(행) col(열)을 이루는 사각형 형태로 표현이 된다.

기본적으로 n(행의 개수) * m(열의 개수) 행렬이라고 말한다.

가장 기본적인 연산은 벡터와 벡터를 덧셈 뺼셈과 스칼라를 곱하는것이다.

1) 덧셈 뺼셈

![행렬 덧셈1](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrixAdd1.png)

![행렬 덧셈2](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrixAdd2.png)

여기서 중요할점은 더할 행렬은 행과 열이 같아야한다는 점이다.

뺼셈은 저기 요소에 빼기만하면된다는걸 직관적으로 알수있다.


2) 곱셈

![행렬 곰셈1 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrixMul1.png)

![행렬 곰셉2 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrixMul2.png)

곱셈은 언제나 가능한게아니다.

A 와 B를 곱할려면 A의 열의 개수와 B의 행의 개수가 언제나 같아야 한다. 또 다른특징으로는 

![행렬 곰셉3 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrixMul3.png)

교환법칙이 성립되지가않는다는점이다.


3) 스칼라

![행렬 스칼라 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrixScala.png)

스칼라는 단순히 행렬의 각요소에 곱해주면 끝인 연산이다.

행렬의 몇가지 연산 으로는 전치행렬과 역행렬이있다

![ 전치행렬1](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrixTanspose1.png)
![ 전치행렬2 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrixTanspose2.png)

전치행렬이란 행렬의 각요소의 행과 열을 바꿔서 나온 행령이다.

만약에 A와 전치행렬을 한 A가 같다면 대칭 행렬이라고 한다.

좀 전치 행렬에 재미있는 관계가 있는데 

![ 전치행렬3 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrixTanspose3.png)

이런 공식이 관계가 존재하다는 점이다.

![ 전치행렬3 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrixUnity.png)

또한 곱셈에 대한 항등원 I 가 존재한다.

항등 행렬은 주대각선분이 모두 1이고 나머지 성분이 전부 0인 행렬이다.

![ 역행렬1 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/martrixInverse1.png)

항등 행렬하면 바로 등장하는 것은 바로 역행렬이다

** 역행렬은 두 행렬이 서로 곱하는 순서랑 상관없이 항등 행렬이 산출된다면 그 정방 행렬은 서로에 대해 역행렬이라고 한다 **

A의 역행렬을 다음과 ![ 역행렬2 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/martrixInverse2.png) 표기하고 "A인벌스" 라고 읽는다.

그치만 모든 행렬이 역행력을 가지는것이 아니다. 이런 행렬을 특이 행렬(singular matrix) 라고 부른다.

마지막으로 이런 성질도있구나하고 넘어가자

![ 역행렬3 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/martrixInverse3.png) 


# 벡터와 행렬의 관계

행렬이 게임에서 가장많이 쓰는이유중하나는 벡터와 행렬을 변환로 가능해서이다.

예로 들어 벡터 v = {1,2,3} 가 있다는 가정하에 다음과 같이 행렬을 포현할수있다.

![ 벡터 행렬변환 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/vectorChange.png) 

이 와 같이 하나의 열로 표현하는것은 열벡터라고 하고 행으로 표현하는건 행 벡터라고한다.

수학 , OpenGL은 열벡터를 기준으로 하고 다이렉트X는 행벡터를 기준으로 삼는다.




