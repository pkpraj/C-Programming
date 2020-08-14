/**
* @file LandBasedRobot.cpp
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
* This C++ program is a source file for the LandBasedRobot. Here we have used all the function defined for the headerfile and just printed out that this particular function has been called.
*/

/*! \file LAndBasedRobot.h
	\brief A file for base class inclusion.

	A base class from which we inherit properties of LandBasedRobots like GoUp and GoDown.
*/

#include "LandBasedRobot.h"
#include <iostream>



/**
* A constructor.
* A constructor which takes name, x, and y as arguments and sets these parameters.
 */
fp::LandBasedRobot::LandBasedRobot(std::string name, int x, int y) : name_{ name }, x_{ x }, y_{ y }, speed_{ 1 }, width_{ 1 }, length_{ 1 }, height_{ 1 }, capacity_{ 1 }, direction_{ 'N' }{};

/**
* A constructor.
* A constructor which takes no arguments and initializes name to none and x & y to 0.
*/

fp::LandBasedRobot::LandBasedRobot() : name_{ "none" }, x_{ 0 }, y_{ 0 }, speed_{ 1 }, width_{ 1 }, length_{ 1 }, height_{ 1 }, capacity_{ 1 }, direction_{ 'N' }{};

/**
* A destructor.
* This will destroy the object LandBasedWheeled after use
*/

fp::LandBasedRobot::~LandBasedRobot(){}

void fp::LandBasedRobot::MoveForward()
{
}



/**
 * @brief This will just ouput that appropriate function are called or not
 * @section Description
 * FUNCTION NAME - TurnLeft
 * FUNCTION PARAMETER TYPE - two integers
 */

void fp::LandBasedRobot::TurnLeft(int x, int y){
	std::cout << "LandBasedRobot::TurnLeft is called\n";

}

/**
 * @brief This will just ouput that appropriate function are called or not
 * @section Description
 * FUNCTION NAME - TurnRight
 * FUNCTION PARAMETER TYPE - two integers
 */

void fp::LandBasedRobot::TurnRight(int x, int y){
	std::cout << "LandBasedRobot::TurnRight is called\n";

}



/**
 * @brief This will just ouput that appropriate function are called or not
 * @section Description
 * FUNCTION NAME - get_x
 * FUNCTION PARAMETER TYPE - none
 */

int fp::LandBasedRobot::get_x() {
	std::cout << "LandBasedRobot::get_x is called\n";
	return 0;
}

/**
 * @brief This will just ouput that appropriate function are called or not
 * @section Description
 * FUNCTION NAME - get_y
 * FUNCTION PARAMETER TYPE - none
 */

int fp::LandBasedRobot::get_y() {
	std::cout << "LandBasedRobot::get_y is called\n";
	return 0;

}
/**
 * @brief This will get direction of robot
 * @section Description
 * FUNCTION NAME - Get_Direction
 * FUNCTION PARAMETER TYPE - none
 */
char fp::LandBasedRobot::GetDirection()
{
	return 0;
}
/**
 * @brief This function gets the spped of landbased robot
 * @section Description
 * FUNCTION NAME - get_speed
 * FUNCTION PARAMETER TYPE - none
 */
double fp::LandBasedRobot::get_speed()
{
	return 0;
}