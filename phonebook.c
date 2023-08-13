#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

struct Contact phonebook[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        printf("Enter name: ");
        scanf("%s", phonebook[contactCount].name);

        printf("Enter phone number: ");
        scanf("%s", phonebook[contactCount].phone);

        printf("Contact added successfully!\n");
        contactCount++;
    } else {
        printf("Phonebook is full. Cannot add more contacts.\n");
    }
}

void searchContact() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone: %s\n", phonebook[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void displayContacts() {
    printf("Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    int choice;

    do {
        printf("\nPhonebook Application\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayContacts();
                break;
            case 4:
                printf("Exiting Phonebook Application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
