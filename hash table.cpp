#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

struct Client {
    char name[30];
    long long phone;
    int occupied; // 0 = empty, 1 = filled
};

struct Client directory[TABLE_SIZE];

// Hash functions
int hash1(long long key) {
    return key % TABLE_SIZE;
}

int hash2(long long key) {
    return 7 - (key % 7);
}

// Insert using Linear Probing
void insertLinear(long long phone, char name[]) {
    int index = hash1(phone);
    int i = 0;

    while (directory[(index + i) % TABLE_SIZE].occupied && i < TABLE_SIZE) {
        i++;
    }

    if (i < TABLE_SIZE) {
        index = (index + i) % TABLE_SIZE;
        strcpy(directory[index].name, name);
        directory[index].phone = phone;
        directory[index].occupied = 1;
    } else {
        printf("Table is full! Cannot insert %s\n", name);
    }
}

// Insert using Quadratic Probing
void insertQuadratic(long long phone, char name[]) {
    int index = hash1(phone);
    int i = 0;

    while (directory[(index + i * i) % TABLE_SIZE].occupied && i < TABLE_SIZE) {
        i++;
    }

    if (i < TABLE_SIZE) {
        index = (index + i * i) % TABLE_SIZE;
        strcpy(directory[index].name, name);
        directory[index].phone = phone;
        directory[index].occupied = 1;
    } else {
        printf("Table is full! Cannot insert %s\n", name);
    }
}

// Insert using Double Hashing
void insertDoubleHash(long long phone, char name[]) {
    int index = hash1(phone);
    int step = hash2(phone);
    int i = 0;

    while (directory[(index + i * step) % TABLE_SIZE].occupied && i < TABLE_SIZE) {
        i++;
    }

    if (i < TABLE_SIZE) {
        index = (index + i * step) % TABLE_SIZE;
        strcpy(directory[index].name, name);
        directory[index].phone = phone;
        directory[index].occupied = 1;
    } else {
        printf("Table is full! Cannot insert %s\n", name);
    }
}

// Search
void search(long long phone) {
    int index = hash1(phone);
    int found = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (directory[i].occupied && directory[i].phone == phone) {
            printf("Found: %s -> %lld\n", directory[i].name, directory[i].phone);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Phone number not found.\n");
}

// Display
void display() {
    printf("\nHash Table (Telephone Directory):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (directory[i].occupied)
            printf("[%d] %s -> %lld\n", i, directory[i].name, directory[i].phone);
        else
            printf("[%d] ---\n", i);
    }
}

int main() {
    int choice;
    long long phone;
    char name[30];

    for (int i = 0; i < TABLE_SIZE; i++)
        directory[i].occupied = 0;

    printf("\n1. Insert (Linear Probing)\n2. Insert (Quadratic Probing)\n3. Insert (Double Hashing)\n4. Search\n5. Display\n6. Exit\n");

    do {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Name and Phone: ");
            scanf("%s %lld", name, &phone);
            insertLinear(phone, name);
            break;
        case 2:
            printf("Enter Name and Phone: ");
            scanf("%s %lld", name, &phone);
            insertQuadratic(phone, name);
            break;
        case 3:
            printf("Enter Name and Phone: ");
            scanf("%s %lld", name, &phone);
            insertDoubleHash(phone, name);
            break;
        case 4:
            printf("Enter Phone to Search: ");
            scanf("%lld", &phone);
            search(phone);
            break;
        case 5:
            display();
            break;
        }
    } while (choice != 6);

    return 0;
}
