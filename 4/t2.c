#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "imgops.h"


void draw_rectangle( uint8_t array[], 
		          unsigned int cols, 
		          unsigned int rows, 
		          int x,
		          int y,
		          int rect_width,
		          int rect_height,
		          uint8_t color ) {
	// w & h positive (right down)
	// w & h negative (left up)
	// x + (y*width) == pixel of the starting point

	// set_pixel assertion 'x < cols' failed

	uint8_t start = x+(y*rect_width);

	
	if (rect_width > 0 && rect_height > 0) {
		for (int i = y; i < y + rect_height; i++) {
				for (int j = x; j < x + rect_width; j++) {
					//so it doesn't fill the middle of rectangle
					if (j == x || j == x + rect_width - 1) {
						
						
						if (j < cols && i < rows) {
							set_pixel(array, cols, rows, j, i, color);
							
						}
					}
					if (i == y || i == y + rect_height - 1) {
						
						if (j < cols && i < rows) {
							set_pixel(array, cols, rows, j, i, color);	

						}
					}					
				}
		}
	}
			
	
	if (rect_width < 0 && rect_height < 0) {

		for (int i = y; i > y + rect_height; i--) {
			for (int j = x; j > x + rect_width; j--) {
				if ( j == x || j == x + rect_width + 1) {
					if ( j < cols && i < rows) {
						set_pixel(array, cols, rows, j, i, color);
					}
 				}
 				if ( i == y || i == y + rect_height + 1) {
 					if ( j < cols && i < rows) {
 						set_pixel(array, cols, rows, j, i, color);
 					}
 				}

			}
		}
	}
	if (rect_width < 0 && rect_height > 0) {
		for (int i = y; i < y + rect_height; i++) {
			for (int j = x; j > x + rect_width; j--) {
				if (j < cols && i < rows) {
					if ( j == x || j == x + rect_width +1) {
						set_pixel(array, cols, rows, j, i, color);
					}
					if (i == y || i == y + rect_height -1) {
						set_pixel(array, cols, rows, j, i, color);
					}
				}
			} 
		}
	}

	if (rect_width > 0 && rect_height < 0) {
		for (int i = y; i > y + rect_height; i--) {
			for (int j = x; j < x + rect_width; j++) {
				if ( j < cols && i < rows) {
					if ( j == x || j == x + rect_width-1) {
						set_pixel(array, cols, rows, j, i, color);
					}
					if (i == y || i == y + rect_height +1) {
						set_pixel(array, cols, rows, j, i, color);
					}
				}
			}
		}
	}

}
		

			// start from left top corner like the positive cases and do the same
			/* for width < 0 height < 0
			y = y + rect_height +1;
			x = x + rect_width +1;
			int width = abs(rect_width);
			int height = abs(rect_height);

			draw_rectangle(array, cols, rows, x, y, width, height, color);

			for width < 0 height > 0
			y = y;
			x = x + rect_height; +1
			int width = abs(rect_width);

			for width > 0 height < 0
			y = y + rect_height +1
			x = x
			int height = abs(rect_height) 
			*/
/*
	if (rect_width < 0 && rect_height < 0) {
		y = y + rect_height + 1;
		x = x + rect_width + 1;
		int width = abs(rect_width);
		int height = abs(rect_height);

		draw_rectangle(array, cols, rows, x, y, width, height, color);
	}
	if (rect_width < 0 && rect_height > 0) {
		x = x + rect_height +1;
		int width = abs(rect_width);

		draw_rectangle(array, cols, rows, x, y, width, rect_height, color);
	}
	if ( rect_width > 0 && rect_height < 0) {
		y = y + rect_height +1;
		int height = abs(rect_height);

		draw_rectangle(array, cols, rows, x, y, rect_width, height, color);
	}

}
*/