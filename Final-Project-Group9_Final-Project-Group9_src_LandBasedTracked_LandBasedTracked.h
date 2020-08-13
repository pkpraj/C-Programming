/**
* @file LandBasedTracked.h
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
* This C++ program is a header file for the LandBasedTracked robot. This is derived class from the Landbased class and inherited all the valid function from it.The namespace is given as fp(a wrapped namespace for the whole base class)
* This has attributes protected attributes like track type.
*/

/*! \file LandBasedRobot.h
	\brief A file for base class inclusion.

	A base class from which we inherit properties of LandBasedRobots.
*/

#pragma once
#include "../LandBasedRobot/LandBasedRobot.h"

#include <string>

/*! \namespace fp
	\brief namespace from the base class

	 This namespace is used for convience and avoid conflict with std.
*/
namespace fp
{
	//!  A LandbasedTracked class.. 
	/*!
	  This class is derived from from the LandBasedRobot base class and it has access to every member function of base class.
	*/
class LandBasedTracked : public LandBasedRobot
{
	protected:
		std::string track_type;
	
	public:

		/**
	  * A constructor.
	  * A constructor which takes name and x and y as an argument.
	  */
		LandBasedTracked(std::string name, int x, int y);
		/**
	   * A constructor.
	   * A constructor with no arguments.
	   */
		LandBasedTracked();
		/**
	  * A destructor.
	  * This will destroy the object LandBasedTracked after use
	  */
		virtual ~LandBasedTracked();

		virtual void MoveForward() override;


		/**
 * @brief This function works for Turnleft for tracked robot
 * @param int
 * @param int
 * @return none
 * @section DESCRIPTION
 * FUNCTION NAME - TurnLeft()
 * FUNCTION PARAMETER TYPE - integers
 * RETURN TYPE OF TurnLeft() is void.
 */

		virtual void TurnLeft(int, int) override;

		/**
 * @brief This function works for TurnRight for tracked robot
 * @param int
 * @param int
 * @return none
 * @section DESCRIPTION
 * FUNCTION NAME - TurnRight()
 * FUNCTION PARAMETER TYPE - integers
 * RETURN TYPE OF TurnRight() is void.
 */
		virtual void TurnRight(int, int) override;
		

		/**
* @brief This function works as getter for x coordinate
* @param None
* @return int
* @section DESCRIPTION
* FUNCTION NAME - get_x()
* FUNCTION PARAMETER TYPE - void
* RETURN TYPE OF get_x() is integer.
*/
		virtual int get_x() override {
			return x_;
		}

/*!
 * @brief This function works as getter for y coordinate
 * @param None
 * @return integer
 * @section DESCRIPTION
 * FUNCTION NAME - get_y()
 * FUNCTION PARAMETER TYPE - void
 * RETURN TYPE OF get_y() is integer.
 */
		virtual int get_y() override {
			
			return y_;
		}
/*!        
 * @brief This function is getter function for direction
 * @param None
 * @return char
 * @section DESCRIPTION
 * FUNCTION NAME - get_Direction()
 * FUNCTION PARAMETER TYPE - char
 * RETURN TYPE OF get_y() is char.
 */
		virtual char GetDirection() override {
			return direction_;
		}
/*!        
 * @brief This function is getter function for spped
 * @param None
 * @return char
 * @section DESCRIPTION
 * FUNCTION NAME - get_speed()
 * FUNCTION PARAMETER TYPE - char
 * RETURN TYPE OF get_y() is char.
 */
		virtual double get_speed() override {
			return speed_;
		}
};

}
