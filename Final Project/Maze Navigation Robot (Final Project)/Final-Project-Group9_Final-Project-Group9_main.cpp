
/**
* @file main.cpp
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
* This C++ program is kind of a test file where prototyped definitions of class can take solid action.
* So here have included all the header files which basically contains functions for the main.cpp to work.
*/

#include "src/LandBasedWheeled/LandBasedWheeled.h"
#include "src/LandBasedTracked/LandBasedTracked.h"
#include "src/LandBasedRobot/LandBasedRobot.h"
#include "src/Algorithm/Algorithm.h"
#include "src/Maze/MAZE.h"

#include <vector>
#include <iostream>

//--prototype
void FollowActionPath(fp::LandBasedRobot *robot, const std::vector<std::string> &vec, std::string obj);

void FollowActionPath(fp::LandBasedRobot *robot, const std::vector<std::string> &vec,std::string obj){
    int x{robot->get_x()};//--should be 1 for wheeled and 2 for tracked
    int y{robot->get_y()};//--should be 4 for wheeled and 3 for tracked
    for (auto s: vec){
        
        if (s.compare("right")==0)
            robot->TurnRight(x,y);
        else if (s.compare("left")==0)
            robot->TurnLeft(x,y);
		else if (s.compare("forward") == 0)
			robot->MoveForward();
		
       
    }
}

/**
 * @brief Main function 
 * @param No arguments
 * @param No Arguments
 * @return 0
 * @section Description
 * The purpose of this method is currently to test whether all classes of this program are being included and implemented.
 * The header files contains the definitions and prototypes whereas the .cpp files contains the implementations of the functions. 
 * LandBasedRobot is the base class from which LandBasedtracked and LandBasedWheeled are derived a spart of inheritance.
 * Heirarchical Inheritance is followed where our two classes are derived from one base class.
 * The derived classes inherits the properties, attributes and functions of the base class.
*/

int main(){
    /*
    fp::LandBasedWheeled *wheeled = new fp::LandBasedWheeled("Husky",1,1);
	wheeled->SpeedUp(1);
    std::vector<std::string> action_path_wheeled {"right", "right","forward"};
    FollowActionPath(wheeled,action_path_wheeled,"book");
    
    fp::LandBasedTracked *tracked = new fp::LandBasedTracked("LT2-F",1,1);
    std::vector<std::string> action_path_tracked {"left","forward" };
    FollowActionPath(tracked,action_path_tracked,"cube");

	std::cout << wheeled->GetDirection() <<std::endl;
	std::cout << wheeled->get_x() <<"," << wheeled->get_y() << std::endl;

	std::cout << tracked->GetDirection() << std::endl;
	std::cout << tracked->get_x() << "," << tracked->get_y() << std::endl;
    
	

    delete wheeled;
    delete tracked;
    
    return 0;
    */
    fp::Maze maze;
    std::shared_ptr<fp::LandBasedRobot> robot = std::make_shared<fp::LandBasedWheeled>("Husky", 0, 0);
    
    fp::Algorithm BFS;

    int i = 0;
    while(!BFS.isGoal(robot->get_x(), robot->get_y())) {
        std::cerr << "BFS Iteration " << i << std::endl; // Output for Debugging
        BFS.Solve(robot, maze);
    i++; // Output for Debugging
    }

    return 0;
    

}

