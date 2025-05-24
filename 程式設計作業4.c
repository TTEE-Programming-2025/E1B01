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
int i,j;
//清除螢幕 
void clearScreen() {
    system("cls");
}
//等待的提示字句 
void pause() {
    printf("\n請按任意鍵繼續...");
    getchar();
    getchar();
}
//我的個人畫風面 
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
//密碼輸入與判斷是否正確 
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
//主選單 
void showMenu() {
    printf("------------[Grade System]----------\n");
    printf("| a. Enter student grades           |\n");
    printf("| b. Display student grades         |\n");
    printf("| c. Search for student grades      |\n");
    printf("| d. Grade ranking                  |\n");
    printf("| e. Exit system                    |\n");
    printf("------------------------------------\n");
}
//密碼和讓使用者選選項 
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
//選項a 
void enterGrades() {
    clearScreen();
    printf("請輸入學生人數 (5~10): ");
    scanf("%d", &student_count);
    if (student_count < 5 || student_count > 10) {
        printf("人數錯誤，請輸入 5 到 10 之間。\n");
        pause();
        return;
    }
    for (i = 0; i < student_count; i++) {
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
//選項b 
void displayGrades() {
    clearScreen();
    printf("%-10s %-10s %-6s %-6s %-6s %-6s\n", "姓名", "學號", "數學", "物理", "英文", "平均");
    for (i = 0; i < student_count; i++) {
        printf("%-10s %-10d %-6d %-6d %-6d %-6.1f\n",
               students[i].name, students[i].id,
               students[i].math, students[i].physics,
               students[i].english, students[i].average);
    }
    pause();
}
//選項c 
void searchGrades() {
    char searchName[50];
    int found = 0;
    clearScreen();
    printf("請輸入要查詢的學生姓名: ");
    scanf("%s", searchName);
    for (i = 0; i < student_count; i++) {
        if (strcmp(searchName, students[i].name) == 0) {
            printf("\n找到學生資料：\n");
            printf("姓名: %s\n", students[i].name);
            printf("學號: %d\n", students[i].id);
            printf("數學: %d\n物理: %d\n英文: %d\n平均: %.1f\n",
                   students[i].math, students[i].physics,
                   students[i].english, students[i].average);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("查無此學生資料。\n");
    }
    pause();
}
//選項d 
void rankGrades() {
    Student temp;
    clearScreen();
    for (i = 0; i < student_count - 1; i++) {
        for (j = i + 1; j < student_count; j++) {
            if (students[i].average < students[j].average) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("%-10s %-10s %-6s\n", "姓名", "學號", "平均");
    for (i = 0; i < student_count; i++) {
        printf("%-10s %-10d %-6.1f\n",
               students[i].name, students[i].id, students[i].average);
    }
    pause();
}
//選項e 
int exitSystem() {
    char choice;
    while (1) {
        printf("確定離開？(y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y') return 1;
        else if (choice == 'n') return 0;
    }
}

/*
說明與心得：
本程式實作一個簡易成績系統，包含學生資料輸入、顯示、搜尋、排名功能，並使用結構與指標操作。
我加入了以字母 C 為背景的新個人風格畫面，並整合清除與暫停畫面，也學會如何應用結構陣列。
過程中練習了條件判斷、字串處理與排序邏輯等，大大增強了 C 語言的實作能力。
*/

