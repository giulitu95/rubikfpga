#include <iostream>
#include <time.h>
#include <fstream>
#include "Cube.h"

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
	cout << endl;
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

#ifdef DEBUG
	cout << endl << endl;
#endif
}
void Cube::colorDecoder(int color) {
	switch (color) {
	case WHITE:
		cout << "white";
		break;
	case GREEN:
		cout << "green";
		break;
	case BLUE:
		cout << "blue";
		break;
	case RED:
		cout << "red";
		break;
	case ORANGE:
		cout << "orange";
		break;
	case YELLOW:
		cout << "yellow";
		break;
	}
}
void Cube::printColorPosition(int color) {
	bool found;
	for (int x = 0; x < 3; x++) {
		for (int y = 0;y < 3;y++) {
			found = 0;
			if (front[x][y] == color) {
				cout << "found ";
				colorDecoder(front[x][y]); 
				cout << " on face front in position x=" << x << " y=" << y << endl;
				found = 1;
			}
			if (back[x][y] == color) {
				cout << "found ";
				colorDecoder(back[x][y]);
				cout << " on face back in position x=" << x << " y=" << y << endl;
				found = 1;
			}
			if (left[x][y] == color) {
				cout << "found ";
				colorDecoder(left[x][y]);
				cout << " on face left in position x=" << x << " y=" << y << endl;
				found = 1;
			}
			if (right[x][y] == color) {
				cout << "found ";
				colorDecoder(right[x][y]);
				cout << " on face right in position x=" << x << " y=" << y << endl;
				found = 1;
			}
			if (down[x][y] == color) {
				cout << "found ";
				colorDecoder(down[x][y]);
				cout << " on face down in position x=" << x << " y=" << y << endl;
				found = 1;
			}
			if (up[x][y] == color) {
				cout << "found ";
				colorDecoder(up[x][y]);
				cout << " on face up in position x=" << x << " y=" << y << endl;
				found = 1;
			}
		}
	}
}
void Cube::faceDecoder(int face) {
	switch (face)
	{
	case UP:
		cout << "Up";
		break;
	case DOWN:
		cout << "Down";
		break;
	case LEFT:
		cout << "Left";
		break;
	case RIGHT:
		cout << "Right";
		break;
	case FRONT:
		cout << "Front";
		break;
	case BACK:
		cout << "Back";
		break;
	}
}
void Cube::findEdge(int color1, int color2, int &x, int &y, int &f){
	int **pt_f, **pt_nf;
	int nx, ny, nf;
	for (int fc = 0; fc < 6; fc++) {
		pt_f = getFace(fc);
		for (int xi = 0; xi < 3; xi++) {
			for (int yi = 0; yi < 3; yi++) {
				if ((xi == 1 && yi == 0) || (xi == 0 && yi == 1) || (xi == 2 && yi == 1) || (xi == 1 && yi == 2)){
					if (color1 == pt_f[yi][xi]) {
						nearEdge(xi, yi, fc, nx, ny, nf);
						pt_nf = getFace(nf);
						if (color2 == pt_nf[ny][nx]) {
							x = xi;
							y = yi;
							f = fc;
							break;
						}
					}
				}
			}
		}
	}
}
void Cube::nearEdge(int actualx, int actualy, int actualf, int &nearx, int &neary, int &nearface) {
	switch (actualf) {
	case UP:
		if ((actualx == 0) & (actualy == 1)) {
			nearface = LEFT;
			nearx = 1;
			neary = 0;
		}
		else if ((actualx == 1) & (actualy == 0)) {
			nearface = BACK;
			nearx = 0;
			neary = 1;
		}
		else if ((actualx == 2) & (actualy == 1)) {
			nearface = RIGHT;
			nearx = 1;
			neary = 0;
		}
		else if ((actualx == 1) & (actualy == 2)) {
			nearface = FRONT;
			nearx = 0;
			neary = 1;
		}
		break;
	case DOWN:
		if ((actualx == 0) & (actualy == 1)) {
			nearface = LEFT;
			nearx = 1;
			neary = 2;
		}
		else if ((actualx == 1) & (actualy == 0)) {
			nearface = FRONT;
			nearx = 1;
			neary = 2;
		}
		else if ((actualx == 2) & (actualy == 1)) {
			nearface = RIGHT;
			nearx = 1;
			neary = 2;
		}
		else if ((actualx == 1) & (actualy == 2)) {
			nearface = BACK;
			nearx = 1;
			neary = 2;
		}
		break;
	case FRONT:
		if ((actualx == 0) & (actualy == 1)) {
			nearface = LEFT;
			nearx = 2;
			neary = 1;
		}
		else if ((actualx == 1) & (actualy == 0)) {
			nearface = UP;
			nearx = 1;
			neary = 2;
		}
		else if ((actualx == 2) & (actualy == 1)) {
			nearface = RIGHT;
			nearx = 0;
			neary = 1;
		}
		else if ((actualx == 1) & (actualy == 2)) {
			nearface = DOWN;
			nearx = 1;
			neary = 0;
		}
		break;
	case BACK:
		if ((actualx == 0) & (actualy == 1)) {
			nearface = RIGHT;
			nearx = 2;
			neary = 1;
		}
		else if ((actualx == 1) & (actualy == 0)) {
			nearface = UP;
			nearx = 0;
			neary = 1;
		}
		else if ((actualx == 2) & (actualy == 1)) {
			nearface = LEFT;
			nearx = 0;
			neary = 1;
		}
		else if ((actualx == 1) & (actualy == 2)) {
			nearface = DOWN;
			nearx = 1;
			neary = 2;
		}
		break;
	case LEFT:
		if ((actualx == 0) & (actualy == 1)) {
			nearface = BACK;
			nearx = 2;
			neary = 1;
		}
		else if ((actualx == 1) & (actualy == 0)) {
			nearface = UP;
			nearx = 0;
			neary = 1;
		}
		else if ((actualx == 2) & (actualy == 1)) {
			nearface = FRONT;
			nearx = 0;
			neary = 1;
		}
		else if ((actualx == 1) & (actualy == 2)) {
			nearface = DOWN;
			nearx = 0;
			neary = 1;
		}
		break;
	case RIGHT:
		if ((actualx == 0) & (actualy == 1)) {
			nearface = FRONT;
			nearx = 2;
			neary = 1;
		}
		else if ((actualx == 1) & (actualy == 0)) {
			nearface = UP;
			nearx = 2;
			neary = 1;
		}
		else if ((actualx == 2) & (actualy == 1)) {
			nearface = BACK;
			nearx = 0;
			neary = 1;
		}
		else if ((actualx == 1) & (actualy == 2)) {
			nearface = DOWN;
			nearx = 2;
			neary = 1;
		}
		break;
	}
}
void Cube::findAngle(int color1, int color2, int color3, int &x, int &y, int &f) {
	int** currentFace;
	int** face1;
	int** face2;
	int f1, f2;
	int nearx1, nearx2, neary1, neary2;
	for (int i = 0; i < 6; i++) {
		currentFace = getFace(i);
		for (int j = 0; j < 3; j = j + 2) {
			for (int k = 0; k < 3; k = k + 2) {
				if (currentFace[j][k] == color1) {
					nearAngle(k, j, i, nearx1, neary1, f1, nearx2, neary2, f2);
					face1 = getFace(f1);
					face2 = getFace(f2);
					if ((face1[neary1][nearx1] == color2 && face2[neary2][nearx2] == color3) || (face1[neary1][nearx1] == color3 && face2[neary2][nearx2] == color2)) {
						x = k;
						y = j;
						f = i;
					}
				}
			}
		}
	}
}
void Cube::nearAngle(int actualx, int actualy, int actualface, int &nearx1, int &neary1, int &nearface1, int &nearx2, int &neary2, int &nearface2) {
	switch (actualface) {
	case FRONT:
		if (actualx == 0 && actualy == 0) {
			nearface1 = UP;
			nearx1 = 0;
			neary1 = 2;
			nearface2 = LEFT;
			nearx2 = 2;
			neary2 = 0;
		}
		else if (actualx == 2 && actualy == 0) {
			nearface1 = UP;
			nearx1 = 2;
			neary1 = 2;
			nearface2 = RIGHT;
			nearx2 = 0;
			neary2 = 0;
		}
		else if (actualx == 0 && actualy == 2) {
			nearface1 = DOWN;
			nearx1 = 0;
			neary1 = 0;
			nearface2 = LEFT;
			nearx2 = 2;
			neary2 = 2;
		}
		else if (actualx == 2 && actualy == 2) {
			nearface1 = DOWN;
			nearx1 = 2;
			neary1 = 0;
			nearface2 = RIGHT;
			nearx2 = 0;
			neary2 = 2;
		}
		break;
	case LEFT:
		if (actualx == 0 && actualy == 0) {
			nearface1 = UP;
			nearx1 = 0;
			neary1 = 0;
			nearface2 = BACK;
			nearx2 = 2;
			neary2 = 0;
		}
		else if (actualx == 2 && actualy == 0) {
			nearface1 = UP;
			nearx1 = 0;
			neary1 = 2;
			nearface2 = FRONT;
			nearx2 = 0;
			neary2 = 0;
		}
		else if (actualx == 0 && actualy == 2) {
			nearface1 = DOWN;
			nearx1 = 0;
			neary1 = 2;
			nearface2 = BACK;
			nearx2 = 2;
			neary2 = 2;
		}
		else if (actualx == 2 && actualy == 2) {
			nearface1 = FRONT;
			nearx1 = 0;
			neary1 = 2;
			nearface2 = DOWN;
			nearx2 = 0;
			neary2 = 0;
		}
		break;
	case RIGHT:
		if (actualx == 0 & actualy == 0) {
			nearface1 = UP;
			nearx1 = 2;
			neary1 = 2;
			nearface2 = FRONT;
			nearx2 = 2;
			neary2 = 0;
		}
		else if (actualx == 2 && actualy == 0) {
			nearface1 = UP;
			nearx1 = 2;
			neary1 = 0;
			nearface2 = BACK;
			nearx2 = 0;
			neary2 = 0;
		}
		else if (actualx == 0 && actualy == 2) {
			nearface1 = DOWN;
			nearx1 = 2;
			neary1 = 0;
			nearface2 = FRONT;
			nearx2 = 2;
			neary2 = 2;
		}
		else if (actualx == 2 & actualy == 2) {
			nearface1 = BACK;
			nearx1 = 0;
			neary1 = 2;
			nearface2 = DOWN;
			nearx2 = 2;
			neary2 = 2;
		}
		break;
	case BACK:
		if (actualx == 0 && actualy == 0) {
			nearface1 = UP;
			nearx1 = 2;
			neary1 = 0;
			nearface2 = RIGHT;
			nearx2 = 2;
			neary2 = 0;
		}
		else if (actualx == 2 && actualy == 0) {
			nearface1 = UP;
			nearx1 = 0;
			neary1 = 0;
			nearface2 = LEFT;
			nearx2 = 0;
			neary2 = 0;
		}
		else if (actualx == 0 && actualy == 2) {
			nearface1 = DOWN;
			nearx1 = 2;
			neary1 = 2;
			nearface2 = RIGHT;
			nearx2 = 2;
			neary2 = 2;
		}
		else if (actualx == 2 && actualy == 2) {
			nearface1 = LEFT;
			nearx1 = 0;
			neary1 = 2;
			nearface2 = DOWN;
			nearx2 = 0;
			neary2 = 2;
		}
		break;
	case UP:
		if (actualx == 0 && actualy == 0) {
			nearface1 = BACK;
			nearx1 = 2;
			neary1 = 0;
			nearface2 = LEFT;
			nearx2 = 0;
			neary2 = 0;
		}
		else if (actualx == 2 && actualy == 0) {
			nearface1 = BACK;
			nearx1 = 0;
			neary1 = 0;
			nearface2 = RIGHT;
			nearx2 = 2;
			neary2 = 0;
		}
		else if (actualx == 0 && actualy == 2) {
			nearface1 = FRONT;
			nearx1 = 0;
			neary1 = 0;
			nearface2 = LEFT;
			nearx2 = 2;
			neary2 = 0;
		}
		else if (actualx == 2 && actualy == 2) {
			nearface1 = FRONT;
			nearx1 = 2;
			neary1 = 0;
			nearface2 = RIGHT;
			nearx2 = 0;
			neary2 = 0;
		}
		break;
	case DOWN:
		if (actualx == 0 && actualy == 0) {
			nearface1 = FRONT;
			nearx1 = 0;
			neary1 = 2;
			nearface2 = LEFT;
			nearx2 = 2;
			neary2 = 2;
		}
		else if (actualx == 2 && actualy == 0) {
			nearface1 = FRONT;
			nearx1 = 2;
			neary1 = 2;
			nearface2 = RIGHT;
			nearx2 = 0;
			neary2 = 2;
		}
		else if (actualx == 0 && actualy == 2) {
			nearface1 = BACK;
			nearx1 = 2;
			neary1 = 2;
			nearface2 = LEFT;
			nearx2 = 0;
			neary2 = 2;
		}
		else if (actualx == 2 && actualy == 2) {
			nearface1 = BACK;
			nearx1 = 0;
			neary1 = 2;
			nearface2 = RIGHT;
			nearx2 = 2;
			neary2 = 2;
		}
		break;
	}

}
int** Cube::getFace(int face) {
	switch (face) {
	case UP:
		return up;
		break;
	case DOWN:
		return down;
		break;
	case LEFT:
		return left;
		break;
	case RIGHT:
		return right;
		break;
	case BACK:
		return back;
		break;
	case FRONT:
		return front;
		break;
	}

}
