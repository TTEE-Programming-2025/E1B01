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
        printf("�K�X���~�W�L�T���A�{�������C\n");
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
                printf("�L�Ī��ﶵ�A�Э��s��J�C\n");
                system("pause");
        }
    }
    return 0;
}


void printWelcomeScreen() {
    printf("************************************\n");
    printf("*                                  *\n");
    printf("*         �w��Ө�ڪ��{��         *\n");
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
        printf("�п�J4��ƱK�X�G");
        scanf("%d", &input);
        if (input == PASSWORD) return 1;
        else {
            printf("�K�X���~�I\n");
            attempts++;
        }
    }
    return 0;
}

void showMenu() {
    printf("--------------------------\n");
    printf("| a. �e�X�����T����       |\n");
    printf("| b. ��ܭ��k��           |\n");
    printf("| c. ����                 |\n");
    printf("--------------------------\n");
    printf("�п�ܤ@�ӿﶵ�G");
}

void drawTriangle() {
    system("cls");
    char ch;
    while (1) {
        printf("�п�J�@�� 'a' �� 'n' ���r���G");
        scanf(" %c", &ch);
        if (ch >= 'a' && ch <= 'n') break;
        else printf("��J���~�A�Э��s��J�C\n");
    }

    int rows = ch - 'a' + 1; // �p��n�X��
    for (int i = 1; i <= rows; i++) {
        // ���L (rows - i) �ӪŮ�
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        // �A�L i �ӬP�P
        for (int k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }

    printf("�����N��^�D���...\n");
    getch();
}

void showMultiplicationTable() {
    system("cls");
    int n;
    while (1) {
        printf("�п�J 1~9 ����ơG");
        scanf("%d", &n);
        if (n >= 1 && n <= 9) break;
        else printf("��J���~�A�Э��s��J�C\n");
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d*%d=%2d  ", i, j, i*j);
        }
        printf("\n");
    }

    printf("�����N��^�D���...\n");
    getch();
}
