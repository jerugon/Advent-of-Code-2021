/*-------------------------------------------*/
/*    Advent of Code 2021 - Day 2: Dive!     */
/*   https://adventofcode.com/2021/day/2     */
/*-------------------------------------------*/

#include <iostream> // std::cout, std::endl
#include <fstream>  // std::ifstream
#include <list>     // std::list

/* Returns the product of horizontal and vertical
 * coordinates after following the planned course */
int part1()
{
    std::ifstream file("input.txt");
    std::string direction;
    int value, x = 0, y = 0;

    while(file >> direction >> value)
    {
        if("down" == direction)
            y += value;
        
        else if("up" == direction)
            y -= value;
        
        else x += value;
    }

    return x * y;
}

/* Returns the product of horizontal and vertical
 * coordinates after following the planned course */
int part2()
{
    std::ifstream file("input.txt");
    std::string direction;
    int value, x = 0, y = 0, aim = 0;

    while(file >> direction >> value)
    {
        if("down" == direction)
            aim += value;
        
        else if("up" == direction)
            aim -= value;
        
        else
        {
            x += value;
            y += aim * value;
        } 
    }

    return x * y;
}

int main()
{
    std::cout << part1() << std::endl << part2() << std::endl;
    return 0;
}