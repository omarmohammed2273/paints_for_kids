#ifndef ADD_HEXAGON_ACTION_H
#define ADD_HEXAGON_ACTION_H

#include "Action.h"

//Add Hexagon Action class
class AddHexagonAction : public Action
{
private:
	Point P1; //Hexagon Corners
	GfxInfo HexagonGfxInfo;

public:
	AddHexagonAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual bool Execute(bool read=1);

	//addition
	virtual void Undo(); //undo the last opeartions
	virtual void Redo();  //redo the undone opeartions


};

#endif
