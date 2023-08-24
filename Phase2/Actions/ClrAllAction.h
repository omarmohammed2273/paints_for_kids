#ifndef ADD_CLEAR_ALL_ACTION_H
#define ADD_CLEAR_ALL_ACTION_H

#include "Action.h"

class ClrAllAction : public Action
{
private:
public:
	ClrAllAction(ApplicationManager* pApp);

	virtual bool Execute(bool read =1);
	virtual void ReadActionParameters();


};

#endif

