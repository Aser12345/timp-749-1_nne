#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct List
{
struct List *NextBlock;
double Data;
} List;
typedef struct node
{
struct node *NextBlock;
double Data;
}node;
void init( List **l)
{
*l = ( List *)malloc(sizeof( List));
(*l)->NextBlock = NULL;
(*l)->Data = 2147483648;
}
void clean( List *l)
{
 List *Temp = l;
do
{
Temp = Temp->NextBlock;
free(l);
l = Temp;
} while (l != NULL);
}
bool is_empty( List *l)
{
if (l == NULL)
return 0;
else
return 1;
}
 node *find( List *l, int value)
{
 List *Temp = l;
while (1)
{
if (Temp == NULL)
return NULL;
else
{
if ((Temp->Data) == value)
return (( node *)l);
}
Temp = Temp->NextBlock;
}
}
int push_back( List *l, int value)
{
if (l->Data == 2147483648)
{
l->Data = value;
return 0;
}
 List *Temp = ( List *)malloc(sizeof( List));
Temp = l;
while (Temp->NextBlock != NULL)
Temp = Temp->NextBlock;
Temp->NextBlock = ( List *)malloc(sizeof( List));
Temp = Temp->NextBlock;
Temp->Data = value;
Temp->NextBlock = NULL;
return 0;
}
int push_front( List **l, int value)
{
 List *Temp = ( List *)malloc(sizeof( List));
Temp->Data = value;
Temp->NextBlock = (*l);
(*l) = Temp;
return 0;
}
int insert_after( node *l, int value)
{
 List *Temp = ( List *)malloc(sizeof( List)), *Temp2;
Temp2=( List *)l->NextBlock;
l->NextBlock =( node *)Temp;
Temp->Data = value;
Temp->NextBlock = Temp2;
return 0;
}
int remove_node( List *l, int value)
{
 List *Temp = l;
if (l != NULL)
{
while (1)
{
if ((Temp->NextBlock) == NULL)
return 1;
if ((Temp->NextBlock->Data) == value)
{
 List *Temp2 = ( List *)malloc(sizeof(List));
Temp2 = Temp->NextBlock->NextBlock;
free(Temp->NextBlock);
Temp->NextBlock = Temp2;
return 0;
}
Temp = Temp->NextBlock;
}
}
else
return 1;
}
void print( List *l)
{
while (l != NULL)
{
printf("%.0lf ", l->Data);
l = l->NextBlock;
}
printf("\n");
}
int main()
{
 List *l, *Temp;
int N, i;
double a, b;
scanf("%d", &N);//1
init(&l);//2
for (i = 0; i < N; i++)
{
scanf("%lf", &a);
push_back(l, a);
}
print(l);//3
for (i = 0; i < 3; i++)//4
{
scanf("%lf", &a);
if (find(l, a) == NULL)
printf("0\n");
else
printf("1\n");
}
scanf("%lf", &a);//5
push_back(l, a);
print(l);//6
scanf("%lf", &a);//7
push_front(&l, a);
print(l);//8
scanf("%lf", &a);//9
scanf("%lf", &b);
 node *el=( node *)l;
while (a != 1)
{
el = el->NextBlock;
a--;
}
insert_after(el, b);
print(l);//10
scanf("%lf", &a);//11
if (l->Data==a)
{
Temp=l->NextBlock;
free(l);
l=Temp;
}
else
remove_node(l, a);
print(l);//12
clean(l);//13
return 1;
}
