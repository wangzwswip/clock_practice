/*简易通讯录*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20
#define OK 1
#define Error 0
typedef struct Node  //定义一个存储数据的结构体
{                       
	char name[SIZE];
	char s;
	long int number;
	char remark[SIZE];
	struct Node *next;
}Node;
typedef struct Node *LinkList; //定义了结构体指针
 
/************创建一个空的结点，作为头结点***************/
LinkList CreateEmptyLinkList()
{
	LinkList p;
	p=(LinkList)malloc(sizeof(Node));   //手动申请一个堆区的地址，为结点提供空间
	if(p==NULL)
	{
		printf("CreateEmptyLinkList Error\n");
		exit(0);
	}
	p->next=NULL;
	return p;
}
 
 
/************头插法添加新的联系人************************/
 
int CreateLinkList(LinkList Q)
{
	LinkList p;
	char name[SIZE],s,remark[SIZE];
	long int num;
	p=(LinkList)malloc(sizeof(Node));
	if(p==NULL)
	{
		printf("CreateLinkList Error\n");
		return Error;
	}
	printf("请输入姓名：");
	scanf("%s",name);
	strcpy(p->name,name);
	printf("请输入性别（m/男，f/女）：");
	scanf("%s",&s);
	while(s!='m'&&s!='f')
	{
		printf("输入错误\n");
		printf("请输入性别（m/男，f/女）：");
		scanf("%s",&s);
	}
	printf("请输入电话号码：");
	scanf("%ld",&num);
	printf("请输入备注：");
	scanf("%s",remark);
	p->s=s;
	p->number=num;
	strcpy(p->remark,remark);
	p->next=Q->next;
	Q->next=p;
	return OK;
}
/*********************制作原始联系人信息****************/
int FirstCreateLinkList(LinkList Q)
{
	LinkList x,y,z;
	x=(LinkList)malloc(sizeof(Node));
	if(x==NULL)
	{
		printf("CreateLinkList Error\n");
		return Error;
	}
	strcpy(x->name,"LiLi");
	x->s='f';
	x->number=10110;
	x->next=Q->next;
	strcpy(x->remark,"LiLi");
	Q->next=x;
	y=(LinkList)malloc(sizeof(Node));
	if(y==NULL)
	{
		printf("CreateLinkList Error\n");
		return Error;
	}
	strcpy(y->name,"NaNa");
	y->s='f';
	y->number=11100;
	strcpy(y->remark,"NaNa");
	y->next=Q->next;
	Q->next=y;
	z=(LinkList)malloc(sizeof(Node));
	if(z==NULL)
	{
		printf("CreateLinkList Error\n");
		return Error;
	}
	strcpy(z->name,"LiuLiu");
	z->s='m';
	z->number=10000;
	strcpy(z->remark,"LiuLiu");
	z->next=Q->next;
	Q->next=z;
	return OK;
}
/*****************按姓名删除一个联系人****************************/
 
int DeleteNameLinkList(LinkList L,char name1[SIZE])
{
	LinkList p,q;
	p=L;
	while(p->next && strcmp(p->next->name,name1))
	{
		p=p->next;
	}
	if(!p->next)
	{
		printf("该通讯录没有要删除的联系人，删除失败！\n");
		return Error;
	}
	else
	{
	q=p->next;
	printf("已删除联系人:\n");
	printf("姓名：%s\n",q->name);
	if(q->s=='m')
		printf("性别：男\n");
	else
		printf("性别：女\n");
	printf("电话号码：%ld\n",q->number);
	printf("备注：%s\n",q->remark);	
	
	p->next=q->next;
	free(q);
	return OK;
	}
}
/*****************按号码删除一个联系人****************************/
 
