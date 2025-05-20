#include <stdio.h>
#include <stdlib.h>

typedef struct USER {
    int id;
    char name[50];
    char email[100];
} user;

int lastIndex = 0;

user *createArray(int);
void insertAtFirst(user *, user);
void insertAtLast(user *, user);
void insertAtSpecificPosition(user *, user, int);
user deleteAtFirst(user *);
user deleteAtLast(user *);
user deleteAtSpecificPosition(user *, int);
void updateUserById(user *, int);
void display(user *);

int main() {
    int size, choice, index;
    user temp;
    user *uarr = NULL;

    printf("Enter the number of users: ");
    scanf("%d", &size);
    
    uarr = createArray(size);
    
    do {
        printf("\n1) Insert At First\n");
        printf("2) Insert At Last\n");
        printf("3) Insert At Specific Position\n");
        printf("4) Delete At First\n");
        printf("5) Delete At Last\n");
        printf("6) Delete At Specific Position\n");
        printf("7) Update the value\n");
        printf("8) Display users\n");
        printf("9) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter user id, name, and email: ");
                scanf("%d %s %s", &temp.id, temp.name, temp.email);
                insertAtFirst(uarr, temp);
                break;
            case 2:
                printf("Enter user id, name, and email: ");
                scanf("%d %s %s", &temp.id, temp.name, temp.email);
                insertAtLast(uarr, temp);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &index);
                printf("Enter user id, name, and email: ");
                scanf("%d %s %s", &temp.id, temp.name, temp.email);
                insertAtSpecificPosition(uarr, temp, index);
                break;
            case 4:
                deleteAtFirst(uarr);
                break;
            case 5:
                deleteAtLast(uarr);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &index);
                deleteAtSpecificPosition(uarr, index);
                break;
            case 7:
                printf("Enter user ID to update: ");
                scanf("%d", &index);
                updateUserById(uarr, index);
                break;
            case 8:
                display(uarr);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 9);

    free(uarr);
    return 0;
}

user *createArray(int size) {
    return (user *)malloc(sizeof(user) * size);
}

void insertAtFirst(user *uarr, user newUser) {
    for (int i = lastIndex; i > 0; i--) {
        uarr[i] = uarr[i - 1];
    }
    uarr[0] = newUser;
    lastIndex++;
}

void insertAtLast(user *uarr, user newUser) {
    uarr[lastIndex] = newUser;
    lastIndex++;
}

void insertAtSpecificPosition(user *uarr, user newUser, int pos) {
    if (pos < 0 || pos > lastIndex) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = lastIndex; i > pos; i--) {
        uarr[i] = uarr[i - 1];
    }
    uarr[pos] = newUser;
    lastIndex++;
}

user deleteAtFirst(user *uarr) {
    user deletedUser = uarr[0];
    for (int i = 0; i < lastIndex - 1; i++) {
        uarr[i] = uarr[i + 1];
    }
    lastIndex--;
    return deletedUser;
}

user deleteAtLast(user *uarr) {
    return uarr[--lastIndex];
}

user deleteAtSpecificPosition(user *uarr, int pos) {
    if (pos < 0 || pos >= lastIndex) {
        printf("Invalid position!\n");
        user empty = {-1, "", ""};
        return empty;
    }
    user deletedUser = uarr[pos];
    for (int i = pos; i < lastIndex - 1; i++) {
        uarr[i] = uarr[i + 1];
    }
    lastIndex--;
    return deletedUser;
}

void updateUserById(user *uarr, int id) {
    for (int i = 0; i < lastIndex; i++) {
        if (uarr[i].id == id) {
            printf("Enter new name and email: ");
            scanf("%s %s", uarr[i].name, uarr[i].email);
            return;
        }
    }
    printf("User not found!\n");
}

void display(user *uarr) {
    for (int i = 0; i < lastIndex; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", uarr[i].id, uarr[i].name, uarr[i].email);
    }
}
