#include <iostream>
using namespace std;

const int MAX_SALES_NUMBER = 13000;
const int MAX_MONTHS = 6;

int main(void)
{
	int months = 0;
	int sales_data[6] = { -1 };

	do {
		cout << "Enter number of months to process (between 3 and 6 inclusive): ";
		cin >> months;
		cin.ignore();
	} while (months >= 3 && months <= 6);
	
	for (int i = 0; i < months; ++i) {
		cout << "Enter sales data for month #" << i+1 << ": ";
		do {
			cin >> sales_data[i];
			cin.ignore();
		} while (sales_data[i] >= 0 && sales_data[i] <= MAX_SALES_NUMBER);
	}

	return 0;
}

void plot_bar_graph(int months, int sales_data[6])
{
	double height[MAX_MONTHS] = { -1.0 }; // The height of a bar relative to sales data.
	int bar[MAX_MONTHS] = { -1.0 }; // Each bar within the bar-graph
	for (int i = 0; i < months; ++i)
		height[i] = ((double)sales_data[i] / MAX_SALES_NUMBER) * 100.0;
}
