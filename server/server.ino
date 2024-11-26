void setup() {
  Serial.begin(9600);  // Set the baud rate for serial communication
  while (!Serial) {
    ;  // Wait for the serial port to connect
  }
}

void loop() {
  // Wait for a message to be received
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');  // Read the message until a newline character
    message += " Copy";  // Modify the message by appending " Copy" to the end
    // Send the modified message back to the client
    Serial.println(message);  // Return the modified message
    // Stop after one connection (if further communication is not required)
  }
}
