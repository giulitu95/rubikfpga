#include"Cube.h"
#include <iostream>
#include <time.h>
#include <fstream>

#define DEBUG
using namespace std;

Cube::Cube() {
	up = new int*[N];
	for (int i = 0; i < N; i++)
		up[i] = new int[N];
	down = new int*[N];
	for (int i = 0; i < N; i++) 
		down[i] = new int[N];
	front = new int*[N];
	for (int i = 0; i < N; i++) 
		front[i] = new int[N];
	back = new int*[N];
	for (int i = 0; i < N; i++)
		back[i] = new int[N];
	right = new int*[N];
	for (int i = 0; i < N; i++)
		right[i] = new int[N];
	left = new int*[N];
	for (int i = 0; i < N; i++)
		left[i] = new int[N];
}

void Cube::loadCube() {
	Cube* cube = new Cube;
	ifstream* input = new ifstream;
	input->open("input.txt");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*input >> up[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*input >> back[i][j];
		}
		for (int j = 0; j < 3; j++) {
			*input >> left[i][j];
		}
		for (int j = 0; j < 3; j++) {
			*input >> front[i][j];
		}
		for (int j = 0; j < 3; j++) {
			*input >> right[i][j];
		}

	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*input >> down[i][j];
		}
	}


	input->close();

}
void Cube::printCube() {
	for (int i = 0; i < 3; i++) {
		cout << "              ";
		for (int j = 0; j < 3; j++) {
			cout << up[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << back[i][j] << " ";
		}
		cout << " ";
		for (int j = 0; j < 3; j++) {
			cout << left[i][j] << " ";
		}
		cout << " ";
		for (int j = 0; j < 3; j++) {
			cout << front[i][j] << " ";
		}
		cout << " ";
		for (int j = 0; j < 3; j++) {
			cout << right[i][j] << " ";
		}

		cout << endl;

	}
	cout << endl;
	for (int i = 0; i < 3; i++) {
		cout << "              ";
		for (int j = 0; j < 3; j++) {
			cout << down[i][j] << " ";
		}
		cout << endl;
	}
}
void Cube::frontRotation(bool direction) {
	int colourTmp[3];
	int j;


	for (int i = 0; i < 3; i++) {
		colourTmp[i] = down[0][i];
	}
	if (!direction) {
		j = 2;
		for (int i = 0; i < 3; i++) {
			down[0][i] = right[j][0];
			j--;
		}
		for (int i = 0; i < 3; i++) {
			right[i][0] = up[2][i];
		}
		j = 2;
		for (int i = 0; i < 3; i++) {
			up[2][i] = left[j][2];
			j--;
		}
		for (int i = 0; i < 3; i++) {
			left[i][2] = colourTmp[i];
		}

	}

	else {
		for (int i = 0; i < 3; i++) {
			down[0][i] = left[i][2];
		}
		j = 2;
		for (int i = 0; i < 3; i++) {
			left[i][2] = up[2][j];
			j--;
		}
		for (int i = 0; i < 3; i++) {
			up[2][i] = right[i][0];
		}
		j = 2;
		for (int i = 0; i < 3; i++) {
			right[i][0] = colourTmp[j];
			j--;
		}
	}
	sideRotation(front, direction);

}
void Cube::backRotation(bool direction) {
	int colourTmp[3];
	int j;


	for (int i = 0; i < 3; i++) {
		colourTmp[i] = down[2][i];
	}
	if (!direction) {
		for (int i = 0; i < 3; i++) {
			down[2][i] = left[i][0];
		}
		j = 2;
		for (int i = 0; i < 3; i++) {
			left[i][0] = up[0][j];
			j--;
		}
		for (int i = 0; i < 3; i++) {
			up[0][i] = right[i][2];
		}
		j = 2;
		for (int i = 0; i < 3; i++) {
			right[i][2] = colourTmp[j];
			j--;
		}

	}

	else {
		j = 2;
		for (int i = 0; i < 3; i++) {
			down[2][i] = right[j][2];
			j--;
		}
		for (int i = 0; i < 3; i++) {
			right[i][2] = up[0][i];
		}
		j = 2;
		for (int i = 0; i < 3; i++) {
			up[0][i] = left[j][0];
			j--;
		}
		for (int i = 0; i < 3; i++) {
			left[i][0] = colourTmp[i];
		}
	}
	sideRotation(back, direction);

}
void Cube::rightRotation(bool direction) {
	int colourTmp[3];
	int j;
	for (int i = 0; i < 3; i++) {
		colourTmp[i] = up[i][2];
	}
	if (!direction) {

		for (int i = 0; i < 3; i++) {
			up[i][2] = front[i][2];
			front[i][2] = down[i][2];
		}
		j = 2;
		for (int i = 0; i < 3; i++) {
			down[i][2] = back[j][0];
			j--;
		}
		j = 2;
		for (int i = 0; i < 3; i++) {
			back[i][0] = colourTmp[j];
			j--;
		}
	}
	else {
		j = 2;
		for (int i = 0; i < 3; i++) {
			up[i][2] = back[j][0];
			back[j][0] = down[i][2];
			j--;
		} 
		for (int i = 0; i < 3; i++) {
			down[i][2] = front[i][2];
			front[i][2] = colourTmp[i];
		}
	}
	sideRotation(right, direction);


}
void Cube::leftRotation(bool direction) {
	int colourTmp[3];
	int j;
	for (int i = 0; i < 3; i++) {
		colourTmp[i] = up[i][0];
	}
	if (!direction) {
		j = 2;
		for (int i = 0; i < 3; i++) {
			up[i][0] = back[j][2];
			back[j][2] = down[i][0];
			j--;
		}
		for (int i = 0; i < 3; i++) {
			down[i][0] = front[i][0];
			front[i][0] = colourTmp[i];
		}
	}
	else {

		for (int i = 0; i < 3; i++) {
			up[i][0] = front[i][0];
			front[i][0] = down[i][0];
		}
		j = 2;
		for (int i = 0; i < 3; i++) {
			down[i][0] = back[j][2];
			j--;
		}
		j = 2;
		for (int i = 0; i < 3; i++) {
			back[i][2] = colourTmp[j];
			j--;
		}
	}
	sideRotation(left, direction);

}
void Cube::downRotation(bool direction) {
	int colourTmp[3];
	for (int i = 0; i < 3; i++) {
		colourTmp[i] = back[2][i];
	}
	if (!direction) {
		for (int i = 0; i < 3; i++) {
			back[2][i] = right[2][i];
			right[2][i] = front[2][i];
			front[2][i] = left[2][i];
			left[2][i] = colourTmp[i];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			back[2][i] = left[2][i];
			left[2][i] = front[2][i];
			front[2][i] = right[2][i];
			right[2][i] = colourTmp[i];
		}

	}
	sideRotation(down, direction);
}
void Cube::upRotation(bool direction) {
	int colourTmp[3];
	for (int i = 0; i < 3; i++) {
		colourTmp[i] = back[0][i];
	}
	if (!direction) {
		for (int i = 0; i < 3; i++) {
			back[0][i] = left[0][i];
			left[0][i] = front[0][i];
			front[0][i] = right[0][i];
			right[0][i] = colourTmp[i];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			back[0][i] = right[0][i];
			right[0][i] = front[0][i];
			front[0][i] = left[0][i];
			left[0][i] = colourTmp[i];
		}
	}
	sideRotation(up, direction);
}
void Cube::sideRotation(int** side, bool direction) {
	int tmp;
	if (!direction) {
		tmp = side[0][0];
		side[0][0] = side[2][0];
		side[2][0] = side[2][2];
		side[2][2] = side[0][2];
		side[0][2] = tmp;

		tmp = side[0][1];
		side[0][1] = side[1][0];
		side[1][0] = side[2][1];
		side[2][1] = side[1][2];
		side[1][2] = tmp;
	}
	else {
		tmp = side[0][0];
		side[0][0] = side[0][2];
		side[0][2] = side[2][2];
		side[2][2] = side[2][0];
		side[2][0] = tmp;

		tmp = side[0][1];
		side[0][1] = side[1][2];
		side[1][2] = side[2][1];
		side[2][1] = side[1][0];
		side[1][0] = tmp;
	}
}
void Cube::mashupCube(int moves) {
	srand(time(NULL));
	for (int i = 0; i < moves; i++) {
		int rotation = rand() % 12;
		switch (rotation) {
		case 0:
#ifdef DEBUG
			cout << "F ";
#endif
			frontRotation(0);
			break;
		case 1:
#ifdef DEBUG
			cout << "F' ";
#endif
			frontRotation(1);
			break;
		case 2:
#ifdef DEBUG
			cout << "B ";
#endif
			backRotation(0);
			break;
		case 3:
#ifdef DEBUG
			cout << "B' ";
#endif
			backRotation(1);
			break;
		case 4:
#ifdef DEBUG
			cout << "R ";
#endif
			rightRotation(0);
			break;
		case 5:
#ifdef DEBUG
			cout << "R' ";
#endif
			rightRotation(1);
			break;
		case 6:
#ifdef DEBUG
			cout << "L ";
#endif
			leftRotation(0);
			break;
		case 7:
#ifdef DEBUG
			cout << "L' ";
#endif
			leftRotation(1);
			break;
		case 8:
#ifdef DEBUG
			cout << "D ";
#endif
			downRotation(0);
			break;
		case 9:
#ifdef DEBUG
			cout << "D' ";
#endif
			downRotation(1);
			break;
		case 10:
#ifdef DEBUG
			cout << "U ";
#endif
			upRotation(0);
			break;
		case 11:
#ifdef DEBUG
			cout << "U' ";
#endif
			upRotation(1);
			break;
		}
	}
}

int main() {
	Cube* c = new Cube();
	c->loadCube();
	c->mashupCube(1000);
	cout << endl << endl;
	c->printCube();
	/*
	c->printCube();
	cout << endl << "-----------------------U'-----------------------------" << endl;
	c->upRotation(1);
	c->printCube();
	cout << endl << "-----------------------D-----------------------------" << endl;
	c->downRotation(0);
	c->printCube();
	*/
	system("PAUSE");
}