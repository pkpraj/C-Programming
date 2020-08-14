/*!
* @file api.cpp
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
* This C++ program is API source files where robot moving functions have been defined.
*/
#include "api.h"
#include <cstdlib>
#include <iostream>
/*!
 * \brief a function to take mazewidth from the user.
 * \param None-      Void function
 * @section DESCRIPTION
 * 
 * A function that takes mazewidth using cin and then return as a string 
 * But main use of this take response and set mazewidth variable.
 */
int fp::API::mazeWidth() {
	std::cout << "mazeWidth" << std::endl;
	std::string response;
	std::cin >> response;
	return atoi(response.c_str());
}
/*!
 * \brief a function to take mazeheight from the user.
 * \param None-  Void function
 * \return integer
 * @section DESCRIPTION
 * 
 * A function that takes maze-hieght using cin and then return as a string 
 * But main use of this take response and set mazeheight variable.
 */
int fp::API::mazeHeight() {
	std::cout << "mazeHeight" << std::endl;
	std::string response;
	std::cin >> response;
	return atoi(response.c_str());
}
/*!
 * \brief a function to set in front of robot.
 * \param None -   void function
 * \return True or False
 * @section DESCRIPTION
 *
 * A function is taking a respose from the robot and then after execution set a wall in front of it. 
 * We wanted to set wall as robot moves and discovers the maze so this is one of this important function to set a wall.
 */
bool fp::API::wallFront() {
	std::cout << "wallFront" << std::endl;
	std::string response;
	std::cin >> response;
	return response == "true";
}
/*!
 * \brief a function to wall in right hand direction.
 * \param None -   void function
 * \return True or False
 * @section DESCRIPTION
 *
 * A function is taking a respose from the robot and then after execution set a wall in right side of robot. 
 * We wanted to set wall as robot moves and discovers the maze so this is one of this important function to set a wall.
 */
bool fp::API::wallRight() {
	std::cout << "wallRight" << std::endl;
	std::string response;
	std::cin >> response;
	return response == "true";
}
/*!
 * \brief a function to wall in left hand direction.
 * \param None -   void function
 * \return True or False
 * @section DESCRIPTION
 *
 * A function is taking a respose from the robot and then after execution set a wall in left side of robot. 
 * We wanted to set wall as robot moves and discovers the maze so this is one of this important function to set a wall.
 */
bool fp::API::wallLeft() {
	std::cout << "wallLeft" << std::endl;
	std::string response;
	std::cin >> response;
	return response == "true";
}
/*!
 * \brief a function to move robot forward.
 * \param None -   void function
 * \return None
 * @section DESCRIPTION
 *
 * This is robot family function and used to move forward. 
 * This gives flexibility to move robot and different from wall family function.
 */
void fp::API::moveForward() {
	std::cout << "moveForward" << std::endl;
	std::string response;
	std::cin >> response;
	if (response != "ack") {
		std::cerr << response << std::endl;
		throw;
	}
}
/*!
 * \brief a function to turn robot right.
 * \param None -   void function
 * \return None
 * @section DESCRIPTION
 *
 * This is robot family function and used to turn right. 
 * This gives flexibility to move robot and different from wall family function.
 */
void fp::API::turnRight() {
	std::cout << "turnRight" << std::endl;
	std::string ack;
	std::cin >> ack;
}
/*!
 * \brief a function to turn robot left
 * \param None -   void function
 * \return None
 * @section DESCRIPTION
 *
 * This is robot family function and used to turnleft.
 * This gives flexibility to move robot and different from wall family function.
 */
void fp::API::turnLeft() {
	std::cout << "turnLeft" << std::endl;
	std::string ack;
	std::cin >> ack;
}
/*!
 * \brief a function to set a wall.
 * \param x co-ordinate
 * \param y co-ordinate
 * \param char for direction
 * \return None
 * @section DESCRIPTION
 *
 * This is function set a wall in given direction with x and y taken integers.
 */
void fp::API::setWall(int x, int y, char direction) {
	std::cout << "setWall " << x << " " << y << " " << direction << std::endl;
}
/*!
 * \brief a function to clear a wall.
 * \param x co-ordinate
 * \param y co-ordinate
 * \param char for direction
 * \return None
 * @section DESCRIPTION
 *
 * This is function clear a wall in given direction with x and y taken integers.
 */
void fp::API::clearWall(int x, int y, char direction) {
	std::cout << "clearWall " << x << " " << y << " " << direction << std::endl;
}
/*!
 * \brief a function to set a color wall
 * \param x co-ordinate
 * \param y co-ordinate
 * \param char for color
 * \return None
 * @section DESCRIPTION
 *
 * This is function used to set a color taken as "color parameter" and set using x-y coordinates.
 */
void fp::API::setColor(int x, int y, char color) {
	std::cout << "setColor " << x << " " << y << " " << color << std::endl;
}
/*!
 * \brief a function to clear a color wall
 * \param x co-ordinate
 * \param y co-ordinate
 * \return None
 * @section DESCRIPTION
 *
 * This is function used to clear a color using given x and y parameters.
 */
void fp::API::clearColor(int x, int y) {
	std::cout << "clearColor " << x << " " << y << std::endl;
}
/*!
 * \brief a function to clear all color
 * \param None -   void function
 * \return None
 * @section DESCRIPTION
 *
 * This is function print clearall.
 */
void fp::API::clearAllColor() {
	std::cout << "clearAllColor" << std::endl;
}
/*!
 * \brief a function to print x-y with text given.
 * \param x co-ordinate
 * \param y co-ordinate
 * \param string as text
 * \return None
 * @section DESCRIPTION
 *
 * This is function takes x-y and print out text at that co-ordinate.
 */
void fp::API::setText(int x, int y, const std::string& text) {
	std::cout << "setText " << x << " " << y << " " << text << std::endl;
}
/*!
 * \brief a function to clear text.
 * \param x co-ordinate
 * \param y co-ordinate
 * \return None
 * @section DESCRIPTION
 *
 * This is function takes x-y and clear out text at that co-ordinate.
 */
void fp::API::clearText(int x, int y) {
	std::cout << "clearText " << x << " " << y << std::endl;
}
/*!
 * \brief print out cleatext message.
 * \param None -   void function
 * \return None
 * @section DESCRIPTION
 *
 * This is function prints out message to user.
 */
void fp::API::clearAllText() {
	std::cout << "clearAllText" << std::endl;
}
/*!
 * \brief print out reset message and set respose as true
 * \param None -   void function
 * \return True/False
 * @section DESCRIPTION
 *
 * This is function take a respose using cin and set it to true.
 */
bool fp::API::wasReset() {
	std::cout << "wasReset" << std::endl;
	std::string response;
	std::cin >> response;
	return response == "true";
}
/*!
 * \brief print out reset message "ackReset"
 * \param None -   void function
 * \return None
 * @section DESCRIPTION
 *
 * This is function set string variable as ackReset.
 */
void fp::API::ackReset() {
	std::cout << "ackReset" << std::endl;
	std::string ack;
	std::cin >> ack;
}