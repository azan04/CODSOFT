#include <iostream>
#include <iomanip>

using namespace std;

void play()
{
	char platform[3][3] = { '\0' };
	for (int i = 0; i < 9; i++)
		platform[i / 3][i % 3] = i + '1';

	int count = 0;
	bool flag = 0;
	while (!flag)
	{
		system("CLS");
		for (int i = 0; i < 3; i++)
		{
			cout << platform[i][0] << " | " << platform[i][1] << " | " << platform[i][2] << endl;
			if (i != 2)
				cout << "----------" << endl;
		}
		if (count % 2 == 0)
		{
			cout << "Player 1's turn"
				<< "\nEnter the position where you want to play: " << endl;
			int location = 0;
			cin >> location;
			if (location >= 1 && location <= 9)
			{
				location--;
				if (platform[location / 3][location % 3] != 'X' && platform[location / 3][location % 3] != 'O')
					platform[location / 3][location % 3] = 'X';
				else
					count--;
			}
		}
		else
		{
			cout << "Player 2's turn"
				<< "\nEnter the position where you want to play: " << endl;
			int location = 0;
			cin >> location;
			if (location >= 1 && location <= 9)
			{
				location--;
				if (platform[location / 3][location % 3] != 'X' && platform[location / 3][location % 3] != 'O')
					platform[location / 3][location % 3] = 'O';
				else
					count--;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (platform[i][0] == platform[i][1] && platform[i][1] == platform[i][2])
			{
				system("CLS");
				for (int i = 0; i < 3; i++)
				{
					cout << platform[i][0] << " | " << platform[i][1] << " | " << platform[i][2] << endl;
					if (i != 2)
						cout << "----------" << endl;
				}
				if (platform[i][0] == 'X')
					cout << "Player 1 Wins!!" << endl;
				else
					cout << "Player 2 Wins!!" << endl;
				flag = 1;
				break;
			}
			else if (platform[0][i] == platform[1][i] && platform[1][i] == platform[2][i])
			{
				system("CLS");
				for (int i = 0; i < 3; i++)
				{
					cout << platform[i][0] << " | " << platform[i][1] << " | " << platform[i][2] << endl;
					if (i != 2)
						cout << "----------" << endl;
				}
				if (platform[0][i] == 'X')
					cout << "Player 1 Wins!!" << endl;
				else
					cout << "Player 2 Wins!!" << endl;
				flag = 1;
				break;
			}
		}
		if (platform[0][0] == platform[1][1] && platform[1][1] == platform[2][2])
		{
			system("CLS");
			for (int i = 0; i < 3; i++)
			{
				cout << platform[i][0] << " | " << platform[i][1] << " | " << platform[i][2] << endl;
				if (i != 2)
					cout << "----------" << endl;
			}
			if (platform[0][0] == 'X')
				cout << "Player 1 Wins!!" << endl;
			else
				cout << "Player 2 Wins!!" << endl;
			flag = 1;
			break;
		}
		else if (platform[0][2] == platform[1][1] && platform[1][1] == platform[2][0])
		{
			system("CLS");
			for (int i = 0; i < 3; i++)
			{
				cout << platform[i][0] << " | " << platform[i][1] << " | " << platform[i][2] << endl;
				if (i != 2)
					cout << "----------" << endl;
			}
			if (platform[0][2] == 'X')
				cout << "Player 1 Wins!!" << endl;
			else
				cout << "Player 2 Wins!!" << endl;
			flag = 1;
			break;
		}
		else if (count == 8)
		{
			system("CLS");
			for (int i = 0; i < 3; i++)
			{
				cout << platform[i][0] << " | " << platform[i][1] << " | " << platform[i][2] << endl;
				if (i != 2)
					cout << "----------" << endl;
			}
			cout << "Draw!!" << endl;
			flag = 1;
			break;
		}

		count++;
	}
	while(1)
	{
		cout << "1.Play again"
			<< "\n2.Back to Main Menu"
			<< "\nChoice: ";
		int choice = -1;
		cin >> choice;
		if (choice == 1)
		{
			play();
			break;
		}
		else if (choice == 2)
		{
			return;
		}
		else
		{
			system("CLS");
			cout << "You entered an invalid choice!\nTry again!" << endl;
		}
	}

}
void rules()
{
	cout << "->The game is played on a 3x3 grid."
		<< "\n->Two players take turns to mark a square with their symbol(X or O)."
		<< "\n->The goal is to get three of your symbols in a row horizontally, vertically, or diagonally."
		<< "\n->The game ends when one player achieves a winning combination or when the grid is full(resulting in a draw)."
		<< "\n->Players take turns until the game is over, and the first player to get three in a row(Vertical, Horizontal or Diagonal) wins."
		<< "\n1.Back to Main Menu"
		<< "\nChoice: ";
	int choice = -1;
	cin >> choice;
	if (choice == 1)
		return;
	else
	{
		system("CLS");
		cout << "Invalid choice!\nTry again\n";
		rules();
	}
}

int main()
{
	int choice = 0;
	while (1)
	{
		cout << "----Tic Tac Toe----" << endl;
		cout << "1. Play"
			<< "\n2. Rules"
			<< "\n0. Exit"
			<< "\nChoice: ";
		cin >> choice;

		if (choice == 1)
		{
			play();
			system("CLS");
		}
		else if (choice == 2)
		{
			rules();
			system("CLS");
		}
		else if (choice == 0)
			return 10;
		else
		{
			system("CLS");
			cout << "You entered an invalid choice!\nTry again!" << endl;
		}
	}
	return 0;
}