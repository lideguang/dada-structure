#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define Error -1
typedef struct node
{
    int *elem;
    int len;
}Seqlist;
void InitList(Seqlist *l)//初始化线性表
{
    l->elem=(int *)malloc(sizeof(int)*100);
    l->len=0;
}
void DestroyList(Seqlist *l)//销毁线性表
{
    free(l->elem);
    l->len=0;
}
void ClearList(Seqlist *l)//清空线性表
{
    l->len=0;
}
int GetList(Seqlist *l,int id)//查找线性表位置的值
{
    if(id<1||id>l->len)
        return Error;
    return l->elem[id-1];
}
bool ListEmpty(Seqlist *l)//判断是否为空
{
    if(l->len==0)
        return true;
    return false;
}
int ListLength(Seqlist *l)//线性表长度
{
    return l->len;
}
int LocateList(Seqlist *l,int e)//查找当前位置
{
    int i;
    for(i=0;i<l->len;i++)
    {
        if(l->elem[i]==e)
        {
            return i+1;
        }
    }
    return Error;
}
int PriorList(Seqlist *l,int e)//查找其前一个位置
{
    int i;
    for(i=0;i<l->len;i++)
    {
        if(l->elem[i]==e)
        {
            if(i>0)
            {
                return l->elem[i-1];
            }
        }
    }
    return Error;
}
int NextList(Seqlist *l,int e)//查找其前一个位置
{
    int i;
    for(i=0;i<l->len;i++)
    {
        if(l->elem[i]==e)
        {
            if(i<l->len-1)
                return l->elem[i+1];
        }
    }
    return Error;
}
void ListInsert(Seqlist *l,int id,int e)//插入
{  int i;
   int *p,*q;
    if(id>100||id<1)
    {
        return ;
    }
    q=l->elem+id-1;
    for(p=l->elem+l->len-1;p>=q;p--)
        *(p+1)=*p;
         *q=e;
         l->len++;

}
void DeleteList(Seqlist *l,int id)//删除值的位置
{
    if(id<1||id>l->len)
        return ;
    int i;
    for(i=id-1;i<l->len-1;i++)
    {
        l->elem[i]=l->elem[i+1];
    }
    l->len--;
}
void DisplayList(Seqlist *l)//遍历线性表
{
    int i;
    for(i=0;i<l->len;i++)
        printf("%d ",l->elem[i]);
    printf("\n");
}
int main()
{
    Seqlist list;
    InitList(&list);
    ListInsert(&list,1,4);
    ListInsert(&list,2,3);
    ListInsert(&list,3,2);
    DisplayList(&list);
    DeleteList(&list,2);
    DisplayList(&list);
    printf("%d",ListLength(&list));
    printf("%d",LocateList(&list,4));

    return 0;
}
