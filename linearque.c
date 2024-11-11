#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int que[SIZE];
int front = -1, rear = -1;

void insertque(int);
int deleteque();
int searchque(int);

int main() {
    int opt, data;
    do {
        printf("\n 1.Insert \n");
        printf("\n 2.Delete \n");
        printf("\n 3.Search \n");
        printf("\n 4.Exit \n");
        printf("\n Enter your option : ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("\n Enter Data : ");
                scanf("%d", &data);
                insertque(data);
                break;
            case 2:
                if (front == -1) {
                    printf("\n Queue is empty\n");
                } else {
                    data = deleteque();
                    printf("\n[%d] deleted \n", data);
                }
                break;
            case 3:
                if (front == -1) {
                    printf("\n Queue is empty\n");
                } else {
                    printf("\nData to search: ");
                    scanf("%d", &data);
                    if (searchque(data))
                        printf("\nFound\n");
                    else
                        printf("\nNot Found\n");
                }
                break;
            case 4:
                exit(0);
        }
    } while (1);
}

void insertque(int item) {
    if (rear == SIZE - 1)
        printf("\n Queue is full \n");
    else if (front == -1) {
        front = rear = 0;
        que[rear] = item;
    } else {
        que[++rear] = item;
    }
}

int deleteque() {
    int item;
    if (front == -1) {
        printf("\n Queue is empty\n");
        exit(1);
    } else if (front == rear) {
        item = que[front];
        front = rear = -1;
        return item;
    } else {
        return que[front++];
    }
}

int searchque(int item) {
    for (int i = front; i <= rear; i++) {
        if (que[i] == item) {
            return 1; 
        }
    }
    return 0; 
}
