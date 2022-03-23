#include "doctest.h"
#include "Notebook.hpp" 
#include "Direction.hpp"
#include<iostream>
#include<string>
#include<stdexcept>

using namespace ariel;

TEST_CASE("Good input"){ // 6 tests
    Notebook nb_test1, nb_test2;
    nb_test1.write(5,5,1,Direction::Horizontal,"Leead");
    CHECK(nb_test1.read(5,5,0,Direction::Horizontal, 7) == "_Leead_");
    nb_test1.erase(5,5,2,Direction::Horizontal, 1);
    CHECK(nb_test1.read(5,5,0,Direction::Horizontal, 7) == "_L~ead_");
    nb_test1.erase(5,5,1,Direction::Horizontal, 5);
    CHECK(nb_test1.read(5,5,0,Direction::Horizontal, 7) == "_~~~~~_");

    nb_test2.write(0,0,0,Direction::Vertical, "Leead");
    CHECK(nb_test2.read(0,0,0,Direction::Vertical, 6) == "Leead_");
    nb_test2.erase(0,0,0,Direction::Vertical, 1);
    CHECK(nb_test2.read(0,0,0,Direction::Vertical, 6) == "~eead_");
    nb_test2.erase(0,0,0,Direction::Vertical, 5);
    CHECK(nb_test2.read(0,0,0,Direction::Vertical, 6) == "~~~~~_");

}

TEST_CASE("Over-writing"){ // 6 tests
    // Initializing the Notebook:
    Notebook nb_test;
    nb_test.write(1, 2, 10, Direction::Horizontal, "Leead");
    //Over-writing Horizontally
    CHECK_THROWS(nb_test.write(1,2,6,Direction::Horizontal,"Test")); 
    CHECK_THROWS(nb_test.write(1,2,10,Direction::Horizontal,"Test")); 
    CHECK_THROWS(nb_test.write(1,2,14,Direction::Horizontal,"Test"));
    //Over-writing Vertically
    CHECK_THROWS(nb_test.write(1,0,10,Direction::Vertical,"Test"));  
    CHECK_THROWS(nb_test.write(1,2,10,Direction::Vertical,"Test"));  
    CHECK_THROWS(nb_test.write(1,6,10,Direction::Vertical,"Test"));  
}
TEST_CASE("Column Input Not in Range [0,100]"){ // 2 tests
    // Initializing the Notebook:
    Notebook nb_test;
    CHECK_THROWS(nb_test.write(1,6,101,Direction::Horizontal,"Leead"));  
    CHECK_THROWS(nb_test.write(1,6,101,Direction::Vertical,"Leead"));
    CHECK_THROWS(nb_test.write(1,6,-1,Direction::Horizontal,"Leead"));  
    CHECK_THROWS(nb_test.write(1,6,-1,Direction::Vertical,"Leead"));  
}
TEST_CASE("Row Input Not in Range [0,-]"){ // 2 tests
    // Initializing the Notebook:
    Notebook nb_test;
    CHECK_THROWS(nb_test.write(1,-1,0,Direction::Horizontal,"Leead"));  
    CHECK_THROWS(nb_test.write(1,-1,0,Direction::Vertical,"Leead"));  
}
TEST_CASE("Page Input Not in Range [0,-]"){ // 2 tests
    // Initializing the Notebook:
    Notebook nb_test;
    CHECK_THROWS(nb_test.write(1,-1,0,Direction::Horizontal,"Leead"));  
    CHECK_THROWS(nb_test.write(1,-1,0,Direction::Vertical,"Leead"));  
}
TEST_CASE("Writing Input Exceeds Column Max Range (100)"){ // 3 tests
    // Initializing the Notebook:
    Notebook nb_test;
    CHECK_THROWS(nb_test.write(1,6,90,Direction::Horizontal,"Leead Jacobowitz"));  
    CHECK_THROWS(nb_test.write(1,6,99,Direction::Horizontal,"LJ")); 
    CHECK_THROWS(nb_test.write(1,6,0,Direction::Horizontal,"MMMMMpppppMMMMMpppppMMMMMpppppMMMMMpppppMMMMMpppppMMMMMpppppMMMMMpppppMMMMMpppppMMMMMpppppMMMMMpppppMMMMMppppp"));    
}
TEST_CASE("Reading length Input Exceeds Column Range [0,100]"){ // 3 tests
    // Initializing the Notebook:
    Notebook nb_test;
    nb_test.write(0,0,94,Direction::Horizontal, "Leead");
    CHECK_THROWS(nb_test.read(0,0,94,Direction::Horizontal,10)); 
    CHECK_THROWS(nb_test.read(0,0,100,Direction::Horizontal,1)); 
    CHECK_THROWS(nb_test.read(0,0,0,Direction::Horizontal,105)); 
       
}
