/*!
* @file MAZE.h
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
* This C++ program is amaze class declaration for the maze. 
* Class and functions to be used are are declared in header file and other library have been included in this header file.
*/
#pragma once

#include <iostream>
#include <array>

#include "../API/api.h"

namespace fp

 {  
/*!
 * \class Maze
 * \author Group-9 ENPM809Y
 * \date 03/12/19
 * \file MAZE.h
 * \brief class declarartion with functions wrapped in the namespace fp.
 */  
    class Maze
    {   
        protected:

        int WallDetectedS[16][16]; /*!< a matrix to check wether wall detected in south direction  */
        int WallDetectedN[16][16]; /*!< a matrix to check wether wall detected in north direction  */
        int WallDetectedW[16][16]; /*!< a matrix to check wether wall detected in west direction  */
        int WallDetectedE[16][16]; /*!< a matrix to check wether wall detected in east direction  */

        public:
//! A constructor.
/*!
A constructor that takes no arguments.

*/
        Maze();
        
/*!
 * \brief this is for the design of the a maze based on the co-ordinates given here in x,y parameter.
 * \param x- x co-ordinate
 * \param y -y co-ordinate
 * \param dir a char to set up direction from N,E,W,S
 * @section DESCRIPTION
 * 
 * A very simple wrapped function(in fp namespace to construct a maze which will with given co-ordinates desihn a maze and 
 * detailed explanation is in implementation file.
 */          
        void MazeDesign(int x, int y, char dir);
        void MazeConstruct();
// ===============++++++++++++++++++++=========================================//
/*!
 * \brief to check at specific location in maze is wall or space in south direction.
 * \param x
 * \param y
 * \return int
 */
        bool SouthWallPresent(int x, int y) const;
 /*!
 * \brief to check at specific location in maze is wall or space in north direction.
 * \param x
 * \param y
 * \return int
 */        
        bool NorthWallPresent(int x, int y) const;
/*!
 * \brief to check at specific location in maze is wall or space in west direction.
 * \param x
 * \param y
 * \return int
 */        
        bool WestWallPresent(int x, int y) const;
        
        bool EastWallPresent(int x, int y) const;
/*!
 * \brief to check at specific location in maze is wall or space in east direction.
 * \param x
 * \param y
 * \return int
 */ 
 
 //!A destructor
        ~Maze() {}
    };

}
