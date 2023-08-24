
#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H

#include "Action.h"

//Add Square Action class
class AddSquareAction : public Action
{
private:
	Point P1; //Square Corners
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual bool Execute(bool read =1);

	//addition
	virtual void Undo(); //undo the last opeartions
	virtual void Redo();  //redo the undone opeartions


};

#endif
