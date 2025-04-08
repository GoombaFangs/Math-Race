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
	printf("game tuturial\n");// need to be more detailed

	int round = 0;
	int try = 0;
	int penalty = 0;
	

	while (round < 3)
	{
		//timer start
		printf("Round %d\n", round + 1);
		for (int i = 0; i < 10; i++)//round details
		{
			//random question by difficukty (bass on round number)
			printf("Question %d: What is %d + %d?\n", i + 1, i, i);	// need to get random number
			int answer;
			scanf_s("%d", &answer);
			printf("Your answer: %d\n", answer); //answer checker
		}
		//timer stop
		round++;
	}


}
