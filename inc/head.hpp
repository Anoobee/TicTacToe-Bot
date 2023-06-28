// Declaration file

#ifndef _UI_HPP
#define _UI_HPP

#include <iostream>
#include <vector>


template <class T>
void display(std::vector<T> &v);
bool win(std::vector<int> &v);
bool draw(std::vector<int> &v);
int MoveGenerator(std::vector<int> vec);
int play();

#endif  //_GRID_HPP