# Tower-Puzzle
Solver for Runescape's master clue scroll tower puzzle

Link to wiki explaining the puzzle
http://runescape.wikia.com/wiki/Treasure_Trails/Guide/Towers?file=Towers_puzzle_scroll_interface.png#General_strategies

Usage:
Input the visible towers found on the edge of the puzzle.
This program assumes they are read left to right top to bottom.
EX:
2 3 2 1 2 3 2 1 4 3 3 2 4 2 1 2 2 3 4 1 

Would be the input for the example linked above, when formatted it would look like:

2   3   2   1   2   
3		            2
1		            4
3		            3
2		            4
2		            1
2   2   3   4   1 

Output:
Output is a 5x5 grid of a possible solved puzzle solution. If multiple exist, they will all be printed, seperated by empty lines. If no solution exists, nothing will be outputed.
EX:

2 1 3 5 4 
5 4 1 3 2 
1 2 5 4 3 
3 5 4 2 1 
4 3 2 1 5 
