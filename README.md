# A_Star_Search_cpp

A* Search Algorithm to find path between 2 points in ASCII data.

## Summary

The program reads a 2D matrix from a file and stores it in a std::vector and is parsed to change it to required format.
0, 1, 0, 0, 0, 0, 0, 0, 0,

0, 1, 0, 0, 0, 0, 0, 0, 0,

0, 1, 0, 0, 0, 0, 0, 0, 0,

0, 1, 0, 0, 0, 0, 0, 0, 0,

0, 0, 0, 0, 1, 0, 0, 0, 0,

The A* algorithm finds a path from the start node to the end node by checking for open neighbors of the current node, computing a heuristic for each of the neighbors, 
and adding those neighbors to the list of open nodes to explore next. 
The next node to explore is the one with the lowest total cost + heuristic (g + h). This process is repeated until the end is found, 
as long as there are still open nodes to explore. 

