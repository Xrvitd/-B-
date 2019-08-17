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

// A templated cost functor that implements the residual r = 10 -
// x. The method operator() is templated so that we can then use an
// automatic differentiation wrapper around it to generate its
// derivatives.
struct re
{
	double ph, P;
}a[300][5],b[300][5];

struct CostFunctor {
	 bool operator()(const double* const x, double* residual) const 
	 {
		double a1 = double(0), a2 = double(0), a3;
		int xx = -1;
		for (int i = 1; i <= 32; i++)
		{
			if (i == 4 || i == 20)
			{
				continue;
			}
			for (int j = 1; j <= 4; j++)
			{
				xx++;
				a1 += double(a[i][j].P)*ceres::sin(double(a[i][j].ph))*(x[xx]);
				a2 += double(a[i][j].P)*ceres::cos(double(a[i][j].ph))*(x[xx]);
			}
		}

		a3 = ceres::sqrt(a1*a1 + a2*a2);
		a3 = (a3 - double(35))*(a3 - double(35));
		//int xx = round(double(0));

		residual[0] = a3;

		//double b1 = double(0), b2 = double(0), b3;
		//int bxx = -1;
		//for (int i = 1; i <= 32; i++)
		//{
		//	if (i == 4 || i == 20)
		//	{
		//		continue;
		//	}
		//	for (int j = 1; j <= 4; j++)
		//	{
		//		bxx++;
		//		b1 += double(b[i][j].P)*ceres::sin(double(b[i][j].ph))*(x[bxx]);
		//		b2 += double(b[i][j].P)*ceres::cos(double(b[i][j].ph))*(x[bxx]);
		//	}
		//}
		//b3 = ceres::sqrt(b1*b1 + b2*b2);
		//b3 = (b3 - double(10))*(b3 - double(10));
		//residual[1] = b3;


		//double cc(0.0);
		//for (int i = 0; i < 120; i++)
		//{
		//	cc += double(-1) * ceres::log(x[i]- double(-1))  / double(1);
		//	cc += double(-1) * ceres::log(double(-1)*x[i] + double(2)) / double(1);

		//	//cc += (x[i] - double(int(x[i])))*(x[i] - double(int(x[i])));
		//}
		//residual[1] = cc;

		int bxx = -1;
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
				xc += (x[bxx])*(x[bxx])*(x[bxx]);
				
			}
			c += (xc - 1)*(xc - 1);
		}
		residual[1] = c;
		//cout << c << endl;
		//residual[0] = 10.0 - x[0]*x[0] * x[0] * x[0];
		return true;
	}
};

int main(int argc, char** argv) {

	google::InitGoogleLogging(argv[0]);

	ifstream in("C:\\Users\\Xrvitd_PC\\Dropbox\\vscode\\ceres\\ceres\\new3.txt");
	ifstream inn("C:\\Users\\Xrvitd_PC\\Dropbox\\vscode\\ceres\\ceres\\new2.txt");
	int q, w;
	double e, r;
	//in >> q >> w >> e >> r;
	//cin >> q;
	double x[120];
	for (int i = 0; i < 120; i++)
	{
		x[i] = 1;
	}
	while (in>>q>>w>>e>>r)
	{
		a[q][w].P = e; 
		a[q][w].P /= 20.0;
		a[q][w].P = pow(10, a[q][w].P);
		a[q][w].ph = r;
		//cout << a[q][w].P << endl;
	}
	while (inn >> q >> w >> e >> r)
	{
		b[q][w].P = e;
		b[q][w].P /= 20.0;
		b[q][w].P = pow(10, b[q][w].P);
		b[q][w].ph = r;
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
		new NumericDiffCostFunction<CostFunctor, ceres::RIDDERS,2,120>(new CostFunctor);
	problem.AddResidualBlock(cost_function, NULL, x);

	// Run the solver!
	Solver::Options options;
	//options.logging_type = ceres::PER_MINIMIZER_ITERATION;
	options.max_num_iterations = 10000;
	options.minimizer_progress_to_stdout = true;
	Solver::Summary summary;
	Solve(options, &problem, &summary);
	
	cout << summary.BriefReport() << "\n";
	
	for (int i = 0; i < 120; i++)
	{
		cout <<x[i] <<"  ->  "<<round(x[i]) << endl;

	}


	system("pause");
	return 0;
}


