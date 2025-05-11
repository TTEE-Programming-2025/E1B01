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

void computerArrange() {
    int need;
    printf("How many seats do you need (1-4)? ");
    scanf("%d", &need);

    int placed = 0;
    for (int i = 0; i < SIZE && !placed; i++) {
        for (int j = 0; j <= SIZE - need; j++) {
            int ok = 1;
            for (int k = 0; k < need; k++) {
                if (seats[i][j + k] != '-') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                for (int k = 0; k < need; k++)
                    seats[i][j + k] = '@';
                placed = 1;
                break;
            }
        }
    }

    if (!placed && need == 4) {
        for (int i = 0; i < SIZE - 1 && !placed; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (seats[i][j] == '-' && seats[i + 1][j] == '-') {
                    seats[i][j] = seats[i + 1][j] = '@';
                    seats[i][(j + 1) % SIZE] = seats[i + 1][(j + 1) % SIZE] = '@';
                    placed = 1;
                    break;
                }
            }
        }
    }

    showSeats();
    printf("Are you satisfied? (y/n): ");
    char response;
    scanf(" %c", &response);
    if (response == 'y') {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (seats[i][j] == '@') seats[i][j] = '*';
    } else {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (seats[i][j] == '@') seats[i][j] = '-';
    }
}

void userChoose() {
    int num;
    printf("How many seats do you want to choose? ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        int row, col;
        char dash;
        while (1) {
            printf("Enter seat (format row-col): ");
            if (scanf("%d-%d", &row, &col) != 2 || row < 1 || row > 9 || col < 1 || col > 9 || seats[row - 1][col - 1] != '-') {
                printf("Invalid or already taken. Try again.\n");
                while (getchar() != '\n');
            } else {
                seats[row - 1][col - 1] = '@';
                break;
            }
        }
    }
    showSeats();
    waitForKey();
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (seats[i][j] == '@') seats[i][j] = '*';
}

void exitProgram() {
    char ch;
    while (1) {
        printf("Continue? (y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y') return;
        else if (ch == 'n') {
            printf("Thank you for using the booking system.\n");
            exit(0);
        } else {
            printf("Invalid input. Try again.\n");
        }
    }
}
