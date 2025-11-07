//Write a program to perform all operation using singly linked list
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create linked list
void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    head = NULL;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  // first node
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to display list
void displayList() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a new node
void insertNode(int data, int position)
{
    struct Node *newNode, *temp;
    int i;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // Insert at beginning
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;
    for (i = 1; i < position-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Invalid position!\n");
        free(newNode);
    }
}

// Function to search an element
void searchElement(int key) {
    struct Node* temp = head;
    int pos = 1, found = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        printf("Element %d not found in the list.\n", key);
}

// Function to sort list in ascending order
void sortList() {
    struct Node *i, *j;
    int temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}

// Function to update an element
void updateElement(int oldValue, int newValue) {
    struct Node* temp = head;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            found = 1;
            printf("Updated %d to %d.\n", oldValue, newValue);
            break;
        }
        temp = temp->next;
    }

    if (!found)
        printf("Element %d not found for update.\n", oldValue);
}

// Function to count nodes
void countNodes() {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total number of nodes: %d\n", count);
}

// Main function
int main() {
    int n, choice, data, pos, oldVal, newVal;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert Node\n");
        printf("4. Search Element\n");
        printf("5. Sort List\n");
        printf("6. Update Element\n");
        printf("7. Count Nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                displayList();
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertNode(data, pos);
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &data);
                searchElement(data);
                break;

            case 5:
                sortList();
                break;

            case 6:
                printf("Enter element to update: ");
                scanf("%d", &oldVal);
                printf("Enter new value: ");
                scanf("%d", &newVal);
                updateElement(oldVal, newVal);
                break;

            case 7:
                countNodes();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
