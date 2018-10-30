#include <iostream>
#include <vector>
#include <cmath>
#define PI 3.14159265358979323846
using namespace std;

typedef double(*Function_T)(double);

class Function {
private:
	Function_T rule;
	vector<double> rect; // area of each rectangle
	vector<double> interval; // "domain" of our function
	double area; // the final result after integration.
	double step;
	int len;

public:
	static vector<double> linspace(double min, double max, int n) {
		vector<double> result;
		int iterator = 0;

		for (int i = 0; i < n - 1; i++) {
			double temp = min + i * (max - min) / (floor((double)n) - 1);
			result.insert(result.begin() + iterator, temp);
			iterator++;
		}

		result.insert(result.begin() + iterator, max);
		return result;
	}

	Function() {
		area = 0;
		step = 0.0001;
		len = 0;
		rule = NULL;
	}
	
	void setStep(double step) {
		this->step = step;
	}

	void setRule(Function_T rule) {
		this->rule = rule;
	}

	void setDomain(double a, double b) {
		this->len = round(((b - a) / step) + 0.5);
		this->interval = linspace(a, b, len);
		this->rect = linspace(a, b, len);
	}

	void run(void) {
		for (int i = 0; i < len; ++i) {
			rect[i] = rule(interval[i]) * step;
			area += rect[i];
		}
	}

	double getArea(void) {
		return area;
	}
};

double f(double x) {
	return (2 * x);
}

int main(void)
{
	Function F = Function();
	
	F.setStep(0.00001);
	F.setDomain(0, 2);
	F.setRule(&f);
	F.run();

	cout << "The area under the curve: " << F.getArea() << endl;
	system("pause");
	return 0;
}
