#include "headers/sense.h"

using namespace std;

// OPTIMIZATION: Pass larger variables by reference
vector< vector <float> > sense(char color, vector< vector <char> > &grid, vector< vector <float> > &beliefs,  float p_hit, float p_miss) 
{
	// OPTIMIZATION: Is the newGrid variable necessary?
  	// Could the beliefs input variable be updated directly?
  	int height, width;

	height = grid.size();
	width = grid[0].size();

	for (int i=0; i < height; ++i) {
		for (int j=0; j < width; ++j) {
			// remove the cell variable since not needed
			if (grid[i][j] == color) {
				// update the belief vector instead of creating new variable
				beliefs[i][j] = beliefs[i][j] * p_hit;
			}
			// remove the extra if statement since not needed
			else {
				// update the belief vector instead of creating new variable
				beliefs[i][j] = beliefs[i][j] * p_miss;
			}
		}
	}
	return beliefs;
}