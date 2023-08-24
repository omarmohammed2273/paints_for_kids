#ifndef PICK_AND_HIDE_H
#define PICK_AND_HIDE_H

#include "Actions/Action.h"

class PickAndHide : public Action
{
private:
	Output* pOut;
	Input* pIn;
	CFigure* PickedFigure;
	string figurename;
	string colorname;
	string msg;
	color clr;
	Point P1;
	int count;
	int CorrectAns;
	int InCorrectAns;
	int FigType;
	int index;
	int DelCount;
	int Selector;
	enum { Type=1, FillColor, TypeAndFillColor };
public:
	PickAndHide(ApplicationManager* pApp,int s);
	bool IsThereFilled();
	void ReadActionParameters();
	void UpdateGameWindow();
	void ReturnToDrawMode();
	void PrintAnswer();
	void PrintQuestion();
	void calculateCount();
	void GetClick();
	bool Execute(bool read =1);
	
};



#endif