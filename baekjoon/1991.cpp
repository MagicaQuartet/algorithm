#include<iostream>
using namespace std;
struct Node {
  Node(Node *_left, Node *_right, char _name) : left(_left), right(_right), name(_name) {}
  Node *left, *right;
  char name;
};
int N;
Node *nodes[26];
void preorder(Node *root) {
  if (root == NULL) return;
  
  cout << root->name;
  preorder(root->left);
  preorder(root->right);
}
void inorder(Node *root) {
  if (root == NULL) return;
  
  inorder(root->left);
  cout << root->name;
  inorder(root->right);
}
void postorder(Node *root) {
  if (root == NULL) return;
  
  postorder(root->left);
  postorder(root->right);
  cout << root->name;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> N;
  for (int i=0; i<N; i++) {
    nodes[i] = new Node(NULL, NULL, 'A'+i);
  }
  for (int i=0; i<N; i++) {
    char root, left, right;
    cin >> root >> left >> right;
    if (left != '.') {
      nodes[root-'A']->left = nodes[left-'A'];
    }
    if (right != '.') {
      nodes[root-'A']->right = nodes[right-'A'];
    }
  }
  
  preorder(nodes[0]);
  cout << "\n";
  inorder(nodes[0]);
  cout << "\n";
  postorder(nodes[0]);
}