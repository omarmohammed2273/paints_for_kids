#ifndef CCIRCLE_H
#define CCIRCLE_H
#include<fstream>
#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point Radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	CCircle();//default constructor for load action 
	//my addition
	//print the info
	virtual void PrintInfo(Output* pOut);
	//check if the point is belong to this figure
	virtual bool CheckFigure(int x,int y);
	virtual Point NewCoor(int x, int y);//set new coordinates to move
	virtual void Save(ofstream& OutFile);//save the ceircle's information 
	virtual void Load(ifstream& Infile);// load circle from save file 
	virtual bool IsFromMe(int i) ;
	CCircle(CCircle*& c);//copy constructor
	
};
#endif