#pragma once
#include"Actions\Action.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include"ApplicationManager.h"
#include"GUI\Output.h"
#include "GUI\input.h"
class LoadAction :public Action
{
	string fileName;
	ifstream input_file;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool read=1);
	color ConvertStringToColor(string s);
};


