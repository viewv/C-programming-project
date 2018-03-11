/**
*题号 A1
*题目内容：
*将一个文本文件复制
*个人姓名：张学楠
*学号：201700800398
*班级：2017计算机（普）
**/
#include <stdio.h>
#include <stdlib.h>

int copyFile(char *fileRead, char *fileWrite);
int main()
{
    char fileRead[100];  // 要复制的文件名
    char fileWrite[100]; // 复制后的文件名

    // 获取用户输入
    printf("recourse file name");
    scanf("%s", fileRead);
    printf("target filename");
    scanf("%s", fileWrite);

    // 进行复制操作
    if (copyFile(fileRead, fileWrite))
    {
        printf("Successful\n");
    }
    else
    {
        printf("Failed\n");
    }
    return 0;
}

/**
* 文件复制函数
* @param    fileRead    要复制的文件
* @param    fileWrite   复制后文件的保存路径
* @return   int         1: 复制成功；2: 复制失败
**/
int copyFile(char *fileRead, char *fileWrite)
{
    FILE *fpRead;  // 指向要复制的文件
    FILE *fpWrite; // 指向复制后的文件

    /**
	* 这里设置缓存区，
	* 1 如果直接读入，如果源文件非常大，内存无法承受
	* 2 现在的硬盘大多数是4k对齐，这里设置4k的缓存区可以加快速度
	**/
    int bufferLen = 1024 * 4;                 // 缓冲区长度
    char *buffer = (char *)malloc(bufferLen); // 开辟缓存
    int readCount;                            // 实际读取的字节数
    if ((fpRead = fopen(fileRead, "rb")) == NULL || (fpWrite = fopen(fileWrite, "wb")) == NULL)
    {
        printf("Cannot open file, press any key to exit!\n");
        getchar();
        exit(1);
    }

    // 不断从fileRead读取内容，放在缓冲区，再将缓冲区的内容写入fileWrite
    while ((readCount = fread(buffer, 1, bufferLen, fpRead)) > 0)
    {
        fwrite(buffer, readCount, 1, fpWrite);
    }
    free(buffer);
    fclose(fpRead);
    fclose(fpWrite);
    return 1;
}
