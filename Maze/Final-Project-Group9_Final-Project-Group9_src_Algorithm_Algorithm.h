/*!
* @file algorithm.h
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
* This C++ program is algorithm declaration for function to be used in source file for the maze. Applied algorithm is BFS(Brute(Breadth) Force Search).
* All the used files are declared here.
*/
#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <queue>
#include <algorithm>
#include <utility>
#include <bits/stdc++.h> 

#include "../API/api.h"
#include "../LandBasedWheeled/LandBasedWheeled.h"
#include "../LandBasedTracked/LandBasedTracked.h"
#include "../Maze/MAZE.h"

namespace fp{
/*!
 * \class Algorithm
 * \author Group-9-ENPM809Y
 * \date 03/12/19
 * \file Algorithm.h
 * \brief Class to be used in source file and the functions that have been used.
 * @section DESCRIPTION
 * This class declaration is the files to be used in the source file and the behaviour has been implemented in the source file
 */     
class Algorithm
{
    private:
    //Struct for storing coordinates.
    struct coordinates 
    {
        int x;/*!< maze's x co-ordinate   */ 
        int y;/*!< maze's y co-ordinate   */ 
    };
        
    coordinates cur_node; /*!< an object creation */ 
    std::pair<std::pair<int, int>, char> cur_state; /*!< a 2-D vector for representing current state  */ 
    std::pair<std::pair<int, int>, char> new_state; /*!<   a 2-D vector for representing new state  */
    std::vector<std::pair<std::pair<int, int>, char>> explored; /*!< a 2-D vector for representing explored state    */
    std::vector<std::pair<std::pair<int, int>, char>> to_do; /*!<   a 2-D vector for representing to_do nodes.  */
    std::map<std::pair<std::pair<int, int>, char>, std::pair<std::pair<int, int>, char>> parents;
    std::vector<std::pair<std::pair<int, int>, char>> paths; /*!<  available path  */
        
    public:
    
    bool if_visited(std::pair<std::pair<int, int>, char> new_node);  /*!<  a function to check if we are in new node during visiting or not. */
    bool if_duplicated(std::pair<std::pair<int, int>, char> new_state); /*!< a function to check wether  we are in new or visited state. */
    bool Solve(std::shared_ptr<fp::LandBasedRobot>, fp::Maze&); /*!< heart of algorithm */
    bool isGoal(int x, int y); /*!<  a function to check wether it s goal or not */
};
}
