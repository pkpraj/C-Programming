/*!
* @file MAZE.cpp
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
* This C++ program is maze implementation for the maze 
* Class and functions to be used are already declared in header file and other library have been included in header files.
*/
#include <iostream>

#include "MAZE.h"
/*!
 * \brief This is declareation for class maze which are wrapped up in the fp namespace.
 * \section DESCRIPTION
 * 
 * We have derived a lot of functions from the api file like set colors and set_text in the maze file.
 * Basically from the derived api untill we meet the wall we craete the maze here.
 */
   
   
fp::Maze::Maze()
{
    //MazeDesign coordinates;
    fp::API::setColor(0,0,'B');
    fp::API::setColor(7,7,'B');
    fp::API::setColor(7,8,'B');
    fp::API::setColor(8,7,'B');
    fp::API::setColor(8,8,'B');
    
    fp::API::setText(0,0,"Start");
    fp::API::setText(7,7,"Goal");
    fp::API::setText(7,8,"Goal");
    fp::API::setText(8,7,"Goal");
    fp::API::setText(8,8,"Goal");

    for(int x = 0; x < 16; x++)
    {
        for(int y = 0; y < 16; y++)
        {
            //Arrays to store the coordinates of the wall in all four directions.
        
            WallDetectedS[x][y] = false;
            WallDetectedN[x][y] = false;
            WallDetectedW[x][y] = false;
            WallDetectedE[x][y] = false;
              
        }
    }
}

// This function is to be called to update the coordinates of the wall as the robot progresses through the maze.
/*!
 * \brief this is for the design of the amze based on the co-ordinates given here in x,y parameter.
 * \param x- x co-ordinate
 * \param y -y co-ordinate
 * \param dir a char to set up direction from N,E,W,S
 * @section DESCRIPTION
 * 
 * A very simple wrapped function(in fp namespace in header file) to design a maze
 * Here for each direction we check for the wallchoice and if the from the api header file we are not meeting to wall
 * we are good to go and it writes a maze and that is why we have 4 different condition for 4 
 * different directions for each option(N,S,E,W). and if we met true than we write it in maze.
 */
void fp::Maze::MazeDesign(int x, int y, char dir)
{
    if(dir == 'S')
    {
        if(fp::API::wallFront())
        {
            fp::API::setWall(x, y, 's');
            WallDetectedS[x][y] = true;
        }

        if(fp::API::wallRight())
        {
             fp::API::setWall(x, y, 'w');
             WallDetectedW[x][y] = true;
        }

        if(fp::API::wallLeft())
        {
             fp::API::setWall(x, y, 'e');
             WallDetectedE[x][y] = true;
        }
    }

    if(dir == 'N')
    {
        if(fp::API::wallFront())
        {
            fp::API::setWall(x, y, 'n');
            WallDetectedN[x][y] = true;
        }

        if(fp::API::wallRight())
        {
             fp::API::setWall(x, y, 'e');
             WallDetectedE[x][y] = true;
        }

        if(fp::API::wallLeft())
        {
             fp::API::setWall(x, y, 'w');
             WallDetectedW[x][y] = true;
        }
    }

    if(dir == 'W')
    {
        if(fp::API::wallFront())
        {
            fp::API::setWall(x, y, 'w');
            WallDetectedW[x][y] = true;
        }

        if(fp::API::wallRight())
        {
             fp::API::setWall(x , y, 'n');
             WallDetectedN[x][y] = true;
        }

        if(fp::API::wallLeft())
        {
             fp::API::setWall(x, y,'s');
             WallDetectedS[x][y] = true;
        }
    }

    if(dir == 'E')
    {
        if(fp::API::wallFront())
        {
            fp::API::setWall(x, y, 'e');
            WallDetectedE[x][y] = true; 
        }

        if(fp::API::wallRight())
        {
             fp::API::setWall(x, y, 's');
             WallDetectedS[x][y] = true;
        }

        if(fp::API::wallLeft())
        {
             fp::API::setWall(x, y, 'n');
             WallDetectedN[x][y] = true;
        }
    }
}

// The four functions to be called to check if a wall is present in front of the robot in all four directions.
// The four functions to be called to check if a wall is present in front of the robot in all four directions.
/*!
 * \brief function is called wether the wall is present in the south direction
 * \param x
 * \param y
 * \return true/false based on the api function WallDetected.
 */
bool fp::Maze::SouthWallPresent(int x, int y) const
{
    return WallDetectedS[x][y];
}
/*!
 * \brief function is called wether the wall is present in the north direction.
 * \param x
 * \param y
 * \return true/false based on the api function WallDetected.
 */
bool fp::Maze::NorthWallPresent(int x, int y) const
{
    return WallDetectedN[x][y];
}
/*!
 * \brief function is called wether the wall is present in the west direction
 * \param x
 * \param y
 * \return true/false based on the api function WallDetected.
 */
bool fp::Maze::WestWallPresent(int x, int y) const
{
    return WallDetectedW[x][y];
}
/*!
 * \brief function is called wether the wall is present in the east direction
 * \param x
 * \param y
 * \return true/false based on the api function WallDetected.
 */
bool fp::Maze::EastWallPresent(int x, int y) const
{
    return WallDetectedE[x][y];
}
