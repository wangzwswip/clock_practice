/* list.h--简单链表类型的头文件 */
#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
//特定程序的声明
#define TSIZE 45//存储电影名的数组大小
struct film
{
    char title[TSIZE];
    int rating;//打分
};
//一般类型的定义
typedef struct film Item;
typedef struct node
{
    Item item;
    struct node *next;
    
} Node;
typedef Node *List;
//函数原型
//初始化一个链表
void InitializeList(List *plist);
//确定链表是否为空
bool ListIsEmpty(const List *plist);
//确定链表是否已满
bool ListIsFull(const List *plist);
//确定链表中的项数
unsigned int ListItemCount(const List *plist);
//在链表末尾添加项
bool AddItem(Item item,List *plist);
//把函数作用于每一项
void Teaverse(const List *plist,void(*pfun)(Item item));
//释放已分配的内存
void EmptyTheList(List *plist);
#endif