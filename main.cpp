#include <iostream>
#include <time.h>
#include <fstream>
#include "Cube.h"
#include "Steps.h"

using namespace std;

int main() {
	Cube* c = new Cube();
	Steps* s = new Steps(c);
	c->loadCube();
	//c->downRotation(0);
	/*
	c->rightRotation(0);
	c->rightRotation(0);
	c->downRotation(1);
	c->rightRotation(0);
	c->rightRotation(0);
	
	c->printCube();
	int whitex;
	int whitey;
	int whiteFace;

	c->findEdge(WHITE, RED, whitex, whitey, whiteFace);
	cout << whitex << endl;
	cout << whitey << endl;
	cout << whiteFace << endl;
	s->step1();
	
	
	s->printSteps();
	cout << endl;
	c->printCube();
	system("PAUSE");
	*/
	s->verifyStep(1, 1000000);
	system ("PAUSE");
}