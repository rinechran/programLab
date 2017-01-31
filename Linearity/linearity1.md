# 선형대수학 1

## 선형 대수

선형대 수학을 공부하면서 가장 많이 접하는 용어가 성형대수이다.

선형 대수를 알아보기전에 이말을 좀 작은 단위로 쪼개 시켜보자.

1) 대수 : '대신하는 수' 우리가 흔히 중학교떄 배운 y = 2x  즉 미지수를 사용하는 수학이다.

2) 선형 : 선형성(線型性, linearity) 또는 선형(線型, linear, 라틴어: linearis)은, 직선처럼 똑바른 도형, 
또는 그와 비슷한 성질을 갖는 대상이라는 뜻이다.  
수학적 정의는 

![선형 위키백과](https://github.com/rinechran/programLab/blob/master/Linearity/img/linearity1.png)

## 백터

정의 : 크기와 방향을 가지는 것을 벡터라고한다. 이거는 유클리드 벡터(Euclidean vector)라고한다.
하지만 벡터의 정의는 생각외로 복잡하다.

![벡터 위키백과](https://github.com/rinechran/programLab/blob/master/Linearity/img/linearity2.png)

가장 중요하게 생각하게 될것은 **"어떤 공간에 속한 임의의 원소들에게 연산을 적용하면 그 출력 결과가 다시 그 공간의 원소가 된다"** 라는 점이다.

무슨말인지 이해가 안가겠지만 이부분은 선형 함수의 정의와 벡터공간의 정의를 함꼐 읽어보면 쉽게 이해가가능하다.

1) 선형 함수 : x,y에 대해 f(x+y) = f(x) + f(y)가 항상 성립
2) 벡터 공간 : v + w 가 다시 V에 속한다.

우리가 주로 할거는 1 , 2차원이 아닌 3차원공간을 중심적으로 다루겠고 이 모든 내용은 2차원 공간에서도 
동일 하게 적응된다.


3차워 공간은 벡터 공간이라고 하지만 엄밀히 말하면 **아핀 공간(Affine Space)**이다.
아핀 공간이란 벡터만 있는게 아니라 점(Point)가 같이 다니는 공간이다.

3차원 공간에서는 벡터는 크기(길이) 방향을 가진것처럼 일종의 화살표가 있는 직선이라고 생각하기 
쉽지만 백터는 위치 개념이 없기때문에 **방향과 길이가 같으면 같은 벡터** 라고 부른다.

벡터의 크기가 1이면 **단위 벡터(Util vector)** 라고 한다.

또한 크기가 0이면 **Zero vector** 이라고 한다.

다시 정의에 선형 함수에 다시 생각해보자 **"x,y에 대해 f(x+y) = f(x) + f(y)가 항상 성립"** 

이 말은 덧셋 뺼셈이 가능하다는점이다.

![선형 위키백과](https://github.com/rinechran/programLab/blob/master/Linearity/img/linearity3.png)
![선형 위키백과](https://github.com/rinechran/programLab/blob/master/Linearity/img/linearity4.png)

이미지 출처 : http://mrw0119.tistory.com/10

S = {v1,v2,v3,v4 ...} 가 있을떄 이들의 선형조합을 다음과 같이 나타낼수 있다.

V = s1 * v1 + s2 * v2...

선형 조합이란 집합 각각의 스칼라 값을 모든 곱한 후 모두 더한것을 말한다.












