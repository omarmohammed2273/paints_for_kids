#pragma once
#include"Actions/Action.h"
class StopRecordAction :public Action
{

public:
	virtual void ReadActionParameters();
	StopRecordAction(ApplicationManager* pApp);
	virtual bool Execute(bool read =1);
};

