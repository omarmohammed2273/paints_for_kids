#pragma once
#include"Actions/Action.h"
#include"Figures\CFigure.h"

class PlayRecordAction :public Action
{
public:
	PlayRecordAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool read =1);

};

