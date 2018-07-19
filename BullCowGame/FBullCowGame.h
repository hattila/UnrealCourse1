#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to 0.
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

//enum class EResetStatus
//{
//	No_Hidden_Word,
//	OK
//};

class FBullCowGame {
public:
	FBullCowGame(); // constructor
	// ~FBullCowGame(); // destructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset(); // TODO make a more rich return value.
	FBullCowCount SubmitValidGuess(FString);

private:
	// initialization is in the constructor
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	// bool IsIsogram(string);
};