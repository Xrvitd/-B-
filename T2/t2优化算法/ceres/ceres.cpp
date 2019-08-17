// ceres.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define _ENABLE_EXTENDED_ALIGNED_STORAGE
#include <iostream>  
#include <fstream>  
#include <string> 
#include <ctime>


#include <Eigen/Core>
#include <Eigen/Geometry>
#include <ceres/ceres.h>
#include <glog/logging.h>
//#include<test.h>
using namespace std;

using ceres::AutoDiffCostFunction;
using ceres::NumericDiffCostFunction;
using ceres::DynamicAutoDiffCostFunction;

using ceres::CostFunction;
using ceres::Problem;
using ceres::Solver;
using ceres::Solve;
double cs[10];
// A templated cost functor that implements the residual r = 10 -
// x. The method operator() is templated so that we can then use an
// automatic differentiation wrapper around it to generate its
// derivatives.
struct re
{
	double ph, P;
}a[300][5][100][100];
double qz1, qz2, qz3, qz4;
struct CostFunctor {
	double pi = ceres::acos(-1);
	double js(double x) const
	{
		//x += 4.5;
	    //double qw = (2 * sin(pi*(x - 5))) / pi + (2 * sin(3 * pi*(x - 5))) / (3 * pi) + (2 * sin(5 * pi*(x - 5))) / (5 * pi) + (10 * sin((pi*(x - 5)) / 5)) / pi - (5 * sin((2 * pi*(x - 5)) / 5)) / pi + (2 * sin(7 * pi*(x - 5))) / (7 * pi) + (10 * sin((3 * pi*(x - 5)) / 5)) / (3 * pi) - (5 * sin((4 * pi*(x - 5)) / 5)) / (2 * pi) + (2 * sin(9 * pi*(x - 5))) / (9 * pi) - (5 * sin((6 * pi*(x - 5)) / 5)) / (3 * pi) + (2 * sin(11 * pi*(x - 5))) / (11 * pi) + (10 * sin((7 * pi*(x - 5)) / 5)) / (7 * pi) - (5 * sin((8 * pi*(x - 5)) / 5)) / (4 * pi) + (2 * sin(13 * pi*(x - 5))) / (13 * pi) + (10 * sin((9 * pi*(x - 5)) / 5)) / (9 * pi) + (10 * sin((11 * pi*(x - 5)) / 5)) / (11 * pi) - (5 * sin((12 * pi*(x - 5)) / 5)) / (6 * pi) + (10 * sin((13 * pi*(x - 5)) / 5)) / (13 * pi) - (5 * sin((14 * pi*(x - 5)) / 5)) / (7 * pi) - (5 * sin((16 * pi*(x - 5)) / 5)) / (8 * pi) + (10 * sin((17 * pi*(x - 5)) / 5)) / (17 * pi) - (5 * sin((18 * pi*(x - 5)) / 5)) / (9 * pi) + (10 * sin((19 * pi*(x - 5)) / 5)) / (19 * pi) + (10 * sin((21 * pi*(x - 5)) / 5)) / (21 * pi) - (5 * sin((22 * pi*(x - 5)) / 5)) / (11 * pi) + (10 * sin((23 * pi*(x - 5)) / 5)) / (23 * pi) - (5 * sin((24 * pi*(x - 5)) / 5)) / (12 * pi) - (5 * sin((26 * pi*(x - 5)) / 5)) / (13 * pi) + (10 * sin((27 * pi*(x - 5)) / 5)) / (27 * pi) - (5 * sin((28 * pi*(x - 5)) / 5)) / (14 * pi) + (10 * sin((29 * pi*(x - 5)) / 5)) / (29 * pi) + (10 * sin((31 * pi*(x - 5)) / 5)) / (31 * pi) - (5 * sin((32 * pi*(x - 5)) / 5)) / (16 * pi) + (10 * sin((33 * pi*(x - 5)) / 5)) / (33 * pi) - (5 * sin((34 * pi*(x - 5)) / 5)) / (17 * pi) - (5 * sin((36 * pi*(x - 5)) / 5)) / (18 * pi) + (10 * sin((37 * pi*(x - 5)) / 5)) / (37 * pi) - (5 * sin((38 * pi*(x - 5)) / 5)) / (19 * pi) + (10 * sin((39 * pi*(x - 5)) / 5)) / (39 * pi) + (10 * sin((41 * pi*(x - 5)) / 5)) / (41 * pi) - (5 * sin((42 * pi*(x - 5)) / 5)) / (21 * pi) + (10 * sin((43 * pi*(x - 5)) / 5)) / (43 * pi) - (5 * sin((44 * pi*(x - 5)) / 5)) / (22 * pi) - (5 * sin((46 * pi*(x - 5)) / 5)) / (23 * pi) + (10 * sin((47 * pi*(x - 5)) / 5)) / (47 * pi) - (5 * sin((48 * pi*(x - 5)) / 5)) / (24 * pi) + (10 * sin((49 * pi*(x - 5)) / 5)) / (49 * pi) + (10 * sin((51 * pi*(x - 5)) / 5)) / (51 * pi) - (5 * sin((52 * pi*(x - 5)) / 5)) / (26 * pi) + (10 * sin((53 * pi*(x - 5)) / 5)) / (53 * pi) - (5 * sin((54 * pi*(x - 5)) / 5)) / (27 * pi) - (5 * sin((56 * pi*(x - 5)) / 5)) / (28 * pi) + (10 * sin((57 * pi*(x - 5)) / 5)) / (57 * pi) - (5 * sin((58 * pi*(x - 5)) / 5)) / (29 * pi) + (10 * sin((59 * pi*(x - 5)) / 5)) / (59 * pi) + (10 * sin((61 * pi*(x - 5)) / 5)) / (61 * pi) - (5 * sin((62 * pi*(x - 5)) / 5)) / (31 * pi) + (10 * sin((63 * pi*(x - 5)) / 5)) / (63 * pi) - (5 * sin((64 * pi*(x - 5)) / 5)) / (32 * pi) - (5 * sin((66 * pi*(x - 5)) / 5)) / (33 * pi) + (10 * sin((67 * pi*(x - 5)) / 5)) / (67 * pi) - (5 * sin((68 * pi*(x - 5)) / 5)) / (34 * pi) + (10 * sin((69 * pi*(x - 5)) / 5)) / (69 * pi) + (cos((18 * pi*(x - 5)) / 5)*(75 * 2 ^ (1 / 2)*(5 ^ (1 / 2) + 5) ^ (1 / 2) - 25 * 18 ^ (1 / 2)*(5 ^ (1 / 2) + 5) ^ (1 / 2))) / (1080 * pi) + (cos((36 * pi*(x - 5)) / 5)*(75 * 2 ^ (1 / 2)*(5 - 5 ^ (1 / 2)) ^ (1 / 2) - 25 * 18 ^ (1 / 2)*(5 - 5 ^ (1 / 2)) ^ (1 / 2))) / (2160 * pi) + 11 / 2;
		
		
		double qw = x + 1 / 2 * ceres::abs(ceres::sin(pi*x));
		return qw;
	}
	 bool operator()(const double* const x, double* residual) const 
	 {
		
		 
		double fly[120];
		for (int i = 0; i < 120; i++)
		{
			fly[i] = js(x[i]);
		}
		double a4=0;
		double fc = 0, ys = 0;
		for (int i = 31; i <= 43; i++)
		{
			for (int j = 16; j <= 22; j++)
			{
				double a1 = 0, a2 = 0, a3;
				int kkk = -1;
				for (int k = 1; k <=32; k++)
				{
					if (k == 4 || k == 20)
					{
						continue;
					}
					for (int l = 1; l <= 4; l++)
					{
						kkk++;
						a1 += a[k][l][i][j].P*ceres::sin(a[k][l][i][j].ph*pi / 180.0) * fly[kkk];
						a2 += a[k][l][i][j].P*ceres::cos(a[k][l][i][j].ph*pi / 180.0) * fly[kkk];
					}
				}
				a3 = ceres::sqrt(a1*a1 + a2*a2);
				ys += 10 * ceres::pow(2, -1 * (a3-31)) - 1;
				//a3 = (a3 - 56.2341)*(a3 - 56.2341);
				fc += ((a3 - 58)*(a3 - 58));
				a4 += a3;
			}
		}
		residual[0] = (a4 / (13.0 * 7.0) - 58)*(a4 / (13.0 * 7.0) - 58)*cs[1];
		residual[1] = fc / (13.0 * 7.0)  *cs[2];
		residual[2] = ys;
		
		
		//cout << fc / (13.0 * 7.0) << endl;
		//double a1 = double(0), a2 = double(0), a3;
		//int xx = -1;
		//for (int i = 1; i <= 32; i++)
		//{
		//	if (i == 4 || i == 20)
		//	{
		//		continue;
		//	}
		//	for (int j = 1; j <= 4; j++)
		//	{
		//		xx++;
		//		a1 += double(a[i][j].P)*ceres::sin(double(a[i][j].ph))*(x[xx]);
		//		a2 += double(a[i][j].P)*ceres::cos(double(a[i][j].ph))*(x[xx]);
		//	}
		//}

		//a3 = ceres::sqrt(a1*a1 + a2*a2);
		//a3 = (a3 - double(35))*(a3 - double(35));
		////int xx = round(double(0));
		// kkk++;
		//residual[kkk] = a3;

		/*double b1 = double(0), b2 = double(0), b3;
		int bxx = -1;
		for (int i = 1; i <= 32; i++)
		{
			if (i == 4 || i == 20)
			{
				continue;
			}
			for (int j = 1; j <= 4; j++)
			{
				bxx++;
				b1 += double(b[i][j].P)*ceres::sin(double(b[i][j].ph))*(x[bxx]);
				b2 += double(b[i][j].P)*ceres::cos(double(b[i][j].ph))*(x[bxx]);
			}
		}
		b3 = ceres::sqrt(b1*b1 + b2*b2);
		b3 = (b3 - double(10))*(b3 - double(10));
		residual[1] = b3;*/


		double cc(0.0),c2=0,c3=0;
		for (int i = 0; i < 120; i++)
		{
			
			//cc += double(-1) * ceres::log((-x[i])+2)/100 ;
			//cc -= 2.7*(1.0 / (-1.0)*x[i]);
			//cc += double(-1) * ceres::log((x[i]) + double(1)) / 100;
			//cc += (x[i] - double(int(x[i])))*(x[i] - double(int(x[i])));


			//cc += (pow(2, x[i] - 4) - 1)*(pow(2, x[i] - 4) - 1) ;
			//cc += (pow(2, -x[i]) - 1)*(pow(2, -x[i]) - 1);


			cc += 3 * ceres::abs(ceres::sin(ceres::acos(-1)*x[i]));
		}
		
		//residual[2] = 0* cc;


		/*int kkk = -1;
		for (int k = 1; k <= 32; k++)
		{
			if (k == 4 || k == 20)
			{
				continue;
			}
			c2 = 0;
			for (int l = 1; l <= 4; l++)
			{
				kkk++;
				c2 += ceres::abs(x[kkk]);
			}
			c3 += (pow(2, c2 - cs[3]) - 1)*(pow(2, c2 - cs[3]) - 1)/1.0;
		}*/
    	//residual[3] = c3*cs[4];
		/*int  bxx = -1;
		double c(0.0);
		for (int i = 1; i <= 32; i++)
		{
			if (i == 4 || i == 20)
			{
				continue;
			}
			double xc = 0;
			for (int j = 1; j <= 4; j++)
			{
				bxx++;
				xc += x[bxx];
				
			}
			double avg = xc / 4, fc = 0;
			for (int j = 1; j <= 4; j++)
			{
				
				fc += (x[bxx - 4 + j] - avg)*(x[bxx - 4 + j] - avg);

			}
			fc = 1.0 / fc  - 16.0/9.0;

			c += fc;
		}
		kkk++;
		residual[kkk] = c;*/
		//cout << c << endl;
		//residual[0] = 10.0 - x[0]*x[0] * x[0] * x[0];
		return true;
	}
};
std::string DoubleToString(const double value, unsigned int precision)
{
	std::ostringstream out;
	if (precision > 0)
		out.precision(precision);

	out << value;
	return out.str();
}

