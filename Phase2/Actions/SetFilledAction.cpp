#include"SetFilledAction.h"
#include"..\ApplicationManager.h"

#include"..\GUI\Output.h"
#include "..\GUI\input.h"

SetFilledAction::SetFilledAction(ApplicationManager *pApp):Action(pApp)
{}


void SetFilledAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetOutput();

	if(pOut->getFilled()) //check filling mode
		pOut->PrintMessage("The figures will not be filled");
	else
		pOut->PrintMessage("The figures will be filled");
	pOut->setFilled(!pOut->getFilled()); //change filling mode to opposite

}

bool SetFilledAction::Execute(bool read)
{
	if(read)
	ReadActionParameters();
	return true;
}


