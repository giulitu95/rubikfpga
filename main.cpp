#include <iostream>
#include <time.h>
#include <fstream>
#include "Cube.h"
#include "Steps.h"

using namespace std;

int main() {
	Cube* c = new Cube();
	c->loadCube();
	c->mashupCube(20);
	c->printCube();
	c->printColorPosition(WHITE);
	system("PAUSE");
}