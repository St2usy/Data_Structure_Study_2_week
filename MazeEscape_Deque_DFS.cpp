#include "Location2d.h"
#include <deque>
#include <iostream>
const int maze_size = 6;
using std::deque;

char map[maze_size][maze_size] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

bool isvalidloc(int r, int c) {
	if (r<0 || c<0 || r>maze_size || c>maze_size) return false;
	else return map[r][c] == '0' || map[r][c] == 'x'; // 
}

int main() {
	deque<Location2D> locdeque; // ��ġ ���� ��ü ����
	Location2D entry(1, 0);
	locdeque.push_front(entry);

	while (locdeque.empty() == false) {
		Location2D here = locdeque.front();
		locdeque.pop_front();

		int r = here.row;
		int c = here.col;
		std::cout << '(' << r << " " << "," << " " << c << ')' << " ";
		if (map[r][c] == 'x') {
			std::cout << "�̷� Ž�� ����!!" << std::endl;
			return 0;
		}
		else {
			map[r][c] = '.'; // ������ ó��
			if (isvalidloc(r - 1, c)) locdeque.push_front(Location2D(r - 1, c)); //��
			if (isvalidloc(r + 1, c)) locdeque.push_front(Location2D(r + 1, c)); //��
			if (isvalidloc(r, c - 1)) locdeque.push_front(Location2D(r, c - 1)); //��
			if (isvalidloc(r, c + 1)) locdeque.push_front(Location2D(r, c + 1)); //��
		}
	}
	std::cout << "�̷� Ž�� ����" << std::endl;
}