
#ifndef ADD_CHANGE_FillCOLOR_ACTION_H
#define ADD_CHANGE_FillCOLOR_ACTION_H

#include"Action.h"

class FillColAction:public Action
{
private:
	color NewFillColor;
	color OldFillCol;
	Output *pOut;
public:
	FillColAction(ApplicationManager *pApp);
	virtual bool Execute(bool read =1);
	virtual void ReadActionParameters();

	//addition
	virtual void Undo(); //undo the last opeartions
	virtual void Redo();  //redo the undone opeartions

};

#endif
