#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char description[100];
    struct Task* next;
} Task;

void displayTasks(Task* head);
Task* insertTask(Task* head, char* description);
Task* deleteTask(Task* head, char* description);

int main() {
    Task* head = NULL;
    int choice;
    char description[100];

    // Inserting some initial tasks
    head = insertTask(head, "Complete homework");
    head = insertTask(head, "Go for a walk");
    head = insertTask(head, "Read a book");

    while (1) {
        printf("\nTo-Do List\n");
        printf("1. Display Tasks\n");
        printf("2. Insert Task\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                displayTasks(head);
                break;
            case 2:
                printf("Enter task description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove the newline character from the input
                head = insertTask(head, description);
                break;
            case 3:
                printf("Enter task description to delete: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove the newline character from the input
                head = deleteTask(head, description);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayTasks(Task* head) {
    if (head == NULL) {
        printf("No tasks to display.\n");
        return;
    }

    printf("Tasks:\n");
    while (head != NULL) {
        printf("- %s\n", head->description);
        head = head->next;
    }
}

Task* insertTask(Task* head, char* description) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->description, description);
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTask;
    }

    return head;
}

Task* deleteTask(Task* head, char* description) {
    if (head == NULL) {
        printf("No tasks to delete.\n");
        return head;
    }

    if (strcmp(head->description, description) == 0) {
        Task* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Task* current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->description, description) == 0) {
            Task* temp = current->next;
            current->next = temp->next;
            free(temp);
            return head;
        }

        current = current->next;
    }
    printf("Task not found.\n");
    return head;
}