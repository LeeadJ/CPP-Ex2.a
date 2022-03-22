#include "Notebook.hpp" // (includes: Direction.hpp, iostream, string, stdexcept)

// The Notebook is restricted to 100 elements.
const int MAX_COL = 100;

namespace ariel{
    void Notebook::write(unsigned int page,unsigned int row,unsigned int column, Direction dir, string text){
        if(column > MAX_COL){
            throw runtime_error("Column input Exceeds the size Restriction!");
        }
        if((text.length() > MAX_COL && dir == Direction::Horizontal) || (text.length() + column > MAX_COL && dir == Direction::Horizontal)){
            throw runtime_error("Text input Exceeds the Column size Restriction!");
        }
    }
    void Notebook::erase(unsigned int page,unsigned int row,unsigned int column, Direction dir,unsigned int len){
        if(column > MAX_COL){
            throw runtime_error("Column input Exceeds the size Restriction!");
        }
        if((len > MAX_COL && dir == Direction::Horizontal) || (len + column > MAX_COL && dir == Direction::Horizontal)){
            throw runtime_error("Erasing length Exceeds the Column size Restriction!");
        }

    }
    string Notebook::read(unsigned int page,unsigned int row,unsigned int column, Direction dir,unsigned int len){
        if(column > MAX_COL){
            throw runtime_error("Column input Exceeds the size Restriction!");
        }
        if((len > MAX_COL && dir == Direction::Horizontal) || (len + column > MAX_COL && dir == Direction::Horizontal)){
            throw runtime_error("Reading length Exceeds the Column size Restriction!");
        }
        return "Function read";
    }
    void Notebook::show(unsigned int page){

    }
}