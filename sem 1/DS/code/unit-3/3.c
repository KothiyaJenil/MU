#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void display() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insertFirst(int value) {
    struct Node *newNode, *temp;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insertLast(int value) {
    struct Node *newNode, *temp;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAtPos(int value, int pos) {
    int i;
    struct Node *newNode, *temp;

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertFirst(value);
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    temp = head;

    for (i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (i != pos - 1 && temp->next == head) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBefore(int value, int key) {
    struct Node *newNode, *temp, *prev = NULL;

    if (head == NULL) return;

    if (head->data == key) {
        insertFirst(value);
        return;
    }

    temp = head;
    prev = NULL;

    do {
        prev = temp;
        temp = temp->next;
        if (temp == head) break;
    } while (temp->data != key);

    if (temp->data == key) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = temp;
        prev->next = newNode;
    } else {
        printf("Key %d not found\n", key);
    }
}

void insertAfter(int value, int key) {
    struct Node *newNode, *temp;

    if (head == NULL) return;

    temp = head;

    do {
        if (temp->data == key) {
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Key %d not found\n", key);
}

void deleteFirst() {
    struct Node *temp, *last;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    temp = head;
    last = head;

    while (last->next != head)
        last = last->next;

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        head = head->next;
        last->next = head;
        free(temp);
    }
}

void deleteLast() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    temp = head;
    prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        free(head);
        head = NULL;
    } else {
        prev->next = head;
        free(temp);
    }
}

void deleteKey(int key) {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    if (head->data == key) {
        deleteFirst();
        return;
    }

    temp = head;
    prev = NULL;

    do {
        prev = temp;
        temp = temp->next;
        if (temp == head) break;
    } while (temp->data != key);

    if (temp != head && temp->data == key) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Key %d not found\n", key);
    }
}

void main() {
    int choice, val, pos, key;

    while (1) {
        printf("\n--- Circular Singly Linked List ---\n");
        printf("1. Insert First\n2. Insert Last\n3. Insert at Position\n");
        printf("4. Insert Before Element\n5. Insert After Element\n");
        printf("6. Delete First\n7. Delete Last\n8. Delete By Key\n");
        printf("9. Display\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFirst(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertLast(val);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d%d", &val, &pos);
                insertAtPos(val, pos);
                break;
            case 4:
                printf("Enter value and key: ");
                scanf("%d%d", &val, &key);
                insertBefore(val, key);
                break;
            case 5:
                printf("Enter value and key: ");
                scanf("%d%d", &val, &key);
                insertAfter(val, key);
                break;
            case 6:
                deleteFirst();
                break;
            case 7:
                deleteLast();
                break;
            case 8:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 9:
                display();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
