#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct Node;
typedef Node* PNode;
int max_distance(PNode);

struct Node
{
  PNode lchild;
  PNode rchild;
  int data;
};

int max(int a,int b)
{
  return a > b ? a : b;
}

// 求p指向的二叉树的深度
int h(PNode p)
{
  if(NULL == p) return -1;
  return max(h(p->lchild), h(p->rchild)) + 1;
}

// 求p指向的二叉树的任意两点间最大距离 
int max_distance(PNode p)
{
  cout << " inside max dis" << endl;
  if(NULL == p) return -1;
  return max(max(h(p->lchild) + h(p->rchild) + 2, // 左右子树深度加+2
                 max_distance(p->lchild)), //左子树最大距离
            max_distance(p->rchild) // 右子树最大距离
      );
}

// 前序遍历初始化一颗二叉树，正整数为有效节点，-1表示空节点，序列以0结尾
PNode init_tree()
{
  int i;
  cin >> i;
  if(-1 == i) return NULL;
  PNode p = new Node;
  p -> data = i;
  p->lchild = init_tree();
  p->rchild = init_tree();
  return p;
}

void pre_order(const PNode root)
{
  if( NULL == root ) return;
  cout << root -> data;
  pre_order(root -> lchild);
  pre_order(root -> rchild);
}

int main()
{
  PNode ptree = init_tree();
  pre_order(ptree);

  cout << max_distance(ptree) << endl;
  return 0;
}



