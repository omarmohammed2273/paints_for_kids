#ifndef ADD_DELETE_ACTION_H
#define ADD_DELETE_ACTION_H

#include "Action.h"

class DeleteAction : public Action
{
private:
public:
	DeleteAction(ApplicationManager* pApp);

	virtual bool Execute(bool read =1);
	virtual void ReadActionParameters();

	//addition
	virtual void Undo(); //undo the last opeartions
	virtual void Redo();  //redo the undone opeartions

};

#endif

