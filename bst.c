#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left, *right;
};

// Function prototypes
struct node* insert(struct node* root, int data);
struct node* search(struct node* root, int data);
struct node* delete(struct node* root, int data);
void display(struct node* root);

void main() {
    struct node* root = (struct node*)0;  // an empty BST
    int opt, data;

    do {
        printf("\n--Binary Search Tree Operation ---\n");
        printf("\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n");
        printf("--------------------------------\n");
        printf("Your Option : ");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            printf("\nEnter the data : ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            if (root == (struct node*)0) {
                printf("\nThe tree is empty.\n");
            } else {
                printf("\nEnter data to Search : ");
                scanf("%d", &data);
                struct node* result = search(root, data);
                if (result != (struct node*)0)
                    printf("\n [%d] Found\n", data);
                else
                    printf("\n [%d] Not Found\n", data);
            }
            break;
        case 3:
             if (root == (struct node*)0) {
                printf("\nThe tree is empty.\n");
            } else {
                printf("\nEnter data to Delete : ");
                scanf("%d", &data);
                root = delete(root, data);
            }
            break;
        case 4:
             if (root == (struct node*)0) {
                printf("\nThe tree is empty.\n");
            } else {
                printf("\nTree Traversal (inorder): ");
                display(root);
                printf("\n");
            }
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid option. Please choose again.\n");
        }
    } while (1);

    return ;
}

// Function to insert a new node
struct node* insert(struct node* root, int data) {
    struct node* t = (struct node*)malloc(sizeof(struct node)); //memory allocate and taken for  data(integers) for storing address of that node
    struct node* t1 = root;
    t->data = data;
    t->left = t->right = (struct node*)0;

    if (root == (struct node*)0) {
        root = t; // Case 1: Tree is empty, set root to the new node. 
    } else {
        while (t1 != (struct node*)0 && t1->data != data) {
            if (data < t1->data) {
                if (t1->left == (struct node*)0) {
                    t1->left = t;//insert left leaf node
                    break;
                }
                t1 = t1->left;  // Move to the left subtree to continue searching.
            } else {
                if (t1->right == (struct node*)0) {
                    t1->right = t;//Insert new node as the right child of the current node.
                    break;
                }
                t1 = t1->right;  // Move to the right subtree to continue searching.
            }
      	  }

        if (t1 != (struct node*)0 && t1->data == data) {
            printf("\nDuplicate Elements not Allowed\n");//Case 2: Handle duplicate values.
            free(t);
        }
    }
    return root;
}

// Function to Search
struct node* search(struct node* root, int data) {
    while (root != (struct node*)0 && root->data != data) {
        if (data < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// Function to delete a node in the BST
struct node* delete(struct node* root, int data) {
    struct node* t1 = root, * t2 = (struct node*)0;

    // Find the node to delete
    while (t1 != (struct node*)0 && t1->data != data) {
        t2 = t1;
        if (data < t1->data)
            t1 = t1->left;
        else
            t1 = t1->right;
    }

    if (t1 == (struct node*)0) {
        printf("\n Not Found\n");
        return root;
    }

    if (t1->left == (struct node*)0 && t1->right == (struct node*)0) {  // Case 1: Node has no children
        if (t2 == (struct node*)0)
            root = (struct node*)0;
        else {
            if (t2->left == t1)
                t2->left = (struct node*)0;
            else
                t2->right = (struct node*)0;
        }
        free(t1);
    } else if (t1->left == (struct node*)0 || t1->right == (struct node*)0) {  // Case 2: Node has one child
        struct node* child = (t1->left != (struct node*)0) ? t1->left : t1->right;
        if (t2 == (struct node*)0)
            root = child;
        else if (t2->left == t1)
            t2->left = child;
        else
            t2->right = child;
        free(t1);
    } 
    
    else {  // Case 3: Node has two children
        struct node* successorpnt = t1;
        struct node* t2 = t1->right;
        while (t2->left != (struct node*)0) {
           successorpnt = t2;
            t2 = t2->left;
        }

        // Copy the inorder successor's content to this node
        t1->data = t2->data;

        // Delete the inorder successor
        if (successorpnt->left == t2)
            successorpnt->left = t2->right;
        else
            successorpnt->right = t2->right;

        free(t2);
    }

    return root;
}

// Function to display the BST in inorder (sorted order)
void display(struct node* root) {
    if (root != (struct node*)0) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

