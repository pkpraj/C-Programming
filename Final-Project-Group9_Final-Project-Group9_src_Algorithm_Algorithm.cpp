/*!
* @file algorithm.cpp
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
* This C++ program is algorithm implementation for the maze. Applied algorithm is BFS(Brute(Breadth) Force Search).
* All the functions are declared in the algorithm.h header file and other library have been included in header files.
*/
#include "Algorithm.h"
/*!
 * \brief a function to check wether we have visited nodes or not.
 * \param x-ordinate 
 * \return y-coordinate
 * @section DESCRIPTION
 *
 * A function is check x-y co-ordinates and check if we are in middle of maze it is end of game.
 */
bool fp::Algorithm::isGoal(int x, int y){
    if(x == 7 && y == 7) return true;
    if(x == 7 && y == 8) return true;
    if(x == 8 && y == 7) return true;
    if(x == 8 && y == 8) return true;
    
    return false;
}

/*!
 * \brief a function to check wether we have visited nodes or not.
 * \param a 2-D vector of new state
 * \return True or False
 * @section DESCRIPTION
 *
 * A function is basically comparing co-ordinates of x-y coordinates with previous nodes array to new node 
 * and if we have visted then set to false or else set true.
 */
bool fp::Algorithm::if_visited(std::pair<std::pair<int, int>, char> new_state){
    for (auto i : explored){
        if (new_state.second == i.second && new_state.first.first == i.first.first && new_state.first.second == i.first.second)
            return true;
    }
    return false;
}
/*!
 * \brief a function to check wether we have duplicate state in new node
 * \param a 2-D vector of new state
 * \return True or False
 * @section DESCRIPTION
 *
 * A function is basically comparing co-ordinates of x-y coordinates with previous node to new node 
 * and if we have visted then set to false or else set true.
 */

bool fp::Algorithm::if_duplicated(std::pair<std::pair<int, int>, char> new_state){
    for (auto i : to_do){
        if (new_state.second == i.second && new_state.first.first == i.first.first && new_state.first.second == i.first.second)
            return true;
    }
    return false;
}
/*!

 * \brief function is the gist of BFS Algorithm.
 * \return None
 * \param a shared pointer of landbased robot class 
 * \param maze object
 * \section DESCRIPTION
 * 
 * This is fairly complex function but mainly we are setting the variable here and then try to push them into a vector 
 * we also set a flag which shows wether this process has ended or not.
 * but basically a while condition shows that we will add nodes to current nodes untill we the path is found.
 * The method we see here is basically moves robot from api file and  then we check the boudries.
 */
