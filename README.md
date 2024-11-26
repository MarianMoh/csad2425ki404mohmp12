### Repository Details
This repository was created to fulfill the learning objectives of the CSAD course. Taking into account the requirements, the repository name is csad2425ki404mohmp12.

### Task1 Details
1. Create a GitHub repository with the nаme csad2425ki404mohmp12, where:
YY1: 24
YY2: 25
Group: ki404
Student's full name: Moh M.P.
Student's number: 12
2. Grant repository access to the author/lecturer.

3. Create a branch in the following format: feature/develop/<task number>.

4. This README file will contain:

Details about the repository and task.
Information about the student's task as per Table 1.
Technology, programming language, and hardware details for the next tasks.
5. Create a Git tag in the format: <PROJECT_NAME>_<VERSION>_WW<YYWWD>, where:

YY: Current year
WW: Work week number
D: Current day number of the week
6. Create a pull request titled task1 and assign the lecturer as a reviewer.

7. After the reviewer approves, merge the pull request into the develop branch.

### Student Details and details from Table 1
Student Number: 12
Student Name: Moh Marian
Group: KI-404

Game : rock paper scissors
Config format : INI

### Technologies, Programming Language, and Hardware
For the upcoming tasks, the following technologies, languages, and hardware will be used:

Programming Language: C++
Hardware: Arduino Uno

### Task 2: Details
Design a simple communication schema where software (SW) acts as a client, hardware (HW) acts as a server, and communication occurs over UART.

The client should send a message to the server through the UART interface. Upon receiving the message, the server should process it, apply modifications (e.g., reverse, append data, or any specific transformation), and send the modified message back to the client. The client then processes the returned message to verify the functionality.

Create a YML configuration file to include the following functionalities:

Build All Binaries: Ensure that all required binaries for both the client and server are built successfully. If additional scripts are required for the build process, include them in a dedicated ci/ directory.
Run Tests: Implement automated tests to validate the communication process, including message transmission, server-side processing, and response handling by the client.
Generate Artifacts: Produce artifacts that contain the built binaries and comprehensive test reports. These artifacts should be stored for future analysis or deployment.
This task ensures the reliability of the communication system, including the correctness of data exchange between the client and server. Proper CI/CD implementation via the YML file guarantees consistent building, testing, and artifact generation.
