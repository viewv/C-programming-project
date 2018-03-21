/**
*题号 B3
*题目内容：
*文章排版
*个人姓名：张学楠
*学号：201700800398
*班级：2017计算机（普）
**/

#include<stdio.h>
#include<string.h>

void printword(int n);//打印函数
int checkflag(int i, int temp);//检查函数
int flag = 0;//设置全局变量flag检查是否需要换行
char allWorld[100000];//字符串存储区

int main()
{
    int n=0;
    char c;//防止gets函数读入不必要的东西
    printf("Please input the n\n");
    scanf("%d",&n);
    printf("Please input the str\n");
    c=getchar();
    gets(allWorld);
    printf("\nThis is result\n\n");
    printword(n);
    return 0;
}

void printword(int n)
{
    int counter=0;
    int i,j,temp=n;
    for(i=0;allWorld[i];i++)
    {
        if(flag==0 && counter<=n)
        {
            printf("%c",allWorld[i]);
            counter++;
            if(allWorld[i]==' ')
            {
                temp = n - counter;
                flag=checkflag(i,temp);
            }
        }
        else
        {
            for(j=counter;j<=counter;j++)
            {
                printf(" ");
            }
            counter=0;
            flag=0;
            printf("\n%c",allWorld[i]);
        }
    }
}

int checkflag(int i,int temp)
{
    int j,counter=1;
    for(j=i+1;allWorld[j]!=' ';j++)
    {
        counter++;
    }
    if(counter<=temp)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}