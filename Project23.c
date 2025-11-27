#include <stdio.h>
int Rows =12;
int Cols =4;
int seats[12][4];
void bookingSystem() 
{   
    printf("Welcome to the Booking System!\n");
    // Additional booking system logic would go here
    char choice = 'A'; // Example choice
    printf("Please select an option:\n");
    printf("A. Book a ticket\n");
    printf("B. Cancel a booking\n");    
    printf("C. View Seat Map\n");
    scanf(" %c", &choice);
    printf("You selected option: %c\n", choice);
    if(choice == 'A') 
    {
        printf("Booking a ticket...\n");
        void bookTicket(); // Placeholder for booking function  
    } 
    else if(choice == 'B') 
    {
        void cancelBooking(); // Placeholder for cancellation function
        printf("Cancelling a booking...\n");
    } 
    else if(choice == 'C')
     {
        void displaySeatMap(); // Placeholder for seat map function
        printf("Displaying seat map...\n");
    } 
    else 
    {
        printf("Invalid option selected.\n");
    }
    printf("Thank you for using the Booking System!\n");
}
void bookTicket() 
{
    // Logic for booking a ticket
    int seatNumber;
    printf("Enter seat number (1-50): ");
    scanf("%d", &seatNumber);
    
    if(seatNumber < 1 || seatNumber > 50) {
        printf("Invalid!\n");
        return;
    }
    
    if(seats[seatNumber - 1] == 1) {
        printf("Already booked!\n");
        return;
    }
    
    seats[seatNumber - 1] = 1;
    printf("Booked seat %d!\n", seatNumber);

    printf("Ticket booked successfully!\n");
}
void cancelBooking()
{
    // Logic for cancelling a booking

    printf("Booking cancelled successfully!\n");
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
                printf("   ||   ");   // Aisle

            printf("%2d(%c) ", seatNumber,seats[i][j] == 0 ? 'O' : 'X');

            seatNumber++;
        }
        printf("\n");
    }
    printf("====================================\n");
}
int main() 
{
    bookingSystem();
    return 0;
}