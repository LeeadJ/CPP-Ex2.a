#include<iostream>
#include "Direction.hpp"
#include<string>
#include <stdexcept>
using namespace std;

namespace ariel{
    class Notebook{
    public:
    //using 'unsigned int' because input can NOT be negative.
    void write(unsigned int page,unsigned int row,unsigned int column, Direction dir, string text);
    void erase(unsigned int page,unsigned int row,unsigned int column, Direction dir,unsigned int len);
    string read(unsigned int page,unsigned int row,unsigned int column, Direction dir,unsigned int len);
    void show(unsigned int page);
    };
    
}