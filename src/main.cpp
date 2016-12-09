/*
 *
 * description:		Displays the A* Algorithm on a grid.
 *
 * author:          Yann Herklotz <ymherklotz@gmail.com>
 * date created:    DD-MM-YYYY
 *
 */

#include "tilemap.hpp"
#include "astar.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	Node n1(NULL, 5);
	Node n2(NULL, 2);

	cout << "n1 > n2: " << (n1 > n2) << endl;
	cout << "n1 < n2: " << (n1 < n2) << endl;
	cout << "n1 <= n2: " << (n1 <= n2) << endl;
	cout << "n1 >= n2: " << (n1 >= n2) << endl;
	return 0;
}
