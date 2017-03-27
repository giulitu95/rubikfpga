#include <iostream>
#include <time.h>
#include <fstream>
#include <list>
#include "Steps.h"

using namespace std;

Steps::Steps(Cube* cube) {
	this->cube = cube;
}
list<char*> Steps::getSteps() {
	return steps;
}
void Steps::up(int i) {
	cube->upRotation(i);
	if (i == 0) 
		steps.push_back("U");
	
	else
		steps.push_back("U'");
}
void Steps::down(int i) {
	cube->downRotation(i);
	if (i == 0)
		steps.push_back("D");
	else
		steps.push_back("D'");
}
void Steps::right(int i) {
	cube->rightRotation(i);
	if (i == 0)
		steps.push_back("R");
	else
		steps.push_back("R'");
}
void Steps::left(int i) {
	cube->leftRotation(i);
	if (i == 0)
		steps.push_back("L");
	else
		steps.push_back("L'");
}
void Steps::front(int i) {
	cube->frontRotation(i);
	if (i == 0)
		steps.push_back("F");
	else
		steps.push_back("F'");
}
void Steps::back(int i) {
	cube->backRotation(i);
	if (i == 0)
		steps.push_back("B");
	else
		steps.push_back("B'");
}
void Steps::up2(int i) {
	cube->upRotation(i);
	cube->upRotation(i);
	if (i == 0)
		steps.push_back("2U");

	else
		steps.push_back("2U'");
}
void Steps::down2(int i) {
	cube->downRotation(i);
	cube->downRotation(i);
	if (i == 0)
		steps.push_back("2D");
	else
		steps.push_back("2D'");
}
void Steps::right2(int i) {
	cube->rightRotation(i);
	cube->rightRotation(i);
	if (i == 0)
		steps.push_back("2R");
	else
		steps.push_back("2R'");
}
void Steps::left2(int i) {
	cube->leftRotation(i);
	cube->leftRotation(i);
	if (i == 0)
		steps.push_back("2L");
	else
		steps.push_back("2L'");
}
void Steps::front2(int i) {
	cube->frontRotation(i);
	cube->frontRotation(i);
	if (i == 0)
		steps.push_back("2F");
	else
		steps.push_back("2F'");
}
void Steps::back2(int i) {
	cube->backRotation(i);
	cube->backRotation(i);
	if (i == 0)
		steps.push_back("2B");
	else
		steps.push_back("2B'");
}


