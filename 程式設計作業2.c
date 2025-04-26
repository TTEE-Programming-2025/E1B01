#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define PASSWORD 2025

void printWelcomeScreen();
int checkPassword();
void showMenu();
void drawTriangle();
void showMultiplicationTable();
void waitAndClear();
char getValidChar(char min, char max);
int getValidInt(int min, int max);

int main() {
    if (!checkPassword()) {
        printf("密碼錯誤超過三次，程式結束。\n");
        return 0;
    }

    char choice;
    while (1) {
        system("cls");
        showMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
            case 'A':
            	drawTriangle();
                break;
            case 'b':
            case 'B':
            	showMultiplicationTable();
                break;
            case 'c':
            case 'C':
                break;
            default:
                printf("無效的選項，請重新輸入。\n");
                system("pause");
        }
    }
    return 0;
}


void printWelcomeScreen() {
    printf("************************************\n");
    printf("*                                  *\n");
    printf("*         歡迎來到我的程式         *\n");
    printf("*          E1B01  Program          *\n");
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
    getch();
    system("cls");
}

int checkPassword() {
    int input, attempts = 0;
    printWelcomeScreen();
    while (attempts < 3) {
        printf("請輸入4位數密碼：");
        scanf("%d", &input);
        if (input == PASSWORD) return 1;
        else {
            printf("密碼錯誤！\n");
            attempts++;
        }
    }
    return 0;
}

void showMenu() {
    printf("--------------------------\n");
    printf("| a. 畫出直角三角形       |\n");
    printf("| b. 顯示乘法表           |\n");
    printf("| c. 結束                 |\n");
    printf("--------------------------\n");
    printf("請選擇一個選項：");
}

void drawTriangle() {
    system("cls");
    char ch;
    while (1) {
        printf("請輸入一個 'a' 到 'n' 的字母：");
        scanf(" %c", &ch);
        if (ch >= 'a' && ch <= 'n') break;
        else printf("輸入錯誤，請重新輸入。\n");
    }

    int rows = ch - 'a' + 1; // 計算要幾行
    for (int i = 1; i <= rows; i++) {
        // 先印 (rows - i) 個空格
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        // 再印 i 個星星
        for (int k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }

    printf("按任意鍵回主選單...\n");
    getch();
}

void showMultiplicationTable() {
    system("cls");
    int n;
    while (1) {
        printf("請輸入 1~9 的整數：");
        scanf("%d", &n);
        if (n >= 1 && n <= 9) break;
        else printf("輸入錯誤，請重新輸入。\n");
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d*%d=%2d  ", i, j, i*j);
        }
        printf("\n");
    }

    printf("按任意鍵回主選單...\n");
    getch();
}
