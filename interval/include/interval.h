#ifndef interval_h
#define interval_h

#include <stdio.h>
#include <stdlib.h>
#include "interval.h"

typedef struct interval{
 int low;
 int high;
}interval;

typedef struct node{
  int max;
  interval *i;
  struct node *left;
  struct node *right;
}node;

node* createNode(interval i);
interval createInterval(int low,int high);

node* insert(node* root, interval i );

int overlap(interval i1,interval i2);

interval overlapSearch(node* root ,interval i);

void inorder(node* root);

node* delete( node *root, interval key);

node *minimum( node *x);




#endif /* interval_h */