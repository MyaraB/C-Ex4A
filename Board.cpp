#include <map>
#include "Board.hpp"
#include <iostream>

using namespace std;
namespace pandemic{


int b = 0;
Board::Board(){}
Board::~Board(){}
bool Board::is_clean(){return true;}
ostream &operator<<(std::ostream &out, Board &b){return out;};
int& Board::operator[](City city){return b;}
};