// KeywordsCIA.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"glasses", "Whould you hit someone with these on?"},
		{"labored", "Out of breath are we?"},
		{"jumble", "What is this program doing again?"},
		{"welcome", "When someone comes home you?"},
		{"wheels", "These on the bus go round and round."},
		{"borrow", "What your neighbor does then never returns it...bob."},
		{"bright", "Shine ______ like a diamond."},
		{"round", "It's like a circle, it never ends."},
		{"copy", "What you do when you want to make a duplicate."},
		{"sun", "Fire in the sky."}
	};
	char again = 'n';
	int tries = 0;
	do
	{
		cout << "\t\t\tWelcome to the CIA Code Breaker Training Simulation Program for recruits.\n\n";
		cout << "Unscramble the letters to make the code.\n";
		cout << "Enter 'hint' for a hint.\n";
		cout << "Enter 'quit' to quit the program.\n\n";
		for (int j = 0; j < 3; ++j)
		{
			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD];
			string theHint = WORDS[choice][HINT];

			string jumble = theWord;
			int length = jumble.size();
			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}
			cout << "The code is: " << jumble;

			string guess;
			cout << "\n\nYour guess: ";
			cin >> guess;

			while ((guess != theWord) && (guess != "quit"))
			{
				if (guess == "hint")
				{
					cout << theHint;
				}
				else
				{
					cout << "That's not correct.";
					++tries;
				}

				cout << "\n\nYour guess: ";
				cin >> guess;
			}
			if (guess == theWord)
			{
				cout << "\nThat is the correct answer.\n";
			}
		}
		cout << "\nYou pass the simulation.\n";
		cout << "It took " << tries << " to guess the code correctly.\n";
		cout << "With an average of " << tries / 3 << ".\n";
		cout << "Would you like to retake the simulation?(y/n)";
		cin >> again;
	} while (again != 'n');

	return 0;
}