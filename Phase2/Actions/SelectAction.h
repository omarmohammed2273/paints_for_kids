#ifndef ADD_SELECT_ACTION_H
#define ADD_SELECT_ACTION_H

#include"Action.h"


class SelectAction:public Action
{
private:
	Point P;//point may belong to figure
	CFigure *lastsele; //pointer of selected figure before this action
public:
	SelectAction(ApplicationManager *pApp);
	virtual bool Execute(bool read =1);
	virtual void ReadActionParameters();


};

#endif