int main(int argc, char** argv) {
	//cout << ceres::cos(90* 3.1415926535/180.0) << endl;
	//cin >> cs[1] >> cs[2] >> cs[3] >> cs[4];
	google::InitGoogleLogging(argv[0]);

	ifstream in("C:\\Users\\Xrvitd_PC\\Dropbox\\vscode\\ceres\\ceres\\cells_v3.txt");
	//ifstream inn("C:\\Users\\Xrvitd_PC\\Dropbox\\vscode\\ceres\\ceres\\new2.txt");
	int q, w, z, s;
	double e, r;

	//cout<<ceres::pow(10,35/20.0)  << endl;

	//-0.000753423   56.2341
	//in >> q >> w >> e >> r;
	//cin >> q;
	double x[120];
	for (int i = 0; i < 120; i++)
	{
		x[i] = rand() % 10000 / 10000.0;
		//x[i] = 0;
	}
	while (in >> q >> w >> z >> s >> e >> r)
	{
		a[q][w][z][s].P = e;
		a[q][w][z][s].P /= 20.0;
		a[q][w][z][s].P = pow(10, a[q][w][z][s].P);
		a[q][w][z][s].ph = r;
		//cout << q<<' '<<w<<" "<<z<<" "<<s<<" "<<a[q][w][z][s].P << endl;
	}



	// The variable to solve for with its initial value. It will be
	// mutated in place by the solver.
	//double x = 0.5;
	//const double initial_x = x;

	// Build the problem.
	Problem problem;

	// Set up the only cost function (also known as residual). This uses
	// auto-differentiation to obtain the derivative (jacobian).NumericDiffCostFunction
	CostFunction* cost_function =
		new NumericDiffCostFunction<CostFunctor, ceres::RIDDERS, 3, 120>(new CostFunctor);
	problem.AddResidualBlock(cost_function, NULL, x);

	// Run the solver!
	Solver::Options options;
	//options.logging_type = ceres::PER_MINIMIZER_ITERATION;
	options.sparse_linear_algebra_library_type = ceres::SUITE_SPARSE;
	options.num_threads = 120;
	options.max_num_iterations = 10000;
	options.minimizer_progress_to_stdout = true;
	options.line_search_direction_type = ceres::BFGS;
	Solver::Summary summary;
	Solve(options, &problem, &summary);

	cout << summary.BriefReport() << "\n";
	double pi = ceres::acos(-1);



	ifstream iiin("test1.csv");
	for (int i = 0; i < 120; i++)
	{
		int kl;
		iiin >> x[i];
		//x[kl]++;
	}
	cout << pi << endl;
	ofstream out("test.csv");
	for (int i = 0; i < 120; i++)
	{
		cout <<x[i] <<"  ->  "<< round(x[i]) << endl;
		//out << round(x[i]) << endl;
	}
	double mmax=-1000, mmin=1000, ak = 0,avg=0;
	for (int i = 1; i <= 73; i++)
	{
		for (int j = 1; j <= 37; j++)
		{
			double a1 = 0,a2=0;
			int kkk = -1;
			for (int k = 1; k <=32; k++)
			{
				if (k == 4 || k == 20)
				{
					continue;
				}
				for (int l = 1; l <= 4; l++)
				{
					kkk++;
					a1 += a[k][l][i][j].P*ceres::sin(a[k][l][i][j].ph*pi / 180.0) * (round(x[kkk]) );
					a2 += a[k][l][i][j].P*ceres::cos(a[k][l][i][j].ph*pi / 180.0) * (round(x[kkk]) );
				}
			}
			double a3 = ceres::sqrt(a1*a1 + a2*a2);
			if (i >= 31 && i <= 43 && j >= 16 && j <= 22)
			{
				avg += 20.0*log10(abs(a3));
				mmax = max(mmax, 20.0*log10(abs(a3)));
				mmin = min(mmin, 20.0*log10(abs(a3)));
			}
			

			out << 20.0*log10(abs(a3))<<"," ;
		}
		out << endl;
	}
	int kkk = -1, bs = 0;;
	for (int k = 1; k <= 32; k++)
	{
		if (k == 4 || k == 20)
		{
			continue;
		}
		int bb = 0;
		for (int l = 1; l <= 4; l++)
		{
			kkk++;
			bb += abs(round(x[kkk]) );
		}
		bs = max(bb, bs);
	}
	
	cout << "bs:   " << bs<<endl;
	ak = mmax - mmin;
	cout << "MaxMag= " << mmax << "   MinMag= " << mmin << "    Ak= " << ak << endl;
	cout << "Avg = " << avg / (13.0 * 7.0) << endl;
	ofstream fout("C:\\Users\\Xrvitd_PC\\Dropbox\\深圳杯\\T2out\\Bs= " + DoubleToString(double(bs), 10) + " Ak= " + DoubleToString(double(ak), 10) + " Avg= " + DoubleToString(double(avg / (13.0 * 7.0)), 10) + " MaxMag=" + DoubleToString(mmax, 10) + " MinMag=" + DoubleToString(mmin, 10)+DoubleToString(double(cs[1]),10)+" "+ DoubleToString(double(cs[2]), 10) + " " + DoubleToString(double(cs[3]), 10) + " " + DoubleToString(double(cs[4]), 10) + " " + " cs="+".txt");
	for (int i = 0; i < 120; i++)
	{
		//cout << x[i] << "  ->  " << round(x[i]) << endl;
		fout << round(x[i]) << endl;
	}
	system("pause");
	return 0;
}


