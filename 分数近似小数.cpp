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

	//输入范围是[0,1)
	vector<int> numerator, denominator;
	vector<double> difference;
	ofstream fout;
	//fout.open("out.txt");
	double a=2,j=1,i=2,d=1,dt=1;
	int b=0, c;//上/下
	//cin >> a;
	a = sqrt(a)-1;
	cout << a << endl;
	switch (int(a*4))
	{
	case 0:
		numerator.push_back(0);
		denominator.push_back(1);
		numerator.push_back(0);
		denominator.push_back(2);
		break;
	case 1:
		numerator.push_back(0);
		denominator.push_back(1);
		numerator.push_back(1);
		denominator.push_back(2);
		break;
	case 2:
		numerator.push_back(1);
		denominator.push_back(1);
		numerator.push_back(1);
		denominator.push_back(2);
		break;
	case 3:
		numerator.push_back(1);
		denominator.push_back(1);
		numerator.push_back(2);
		denominator.push_back(2);
		break;
	default:
		break;
	}
	difference.push_back(abs(numerator[0] / denominator[0] - a));
	difference.push_back(abs(numerator[1] / denominator[1] - a));
	while (difference.back()!=0)
	{
		j = numerator.back() + *(numerator.end() - 2) - 2;
		i = denominator.back() + *(denominator.end() - 2)-1;
		dt = difference.back();
		for (; d >= dt;)
		{
			i++;
			d = abs(j / i - a); j++;
			for (; abs(j / i - a) < d; j++)
			{
				d = abs(j / i - a);
			}
			j--; 
		}
		numerator.push_back(j);
		denominator.push_back(i);
		difference.push_back(d);
		totaltime = (double)(clock() - start) / CLOCKS_PER_SEC; //start = clock();
		cout << j << "/" << i << "\t" << d << "\t" << d*i << "   " << totaltime << endl;
	}
	//cout << numerator[0];
	
	//for (double i = 1; i < 100000000; i++)//保证能除
	//{
	//	for (double j = b; j < i; j++)
	//	{
	//		if ((j/i)>a)
	//		{
	//			if (j/i-a>a-(j-1)/i)
	//			{
	//				b = j - 1;
	//			}
	//			else
	//			{
	//				b = j;
	//			}
	//			if (abs(b / i - a) < difference)
	//			{
	//				difference = abs(b / i - a);
	//				cout << b << "/" << i << "\t" << difference << "\t" << difference*i << endl;
	//				fout << b << "/" << i << "\t" << difference << "\t" << difference*i << endl;
	//			}
	//			break;
	//		}
	//	}
	//}





	int t;
	cin >> t;
    return 0;
}

