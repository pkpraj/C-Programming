/*!
* @file api.h
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
* This C++ program is API header files where we have declared variables and function used in cpp file to be used in source file for the maze. 
* All the used files are declared here.
*/
#pragma once
#include <string>
namespace fp {
/*!
 * \class API
 * \author Group-9-ENPM809Y
 * \date 03/12/19
 * \file api.h
 * \brief Class to be used in source file and the functions that have been used.
 * @section DESCRIPTION
 * This class declaration for files which are in api.cpp this all function will be used to move robot. 
 */      
    
	class API {
	public:
		static int mazeWidth();/*!< maze width that can not be changed and static type  */
		static int mazeHeight();/*!< maze hieght that can not be changed and static type  */
		static bool wallFront();/*!< a boolean to check wether ther is wall in front or not. */
		static bool wallRight();/*!< a boolean to check wether ther is wall in right of the robot */
		static bool wallLeft();/*!< a boolean to check wether ther is wall in left or not. */
		static void moveForward(); /*!< a void method to move robot forward */
		static void turnRight();/*!< a void method to move turn robot right */
		static void turnLeft();/*!< a void method to move turn robot left */
		static void setWall(int x, int y, char direction);/*!< a void method to set a wall */
		static void clearWall(int x, int y, char direction);/*!< a void method to clear a wall */
		static void setColor(int x, int y, char color); /*!< a void method to set a color */
		static void clearColor(int x, int y);/*!< a void method to clear a color */
		static void clearAllColor();/*!< a void method to print message */
		static void setText(int x, int y, const std::string& text);/*!< a void method to set a text*/
		static void clearText(int x, int y);/*!< a void method to clear a color */
		static void clearAllText(); /*!< a void method to print meassage */
		static bool wasReset();/*!< a bool method to set a a string variable */
		static void ackReset();/*!< a bool method to set a a string variable */
	};
}