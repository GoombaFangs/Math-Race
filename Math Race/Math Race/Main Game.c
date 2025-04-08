#include "Player.c"

#define MAX_PLAYERS 3

void InputPlayerName() 
{
    struct Player players[MAX_PLAYERS];
    printf("Enter Your name: ");
    fgets(players[0].name, sizeof(players[0].name), stdin);
}

void main() 
{
    printf("Welcome to Math Race!\n\n");
	InputPlayerName();
	printf("game tuturial\n");

	int round = 0;
	int try = 0;
	int penalty = 0;
	

	//timer start

	for (int i = 0; i < 10; i++)
	{
		//random question by difficukty (bass on round number)
		printf("Question %d: What is %d + %d?\n", i + 1, i, i);	// need to get random number
		int answer;
		scanf_s("%d", &answer);
		printf("Your answer: %d\n", answer);
		//answer check
	}

}
