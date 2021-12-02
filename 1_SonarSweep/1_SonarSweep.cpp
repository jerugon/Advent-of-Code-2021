/*-------------------------------------------*/
/* Advent of Code 2021 - Day 1: Sonar Sweep  */
/*   https://adventofcode.com/2021/day/1     */
/*-------------------------------------------*/

#include <iostream> // std::cout, std::endl
#include <fstream>  // std::ifstream
#include <list>     // std::list

/* Returns the number of times a depth measurement
 * increases from the previous measurement */
int part1()
{
    std::ifstream file("input.txt");
    int depth, previous_depth = 0;
    int increases = 0;

    while(file >> depth)
    {
        if(depth > previous_depth) ++increases;
        previous_depth = depth;
    }

    return increases - 1;
}

/* Returns the number of times a depth measurement 
 * increases from the third-to-last previous measurement */
int part2()
{
    std::ifstream file("input.txt");
    std::list<int> window;
    int depth, increases = 0;

    /* Set the window to the first three values */
    file >> depth; window.push_back(depth);
    file >> depth; window.push_back(depth);
    file >> depth; window.push_back(depth);

    while(file >> depth)
    {
        if(depth > window.front())
            ++increases;

        window.pop_front();
        window.push_back(depth);   
    }

    return increases;
}

int main()
{
    std::cout << part1() << std::endl << part2() << std::endl;
    return 0;
}