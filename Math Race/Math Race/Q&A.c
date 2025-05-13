#include "Q&A.h"

int question[5] = { 0,0,0,0,0 };
double penalty = 5.0;
int tries = 0;
int q = 0;

double GenerateAndCheckQuestion(int round)
{
	double roundPenalty = 0;
	if (round < 0 || round > 2) // stops bugs if round number is wrong
	{
		printg(0.025, "Invalid round number. Please enter a number between 0 and 2.\n");
		return -1; // Return an error code
	}

	for (; q < NUMBER_OF_QUESTIONS;)
	{
		PrintBackToMenu();
		if(question[0] == 0)
		{
			if (round == 0) // Difficulty based on round number 
			{
				GenerateQuestion(1, 10, 2, question);
			}
			else if (round == 1)
			{
				GenerateQuestion(1, 30, 2, question);
			}
			else if (round == 2)
			{
				GenerateQuestion(1, 15, 3, question);
			}
		}
		PrintQuestion(question);
    	int result = AnswerChecker(AnswerCalculator(question), question);
		if (result < 0)
		{
			return -1;
		}
		roundPenalty += result;
	}
	if (q == NUMBER_OF_QUESTIONS)
	{
		q = 0;
	}
	return roundPenalty; // Return the penalty	
}

int AnswerCalculator(int questions[])
{
	int answer = 0;
	int firstCalc = 0;
	if (questions[1] == 2) // checking operator precidence because of *
	{
		firstCalc = OperatorCalculator(questions[0], questions[2], questions[1]);
		answer = OperatorCalculator(firstCalc, questions[4], questions[3]);
		return answer;
	}
	else if (questions[3] == 2)
	{
		firstCalc = OperatorCalculator(questions[2], questions[4], questions[3]);
		answer = OperatorCalculator(questions[0], firstCalc, questions[1]);
		return answer;
	}
	else
	{
		firstCalc = OperatorCalculator(questions[0], questions[2], questions[1]);
		answer = OperatorCalculator(firstCalc, questions[4], questions[3]);
		return answer;
	}
}

int OperatorCalculator(int totalSum, int nextNumber, int operatorIndex)
{
	switch (operatorIndex)
	{
	case 0:
		return totalSum + nextNumber;

	case 1:
		return totalSum - nextNumber;

	case 2:
		return totalSum * nextNumber;

	default:
		return totalSum;
	}
}

void PrintOperator(int operatorIndex)
{
	switch (operatorIndex)
	{
	case 0:
		printg(0.015, "+ ");
		break;

	case 1:
		printg(0.015, "- ");
		break;

	case 2:
		printg(0.015, "* ");
		break;

	default:
		printg(0.015, " ");
		break;
	}
}

double AnswerChecker(int questionAnswer, int questions[])
{
	int playerAnswer = 0;
	int keyboardInput;
	int bufferIndex = 0;
	char inputBuffer[10] = { 0 };
	if (questions == NULL)  // Check for NULL pointer bug
	{
		printg(0.01, "Error: question is NULL\n");
		return -1; // Return an error code
	}
	while (1)
	{
		keyboardInput = _getch();
		if (keyboardInput >= '0' && keyboardInput <= '9')
		{
			if (bufferIndex < sizeof(inputBuffer) - 1)
			{
				inputBuffer[bufferIndex++] = keyboardInput;
				putchar(keyboardInput);
			}
		}
		else if (keyboardInput == '-' && bufferIndex == 0)
		{
			inputBuffer[bufferIndex++] = keyboardInput;
			putchar(keyboardInput);
		}
		else if (keyboardInput == '\r') // Enter key
		{
			inputBuffer[bufferIndex] = '\0';
			playerAnswer = atoi(inputBuffer);
			if (playerAnswer != questionAnswer)
			{
				if (tries == 2)
				{
					tries = 0;
					question[0] = 0;
					printg(0.025, "\nWrong answer, Next Question\nPenalty: 5 Seconds, Be careful!\n");
					HoldSeconds(1);
					return penalty;
					break;
				}
				else
				{
					tries++;
					printg(0.01, "\nWrong answer, Try again!\nPenalty: 5 Seconds, Be careful!\n");
					HoldSeconds(1);
					return penalty;
				}
			}
			else
			{
				q++;
				tries = 0;
				question[0] = 0;
				printg(0.01, "\nCorrect!\n");
				HoldSeconds(0.6);
				return 0;
				break;
			}
		}
		else if (keyboardInput == 27) // Escape Key
		{
			q = 0; 
			tries = 0;
			question[0] = 0;
			return -1;
		}
		else if (keyboardInput == '\b' && bufferIndex > 0) // Backspace
		{
			bufferIndex--;
			printf("\b \b"); // Remove the last character from the console
		}
	}
	return penalty;
}

void PrintQuestion(int question[])
{
	printg(0.015, "%d ", question[0]);
	PrintOperator(question[1]);
	printg(0.015, "%d ", question[2]);
	PrintOperator(question[3]);
	printg(0.015, "%d ", question[4]);
	printg(0.015, "= ?\n");
}

void GenerateQuestion(int minRandomNumber, int maxRandomNumber, int multiplication, int questions[])
{
	int numbers[3] = { 0,0,0 };
	int operatorIndex1 = 0;
	int operatorIndex2 = 0;
	numbers[0] = rand() % maxRandomNumber + minRandomNumber;
	numbers[1] = rand() % maxRandomNumber + minRandomNumber;
	numbers[2] = rand() % maxRandomNumber + minRandomNumber;
	operatorIndex1 = rand() % multiplication;
	operatorIndex2 = rand() % multiplication;
	question[0] = numbers[0];
	question[1] = operatorIndex1;
	question[2] = numbers[1];
	question[3] = operatorIndex2;
	question[4] = numbers[2];
}