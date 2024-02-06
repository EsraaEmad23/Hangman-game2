#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>   

#define EASY_CHANCES 6
#define NORMAL_CHANCES 4
#define HARD_CHANCES 2
#define MAX_WORDS 30
#define MAX_WORD_LENGTH 20

int chances = 0;
char x = ' ';

void displayHangman(int chances);
void playHangman(int difficulty);
void printWelcomeMessage();
void printCreatedByMessage();
void printInstructions();
void displayHelpMessage();

int main() {
    do {
        srand(time(NULL));

        printf("\n");
        printWelcomeMessage();

        // Display menu and get user's choice
 
        printf("          ##################################### \n");
        printf("               play (1) \n");
        printf("               created by (2) \n");
        printf("               instruction (3) \n");
        printf("               exit (4) \n");
        printf("                            you want....");

        int choice1;
        if (scanf("%d", &choice1) != 1 || (choice1 < 1 || choice1 > 4)) {
            printf("Invalid input. Please enter a valid menu option.\n");
            // Handle invalid input  
            continue;
        }

        // Handle user's choice
        switch (choice1) {
            // Play Hangman
            case 1:
                printf("          ##################################### \n");
                printf("          game mode :\n");
                printf("               easy (1) \n");
                printf("               normal (2) \n");
                printf("               hard (3) \n");
                printf("                            you want....");
                int choice2;
                if (scanf("%d", &choice2) != 1 || (choice2 < 1 || choice2 > 3)) {
                    printf("Invalid input. Please enter a valid difficulty level.\n");
                    // Handle invalid input  
                    continue;
                }
                printf("          ##################################### \n");
                playHangman(choice2);
                break;

            case 2:
                // Display game creator message
                printCreatedByMessage();
                break;

            case 3:
                // Display game instructions
                printInstructions();
                break;

            case 4:
                // Exit the game
                break;
        }

        printf("                             Back:B\n\n");
        printf(" press on Back if you want to return \n ");
        printf(" anything else if you dont \n ");
        scanf(" %c", &x);

    } while (x == 'B' || x == 'b');

    return 0;
}


// Draw hangman  art  based on the number of chances
void displayHangman(int chances) {
    if (chances == 6) {
        printf("          ____________\n"
               "          |/          | \n"
               "          |/            \n"
               "          |              \n"
               "          |           \n"
               "__________|___________\n");
    } else if (chances == 5) {
        printf("          ____________\n"
               "          |/          | \n"
               "          |/          O \n"
               "          |              \n"
               "          |           \n"
               "__________|___________\n");
    } else if (chances == 4) {
        printf("          ____________     \n"
               "          |/          |    \n"
               "          |/          O    \n"
               "          |           |   \n"
               "          |                \n"
               "__________|___________     \n");
    } else if (chances == 3) {
        printf("          ____________\n"
               "          |/          | \n"
               "          |/          O \n"
               "          |          /|   \n"
               "          |               \n"
               "__________|___________\n");
    } else if (chances == 2) {
        printf("          ____________\n"
               "          |/          | \n"
               "          |/          O \n"
               "          |          /|\\   \n"
               "          |                \n"
               "__________|___________\n");
    } else if (chances == 1) {
        printf("          ____________\n"
               "          |/          | \n"
               "          |/          O \n"
               "          |          /|\\   \n"
               "          |          /     \n"
               "__________|___________\n");
    }
     else if (chances == 0){
           printf("          ____________\n"
               "          |/          | \n"
               "          |/          O \n"
               "          |          /|\\   \n"
               "          |          / \\    \n"
               "__________|___________\n");
    }
    
}



