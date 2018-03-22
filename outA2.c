

#include <stdio.h>
#include <stdlib.h>


void check_comment(char); 
void block_comment();     
void single_comment();    

FILE *from, *target; 

int main() 
{
    char c;
    char filename[100];       
    char targetfilename[100]; 

    
    printf("Please enter the resource filename\n");
    scanf("%s", filename);
    printf("Please enter the target filename\n");
    scanf("%s", targetfilename);

    from = fopen(filename, "r");
    target = fopen(targetfilename, "w");

    while ((c = fgetc(from)) != EOF) 
        check_comment(c);            

    
    fclose(from);
    fclose(target);
    return 0;
}


void check_comment(char c)
{
    char d;
    if (c == '/')
    {
        if ((d = fgetc(from)) == '*') 
        {
            block_comment(); 
        }

        else if (d == '/')
        {
            single_comment(); 
            fputc('\n', target);
        }
        else
        {
            
            fputc(c, target);
            fputc(d, target);
        }
    }
    
    else
        fputc(c, target);
}


void block_comment()
{
    char d, e;
    while ((d = fgetc(from)) != EOF) 
    {
        if (d == '*') 
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


void single_comment()
{
    char d, e;
    while ((d = fgetc(from)) != EOF) 
    {
        if (d == '\n') 
        {
            return;
        }
    }
}