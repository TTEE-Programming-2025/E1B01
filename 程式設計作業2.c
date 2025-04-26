#include <stdio.h>
#include <stdlib.h> 

#define PASSWORD 2025 // 預設密碼

// 等待使用者按Enter
void waitForEnter() {
    printf("請按Enter鍵繼續...");
    while (getchar() != '\n'); // 清除前面的換行符號
    getchar(); // 等待新的一次Enter
}

// 開場畫面
void printWelcomeScreen() {
    int i;
    system("cls");
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

// 主選單
void printMenu() {
    printf("--------------------------\n");
    printf("| a. 畫出直角三角形       |\n");
    printf("| b. 顯示乘法表           |\n");
    printf("| c. 結束                 |\n");
    printf("--------------------------\n");
    printf("請選擇(a/b/c)：");
}

// 畫直角三角形
void drawTriangle() {
    char ch;
    int rows, i, j, k;
    system("cls");
    while (1) {
        printf("請輸入一個 'a' 到 'n' 的小寫字母：");
        scanf(" %c", &ch);
        if (ch >= 'a' && ch <= 'n') {
            break;
        } else {
            printf("輸入錯誤，請重新輸入。\n");
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

// 顯示乘法表
void showMultiplicationTable() {
    int n, i, j;
    system("cls");
    while (1) {
        printf("請輸入1到9的整數：");
        scanf("%d", &n);
        if (n >= 1 && n <= 9) {
            break;
        } else {
            printf("輸入錯誤，請重新輸入。\n");
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

    // 密碼輸入
    while (attempts < 3) {
        printf("請輸入4位數密碼：");
        scanf("%d", &password);

        if (password == PASSWORD) {
            break;
        } else {
            attempts++;
            printf("密碼錯誤！剩下%d次機會。\n", 3 - attempts);
        }
    }

    if (attempts == 3) {
        printf("密碼錯誤超過三次！程式結束。\n");
        return 0;
    }

    // 主流程
    do {
        system("cls");
        printMenu();
        scanf(" %c", &choice);

        if (choice == 'a' || choice == 'A') {
            drawTriangle();
        } else if (choice == 'b' || choice == 'B') {
            showMultiplicationTable();
        } else if (choice == 'c' || choice == 'C') {
            printf("確定要結束嗎？(y/n)：");
            scanf(" %c", &continueChoice);

            while (continueChoice != 'y' && continueChoice != 'Y' &&
                   continueChoice != 'n' && continueChoice != 'N') {
                printf("輸入錯誤，請重新輸入(y/n)：");
                scanf(" %c", &continueChoice);
            }

            if (continueChoice == 'y' || continueChoice == 'Y') {
                printf("程式結束！\n");
                break;
            }
        } else {
            printf("無效選項，請重新選擇！\n");
            waitForEnter();
        }
    } while (1);

    return 0;
}

//這次作業主要練習了C語言中的迴圈與條件判斷，透過設計密碼驗證、主選單、三角形繪製與乘法表功能，加深了我對基本語法的理解。
//在撰寫過程中，遇到了for迴圈變數宣告的錯誤，讓我學到C語言不同標準（如C90和C99）之間的差異，也讓我更加注意程式的相容性。
//此外，我也體會到良好的排版與清楚的註解對程式可讀性的重要性。
//雖然過程中花了不少時間除錯，但當成功執行時，成就感也隨之而來。
//未來希望能持續練習，讓自己在C語言的基礎上更扎實。


