/** 
 *  @file    util.hpp
 *  @author  Harith Neralla
 *  @date    7/8/2017  
 *  @version 1.0 
 *  
 *  @brief Implementation of directed graphs.
 */

#ifndef util_hpp
#define util_hpp

/**
*   @brief  Stop the program.
*/
void stop();

/**
*   @brief  Reads graph contents from input file. 
*  
*   @param  fileName: string
*   @return newly updated graph 
*/ 
Graph read(std::string fileName);

#endif /* util_hpp */

