#include "stdafx.h"
#include "LamdaExpr.h"

#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <array>

// ��ó: https://vallista.tistory.com/entry/C-11-Lambda-Expression-����-ǥ����-�Լ�-��ü-Functor [VallistA]

CLamdaExpr::~CLamdaExpr()
{
}

int CLamdaExpr::testLamda()
{
	// ����ü�� oprator() �� ���� ����ü�� ī��Ʈ ���� ��� �����˴ϴ�.
	// �ش� ���ٽ� a �� 10 + 20 �� ȣ���Ͽ� 30�� ��µǰ� �˴ϴ�.	
	// �Լ� �����Ϳ� ������ ��������� �Լ������� ���� ������� �ʴ´ٴ� Ư¡�� ������,
	// �ζ��� �Լ��� ó���ɼ� �ֱ⿡ ������ �ֽ��ϴ�.

	Accumulator a;
	std::cout << a(10) << std::endl;
	std::cout << a(20) << std::endl;

	int min = 0;
	int max = 10;
	//std::for_each(min, max, testFunc());

	CLamdaExpr functor;
	std::array<int, 10> theList = { 1,2,3,4,5,6,7,8,9,10 }; // Uniform Initialization ���� �ʱ�ȭ
	functor = std::for_each(theList.cbegin(), theList.cend(), functor);
	// cBegin(ó��) ���� cEnd(������) ���� üũ�ؼ� functor(opeartor()(int x)) �� �ѱ� 
	// �׷��� ������ ���ڸ� ���� operator �Լ��� ���� üũ�ؼ� functor (EvenOddFunctor)�� �Ѱ���. 
	// �׷��� ���� EvenOddFunctor�� functor�� �־������ν� evenSum, oddSum���� ������ �����ϰ� �ȴ�.

	std::cout << "Sum of evens: " << functor.sumEven() << std::endl;
	std::cout << "Sum of odds: " << functor.sumOdd() << std::endl;

	return 0;
}


int CLamdaExpr::testFunc()
{
	int n = 0;
	return n;
}