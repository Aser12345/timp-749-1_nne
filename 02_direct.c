#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

typedef struct node
{
  int data;
  struct node * left;
  struct node * right;
  struct node * parent;
} node;

typedef struct tree
{
  struct node * root;   // указатель на корень дерева
  int count;            // количество узлов в дереве
} tree;

void init(tree * t)
{
    struct tree * new_t = malloc(sizeof new_t);
    new_t->root = NULL;
    new_t->count = 0;
    t = new_t;
}

int find(tree* t, int value, node* n)
{
  struct node * n2;
  n2 = t->root;

  if (t->root == NULL){
    return 1;
  }


  while (1){
    if (n2 == NULL) {
      return 1;
    } else if (n2->data == value){

      n->data = n2->data;
      n->left = n2->left;
      n->right = n2->right;
      n->parent = n2->parent;

      return 0;
    } else if (value > n2->data){
      n2 = n2->right;
    } else {
      n2 = n2->left;
    }
  }

  return 1;
}

int insert(tree* t, int value)
{
  struct node * n, ** nn, * last_n = NULL;

  struct node * e_n;
  e_n = malloc(sizeof * e_n);

  int err = find(t, value, e_n);
  if (err == 0){
    return 1;
  }

  nn = &t->root;
  n = t->root;

  while (1){
    if (n == NULL) {
      n = *nn = malloc(sizeof * n);
      if (n != NULL){
        n->data = value;
        n->left = NULL;
        n->right = NULL;
        n->parent = last_n;

        t->count++;
        return 0;
      } else {

        return 2;
      }
    }
    last_n = n;

    if (value > n->data){
      nn = &n->right;
      n = n->right;
    } else {
      nn = &n->left;
      n = n->left;
    }
  }
  return 0;
}

void direct(struct tree * t)
{
    node * a[15];
    int a_i = 0;

    node * write[15];
    int w_i = 0;

    node * n = t->root;

    while (w_i < t->count){
        while (n != NULL){
            w_i++;
            if (n->right != NULL){
                a_i++;
                a[a_i] = n->right;
            }
            write[w_i] = n;
            n = n->left;
        }
        n = a[a_i];
        a_i -= 1;

    }
    int flag = 0;
    for (int i = 1; i <= w_i; i++){
        if (flag > 0){
            printf(" ");
        } else {
            flag++;
        }
        printf("%d", write[i]->data);
    }

  printf("\n");
}

int main(){
  struct tree * t = malloc(sizeof t);
  init(t);
  for (int i = 0; i < 7; i++){
    int a;
    scanf("%d", &a);
    insert(t, a);
  }
  direct(t);
  return 0;
}
