#ifndef QA_H
#define QA_H

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define NUBMER_OF_QUESTIONS 5

int OperatorCalculator(int totalSum, int newNubmer, int operatorIndex);
void PrintOperator(int operatorIndex);
void PrintQuestion(int questions[]);
double AnswerChecker(int questionAnswer, int question[]);
int AnswerCalculator(int questions[]);
int GenerateQuestion(int minRandomNumber, int maxRandomNumber, int muliplication, int questions[]);


double GenerateAndCheckQuestion(int round)
{
	double roundPenalty = 0;
	if (round < 0 || round > 2) // stops bugs if round number is wrong
	{
		printg(0.025, "Invalid round number. Please enter a number between 0 and 2.\n");
		return -1; // Return an error code
	}

	for (int i = 0; i < NUBMER_OF_QUESTIONS; i++)
	{
		int question[5] = { 0,0,0,0,0 };
		if (round == 0) // Difficulty based on round nubmer 
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
		clearConsole();
		PrintQuestion(question);
		roundPenalty += AnswerChecker(AnswerCalculator(question), question);
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

int OperatorCalculator(int totalSum, int nextNubmer, int operatorIndex)
{
	switch (operatorIndex)
	{
	case 0:
		return totalSum + nextNubmer;

	case 1:
		return totalSum - nextNubmer;

	case 2:
		return totalSum * nextNubmer;

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
	if (questions == NULL)  // Check for NULL pointer bug
	{
		printg(0.01, "Error: question is NULL\n");
		return -1; // Return an error code
	}

	int playerAnswer = 0;
	double penalty = 0.0;
	for (int tries = 0; tries < 3; tries++)
	{
		int error = 1;
		while (error == 1)
		{
			if (scanf_s("%d", &playerAnswer) != 1 || getchar() != '\n')
			{
				while (getchar() != '\n');
				printg(0.01, "Invalid input. Please enter a valid number.\n");
				HoldSeconds(1);
				PrintQuestion(questions);
				error = 1; 
			}
			else
			{
				error = 0;
			}	
		}
		
		if (playerAnswer != questionAnswer)
		{
			penalty += 5.0;
			if (tries == 2)
			{
				printg(0.01, "Wrong answer, Next Question\nPenalty: 5 Seconds, Be careful!\n");
				HoldSeconds(1);
				PrintQuestion(questions);
			}
			else
			{
				printg(0.01, "Wrong answer, Try again!\nPenalty: 5 Seconds, Be careful!\n");
				HoldSeconds(1);
				PrintQuestion(questions);
			}
		}
		else
		{
			printg(0.01, "Correct!\n");
			HoldSeconds(0.6);
			return penalty; // No penalty
			break;
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

int GenerateQuestion(int minRandomNumber, int maxRandomNumber, int includeMuliplication , int questions[])
{
	int numbers[3] = { 0,0,0 };
	int operatorIndex1 = 0;
	int operatorIndex2 = 0;
	numbers[0] = rand() % maxRandomNumber + minRandomNumber;
	numbers[1] = rand() % maxRandomNumber + minRandomNumber;
	numbers[2] = rand() % maxRandomNumber + minRandomNumber;
	operatorIndex1 = rand() % includeMuliplication;
	operatorIndex2 = rand() % includeMuliplication;
	questions[0] = numbers[0];
	questions[1] = operatorIndex1;
	questions[2] = numbers[1];
	questions[3] = operatorIndex2;
	questions[4] = numbers[2];
	return questions;
}
#endif

