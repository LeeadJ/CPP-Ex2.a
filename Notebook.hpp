#include<iostream>
#include "Direction.hpp"
#include<string>
#include <stdexcept>
using namespace std;

namespace ariel{
    class Notebook{
    public:
    
    static void write(int page, int row, int column, Direction dir, string const &text);
    static void erase(int page, int row, int column, Direction dir, int len);
    static string read(int page, int row, int column, Direction dir, int len);
    void show(int page);
    };
    
}