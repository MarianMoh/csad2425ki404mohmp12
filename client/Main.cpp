#include <iostream>
#include "SerialPort.h"

// The main function initializes serial communication, sends a user-defined message to Arduino,
// and terminates automatically after receiving a response.
int main() {
    SerialPort serialPort("\\\\.\\COM3");

    // Attempt to configure the serial port. Exit if configuration fails.
    if (!serialPort.configurePort()) {
        std::cerr << "Failed to initialize the serial port. Check the connection and try again!" << std::endl;
        return 1;
    }
    std::cout << "Serial port initialized successfully." << std::endl;

    // Ask the user to input a message for Arduino.
    std::string userMessage;
    std::cout << "Please enter a message to send to Arduino: ";
    std::getline(std::cin, userMessage);

    // Inform the user that the program is waiting for a response.
    std::cout << "Awaiting a response from the Arduino device..." << std::endl;

    // Send the user's message and read the response from Arduino.
    std::string deviceReply = serialPort.sendMessage(userMessage);

    // If a response is received, display it and exit the program.
    if (!deviceReply.empty()) {
        std::cout << "Arduino replied: " << deviceReply << std::endl;
    }
    else {
        std::cerr << "Error: No response received from the device." << std::endl;
    }

    // Program automatically exits after displaying the response.
    return 0;
}