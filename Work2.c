#include<stdio.h>
#include<stdlib.h>
int main()
{
    char SEX;
    float height, kg, bmi;

    while(1)
    {
        while (1)
        {
            printf("您的性别是(M/F):");
            scanf(" %c", &SEX);
            if(SEX != 'M' && SEX != 'm' && SEX != 'F' && SEX != 'f'){//如果输入的不是M/F，弹出错误信息
                printf("无效性别输入！\n");
            }else break;
        }
        
        
        printf("请输入您的身高(单位：米):");
        scanf("%f", &height);
        printf("请输入您的体重:");
        scanf("%f", &kg);

        bmi = kg / (height * height);//计算BMI值

        if(SEX == 'M' || SEX == 'm')//判断性别
        {
            if(bmi < 20)printf("您的体型过轻！");
            else if(bmi >= 20 && bmi < 25)printf("您的体型适中！");
            else if(bmi >= 25 && bmi < 30)printf("您的体型过重！");
            else if(bmi >= 30 && bmi < 35)printf("您的体型肥胖！");
            else printf("您的体型非常肥胖！");
            break;
        }
        else if(SEX == 'F' || SEX == 'f')
        { 
            if(bmi < 19)printf("您的体型过轻！");
            else if(bmi >= 19 && bmi < 24)printf("您的体型适中！");
            else if(bmi >= 24 && bmi < 29)printf("您的体型过重！");
            else if(bmi >= 29 && bmi < 34)printf("您的体型肥胖！");
            else printf("您的体型非常肥胖！");
            break;
        }
    }
    system("pause");
    return 0;
}
