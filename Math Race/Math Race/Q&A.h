#ifndef QA_H
#define QA_H

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "Visuals.h"

#define NUMBER_OF_QUESTIONS 5

double GenerateAndCheckQuestion(int round);
int AnswerCalculator(int questions[]);
int OperatorCalculator(int totalSum, int nextNumber, int operatorIndex);
void PrintOperator(int operatorIndex);
double AnswerChecker(int questionAnswer, int questions[]);
void PrintQuestion(int question[]);
void GenerateQuestion(int minRandomNumber, int maxRandomNumber, int multiplication, int questions[]);
#endif