#include <iostream>
#include <time.h>
using namespace std;

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} TreeNode;

TreeNode* treeInsert(TreeNode *t, int data)
{
    TreeNode *NewNode;
    //NewNode = new TreeNode ;
    NewNode = (TreeNode*) malloc(sizeof(TreeNode));
    NewNode->key = data;
    NewNode->right = NULL;
    NewNode->left = NULL;
    TreeNode *current = t;
    TreeNode *parent = t;

    if (t==NULL) t=NewNode;
    else{
        while (current->key !=data)
        {
            parent = current;
            if(current->key > data){
                current = current->left;
                if(current==NULL){
                    parent->left = NewNode;
                    return t;
                }
            }
            else{
                current = current->right;
                if(current==NULL){
                    parent->right = NewNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void PrintTree(TreeNode *root)
{
    if(root){
        cout << root->key;
        if(root->left || root->right){
            cout << "(";
            if(root->left) PrintTree(root->left);
            else cout << "NULL";
            cout << ",";
            if(root->right) PrintTree(root->right);
            else cout << "NULL";
            cout << ")";
        }
    }
}

TreeNode* getSuccessor(TreeNode *node){
    TreeNode *current = node->right;
    TreeNode *parent = node;
    TreeNode *s=node;

    while(current!=NULL){
        parent=s;
        s=current;
        current=current->left;
    }
    if(s!=node->right){
        parent->left = s->right;
        s->right = node->right;
    }
    return s;
}


bool NodeDelete(TreeNode *root,int key){
    TreeNode *current = root;
    TreeNode *parent = root;
    bool isLeftChild = true;
    while (current->key != key){
        parent = current;
        if(key < current->key){
            current=  current->left;
            isLeftChild = true;
        }
        else{
            current=  current->right;
            isLeftChild = false;
        }
        if(current ==NULL)  return false;
    }
    if(current->left==NULL && current->right==NULL){
        if(current==root)   root=NULL;
        else if(isLeftChild) parent->left=NULL;
        else parent->right = NULL;
    }
    else if(current->right==NULL){
        if(isLeftChild) parent->left=current->left;
        else parent->right = current->left;
    }
    else if(current->left==NULL){
        if(isLeftChild) parent->left=current->right;
        else parent->right = current->right;
    }
    else {
        TreeNode  *successor = getSuccessor(current);
        if(current ==root) root = successor;
        else if(isLeftChild) parent->left = successor;
        else parent->right = successor;
        successor->left = current->left;
    }
    return true;
}
//task 1
int height(TreeNode * root){
    if(root==NULL)  return 0;
    return 1 + max(height(root->left),height(root->right));
}

bool isBalanced(TreeNode *root)
{
    return height(root->left) == height(root->right);
}
//task 2
void Create(TreeNode **root,int quant)
{
    for(int i=0;i<quant;++i)
    {
        root[i]= nullptr;
        root[i] = treeInsert(root[i],rand());
        for(int j=1;j<10000;++j) treeInsert(root[i],rand());
    }
}
//task 3
float Percent(TreeNode **root,int quant)
{
    int sum=0;
    for(int i=0;i<quant;++i){
        if(isBalanced(root[i])) sum++;
    }
    return (float)sum/(float)quant;
}
int main() {
    //task 1 test
    /*TreeNode *tree = nullptr;
    tree = treeInsert(tree, 10);
    treeInsert(tree,8);
    treeInsert(tree,12);
    treeInsert(tree,5);
    treeInsert(tree,11);
    treeInsert(tree,13);
    PrintTree(tree);
    cout << endl;
    if(isBalanced(tree)) cout << "YES\n";
    else cout << "NO\n";*/
    //task 2 test
    /*srand(time(0));
    TreeNode *TS[50];
    Create(TS,50);*/
    //task 3 test
    /*srand(time(0));
    TreeNode *TS[50];
    Create(TS,50);
    cout << Percent(TS,50);*/
    return 0;
}
