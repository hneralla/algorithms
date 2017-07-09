/** 
*  @file 	util.hpp   
*  @author  Harith Neralla
*  @date    7/8/2017  
*  @version 1.0 
*  
*  @brief Implementation of min-heap.
*/

#ifndef util_hpp
#define util_hpp

#include "heap.hpp"

/**
*   @brief  Stop the program.
*/  
void stop();

/**
*   @brief  Reads heap contents from input file. 
*  
*   @param  Heap object and input file name.
*   @return newly updated heap 
*/ 
Heap read(Heap heap, std::string fileName); 

#endif /* util_hpp */

