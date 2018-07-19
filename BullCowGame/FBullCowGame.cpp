#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 3;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::isGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) { // if the guess isn't an isogram
		return EGuessStatus::Not_Isogram;
	}
	else if (false) { // if the guess is not all lowercase
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) { // if the guess length is wrong
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}

// recieves a VALID guess, increments turn, and return counts
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	int32 GuessWordLength = Guess.length();
	for (int32 i = 0; i < HiddenWordLength; i++) {
		// compare letters against the hidden word
		for (int32 j = 0; j < GuessWordLength; j++) {
			// if they match
			if (Guess[j] == MyHiddenWord[i]) {
				// inc bulls if the place is correct
				// inc cows if not
				if (Guess[j] == MyHiddenWord[j]) {
					BullCowCount.Bulls++;
				} else {
					BullCowCount.Cows++;
				}
			}	
		}
	}

	return BullCowCount;
}
