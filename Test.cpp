#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;

TEST_CASE("country insert"){
Board board;
CHECK_EQ(board[City::Algiers],0);
CHECK_EQ(board[City::Atlanta],0);
CHECK_EQ(board[City::Baghdad],0);
CHECK_EQ(board[City::Bangkok],0);
CHECK_EQ(board[City::Beijing],0);
CHECK_EQ(board[City::Bogota],0);
CHECK_EQ(board[City::Lagos],0);
CHECK_EQ(board[City::Riyadh],0);
CHECK_EQ(board[City::HongKong],0);
CHECK_EQ(board[City::HongKong]=2,2);
CHECK_EQ(board[City::HongKong]=0,0);
CHECK_EQ(board.is_clean(),true);
   
}

TEST_CASE("basic player methods + Medic power"){
Board board;
Medic player(board,HongKong);
CHECK_THROWS(player.drive(Miami));
CHECK_NOTHROW(player.drive(Taipei));

CHECK_THROWS(player.build());
player.take_card(Taipei);
CHECK_NOTHROW(player.build());

player.take_card(SaoPaulo);
CHECK_THROWS(player.fly_direct(Bogota));
CHECK_NOTHROW(player.fly_direct(SaoPaulo));

CHECK_THROWS(player.fly_direct(Istanbul));
player.take_card(SaoPaulo);
CHECK_NOTHROW(player.fly_direct(SaoPaulo));

player.take_card(SaoPaulo);
CHECK_THROWS(player.fly_shuttle(Taipei));
player.build();
CHECK_NOTHROW(player.fly_shuttle(Taipei));

board[Taipei]=5; 
player.treat(Taipei);//Medic power
CHECK_EQ(board[Taipei], 0);
}

TEST_CASE("Operations expert power test + discover cure test"){
Board board;
OperationsExpert player(board,HongKong);

board[HongKong]=5;
player.take_card(Osaka).take_card(Manila).take_card(Jakarta).take_card(Beijing).take_card(Shanghai);
player.build();
player.take_card(HongKong);
player.discover_cure(Red);
player.treat(HongKong);
CHECK_EQ(board[HongKong],0);
}




