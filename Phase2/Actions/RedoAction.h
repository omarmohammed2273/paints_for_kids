#ifndef ADD_REDO_ACTION_H
#define ADD_REDO_ACTION_H

#include"Action.h"

class RedoAction:public Action
{
private:
	Action *Last; //pointer of one of last actions which can undo or redo
public:
	RedoAction(ApplicationManager *pApp);
	virtual bool Execute(bool read =1);
	virtual void ReadActionParameters();
	virtual bool checkUn_Re();

};

#endif
