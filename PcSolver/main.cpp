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
	
	c->mashupCube(100);
	
	s->step1();
	c->printCube();
	
	
	s->printSteps();
	s->step2();
	cout << endl;
	c->printCube();
	system("PAUSE");
	
	/*s->verifyStep(1, 100, 1);
	system ("PAUSE");*/
}