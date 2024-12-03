#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertAfterPosition(Node* head, int position, int data) {
    Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return head;
    }
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (position == 1) {
        return deleteFromBeginning(head);
    }
    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return head;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    return head;
}

int main() {
    Node* head = NULL;
    int n, data, position;

    printf("Enter the size of the linked list: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    printf("Initial Linked List:\n");
    display(head);

    printf("Insert at beginning. Enter data: ");
    scanf("%d", &data);
    head = insertAtBeginning(head, data);
    printf("After insertion at beginning:\n");
    display(head);

    printf("Insert at a position. Enter position and data: ");
    scanf("%d %d", &position, &data);
    head = insertAfterPosition(head, position, data);
    printf("After insertion at position %d:\n", position);
    display(head);

    printf("Insert at end. Enter data: ");
    scanf("%d", &data);
    head = insertAtEnd(head, data);
    printf("After insertion at end:\n");
    display(head);

    printf("Delete from beginning.\n");
    head = deleteFromBeginning(head);
    printf("After deletion from beginning:\n");
    display(head);

    printf("Delete at a position. Enter position: ");
    scanf("%d", &position);
    head = deleteAtPosition(head, position);
    printf("After deletion at position %d:\n", position);
    display(head);

    printf("Delete from end.\n");
    head = deleteFromEnd(head);
    printf("After deletion from end:\n");
    display(head);

    return 0;
}
