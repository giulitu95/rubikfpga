#ifndef STEPS_H
#define STEPS_H
#include"Cube.h"
#include<list>

using namespace std;

class Steps {
private:
	Cube* cube; //Istance of a cube
	list<char*> steps; // List that contains all the rotation done throw the standard rappresentation
	
	/*
	Functions that allow to roatate a face and update the steps list at the
	same time.
	There are also the methods for rotate 2 time the same face
	*/
	void up(int i);
	void down(int i);
	void right(int i);
	void left(int i);
	void front(int i);
	void back(int i);
	void up2(int i);
	void down2(int i);
	void right2(int i);
	void left2(int i);
	void front2(int i);
	void back2(int i);

public:
	//Constructor of this class, the constructor need a instance of a cube
	Steps(Cube* cube);
	//Return the steps list
	list<char*> getSteps(); 
	//Method that create the first white cross with the pieces in the right position
	void step1(); 
	//Method that complete all the white face with the piece in the right position
	void step2();
	//Method that complete the second layer of the cube 
	void step3();
	//Method that create the yellow cross, in this steps the pieces don't need to be in the right position
	void step4();
	//Method that complete the yellow face, the piece don't need to be in the right position
	void step5();
	//Method that put the angle of the yellow face in the right position
	void step6();
	//Method that finalize the cube putting the edge of the last face in the correct position
	void step7();
	//Method that print the steps currently done
	void printSteps();

	//Used for debugging.
	//Get a step number. It mash up the cube and solves until that step for cycles times. 
	//Return on console some diagnostic informations if the solution isn't correct.
	void verifyStep(int stepNo, int cycles);
};
#endif;
