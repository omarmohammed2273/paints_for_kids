#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H
#include "Action.h"

//Add Square Action class
class AddCircleAction : public Action
{
private:
	Point P1; //Circle Center
	Point P2; //Circle Radius
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual bool Execute(bool read =1);

	//addition
	virtual void Undo(); //undo the last opeartions
	virtual void Redo();  //redo the undone opeartions


};

#endif

