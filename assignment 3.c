#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int me, comp;
    int round;
    int myScore = 0, compScore = 0;

    srand(time(0));

    for(round = 1; round <= 3; round++) {

        printf("\n--- Round %d ---\n", round);
        printf("0 = Rock\n1 = Paper\n2 = Scissors\n");

        printf("Enter your choice (0/1/2): ");
        scanf("%d", &me);

        if(me < 0 || me > 2) {
            printf("Invalid choice! Try this round again.\n");
            round--;   // repeat same round
            continue;
        }

        comp = rand() % 3;

        printf("You chose: ");
        if(me == 0) printf("Rock");
        else if(me == 1) printf("Paper");
        else printf("Scissors");

        printf("\nComputer chose: ");
        if(comp == 0) printf("Rock");
        else if(comp == 1) printf("Paper");
        else printf("Scissors");

        if(me == comp) {
            printf("\nResult: Draw!\n");
        }
        else if((me == 0 && comp == 2) ||
                (me == 1 && comp == 0) ||
                (me == 2 && comp == 1)) {
            printf("\nResult: You Win!\n");
            myScore++;
        }
        else {
            printf("\nResult: Computer Wins!\n");
            compScore++;
        }

        printf("Score ? You: %d | Computer: %d\n", myScore, compScore);
    }

    printf("\n===== Final Result after 3 Rounds =====\n");
    if(myScore > compScore)
        printf("?? You WON the game\n");
    else if(compScore > myScore)
        printf("Computer WON the game\n");
    else
        printf("The game is a DRAW\n");

    return 0;
}
