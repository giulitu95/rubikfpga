#ifndef CUBE_H
#define CUBE_H

#define WHITE	0
#define BLUE	1
#define RED		2
#define GREEN	3
#define ORANGE	4
#define YELLOW	5

#define UP		0
#define DOWN	1
#define LEFT	2
#define RIGHT	3
#define FRONT	4
#define BACK	5

/*
CLOCKWISE			--> 0
COUNTERCLOCKWISE	--> 1
*/

class Cube {
	const int N = 3;
private:
	/* Face Matrix */
	int** up;
	int** down;
	int** front;
	int** back;
	int** left;
	int** right;

	void sideRotation(int** matrix, bool direction);
public:
	
	Cube(); /* Input from file*/

	/* Face rotation*/
	void loadCube();
	void frontRotation(bool direction);
	void rightRotation(bool direction);
	void leftRotation(bool direction);
	void downRotation(bool direction);
	void upRotation(bool direction);
	void backRotation(bool direction);
	void mashupCube(int moves);

	/* Print utils */

	//Print all the cube
	void printCube();
	//Convert from int to color for print on console
	void colorDecoder(int color);
	//Search in the cube all the blocks with the specified color
	void printColorPosition(int color);

	/* Search functions */
	void findEdge(int color1, int color2, int &x, int &y, int &f);
	void nearEdge(int actualx, int actualy, int actualf, int &nearx, int &neary, int &nearface);
	void findAngle(int color1, int color2, int color3, int &x, int &y, int &f);
	void nearAngle(int actualx, int actualy, int actualface, int &nearx1, int &neary1, int &nearface1, int &nearx2, int &neary2, int &nearface2);

	/* */
	int** getFace(int face);
};
#endif;