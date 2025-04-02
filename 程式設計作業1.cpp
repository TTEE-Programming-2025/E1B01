#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  //Windows專用，控制台輸入輸出 
#include <ctype.h> //字元類型標頭檔 

#define PASSWORD 2024
//1.我的個人風格畫面
void display_welcome_screen() {
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

// 2. 讓使用者輸入密碼
void enter_password() {
    int input_password;
    printf("請輸入4位數字密碼：");
    scanf("%d", &input_password);
    
    if (input_password==PASSWORD) {
        printf("密碼正確，請繼續...\n");
    } else {
        printf("密碼錯誤，結束程式！\n");
        exit(0);
    }
}

// 3. 清除螢幕並顯示選單
void display_menu() {
    printf("---------------------------------------\n");
    printf("|    'A'...'Z' : Uppercase(英文大寫)   |\n");
    printf("|    'a'...'z' : Lowercase(英文小寫)   |\n");
    printf("|    '0'...'9' : Digit(數字)           |\n");
    printf("|    Otherwise : Author Name           |\n");
    printf("---------------------------------------\n\n");
}

// 4. 判斷輸入字元類型
void identify_character() {
    char ch;
    printf("請輸入一個字元：");
    fflush(stdin);
    scanf(" %c", &ch);

    if (isupper(ch)) {
        printf("Uppercase(英文大寫)\n");
    } else if (islower(ch)) {
        printf("Lowercase(英文小寫)\n");
    } else if (isdigit(ch)) {
        printf("Digit(數字)\n");
    } else {
        printf("E1B01 王麗涵\n");
    }

    printf("\n請按任意鍵返回...\n");
    getch();  // 等待使用者輸入
}

// 5. 排版、註解、程式結束
void program_exit() {
    printf("\n感謝使用本程式，歡迎下次再來！\n");
    exit(0);
}

// 主函式
int main() {
    display_welcome_screen();
    enter_password();
    display_menu();
    identify_character();
    program_exit();
    
    return 0;
}

// 心得
//在這次的作業中，我學會了如何使用 C 語言來設計互動式程式，
//並加入個人風格的元素，例如一開始的聖誕樹畫面，讓程式更具特色。
//我了解到 #include <stdio.h> 和 #include <stdlib.h> 這些標頭檔的作用，
//以及 getch() 讓使用者按任意鍵繼續，system("cls") 來清除螢幕，使畫面更加整潔。
//此外，這次作業讓我熟悉了 printf() 的運用，能夠輸出對齊的圖案，提升可讀性。
//我發現設計一個簡單但有趣的介面，是需要考慮美觀與程式的流暢度，這就是寫程式的樂趣之一吧。
//希望未來我能嘗試更多互動設計，讓程式更具吸引力。
 
 
