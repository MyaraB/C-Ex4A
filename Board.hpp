#pragma once
#include <set>
#include <map>
#include "City.hpp"
#include "Color.hpp"
namespace pandemic
{
    class Board
    {
        static std::map<City, std::set<City>> connections;
        std::map<City, int> disease_lvl;
        std::set<City> research_stations;

    public:
        Board();
        int& operator[](City city);
        void remove_cures(){}
        ~Board();
        bool is_clean();

        friend std::ostream &operator<<(std::ostream &out, Board &b);
    };
}