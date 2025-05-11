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

int i, j;  // 全局宣告變數 i 和 j

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
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            seats[i][j] = '-';
        }
    }
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

void showMenu() {
    clearScreen();
    printf("----------[Booking System]----------\n");
    printf("| a. Available seats               |\n");
    printf("| b. Arrange for you               |\n");
    printf("| c. Choose by yourself            |\n");
    printf("| d. Exit                          |\n");
    printf("------------------------------------\n");
}

void showSeats() {
    printf("\\123456789\n");
    for (i = SIZE - 1; i >= 0; i--) {
        printf("%d", i + 1);
        for (j = 0; j < SIZE; j++) {
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
    for (i = 0; i < SIZE && !placed; i++) {
        for (j = 0; j <= SIZE - need; j++) {
            int ok = 1;
            int k;
            for (k = 0; k < need; k++) {
                if (seats[i][j + k] != '-') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                for (k = 0; k < need; k++)
                    seats[i][j + k] = '@';
                placed = 1;
                break;
            }
        }
    }

    if (!placed && need == 4) {
        for (i = 0; i < SIZE - 1 && !placed; i++) {
            for (j = 0; j < SIZE; j++) {
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
        for (i = 0; i < SIZE; i++)
            for (j = 0; j < SIZE; j++)
                if (seats[i][j] == '@') seats[i][j] = '*';
    } else {
        for (i = 0; i < SIZE; i++)
            for (j = 0; j < SIZE; j++)
                if (seats[i][j] == '@') seats[i][j] = '-';
    }
}

void userChoose() {
    int num;
    printf("How many seats do you want to choose? ");
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
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
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
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

//平常在電影院或高鐵上選座位感覺很簡單，只要打開系統點幾下就完成了，但這次自己用 C 語言寫訂位系統才發現背後真的很複雜。
//光是要讓座位正確顯示、確保不能重複選位，就花了我很多時間。
//尤其是要處理使用者輸入格式錯誤、檢查座位是否被選走、還要記得清除緩衝區，
//這些小細節常常讓我 debug 到很頭痛。此外，原本寫在 for 裡面的變數宣告也因為編譯器問題要一一改成外部宣告，
//讓我更了解 C 語言在不同標準下的規定。
//雖然過程中很繁瑣，但做出一個自己能操作的系統，還是覺得很有成就感，也讓我更佩服那些開發訂票系統的工程師。
