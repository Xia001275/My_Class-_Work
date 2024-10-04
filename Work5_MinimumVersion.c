#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<conio.h>

int main() {
    int h, m, s;
    int total_seconds;
    int hours, minutes, seconds;
    int paused = 1; // 初始化为暂停状态
    int end = 0; // 初始化倒计时结束标志

    printf("==========================\n");
    printf("|         倒计时         |\n");
    printf("|    设置:S 开始:空格    |\n");
    printf("==========================\n");

    while (1) {
        char key;
        key = 0;

        if (_kbhit()) {
            key = _getch();
            switch(key) {
                case 's':
                case 'S':
                    printf("请输入要倒计时的时间(格式为 HH MM SS):");
                    scanf("%d%d%d", &h, &m, &s);
                    printf("按空格开始倒计时...\n");
                    h = h * 3600;
                    m = m * 60;
                    total_seconds = h + m + s;
                    paused = 1; // 设置为暂停状态
                    end = 0; // 重置倒计时结束标志
                    break;
                case ' ':
                    if (paused) {
                        printf("倒计时开始：\n");
                        paused = 0; // 设置为非暂停状态
                    } else {
                        paused = 1; // 设置为暂停状态
                    }
                    break;
                case 'q':
                case 'Q':
                    exit(0); // 退出程序
                    break;
            }
        }

        if (!paused && total_seconds >= 0 && !end) {
            hours = total_seconds / 3600;
            minutes = (total_seconds % 3600) / 60;
            seconds = total_seconds % 60;

            system("cls");

            printf("%02d:%02d:%02d\n", hours, minutes, seconds);
            sleep(1); // 每次暂停1秒
            total_seconds--; // 减少一秒
        }

        if (total_seconds < 0 && !end) {
            printf("时间到！\n");
            printf("按Q键退出\n");
            end = 1; // 设置倒计时结束标志
            paused = 1; // 设置为暂停状态
        }
    }
    return 0;
}