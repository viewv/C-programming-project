
#include <stdio.h>
#include <stdlib.h>

int copyFile(char *Read, char *Write);
int main()
{
    char Read[100];  
    char Write[100]; 

    
    printf("recourse file name");
    scanf("%s", Read);
    printf("target filename");
    scanf("%s", Write);

    
    if (copyFile(Read, Write))
    {
        printf("Successful\n");
    }
    else
    {
        printf("Failed\n");
    }
    return 0;
}


int copyFile(char *Read, char *Write)
{
    FILE *fpRead=NULL;  
    FILE *fpWrite=NULL; 

    
    int bufferLen = 1024 * 4;                 
    char *buffer = (char *)malloc(bufferLen); 
    int readCount;                            
    if ((fpRead = fopen(Read, "rb")) == NULL || (fpWrite = fopen(Write, "wb")) == NULL)
    
    
    {
        printf("Cannot open file, press any key to exit!\n");
        getchar();
        exit(1);
    }

    
    while ((readCount = fread(buffer, 1, bufferLen, fpRead)) > 0)
    {
        fwrite(buffer, readCount, 1, fpWrite);
    }
    free(buffer);
    fclose(fpRead);
    fclose(fpWrite);
    return 1;
}
