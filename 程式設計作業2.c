#include <stdio.h>
#include <stdlib.h> 

#define PASSWORD 2025 // �w�]�K�X

// ���ݨϥΪ̫�Enter
void waitForEnter() {
    printf("�Ы�Enter���~��...");
    while (getchar() != '\n'); // �M���e��������Ÿ�
    getchar(); // ���ݷs���@��Enter
}

// �}���e��
void printWelcomeScreen() {
    int i;
    system("cls");
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
}

// �D���
void printMenu() {
    printf("--------------------------\n");
    printf("| a. �e�X�����T����       |\n");
    printf("| b. ��ܭ��k��           |\n");
    printf("| c. ����                 |\n");
    printf("--------------------------\n");
    printf("�п��(a/b/c)�G");
}

// �e�����T����
void drawTriangle() {
    char ch;
    int rows, i, j, k;
    system("cls");
    while (1) {
        printf("�п�J�@�� 'a' �� 'n' ���p�g�r���G");
        scanf(" %c", &ch);
        if (ch >= 'a' && ch <= 'n') {
            break;
        } else {
            printf("��J���~�A�Э��s��J�C\n");
        }
    }

    rows = ch - 'a' + 1;
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }

    waitForEnter();
}

// ��ܭ��k��
void showMultiplicationTable() {
    int n, i, j;
    system("cls");
    while (1) {
        printf("�п�J1��9����ơG");
        scanf("%d", &n);
        if (n >= 1 && n <= 9) {
            break;
        } else {
            printf("��J���~�A�Э��s��J�C\n");
        }
    }

    printf("\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d*%d=%2d  ", i, j, i*j);
        }
        printf("\n");
    }

    waitForEnter();
}

int main() {
    int password;
    int attempts = 0;
    char choice;
    char continueChoice;

    printWelcomeScreen();

    // �K�X��J
    while (attempts < 3) {
        printf("�п�J4��ƱK�X�G");
        scanf("%d", &password);

        if (password == PASSWORD) {
            break;
        } else {
            attempts++;
            printf("�K�X���~�I�ѤU%d�����|�C\n", 3 - attempts);
        }
    }

    if (attempts == 3) {
        printf("�K�X���~�W�L�T���I�{�������C\n");
        return 0;
    }

    // �D�y�{
    do {
        system("cls");
        printMenu();
        scanf(" %c", &choice);

        if (choice == 'a' || choice == 'A') {
            drawTriangle();
        } else if (choice == 'b' || choice == 'B') {
            showMultiplicationTable();
        } else if (choice == 'c' || choice == 'C') {
            printf("�T�w�n�����ܡH(y/n)�G");
            scanf(" %c", &continueChoice);

            while (continueChoice != 'y' && continueChoice != 'Y' &&
                   continueChoice != 'n' && continueChoice != 'N') {
                printf("��J���~�A�Э��s��J(y/n)�G");
                scanf(" %c", &continueChoice);
            }

            if (continueChoice == 'y' || continueChoice == 'Y') {
                printf("�{�������I\n");
                break;
            }
        } else {
            printf("�L�Ŀﶵ�A�Э��s��ܡI\n");
            waitForEnter();
        }
    } while (1);

    return 0;
}


