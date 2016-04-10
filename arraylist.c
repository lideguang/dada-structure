/**************************************************/
#include <stdio.h>
/**************************************************/
#define MaxSize	20						//线性表最大长度
#define	OK		1
#define ERROR	0
#define TRUE	1
#define	FALSE	0
typedef	int		Status;				
typedef int		ElemType;
/**************************************************/
typedef struct {
	ElemType	data[MaxSize+1];		//为了操作方便，规定下标从1开始
	int			length;					//顺序表当前长度
}SqList;
/**************************************************/
//置空表
Status	SetNull(SqList *L)
{
	L->length = 0;
	return OK;
}
/**************************************************/
//在末尾追加
Status append_arr(SqList *L, ElemType val)
{
	if (L->length > MaxSize)
		return FALSE;
	L->data[++L->length] = val;
	return TRUE;
}
/**************************************************/
//求顺序表的长度
int GetLength(SqList *L)
{
	return L->length;
}
/**************************************************/
//输出顺序表
void DisLisy(SqList *L)
{
	int i;
	for (i=1; i<=L->length; ++i)
		printf("%d ", L->data[i]);
}
/**************************************************/
//顺序表判空
Status ListEmpty(SqList *L)
{
	if (0 == L->length)
		return TRUE;
	else
		return FALSE;
}
/**************************************************/
//取得顺序表中第i个元素的值，放入e中
Status GetElem(SqList *L, int i, ElemType *e)
{
	if (i<=0 || i>L->length)
		return ERROR;

	*e = L->data[i];
	return OK;
}
/**************************************************/
//查找顺序表中是否有与e相同的元素
//若有则返回该元素的下标
//否则返回0
Status LocateElem(SqList *L, ElemType e)
{
	int i;
	for (i=1; i<=L->length; ++i)
	{
		if (e == L->data[i])
			return i;
	}
	return FALSE;
}
/**************************************************/
//在顺序表中的第i个位置插入元素e
//若插入成功返回TRUE
//否则返回FALSE
Status ListInset(SqList *L, int i, ElemType e)
{
	int k;

	if ( (i<1 || i>L->length+1) 
		 && (L->length < MaxSize) )
		return FALSE;
	
	if (i<=L->length)
	{
		for (k=L->length; k>=i; --k)
			L->data[k+1] = L->data[k];
	}
	L->data[i] = e;
	++L->length;
	return TRUE;

}
/**************************************************/
//删除顺序表中第i个元素的值
//删除成功返回被删除的元素的值
//删除失败返回FALSE
Status ListDelete(SqList *L, int i, ElemType *e)
{
	int k;
	if (ListEmpty(L))
		return FALSE;
	if (i<1 || i>L->length)
		return FALSE;
	
	*e = L->data[i];
	if (i<L->length)
	{
		for (k=i; k<L->length; ++k)	
			L->data[k] = L->data[k+1];
	}
	--L->length;
	return TRUE;
}
/**************************************************/
int main(void)
{
	SqList L;
	ElemType e;
	SetNull(&L);
	append_arr(&L, 3);
	append_arr(&L, 2);
	append_arr(&L, 6);
	append_arr(&L, 2);
	ListDelete(&L, 2, &e);
	DisLisy(&L);
	printf("\n\n%d", e);
	return 0;
}
