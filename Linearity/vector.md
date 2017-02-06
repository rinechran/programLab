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

벡터의 덧셈은 두 벡터가 각각 v = ( Vx , Vy ,Vz ) w = ( Wx , Wy ,Wz )라면

v + w = ( Vx + Wx , Vy + Wy , Vz + Wz )이다.

각각의 x y z 성분을 더한값이 바로 새로운 벡터가 만들어진다 

스칼라 곱도 매우 직관적이다 

s * v = ( s * Vx , s * Vy , S * Vz)

벡터의 크기는 어떻게 구할까? 

쉽게 생각하여 원점에서부터 (Vx ,Vy, Vz)까지의 길이가 바로 크기가 된다.

피타고라스 정리를 생각하면 매우 간단하다.

![벡터 크기](https://github.com/rinechran/programLab/blob/master/Linearity/img/linearity5.png)

또한 벡터를 단위 벡터로 만들고싶다면 각 성분을 벡터의 길이로 나누면 된다. 
이러한 과정을 정규화(normalize)이라고 한다.

![벡터 정규화](https://github.com/rinechran/programLab/blob/master/Linearity/img/linearity6.png)


## 벡터의 내적과 외적

### 내적 
내적은 공식은 아래와 같다.

벡터의 내적이란 두개의 벡터를 가지구 한 스칼라를 구하는 연산으로 아래와 같이 정의된다.

![벡터의 내적](https://github.com/rinechran/programLab/blob/master/Linearity/img/linearity7.png)

이미지 출처 : http://j1w2k3.tistory.com/627

실제 게임에서는 v = ( Vx , Vy ,Vz ) w = ( Wx , Wy ,Wz ) 이면 

v * w = Vx * Wx + Vy * + Wy ....

간단하게 각 성분을 곱하고 더하면 그만이다.

게임에서는 이러한 공식을 이용해 두 벡터의 사이각을 구한다.

또한 벡터의 제곱근을 구하는 것이 느리기떄문에 그 자신과 내적시키는 경우를 볼수있다.

실제 게임에서는 상대방이 주인공 앞에 있는지를 확인할수있다.

아래 그래프는 Cos ,Sin 그래프이다. 

![벡터 내적 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/linearityTangentFunction.png)

중요할점은 0 ~ 90 , 270 ~ 360 향상 양이기떄문에 적이 뒤에 있는지 앞에 있는지 확인할수있다는 점이다.

만약 둘다 단위 벡터라면 두 벡터가 평행인지 확인할수 있다.

그치만 단위벡터로 내적하게 될경우  (3번 곱 , 2번의 덧셈 , 1번 제곱근) 으로 쓰기떄문에 

평향성을 구할려면 외적을 사용한다.

외적을 보기전에 내적의 한 예를 보자.

![벡터 투영 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/ProjectionVector.jpg)

이미지 출처 " http://toymaker.tistory.com/entry/투영-벡터-Projection-Vector

벡터를를 다른 벡터에 투영한 결과를 계산할떄 이용을 한다

      A * B  = ||A||| * ||B|| * cosθ

      = ||A||| * ||B|| * || Aproj || / || A||

      = ||B|| * || Aproj ||

그러므로 || Aproj || = A * B / ||B|| 가 성립된다.

벡터 투영은 충돌검사에서 자주 나온다고한다.

### 외적

외적에 내용이 많아 길어질거 같다.

![벡터 외적 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/outerProduct.png)

이미지 출처 : http://j1w2k3.tistory.com/635

외적이란 두 벡터를 가지고 새로운 벡터를 만드는 공식이다.

이 새로운 벡터는 재미있는 특징은 새로운 벡터는 두 벡터에 전부 수직이라는 점이다.

![벡터 외적 공식 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/outerProductMath.png)

![벡터 외적 공식 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/outerProductMath2.png) 

내적에 비교하면 Cos 에서 Sin으로 바뀌었고 * 가 아니라 cross형태가 되었다.

[외적 계산법](http://j1w2k3.tistory.com/635)은 이쪽을 보는게 매우 정리가 잘되어 있다.

외적에 관해 더 살펴볼것이 있다.

V ![벡터 외적 공식 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/outerProductMath2.png)  W = -(W ![벡터 외적 공식 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/outerProductMath2.png)  V)

바로 내적에 비해 교환법칙하고 다르다는점이다. 내적같은경우는 자연스럽게 교환법칙이 성립하지만 외적같은경우는 방향이 반대로 바뀌기 떄문이다.

V ![좌표계](https://github.com/rinechran/programLab/blob/master/Linearity/img/coordinateSystem.png) 

이떄 방향에 한번더 살펴볼 것이 DirectX라는 MS개발툴은 왼손좌표계를 사용한다. 이와달리 OpenGl은 오른손 좌표계를 사용한다.

그결과 외적의 방향을 알려면 오른손 좌표계는 오른손으로 왼손 좌표계는 왼손을 사용해야한다.

가장 흔하게 쓰는 방식은 평면의 법선벡터를 구하거나 두 벡터의 평행 여부를 판단할떄 쓰인다.

** 내적인 경우 두 벡터를 정규화해야하지만 외적같은경우는 서로 평행하다면 외적으로 나온 크기가 0이 된다는점이다.

이는 두 사이각의 벡터가 평행하면 각이 0 , 180 도여야하는데 sin 그래프에서 해당 각도에서는 0이 된다는걸 알수있다.









