// C++ program to demonstrate searching operation
// in binary search tree without recursion
#include <bits/stdc++.h>
#define COUNT 10

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};


// A utility function to create a new BST Node
struct Node* newNode(int item)
{
    struct Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new Node with
   given key in BST */
struct Node* insert(struct Node* Node, int data)
{
    /* If the tree is empty, return a new Node */
    if (Node == NULL)
        return newNode(data);

    /* Otherwise, recur down the tree */
    if (data < Node->data)
        Node->left = insert(Node->left, data);
    else if (data > Node->data)
        Node->right = insert(Node->right, data);

    /* return the (unchanged) Node pointer */
    return Node;
}
// Function to traverse the tree in preorder
// and check if the given node exists in it
int searchIntervall(struct Node* t, int a, int b)
{
    int c=0;

    if (t)
    {
        if(t->data<=b && t->data>=a)
        {
            c=searchIntervall(t->right,a,b)+searchIntervall(t->left,a,b)+1;
        }
        if(t->data>b)
        {
            searchIntervall(t->left, a, b);
        }
        if(t->data<a)
        {
            searchIntervall(t->right, a, b);
        }
    }

    return c;
}
void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
// Driver Program to test above functions
int main()
{

    vector<int> b= {75,  43,  22,  63,  10,  37,  68,  85,  88,  49,  40,  56,  39,  52,  15,  38};
    struct Node* root = NULL;
    root = insert(root, 75);
    for(int i = 1; i<b.size(); i++)
    {
        insert(root, b[i]);
    }
    cout << "Write root";
    print2D(root);
}
