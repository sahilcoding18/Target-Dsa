/*
1536. Minimum Swaps to Arrange a Binary Grid
Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3

Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.
*/
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
       int n = grid.size();
        vector<int> rows; 
        int count=0;
        for(int i=0;i<n;i++)
        {
            count=0;
            for(int j=n-1;j>=0;j--)
            {
               if(grid[i][j]!=0)
                   break;
               else
                   count++;
            }
            rows.push_back(count);
        }
        int swaps=0;
        for(int i=0;i<n;i++)
        {
            int target=n-i-1;
            int j=i;
            while(j<n and rows[j]<target)
            {
                j++;
            }
            if(j==n)
            {
                return -1;
            }
            swaps+=j-i;
            rows.erase(rows.begin()+j);
            rows.insert(rows.begin()+i,target);
        }
        return swaps;
    }
};