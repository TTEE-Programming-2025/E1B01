#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  //Windows�M�ΡA����x��J��X 
#include <ctype.h> //�r���������Y�� 

#define PASSWORD 2024
//1.�ڪ��ӤH����e��
void display_welcome_screen() {
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

// 2. ���ϥΪ̿�J�K�X
void enter_password() {
    int input_password;
    printf("�п�J4��Ʀr�K�X�G");
    scanf("%d", &input_password);
    
    if (input_password==PASSWORD) {
        printf("�K�X���T�A���~��...\n");
    } else {
        printf("�K�X���~�A�����{���I\n");
        exit(0);
    }
}

// 3. �M���ù�����ܿ��
void display_menu() {
    printf("---------------------------------------\n");
    printf("|    'A'...'Z' : Uppercase(�^��j�g)   |\n");
    printf("|    'a'...'z' : Lowercase(�^��p�g)   |\n");
    printf("|    '0'...'9' : Digit(�Ʀr)           |\n");
    printf("|    Otherwise : Author Name           |\n");
    printf("---------------------------------------\n\n");
}

// 4. �P�_��J�r������
void identify_character() {
    char ch;
    printf("�п�J�@�Ӧr���G");
    fflush(stdin);
    scanf(" %c", &ch);

    if (isupper(ch)) {
        printf("Uppercase(�^��j�g)\n");
    } else if (islower(ch)) {
        printf("Lowercase(�^��p�g)\n");
    } else if (isdigit(ch)) {
        printf("Digit(�Ʀr)\n");
    } else {
        printf("E1B01 ���R�[\n");
    }

    printf("\n�Ы����N���^...\n");
    getch();  // ���ݨϥΪ̿�J
}

// 5. �ƪ��B���ѡB�{������
void program_exit() {
    printf("\n�P�¨ϥΥ��{���A�w��U���A�ӡI\n");
    exit(0);
}

// �D�禡
int main() {
    display_welcome_screen();
    enter_password();
    display_menu();
    identify_character();
    program_exit();
    
    return 0;
}

// �߱o
//�b�o�����@�~���A�ھǷ|�F�p��ϥ� C �y���ӳ]�p���ʦ��{���A
//�å[�J�ӤH���檺�����A�Ҧp�@�}�l���t�Ͼ�e���A���{�����S��C
//�ڤF�Ѩ� #include <stdio.h> �M #include <stdlib.h> �o�Ǽ��Y�ɪ��@�ΡA
//�H�� getch() ���ϥΪ̫����N���~��Asystem("cls") �ӲM���ù��A�ϵe����[���C
//���~�A�o���@�~���ڼ��x�F printf() ���B�ΡA�����X������ϮסA���ɥiŪ�ʡC
//�ڵo�{�]�p�@��²������쪺�����A�O�ݭn�Ҽ{���[�P�{�����y�Z�סA�o�N�O�g�{�����ֽ줧�@�a�C
//�Ʊ楼�ӧگ���է�h���ʳ]�p�A���{�����l�ޤO�C
 
 
