#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();//default constructor for load action
	virtual void Draw(Output* pOut) const;

	//my addition
	void PrintInfo(Output* pOut);	 //print all figure info on the status bar
	bool CheckFigure(int x,int y); //check if this point belong to this figure
	virtual Point NewCoor(int x, int y); //set new coordinate
	virtual void Save(ofstream& OutFile);//save the rectangle's information
	virtual void Load(ifstream& Infile);// load rectangel from save file 
	virtual bool IsFromMe(int i);
	CRectangle(CRectangle*& r);
};

#endif