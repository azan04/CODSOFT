#include <iostream>
#include <time.h>

using namespace std;

void welcomePlayer()
{
	cout << "Welcome to Number Guessing game!" << endl;
	cout << endl << "1.Start Game\n2.Rules\n0.Exit\nChoice: ";
}

void displayRules()
{
	cout << "Rules:\n->When you click on start you will be given an option to choose from 3 difficulty levels and the game will generate a\n  random number which you will have to guess."
		<< "\n->The difficulty levels and the range of random generated are as follows:"
		<< "\n\t1.Easy(0 to 10)\n\t2.Medium(0 to 50)\n\t3.Hard(0 to 100)"
		<< "\n->You will be asked to make your guess on what random number was generated"
		<< "\n->Once you make your guess the game will evaluate your guess and compare it to the generated number."
		<< "\n->If your guess is correct you will win otherwise the game will tell you if your guess was greater or smaller than the\n  number generated."
		<< "\n->Then you can make your next guess and the continues in this fashion."
		<< "\n->You can quit the game at any time by entering the number \"-1\"."
		<< "\n->If you do so the game will end and you will lose and the number generated will be displayed."
		<< "\n->From here you can restart the game or quit it."
		<< "\n\n1.Return to main menu\nInput: " << endl;
}

int playGame(int difficulty)
{
	int randNum = 0;

	if (difficulty == 1)
		randNum = (rand() % 10) + 1;
	else if (difficulty == 2)
		randNum = (rand() % 50) + 1;
	else
		randNum = (rand() % 100) + 1;

	int input = -2;

	cout << "Guess the number!" << endl;
	cout << "Enter your guess: ";
	cin >> input;
	if (input == randNum)
	{
		system("CLS");
		cout << "Correct Guess!\nYou win!!" << endl;
		cout << "1.Play Again\n0.Exit\nChoice: ";
		cin >> input;
		while (input != 1 && input != 0)
		{
			system("CLS");
			cout << "Invalid choice! Try again\n";
			cout << "1.Play Again\n0.Exit\nChoice: ";
			cin >> input;
			return input;
		}
		return input;
	}
	while (1)
	{
		if (input == randNum)
		{
			system("CLS");
			cout << "Correct Guess!\nYou win!!" << endl;
			cout << "1.Play Again\n0.Exit\nChoice: ";
			cin >> input;
			while (input != 1 && input != 0)
			{
				system("CLS");
				cout << "Invalid choice! Try again\n";
				cout << "1.Play Again\n0.Exit\nChoice: ";
				cin >> input;
				return input;
			}
			return input;
		}
		else if (input > randNum)
		{
			system("CLS");
			cout << "Guess the number!" << endl;
			cout << "You Guessed a number greater than the desired number!\nGiveup: -1\nGive it another try\nGuess:";
			cin >> input;
		}
		else if (input < randNum)
		{
			system("CLS");
			cout << "Guess the number!" << endl;
			cout << "You Guessed a number smaller than the desired number!\nGiveup: -1\nGive it another try\nGuess:";
			cin >> input;
		}
		else if (input == -1)
		{
			system("CLS");
			cout << "You Quit!\nBetter Luck Next Time." << endl;
			cout << "1.Play Again\n0.Exit\nChoice: ";
			cin >> input;
			while (input != 1 && input != 0)
			{
				system("CLS");
				cout << "Invalid choice! Try again\n";
				cout << "1.Play Again\n0.Exit\nChoice: ";
				cin >> input;
				return input;
			}
			return input;
		}
	}

	return input;
}

int main()
{
	srand(time(0));
	int input = -1;
	welcomePlayer();
	cin >> input;
	while (1)
	{
		if (input == 1)
		{
			system("CLS");
			cout << "Choose difficulty:"
				<<"\n->1.Easy(Guess number between 0 and 10)"
				<< "\n->2.Medium(Guess number between 0 and 50)"
				<< "\n->3.Hard(Guess number between 0 and 100"
				<< "\nChoice: ";
			int difficulty = 0;
			cin >> difficulty;
			while (difficulty <= 0 || difficulty >= 4)
			{
				system("CLS");
				cout << "Invalid choice! Try again" << endl;
				cout << "Choose difficulty:\n->1.Easy(Guess number between 0 and 10)"
					<< "\n->2.Medium(Guess number between 0 and 50)"
					<< "\n->3.Hard(Guess number between 0 and 100"
					<< "\nChoice: ";
				cin >> difficulty;
			}
			system("CLS");
			input = playGame(difficulty);
		}
		else if (input == 2)
		{
			system("CLS");
			displayRules();
			cin >> input;
			while (input != 1)
			{
				system("CLS");
				cout << "You Entered an incorrect number!" << endl;
				displayRules();
				cin >> input;
			}
			system("CLS");
			welcomePlayer();
			cin >> input;
		}
		else if(input == 0)
		{
			cout << "Are you sure you want to quit?"
				<< "\n1.Return to game\n0.Exit\nChoice: ";
			cin >> input;
			if (input == 0)
				break;
			system("CLS");
			welcomePlayer();
			cin >> input;
		}
		else
		{
			cout << "You entered an invalid number!\nTry again\nChoice: " << endl;
			cin >> input;
		}
	}
	return 0;
}