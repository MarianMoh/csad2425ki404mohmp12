#include "SerialPort.h"
#include <iostream>

// Constructor that attempts to open the specified serial port.
SerialPort::SerialPort(const std::string& portName) {
    serialHandle = CreateFileA(portName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (serialHandle == INVALID_HANDLE_VALUE) {
        std::cerr << "Unable to open port: " << portName << std::endl;
    }
}

// Destructor that closes the serial port if it is open.
SerialPort::~SerialPort() {
    if (serialHandle != INVALID_HANDLE_VALUE) {
        CloseHandle(serialHandle);
    }
}

// Configure the port by setting its state and timeouts.
bool SerialPort::configurePort() {
    if (!setPortState()) {
        std::cerr << "Error: Unable to configure port state." << std::endl;
        return false;
    }
    if (!setPortTimeouts()) {
        std::cerr << "Error: Unable to set port timeouts." << std::endl;
        return false;
    }
    return true;
}

// Set port parameters such as baud rate, byte size, stop bits, and parity.
bool SerialPort::setPortState() {
    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(serialHandle, &dcbSerialParams)) {
        std::cerr << "Error: Unable to get port state." << std::endl;
        return false;
    }

    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(serialHandle, &dcbSerialParams)) {
        std::cerr << "Error: Unable to configure port." << std::endl;
        return false;
    }
    return true;
}

// Set timeouts for reading and writing to the port.
bool SerialPort::setPortTimeouts() {
    COMMTIMEOUTS timeouts = { 0 };
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;

    if (!SetCommTimeouts(serialHandle, &timeouts)) {
        std::cerr << "Error: Unable to set timeouts." << std::endl;
        return false;
    }
    return true;
}

// Send a message to Arduino and read the response.
std::string SerialPort::sendMessage(const std::string& message) {
    DWORD bytesWritten;
    if (!WriteFile(serialHandle, message.c_str(), message.size(), &bytesWritten, NULL) || bytesWritten != message.size()) {
        std::cerr << "Error: Unable to send message." << std::endl;
        return "";
    }

    Sleep(1000); // Waiting for a response

    char buffer[1024];
    DWORD bytesRead;
    if (!ReadFile(serialHandle, buffer, sizeof(buffer) - 1, &bytesRead, NULL)) {
        std::cerr << "Error: Unable to receive response." << std::endl;
        return "";
    }
    buffer[bytesRead] = '\0';
    return std::string(buffer);
}
