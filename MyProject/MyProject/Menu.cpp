#include <iostream>
#include <fstream>
#include <string>
#include "VIP.cpp"
#include "Seat.cpp"
#include "Movie.cpp"

int main() {
    // Print welcome message
    std::cout << "Welcome to the ticketing app!" << std::endl;

    // Get client name
    std::string name;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);

    // Ask if client wants to buy a ticket
    std::string response;
    std::cout << "Do you want to buy a ticket? (y/n) ";
    std::getline(std::cin, response);
    if (response != "y") {
        // Exit if client doesn't want to buy a ticket
        std::cout << "Thank you, have a nice day!" << std::endl;
        return 0;
    }

    // Get movie details
    Movie movie;
    std::cout << "Do you want to go to the Fast and Furious 23 movie? (y/n) ";
    std::getline(std::cin, response);
    if (response != "y") {
        std::cout << "Please enter the date, time and name of the movie you want to go to:";
        std::cin >> movie;
    }

    // Get seat details
    Seat seat;
    bool isSeatTaken = true;
    while (isSeatTaken) {
        std::cout << "Please enter the seat row: ";
        std::cin >> seat.row();
        std::cout << "Please enter the seat number: ";
        std::cin >> seat.number();
        isSeatTaken = seat.is_available();
        if (isSeatTaken) {
            std::cout << "Sorry, that seat is taken. Please choose another seat." << std::endl;
        }
    }

    // Get ticket type
    VIP vip;
    std::cout << "Do you want a VIP ticket? (y/n) ";
    std::cin >> response;
    if (response == "y") {
        vip.SetVIP(true);
        std::cout << "The VIP ticket costs $100. The normal ticket costs $50." << std::endl;
    }
    else {
        vip.SetVIP(false);
        std::cout << "The normal ticket costs $50." << std::endl;
    }

    // Print ticket
    std::cout << "--- TICKET ---" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Movie: " << movie << std::endl;
    std::cout << "Seat: " << seat << std::endl;
    if (vip.IsVIP()) {
        std::cout << "Price: $100 (VIP ticket)" << std::endl;
    }
    else {
        std::cout << "Price: $50 (normal ticket)" << std::endl;
    }

    // Open an output file stream
    std::ofstream out_file("tickets.txt");

    // Check if the file was opened successfully
    if (out_file.is_open()) {
        // Write to the file
        out_file << "Ticket information" << std::endl;
        out_file << "--- TICKET ---" << std::endl;
        out_file << "Name: " << name << std::endl;
        out_file << "Movie: " << movie << std::endl;
        out_file << "Seat: " << seat << std::endl;
        if (vip.IsVIP()) {
            std::cout << "Price: $100 (VIP ticket)" << std::endl;
        }
        else {
            std::cout << "Price: $50 (normal ticket)" << std::endl;
        }

        // Close the file
        out_file.close();
    }
    else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }

    return 0;
}

