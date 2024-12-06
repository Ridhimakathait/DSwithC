#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int findSecondHighest(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return -1; // No second highest if tree is empty or has one node
    }

    Node* current = root;
    while (current->right != NULL) {
        if (current->right->right == NULL && current->right->left == NULL) {
            return current->data;
        }
        current = current->right;
    }
    return -1; // In case there is no second highest
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int countCommonParent(Node* root) {
    if (root == NULL) return 0;
    return (root->left != NULL && root->right != NULL) + countCommonParent(root->left) + countCommonParent(root->right);
}

int height(Node* node) {
    if (node == NULL) {
        return -1; // Height of an empty tree is -1
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countLeftNodes(Node* root) {
    if (root == NULL) return 0;
    return countLeftNodes(root->left) + (root->left != NULL ? 1 : 0);
}

void menu() {
    printf("1. Insert Node\n");
    printf("2. Find Second Highest Node\n");
    printf("3. Delete Node\n");
    printf("4. Count Total Nodes with Common Parent\n");
    printf("5. Find Height of the Tree\n");
    printf("6. Count Nodes on Left Side of Root\n");
    printf("7. Exit\n");
}

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                data = findSecondHighest(root);
                if (data != -1) {
                    printf("Second highest node: %d\n", data);
                } else {
                    printf("No second highest node found.\n");
                }
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 4:
                printf("Total nodes with common parent: %d\n", countCommonParent(root));
                break;
            case 5:
                printf("Height of the tree: %d\n", height(root));
                break;
            case 6:
                printf("Total nodes on left side of root: %d\n", countLeftNodes(root));
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;

}