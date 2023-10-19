#include<stdio.h>
#include<stdlib.h>

struct node *add_to_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
int cmp(const void *a, const void *b);

struct node
{
	int value;
	struct node *next;
};

int main()
{
	return 0;
}

//�������в�����(list��ָ����б����׽���ָ��,n����Ҫ�洢���½���е�����)
struct node *add_to_list(struct node *list, int  n)
{
	struct node *new_node;

	new_node=malloc(sizeof(struct node));
	if(new_node == NULL)
	{
		printf("���ˡ�\n");
		exit(EXIT_FAILURE);
	}
	new_node->value=n;
	new_node->next=list;
	return new_node;
}

//������ɾ�����(list��ָ����б����׽���ָ��,n��ɾ������n�ĵ�һ�����)
struct node *delete_from_list(struct node *list, int n)
{
	struct node *cur, *prev;

	for(cur=list, prev=NULL;
		cur !=NULL && cur->value != n;
		prev=cur, cur=cur->next)
	{
		;
	}

	if(cur == NULL)
	{
		return list;
	}
	if(prev == NULL)
	{
		list=list->next;
	}
	else
	{
		prev->next=cur->next;
	}
	free(cur);
	return list;
}

//����qsort(������a, Ҫ����Ԫ�ص�����sz�� ÿ��Ԫ�صĴ�Сsizeof(arr[0])ʱ��cmp����һ��������
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);//��С������
	//return (*(int *)b - *(int *)a);//�ɴ�С��
}