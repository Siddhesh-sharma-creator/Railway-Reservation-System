#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ========================================
// Ayush Ambetkar: QUEUE OPERATIONS (FULL/EMPTY)
// ========================================
#define MAX 5
#define MAX_TICKETS 2

struct Passenger {
    int id;
    char name[50];
    int age;
    int trainNo;
    int seatNo;
};

struct Passenger queue[MAX];
int front = -1, rear = -1;
int seatCounter = 1;

// ========================================
// Siddhesh Sharma: TICKET LIMIT LOGIC
// ========================================
int countTickets(int id) {
    if (front == -1) return 0;

    int count = 0, i = front;

    while (1) {
        if (queue[i].id == id)
            count++;

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
    return count;
}

int isFull() {
    return (front == (rear + 1) % MAX);
}

int isEmpty() {
    return (front == -1);
}

// ========================================
// Siddhesh Sharma: BOOKING + PRIORITY LOGIC
// ========================================
void bookTicket() {
    if (isFull()) {
        printf("\nQueue Full! No reservations possible.\n");
        return;
    }

    struct Passenger p;

    printf("\nEnter Passenger ID: ");
    scanf("%d", &p.id);

    if (countTickets(p.id) >= MAX_TICKETS) {
        printf("Ticket limit reached for this passenger!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter Train Number: ");
    scanf("%d", &p.trainNo);

    p.seatNo = seatCounter++;

    if (isEmpty()) {
        front = rear = 0;
        queue[rear] = p;
    }
    else {
        if (p.age >= 60) {
            front = (front - 1 + MAX) % MAX;
            queue[front] = p;
        } else {
            rear = (rear + 1) % MAX;
            queue[rear] = p;
        }
    }

    printf("\nTicket Booked! Seat No: %d\n", p.seatNo);
}
// ========================================
// Aniket Chopde : BOOKING + PRIORITY LOGIC
// ========================================

void cancelTicket() {
    if (isEmpty()) {
        printf("\nNo reservations to cancel.\n");
        return;
    }

    struct Passenger p = queue[front];

    printf("\nCancelled Ticket:\n");
    printf("ID:%d Name:%s Age:%d Train:%d Seat:%d\n",
           p.id, p.name, p.age, p.trainNo, p.seatNo);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}
// ========================================
// Aniket Chopde : BOOKING + PRIORITY LOGIC
// ========================================

void display() {
    if (isEmpty()) {
        printf("\nNo reservations.\n");
        return;
    }

    printf("\nReservations:\n");

    int i = front;
    while (1) {
        printf("ID:%d | Name:%s | Age:%d | Train:%d | Seat:%d\n",
               queue[i].id,
               queue[i].name,
               queue[i].age,
               queue[i].trainNo,
               queue[i].seatNo);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Railway Reservation System ---\n");
        printf("1. Book Ticket\n2. Cancel Ticket\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bookTicket(); break;
            case 2: cancelTicket(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

   int main() {
    int choice;

    while (1) {
        printf("\n--- Railway Reservation System ---\n");
        printf("1. Book Ticket\n2. Cancel Ticket\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bookTicket(); break;
            case 2: cancelTicket(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}  
