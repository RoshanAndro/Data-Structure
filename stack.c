#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int stack[SIZE];
int sp = -1;

void push(int);
int pop();
void display();

int main() {
    int opt, data;
    do {
        printf("\n1.Insert\n");
        printf("\n2.Delete\n");
        printf("\n3.Display\n");
        printf("\n4.Exit\n");
        printf("\nYour Option : ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("\nData: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                if (sp == -1) {
                    printf("\nEmpty stack\n");
                } else {
                    data = pop();
                    printf("\nPopped data [%d]\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    } while (1);
}

void push(int data) {
    if (sp == SIZE - 1)
        printf("\nFull stack\n");
    else
        stack[++sp] = data;
}

int pop() {
    return stack[sp--];
}

void display() {
    if (sp == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("\nStack content: ");
        for (int tsp = sp; tsp >= 0; tsp--) {
            printf("%d ", stack[tsp]);
        }
        printf("\n");
    }
}
