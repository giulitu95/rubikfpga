#ifndef CUBE_H
#define CUBE_H
/*
WHITE				--> 0
BLUE				--> 1
RED					--> 2
GREEN				--> 3
ORANGE				--> 4
YELLOW				--> 5

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
	void printCube();
	void frontRotation(bool direction);
	void rightRotation(bool direction);
	void leftRotation(bool direction);
	void downRotation(bool direction);
	void upRotation(bool direction);
	void backRotation(bool direction);

	void mashupCube(int moves);

};
#endif;