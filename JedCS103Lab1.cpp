#include <iostream>
using namespace std;

//Function Prototypes
void Line(int dashes);
void DrawHangMan();
int Play(char check);
void InvertHangMan();
void Win();

int main()
{
	//Initial Output
	cout << "Welcome to play hangman. This game is to check your spelling skill\n";//Strange phrasing, spacing etc are preserved from the brief throughout
	Line(66);//Will create 66 dashes in a line
	DrawHangMan();
	cout << "\nGuess the missing letter in Yo_bee : ";

	//Gameplay
	char answer;
	cin >> answer;
	
	int result = Play(answer);//Passing player's answer as argument and setting return value as variable value
	
	if (result == 0) {//0 indicates a loss
		cout << "Sorry, try again\nGuess the missing letter in Yo_bee : ";
		cin >> answer;//Overwriting same variable from before is fine and saves memory; same applies to 'result' variable
		result = Play(answer);

		if (result == 0) {
			cout << "Sorry, try again\nGuess the missing letter in Yo_bee : ";
			cin >> answer;
			result = Play(answer);

			if (result == 0) {
				InvertHangMan();
			}

			else {//If the value is not a 0 then it must be a 1 (which indicates a win) as those are the only two possibilities I have coded
				Win();
			}
		}

		else {
			Win();
		}

	}

	else {
		Win();
	}
}

//Function Definitions
void Line(int dashes) {
	for (int loops = 0; loops < dashes; loops++) {//Draws as many dashes as the argument passed
		cout << "-";
	}
}

void DrawHangMan() {
	cout << "\n   ____\n  |    |\n  |    o\n  |   \\|/\n  |    |\n  |   / \\\n  |\n  |\n-----";//Draws initial hangman
}

int Play(char check) {
	if (check == 'o' || check == 'O') {//Using capital letters isn't a spelling mistake so I made capital O a success
		return 1;//Returning 1 indicates a win
	}
	else {
		return 0;//Returning 0 indicates a loss
	}
}

void InvertHangMan() {
	cout << "\n Your guess is wrong\n\n   ____\n  |    |\n  |   /|\\\n  |    |\n  |   /o\\\n  |\n  |\n-----";//Draws inverted hangman
}

void Win() {
	cout << "\n Your guess is correct\n     o\n    \\|/\n     |\n    / \\";//Draws walkman
}