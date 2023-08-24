#ifndef CTRINGLE_H
#define CTRINGLE_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Vertex1;
	Point Vertex2;
	Point Vertex3;
public:
	CTriangle(Point,Point,Point, GfxInfo FigureGfxInfo);
	CTriangle();//default constructor for load action
	virtual void Draw(Output* pOut) const;

	//my addition
	void PrintInfo(Output* pOut);	  //print all figure info on the status bar
	bool CheckFigure(int x,int y);  //check if this point belong to this figure
	virtual Point NewCoor(int x,int y); //set new coordinate
	virtual void Save(ofstream& OutFile);//save the triangel's information
	virtual void Load(ifstream& Infile);// load triangle from save file 
	virtual bool IsFromMe(int i);
	CTriangle(CTriangle*& t);
};

#endif