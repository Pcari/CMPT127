#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "imgops.h"
#include <string.h>



void life( uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows ) {
//uint8_t
	//uint8_t* temp = malloc(cols * rows * sizeof(uint8_t));
	uint8_t* temp = malloc(cols * rows * sizeof(array[0]));
	if (temp == NULL) {
		free(temp);
	}
	//set all values of temp to 0
	//array[0]
	memset(temp, 0, cols * rows * sizeof(array[0]));
	// 8 cells around 
	
	
	int neighbours = 0;

	for (int py = 0; py < rows; py++) {
		for (int px = 0; px < cols; px++) {

			//cover all edge cases, then top row, bot row, left, right, then the rest
			//torus topology -> so they must be wrapped around

			int topLeftX, topLeftY, topX, topY, topRightX, topRightY, leftX, leftY, rightX, rightY,
			bottomLeftX, bottomLeftY, bottomX, bottomY, bottomRightX, bottomRightY = 0;

			topLeftX = (px-1+cols)%cols;
			topLeftY = (py-1+rows)%rows; 
			topX = px;
			topY = (py-1+rows)%rows;
			topRightX = (px+1+cols)%cols;
			topRightY = (py-1+rows)%rows;
			leftX = (px-1+cols)%cols;
			leftY = py;
			rightX = (px+1+cols)%cols;
			rightY = py;
			bottomLeftX = (px-1+cols)%cols;
			bottomLeftY = (py+1+rows)%rows;
			bottomX = px;
			bottomY = (py+1+rows)%rows;
			bottomRightX = (px+1+cols)%cols;
			bottomRightY = (py+1+rows)%rows;

			if (get_pixel(array, cols, rows, topLeftX, topLeftY) > 0) {
				neighbours++;
			}
			if (get_pixel(array, cols, rows, topX, topY) > 0) {
				neighbours++;
			}
			if (get_pixel(array, cols, rows, topRightX, topRightY) > 0) {
				neighbours++;
			}
			if (get_pixel(array, cols, rows, leftX, leftY) > 0) {
				neighbours++;
			}
			if (get_pixel(array, cols, rows, rightX, rightY) > 0) {
				neighbours++;
			}
			if (get_pixel(array, cols, rows, bottomLeftX, bottomLeftY) > 0) {
				neighbours++;
			}
			if (get_pixel(array, cols, rows, bottomX, bottomY) > 0) {
				neighbours++;
			}
			if (get_pixel(array, cols, rows, bottomRightX, bottomRightY) > 0) {
				neighbours++;
			}
			
/*
			if (get_pixel(array, cols, rows, px, py) != 0) {
				if (neighbours == 2 || neighbours == 3) {
					
					set_pixel(temp, cols, rows, px, py, 255);
				} else {
					set_pixel(temp, cols, rows, px, py, 0);
				}
			}

			if (get_pixel(array, cols, rows, px, py) == 0) {
				if (neighbours == 3) {
					//temp[pos] = 255;
					set_pixel(temp, cols, rows, px, py, 255);
				} else {
					//temp[pos] = 0;
					set_pixel(temp, cols, rows, px, py, 0);
				}
			}
*/			


			//1. any live cell with fewer than two live nighbours dies
			//2. any live cell with 2 or 3 live neighbours live on to the next generation
			//3. any live cell with more than 3 live neighbours dies
			//4. any dead cell with exactly three live neighbours becomes a live cell

			// live cell
			//array[pos] != 0

			int currentPixel = get_pixel(array, cols, rows, px, py);
			if (neighbours == 3) {
				set_pixel(temp, cols, rows, px, py, 255);
			}
			if (neighbours == 2 && currentPixel > 0) {
				set_pixel(temp, cols, rows, px, py, 255);
			}
			if (neighbours < 2 || neighbours > 3) {
				set_pixel(temp, cols, rows, px, py, 0);
			}
			
			

/*
			if (get_pixel(array, cols, rows, px, py) != 0) {
				if (sum == 2 || sum == 3) {
					//temp[pos] = 255;
					set_pixel(temp, cols, rows, px, py, 255);
				} else {
					// fewer than two live neighbours or more than 3 -> dies
					//temp[pos] = 0;
					set_pixel(temp, cols, rows, px, py, 0);
				}
			}
			//dead cell
			//array[pos] == 0
			
			if (get_pixel(array, cols, rows, px, py) == 0) {
				if (sum == 3) {
					//temp[pos] = 255;
					set_pixel(temp, cols, rows, px, py, 255);
				} else {
					//temp[pos] = 0;
					set_pixel(temp, cols, rows, px, py, 0);
				}
			}
			*/
			//reset neighbour variables to 0


			neighbours = 0;

		}
	}
	memset(array, 0, sizeof(array[0]));
	for (int i = 0; i < rows*cols; i++) {
		array[i] = temp[i];
	}
	free (temp);
}