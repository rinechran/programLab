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

![ 전치행렬2 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrixTanspose1.png)
![ 전치행렬1 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/matrixTanspose2.png)

전치행렬이란 행렬의 각요소의 행과 열을 바꿔서 나온 행령이다.

만약에 A와 전치행렬을 한 A가 같다면 대칭 행렬이라고 한다.



