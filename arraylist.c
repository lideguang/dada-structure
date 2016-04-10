/**************************************************/
#include <stdio.h>
/**************************************************/
#define MaxSize	20						//���Ա���󳤶�
#define	OK		1
#define ERROR	0
#define TRUE	1
#define	FALSE	0
typedef	int		Status;				
typedef int		ElemType;
/**************************************************/
typedef struct {
	ElemType	data[MaxSize+1];		//Ϊ�˲������㣬�涨�±��1��ʼ
	int			length;					//˳���ǰ����
}SqList;
/**************************************************/
//�ÿձ�
Status	SetNull(SqList *L)
{
	L->length = 0;
	return OK;
}
/**************************************************/
//��ĩβ׷��
Status append_arr(SqList *L, ElemType val)
{
	if (L->length > MaxSize)
		return FALSE;
	L->data[++L->length] = val;
	return TRUE;
}
/**************************************************/
//��˳���ĳ���
int GetLength(SqList *L)
{
	return L->length;
}
/**************************************************/
//���˳���
void DisLisy(SqList *L)
{
	int i;
	for (i=1; i<=L->length; ++i)
		printf("%d ", L->data[i]);
}
/**************************************************/
//˳����п�
Status ListEmpty(SqList *L)
{
	if (0 == L->length)
		return TRUE;
	else
		return FALSE;
}
/**************************************************/
//ȡ��˳����е�i��Ԫ�ص�ֵ������e��
Status GetElem(SqList *L, int i, ElemType *e)
{
	if (i<=0 || i>L->length)
		return ERROR;

	*e = L->data[i];
	return OK;
}
/**************************************************/
//����˳������Ƿ�����e��ͬ��Ԫ��
//�����򷵻ظ�Ԫ�ص��±�
//���򷵻�0
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
//��˳����еĵ�i��λ�ò���Ԫ��e
//������ɹ�����TRUE
//���򷵻�FALSE
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
//ɾ��˳����е�i��Ԫ�ص�ֵ
//ɾ���ɹ����ر�ɾ����Ԫ�ص�ֵ
//ɾ��ʧ�ܷ���FALSE
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
