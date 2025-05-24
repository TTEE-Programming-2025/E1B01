#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10

typedef struct {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void clearScreen() {
    system("cls");
}

void pause() {
    printf("\n�Ы����N���~��...");
    getchar();
    getchar();
}

void printWelcomeArt() {
    clearScreen();
    printf("########################################\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("#     CCCCCCCCCCCCCCCCCCCCCCCCCCCC       #\n");
    printf("#   CC                             CC    #\n");
    printf("#  CC     *************************  CC  #\n");
    printf("# CC     *                       *   CC  #\n");
    printf("# CC     *        E1B01         *   CC   #\n");
    printf("# CC     *                       *   CC  #\n");
    printf("#  CC     *************************  CC  #\n");
    printf("#   CC                             CC    #\n");
    printf("#     CCCCCCCCCCCCCCCCCCCCCCCCCCCC       #\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("#                                        #\n");
    printf("########################################\n");
    printf("\n�w��ϥ�²�����Z�t�ΡA�п�J�K�X (4 ���):\n");
}

int login() {
    int password, attempts = 0;
    while (attempts < 3) {
        printf("�п�J�K�X: ");
        scanf("%d", &password);
        if (password == 2025) {
            printf("\n�K�X���T�A�w��i�J�t�ΡI\n");
            return 1;
        } else {
            printf("�K�X���~�I\n");
            attempts++;
        }
    }
    return 0;
}

void showMenu() {
    printf("------------[Grade System]----------\n");
    printf("| a. Enter student grades           |\n");
    printf("| b. Display student grades         |\n");
    printf("| c. Search for student grades      |\n");
    printf("| d. Grade ranking                  |\n");
    printf("| e. Exit system                    |\n");
    printf("------------------------------------\n");
}

int main() {
    char choice;
    printWelcomeArt();
    if (!login()) {
        printf("�w�s����~�T���A�t�αN�����C\n");
        return 0;
    }
    do {
        clearScreen();
        showMenu();
        printf("�п�J�ﶵ: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a': enterGrades(); break;
            case 'b': displayGrades(); break;
            case 'c': searchGrades(); break;
            case 'd': rankGrades(); break;
            case 'e': if (exitSystem()) return 0; break;
            default: printf("�L�Ī��ﶵ�A�Э��s��J�I\n"); pause();
        }
    } while (1);

    return 0;
}

