#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode;
string getHeader(int depth);
bool nodecmp(TreeNode* lhs, TreeNode* rhs);

int N, K;
struct TreeNode {
  string _label;
  int _depth;
  vector<TreeNode*> children;
  TreeNode(string label, int depth): _label(label), _depth(depth) {}

  string getLabel() {
    return _label;
  }

  int getDepth() {
    return _depth;
  }

  TreeNode* getChild(string label) {
    for (TreeNode* node: children) {
      if (node->getLabel() == label) {
        return node;
      }
    }

    TreeNode* child = new TreeNode(label, getDepth()+1);
    children.push_back(child);
    return child;
  }

  void sortNode() {
    sort(children.begin(), children.end(), nodecmp);
  }

  void printLabel() {
    if (_label == "") {
      return;
    }
    cout << getHeader(_depth) << _label << "\n";
  }
};

string getHeader(int depth) {
  string header = "--";
  string ret = "";
  while (depth--) {
    ret += header;
  }
  return ret;
}

bool nodecmp(TreeNode* lhs, TreeNode* rhs) {
  return lhs->getLabel() < rhs->getLabel();
}

void dfs(TreeNode* node) {
  node->printLabel();
  node->sortNode();
  for (TreeNode* child: node->children) {
    dfs(child);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  TreeNode* root = new TreeNode("", -1);
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> K;
    TreeNode* node = root;
    string label;
    for (int j=0; j<K; j++) {
      cin >> label;
      node = node->getChild(label);
    }
  }

  dfs(root);
}