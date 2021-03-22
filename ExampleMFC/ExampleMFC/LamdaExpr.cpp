#include "stdafx.h"
#include "LamdaExpr.h"

#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <array>

// 출처: https://vallista.tistory.com/entry/C-11-Lambda-Expression-람다-표현식-함수-객체-Functor [VallistA]

CLamdaExpr::~CLamdaExpr()
{
}

int CLamdaExpr::testLamda()
{
	// 구조체의 oprator() 로 인해 구조체의 카운트 값이 계속 누적됩니다.
	// 해당 람다식 a 는 10 + 20 을 호출하여 30이 출력되게 됩니다.	
	// 함수 포인터와 동작은 비슷하지만 함수내에서 값이 사라지지 않는다는 특징이 있으며,
	// 인라인 함수로 처리될수 있기에 이점이 있습니다.

	Accumulator a;
	std::cout << a(10) << std::endl;
	std::cout << a(20) << std::endl;

	int min = 0;
	int max = 10;
	//std::for_each(min, max, testFunc());

	CLamdaExpr functor;
	std::array<int, 10> theList = { 1,2,3,4,5,6,7,8,9,10 }; // Uniform Initialization 으로 초기화
	functor = std::for_each(theList.cbegin(), theList.cend(), functor);
	// cBegin(처음) 부터 cEnd(마지막) 까지 체크해서 functor(opeartor()(int x)) 에 넘김 
	// 그러면 각각의 숫자를 넣은 operator 함수의 값을 체크해서 functor (EvenOddFunctor)을 넘겨줌. 
	// 그러면 현재 EvenOddFunctor인 functor에 넣어줌으로써 evenSum, oddSum등의 변수를 저장하게 된다.

	std::cout << "Sum of evens: " << functor.sumEven() << std::endl;
	std::cout << "Sum of odds: " << functor.sumOdd() << std::endl;

	return 0;
}


int CLamdaExpr::testFunc()
{
	int n = 0;
	return n;
}