#include "Player.hpp"

using namespace std;
using namespace pandemic;

Player& Player::drive(City geo_location){return *this;}
Player& Player::fly_direct(City geo_location){return *this;}
Player& Player::fly_charter(City geo_location){return *this;}
Player& Player::fly_shuttle(City geo_location){return *this;}
Player& Player::build(){return *this;}
Player& Player::discover_cure(Color color){return *this;}
Player& Player::treat(City geo_location){return *this;}
Player& Player::take_card(City geo_location){return *this;}     
    