
#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "CFigure.h"
class CHexagon : public CFigure
{
private:
	Point Center;
	int size;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	CHexagon();//default constructor for load action 
	//my addition
	void PrintInfo(Output* pOut);	//print all figure info on the status bar
	bool CheckFigure(int x,int y); //check if this point belong to this figure
	virtual Point NewCoor(int x, int y); //set new coordinate
	virtual void Save(ofstream& OutFile);//save the hexagon's information 
	virtual void Load(ifstream& Infile);// load hexagon from save file 
	virtual bool IsFromMe(int i);
	CHexagon(CHexagon*& h);
};

#endif