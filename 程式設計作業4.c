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
    printf("\n請按任意鍵繼續...");
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
    printf("\n歡迎使用簡易成績系統，請輸入密碼 (4 位數):\n");
}

int login() {
    int password, attempts = 0;
    while (attempts < 3) {
        printf("請輸入密碼: ");
        scanf("%d", &password);
        if (password == 2025) {
            printf("\n密碼正確，歡迎進入系統！\n");
            return 1;
        } else {
            printf("密碼錯誤！\n");
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
        printf("已連續錯誤三次，系統將結束。\n");
        return 0;
    }
    do {
        clearScreen();
        showMenu();
        printf("請輸入選項: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a': enterGrades(); break;
            case 'b': displayGrades(); break;
            case 'c': searchGrades(); break;
            case 'd': rankGrades(); break;
            case 'e': if (exitSystem()) return 0; break;
            default: printf("無效的選項，請重新輸入！\n"); pause();
        }
    } while (1);

    return 0;
}

