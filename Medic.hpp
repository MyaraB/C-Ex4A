#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{

    class Medic: public Player {

        public:
            Medic(Board& board, City geo): Player(board, geo, "Medic") {}
            Player& treat(City geo);
    };
}