/*****************************
/ Program by: Alex White
/ Date Created: 2/17/16
/
/ This program is designed
/ to play a proper game of
/ Tic Tac Toe.
/
/ Assignment3.cpp sees the
/ front end of the game, so
/ to speak, providing all
/ essential "game" stuff.
/****************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
#include "tic.h"

	int createTrueSpot(int x, int y){
		int trueSpot;
		if(x == 0){
			if(y == 0){
				trueSpot = 0;
			} else if (y == 1){
				trueSpot = 3;
			} else if (y == 2){
				trueSpot = 6;
			}
		} else if(x == 1){
			if(y == 0){
				trueSpot = 1;
			} else if (y == 1){
				trueSpot = 4;
			} else if (y == 2){
				trueSpot = 7;
			}
		} else if(x == 2){
			if(y == 0){
				trueSpot = 2;
			} else if (y == 1){
				trueSpot = 5;
			} else if (y == 2){
				trueSpot = 8;
			}
		} else if (x > 2 || y > 2){
			trueSpot = 99; //This will be the error number.
		}
		return trueSpot;
	}
	
	int main(void){
		string name1, name2, num;
		int x, y, spot;
		int spaceCount = 0; //This little variable will count the number of spaces to see if a tie needs to be determined
		vector<string> grid(9);
		cout << "Hello! Welcome to Tic-Tac-Toe" << endl;
		cout << "What is the name of the player going first (x)?" << endl;
		getline(cin, name1);
		cout << name1 << " is x" << endl;
		cout << "What is the name of the player going second (o)?" << endl;
		getline(cin, name2);
		cout << name2 << " is o" << endl;
		bool legal, won;
		
		tic p1(name1), p2(name2);
		p1.drawGrid(grid);
		
		while(p1.isWin(grid, "x") == false && p2.isWin(grid, "o") == false){
			cout << name1 << " enter space to place x as ROW COL then press enter" << endl;
			getline(cin, num);
			x = atoi(num.substr(0,1).c_str());
			y = atoi(num.substr(2,1).c_str());
			spot = createTrueSpot(x,y);

			legal = p1.isLegal(grid, spot);
			if(legal == false){
				while(!legal){
					cout << "This input is invalid! Try again: " << endl;
					getline(cin, num);
					x = atoi(num.substr(0,1).c_str());
					y = atoi(num.substr(2,1).c_str());
					spot = createTrueSpot(x,y);
					legal = p1.isLegal(grid, spot);
				}
			}
			p1.setTrueSpot(spot);
			p1.setX("x", grid);
			p1.drawGrid(grid);
			
			won = p1.isWin(grid, "x");
			if(won){
				cout << name1 << " wins the game!" << endl;
				break; //I'm sorry
			} else{
				spaceCount++;
			}
			if(spaceCount == 9){
				cout << "There is no winner. It's a tie" << endl;
				break; //Sorry
			}
			
			//Player 2's turn now
			cout << name2 << " enter space to place x as ROW COL then press enter" << endl;
			getline(cin, num);
			x = atoi(num.substr(0,1).c_str());
			y = atoi(num.substr(2,1).c_str());
			spot = createTrueSpot(x,y);
			
			legal = p2.isLegal(grid, spot);
			if(legal == false){
				while(!legal){
					cout << "This input is invalid! Try again: " << endl;
					getline(cin, num);
					x = atoi(num.substr(0,1).c_str());
					y = atoi(num.substr(2,1).c_str());
					spot = createTrueSpot(x,y);
					legal = p2.isLegal(grid, spot);
				}
			}
			
			p2.setTrueSpot(spot);
			p2.setO("o", grid);
			p2.drawGrid(grid);
			
			won = p2.isWin(grid, "o");
			if(won){
				cout << name2 << " wins the game!" << endl;
				break; //Sorry
			} else{
				spaceCount++;
			}
			
			if(spaceCount == 9){
				cout << "There is no winner. It's a tie" << endl;
				break; //Sorry
			}
		
		}
		
		
		return 0;
	}
