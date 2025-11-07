// Doubly linked list perform (insert,delete,display) operations
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void create(int value)
{
    if (head != NULL)
    {
        printf("List already created!\n");
        return;
    }
    head = createNode(value);
    printf("List created with value %%d.\n", value);
}

void display()
{
    struct Node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertFirst(int value)
{
    struct Node *newNode;
    newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at beginning.\n", value);
}

void insertLast(int value)
{
    struct Node *newNode;
    struct Node *temp;
    newNode = createNode(value);
    temp = head;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at end.\n", value);
}

void insertAfter(int key, int value)
{
    struct Node *temp;
    struct Node *newNode;
    temp = head;
    newNode = createNode(value);
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Key %%d not found!\n", key);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("%%d inserted after %%d.\n", value, key);
}

void insertBefore(int key, int value)
{
    struct Node *temp;
    struct Node *newNode;
    temp = head;
    newNode = createNode(value);
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Key %%d not found!\n", key);
        return;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev == NULL) // Insertion before head
    {
        head = newNode;
    }
    else
    {
        temp->prev->next = newNode;
    }
    temp->prev = newNode;
    printf("%%d inserted before %%d.\n", value, key);
}

void deleteFirst()
{
    struct Node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    printf("First node %%d deleted.\n", temp->data);
    free(temp);
}

void deleteLast()
{
    struct Node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if (temp->next == NULL) // Only one node
    {
        printf("Last node %%d deleted.\n", temp->data);
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Last node %%d deleted.\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

void deleteDesired(int key)
{
    struct Node *temp;
    temp = head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Key %%d not found!\n", key);
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next; // Deleted node is the head
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    printf("Node %%d deleted.\n", temp->data);
    free(temp);
}

void deleteAfter(int key)
{
    struct Node *temp;
    struct Node *delNode;
    temp = head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("No node exists after %%d.\n", key);
        return;
    }

    delNode = temp->next;
    temp->next = delNode->next;
    if (delNode->next != NULL)
    {
        delNode->next->prev = temp;
    }
    printf("Node %%d deleted after %%d.\n", delNode->data, key);
    free(delNode);
}

void deleteBefore(int key)
{
    struct Node *temp;
    struct Node *delNode;
    temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->prev == NULL)
    {
        printf("No node exists before %%d.\n", key);
        return;
    }

    delNode = temp->prev;
    if (delNode->prev != NULL)
    {
        delNode->prev->next = temp;
        temp->prev = delNode->prev;
    }
    else // The node to be deleted is the head
    {
        head = temp;
        temp->prev = NULL;
    }
    printf("Node %%d deleted before %%d.\n", delNode->data, key);
    free(delNode);
}

int main()
{
    int choice, value, key;

    while (1)
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert First\n");
        printf("4. Insert Last\n");
        printf("5. Insert After\n");
        printf("6. Insert Before\n");
        printf("7. Delete First\n");
        printf("8. Delete Last\n");
        printf("9. Delete Desired\n");
        printf("10. Delete After\n");
        printf("11. Delete Before\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to create list: ");
            scanf("%d", &value);
            create(value);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter value to insert at first: ");
            scanf("%d", &value);
            insertFirst(value);
            break;
        case 4:
            printf("Enter value to insert at last: ");
            scanf("%d", &value);
            insertLast(value);
            break;
        case 5:
            printf("Enter key after which to insert: ");
            scanf("%d", &key);
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAfter(key, value);
            break;
        case 6:
            printf("Enter key before which to insert: ");
            scanf("%d", &key);
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertBefore(key, value);
            break;
        case 7:
            deleteFirst();
            break;
        case 8:
            deleteLast();
            break;
        case 9:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteDesired(key);
            break;
        case 10:
            printf("Enter key after which node should be deleted: ");
            scanf("%d", &key);
            deleteAfter(key);
            break;
        case 11:
            printf("Enter key before which node should be deleted: ");
            scanf("%d", &key);
            deleteBefore(key);
            break;
        case 12:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
