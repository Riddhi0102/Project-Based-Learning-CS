#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a structure to store book details
struct library {
    char book_name[100];
    char author_name[100];
    float cost;
    int no_of_pages;
};

int main() {
    struct library lib[100];
    int i = 0, j = 0, count = 0;

    while (1) {
        printf("\n\n1. Add Book Details\n");
        printf("2. Display the List of Books and Their Details\n");
        printf("3. Display the Total Number of Books in the Library\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &j);

        switch (j) {
            case 1:
                // Add book details
                printf("\nYou can add the details of a new book.");
                printf("\nEnter the book name: ");
                scanf(" %[^\n]", lib[i].book_name); // To include spaces in the book name
                printf("Enter the author name: ");
                scanf(" %[^\n]", lib[i].author_name); // To include spaces in the author name
                printf("Enter the number of pages: ");
                scanf("%d", &lib[i].no_of_pages);
                printf("Enter the cost of the book: ");
                scanf("%f", &lib[i].cost);
                i++;
                count++;
                printf("\nBook added successfully!\n");
                break;

            case 2:
                // Display the list of books
                if (count == 0) {
                    printf("\nThere are no books stored in the library.\n");
                } else {
                    printf("\nList of books in the library:\n");
                    for (int k = 0; k < count; k++) {
                        printf("\nBook %d:\n", k + 1);
                        printf("Name: %s\n", lib[k].book_name);
                        printf("Author: %s\n", lib[k].author_name);
                        printf("Number of pages: %d\n", lib[k].no_of_pages);
                        printf("Cost: %.2f\n", lib[k].cost);
                    }
                }
                break;

            case 3:
                // Display total number of books
                printf("\nTotal number of books in the library: %d\n", count);
                break;

            case 4:
                // Exit the program
                printf("\nExiting the program. Goodbye!\n");
                exit(0);

            default:
                // Handle invalid input
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}