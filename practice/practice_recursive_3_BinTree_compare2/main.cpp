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
bool compare(node* t1,node* t2)
{
    bool l=true;
    if(t1 && t2)
    {
        l = l && (compare(t1->left,t2->left) && compare(t1->right,t2->right));
        return  t1->data==t2->data;
    }
    else if((t1 && !t2) || (!t1 && t2))
    {
        return false;
    }

    return l;
}
/* Driver code */
int main()
{
    char in[] = {'L', 'M', 'H', 'A', 'E', 'D', 'B', 'G', 'K', 'N', 'P', 'C', 'F', 'Q'};
    char pre[] = {'D','E', 'M', 'L', 'A', 'H', 'P', 'B', 'K', 'G', 'N', 'Q', 'C', 'F'};
    char in1[] = {'L', 'M', 'H', 'A', 'E', 'D', 'B', 'G', 'K', 'N', 'P', 'C', 'F', 'Q'};
    char pre1[] = {'D','E', 'M', 'L', 'A', 'H', 'P', 'B', 'K', 'G', 'N', 'Q', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    int len1 = sizeof(in1) / sizeof(in1[0]);

    node* root = buildTree(in, pre, 0, len - 1);
    node* root2 = buildTree(in1, pre1, 0, len1 - 1);
    node* root3 = buildTree(in1, pre1, 0, len1 - 1);

    print2D(root);

    cout << "-----------------------------------------------------------------" <<endl;
    print2D(root2);
    cout << "-----------------------------------------------------------------" <<endl;
    print2D(root3);

    if(compare(root3,root))
    {
        cout<<"equal"<<endl;
    }
    else
    {
        cout<<"Not equal"<<endl;
    }
}

// This is code is contributed by rathbhupendra
