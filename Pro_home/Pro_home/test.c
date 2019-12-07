#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define Maxsize 100

typedef struct ANode
{
	int adjchild;//�洢���ӵ�αָ��
	struct ANode *nextchild;//ָ����һ�����ӵ�ָ��
}ArcNode;

typedef struct JDdate
{
	char name[20];
	char sex[10];
	char birthday[20];
	char wifename[20];
	char thing[100];
	char relationship[30];
}ElemType;

typedef struct VNode//��ͷ���
{
	ElemType data;//˫����Ϣ
	int adjparents;//˫�׵�ַ��αָ��
	ArcNode *firstchild;//ָ���һ������

}st;

void CreatTree(int n);//���������Ա
void InputTree(int n);//��������Ա
void InestTree(int n);//���뺢��
void DeleteTree(int n);//ɾ�������Ա
void ReviseTree(int n);//�޸ļ����Ա
void SearchTree(int n);//���¼����Ҽ����Ա
int system(const char *string);//����

st Pt[Maxsize];//����ṹ������
/*********************���������Ա**********************/
void CreatTree(int n)//n��ȫ����Ա
{
	system("cls");
	int i, j, p = 0, q = 0, d;
	ArcNode *m = NULL, *w = NULL;
	char namechild[20];
	char nameparents[20];
	for (i = 0; i<n; i++)
	{
		Pt[i].adjparents = 0;
	}
	printf("����������ȫ�������Ա��Ϣ:\n");
	for (i = 0; i<n; i++)
	{
		scanf("%s%s%s%s%s%s", Pt[i].data.name, Pt[i].data.sex, Pt[i].data.birthday, Pt[i].data.wifename, Pt[i].data.thing, Pt[i].data.relationship);
	}
	printf("����������һ��˫�׺����м�������\n");
	scanf("%s%d", nameparents, &d);
	printf("�����뺢�ӵ����֣�\n");
	for (i = 0; i<d; i++)
	{
		scanf("%s", namechild);
		for (j = 0; j<n; j++)
		{
			if (strcmp(namechild, Pt[j].data.name) == 0)
			{
				p = j;//���ӵ�λ�� 4
			}
			if (strcmp(nameparents, Pt[j].data.name) == 0)
			{
				q = j;//˫�׵�λ�� 1
			}
		}
		Pt[p].adjparents = q;
		if (i == 0)
		{
			m = (ArcNode*)malloc(sizeof(ArcNode));
			Pt[q].firstchild = m;
			m->adjchild = p;
			m->nextchild = NULL;
			w = m;
		}
		else
		{
			m = (ArcNode*)malloc(sizeof(ArcNode));
			w->nextchild = m;
			m->adjchild = p;
			w = m;
		}
		w->nextchild = NULL;
	}
	printf("�����ɹ���\n");
}
/***********************��������Ա**********************/
void InputTree(int n)

{
	system("cls");
	int a;
	for (int i = 0; i<n; i++)
	{
		ArcNode *w = Pt[i].firstchild;
		printf("[%d]%s %s %s %s %s %s\n", i + 1, Pt[i].data.name, Pt[i].data.sex, Pt[i].data.birthday, Pt[i].data.wifename, Pt[i].data.thing, Pt[i].data.relationship);
		while (w != NULL)
		{
			a = w->adjchild;
			printf("  %s %s %s %s %s %s\n", Pt[a].data.name, Pt[a].data.sex, Pt[a].data.birthday, Pt[a].data.wifename, Pt[a].data.thing, Pt[a].data.relationship);
			w = w->nextchild;
		}
		printf("\n\n");
	}
}
/*********************���뺢��**********************/
void InestTree(int n)
{
	system("cls");
	int p, q;
	ArcNode *m = NULL;
	char namechild[20];
	char nameparents[20];
	printf("������Ҫ�����˫�׺ͺ���:\n");
	scanf("%s%s", nameparents, namechild);
	for (int i = 0; i<n; i++)
	{
		if (strcmp(nameparents, Pt[i].data.name) == 0)
		{
			q = i;//˫��λ��
		}
		if (strcmp(namechild, Pt[i].data.name) == 0)
		{
			p = i;//���ӵ�λ��
		}
	}
	Pt[p].adjparents = q;
	m = (ArcNode*)malloc(sizeof(ArcNode));
	m->adjchild = p;
	m->nextchild = Pt[q].firstchild;
	Pt[q].firstchild = m;
	printf("��ӳɹ���\n");
}
/************************ɾ�������Ա***************************/

