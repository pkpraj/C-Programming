/**
* @file LandBasedTracked.cpp
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
* This C++ program is a source file for the LandBasedtracked robot. This implements derived class from the Landbased class and inherited all the valid function from it.The namespace is given as fp(a wrapped namespace for the whole base class)
* This has attributes protected attributes like track type.
*/

/*! \file LandBasedTracked.h
	\brief A file for base class inclusion.

	A base class from which we inherit properties of LandBasedRobot.
*/

#include "LandBasedTracked.h"
#include "../API/api.h"
#include <iostream>
#include <string>

/**
* A constructor.
* A constructor which takes name, x, and y as arguments and sets these parameters.
 */
fp::LandBasedTracked::LandBasedTracked(std::string name, int x, int y) : LandBasedRobot(name, x, y), track_type{ "tank" } {}

/**
* A constructor.
* A constructor which takes no arguments and initializes name to none and x & y to 0.
*/

fp::LandBasedTracked::LandBasedTracked() : LandBasedRobot(), track_type{ "tank" } {}

/**
* A destructor.
* This will destroy the object LandBasedTracked after use
*/
fp::LandBasedTracked::~LandBasedTracked(){}
/**
 * @brief This will move forward 
 * @section Description
 * FUNCTION NAME - MoveForward
 * FUNCTION PARAMETER TYPE - two integers
 */
void fp::LandBasedTracked::MoveForward() {
	switch (direction_) {
		case 'N':
			y_++;
			break;
		case 'E':
			x_++;
			break;
		case 'S':
			y_--;
			break;
		case 'W':
			x_--;
			break;
}
}



/**
 * @brief This will turn robot left given as co-ordinates
 * @section Description
 * FUNCTION NAME - TurnLeft
 * FUNCTION PARAMETER TYPE - two integers
 */


void fp::LandBasedTracked::TurnLeft(int x, int y){
	switch (direction_) {
	case 'N':
		direction_ = 'W';
		break;
	case 'E':
		direction_ = 'N';
		break;
	case 'S':
		direction_ = 'E';
		break;
	case 'W':
		direction_ = 'S';
		break;
	}
}

/**
 * @brief This will just ouput that appropriate function are called or not
 * @section Description
 * FUNCTION NAME - TurnRight
 * FUNCTION PARAMETER TYPE - two integers
 */

void fp::LandBasedTracked::TurnRight(int x, int y){
	switch (direction_) {
	case 'N':
		direction_ = 'E';
		break;
	case 'E':
		direction_ = 'S';
		break;
	case 'S':
		direction_ = 'W';
		break;
	case 'W':
		direction_ = 'N';
		break;
	}
}



