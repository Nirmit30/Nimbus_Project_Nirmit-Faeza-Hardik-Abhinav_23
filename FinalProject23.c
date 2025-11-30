#include <stdio.h>
#include <string.h>

#define ROWS 12
#define COLS 4
#define MAX_BUSES 2
#define WAITLIST_SIZE 10

// Structure for Bus
typedef struct {
    int id;
    char route[50];
    int seats[ROWS][COLS];   // 0 = empty, 1 = booked
    int waitlist[WAITLIST_SIZE];
    int front, rear;
} Bus;

// Global array for buses
Bus buses[MAX_BUSES];

// ---------------- WAITLIST FUNCTIONS ----------------
int isWaitlistFull(Bus *b) {
    return b->rear == WAITLIST_SIZE - 1;
}

int isWaitlistEmpty(Bus *b) {
    return b->front > b->rear;
}

void addToWaitlist(Bus *b, int pid) {
    if (isWaitlistFull(b)) {
        printf("Waitlist full, cannot add more passengers!\n");
        return;
    }
    b->rear++;
    b->waitlist[b->rear] = pid;
    printf("Passenger %d added to waitlist.\n", pid);
}

int removeFromWaitlist(Bus *b) {
    if (isWaitlistEmpty(b))
        return -1;
    int p = b->waitlist[b->front];
    b->front++;
    return p;
}


//Abhinav Code 
// ---------------- INITIALIZATION ----------------
void initBuses() {
    for (int b = 0; b < MAX_BUSES; b++) {
        buses[b].id = b + 1;
        sprintf(buses[b].route, "City %d -> City %d", b + 1, b + 2);
        buses[b].front = 0;
        buses[b].rear = -1;

        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                buses[b].seats[i][j] = 0;
    }
}

//Abhinav Code

// ---------------- DISPLAY SEATS ----------------

void showSeats(Bus *b) {
    printf("\n========== BUS %d SEAT MAP ==========\n", b->id);
    printf("Route: %s\n", b->route);
    printf("O = empty   X = booked\n\n");

    int seatNo = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d(%c)\t", seatNo, b->seats[i][j] ? 'X' : 'O');
            seatNo++;
        }
        printf("\n");
    }
    printf("====================================\n");
}

// ---------------- PRICING ----------------

//Hardik Code
// ---------------- BOOKING ----------------

//Faeza Code
void bookSeat(Bus *b) {
    int seatNo, pid;
    printf("\nEnter passenger ID: ");
    scanf("%d", &pid);
    printf("Enter seat number (1-48): ");
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > 48) {
        printf("Invalid seat number!\n");
        return;
    }

    int r = (seatNo - 1) / COLS;
    int c = (seatNo - 1) % COLS;

    if (b->seats[r][c] == 1) {
        printf("Seat already booked! Adding passenger to waitlist...\n");
        addToWaitlist(b, pid);
        return;
    }

    b->seats[r][c] = 1;
    printf("\nSeat %d booked successfully!\n", seatNo);
    printf("Ticket price: Rs.%d\n", seatPrice(c));

}

// ---------------- CANCELLATION ----------------

//Faeza Code

void cancelSeat(Bus *b) {
    int seatNo;
    printf("\nEnter seat number to cancel: ");
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > 48) {
        printf("Invalid seat number!\n");
        return;
    }

    int r = (seatNo - 1) / COLS;
    int c = (seatNo - 1) % COLS;

    if (b->seats[r][c] == 0) {
        printf("Seat is not booked!\n");
        return;
    }
}

// ---------------- BUS SELECTION ----------------

//Hardik Code


void menu() {
    int ch;
    initBuses();

    while (1) {
        printf("\n===== BUS BOOKING SYSTEM =====\n");
        printf("1. Book Seat\n");
        printf("2. Cancel Seat\n");
        printf("3. Show Seat Map\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        Bus *bus;

        switch (ch) {
            case 1:
                bus = selectBus();
                if (bus) bookSeat(bus);
                break;
            case 2:
                bus = selectBus();
                if (bus) cancelSeat(bus);
                break;
            case 3:
                bus = selectBus();
                if (bus) showSeats(bus);
                break;
            case 4:
                printf("\nThank you for using the Bus Booking System!\n");
                return;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}

// ---------------- MAIN FUNCTION ----------------

int main() {
    menu();
    return 0;
}
