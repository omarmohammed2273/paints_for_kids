#include "ClrAllAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ClrAllAction::ClrAllAction(ApplicationManager* pApp):Action(pApp)
{}

void ClrAllAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetOutput();
	pOut->PrintMessage("Clear is done");
}

//Execute the action
bool ClrAllAction::Execute(bool read)
{
	//This action needs to read some parameters first
	pManager->ClearAll();
	if( read)
	ReadActionParameters();
	return true;
}


