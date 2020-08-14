/**
* @file Assignment.cpp
* @author Group9 <ENPM809Y>
* @version 2.0
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* @section DESCRIPTION
*
* This C++ program finds a path in a maze for a robot in 2-D Environment from the specified start and goal. 
*/


#include <iostream>
#include <array>
#include <vector>
#include <fstream> 
#include <limits>

using namespace std; 

/**
* @brief These are the list of functions we have used and their detailed description will be given before each function.
*/

/**
* @brief Functions are prototyped below. The entire body of the functions are declared after the 'main()' function.
*/

/**
 * @section Description
 * FUNCTION NAME - CheckPoint(array<int, 2> &z)
 * FUNCTION PARAMETER TYPE - Array of Integers
 * RETURN TYPE OF CheckPoint is void
 */

void CheckPoint(array<int, 2> &z);

/**
 * @section Description
 * FUNCTION NAME - FindPath(int x, int y)
 * FUNCTION PARAMETER TYPE - Integers
 * RETURN TYPE OF FindPath is Boolean
 */

bool FindPath(int x, int y);

/**
 * @section Description
 * FUNCTION NAME - PrintMaze()
 * FUNCTION PARAMETER TYPE - No parameters
 * RETURN TYPE OF PrintMaze() is void
 */

void PrintMaze();

array<int, 2> start, goal;

const int MazeWidth{7}, MazeHeight{6};
char maze[MazeHeight][MazeWidth];

int count{0};

/**
 * @brief Main function 
 * @param argc
 * @param argv
 * @return 0
 * @section Description
 * This function imports the maze file given in text format, reads it, transfers it to an array and prints the maze.
 * The printed maze is formed using characters like '#' and '.'
 * Here you will call all the functions and to check for a path and result and prints the final maze with the output.
*/

int main(int argc, char **argv)
{   
	ifstream myfile;
	myfile.open("maze2.txt");
    
    if(!myfile.is_open()){
        cout << "Directory not found!" << endl;
        return 0;
    }    
	
	for (int i = 0; i < MazeHeight; i++) {
		for (int j = 0; j < MazeWidth; j++) {
			myfile >> noskipws >> maze[i][j];
		}
	}

	myfile.close();
    
	PrintMaze();
         
    cout << "\nPlease input the desired start node: " << endl;
    cin >> start.at(1) >> start.at(0);
	CheckPoint(start);

    cout << "Please input the desired goal node: " << endl;
    cin >> goal.at(1) >> goal.at(0);
    
	CheckPoint(goal);
       
    maze[MazeHeight - 1 - goal[0]][goal[1]] = 'd';
    
	if (FindPath(MazeHeight - 1 - start[0], start[1])) {
		maze[MazeHeight - 1 - start[0]][start[1]] = 's';
		PrintMaze();
		cout << "\nPath found!" << endl;
	}
    else{
        PrintMaze();
        cout << "Damn! What's wrong!" << endl;
    }
        
	return 0;
}

/**
 * @brief This function checks whether appropriate inputs are provided for the program.
 * @section DESCRIPTION
 * The 'do while()' loop is used to check for invalid inputs unless a valid input is provided. 
 * The first if statements is used to check whether given inputs are integers or not.
 * Once done the next if statement checks if the inputs are in a valid position inside the maze and not on the boundaries. 
  
  
  @param z
  @return None 
 */

void CheckPoint(array<int, 2> &z) {
	bool b = false;
	do {
		if (!cin.good()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input, please re-input: " << endl;

			cin >> z.at(1) >> z.at(0);
		}

		else if (z.at(0) < 0 || z.at(0) > MazeHeight - 1 || z.at(1) < 0 || z.at(1) >= MazeWidth - 1) {
			cout << "Out of Bounds! Please re-input: " << endl;
			cin >> z.at(1) >> z.at(0);
		}

		else if (maze[MazeHeight - 1 - z.at(0)][z.at(1)] == '#') {
			cout << "That's a wall! Please re-input: " << endl;
			cin >> z.at(1) >> z.at(0);
		}
		else {
			b = true;
		}
	} while (!b);
}

/**
 * @brief This function checks for a possible path in the maze in which the robot can traverse and backtrack if path not found.
 * @param int x
 * @param int y
 * @return bool
 * @section DESCRIPTION
 * The function takes in integers x and y parameters as coordinates and checks for the bound conditions in first if statement.
 * Then in the next 'if condition' we check whether destination is determined or not.
 * The last part of the program is recursive in nature and adds 4 move to check whether those moves are possible in the given coordinate space.
 * The path is marked using "+" sign.
 * Again 4 move is up,down,left and right.
 */

bool FindPath(int x, int y){
    if (x < 0 || x >= MazeHeight || y < 0 || y >= MazeWidth){
        return false;
    }
    
    //goal found.
    if (maze[x][y] == 'd'){
        return true;
    }
    //to determine the edge conditions.
    if (maze[x][y] != '.'){
        return false;
    }
    
        
    maze[x][y] = '+';//Mark (x, y) as part of the solution;
    
    if (FindPath(x - 1, y))
        return true;
        
    if (FindPath(x, y + 1))
        return true;
    
    if (FindPath(x + 1, y))
        return true;
    
    if (FindPath(x, y - 1))
        return true;
    
    
    maze[x][y] = '.';
    
    return false;
    
    
}

/**
 * @brief This function will print the initial maze and the final output maze with the resultant path.
 * @section Description
 * The function prints the maze using two for loops 
 */

void PrintMaze(){
    
    for (int i = 0; i < MazeHeight; i++) {
		for (int j = 0; j < MazeWidth; j++) {
			printf("%c",maze[i][j]);
		}
	}
   
}