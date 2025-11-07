// Write a program to perform operations(Insert, Delete, Search, Update, count, sort, display) using circular doubly linked list
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Global head pointer, initially NULL
struct Node *head = NULL;

// Function prototypes
void createList(int n);
void display();
void insertFirst(int data);
void insertLast(int data);
void insertAfter(int val, int data);
void insertBefore(int val, int data);
void deleteFirst();
void deleteLast();
void deleteDesired(int val);
void search(int val);
void sortList();
void update(int oldVal, int newVal);
void countNodes();

// Main function with menu-driven interface
int main() {
    int choice, n, data, val, oldVal, newVal;
    while (1) {
        printf("\n\n*** Circular Doubly Linked List Menu ***\n");
        printf("1. Create\n2. Display\n3. Insert First\n4. Insert Last\n");
        printf("5. Insert After\n6. Insert Before\n7. Delete First\n8. Delete Last\n");
        printf("9. Delete Desired\n10. Search\n11. Sort Ascending\n12. Update\n13. Count Nodes\n14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFirst(data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                insertLast(data);
                break;
            case 5:
                printf("Enter node value after which to insert: ");
                scanf("%d", &val);
                printf("Enter data: ");
                scanf("%d", &data);
                insertAfter(val, data);
                break;
            case 6:
                printf("Enter node value before which to insert: ");
                scanf("%d", &val);
                printf("Enter data: ");
                scanf("%d", &data);
                insertBefore(val, data);
                break;
            case 7:
                deleteFirst();
                break;
            case 8:
                deleteLast();
                break;
            case 9:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteDesired(val);
                break;
            case 10:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 11:
                sortList();
                break;
            case 12:
                printf("Enter old value to update: ");
                scanf("%d", &oldVal);
                printf("Enter new value: ");
                scanf("%d", &newVal);
                update(oldVal, newVal);
                break;
            case 13:
                countNodes();
                break;
            case 14:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to create the initial list
void createList(int n) {
    int i, data;
    struct Node *newNode, *temp;
    if (n <= 0) {
        printf("Invalid number of nodes!\n");
        return;
    }

    head = NULL;
    for (i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            temp = head->prev;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
    }
    printf("List created successfully.\n");
}

// Function to display the list
void display() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to insert a node at the beginning
void insertFirst(int data) {
    struct Node *newNode, *last;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node inserted at beginning.\n");
}

// Function to insert a node at the end
void insertLast(int data) {
    struct Node *newNode, *last;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
    printf("Node inserted at end.\n");
}

// Function to insert a node after a specific value
void insertAfter(int val, int data) {
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        printf("List empty.\n");
        free(newNode);
        return;
    }
    temp = head;
    do {
        if (temp->data == val) {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            printf("Node inserted after %d.\n", val);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Value not found.\n");
}

// Function to insert a node before a specific value
void insertBefore(int val, int data) {
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        printf("List empty.\n");
        free(newNode);
        return;
    }
    temp = head;
    do {
        if (temp->data == val) {
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            if (temp == head) {
                head = newNode;
            }
            printf("Node inserted before %d.\n", val);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Value not found.\n");
}

// Function to delete the first node
void deleteFirst() {
    struct Node *temp, *last;
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        last = head->prev;
        temp = head;
        head = head->next;
        head->prev = last;
        last->next = head;
        free(temp);
    }
    printf("First node deleted.\n");
}

// Function to delete the last node
void deleteLast() {
    struct Node *last;
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        last = head->prev;
        last->prev->next = head;
        head->prev = last->prev;
        free(last);
    }
    printf("Last node deleted.\n");
}

// Function to delete a node with a specific value
void deleteDesired(int val) {
    struct Node *temp;
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    temp = head;
    do {
        if (temp->data == val) {
            if (temp->next == temp) { // Only one node in the list
                head = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head) { // Deleting the head node
                    head = temp->next;
                }
            }
            free(temp);
            printf("Node with value %d deleted.\n", val);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Value not found.\n");
}

// Function to search for a value in the list
void search(int val) {
    struct Node *temp;
    int pos = 1;
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    temp = head;
    do {
        if (temp->data == val) {
            printf("Value %d found at position %d.\n", val, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Value not found.\n");
}

// Function to sort the list in ascending order (Bubble Sort)
void sortList() {
    struct Node *i, *j;
    int temp;
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    for (i = head; i->next != head; i = i->next) {
        for (j = i->next; j != head; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}

// Function to update a node's value
void update(int oldVal, int newVal) {
    struct Node *temp;
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    temp = head;
    do {
        if (temp->data == oldVal) {
            temp->data = newVal;
            printf("Value %d updated to %d.\n", oldVal, newVal);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Value not found.\n");
}

// Function to count the number of nodes
void countNodes() {
    struct Node *temp;
    int count = 0;
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    printf("Total number of nodes: %d\n", count);
}
