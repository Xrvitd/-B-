// 曲面.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

string file = "test.csv";
string file1 = "22222.obj";




int main()
{
	ifstream in(file);
	ofstream out(file1);
	double a[100][100];
	out << "mtllib MyColorBar2.mtl\nusemtl MyColorBar2\n";
	double mx = 0, mn = 999;
	for (int i = 1; i <= 73; i++)
	{
		for (int j = 1; j <= 37; j++)
		{
			in >> a[i][j];
			
			if (a[i][j] <= 0&&!(i == 39 && j == 21))
			{
				a[i][j] = 0;
			}
			out << "v " << i <<" "<< j <<" "<< a[i][j]/40*20 << endl;
			//out << "vt " << a[i][j] / 37.0 << " 0\n";
			mx = max(mx, a[i][j]);
			mn = min(mn, a[i][j]);
		}
	}
	for (int i = 1; i <= 73; i++)
	{
		for (int j = 1; j <= 37; j++)
		{
			//out << "v " << i << " " << j << " " << a[i][j] / 36.0 * 15 << endl;
			/*if ((i == 39 && j == 21))
			{
				out << "vt " << 0.99 << " 0 \n";
			}else*/
			out << "vt " << (a[i][j]-mn) /(mx-mn+1)+0.02 << " 0 \n";
		}
	}

	cout << mx << " " << mn << endl;
	for (int i = 1; i <= 72; i++)
	{
		for (int j = 1; j <= 36; j++)
		{
			out << "f " << (i - 1) * 37 + j << "\\" << (i - 1) * 37 + j << " " << (i) * 37 + j << "\\" << (i) * 37 + j << " " << (i - 1) * 37 + j + 1 << "\\" << (i - 1) * 37 + j + 1 <<endl;
		}
	}
	for (int i = 1; i <= 72; i++)
	{
		for (int j = 2; j <= 37; j++)
		{
			out << "f " << (i - 1) * 37 + j<<"\\"<<(i - 1) * 37 + j << " " << (i) * 37 + j - 1 << "\\" << (i) * 37 + j - 1 << " " << (i) * 37 + j << "\\" << (i) * 37 + j <<endl;
		}
	}
	










    return 0;
}

