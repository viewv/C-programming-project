/**
*题号 A3
*题目内容：
*链接两个文件
*个人姓名：张学楠
*学号：201700800398
*班级：2017计算机（普）
**/
#include <stdio.h>
#include <stdlib.h>

void linkfile();

FILE *db1, *db2, *db3; //创建文件指针

int main()
{
    char c;
    char db1str[100]; //db1文件名
    char db2str[100]; //db2文件名
    char db3str[100]; //db3文件名

    printf("Please enter the db1 filename\n");
    scanf("%s", db1str);
    c = getchar();
    printf("Please enter the db1 filename\n");
    scanf("%s", db2str);
    c = getchar();
    printf("Please enter the db3 filename\n");
    scanf("%s", db3str);

    db1 = fopen(db1str, "r"); //打开文件
    db2 = fopen(db2str, "r"); //打开文件
    db3 = fopen(db3str, "w"); //打开文件

    linkfile(); //链接函数

    /*
    关闭所有文件
    */
    fclose(db1);
    fclose(db2);
    fclose(db3);

    return 0;
}

void linkfile()
{
    int i, j;

    float mathscore, englishscore; //数学成绩，英语成绩
    float average;                 //平均数

    //按照一行一行的读
    char maxchardb1[1024];
    char maxchardb2[1024];

    //最后写入的字符串
    char math[10];
    char english[10];
    char name[10];
    char averagestr[100];

    while (!feof(db1) && !feof(db2))
    {
        fgets(maxchardb1, 1024, db1);
        fgets(maxchardb2, 1024, db2);

        if ((maxchardb1[0] == '\n') || (maxchardb1[0] == '\0'))
        {
            break;
        }

        j = 0;
        for (i = 0; maxchardb1[i] != ' '; i++)
        {
            name[j] = maxchardb1[i];
            j++;
        }
        name[j] = '\0';
        j = 0; //读姓名
        for (i = i + 1; (maxchardb1[i] != '\n') && (maxchardb1[i] != '\0'); i++)
        {
            english[j] = maxchardb1[i];
            j++;
        }
        english[j] = '\0';
        j = 0; //读英语成绩
        for (i = 0; maxchardb2[i] != ' '; i++)
        {
            ;
        }
        j = 0;
        for (i = i + 1; (maxchardb2[i] != '\n') && (maxchardb2[i] != '\0'); i++)
        {
            math[j] = maxchardb2[i];
            j++;
        }
        math[j] = '\0';
        j = 0; //读数学成绩

        //转换成数字
        mathscore = atof(math);
        englishscore = atof(english);
        average = ((float)mathscore + (float)englishscore) / 2.0;

        gcvt(average, 10, averagestr); //转换成字符串

        //注入信息到db3
        fputs("Name:", db3);
        fputs(name, db3);

        fputs("\tMath:", db3);
        fputs(math, db3);

        fputs("\tEnglish:", db3);
        fputs(english, db3);

        fputs("\tAverage:", db3);
        fputs(averagestr, db3);

        fputc('\n', db3);
    }
}