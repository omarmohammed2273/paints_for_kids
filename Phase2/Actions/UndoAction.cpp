#include"UndoAction.h"
#include"..\ApplicationManager.h"

#include"..\GUI\Output.h"
#include "..\GUI\input.h"

UndoAction::UndoAction(ApplicationManager *pApp):Action(pApp)
{Last = pManager->getUndo();}
void UndoAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Action *pre=pManager->getLastAct();
	if(Last!=NULL && pManager->setUndo())
	{
		pOut->PrintMessage("Undo is done");
		check = true;
	}else
	{
		pOut->PrintMessage("Undo is not done as there is no action to undo");
		check = false;
	}
}

bool UndoAction::Execute(bool read)
{
	if(read)
	ReadActionParameters();
	if(check)
		Last->Undo();
	return check;
}

bool UndoAction::checkUn_Re()
{return true;}
