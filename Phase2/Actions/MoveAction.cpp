#include "MoveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


MoveAction::MoveAction(ApplicationManager* pApp):Action(pApp)
{FigOfAct = pManager->getSelFigure();}



void MoveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();
	if(FigOfAct == NULL) //check there is selected figure
	{
		
		pOut->PrintMessage("No figure is selected");
		check = false;
		return ;
	}
	check = true;
	pOut->PrintMessage("You clicked on move icon. Please, choose the new center point");
	pIn->GetPointClicked(NewCenter.x,NewCenter.y); //get new center
	pOut->PrintMessage("The figure has moved");
}

bool MoveAction::Execute(bool read)
{
	if(read)
	ReadActionParameters();
	if(check)
	{
		
		OldCenter = FigOfAct->NewCoor(NewCenter.x,NewCenter.y); //change the coordinates
		FigOfAct->Unselect();
		pManager->setSelFigure(NULL);
		pManager->AddUndoAcion(this);
	}
	return check;
}



void  MoveAction::Undo() //undo the last opeartions
{
	Point p = FigOfAct->NewCoor(OldCenter.x,OldCenter.y);
}

void  MoveAction::Redo()  //redo the undone opeartions
{
	Point p = FigOfAct->NewCoor(NewCenter.x,NewCenter.y);
}
