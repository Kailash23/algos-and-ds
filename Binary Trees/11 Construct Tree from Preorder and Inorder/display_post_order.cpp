#include <iostream>
using namespace std;

struct Result {
    Result() : output1(){};
    int output1[100];
};

template <typename T>

class BinaryTreeNode {
  public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

int s = 0;

void postOrder(BinaryTreeNode<int> *root, int *output) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left, output);
    postOrder(root->right, output);
    output[s++] = root->data;
}

BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE) {
    if (inS > inE) {
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++) {
        if (in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }

    int LinS = inS;
    int LinE = rootIndex - 1;
    int RinS = rootIndex + 1;
    int RinE = inE;
    int LpreS = preS + 1;
    int LpreE = LpreS + (LinE - LinS);
    int RpreS = LpreE + 1;
    int RpreE = preE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, LinS, LinE, LpreS, LpreE);
    root->right = buildTreeHelper(in, pre, RinS, RinE, RpreS, RpreE);
    return root;
}

Result Find_PostOrder(int input1, int input2[], int input3[]) {
    BinaryTreeNode<int> *root = buildTreeHelper(input2, input3, 0, input1 - 1, 0, input1 - 1);

    int *output = new int[input1];
    postOrder(root, output);
    Result sol;
    for (int i = 0; i < input1; i++) {
        sol.output1[i] = output[i];
    }
    return sol;
}

int main() {
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    int size = sizeof(pre) / sizeof(pre[0]);
    Result ans = Find_PostOrder(size, in, pre);
    for (int i = 0; i < size; i++) {
        cout << ans.output1[i] << " ";
    }
}