int DeleteNumLinkList(LinkList L,long int j)
{
	LinkList p,q;
	p=L;
	while((p->next->number!=j)&&((p->next)!=NULL))
	{
		p=p->next;
		if((p->next)==NULL)
		{
			printf("该通讯录没有要删除的联系人，删除失败！\n");
			return Error;
		}
	}
	q=p->next;
	printf("已删除联系人:\n");
	printf("姓名：%s\n",q->name);
	if(q->s=='m')
		printf("性别：男\n");
	else
		printf("性别：女\n");
	printf("电话号码：%ld\n",q->number);
	printf("备注：%s\n",q->remark);	
	p->next=q->next;
	free(q);
	return OK;
}
 
/******************按姓名查找一个联系人****************************/
int FindNameLinkList(LinkList L,char name2[SIZE])
{
	LinkList p,q;
	p=L;
	while(strcmp(p->next->name,name2)!=0&&(p->next!=NULL))
	{
		p=p->next;
		if(p->next==NULL)
		{
			printf("该通讯录没有您要找的人，查找失败\n");
			return Error;
		}
	}
	q=p->next;
	printf("找到记录：\n");
	printf("姓名：%s\n",q->name);
	if(q->s=='m')
		printf("性别：男\n");
	else
		printf("性别：女\n");
	printf("电话号码：%ld\n",q->number);
	printf("备注：%s\n",q->remark);
	printf("*********************************\n");
	return OK;
}
/******************按号码查找一个联系人****************************/
int FindNumLinkList(LinkList L,long int j)
{
	LinkList p,q;
	p=L;
	while((p->next->number!=j)&&((p->next)!=NULL))
	{
		p=p->next;
		if((p->next)==NULL)
		{
			printf("该通讯录没有您要找的人，查找失败\n");
			return Error;
		}
	}
	q=p->next;
	printf("找到记录：\n");
	printf("姓名：%s\n",q->name);
	if(q->s=='m')
		printf("性别：男\n");
	else
		printf("性别：女\n");
	printf("电话号码：%ld\n",q->number);
	printf("备注：%s\n",q->remark);
	printf("*********************************\n");
	return OK;
}
/******************查找一个联系人****************************/
int FindLinkList(LinkList L)
{
	LinkList head = L;					
	printf("*********************************\n");
	printf("请输入查找联系人的方式：\n");
	printf("1:按姓名\n");
	printf("2:按号码\n");
	printf("0:返回\n");
	printf("*********************************\n");
	printf("请选择：");
	int k=3;   //确保下面while循环运行
	while(k)
	{
		scanf("%d",&k);
		char Delname1[SIZE];
		long int N;
		if(k>2||k<0)
		{
			printf("输入错误，请重新输入：");
			scanf("%d",&k);
			while(getchar()!='\n')
			printf("\n");
		}
		switch(k)
		{
			case 1:
				printf("请输入姓名：");
				scanf("%s",Delname1);
				FindNameLinkList(head,Delname1);
				k=0;
				break;
			case 2:
				printf("请输入号码：");
				scanf("%ld",&N);
				FindNumLinkList(head,N);
				k=0;
				break;
		}
 
	}
}
/********************清空联系人信息*************************/
int ClearLinkList(LinkList L)
{
	LinkList p,q;
	p=L->next;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;
	printf("清空所有联系人成功\n");
	return OK;
}
 
