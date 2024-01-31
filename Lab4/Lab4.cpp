// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// Print out the menu of choices for the user to select from
void printMenu() {
	cout << "Please Select which operation to perform:" << endl;
	cout << "\t1. Factorial" << endl;
	cout << "\t2. Arithmetic Series" << endl;
	cout << "\t3. Geometric Series" << endl;
	cout << "\t4. Exit" << endl;
	cout << "Your Selection: ";
}
void factorial() {
	int X = 0;
	int count = 1;
	int f = 1;
	cout << "Factorial:" << endl << "Please enter a number: ";
	cin >> X;
	while (X <= 0) {
		cout << "Nice try, please enter a POSITIVE number...: ";
		cin >> X;
	}
	cout << X << "! = ";
	cout << count;
	while (count < X) {
		count++;
		cout << " * " << count;
		f = f * count;
	}
	cout << " = " << f << endl;
}
void arithmetic() {
	int D = 0;
	int S = 0;
	int n = 0;
	int count = 1;
	int f = 1;
	cout << "Arithmetic:" << endl << "Enter a number to start at: ";
	cin >> S;
	cout << "Enter a number to add each time: ";
	cin >> D;
	cout << "Enter the number of elements in the series: ";
	cin >> n;
	while (n <= 0) {
		cout << "Nice try, please enter a POSITIVE number...: ";
		cin >> n;
	}
	cout << S;
	f = S;
	while (count < n) {
		count++;
		cout << " + ";
		S = S + D;
		cout << S;
		f = f + S;
	}
	cout << " = " << f << endl;
}
void geometric() {
	int r = 0;
	int a = 0;
	int n = 0;
	int count = 1;
	int f = 1;
	cout << "Geometric:" << endl << "Enter a number to start at: ";
	cin >> a;
	cout << "Enter a number to multiply by each time: ";
	cin >> r;
	cout << "Enter the number of elements in the series: ";
	cin >> n;
	while (n <= 0) {
		cout << "Nice try, please enter a POSITIVE number...: ";
		cin >> n;
	}
	cout << a;
	f = a;
	while (count < n) {
		count++;
		cout << " + ";
		a = a * r;
		cout << a;
		f = f + a;
	}
	cout << " = " << f << endl;
}
int main() {
	int choice;
	char again;
	do {
		printMenu();
		cin >> choice;
		// Quit if user chooses to exit (or any invalid choice)
		if (choice > 3 || choice < 1) {
			return 0;
		}
		else if (choice == 1) {
			factorial();
		}
		else if (choice == 2) {
			arithmetic();
		}
		else if (choice == 3) {
			geometric();
		}
		cout << "Go Again? [Y/N] ";
		cin >> again;
	} while (again == 'y' || again == 'Y');
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
