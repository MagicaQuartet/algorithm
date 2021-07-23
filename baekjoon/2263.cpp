#include<cstdio>
int N;
int inorder[100010], postorder[100010];
int pidx;

struct Node {
  struct Node *left;
  struct Node *right;
  int num;
};

void search(Node *node, int ileft, int iright) {
  node->num = postorder[pidx--];
  node->left = NULL;
  node->right = NULL;
  int iidx;
  for (int i=ileft; i<=iright; i++) {
    if (inorder[i] == node->num) {
      iidx = i;
      break;
    }
  }
  if (iidx < iright) {
    Node *r = new Node;
    node->right = r;
    search(r, iidx+1, iright);
  }
  if (ileft < iidx) {
    Node *l = new Node;
    node->left = l;
    search(l, ileft, iidx-1);
  }
}

void preorder(Node *node) {
  printf("%d ", node->num);
  if (node->left != NULL) {
    preorder(node->left);
  }
  if (node->right != NULL) {
    preorder(node->right);
  }
}

int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", inorder+i);
  }
  for (int i=0; i<N; i++) {
    scanf("%d", postorder+i);
  }

  Node *root = new Node;
  pidx = N-1;
  search(root, 0, N-1);
  preorder(root);
}
