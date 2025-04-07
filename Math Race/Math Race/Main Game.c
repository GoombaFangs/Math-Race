#include "Player.c"

#define MAX_PLAYERS 3



int main() {
    printf("Welcome to Math Race!\n\n");
    

    struct Player players[MAX_PLAYERS];
    printf("Enter Your name: ");
    fgets(players[0].name, sizeof(players[0].name), stdin);

    // Remove newline character if present
    size_t len = strlen(players[0].name);
    if (len > 0 && players[0].name[len - 1] == '\n') {
        players[0].name[len - 1] = '\0';
    }
   

    printf("\n--- Player List ---\n");
    printf("Player name: %s\n", players[0].name);

}
