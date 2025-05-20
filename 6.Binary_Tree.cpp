#include <iostream>
#include <algorithm> // for max
using namespace std;

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
} TreeNode;

TreeNode* createTree() {
    int data;
    cin >> data;
    if (data == -1) return NULL;
    TreeNode* root = new TreeNode(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}

int Sum(TreeNode* root) {
    if (root == NULL) return 0;
    return Sum(root->left) + Sum(root->right) + root->data;
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int height(TreeNode* root) {
    if (root == NULL) return 0;
    int LST = height(root->left);
    int RST = height(root->right);
    return max(LST, RST) + 1;
}

// ✅ Function to calculate the diameter of the binary tree
int diameter(TreeNode* root, int& max_dia) {
    if (root == NULL) return 0;
    int left = diameter(root->left, max_dia);
    int right = diameter(root->right, max_dia);
    max_dia = max(max_dia, left + right);
    return max(left, right) + 1;
}

int main() {
    TreeNode* root = createTree();

    inorder(root);
    cout << endl;

    preorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    cout << "Sum: " << Sum(root) << endl;
    cout << "Height: " << height(root) << endl;

    int max_dia = 0;
    diameter(root, max_dia);
    cout << "Diameter: " << max_dia << endl;

    return 0;
}
