/*****************************
/ Program by: Alex White
/ Date Created: 2/17/16
/
/ This program is designed
/ to play a proper game of
/ Tic Tac Toe.
/
/ tic.cpp implements the
/ functions declared in tic.h
/ creating a functioning
/ backend to the Tic Tac Toe
/ game.
/****************************/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
#include "tic.h"

	/****************************************
	************ CONSTRUCTORS ***************
	****************************************/ //Because there's nothing more irritating than inconsistant documentation formatting

	tic::tic() { }
	tic::tic(string name) { }

	/****************************************
	************* DESTRUCTOR ****************
	****************************************/

	tic::~tic() { }
	
	/****************************************
	************* INSPECTORS ****************
	****************************************/ 

	bool tic::isLegal(vector<string> grid, int spot) const{
		if(spot == 99){
			return false;
		} else if(grid[spot] == "x" || grid[spot] == "o"){
			return false;
		} else{
			return true;
		}	
	}
	
	bool tic::isWin(vector<string> grid, string c) const{
		if((grid[0] == c && grid[1] == c && grid[2] == c)){
			return true;
		} else if((grid[3] == c && grid[4] == c && grid[5] == c)){
			return true;
		} else if((grid[6] == c && grid[7] == c && grid[8] == c)){
			return true;
		} else if((grid[0] == c && grid[3] == c && grid[6] == c)){
			return true;
		} else if((grid[1] == c && grid[4] == c && grid[7] == c)){
			return true;
		} else if((grid[2] == c && grid[5] == c && grid[8] == c)){
			return true;
		} else if((grid[2] == c && grid[4] == c && grid[6] == c)){
			return true;
		} else if((grid[0] == c && grid[4] == c && grid[8] == c)){
			return true;
		} else{
			return false;
		}
	}
	

	/****************************************
	************** MUTATORS *****************
	****************************************/ 
	
	void tic::setTrueSpot(int trueSpot){
		trueSpot_ = trueSpot;
	}

	void tic::setX(string c, vector<string> &grid){
		grid[trueSpot_] = c;
	}
	
	void tic::setO(string o, vector<string> &grid){
		grid[trueSpot_] = o;
	}
	
	/****************************************
	************* FACILITATOR ***************
	****************************************/ 
	
	void tic::drawGrid(vector<string> grid) const{
		cout << " |" << setw(5) << "0" << "|" << setw(5) << "1" << "|" << setw(5) << "2" << "|" << endl;
		cout << " +-----------------+" << endl;
		cout << "0|" << setw(5) << grid[0] << "|" << setw(5) << grid[1] << "|" << setw(5) << grid[2] << "|" << endl;
		cout << " +-----------------+" << endl;
		cout << "1|" << setw(5) << grid[3] << "|" << setw(5) << grid[4] << "|" << setw(5) << grid[5] << "|" << endl;
		cout << " +-----------------+" << endl;
		cout << "2|" << setw(5) << grid[6] << "|" << setw(5) << grid[7] << "|" << setw(5) << grid[8] << "|" << endl;
		cout << " +-----------------+" << endl;
	}

