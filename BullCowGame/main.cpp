// first c++ app

/* This is the console executeable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
// #include "WouldBeMyLib.h"
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

// function prototyes ?
void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintGuess(FText);
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// entry point of the app
int main ()
{
	do {
		PrintIntro();
		PlayGame();
		// AskToPlayAgain();
	} while (AskToPlayAgain());
	
	return 0; // exit app
}

/**
* void function. Are annotations a thing?
*/
void PrintIntro()
{
	// introduce the game
	// std::cout << "Welcome to Bulls and Cows\n"; // std::cout is the namespaced syntax
	std::cout << "\nWelcome to Bulls and Cows\n"; // << endl is endline as well
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n\n";

	return; // must return, even if it's void
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game is NOT won
	// and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
	
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";

		// std::cout << "Your guess was: " << Guess << "\n\n";
	}

	// Summarize game
	if (BCGame.IsGameWon()) {
		std::cout << "Grats! You won in " << (BCGame.GetCurrentTry() -1)  << " tries!\n";
	}
	else {
		std::cout << "Sorry man, you didn't make it.\n";
	}
	
}

FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = ""; // uppercase variable name, UE coding standard

	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		// get a guess from the user
		std::cout << "Try " << CurrentTry << ".: Enter your guess: ";

		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Plese enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Plese enter an isogram! (No repeating letters)\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Plese enter an all lowercase word!\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
		std::cout << std::endl;

	} while (Status != EGuessStatus::OK); // keep looping until we get no errors

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";

	std::getline(std::cin, Response);

	// is valid input
	if (Response[0] != 'y' && Response[0] != 'Y' && Response[0] != 'n' && Response[0] != 'N') {
		std::cout << "Invalid character: " << Response[0] << "\n";
		// AskToPlayAgain();
		return false;
	}

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

