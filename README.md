# Finding the shortest path in a warehouse

This project focuses on optimizing forklift routes within a warehouse for efficient item collection. Having experience working in a warehouse, I observed that one of the tasks involves using a forklift to gather items for shipment. The forklift's digital display shows a list of items needed for a specific order, and these items are organized based on their location within the warehouse, the two options on sorting the list is from small to large indexes or the other way around. The items are stored on shelves, and their positions follow a format such as 124-001 to 124-100. In this format, '124' represents the shelf number, and '001' to '100' represent specific spots on the shelf.

Currently, warehouse employees manually select the paths to collect items, relying on their knowledge of the warehouse's layout. However, this process is susceptible to human errors, leading to time wastage, increased wear and tear on the forklifts, and higher energy consumption, especially when longer paths are chosen.

My objective is to replace this manual path selection with an automated system that optimizes item sorting based on the shortest paths. This will not only enhance efficiency but also reduce the margin for human error, ultimately saving time, preserving forklifts, and minimizing energy consumption.

## Program specifications and languages

#### The graph and shortest path algorithm
This will be implemented in C.

#### Visualisation of the warehouse and forklift
I have an idea of making a visualisation of the warehouse and forklift driving the shortest path. I am considering doing this in python for a learning experience but I have not decided yet.

#### Testing
Some unit tests will be implemented, will update once that has been implemented.

#### Linter
TBD.

## Compiling and running instructions
*IMPORTANT*
This is done with using the GNU compiler for C.

#### Windows:
After cloning the project, navigate to the Graph directory of the project through your choice of CLI (command-line interface). Enter this line of code ```gcc -fdiagnostics-color=always -g -Iinc src/*.c -o bin/main.exe
``` to compile the project. Follow that up with entering ```main.exe``` in your CLI to run the program.

#### Linux:
After cloning the project, navigate to the Graph directory of the project through your choice of CLI (command-line interface). Enter this line of code ```gcc -fdiagnostics-color=always -g -Iinc src/*.c -o bin/main``` to compile the project. Follow that up with entering ```./main``` in your CLI to run the program.

## Kanban board
Click [here](https://github.com/users/simondereuver/projects/4) to view the Kanban board of the project.