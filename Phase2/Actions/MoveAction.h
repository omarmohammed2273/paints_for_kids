#ifndef ADD_MOVE_ACTION_H
#define ADD_MOVE_ACTION_H

#include "Action.h"

class MoveAction : public Action
{
private:
	Point NewCenter; //new center because of move
	Point OldCenter; //old center before of move
public:
	MoveAction(ApplicationManager* pApp);

	virtual bool Execute(bool read =1);
	virtual void ReadActionParameters();

	//addition
	virtual void Undo(); //undo the last opeartions
	virtual void Redo();  //redo the undone opeartions
	 
};

#endif

