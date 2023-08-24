
#ifndef ADD_TRINGLE_ACTION_H
#define ADD_TRINGLE_ACTION_H

#include "Action.h"

//Add Square Action class
class AddTriangleAction : public Action
{
private:
	Point P1; //Triangle Vertex 1
	Point P2; //Triangle Vertex 2
	Point P3; //Triangle Vertex 3
	GfxInfo TriangleGfxInfo;
public:
	AddTriangleAction(ApplicationManager* pApp);

	//Reads Tringle parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual bool Execute(bool read=1);

	//addition
	virtual void Undo(); //undo the last opeartions
	virtual void Redo();  //redo the undone opeartions

};

#endif
