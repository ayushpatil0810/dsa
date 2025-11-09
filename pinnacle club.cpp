#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int prn;
    char name[50];
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(int prn, char name[]) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prn = prn;
    strcpy(temp->name, name);
    temp->next = NULL;
    return temp;
}
void addPresident(int prn, char name[]) {
    struct node *temp = createNode(prn, name);
    temp->next = head;
    head = temp;
    printf("? President added.\n");
}
void addSecretary(int prn, char name[]) {
    struct node *temp = createNode(prn, name);
    if (head == NULL) {
        head = temp;
        return;
    }
    struct node *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    printf("? Secretary added.\n");
}
void addMember(int prn, char name[]) {
    if (head == NULL) {
        printf("Add President first!\n");
        return;
    }
    struct node *temp = createNode(prn, name);
    struct node *p = head;
    while (p->next != NULL && p->next->next != NULL)
        p = p->next;
    temp->next = p->next;
    p->next = temp;
    printf("? Member added.\n");
}
void deletePresident() {
    if (head == NULL) {
        printf("List empty!\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("? President removed.\n");
}
void deleteSecretary() {
    if (head == NULL || head->next == NULL) {
        printf("List too small!\n");
        return;
    }
    struct node *p = head;
    while (p->next->next != NULL)
        p = p->next;
    free(p->next);
    p->next = NULL;
    printf("? Secretary removed.\n");
}
void display() {
    if (head == NULL) {
        printf("No members.\n");
        return;
    }
    struct node *p = head;
    printf("\n--- Club Members ---\n");
    while (p != NULL) {
        printf("PRN: %d | Name: %s\n", p->prn, p->name);
        p = p->next;
    }
}
void count() {
    int c = 0;
    struct node *p = head;
    while (p != NULL) {
        c++;
        p = p->next;
    }
    printf("Total Members (including President & Secretary): %d\n", c);
}
struct node* concatenate(struct node *head1, struct node *head2) {
    if (head1 == NULL) return head2;
    struct node *p = head1;
    while (p->next != NULL)
        p = p->next;
    p->next = head2;
    return head1;
}

int main() {
    int ch, prn;
    char name[50];
    struct node *head2 = NULL;

    do {
        printf("\n=== Pinnacle Club Management ===\n");
        printf("1. Add President\n2. Add Secretary\n3. Add Member\n4. Delete President\n");
        printf("5. Delete Secretary\n6. Display Members\n7. Count Members\n8. Concatenate Two Divisions\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter PRN & Name: ");
                scanf("%d %s", &prn, name);
                addPresident(prn, name);
                break;
            case 2:
                printf("Enter PRN & Name: ");
                scanf("%d %s", &prn, name);
                addSecretary(prn, name);
                break;
            case 3:
                printf("Enter PRN & Name: ");
                scanf("%d %s", &prn, name);
                addMember(prn, name);
                break;
            case 4:
                deletePresident();
                break;
            case 5:
                deleteSecretary();
                break;
            case 6:
                display();
                break;
            case 7:
                count();
                break;
            case 8:
                printf("\nEnter 1st division president (PRN & Name): ");
                scanf("%d %s", &prn, name);
                struct node *div1 = createNode(prn, name);
                div1->next = NULL;
                printf("Enter 2nd division president (PRN & Name): ");
                scanf("%d %s", &prn, name);
                head2 = createNode(prn, name);
                div1 = concatenate(div1, head2);
                printf("? Two divisions concatenated!\n");
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 9);

    return 0;
}

