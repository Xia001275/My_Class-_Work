#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

void choose(int num) {
    switch (num) {
        case 0:
        case 1:
            printf("一饭堂\n");
            break;
        case 2:
        case 3:
            printf("二饭堂\n");
            break;
        case 4:
        case 5:
            printf("三饭堂\n");
            break;
        case 6:
        case 7:
            printf("四饭堂\n");
            break;
        case 8:
            printf("外出就餐\n");
            break;
        default:
            printf("叫外卖\n");
            break;
    }
}

void print_menu() {
    printf("========================\n");
    printf("| 按空格键随机选择一餐 |\n");
    printf("|按'e'或'E'进入隐藏模式|\n");
    printf("| 按'q'或'Q'键退出程序 |\n");
    printf("========================\n");
}

void print_hidden_menu() {
    printf("========================\n");
    printf("|      隐藏模式下      |\n");
    printf("| 输入'sl'即可抽取十连 |\n");
    printf("| 按'q'或'Q'键退出程序 |\n");
    printf("========================\n");
}

int main() {
    int num;
    char sl[3];
    srand(time(NULL)); // 初始化随机数种子

    print_menu();

    while (1) { // 无限循环，直到用户按下 'q' 或 'Q'
        char key;
        key = 0;

        if (_kbhit()) { // 检测到按键按下
            key = _getch(); // 读取按键

            switch (key) {
                case ' ': // 按下空格键
                    num = rand() % 10; // 生成随机数
                    choose(num);
                    break;
                case 'e':
                case 'E':
                    printf("隐藏模式已开启\n");
                    print_hidden_menu();
                    fgets(sl, sizeof(sl), stdin); // 使用 fgets 读取字符串
                    sl[strcspn(sl, "\n")] = 0; // 去除换行符
                    if (strcmp(sl, "sl") == 0) { // 检查是否输入 "sl"
                        for (int i = 0; i < 10; i++) { // 循环十次
                            num = rand() % 10; // 生成随机数
                            choose(num);
                        }
                    }
                    break;
                case 'q':
                case 'Q': // 按下 'q' 或 'Q' 键退出程序
                    printf("程序退出\n");
                    system("pause");
                    return 0;
            }
        }
    }

    return 0;
}
