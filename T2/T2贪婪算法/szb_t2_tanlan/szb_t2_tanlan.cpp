// szb_t2_tanlan.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  
#include <fstream>  
#include <string> 
#include <ctime>
#include<sstream>
#include<map>
#include<algorithm>
using namespace std;
int bs = 1;
std::string DoubleToString(const double value, unsigned int precision)
{
	std::ostringstream out;
	if (precision > 0)
		out.precision(precision);

	out << value;
	return out.str();
}
int x[120];
struct re
{
	double ph, P;
}a[300][5][100][100];

double e1[100][100] = {0}, e2[100][100] = { 0 }, te1[100][100] = { 0 }, te2[100][100] = { 0 }, E[100][100] = { 0 }, tE[100][100] = { 0 };
double qx[100][100][120] = { 0 },qx1[100][100][120] = { 0 },qx2[100][100][120] = { 0 },qavg[120] = { 0 },qfc[120] = { 0 },qz[120] = { 0 };
map<pair<int, int >, int > findx;
int main()
{
	double minak = 999, minj = 999;

	ifstream in("C:\\Users\\Xrvitd_PC\\Dropbox\\vscode\\ceres\\ceres\\cells_v3.txt");
	int q, w, z, s;
	double e, r;
	while (in >> q >> w >> z >> s >> e >> r)
	{
		a[q][w][z][s].P = e;
		a[q][w][z][s].P /= 20.0;
		a[q][w][z][s].P = pow(10, a[q][w][z][s].P);
		a[q][w][z][s].ph = r;
		//cout << q << ' ' << w << " " << z << " " << s << " " << a[q][w][z][s].P << endl;
	}
	
	for (int i = 0; i <120; i++)
	{
		x[i] = 0;
		//x[i] = 0;
	}
	int kk = -1;
	for (int k = 1; k <= 32; k++)
	{
		if (k == 4 || k == 20)
		{
			continue;
		}
		for (int l = 1; l <= 4; l++)
		{

			kk++;

			findx[pair<int,int>(k, l)] = kk;

		}
	}
	double pi = acos(-1),a4=0;
	
	ofstream oout("C:\\Users\\Xrvitd_PC\\Dropbox\\vscode\\szb_t2_tanlan\\szb_t2_tanlan\\ans.txt");
	for (double jj = 58.0; jj <= 58; jj+=0.1)
	{
		stringstream sss;
		sss << jj;
		string sc = sss.str();
		oout << "----------------------------- " << jj << "---------------------------------------\n\n\n";
	for (int ii = 1; ii <= 20; ii++)
	{
		bs = ii;
		stringstream ss;
		ss << ii;
		string s = ss.str();
		ofstream outt("C:\\Users\\Xrvitd_PC\\Dropbox\\vscode\\szb_t2_tanlan\\szb_t2_tanlan\\" + sc + "\\Bs=" + s  + " pz.txt");
		memset(E, 0, sizeof(E));
		memset(tE, 0, sizeof(tE));
		memset(e1, 0, sizeof(e1));
		memset(e2, 0, sizeof(e2));
		memset(te1, 0, sizeof(te1));
		memset(te2, 0, sizeof(te2));
		memset(x, 0, sizeof(x));


		
		double tdt = 99999999999.9;
		int gen = 0;
		while (true)
		{
			int tk, tl;
			gen++;


			bool fd = 0;
			double ltdt = tdt;
			for (int k = 1; k <= 32; k++)
			{
				if (k == 4 || k == 20)
				{
					continue;
				}
				for (int l = 1; l <= 4; l++)
				{
					if (x[k] > bs)
					{
						continue;
					}

					double dt = 0;
					double mx = 999, mn = -999;
					for (int i = 31; i <= 43; i++)
					{
						for (int j = 16; j <= 22; j++)
						{
							te1[i][j] = e1[i][j] + a[k][l][i][j].P *sin(a[k][l][i][j].ph*pi / 180.0);
							te2[i][j] = e2[i][j] + a[k][l][i][j].P *cos(a[k][l][i][j].ph*pi / 180.0);
							tE[i][j] = sqrt(te1[i][j] * te1[i][j] + te2[i][j] * te2[i][j]);

							mx = max(mx, tE[i][j]);
							mn = min(mn, tE[i][j]);

							dt += (tE[i][j] - jj) * (tE[i][j] - jj);
						}

					}
					dt /= (13.0 * 7.0);
					//dt += (mx - mn)*50.0;
					//	cout << dt << endl;
					if (tdt - dt>0.01)
					{
						tdt = dt;
						tk = k;
						tl = l;
						fd = 1;
					}

				}
			}
			if (!fd)
			{


				double mmax = -1000, mmin = 1000, ak = 0, avg = 0;
				for (int i = 1; i <= 73; i++)
				{
					for (int j = 1; j <= 37; j++)
					{

						//tdt += (E[i][j] - 58) * (E[i][j] - 58);

						E[i][j] = 20.0*log10(abs(E[i][j]));
						if (i >= 31 && i <= 43 && j >= 16 && j <= 22)
						{
							avg += (E[i][j]);
							mmax = max(mmax, (E[i][j]));
							mmin = min(mmin, (E[i][j]));
						}



					}


				}
				ak = mmax - mmin;
				ofstream out("C:\\Users\\Xrvitd_PC\\Dropbox\\vscode\\szb_t2_tanlan\\szb_t2_tanlan\\" + sc + "\\Bs=" + s + " Ak= " + DoubleToString(ak, 10) + ".csv");
				for (int i = 1; i <= 73; i++)
				{
					for (int j = 1; j <= 37; j++)
					{

						//tdt += (E[i][j] - 58) * (E[i][j] - 58)

						if (j != 37)
							out << E[i][j] << ",";
						else
						{
							out << E[i][j];
						}
					}
					out << endl;

				}
				cout << "bs:   " << bs << endl;
				//ak = mmax - mmin;
				cout << "MaxMag= " << mmax << "   MinMag= " << mmin << "    Ak= " << ak << endl;
				cout << "Avg = " << avg / (13.0 * 7.0) << endl;
				

				if (ak < minak)
				{
					minak = ak;
					minj = jj;
				}
				oout << "bs:   " << bs << endl;
				//ak = mmax - mmin;
				oout << "MaxMag= " << mmax << "   MinMag= " << mmin << "    Ak= " << ak << endl;
				oout << "Avg = " << avg / (13.0 * 7.0) << endl;
				break;
			}

			outt <<tk<<" "<< tl<< endl;
			x[tk]++;

			tdt = 0;


			for (int i = 1; i <= 73; i++)
			{
				for (int j = 1; j <= 37; j++)
				{
					e1[i][j] = e1[i][j] + a[tk][tl][i][j].P *sin(a[tk][tl][i][j].ph*pi / 180.0);
					e2[i][j] = e2[i][j] + a[tk][tl][i][j].P *cos(a[tk][tl][i][j].ph*pi / 180.0);
					E[i][j] = sqrt(e1[i][j] * e1[i][j] + e2[i][j] * e2[i][j]);
					//tdt += (E[i][j] - 58) * (E[i][j] - 58);

				}


			}



			double tmx = 999, tmn = -999;
			for (int i = 31; i <= 43; i++)
			{
				for (int j = 16; j <= 22; j++)
				{
					//e1[i][j] = e1[i][j] + a[tk][tl][i][j].P *sin(a[tk][tl][i][j].ph*pi / 180.0);
					//e2[i][j] = e2[i][j] + a[tk][tl][i][j].P *cos(a[tk][tl][i][j].ph*pi / 180.0);
					//E[i][j] = sqrt(e1[i][j] * e1[i][j] + e2[i][j] * e2[i][j]);
					tdt += (E[i][j] - jj) * (E[i][j] - jj);

					tmx = max(tmx, E[i][j]);
					tmn = min(tmn, E[i][j]);
				}

			}
			//tdt /= (13.0 * 7.0);
			//tdt += (tmx - tmn)* 10.0;


			if (tdt>ltdt)
			{

				
				double mmax = -1000, mmin = 1000, ak = 0, avg = 0;
				for (int i = 1; i <= 73; i++)
				{
					for (int j = 1; j <= 37; j++)
					{

						//tdt += (E[i][j] - 58) * (E[i][j] - 58);

						E[i][j] = 20.0*log10(abs(E[i][j]));
						if (i >= 31 && i <= 43 && j >= 16 && j <= 22)
						{
							avg += (E[i][j]);
							mmax = max(mmax, (E[i][j]));
							mmin = min(mmin, (E[i][j]));
						}


						
					}
				

				}
				ak = mmax - mmin;
				ofstream out("C:\\Users\\Xrvitd_PC\\Dropbox\\vscode\\szb_t2_tanlan\\szb_t2_tanlan\\" + sc + "\\Bs=" + s + " Ak= "+DoubleToString(ak,10)+ ".csv");
				for (int i = 1; i <= 73; i++)
				{
					for (int j = 1; j <= 37; j++)
					{

						//tdt += (E[i][j] - 58) * (E[i][j] - 58)

						if (j != 37)
							out << E[i][j] << ",";
						else
						{
							out << E[i][j];
						}
					}
					out << endl;

				}

				cout << "bs:   " << bs << endl;
				
				cout << "MaxMag= " << mmax << "   MinMag= " << mmin << "    Ak= " << ak << endl;
				cout << "Avg = " << avg / (13.0 * 7.0) << endl;

				if (ak < minak)
				{
					minak = ak;
					minj = jj;
				}

				oout << "bs:   " << bs << endl;
				//ak = mmax - mmin;
				oout << "MaxMag= " << mmax << "   MinMag= " << mmin << "    Ak= " << ak << endl;
				oout << "Avg = " << avg / (13.0 * 7.0) << endl;

				break;
			}



		}
	}


	}
	
	cout << minak<<"  "<<minj << endl;


	system("pause");
    return 0;
}

