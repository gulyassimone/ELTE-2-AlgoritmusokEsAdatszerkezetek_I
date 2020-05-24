/* C++ program to construct tree using
inorder and preorder traversals */
#include <bits/stdc++.h>
#define COUNT 10

using namespace std;


/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
public:
    char data;
    node* left;
    node* right;
};

/* Prototypes for utility functions */
int search(char arr[], int strt, int end, char value);
node* newNode(char data);

/* Recursive function to construct binary
of size len from Inorder traversal in[]
and Preorder traversal pre[]. Initial values
of inStrt and inEnd should be 0 and len -1.
The function doesn't do any error checking
for cases where inorder and preorder do not
form a tree */
node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;

    /* Pick current node from Preorder
    traversal using preIndex
    and increment preIndex */
    node* tNode = newNode(pre[preIndex++]);

    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;

    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    /* Using index in Inorder traversal, construct left and
    right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
The function assumes that value is present in in[] */
int search(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(char data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

void print2DUtil(node *root, int space)
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
void print2D(node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
int nodeCount(node* t)
{
    int c=0;
    if(t)
    {
        c=nodeCount(t->left)+nodeCount(t->right)+1;
    }
    else
    {
        return 0;
    }
    return c;
}

int leafCount(node* t)
{
    int cb=0;
    int cj=0;
    if(t)
    {
        if(t->left==0 && t->right==0)
        {
            return 1;
        }
        else
        {
            cb=leafCount(t->left);
            cj=leafCount(t->right);
            return cb+cj;
        }
    }
    else
    {
        return 0;
    }
}
/* Driver code */
int main()
{
    char in[] = {'L', 'M', 'H', 'A', 'E', 'D', 'B', 'G', 'K', 'N', 'P', 'C', 'F', 'Q'};
    char pre[] = {'D','E', 'M', 'L', 'A', 'H', 'P', 'B', 'K', 'G', 'N', 'Q', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    node* root = buildTree(in, pre, 0, len - 1);

    /* Let us test the built tree by
    printing Insorder traversal */
    cout << "Write root";
    print2D(root);
    cout<< "node count: " <<nodeCount(root) << endl;
    cout<< "leaf count: " <<leafCount(root) << endl;
}

// This is code is contributed by rathbhupendra