void Steps::step1() {
	bool count = true;
	int whitex; 
	int whitey;
	int whiteFace;
	cube->findEdge(WHITE, RED, whitex, whitey, whiteFace);
	while (count) {
		switch (whiteFace) {
		case DOWN:
			if (whitex == 0) {
				down(0);
			}
			else if (whitex == 2) {
				down(1);
			}
			else if (whitey == 2) {
				down2(0);
			}
			count = false;
			break;
		case RIGHT:
			if (whitex == 0) {
				front(0);
				count = false;
			}
			else if (whitex == 2) {
				right2(0);
				whitex = 0;
				whiteFace = RIGHT;
			}
			else if (whitey == 0) {
				right(1);
				whitex = 0;
				whiteFace = RIGHT;
			}
			else if (whitey == 2) {
				right(0);
				whitex = 0;
				whiteFace = RIGHT;
			}
			break;
		case FRONT:
			if (whitex == 0) {
				left(0);
				whitex = 0;
				whiteFace = DOWN;
			}
			else if (whitex == 2) {
				right(1);
				whitex = 2;
				whiteFace = DOWN;
			}
			else if (whitey == 0) {
				front(1);
				whitex = 0;
				whiteFace = FRONT;
			}
			else if (whitey == 2) {
				front(0);
				whitex = 0;
				whiteFace = FRONT;
			}
			break;
		case LEFT:
			if (whitex == 2) {
				front(1);
				count = false;
			}
			else if (whitex == 0) {
				left2(0);
				whitex = 2;
				whiteFace = LEFT;
			}
			else if (whitey == 0) {
				left(0);
				whitex = 2;
				whiteFace = LEFT;

			}
			else if (whitey == 2) {
				left(1);
				whitex = 2;
				whiteFace = LEFT;
			}
			break;
		case BACK:
			if (whitex == 0) {
				right(0);
				whitex = 2;
				whiteFace = DOWN;
			}
			else if (whitex == 2) {
				left(1);
				whitex = 0;
				whiteFace = DOWN;

			}
			else if (whitey == 0) {
				up(0);
				whitex = 1;
				whitey = 0;
				whiteFace = RIGHT;
			}
			else if (whitey = 2) {
				down(0);
				whitex = 1;
				whitey = 2;
				whiteFace = LEFT;
			}
			break;
		case UP:
			if (whitex == 0) {
				left(0);
				whitex = 0;
				whiteFace = FRONT;
			}
			else if (whitex == 2) {
				right(1);
				whitex = 2;
				whiteFace = FRONT;
			}
			else if (whitey == 0) {
				back(1);
				whitex = 2;
				whiteFace = RIGHT;
			}
			else if (whitey == 2) {
				front(0);
				whitex = 0;
				whiteFace = RIGHT;
			}
			break;
		}
	}
	count = true;
	cube->findEdge(WHITE, GREEN,whitex, whitey, whiteFace);
	while (count) {
		switch (whiteFace) {
		case DOWN:
			if (whitex == 0) {
				left(0);
				whitex = 2;
				whiteFace = BACK;
			}
			else if (whitey == 2) {
				back2(0);
				whitex = 1;
				whitey = 0;
				whiteFace = UP;
			}
			else
				count = false;
			break;
		case RIGHT:
			if (whitex == 0) {
				right2(0);
				whitex = 2;
				whiteFace = RIGHT;
			}
			else if(whitex == 2) {
				back(0);
				whitex = 1;
				whitey = 0;
				whiteFace = UP;
			}
			else if (whitey == 0) {
				right(0);
				whitex = 2;
				whiteFace = RIGHT;
			}
			else if (whitey == 2) {
				right(1);
				whitex = 2;
				whiteFace = RIGHT;
			}
			break;
		case BACK:
			if (whitex == 0) {
				right(0);
				count = false;
			}
			else if (whitex == 2) {
				back2(0);
				whitex = 0;
				whiteFace = BACK;
			}
			else if (whitey == 0) {
				back(1);
				whitex = 0;
				whiteFace = BACK;
			}
			else if (whitey == 2) {
				back(0);
				whitex = 0;
				whiteFace = BACK;
			}
			break;
		case FRONT:
			if (whitex == 0) {
				left(1);
				whitex = 0;
				whiteFace = UP;
			}
			else if (whitex == 2) {
				right(0);
				whitex = 2;
				whiteFace = UP;
			}
			else if (whitey == 0) {
				up(1);
				whitex = 1;
				whitey = 0;
				whiteFace = RIGHT;
			}
			break;
		case UP:
			if (whitex == 0) {
				up2(0);
				whitex = 2;
				whiteFace = UP;
			}
			else if (whitex == 2) {
				right2(0);
				count = false;
			}
			else if (whitey == 0) {
				up(0);
				whitex = 2;
				whiteFace = UP;
			}
			else if (whitey == 2) {
				up(1);
				whitex = 2;
				whiteFace = UP;
			}
			break;
		case LEFT:
			if (whitex == 0) {
				back(1);
				whitex = 1;
				whitey = 0;
				whiteFace = UP;
			}
			else if (whitex == 2) {
				left2(0);
				whitex = 0;
				whiteFace = LEFT;
			}
			else if (whitey == 0) {
				left(1);
				whitex = 0;
				whiteFace = LEFT;
			}
			else if (whitey == 2) {
				left(0);
				whitex = 0;
				whiteFace = LEFT;
			}
			break;
		}
		

	
	}
	count = true;
	cube->findEdge(WHITE, ORANGE, whitex, whitey, whiteFace);
	while (count) {
		switch (whiteFace) {
		case RIGHT:
			if (whitex == 0) {
				down(1);
				right2(0);
				down(0);
				whitex = 2;
				whiteFace = RIGHT;
			}
			else if (whitex == 2) {
				back(1);
				count = false;
			}
			else if (whitey == 0) {
				down(1);
				right(0);
				down(0);
				whitex = 2;
				whiteFace = RIGHT;
			}

			break;
		case LEFT:
			if (whitex == 0) {
				back(0);
				count = false;
			}
			else if (whitex == 2) {
				left2(0);
				whitex = 0;
				whiteFace = LEFT;
			}
			else if (whitey == 0) {
				left(1);
				whitex = 0;
				whiteFace = LEFT;
			}
			else if (whitey == 2) {
				left(0);
				whitex = 0;
				whiteFace = LEFT;
			}
			break;
		case UP:
			if (whitex == 0) {
				up(0);
				whitex = 1;
				whitey = 0;
				whiteFace = UP;
			}
			else if (whitex == 2){
				up(1);
				whitex = 1;
				whitey = 0;
				whiteFace = UP;
			}
			else if (whitey == 0) {
				back2(0);
				count = false;
			}
			else if (whitey == 2) {
				up2(1);
				whitex = 1;
				whitey = 0;
				whiteFace = UP;
			}
			break;
		case DOWN:
			if (whitex == 0) {
				left(1);
				whitex = 0;
				whiteFace = FRONT;
			  }
			else {
				count = false;
			}
			break;
		case FRONT:
			if (whitex == 0) {
				down(0);
				left(0);
				down(1);
				count = false;
			}
			else if (whitex == 2) {
				down(1);
				right(1);
				down(0);
				count = false;
			}
			else if (whitey == 0) {
				down(0);
				front(1);
				left(0);
				down(1);
				count = false;
			}
			break;
			
		case BACK:
			if (whitex == 0) {
				down(1);
				right(0);
				down(0);
				count = false;
			}
			else if (whitex == 2) {
				left(0);
				up(0);
				back2(0);
				count = false;
			}
			else if (whitey == 0) {
				up(1);
				left(1);
				back(0);
				count = false;
			}
			else if (whitey == 2) {
				back(0);
				whitex = 0;
				whiteFace = BACK;
			}
			break;
		}
	}
	count = true;
	cube->findEdge(WHITE, BLUE, whitex, whitey, whiteFace);
	while (count) {
		switch (whiteFace) {
		case DOWN:
			count = false;
			break;
		case FRONT:
			if (whitex == 0) {
				left(0);
				count = false;
			}
			else if (whitex == 2) {
				down(0);
				front2(0);
				down(1);
				left(0);
				count = false;
			}
			else if (whitey == 0) {
				down(0);
				front(1);
				down(1);
				left(0);
				count = false;
			}
			break;
		case BACK:
			if (whitex == 0) {
				down2(0);
				right(0);
				down2(0);
				count = false;
			}
			else if (whitex == 2) {
				left(1);
				count = false;
			}
			else if (whitey == 0) {
				down(1);
				back(0);
				down(0);
				left(1);
				count = false;
			}
			break;
		case RIGHT:
			if (whitex == 0) {
				down(0);
				front(0);
				down(1);
				count = false;
			}
			if (whitex == 2) {
				down(1);
				back(1);
				down(0);
				count = false;
			}
			else if (whitey == 0) {
				up2(0);
				left(0);
				down(0);
				front(1);
				down(1);
				count = false;
			}
			break;
		case LEFT:
			if (whitex == 0) {
				down(1);
				back(0);
				down(0);
				count = false;
			}
			else if (whitex == 2) {
				down(0);
				front(1);
				down(1);
				count = false;
			}
			else if (whitey == 0) {
				left(0);
				whitex = 2;
				whiteFace = LEFT;
			}
			else if (whitey == 2) {
				left(1);
				whitex = 2;
				whiteFace = LEFT;
			}
			break;
		case UP:
			if (whitex == 0) {
				left2(0); 
				count = false;
			}
			else if (whitex == 2) {
				up2(0);
				whitex = 0;
				whiteFace = UP;
			}
			else if (whitey == 0) {
				up(1);
				whitex = 0;
				whiteFace = UP;
			}
			else if (whitey == 2) {
				up(0);
				whitex = 0;
				whiteFace = UP;
			}
			break;
		}
	}
}
void Steps::step2() {}
void Steps::step3() {}
void Steps::step4() {}
void Steps::step5() {}
void Steps::step6() {}

