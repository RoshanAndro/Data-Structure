#include <stdio.h>
#include <stdlib.h>

int uset[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
#define SIZE 10

struct bit {
    unsigned char x : 1; // 1-bit flag for each element
};

// Function Prototypes
void readset(struct bit s[], int n);
void printset(struct bit s[]);
void set_union(struct bit a[], struct bit b[], struct bit c[]);
void set_intersection(struct bit a[], struct bit b[], struct bit c[]);
void set_difference(struct bit a[], struct bit b[], struct bit c[]);

int main() {
    struct bit a[SIZE] = {0}, b[SIZE] = {0}, c[SIZE] = {0};
    int n;

    // Input for set A
    printf("No: of Elements for set A: ");
    scanf("%d", &n);
    readset(a, n);

    // Input for set B
    printf("No: of Elements for set B: ");
    scanf("%d", &n);
    readset(b, n);

    // Display sets
    printf("Set A: ");
    printset(a);
    printf("Set B: ");
    printset(b);

    // Set Union
    set_union(a, b, c);
    printf("Set Union: ");
    printset(c);

    // Set Intersection
    set_intersection(a, b, c);
    printf("Set Intersection: ");
    printset(c);

    // Set Difference (A - B)
    set_difference(a, b, c);
    printf("Set Difference (A - B): ");
    printset(c);

    return 0;
}

void printset(struct bit s[]) {
    int k;
    printf("{");
    for(k = 0; k < SIZE; k++) {
        if(s[k].x == 1) {
            printf("%d", uset[k]);
            if (k < SIZE - 1 && s[k + 1].x == 1) {
                printf(", "); // Proper comma separation
            }
        }
    }
    printf("}\n");
}

void readset(struct bit s[], int n) {
    int i, x, k;
    printf("Enter %d Element(s): ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        for (k = 0; k < SIZE; k++) {
            if(uset[k] == x) {
                s[k].x = 1; // Mark the corresponding element as part of the set
                break;
            }
        }
    }
}

void set_union(struct bit a[], struct bit b[], struct bit c[]) {
    int i;
    for(i = 0; i < SIZE; i++) {
        c[i].x = a[i].x | b[i].x; // Union: OR operation
    }
}

void set_intersection(struct bit a[], struct bit b[], struct bit c[]) {
    int i;
    for(i = 0; i < SIZE; i++) {
        c[i].x = a[i].x & b[i].x; // Intersection: AND operation
    }
}

void set_difference(struct bit a[], struct bit b[], struct bit c[]) {
    int i;
    for(i = 0; i < SIZE; i++) {
        c[i].x = a[i].x & ~b[i].x; // Difference (A - B): AND NOT operation
    }
}

