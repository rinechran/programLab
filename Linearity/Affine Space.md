# 선형대 수학3

## 아핀공간 (Affine Space)


벡터는 힘과 방향을 가르키지만 실 게임에서 주인공이나 적들의 ㅊ위치를 벡터를 가지고 표현할수는 없다.

그렇다면 위치는 어떻게 표현해야할까? 바로 ** 점 ** 이다.

이 점을 존재하는 공간을 아핀 공간이라고 하며 흔히들 유클리드 공간을 벡터라고 하지만 아핀공간(Affine Space) 이다.

![아핀공간 점](https://github.com/rinechran/programLab/blob/master/Linearity/img/AffineSpacePoint.png)

출처 : 위키백과

** 아핀 공간에서는 점에서 점을 빼서 벡터를 얻거나 점에 벡터를 더해 다른 점을 얻을 수는 있지만 원점이 없으므로 점과 점을 더할 수는 없다.** 문구를 보자.

정의를 버려두고 터와 뎃셈 연산에 대해 보자

![아핀공간 점덧셈 ](https://github.com/rinechran/programLab/blob/master/Linearity/img/ApointAddvector.png)

점 O를 벡터 V를 이용헤서 점P로 이동시킨것과 같다.

O = ( Ox , Oy ,Oz )  = ( Vx , Vy ,Vz )

O + V = ( Ox + Vx , Oy + Vy ,Oz + Vz )

두벡터와 더하는 수식과 완전히 같다는 점이다.