void Steps::printSteps() {
	for (list<char*>::iterator it = steps.begin(); it != steps.end(); it++) {
		cout << *it << " ";
	}
}

void Steps::verifyStep(int stepNo, int cycles) {
	cout << "Verify until step " << stepNo << " for " << cycles << " times." << endl << endl;
	int errorCases=0, okCases=0;
	bool error=0;
	int **f, **b, **d, **l, **r;
	for (int i = 1; i <= cycles; i++) {
		cout << "Case " << i << " of " << cycles << ": ";
		cube->mashupCube(60);
		switch (stepNo) {
		case 1:
			step1();
			d = cube->getFace(DOWN);
			b = cube->getFace(BACK);
			f = cube->getFace(FRONT);
			l = cube->getFace(LEFT);
			r = cube->getFace(RIGHT);

			//Verify the white cross
			for (int x = 0;x < 3;x++) {
				for (int y = 0; y < 3;y++) {
					if (((x == 1) && ((y == 0) || (y == 2))) || ((y == 1) && ((x == 0) || (x == 2)))) {
						if (d[y][x] != WHITE) {
							error = 1;
						}
					}
				}
			}
			if (error) {
				cout << "error" << endl << "White cross pattern on down face not complete" << endl;
			}
			//Verify all the near faces of the edges have the same color of the face's centers
			else {
				//front->red, right->green, left->blue, back->orange
				if (f[2][1] != RED) {
					error = 1;
					cout << "error" << endl << "Red edge on front face not in position" << endl;
				}
				if (r[2][1] != GREEN) {
					if (error == 0) { cout << "error" << endl; }
					error = 1;
					cout << "Green edge on right face not in position" << endl;
				}
				if (b[2][1] != ORANGE) {
					if (error == 0) { cout << "error" << endl; }
					error = 1;
					cout << "Orange edge on back face not in position" << endl;
				}
				if (l[2][1] != BLUE) {
					if (error == 0) { cout << "error" << endl; }
					error = 1;
					cout << "Blue edge on left face not in position" << endl;
				}
			}
			if (error) {
				cout << endl;
				cube->printCube();
				errorCases++;
			}
			else {
				cout << "ok" << endl << endl;
				okCases++;
			}
			break;
		}
	}
	cout << "Done " << cycles << " verification cycles until " << stepNo << " step: " << okCases << " times gone ok," << errorCases << " times gone with errors.";
}