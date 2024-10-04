#include<stdio.h>
#include<stdlib.h>

int main()
{
    long long username = 20130184561; // 原本是int类型的，但太长了，所以用long long
    long long initialpsw = username % 20130000000LL; // 这个也是同理
    int psw = initialpsw;
    int newpsw;
    int confirmedpsw;
    char sex = 'M';
    float height = 175.5;
    printf("用户: %lld\n", username); // 一开始已经用longlong了，这里就要lld了

    printf("请输入新密码: ");
    scanf("%d", &newpsw);
    printf("请输入确认密码: ");
    scanf("%d", &confirmedpsw);
    if (newpsw == confirmedpsw) // 判断两次密码是否输入一致
    {
        printf("修改密码成功!\n");
    }
    else
    {
        printf("两次密码输入不一致!\n");
    }

    system("pause");
    return 0;
}
