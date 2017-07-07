#ifndef util_hpp
#define util_hpp

#include "heap.hpp"
#include <string>

// Stops program
void stop();

// Reads input file
Heap read(Heap heap, std::string fileName); 

#endif /* util_hpp */

