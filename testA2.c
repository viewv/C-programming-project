/**
*附录
*A2测试文件
*删除注释
*个人姓名：张学楠
*学号：201700800398
*班级：2017计算机（普）
**/

#include <stdio.h>
#include <stdlib.h>

/*声明函数*/
void check_comment(char); // 检查注释函数
void block_comment();     // 跳过多行注释
void single_comment();    // 跳过单行注释

FILE *from, *target; //from源文件，target目标文件

int main() //主函数
{
    char c;
    char filename[100];       //源文件名
    char targetfilename[100]; //目标文件

    //用户输入
    printf("Please enter the resource filename\n");
    scanf("%s", filename);
    printf("Please enter the target filename\n");
    scanf("%s", targetfilename);

    from = fopen(filename, "r");
    target = fopen(targetfilename, "w");

    while ((c = fgetc(from)) != EOF) //逐字符输入
        check_comment(c);            // 检查是否为注释

    //关闭所有文件
    fclose(from);
    fclose(target);
    return 0;
}

//检查注释函数
void check_comment(char c)
{
    char d;
    if (c == '/')
    {
        if ((d = fgetc(from)) == '*') //找到/*注释头
        {
            block_comment(); //跳过多行注释函数
        }

        else if (d == '/')
        {
            single_comment(); //跳过单行注释
            fputc('\n', target);
        }
        else
        {
            // 将不是注释的部分写入target文件
            fputc(c, target);
            fputc(d, target);
        }
    }
    // 如果都不是，要把c字符写入文件
    else
        fputc(c, target);
}

// 跳过多行注释函数
void block_comment()
{
    char d, e;
    while ((d = fgetc(from)) != EOF) //读文件，这里是在找到注释头开始读
    {
        if (d == '*') // 检查是否到达注释尾
        {
            e = fgetc(from);
            if (e == '/')
                return;
        }
        if (d == '/' && e == '*')
        {
            return;
        }
    }
}

// 跳过单行注释函数
void single_comment()
{
    char d, e;
    while ((d = fgetc(from)) != EOF) //读文件，这里是在单行注释头之后读取
    {
        if (d == '\n') // 检查是否到注释尾
        {
            return;
        }
    }
}