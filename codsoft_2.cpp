#include <iostream>
#include <cmath>

using namespace std;

double solve(float num1, float num2, char op)
{
	if (op == '+')
		return num1 + num2;
	else if (op == '-')
		return num1 - num2;
	else if (op == '*')
		return num1 * num2;
	else if (op == '/')
		return num1 / num2;
	else if (op == '^')
		return pow(num1, num2);
	
	return -999999999;
}

int main()
{
	float num1 = 0, num2 = 0;
	double ans = 0;
	char operation = '\0';
	cout << "----Calculator----" << endl;
	cout << "Signs for operations:\n"
		<< "\'+\' for addition\n"
		<< "\'-\' for subtraction\n"
		<< "\'*\' for multiplication\n"
		<< "\'/\' for division\n"
		<< "\'^\' for power\n";
	cout << endl << "Enter the first number: ";
	cin >> num1;
	cout << "Enter the second number: ";
	cin >> num2;
	while (1)
	{
		cout << "Enter the operation: ";
		cin >> operation;

		if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^')
			break;
		else
		{
			cout << "Invalid operation. Please enter a valid operation." << endl;
		}
	}
	ans = solve(num1, num2, operation);
	cout << num1 << " " << operation << " " << num2 << " = " << ans;
	return 0;
}