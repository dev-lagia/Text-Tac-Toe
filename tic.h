/****************************
/ Program by: Alex White
/ Date Created: 2/17/16
/
/ This program is designed
/ to play a proper game of
/ Tic Tac Toe.
/
/ tic.h is created with the
/ intent of creating of
/ any function I need.
/***************************/

#ifndef _TIC_H
#define _TIC_H

#include <vector>
#include <string>

using namespace std;

class tic{
	public:
		/***************
		* Constructors *
		***************/
	
		tic();
		tic(string name);
		
		/***************
		*  Destructors *
		***************/
	
		~tic();
		
		/*************
		* Inspectors *
		*************/
	
		bool isLegal(vector<string> grid,int spot) const;
		bool isWin(vector<string> grid, string c) const;
	
		/***********
		* Mutators *
		***********/
	
		void setX(string c, vector<string> &grid);
		void setO(string o, vector<string> &grid);
		void setTrueSpot(int trueSpot);
	
		/***************
		* Facilitators *
		***************/
	
		void drawGrid(vector<string> grid) const;
	
	private:
		int trueSpot_;
};
#endif
