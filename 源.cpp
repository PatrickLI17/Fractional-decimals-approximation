// 分数近似小数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "math.h"
#include <iostream>
#include <fstream>
#include <vector>
#include<time.h>
using namespace std;


int main()
{
	clock_t start, finish;
	double totaltime;
	start = clock();

	vector<int> numerator, denominator;

	ofstream fout;
	fout.open("out.txt");
	double a = 2, difference = 1;
	int b = 0, c;//上/下
				 //cin >> a;
	a = sqrt(a) - 1;
	cout << a << endl;

	for (double i = 1; i < 100000000; i++)//保证能除
	{
		for (double j = b; j < i; j++)
		{
			if ((j/i)>a)
			{
				if (j/i-a>a-(j-1)/i)
				{
					b = j - 1;
				}
				else
				{
					b = j;
				}
				if (abs(b / i - a) < difference)
				{
					difference = abs(b / i - a);
					
					totaltime = (double)(clock() - start) / CLOCKS_PER_SEC;start = clock();
					cout << b << "/" << i << "\t" << difference << "\t" << difference*i << "   " << totaltime << endl;
					fout << b << "/" << i << "\t" << difference << "\t" << difference*i << "   " << totaltime << endl;
				}
				break;
			}
		}
	}





	int t;
	cin >> t;
	return 0;
}

