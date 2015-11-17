#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

int secret_number;

void initialize_number_generator();
void choose_new_secret_number();
void read_guesses();

int main() {
    char command;
    
    printf("Guess number between 1 and %d.\n\n", MAX_NUMBER);
    initialize_number_generator();
    do {
        choose_new_secret_number();
        printf("S number has been choosen.\n");    
        read_guesses();
        printf("Play again y/n");
        scanf(" %c", &command);
        printf("\n");
    } while(command == 'y' || command == 'Y');
    
    return 0;
}

void initialize_number_generator() {
    srand((unsigned) time(NULL));
}

void choose_new_secret_number() {
    secret_number = rand() % MAX_NUMBER + 1;
}

void read_guesses() {
    int guess, num_guesses = 0;

    for (;;) {
        num_guesses++;
        printf("Enter number: ");
        scanf("%d", &guess);
        if (guess == secret_number) {
            printf("You won");
            return;
        }
        else if (guess < secret_number)
            printf("Too low");
        else
            printf("Too high");
    }
}
