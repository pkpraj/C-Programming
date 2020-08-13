/**
* @file LandBasedRobot.h
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

* This C++ program is a header file for the LandBasedRobot. This is an abstract base class from which we will inherit all the functions of base class like simple GoUp and GoDown and besides we also have access of attributes like speed and width as well.
*/

#pragma once
#include <string>


namespace fp
{
/*!
 * \class LandbasedRobot
 * \author Group-9-ENPM809Y
 * \date 03/12/19
 * \file LandBasedRobot.h
 * \brief Class to be used in source file and the functions that have been used.
 * @section DESCRIPTION
 * This class declaration for files which are in LandBasedRobot.cpp this all function will be used to move robot. 
 */
class LandBasedRobot
{
	protected:
		std::string name_; /*!< protected name of the robot */
		int x_;  /*!< X-Co-ordinate of robot location */
		int y_; /*!< Y-Co-ordinate of robot location */
		double speed_; /*!< a float speed of robot */
		double width_; /*!< width of robot */
		double length_; /*!< length attribut of robot */
		double height_; /*!< height attribut of robot */
		double capacity_; /*!< capaity of robot */
		char direction_; /*!< direction of robot */

	public:
		LandBasedRobot(std::string name, int x, int y);
		LandBasedRobot();
		~LandBasedRobot();
		virtual void MoveForward() = 0;
		virtual void TurnLeft(int x, int y) = 0;
		virtual void TurnRight(int x, int y) = 0;
		

		virtual int get_x() = 0;
		virtual int get_y() = 0;
		virtual char GetDirection() = 0;/*!< This is used to get the direction as character form */
		virtual double get_speed() = 0;/*!< This is getter function for spped. */
};

}
