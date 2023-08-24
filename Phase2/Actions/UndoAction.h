#ifndef ADD_UNDO_ACTION_H
#define ADD_UNDO_ACTION_H

#include"Action.h"

class UndoAction:public Action
{
private:
	Action *Last; //pointer of one of last actions which can undo or undo
public:
	UndoAction(ApplicationManager *pApp);
	virtual bool Execute(bool read=1);
	virtual void ReadActionParameters();
	virtual bool checkUn_Re();

};

#endif
