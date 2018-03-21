/**
*题号 C1
*题目内容：
*单向链表
*个人姓名：张学楠
*学号：201700800398
*班级：2017计算机（普）
**/

#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct student)

struct student
{
    int num;
    char name[20];
    char sex[10];
    int age;
    struct student *next;
};

int n;

struct student *Create();
void Printlinklist(struct student *head);
struct student *Del(struct student *head, int num);
struct student *Insert(struct student *head, int num, struct student *node);

int main()
{
    int option;
    int temp;
    int control = 1;
    struct student *head = NULL;
    struct student *node = NULL;
    while (control == 1)
    {
        printf("====================================\n");
        printf("|     Please Choose your option    |\n");
        printf("|    Input the number to choose    |\n");
        printf("|     1:Creat a list of student    |\n");
        printf("|   2:Show The Information of list |\n");
        printf("|   3:Delete the student by number |\n");
        printf("|   4:Insert a student information |\n");
        printf("|         0:Exit    9:Run          |\n");
        printf("====================================\n");
        scanf("%d", &option);
        if (option == 1)
        {
            printf("Input the student information\n");
            printf("Input 0 0 0 0 to stop\n");
            head = Create();
        }

        if (option == 2)
        {
            Printlinklist(head);
        }

        if (option == 3)
        {
            printf("Please input the student number\n");
            printf("you want to delete\n");
            scanf("%d", &temp);
            Del(head, temp);
        }

        if (option == 4)
        {
            printf("Please input the student information\n");
            printf("\nStudent number name sex age\n");
            node = (struct student *)malloc(LEN); //创建新节点，这个节点保存信息
            scanf("%d%s%s%d", &(node->num),
                  &(node->name),
                  &(node->sex),
                  &(node->age)); //录入数据
            printf("Please input the place you want to insert\n");
            printf("(a student number befor you want)\n");
            scanf("%d", &temp);
            Insert(head, temp, node);
        }
        if (option == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        if (option == 9)
        {
            printf("OK!\n");
        }
    }

    return 0;
}

/*
创建链表
*/
struct student *Create()
{
    struct student *head;      //头节点
    struct student *p1 = NULL; //p1保存创建的新节点的地址
    struct student *p2 = NULL; //p2保存原链表最后一个节点的地址

    n = 0;                              //创建前链表的节点总数为0：空链表
    p1 = (struct student *)malloc(LEN); //开辟一个新节点
    p2 = p1;

    if (p1 == NULL) //节点开辟不成功
    {
        printf("\nCann't create it!\n");
        return NULL;
    }
    else //节点开辟成功
    {
        head = NULL; //开始head指向NULL
        printf("Please input %d node information", n + 1);
        printf("\nStudent number name sex age\n");
        scanf("%d%s%s%d", &(p1->num),
              &(p1->name),
              &(p1->sex),
              &(p1->age)); // 录入数据
    }
    while (p1->num != 0) //学号为0是截止
    {
        n++;        //节点总数增加1个
        if (n == 1) //如果节点总数是1，则head指向刚创建的节点p1
        {
            head = p1;
            p2->next = NULL; //此时的p2就是p1,也就是p1->next指向NULL
        }
        else
        {
            p2->next = p1; //指向上次下面刚刚开辟的新节点
        }

        p2 = p1; //把p1的地址给p2保留，然后p1产生新的节点

        p1 = (struct student *)malloc(LEN);
        printf("Please input %d node information", n + 1);
        printf("\nStudent number name sex age\n");
        scanf("%d%s%s%d", &(p1->num),
              &(p1->name),
              &(p1->sex),
              &(p1->age)); //录入数据
    }
    p2->next = NULL;

    free(p1);
    p1 = NULL;
    return head;
}

/*
输出链表所有节点
*/
void Printlinklist(struct student *head)
{
    struct student *p;
    printf("\nNow , These %d records are:\n\n", n);
    printf("Number\tName\tsex\tage\n\n");
    p = head;
    if (head != NULL) //只要不是空链表，就输出链表中所有节点
    {
        do
        {
            printf("%d\t%s\t%s\t%d\n", p->num, p->name, p->sex, p->age);
            p = p->next; //移到下一个节点
        } while (p != NULL);
    }
}

/* 
删除指定学号的节点
*/
struct student *Del(struct student *head, int num)
{
    struct student *p1; //p1保存当前需要检查的节点的地址
    struct student *p2; //p2保存当前检查过的节点的地址
    if (head == NULL)   //如果是空链表
    {
        printf("\nList is null!\n");
        return head;
    }

    //定位要删除的节点
    p1 = head;
    while (p1->num != num && p1->next != NULL) //p1指向的节点不是所要查找的，并且它不是最后一个节点，就继续往下找
    {
        p2 = p1;       //保存当前节点的地址
        p1 = p1->next; //后移一个节点
    }

    if (p1->num == num) //寻找成功
    {
        if (p1 == head) //如果要删除的节点是第一个节点
        {
            head = p1->next; //头指针指向第一个节点的后一个节点，也就是第二个节点。这样第一个节点就不在链表中，即删除
        }
        else //如果是其它节点，则让原来指向当前节点的指针，指向它的下一个节点，完成删除
        {
            p2->next = p1->next;
        }

        free(p1); //释放当前节点
        p1 = NULL;
        printf("\nDelete %d success!\n", num);
        n -= 1; //节点总数减1个
    }
    else //没有找到
    {
        printf("\n%d Not been found!\n", num);
    }

    return head;
}

/*  
插入指定学号的后面 
*/
struct student *Insert(struct student *head, int num, struct student *node)
{
    struct student *p1;
    //p1保存当前需要检查的节点的地址
    if (head == NULL)
    {
        head = node;
        node->next = NULL;
        n += 1;
        return head;
    }

    p1 = head;
    while (p1->num != num && p1->next != NULL)
    //p1指向的节点不是所要查找的，并且它不是最后一个节点，继续往下找
    {
        p1 = p1->next; //后移一个节点
    }

    if (p1->num == num) //寻找成功
    {
        node->next = p1->next; //显然node的下一节点是原p1的next
        p1->next = node;       //插入后，原p1的下一节点就是要插入的node
        n += 1;                //节点总数增加1个
    }
    else
    {
        printf("\n%d not been found!\n", num);
    }
    return head;
}