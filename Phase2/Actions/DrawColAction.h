#ifndef ADD_CHANGE_DrawCOLOR_ACTION_H
#define ADD_CHANGE_DrawCOLOR_ACTION_H

#include"Action.h"

class DrawColAction:public Action
{
private:
	color NewDrawCol;
	color OldDrawCol;
public:
	DrawColAction(ApplicationManager *pApp);
	virtual bool Execute(bool read =1);
	virtual void ReadActionParameters();

	//addition
	virtual void Undo(); //undo the last opeartions
	virtual void Redo();  //redo the undone opeartions


};

#endif
