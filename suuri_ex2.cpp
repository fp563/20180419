#include <stdio.h>
#include <iostream>
#include <math.h>

#define GOLD 1.618033988
#define EPS pow(10,-10)

using namespace std;


double dx = 0.000001;
int count_1 = 0;
int count_2 = 0;
int count_3 = 0;



double f(double x) {
	return (1.0 / x + exp(x));
}

double g(double x) {
	return sin(5 * x) + pow(x - 5, 2);
}

//1階微分
double bibun(double x, double(*func)(double)) {
	return (func(x + dx) - func(x)) / dx;
}

//2階微分
double bibun_2(double x, double(*func)(double)) {
	return (bibun(x + dx, func) - bibun(x, func)) / dx;
}

//黄金分割法
double golden(double minimum, double maximum,double(*func)(double)) {
	double lamda = minimum + (maximum - minimum)*1/(1+GOLD);
	double x = (maximum + lamda) / 2;

	if (abs(lamda - x)<EPS) return lamda;
	if (func(x)<func(maximum) && func(x)<func(lamda)) {
		count_1++;
		return golden(lamda,maximum,func);
	}
	else {
		count_1++;
		return golden(minimum, x,func);
	}
}

//二分割法
double nibun(double minimum, double maximum,double(*func)(double)) {
	double lamda = (minimum + maximum) / 2;
	if (maximum - minimum<EPS) return lamda;

	if (func(lamda + dx) - func(lamda)>0) {
		count_2++;
		return nibun(minimum, lamda,func);
	}
	else {
		count_2++;
		return nibun(lamda, maximum,func);
	}
}

//ニュートン法
double newton(double x0, double(*func)(double)) {
	if (abs(bibun(x0, func) / bibun_2(x0, func)) < EPS) {
		return x0;
	}
	else {
		count_3++;
		return newton(x0 - bibun(x0, func) / bibun_2(x0, func), func);
	}
}


int main() {
	cout << "golden x=" << golden(0.1, 5,f) << endl;
	cout << count_1 << endl;
	cout << "nibun x=" << nibun(0.1, 2,f) << endl;
	cout << count_2 << endl;
	cout << "newton x=" << newton(0.1, f) << endl;
	cout << count_3 << endl;

	cout << endl;
	count_1 = 0;
	count_2 = 0;
	count_3 = 0;
	
	cout << "golden x=" << golden(4,5, g) << endl;
	cout << count_1 << endl;
	cout << "nibun x=" << nibun(4, 5, g) << endl;
	cout << count_2 << endl;
	cout << "newton x=" << newton(4.5, g) << endl;
	cout << count_3 << endl;

	return 0;
}