bool fp::Algorithm::Solve(std::shared_ptr<fp::LandBasedRobot> robot, fp::Maze& maze)
{    
    cur_node = {robot->get_x(), robot->get_y()};
    char direction = robot->GetDirection();
    
    std::cerr << direction << std::endl;
    cur_state = {{cur_node.x, cur_node.y}, direction};
    maze.MazeDesign(cur_node.x, cur_node.y, direction);
    
    
    //to_do.push(cur_node);
    //explored.push_back(cur_node);

    //int flag = 0;
    while (fp::Algorithm::isGoal(cur_node.x, cur_node.y) == false){
        if(fp::Algorithm::if_visited(cur_state) == false){
            //When the robot facing north.
            if (direction == 'N'){
                //Front
                if(cur_node.y <= 14 && maze.NorthWallPresent(cur_node.x, cur_node.y) == false && if_duplicated({{cur_node.x, cur_node.y + 1}, 'N'}) == false){
                    new_state = {{cur_node.x, cur_node.y + 1}, 'N'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
                //Backward
                if(maze.WestWallPresent(cur_node.x, cur_node.y) == true && maze.NorthWallPresent(cur_node.x, cur_node.y) == true && maze.EastWallPresent(cur_node.x, cur_node.y) == true){
                    new_state = {{cur_node.x, cur_node.y - 1}, 'S'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
                //Left
                if(cur_node.x >= 1 && maze.WestWallPresent(cur_node.x, cur_node.y) == false && if_duplicated({{cur_node.x - 1, cur_node.y}, 'W'}) == false){
                    new_state = {{cur_node.x - 1, cur_node.y}, 'W'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
                //Right
                if(cur_node.x <= 14 && maze.EastWallPresent(cur_node.x, cur_node.y) == false && if_duplicated({{cur_node.x + 1, cur_node.y}, 'E'}) == false){
                    new_state = {{cur_node.x + 1, cur_node.y}, 'E'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
            }
            //When the robot facing south.
            if (direction == 'S'){
                //Front
                if(cur_node.y >= 1 && maze.SouthWallPresent(cur_node.x, cur_node.y) == false && if_duplicated({{cur_node.x, cur_node.y - 1}, 'S'})== false){
                    new_state = {{cur_node.x, cur_node.y - 1}, 'S'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
                //Backward
                if(maze.WestWallPresent(cur_node.x, cur_node.y)  == true && maze.SouthWallPresent(cur_node.x, cur_node.y) == true && maze.EastWallPresent(cur_node.x, cur_node.y) == true){
                    new_state = {{cur_node.x, cur_node.y + 1}, 'N'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
                //Right
                if(cur_node.x >= 1 && maze.WestWallPresent(cur_node.x, cur_node.y) == false && if_duplicated({{cur_node.x - 1, cur_node.y}, 'W'}) == false){
                    new_state = {{cur_node.x - 1, cur_node.y}, 'W'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
                //left
                if(cur_node.x <= 14 && maze.EastWallPresent(cur_node.x, cur_node.y) == false && if_duplicated({{cur_node.x + 1, cur_node.y}, 'E'}) == false){
                    new_state = {{cur_node.x + 1, cur_node.y}, 'E'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
            }
            
            if (direction == 'W'){
                //Front
                if(cur_node.x >= 1 && maze.WestWallPresent(cur_node.x, cur_node.y) == false && if_duplicated({{cur_node.x - 1, cur_node.y}, 'W'}) == false){
                    new_state = {{cur_node.x - 1, cur_node.y}, 'W'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
                //Backward
                if(maze.WestWallPresent(cur_node.x, cur_node.y) == true && maze.NorthWallPresent(cur_node.x, cur_node.y) == true && maze.SouthWallPresent(cur_node.x, cur_node.y) == true){
                    new_state = {{cur_node.x + 1, cur_node.y}, 'E'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
                //Left
                if(cur_node.y >= 1 && maze.SouthWallPresent(cur_node.x, cur_node.y) == false && if_duplicated({{cur_node.x, cur_node.y - 1}, 'S'}) == false){
                    new_state = {{cur_node.x, cur_node.y - 1}, 'S'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
                //Right
                if(cur_node.y <= 14 && maze.NorthWallPresent(cur_node.x, cur_node.y) == false && if_duplicated({{cur_node.x, cur_node.y + 1}, 'N'}) == false){
                    new_state = {{cur_node.x, cur_node.y + 1}, 'N'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
            }
            
            if (direction == 'E'){
                //Front
                if(cur_node.x <= 14 && maze.EastWallPresent(cur_node.x, cur_node.y) == false && if_duplicated({{cur_node.x + 1, cur_node.y}, 'E'}) == false){
                    new_state = {{cur_node.x + 1, cur_node.y}, 'E'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
                //Backward
                if(maze.EastWallPresent(cur_node.x, cur_node.y) == true && maze.NorthWallPresent(cur_node.x, cur_node.y) == true && maze.SouthWallPresent(cur_node.x, cur_node.y) == true){
                    new_state = {{cur_node.x - 1, cur_node.y}, 'W'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
                //Right
                if(cur_node.y >= 1 && maze.SouthWallPresent(cur_node.x, cur_node.y) == false && if_duplicated({{cur_node.x, cur_node.y - 1}, 'S'}) == false){
                    new_state = {{cur_node.x, cur_node.y - 1}, 'S'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
                //Left
                if(cur_node.y <= 14 && maze.NorthWallPresent(cur_node.x, cur_node.y) == false && if_duplicated({{cur_node.x, cur_node.y + 1}, 'N'}) == false){
                    new_state = {{cur_node.x, cur_node.y + 1}, 'N'};
                    to_do.push_back(new_state);
                    parents.insert({new_state, cur_state});
                }
            }
        }
        
        if (to_do.size() != 0){
            explored.push_back(cur_state);
            std::cerr << to_do.size() << std::endl;
            cur_state = to_do[0];
            cur_node = {cur_state.first.first, cur_state.first.second};
            direction = cur_state.second;
            //std::cerr << cur_node.x << ' ' << cur_node.y << ' ' << direction << std::endl;
            to_do.erase(to_do.begin());
            std::cerr << to_do.size() << std::endl;
        }
    }
    std::cerr << "Check" << std::endl;
    //Generate the path through back-tracing.
    paths.push_back(cur_state);
    while (paths.back() != explored.front()){
        paths.push_back(parents.at(paths.back()));
        if (robot->get_x() == 0 && robot->get_y() == 0){
            
        }else{
            
        //fp::API::setColor(paths.back().first.first, paths.back().first.second, 'B');
        
        }
    }
    std::reverse(paths.begin(), paths.end());
    
    //Now lets get the robot moving!!!
    coordinates cur_cord;
    char dir;
    for (unsigned int i = 1; i < paths.size(); i++){
        cur_cord = {robot->get_x(), robot->get_y()};
        dir = robot->GetDirection();
        std::cerr << "Move from " << robot->get_x() << " " << robot->get_y() << " " << robot->GetDirection() << " to -> ";
        std::cerr << paths[i].first.first << " " << paths[i].first.second << " " << paths[i].second << std::endl; 
        //When the robot facing north.
        if (dir == 'N' && paths[i].second == 'N' && maze.NorthWallPresent(cur_cord.x, cur_cord.y) == false){
            std::cerr << "forward" << std::endl;
            robot->MoveForward();
        }
        else if (dir == 'N' && paths[i].second == 'W' && maze.WestWallPresent(cur_cord.x, cur_cord.y) == false){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'N' && paths[i].second == 'E' && maze.EastWallPresent(cur_cord.x, cur_cord.y) == false){
            robot->TurnRight(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'N' && paths[i].second == 'S'){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }//when the robot facing south.
        else if (dir == 'S' && paths[i].second == 'S' && maze.SouthWallPresent(cur_cord.x, cur_cord.y) == false){
            std::cerr << "hit" << std::endl;
            robot->MoveForward();
            
        }
        else if (dir == 'S' && paths[i].second == 'E' && maze.EastWallPresent(cur_cord.x, cur_cord.y) == false){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'S' && paths[i].second == 'W' && maze.WestWallPresent(cur_cord.x, cur_cord.y) == false){
            robot->TurnRight(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'S' && paths[i].second == 'N'){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }//when the robot facing west.
        else if (dir == 'W' && paths[i].second == 'W' && maze.WestWallPresent(cur_cord.x, cur_cord.y) == false)
            robot->MoveForward();
        else if (dir == 'W' && paths[i].second == 'S' && maze.SouthWallPresent(cur_cord.x, cur_cord.y) == false){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'W' && paths[i].second == 'N' && maze.NorthWallPresent(cur_cord.x, cur_cord.y) == false){
            robot->TurnRight(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'W' && paths[i].second == 'E'){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }//when the robot facing east.
        else if (dir == 'E' && paths[i].second == 'E' && maze.EastWallPresent(cur_cord.x, cur_cord.y) == false)
            robot->MoveForward();
        else if (dir == 'E' && paths[i].second == 'N' && maze.NorthWallPresent(cur_cord.x, cur_cord.y) == false){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'E' && paths[i].second == 'S' && maze.SouthWallPresent(cur_cord.x, cur_cord.y) == false){
            robot->TurnRight(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'E' && paths[i].second == 'W'){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        
        if (cur_cord.x == robot->get_x() && cur_cord.y == robot->get_y()){
            explored.clear();
            to_do.clear();
            paths.clear();
            parents.clear();
            //fp::API::clearAllColor();
            return false;
        }else{
            maze.MazeDesign(robot->get_x(), robot->get_y(), robot->GetDirection());
            fp::API::setColor(robot->get_x(), robot->get_y(), 'R');
        }
    }
    return true;
    
}
    
    
    /*
    coordinates start_node = cur_node;
    coordinates end_node;
    
    while (!to_do.empty()){
        cur_node = to_do.front(); to_do.pop();
        
        if ((g_x == cur_node.x && g_y == cur_node.y) || maze[cur_node.y][cur_node.x] == 'Goal'){ 
            std::cerr << "Path found!" << std::endl;
            end_node = cur_node;
            flag = 1;
            break; 
        }
        
        //cout << cur_node.x << cur_node.y << endl;
        
        for (auto i : Algorithm::moves){
            coordinates new_node = {cur_node.x + i.x, cur_node.y + i.y};
            
            if (!Checker(new_node, explored)){
                //std::cerr << Checker(new_node, explored) << std::endl;
                continue;   
            }
            
            //std::cerr << new_node.x << " " << new_node.y << std::endl;
            paths.emplace(new_node, cur_node);
            to_do.push(new_node);
            explored.push_back(new_node);
        }
        
    }
    
    if (flag == 0){
        std::cerr << " Path not found..." << std::endl;
        return;
    }
    
    coordinates path = end_node;
    API::setColor(path.x, path.y, 'R');
    std::vector<coordinates> final_route = {path};
    
    while (path != start_node){
        const auto itr = paths.find(path);
        coordinates parent = (*itr).second;
        API::setColor(parent.x, parent.y, 'R');
        final_route.insert(final_route.begin(), parent);
        path = parent;
    } 
    
    coordinates cur = start_node;
    int flag1 = 0;
    
    
    for (auto i : final_route){
        //headed east
        if (i.x - cur.x == 1 && i.y - cur.y == 0){
            if (mouse::GetDirection() == 'E' && API::wallFront()){
                flag1 = 1;
                break;
            }
            else if (LandBasedTracked::GetDirection() == 'E'){
                API::moveForward();
                cur = i;
            }
            
            if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'N' && API::wallRight()){
                flag1 = 1;
                break;
            }
            else if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'N'){
                API::turnRight();
                API::moveForward(); 
                cur = i;
            }
            
            if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'S' && API::wallLeft()){
                flag1 = 1;
                break;
            }
            else if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'N'){
                API::turnLeft();
                API::moveForward(); 
                cur = i;
            }
        }
        //headed west
        if (i.x - cur.x == -1 && i.y - cur.y == 0){
            if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'W' && API::wallFront()){
                flag1 = 1;
                break;
            }
            else if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'W'){
                API::moveForward();
                cur = i;
            }
            
            if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'N' && API::wallLeft()){
                flag1 = 1;
                break;
            }
            else if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'N'){
                API::turnLefr();
                API::moveForward(); 
                cur = i;
            }
            
            if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'S' && API::wallRight()){
                flag1 = 1;
                break;
            }
            else if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'S'){
                API::turnRight();
                API::moveForward(); 
                cur = i;
            }
        }
        //headed north
        if (i.x - cur.x == 0 && i.y - cur.y == 1){
            if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'N' && API::wallFront()){
                flag1 = 1;
                break;
            }
            else if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'N'){
                API::moveForward();
                cur = i;
            }
            
            if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'W' && API::wallRight()){
                flag1 = 1;
                break;
            }
            else if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'W'){
                API::turnRight();
                API::moveForward(); 
                cur = i;
            }
            
            if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'E' && API::wallLeft()){
                flag1 = 1;
                break;
            }
            else if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'E'){
                API::turnLeft();
                API::moveForward(); 
                cur = i;
            }
        }
        //headed south
        if (i.x - cur.x == 0 && i.y - cur.y == -1){
            if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'S' && API::wallFront()){
                flag1 = 1;
                break;
            }
            else if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'S'){
                API::moveForward();
                cur = i;
            }
            
            if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'E' && API::wallRight()){
                flag1 = 1;
                break;
            }
            else if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'E'){
                API::turnRight();
                API::moveForward(); 
                cur = i;
            }
            
            if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'W' && API::wallLeft()){
                flag1 = 1;
                break;
            }
            else if (LandBasedTracked(name, cur.x, cur.y)::GetDirection() == 'W'){
                API::turnLeft();
                API::moveForward(); 
                cur = i;
            }
        }
    
    if (flag1 == 1){
        Solve();
    }
    else{
        std::cerr << "Goal reached!" << std::endl;
        return;
    }
}

}
*/
/*
int main(int argc, char **argv)
{
    cerr << "please input the start node:" <<endl;
    coordinates s;
    cin >> s.x >> s.y;
    
    cerr << "please input the goal node:" << endl;
    coordinates g ;
    cin >> g.x >> g.y;
    maze[g.y][g.x] = 'G';
    
    vector<coordinates> target;
    target.push_back(s);
    target.push_back(g);
    
    cout << BFS(target) << endl;
    
	return 0;
}
*/