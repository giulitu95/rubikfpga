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

private:
	const int N = 3;

	/* Face Matrix */
	int** up;
	int** down;
	int** front;
	int** back;
	int** left;
	int** right;

	void sideRotation(int** matrix, bool direction);

public:
	Cube(); 

	/* Input from file*/
	void loadCube();

	/* Face rotation*/
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
	//Convert from int to color and print on console
	void colorDecoder(int color);
	//Search in the cube all the blocks with the specified color
	void printColorPosition(int color);
	//Convert from int to face name and print on console
	void faceDecoder(int face);

	/* Search functions */
	//Search an edge with color1 near another with color2
	void findEdge(int color1, int color2, int &x, int &y, int &f);
	//Search an angle with color1 near another with color2 and color3
	void findAngle(int color1, int color2, int color3, int &x, int &y, int &f);

	/* Face Navigation Utils */
	//Returns a pointer to the wanted face matrix
	int** getFace(int face);
	//Returns the coordinates and the face of the edge near the given one
	void nearEdge(int actualx, int actualy, int actualf, int &nearx, int &neary, int &nearface);
	//Returns the coordinates and the faces of the two angles near the given one
	void nearAngle(int actualx, int actualy, int actualface, int &nearx1, int &neary1, int &nearface1, int &nearx2, int &neary2, int &nearface2);
};
#endif;