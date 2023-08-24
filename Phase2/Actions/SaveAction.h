#pragma once
#include"Action.h"
#include <fstream>
#include <iostream>
#include <iomanip>
class SaveAction:public Action 
{
	ofstream output_file;
	string file_name;
public:
	SaveAction(ApplicationManager* pApp);
	virtual bool Execute(bool read=1);
	virtual void ReadActionParameters();
};

