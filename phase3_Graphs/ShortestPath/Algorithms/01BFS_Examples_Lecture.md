**Question: Generate bridge b/w Islands**

Given an MxN grid with three marked components (1, 2, and 3) and empty cells, find the minimum number of empty cells that need to be converted to bridges so that all three components are connected.



### Soln

**HINT** \
There'll be a central point X in the grid such that the sum of its distances to all three components (1, 2, and 3) is minimized. \
This point will indicate the minimum number of empty cells that need to be converted to bridges to connect all components.

STEPS
- Perform BFS from each component (1, 2, and 3) to record distances to all cells.
- Iterate through all cells to find the one with the minimum sum of distances from the three components.

\
This is a **0-1 BFS problem** because traversing within a component has a cost of 0, while moving to an empty cell has a cost of 1.

