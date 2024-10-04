#include<stdio.h>
#include<stdlib.h>

int main()
{
    for(int i = 1; i <= 100; i++){
        if(i % 7 == 0 || i % 10 == 7 || (i / 10) % 10 == 7 || (i / 100) % 10 == 7){//判断含有数字7或7的倍数并呱
            printf("呱 ");
        } else {
            printf("%d ", i);//如果不是就直接出数字
        }
    }
    system("pause");
    return 0;
}

