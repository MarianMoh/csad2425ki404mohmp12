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

### Task 3: Details

Develop a Server and Client application capable of supporting various game modes and functionalities. The system should enable seamless interaction between players or AI agents while maintaining game state and providing options for game management. Below are the specific requirements:

### Play Modes
1. Player vs Player:
Two human players interact with each other, taking turns during the game. The server facilitates communication between the two clients to ensure proper game synchronization.

2. Player vs AI (Random):
A human player competes against an AI opponent. The AI makes random moves, ensuring unpredictable behavior without a specific winning strategy.

3. Player vs AI (Win Strategy):
A human player competes against an AI opponent programmed with a specific winning strategy. The AI aims to maximize its chances of winning by evaluating the game state and making calculated moves.

4. AI (Random) vs AI (Win Strategy):
Two AI agents compete against each other: one using random moves and the other using a pre-programmed winning strategy. The game runs autonomously, allowing observers to analyze the performance of both AI implementations.

### Actions
1. New Game:
Start a fresh game session. Both the client and server should initialize all necessary components, including resetting the game state, scores, and player details.

2. Load Game:
Allow players to load a previously saved game state. The server retrieves the saved game data and synchronizes it with the client, enabling the players to resume from where they left off.

Save Game:
Provide the functionality to save the current game state, including player progress, scores, and the game board. The server should handle saving the data in a structured format for easy retrieval during a "Load Game" operation.
