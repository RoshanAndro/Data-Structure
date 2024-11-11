#include<stdio.h>

void readarray(int[], int);
void printarray(int[], int);
void sortarray(int[], int);
void mergearray(int[], int, int[], int, int[]);

int main() {
    int ar1[20], ar2[20], ar3[40];
    int n1, n2;

    printf("Number of Elements in first array [1-20]: ");
    scanf("%d", &n1);
    printf("Enter %d Elements: ", n1);
    readarray(ar1, n1);

    printf("Number of Elements in Second array [1-20]: ");
    scanf("%d", &n2);
    printf("Enter %d Elements: ", n2);
    readarray(ar2, n2);

    sortarray(ar1, n1);
    sortarray(ar2, n2);  

    mergearray(ar1, n1, ar2, n2, ar3);

    printf("First array sorted: ");
    printarray(ar1, n1);

    printf("Second array sorted: ");
    printarray(ar2, n2);

    printf("Merged array: ");
    printarray(ar3, n1 + n2);

    return 0;
}

void readarray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void printarray(int a[], int n) {
    int i;
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void sortarray(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

void mergearray(int a[], int n1, int b[], int n2, int c[]) {
    int i, j, k;
    i = j = k = 0;
    while (i < n1 && j < n2)
        if (a[i] < b[j]) {
            c[k] = a[i];
            k++;
            i++;
        } else {
            c[k] = b[j];
            k++;
            j++;
        }
    while (i < n1)
        c[k++] = a[i++];
    while (j < n2)
        c[k++] = b[j++];
}
