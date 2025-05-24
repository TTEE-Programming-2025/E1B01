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

void enterGrades() {
    clearScreen();
    printf("�п�J�ǥͤH�� (5~10): ");
    scanf("%d", &student_count);
    if (student_count < 5 || student_count > 10) {
        printf("�H�ƿ��~�A�п�J 5 �� 10 �����C\n");
        pause();
        return;
    }
    for (int i = 0; i < student_count; i++) {
        printf("\n�� %d ��ǥ�\n", i + 1);
        printf("�m�W: ");
        scanf("%s", students[i].name);
        printf("�Ǹ� (6 ���): ");
        scanf("%d", &students[i].id);
        if (students[i].id < 100000 || students[i].id > 999999) {
            printf("�Ǹ��榡���~�I\n");
            i--;
            continue;
        }
        printf("�ƾǦ��Z: ");
        scanf("%d", &students[i].math);
        printf("���z���Z: ");
        scanf("%d", &students[i].physics);
        printf("�^�妨�Z: ");
        scanf("%d", &students[i].english);

        if (students[i].math < 0 || students[i].math > 100 ||
            students[i].physics < 0 || students[i].physics > 100 ||
            students[i].english < 0 || students[i].english > 100) {
            printf("���Z��J���~�A�Э��s��J�ӥ͸�ơC\n");
            i--;
            continue;
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
    printf("\n�Ҧ��ǥ͸�ƿ�J�����C\n");
    pause();
}

void displayGrades() {
    clearScreen();
    printf("%-10s %-10s %-6s %-6s %-6s %-6s\n", "�m�W", "�Ǹ�", "�ƾ�", "���z", "�^��", "����");
    for (int i = 0; i < student_count; i++) {
        printf("%-10s %-10d %-6d %-6d %-6d %-6.1f\n",
               students[i].name, students[i].id,
               students[i].math, students[i].physics,
               students[i].english, students[i].average);
    }
    pause();
}


