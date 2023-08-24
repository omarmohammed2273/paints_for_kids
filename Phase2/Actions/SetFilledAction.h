#ifndef ADD_CHANGE_FILLED_ACTION_H
#define ADD_CHANGE_FILLED_ACTION_H

#include"Action.h"

class SetFilledAction:public Action
{
private:
public:
	SetFilledAction(ApplicationManager *pApp);
	virtual bool Execute(bool read =1);
	virtual void ReadActionParameters();

};

#endif
