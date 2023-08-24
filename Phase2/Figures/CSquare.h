
#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"
class CSquare : public CFigure
{
private:
	Point Center;
	int size;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare();//default constructor for load action
	virtual void Draw(Output* pOut) const;

	//my addition
	void PrintInfo(Output* pOut);	 //print all figure info on the status bar
	bool CheckFigure(int x,int y); //check if this point belong to this figure
	virtual Point NewCoor(int x, int y); //set new coordinate
	virtual void Save(ofstream& OutFile);//save the square's information
	virtual void Load(ifstream& Infile);// load Square from save file 
	virtual bool IsFromMe(int i);
	CSquare(CSquare*& s);
};

#endif