/*********************筛选所有男性联系人**********************/
int ScreenMaleLinkList(LinkList L)
{
	LinkList p;
	p=L->next;
	int i=0;
	while(p)
	{
		if(p->s=='m')
		{
			printf("姓名：%s\n",p->name);
			if(p->s=='m')
				printf("性别：男\n");
			else
				printf("性别：女\n");
			printf("电话号码：%ld\n",p->number);
			printf("备注：%s\n",p->remark);	
			printf("*********************************\n");
		}
		p=p->next;
		i++;
	}
	if(i==0&&!p)
	{
		printf("无男性联系人\n");
	}
	return OK;
}
/*********************筛选所女性联系人**********************/
int ScreenFemaleLinkList(LinkList L)
{
	LinkList p;
	p=L->next;
	int i=0;
	while(p)
	{
		if(p->s=='f')
		{
			printf("姓名：%s\n",p->name);
			if(p->s=='m')
				printf("性别：男\n");
			else
				printf("性别：女\n");
			printf("电话号码：%ld\n",p->number);
			printf("备注：%s\n",p->remark);	
			printf("*********************************\n");
		}
		p=p->next;
		i++;
	}
	if(i==0&&!p)
	{
		printf("无女性联系人\n");
	}
	return OK;
}
/************************通讯录功能界面*****************/
void FunctionalInterface()
{
	system ("clear");
	printf("*********************************\n");
	printf("欢迎使用Linux通讯录！\n");
	printf("*********************************\n");
	printf("1:输出全部联系人信息\n");
	printf("2:插入新的联系人\n");
	printf("3:删除一个联系人\n");
	printf("4:查找某个联系人\n");
	printf("5:清空全部联系人信息\n");
	printf("6:筛选全部男性联系人信息\n");
	printf("7:筛选全部女性联系人信息\n");
	printf("0:退出\n");
	printf("*********************************\n");
}
/*****************删除一个联系人****************************/
 
int DeleteLinkList(LinkList L)
{
	LinkList head = L;
	printf("*********************************\n");
	printf("请输入删除联系人的方式：\n");
	printf("1:按姓名\n");
	printf("2:按号码\n");
	printf("0:返回\n");
	printf("*********************************\n");
	printf("请选择：");
	int i=3;
	while(i)
	{
		scanf("%d",&i);
		char Delname[SIZE];
		long int j;
		if(i>2||i<0)
		{
			printf("输入错误，请重新输入：");
			scanf("%d",&i);
			while(getchar()!='\n')
			printf("\n");
		}
		switch(i)
		{
			case 1:
				printf("请输入姓名：");
				scanf("%s",Delname);
				DeleteNameLinkList(head,Delname);
				i=0;
				break;
			case 2:
				printf("请输入号码：");
				scanf("%ld",&j);
				DeleteNumLinkList(head,j);
				i=0;
				break;
		}
 
	}
 
}
/*******************遍历打印整个链表**********************/
int PrintfLinkList(LinkList L)
{
	LinkList p,q;
	q=p=L->next;
	int i=0;
	while(q)
	{
		i++;
		q=q->next;
	if(i==0&&!p)
	{
		printf("无联系人\n");
	}
	}
	printf("共有%d个联系人\n",i);
	while(p)
	{
		printf("*********************************\n");
		printf("姓名：%s\n",p->name);
		if(p->s=='m')
			printf("性别：男\n");
		else
			printf("性别：女\n");
		printf("电话号码：%ld\n",p->number);
		printf("备注：%s\n",p->remark);	
		p=p->next;
	}
	printf("*********************************\n");
	return OK;
 
}
 
int main()
{
	int a;
	LinkList head;
	head=CreateEmptyLinkList();
	FirstCreateLinkList(head);
	FunctionalInterface();
	while(a)
	{
		printf("请输入您要选择的功能:");
		scanf("%d",&a);
		if(a>7||a<0)
		{
			printf("输入错误，请重新输入：");
			scanf("%d",&a);
			while(getchar()!='\n')
			printf("\n");
		}
		switch(a)
		{
			case 1:
				PrintfLinkList(head);
				break;
			case 2:
				CreateLinkList(head);
				break;
			case 3:
				DeleteLinkList(head);
				break;
			case 4:
				FindLinkList(head);
				break;
			case 5:
				ClearLinkList(head);
				break;
			case 6:
				ScreenMaleLinkList(head);
				break;
			case 7:
				ScreenFemaleLinkList(head);
				break;
			}
		if(a!=0)
		{
			printf("请按回车键继续：");
			getchar();
			if(getchar()=='\n')
				FunctionalInterface();
		}
	}
	printf("欢迎再次使用\n");
	return 0;
}