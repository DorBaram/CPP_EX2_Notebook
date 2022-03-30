/**
 * Notebook Exercise
 * 
 * Author: Dor Baram
 * Since : 2022-03
 */

#include "Direction.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct defaultChar{
    char d = '_';
};

namespace ariel{
    const int MAX_ROW = 100;
    const int SHOW = 40;
    int const MIN_C = 32;
    int const MAX_C = 125;
    void validator(int page,  int row,  int col, Direction dire ,int strl ,int pos);
    class Notebook
    {
        private:
        unordered_map<int,unordered_map<int,defaultChar[MAX_ROW]>> notebook;
        public:
        Notebook();
        void write(int page,int row, int col, Direction dire, string const &str);
        string read( int page,  int row,  int col, Direction dire, int amount);
        void erase( int page,  int row,  int col, Direction dire, int amount);
        void show( int page);
        
    };
}