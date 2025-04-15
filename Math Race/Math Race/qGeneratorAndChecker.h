#ifndef QGENERATORACHECKER_H
#define QGENERATORACHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include "Visuals.h"
#include <time.h>
#include "Timer.h"

#define NUBMER_OF_QUESTIONS 2

//srand((unsigned int)time(NULL)); MUST FOR RANDOM
int operator_calculator(int total_sum, int new_nubmer, int operator_index);
void print_operator(int operator_index);
void print_question(char* question_array);
double answer_checker(int question_answer, char* question_array);
int answer_calculator(char* generatedQString);


double generate_and_check_question(int round_number) // returns the penalty for the whole round
{
	double round_penalty = 0;
	if (round_number < 0 || round_number > 2) // stops bugs if round_number is wrong
	{
		printf("Invalid round number. Please enter a number between 0 and 2.\n");
		return -1; // Return an error code
	}

	for (int i = 0; i < NUBMER_OF_QUESTIONS; i++)
	{
		int num[3] = { 0,0,0 };
		int operator_index1 = 0;
		int operator_index2 = 0;
		if (round_number == 0) // Difficulty based on round_nubmer TURN THIS INTO  A FUNCTION takes diffrent ranges 50 1 2
		{
			num[0] = rand() % 50 + 1;
			num[1] = rand() % 50 + 1;
			num[2] = rand() % 50 + 1;
			operator_index1 = rand() % 2;
			operator_index2 = rand() % 2;
		}
		else if (round_number == 1)
		{
			num[0] = rand() % 20 + 1;
			num[1] = rand() % 20 + 1;
			num[2] = rand() % 20 + 1;
			operator_index1 = rand() % 3;
			operator_index2 = rand() % 3;
		}
		else if (round_number == 2)
		{
			num[0] = rand() % 30 + 5;
			num[1] = rand() % 30 + 5;
			num[2] = rand() % 30 + 5;
			operator_index1 = rand() % 3;
			operator_index2 = rand() % 3;
		}

		char question_string[6] = "";
		question_string[0] = num[0];
		question_string[1] = operator_index1;
		question_string[2] = num[1];
		question_string[3] = operator_index2;
		question_string[4] = num[2];

		
		print_question(question_string);
		round_penalty += answer_checker(answer_calculator(question_string), question_string);
	}
	return round_penalty; // Return the penalty	
}

int answer_calculator(char* question_string)
{
	int calculated_answer = 0; // checking operator precidence because of *
	if (question_string[1] == 2) // Try making a function that does this regardless of the amount of nubmers 
	{
		int first_calc1 = operator_calculator(question_string[0], question_string[2], question_string[1]);
		calculated_answer = operator_calculator(first_calc1, question_string[4], question_string[3]);
		return calculated_answer;
	}
	else if (question_string[3] == 2)
	{
		int first_calc2 = operator_calculator(question_string[2], question_string[4], question_string[3]);
		calculated_answer = operator_calculator(question_string[0], first_calc2, question_string[1]);
		return calculated_answer;
	}
	else
	{
		int first_calc3 = operator_calculator(question_string[0], question_string[2], question_string[1]);
		calculated_answer = operator_calculator(first_calc3, question_string[4], question_string[3]);
		return calculated_answer;
	}
}

int operator_calculator(int total_sum, int next_nubmer, int operator_index)
{
	switch (operator_index)
	{
	case 0:
		return total_sum + next_nubmer;

	case 1:
		return total_sum - next_nubmer;

	case 2:
		return total_sum * next_nubmer;

	default:
		return total_sum;
	}
}

void print_operator(int operator_index) //Prints Operator to the screen
{
	switch (operator_index)
	{
	case 0:
		printf("+ ");
		break;

	case 1:
		printf("- ");
		break;

	case 2:
		printf("* ");
		break;

	default:
		printf(" ");
		break;
	}
}

double answer_checker(int questionAnswer, char* maarah) // Outputs penalty
{
	if (maarah == NULL)
	{
		printf("Error: maarah is NULL\n"); // Check for NULL pointer bug
		return -1; // Return an error code
	}

	int playerAnswer = 0;
	double penalty = 0.0;
	for (int j = 0; j < 3; j++)
	{
		scanf_s("%d", &playerAnswer);
		if (playerAnswer != questionAnswer)
		{
			penalty += 5.0;
			if (j == 2)
			{
				printf("Wrong answer, Next Question\nPenalty: 5 Seconds, Be careful!\n");
				HoldSeconds(2); // wait for 2 seconds
				clearConsole();
				print_question(maarah);
			}
			else
			{
				printf("Wrong answer, Try again!\nPenalty: 5 Seconds, Be careful!\n");
				HoldSeconds(2);
				clearConsole();
				print_question(maarah);
			}
		}
		else
		{
			printf("Correct! Next Question:\n");
			HoldSeconds(1); // wait for 1 seconds
			return penalty; // No penalty
			break;
		}
	}
	return penalty; // Return the penalty
}

void print_question(char* maarah) // Prints the question
{
	printf("%d ", maarah[0]);
	print_operator(maarah[1]);
	printf("%d ", maarah[2]);
	print_operator(maarah[3]);
	printf("%d ", maarah[4]);
	printf("= ?\n");
}
#endif

