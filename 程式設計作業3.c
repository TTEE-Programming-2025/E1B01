#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 9
#define MAX_ATTEMPTS 3
#define PASSWORD "2025"

char seats[SIZE][SIZE];

void initializeSeats();
void showLogin();
int verifyPassword();
void showMenu();
void showSeats();
void randomBookedSeats();
void clearScreen();
void computerArrange();
int isAvailable(int row, int col);
void markSeats(int row, int col, int count, int vertical);
int checkValid(int row, int col);
void userChoose();
void exitProgram();
void waitForKey();

int main() {
    srand(time(NULL));
    showLogin();
    if (!verifyPassword()) {
        printf("Too many incorrect attempts. Exiting program.\n");
        return 0;
    }
    initializeSeats();
    randomBookedSeats();

    char choice;
    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a':
                showSeats();
                waitForKey();
                break;
            case 'b':
                computerArrange();
                break;
            case 'c':
                userChoose();
                break;
            case 'd':
                exitProgram();
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }
    return 0;
}

void initializeSeats() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            seats[i][j] = '-';
}

void showLogin() {
    printf("************************************\n");
    printf("*                                  *\n");
    printf("*         歡迎來到我的程式         *\n");
    printf("*          E1B01   Program         *\n");
    printf("*                                  *\n");
    printf("************************************\n");
    printf("*         Merry Christmas!         *\n");
    printf("*                                  *\n");
	printf("*                0                 *\n");
	printf("*               000                *\n");
	printf("*              00000               *\n");
	printf("*             0000000              *\n");
	printf("*            000000000             *\n");
	printf("*           00000000000            *\n");
	printf("*          0000000000000           *\n");
	printf("*         000000000000000          *\n");
	printf("*        00000000000000000         *\n");
	printf("*       0000000000000000000        *\n");
	printf("*      000000000000000000000       *\n");
	printf("*              000000              *\n");
	printf("*              000000              *\n");
	printf("*              000000              *\n");
	printf("************************************\n");
}

int verifyPassword() {
    char input[10];
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        printf("Enter 4-digit password: ");
        scanf("%s", input);
        if (strcmp(input, PASSWORD) == 0) {
            printf("Welcome! Access granted.\n");
            return 1;
        } else {
            printf("Incorrect password.\n");
            attempts++;
        }
    }
    return 0;
}

void showSeats() {
    printf("\\123456789\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

void randomBookedSeats() {
    int count = 0;
    while (count < 10) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;
        if (seats[r][c] == '-') {
            seats[r][c] = '*';
            count++;
        }
    }
}

void clearScreen() {
    system("cls");
}

void waitForKey() {
    printf("Press any key to return to menu...\n");
    getchar();
    getchar();
}


