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

void enterGrades() {
    clearScreen();
    printf("請輸入學生人數 (5~10): ");
    scanf("%d", &student_count);
    if (student_count < 5 || student_count > 10) {
        printf("人數錯誤，請輸入 5 到 10 之間。\n");
        pause();
        return;
    }
    for (int i = 0; i < student_count; i++) {
        printf("\n第 %d 位學生\n", i + 1);
        printf("姓名: ");
        scanf("%s", students[i].name);
        printf("學號 (6 位數): ");
        scanf("%d", &students[i].id);
        if (students[i].id < 100000 || students[i].id > 999999) {
            printf("學號格式錯誤！\n");
            i--;
            continue;
        }
        printf("數學成績: ");
        scanf("%d", &students[i].math);
        printf("物理成績: ");
        scanf("%d", &students[i].physics);
        printf("英文成績: ");
        scanf("%d", &students[i].english);

        if (students[i].math < 0 || students[i].math > 100 ||
            students[i].physics < 0 || students[i].physics > 100 ||
            students[i].english < 0 || students[i].english > 100) {
            printf("成績輸入錯誤，請重新輸入該生資料。\n");
            i--;
            continue;
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
    printf("\n所有學生資料輸入完成。\n");
    pause();
}

void displayGrades() {
    clearScreen();
    printf("%-10s %-10s %-6s %-6s %-6s %-6s\n", "姓名", "學號", "數學", "物理", "英文", "平均");
    for (int i = 0; i < student_count; i++) {
        printf("%-10s %-10d %-6d %-6d %-6d %-6.1f\n",
               students[i].name, students[i].id,
               students[i].math, students[i].physics,
               students[i].english, students[i].average);
    }
    pause();
}


