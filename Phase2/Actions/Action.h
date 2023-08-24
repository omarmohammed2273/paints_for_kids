#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include "..\Figures\CFigure.h"
class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

	//my addition
	CFigure *FigOfAct; //pointer of figure which change because of action
	bool check;  //check if the action is done or no

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual bool Execute(bool read=1) =0;
	

	//addition
	virtual void Undo() //undo the last opeartions
	{}
	virtual void Redo() //redo the undone opeartions
	{}
	virtual bool checkUn_Re()
	{return false;}
};

#endif