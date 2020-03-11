#include<cstdio>
struct Node {
  Node(Node *_left, Node *_right, int _key) : left(_left), right(_right), key(_key) {}
  Node *left, *right;
  int key;
};

Node *root = NULL;
void insert(Node *node, int key) {
  if (node == NULL) {
    root = new Node(NULL, NULL, key);
    return;
  }
  
  if (node->key < key) {
    if (node->right) {
      insert(node->right, key);
    }
    else {
      node->right = new Node(NULL, NULL, key);
    }
  }
  else {
    if (node->left) {
      insert(node->left, key);
    }
    else {
      node->left = new Node(NULL, NULL, key);
    }
  }
}
void postorder(Node *node) {
  if (node == NULL) {
    return;
  }
  
  postorder(node->left);
  postorder(node->right);
  printf("%d\n", node->key);
}
int main() {
  int num;
  while (scanf("%d", &num) != EOF) {
    insert(root, num);
  }
  postorder(root);
}

/*
  트리 직접 구현하는 법 연습하기 중
*/