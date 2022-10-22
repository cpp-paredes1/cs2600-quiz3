#include <stdio.h>
#include <stdbool.h>

time_t t;
bool isLoshu(int grid[3][3]){

}
void randomizeGrid(int * grid[3][3]){
	int current = 1;
	while(current < 10){
		x = rand()%3;
		y = rand()%3;
		if(grid[x][y] != 0){
			grid[x][y] = current;
			current++;
		}
	}
}

int main(){
	srand((unsigned)time(&t));
	// init grid
	int grid[3][3];
	// make all grid entries 0
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			grid[i][j] == 0;
		}
	}
	int iterations = 0;
	// while the grid is not a loshu square
	while(!isLoshu(grid)){
		// make all grid entries 0
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				grid[i][j] == 0;
			}
		}
		// randomize grid
		randomizeGrid(&grid);
		iterations++;
	}
	printf("%i", iterations);
}