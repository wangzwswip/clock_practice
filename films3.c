/* films3.c --使用抽象数据类型（ADT）风格的链表 */
/* 与list,c一起编译  */
#include <stdio.h>
#include <stdlib.h> //提供exit()原型
#include <string.h>
#include "list.h"   //定义List、Item
void showmovies(Item item);
char *s_gets(char *st,int n);
int main(void)
{
    List movies;
    Item temp;
    //初始化
    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr,"No memeory available! Bye！\n");
        exit(1);
    }
    //获取用户输入并存储
    puts("Enter first movie title:");
    while (s_gets(temp.title,TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d",&temp.rating);
        while(getchar() != '\n'){
            continue;
        }
        if (AddItem(temp,&movies) == false)
        {
            fprintf(stderr,"Problem allocating memory\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("The list is now full.\n");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }
    //显示列表
    if (ListIsEmpty(&movies))
    {
        printf("No data entered. ");
    }
    else
    {
        printf("Here is the movie list:\n");
        Traverse(&movies,showmovies);
    }
    printf("You entered %d movies.\n",ListItemCount(&movies));
    //清理
    EmptyTheList(&movies);
    printf("Bye!\n");
    return 0;
}
void showmovies(Item item)
{
    printf("Movie: %s Rating: %d",item.title,item.rating);
}
char *s_gets(char *st,int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st,n,stdin);//fgets读取成功返回指向取得值的指针，包含换行符
    if (ret_val)
    {
        find = strchr(st,'\n');//查找换行符
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
        
    }
    return ret_val;
}
