#pragma once
#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <array>


class CLamdaExpr
{
public:
	//CLamdaExpr();
	~CLamdaExpr();

	//void operator()()
	////{
	////	std::cout << "Simple Functor" << std::endl;
	////}

	struct Accumulator
	{
		Accumulator()
		{
			counter = 0;
		}

		int counter;
		int operator()(int i)   // �Լ� ��ü�� ����� ���ؼ��� �Լ� ȣ�� �����ڸ� �ݵ�� �����ε� �ؾ��Ѵ�.
		{
			return counter += i;
		}
	};

public:
	CLamdaExpr() : evenSum(0), oddSum(0) {}

	void operator() (int x)
	{
		if (x % 2 == 0)
			evenSum += x; // 2 4 6 8 10 
		else
			oddSum += x; // 1 3 5 7 9
	}
	int sumEven() const { return evenSum; }
	int sumOdd() const { return oddSum; }

	int evenSum;
	int oddSum;



	int testLamda();
	int testFunc();
};

