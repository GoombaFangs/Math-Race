#ifndef QGENERATORACHECKER_H
#define QGENERATORACHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define NUBMER_OF_QUESTIONS 2

int operator_calculator(int total_sum, int new_nubmer, int operator_index);
void print_operator(int operator_index);
void print_question(int question_array[]);
double answer_checker(int questionAnswer, int generated_question[]);
int answer_calculator(int question_array[]);
int generate_question(int min_random_number, int max_random_number, int include_muliplication, int question_array[]);

double generate_and_check_question(int round_number) // returns the penalty for the whole round
{
	double round_penalty = 0;
	if (round_number < 0 || round_number > 2) // stops bugs if round_number is wrong
	{
		printg("Invalid round number. Please enter a number between 0 and 2.\n");
		return -1; // Return an error code
	}

	for (int i = 0; i < NUBMER_OF_QUESTIONS; i++)
	{
		int generated_question[5] = { 0, };
		if (round_number == 0) // Difficulty based on round_nubmer 
		{
			generate_question(1, 10, 2, generated_question);
		}
		else if (round_number == 1)
		{
			generate_question(1, 30, 2, generated_question);
		}
		else if (round_number == 2)
		{
			generate_question(1, 15, 3, generated_question);
		}
		clearConsole();
		print_question(generated_question);
		round_penalty += answer_checker(answer_calculator(generated_question), generated_question);
	}
	return round_penalty; // Return the penalty	
}

int answer_calculator(int question_array[])
{
	int calculated_answer = 0; // checking operator precidence because of *
	if (question_array[1] == 2) // Try making a function that does this regardless of the amount of nubmers 
	{
		int first_calc1 = operator_calculator(question_array[0], question_array[2], question_array[1]);
		calculated_answer = operator_calculator(first_calc1, question_array[4], question_array[3]);
		return calculated_answer;
	}
	else if (question_array[3] == 2)
	{
		int first_calc2 = operator_calculator(question_array[2], question_array[4], question_array[3]);
		calculated_answer = operator_calculator(question_array[0], first_calc2, question_array[1]);
		return calculated_answer;
	}
	else
	{
		int first_calc3 = operator_calculator(question_array[0], question_array[2], question_array[1]);
		calculated_answer = operator_calculator(first_calc3, question_array[4], question_array[3]);
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
		printg("+ ");
		break;

	case 1:
		printg("- ");
		break;

	case 2:
		printg("* ");
		break;

	default:
		printg(" ");
		break;
	}
}

double answer_checker(int questionAnswer, int generated_question[]) // Outputs penalty
{
	if (generated_question == NULL)
	{
		printg("Error:generated_question is NULL\n"); // Check for NULL pointer bug
		return -1; // Return an error code
	}

	int playerAnswer = 0;
	double penalty = 0.0;
	for (int tries = 0; tries < 3; tries++)
	{
		scanf_s("%d", &playerAnswer);
		if (playerAnswer != questionAnswer)
		{
			penalty += 5.0;
			if (tries == 2)
			{
				printg("Wrong answer, Next Question\nPenalty: 5 Seconds, Be careful!\n");
				HoldSeconds(2);; // Sleep for 2 seconds
				print_question(generated_question);
			}
			else
			{
				printg("Wrong answer, Try again!\nPenalty: 5 Seconds, Be careful!\n");
				HoldSeconds(2);
				print_question(generated_question);
			}
		}
		else
		{
			printg("Correct!\n");
			HoldSeconds(0.6); // Sleep for 1 seconds
			return penalty; // No penalty
			break;
		}
	}
	return penalty; // Return the penalty
}

void print_question(int question[]) // Prints the question
{
	printg("%d ", question[0]);
	print_operator(question[1]);
	printg("%d ", question[2]);
	print_operator(question[3]);
	printg("%d ", question[4]);
	printg("= ?\n");
}

int generate_question(int min_random_number, int max_random_number, int include_muliplication /*multiplication 2 exclude 3 include uses operator_calculatur()*/, int question_array[]) {
	int num[3] = { 0,0,0 };
	int operator_index1 = 0;
	int operator_index2 = 0;
	num[0] = rand() % max_random_number + min_random_number;
	num[1] = rand() % max_random_number + min_random_number;
	num[2] = rand() % max_random_number + min_random_number;
	operator_index1 = rand() % include_muliplication;
	operator_index2 = rand() % include_muliplication;
	question_array[0] = num[0];
	question_array[1] = operator_index1;
	question_array[2] = num[1];
	question_array[3] = operator_index2;
	question_array[4] = num[2];
	return question_array;
}
#endif

