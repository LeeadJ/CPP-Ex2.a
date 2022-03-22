#include "Notebook.hpp" // (includes: Direction.hpp, iostream, string, stdexcept)
using namespace std;
// The Notebook is restricted to 100 elements.
const int MAX_COL = 100;

namespace ariel{
    void write(unsigned int page,unsigned int row,unsigned int column, Direction dir, string text){
        if(column > MAX_COL){
            throw runtime_error("Column input Exceeds the size Restriction!");
        }
        else if((text.length() > MAX_COL && dir == Direction::Horizontal) || (text.length() + column > MAX_COL && dir == Direction::Horizontal)){
            throw runtime_error("Text input Exceeds the Column size Restriction!");
        }
    }
    void erase(unsigned int page,unsigned int row,unsigned int column, Direction dir,unsigned int len){
        if(column > MAX_COL){
            throw runtime_error("Column input Exceeds the size Restriction!");
        }
        else if((len > MAX_COL && dir == Direction::Horizontal) || (len + column > MAX_COL && dir == Direction::Horizontal)){
            throw runtime_error("Erasing length Exceeds the Column size Restriction!");
        }

    }
    string read(unsigned int page,unsigned int row,unsigned int column, Direction dir,unsigned int len){
        if(column > MAX_COL){
            throw runtime_error("Column input Exceeds the size Restriction!");
        }
        else if((len > MAX_COL && dir == Direction::Horizontal) || (len + column > MAX_COL && dir == Direction::Horizontal)){
            throw runtime_error("Reading length Exceeds the Column size Restriction!");
        }
        return "Function read";
    }
    void show(unsigned int page){

    }
}