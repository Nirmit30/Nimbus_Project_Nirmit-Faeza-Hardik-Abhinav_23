#include <stdio.h>
#define Rows 12
#define Cols 4

int seats[Rows][Cols] = {0}; // Initialize all seats to 0

void bookTicket();
void cancelBooking();
void displaySeatMap();

void bookingSystem() 
{   
    printf("Welcome to the Booking System!\n");

    char choice;
    printf("Please select an option:\n");
    printf("A. Book a ticket\n");
    printf("B. Cancel a booking\n");    
    printf("C. View Seat Map\n");
    scanf(" %c", &choice);

    if(choice == 'A' || choice == 'a') 
    {
        bookTicket();  // Correct function call
    } 
    else if(choice == 'B' || choice == 'b') 
    {
        cancelBooking();  // Correct function call
    } 
    else if(choice == 'C' || choice == 'c')
    {
        displaySeatMap();  // Correct function call
    } 
    else 
    {
        printf("Invalid option selected.\n");
    }

    printf("Thank you for using the Booking System!\n");
}

void bookTicket() 
{
    int seatNumber;
    printf("Enter seat number (1-48): ");
    scanf("%d", &seatNumber);
    
    if(seatNumber < 1 || seatNumber > 48) {
        printf("❌ Invalid seat number!\n");
        return;
    }

    // Convert seat number into 2D index
    int row = (seatNumber - 1) / Cols;
    int col = (seatNumber - 1) % Cols;

    if(seats[row][col] == 1) {
        printf("❌ Seat already booked!\n");
        return;
    }

    seats[row][col] = 1;
    printf("🎉 Seat %d booked successfully!\n", seatNumber);
}

void cancelBooking()
{
    int seatNumber;
    printf("Enter seat number to cancel (1-48): ");
    scanf("%d", &seatNumber);

    if(seatNumber < 1 || seatNumber > 48) {
        printf("❌ Invalid seat number!\n");
        return;
    }

    int row = (seatNumber - 1) / Cols;
    int col = (seatNumber - 1) % Cols;

    if(seats[row][col] == 0) {
        printf("❌ Seat was not booked!\n");
        return;
    }

    seats[row][col] = 0;
    printf("✔ Seat %d booking cancelled successfully!\n", seatNumber);
}

void displaySeatMap()
{
    printf("\n=========== BUS SEAT MAP ===========\n");
    printf("O = Available | X = Booked\n\n");

    int seatNumber = 1;
    for(int i = 0; i < Rows; i++)
    {
        for(int j = 0; j < Cols; j++)
        {
            if(j == 2)
                printf("   ||   ");   // Aisle representation

            printf("%2d(%c) ", seatNumber, seats[i][j] ? 'X' : 'O');
            seatNumber++;
        }
        printf("\n");
    }
    printf("====================================\n");
}