void DeleteTree(int n)
{
	system("cls");
	char nameDelete[20];
	printf("Ҫɾ���ļ����Ա�����֣�\n");
	scanf("%s", nameDelete);
	for (int i = 0; i<n; i++)
	{
		if (strcmp(nameDelete, Pt[i].data.name) == 0)
		{
			for (int j = i; j<n - 1; j++)
			{
				Pt[j] = Pt[j + 1];
			}
		}
	}
	printf("ɾ���ɹ���\n");
}

/*********************�޸ļ����Ա*************************/
void ReviseTree(int n)
{
	system("cls");
	char reviseName[20];
	int i, m;
	char name[20];
	char sex[10];
	char birthday[20];
	char wifename[20];
	char thing[100];
	char relationship[30];
	printf("������Ҫ�޸ļ����Ա�����֣�\n");
	scanf("%s", reviseName);
	for (i = 0; i<n; i++)
	{
		if (strcmp(reviseName, Pt[i].data.name) == 0)
		{
			printf("��ѡ��Ҫ�޸ļ����Ա����Ϣ(1.���� 2.�Ա� 3.�������� 4.��ż���� 5.�¼� 6.��ϵ)\n");
			scanf("%d", &m);
			switch (m)
			{
			case 1:
				printf("�����룺\n");
				scanf("%s", name);
				strcpy(Pt[i].data.name, name);
				break;
			case 2:
				printf("�����룺\n");
				scanf("%s", sex);
				strcpy(Pt[i].data.sex, sex);
				break;
			case 3:
				printf("�����룺\n");
				scanf("%s", birthday);
				strcpy(Pt[i].data.birthday, birthday);
				break;
			case 4:
				printf("�����룺\n");
				scanf("%s", wifename);
				strcpy(Pt[i].data.wifename, wifename);
				break;
			case 5:
				printf("�����룺\n");
				scanf("%s", thing);
				strcpy(Pt[i].data.thing, thing);
				break;
			case 6:
				printf("�����룺\n");
				scanf("%s", relationship);
				strcpy(Pt[i].data.relationship, relationship);
				break;
			default:
				printf("��������");
			}
		}
	}
	printf("�޸ĳɹ���\n");
}

/************����**************/
void SearchTree(int n)
{
	system("cls");
	int i, k = 0;
	char thing[100];
	printf("����������Ա���¼���\n");
	scanf("%s", thing);
	for (i = 0; i < n; i++)
	{
		k++;
		if (strcmp(thing, Pt[i].data.thing) == 0)
		{
			printf("%s %s %s %s %s %s\n", Pt[i].data.name, Pt[i].data.sex, Pt[i].data.birthday, Pt[i].data.wifename, Pt[i].data.thing, Pt[i].data.relationship);
			break;
		}
	}
	if (k == n&&i != n - 1)
		printf("���¼�û�в鵽���ˣ���׼ȷ������˵��¼���\n");
}
int main()
{
	int n, m;
	printf("ȫ�������Ա������\n");
	scanf("%d", &m);
	while (1)
	{
		printf("��ѡ��1.����.2.��� 3.���� 4.ɾ�� 5.�޸� 6.���� 7.�˳�\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			CreatTree(m);
			break;
		case 2:
			InputTree(m);
			break;
		case 3:
			InestTree(m);
			break;
		case 4:
			DeleteTree(m);
			break;
		case 5:
			ReviseTree(m);
			break;
		case 6:
			SearchTree(m);
			break;
		case 7:
			exit(1);
			break;
		default:
			printf("��������\n");
			break;
		}
	}
	return 0;
}