// Play the Hangman game based on the chosen difficulty level
void playHangman(int difficulty) {
 char title[][20] = {"colour","colour","colour", "animal","animal","animal", "mounth","mounth","mounth", "social media","social media", "days", "country", "feeling", "organ", "furniture", "time", "weather", "job", "science", "TeamGleader", "teamGmember1","teamGmember2","teamGmember3","teamGmember4"};
 char words[][20] = {"blue","orange","green", "cat","monkey","donkey", "april","march","mai", "itop","twitter", "monday", "egypt", "angry", "heart", "chair", "morning", "sunny", "engineer", "math", "ibrahem", "eman","esraa","malk","youssef"};

    int random1 = rand() % 25;
    int lengthhint = strlen(title[random1]);
    int length = strlen(words[random1]);
    int corrects = 0;
    int oldcorrects = 0;

   
    switch (difficulty) {
        case 1:
            chances = 6;
            break;
        case 2:
            chances = 4;
            break;
        case 3:
            chances = 2;
            break;
        default:
            chances = 6;    // Default to easy difficulty
    }

    char guess;
    char guessold = ' ';
    char space[length];

    for (int space0 = 0; space0 < length; space0++) {
        space[space0] = '-';
    }

    while (corrects < length && chances > 0) {
        displayHangman(chances);

        printf("               the hint is : ");
        for (int hintpass = 0; hintpass < lengthhint; hintpass++) {
            printf("%c", title[random1][hintpass]);
        }
        printf("\n");

        printf("               the word is : ");
        for (int space2 = 0; space2 < length; space2++) {
            printf("%c", space[space2]);
        }
        printf("\n");

        printf("                     guess the letter....");
        scanf("\n%c", &guess);

        int incorrectGuess = 1;  // Flag to check if the guess is incorrect

        for (int pass = 0; pass < length; pass++) {
            if (words[random1][pass] == guess&& space[pass]!=guess) {
                corrects++;
                space[pass] = guess;
                incorrectGuess = 0;  // Set flag to 0 for correct guess
            }
        }

        if (incorrectGuess) {
            // Display help message for incorrect guess
            displayHelpMessage();
            printf("                     wrong guess....\n");
            chances--;
        } else {
            printf("                     right guess....\n");
        }

        printf("          ##################################### \n");
    }

    if (chances > 0) {
        printf("               the word is : ");
        for (int space3 = 0; space3 < length; space3++) {
            printf("%c", words[random1][space3]);
        }
        printf("\n");
	    printf("       O  \n ");
		printf("     /|\\    \n ");
		printf("     / \\  \n ");
        printf("   thanks, you saved me \n       --> I am sure you are one of IEEEiens \n\n");
    }
	else {
        printf("               the word is : ");
        for (int space3 = 0; space3 < length; space3++) {
            printf("%c", words[random1][space3]);
        }
        printf("\n");
        displayHangman(chances);
        printf("               sorry, he is dead.....!!!!!!!!!!\n           -->   Excuse me,you are stubid \n\n");
    }
}



// Display help message
void displayHelpMessage() {
    if (chances > 1) {
        printf("     \\O/ \n ");
        printf("     |         Help me, focus more. \n ");
        printf("    / \\ \n ");
    }
}

// Display a welcome message
void printWelcomeMessage() {
    printf("          ##################################### \n");
    printf("               welcome to hangman game \n");
    printf("                               have a nice time \n");
    printf("          ##################################### \n");
}

// Display a message about the game creator
void printCreatedByMessage() {
    printf("########################################### \n");
    printf(" IEEE BUB SB \n");
    printf(" TEAM G IEEEIANS : \n");
    printf(" TEAM G Leader :Ibrahem \n");
    printf(" member 1: Eman \n member 2: Esraa \n member 3: Malk \n member 4: Youssef");
    printf(" thank you for playing our game, wish a great time for you \n");
    printf("############################################ \n\n");
}

// Display game instructions
void printInstructions() {
    printf("###################### \n");
    printf("Rules: \n");
    printf("Maximum 6 mistakes are allowed in easy level \n");
    printf("Maximum 4 mistakes are allowed in normal level \n");
    printf("Maximum 2 mistakes are allowed in difficult level \n");
    printf("All alphabet are in lower case \n");
    printf("don't repeat the letter, it costs you chances \n");
    printf("check the hint to guess correctly \n");
    printf("finally, try to save the man \n");
    printf("If you feel that you are so smart, do not try to enter more than one letter at a time, OR.....\n");
    printf("###################### \n");
}
