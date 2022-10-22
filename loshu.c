#include <stdio.h>
#include <stdbool.h>
#include <time.h>


bool isLoshu(int grid[3][3]){
	int targetSum = 0;
	for(int i = 0; i < 3; i++){
		targetSum += grid[i][0];
	}
	int tempSum = 0;
	// horizontal
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			tempSum += grid[i][j];
		}
		if(tempSum != targetSum){
			return false;
		}
		tempSum = 0;
	}
	// vertical
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			tempSum += grid[j][i];
		}
		if(tempSum != targetSum){
			return false;
		}
		tempSum = 0;
	}
	// first horizontal
	tempSum += grid[0][0] + grid[1][1] + grid[2][2];
	if(tempSum != targetSum){
		return false;
	}
	tempSum = 0;	
	// other horizontal
	tempSum += grid[2][0] + grid[1][1] + grid[0][2];
	if(tempSum != targetSum){
		return false;
	}
	return true;
}

void randomizeGrid(int grid[3][3]){
	int used[9];
	for(int i = 0; i < 9; i++){
		used[i] = 0;
	}
	int index = 0;
	int temp;
	bool found;
	while(index < 9){
		temp = 1+(rand()%9);
		found = false;
		for(int i = 0; i < index; i++){
			if(temp == used[i]){
				found = true;
			}
		}
		if(!found){
			used[index] = temp;
			index++;
			found = true;
		}
	}
	index = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			grid[i][j] = used[index];
			index++;
		}
	}
}

int main(){

	time_t t;
	srand((unsigned)time(&t));
	// testing given lo shu square
	// int gaming[3][3];
	// gaming[0][0] = 4;
	// gaming[0][1] = 9;
	// gaming[0][2] = 2;
	// gaming[1][0] = 3;
	// gaming[1][1] = 5;
	// gaming[1][2] = 7;
	// gaming[2][0] = 8;
	// gaming[2][1] = 1;
	// gaming[2][2] = 6;
	// bool tf = isLoshu(gaming);
	// if(tf){
	// 	printf("woooo");
	// 	return 1;
	// } else{
	// 	printf("bad");
	// 	return 0;
	// }


	// init grid
	int grid[3][3];
	// start off by randomizing at least once
	randomizeGrid(&grid);
	int iterations = 1;
	// while the grid is not a loshu square
	while(!isLoshu(grid)){
		// make new grid
		randomizeGrid(&grid);
		iterations++;
	}
	printf("Generated a Lo Shu Magic Square in %i iterations.\n", iterations);
	for(int i = 0; i < 3; i++){
		printf("[ ");
		for(int j = 0; j < 3; j++){
			printf("%i ", grid[i][j]);
		}
		printf("]\n");
	}
	return 0;
}