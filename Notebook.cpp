#include "Notebook.hpp" // (includes: Direction.hpp, iostream, string, stdexcept)
using namespace std;
// The Notebook is restricted to 100 elements.
const int MAX_COL = 100;

namespace ariel{
    void write(unsigned int page,unsigned int row,unsigned int column, Direction dir, string text){
        if(column > MAX_COL){
            throw runtime_error("Column input Exceeds the size Restriction!");
        }
        else if(text.length() > MAX_COL && dir == Direction::Horizontal){
            throw runtime_error("Text input Exceeds the Column size Restriction!");
        }
        else if((text.length() > column && dir == Direction::Horizontal) || (text.length() > row && dir == Direction::Vertical)){
            throw runtime_error("Text input Exceeds the Column/Row input!");
        }
    }
    void erase(unsigned int page,unsigned int row,unsigned int column, Direction dir,unsigned int len){
        if(column > MAX_COL){
            throw runtime_error("Column input Exceeds the size Restriction!");
        }
        else if(len > MAX_COL && dir == Direction::Horizontal){
            throw runtime_error("Erasing length Exceeds the Column size Restriction!");
        }
        else if((len > column && dir == Direction::Horizontal) || (len > row && dir == Direction::Vertical)){
            throw runtime_error("Erasing length Exceeds the Column/Row input!");
        }

    }
    string read(unsigned int page,unsigned int row,unsigned int column, Direction dir,unsigned int len){
        if(column > MAX_COL){
            throw runtime_error("Column input Exceeds the size Restriction!");
        }
        else if(len > MAX_COL && dir == Direction::Horizontal){
            throw runtime_error("Reading length Exceeds the Column size Restriction!");
        }
        else if((len > column && dir == Direction::Horizontal) || (len > row && dir == Direction::Vertical)){
            throw runtime_error("Reading length Exceeds the Column/Row input!");
        }
        return "Function read";
    }
    void show(unsigned int page){

    }
}