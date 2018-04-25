/*
#include <stdio.h>
#include <string.h>

int InRectangle(float p[2], float rect[4]);

int main(int argc, char* argv[])
{

  float rect[4] = {1.0, 1.0, 2.0, 2.0 };
 
  // define a point that is inside the rectangle
  float p_in[2] = { 1.5, 1.5 };
 
  // define a point that is outside the rectangle
  float p_out[2] = {2.5, 0.5};
 
  // define a point that is on the edge of the rectangle
  float p_edge[2] = {1.0, 1.0};

  if( InRectangle( p_in, rect ) == 0 )
  {
    puts( "error: should return true for p_in." );
    return 1; // indicate error
  }
 
  // test 2
  if( InRectangle( p_out, rect ) != 0 )
  {
    puts( "error: should return false for p_out." );
    return 1; // indicate error
  }
 
  // test 3
  if( InRectangle( p_edge, rect ) == 0 )
  {
    puts( "error: should return true for p_edge." );
    return 1; // indicate error
  }

  return 0;

}
*/
int InRectangle(float p[2], float rect[4]) {


	float pointX = p[0];
	float pointY = p[1];

	float x1Rect = rect[0];
	float y1Rect = rect[1];
	float x2Rect = rect[2];
	float y2Rect = rect[3];

	if (pointX >= x1Rect && pointX <= x2Rect) {
		if ((pointY >= y1Rect && pointY <= y2Rect) ||
			(pointY <= y1Rect && pointY >= y2Rect)) {
			return 1;		
			} 
	}
		
	
	if (pointX >= x2Rect && pointX <= x1Rect) {
		if ((pointY >= y2Rect && pointY <= y1Rect) ||
			(pointY <= y1Rect && pointY >= y2Rect)) {
		return 1;
		}
	}

	if (pointX <= x1Rect && pointX >= x2Rect) {
		if ((pointY >= y1Rect && pointY <= y2Rect) ||
			(pointY <= y1Rect && pointY >= y2Rect)) {
			return 1;
		}
	}

	if (pointX <= x2Rect && pointX >= x1Rect) {
		if ((pointY >= y2Rect && pointY <= y1Rect) ||
			(pointY <= y2Rect && pointY >= y1Rect)) {
			return 1;
		}
	}

	if (pointY <= y1Rect && pointY >= y2Rect) {
		if ((pointX <= x1Rect && pointX >= x2Rect) ||
			(pointX >= x1Rect && pointX <= x2Rect)) {
			return 1;
		}
	}

	if (pointY <= y2Rect && pointY >= y1Rect) {
		if ((pointX <= x2Rect && pointX >= x1Rect) ||
			(pointX >= x2Rect && pointX <= x1Rect)) {
			return 1;
		}
	}

	if (pointX >= x1Rect && pointX <= x2Rect) {
		if ((pointY <= y1Rect && pointY >= y2Rect) ||
			(pointY <= y2Rect && pointY >= y1Rect)) {
				return 1;
			}
	}

	if (pointX >= x2Rect && pointX <= x1Rect) {
		if ((pointY <= y2Rect && pointY >= y1Rect) ||
			(pointY <= y1Rect && pointY >= y2Rect)) {
			return 1;
		}
	}
	return 0; 

}