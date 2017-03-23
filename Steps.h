#ifndef STEPS_H
#include"Cube.h"
#include<list>

using namespace std;
class Steps {
private:
	Cube cube;
	list<char*> steps;
public:
	Steps(Cube cube);
	void step1();
	void step2();
	void step3();
	void step4();
	void step5();
	void step6();
};
#endif;
