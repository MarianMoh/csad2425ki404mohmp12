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

### Task 5: Details
Testing Server and Client Code
When testing server and client parts of an application, the main goal is to ensure that all components behave as expected under different scenarios.

1. Server-Side Testing: This involves testing the server logic, such as request handling, database interactions, and API processing. You write unit tests for individual server functions and integration tests for the entire server behavior. For example, you might test how the server handles client requests or interacts with a database.

2. Client-Side Testing: On the client side, you test UI components, user interactions, and communication with the server. Unit tests verify individual functions, such as form validations, while integration tests check how the client interacts with the server. Mocking server responses is often used to simulate communication during client testing.

Using OpenCppCoverage for Code Coverage
OpenCppCoverage helps measure how much of your server and client code is tested. It provides coverage reports that show which lines of code were executed during testing.

1. How It Works: OpenCppCoverage instruments your server and client binaries to track which lines of code are executed during test runs. It generates a report showing the percentage of covered and uncovered code.

2. Coverage Report: The report shows coverage percentages, such as "Cover 78%" and "Uncover 22%", indicating which parts of the server or client code have been tested and which have not.

Improving Test Coverage
If you see a lot of uncovered code (e.g., 22% uncovered), you can improve testing by writing additional unit or integration tests to cover those parts, ensuring better validation of both server and client functionalities.
