#include "DeleteAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager* pApp):Action(pApp)
{
	FigOfAct = pManager->getSelFigure();
}

void DeleteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetOutput();
	if(FigOfAct==NULL)
	{
		pOut->PrintMessage("No selected figure to delete");
		check = false;
	}
	else
	{
		pOut->PrintMessage("Delete is done"); //if there is selected figure when use delete icon
		check = true;
	}
}

//Execute the action
bool DeleteAction::Execute(bool read)
{
	//This action needs to read some parameters first
	if(read)
	ReadActionParameters();
	if(check)
	{
		pManager->DeleteFig(FigOfAct);
		pManager->setSelFigure(NULL);
		FigOfAct->Unselect();
		pManager->AddUndoAcion(this);
	}
	return check;
}



void DeleteAction::Undo() //undo the last opeartions
{
	pManager->AddFigure(FigOfAct);
}
void DeleteAction::Redo()  //redo the undone opeartions
{
	if(FigOfAct==pManager->getSelFigure())
	{
		pManager->setSelFigure(NULL);
		FigOfAct->Unselect();
	}
	pManager->DeleteFig(FigOfAct);
}
