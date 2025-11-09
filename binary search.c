#include <stdio.h>
#define MAX 50

int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key)
            return i;  // found
    }
    return -1; // not found
}
int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// --- Sort Array (for Binary Search) ---
void sortArray(int a[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
int main() {
    int a[MAX], n, key, ch, pos;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter roll numbers:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do {
        printf("\n=== Menu ===\n");
        printf("1. Linear Search (Random Order)\n");
        printf("2. Binary Search (Sorted Order)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter roll number to search: ");
                scanf("%d", &key);
                pos = linearSearch(a, n, key);
                if (pos == -1)
                    printf("Roll number not found.\n");
                else
                    printf("Roll number found at position %d.\n", pos + 1);
                break;

            case 2:
                sortArray(a, n);
                printf("Sorted Roll Numbers: ");
                for (int i = 0; i < n; i++)
                    printf("%d ", a[i]);
                printf("\nEnter roll number to search: ");
                scanf("%d", &key);
                pos = binarySearch(a, n, key);
                if (pos == -1)
                    printf("Roll number not found.\n");
                else
                    printf("Roll number found at position %d.\n", pos + 1);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (ch != 3);

    return 0;
}
