#include"RedoAction.h"
#include"..\ApplicationManager.h"

#include"..\GUI\Output.h"
#include "..\GUI\input.h"

RedoAction::RedoAction(ApplicationManager *pApp):Action(pApp)
{Last = pManager->getRedo();}
void RedoAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Action *prevoius = pManager->getLastAct();
	if(prevoius->checkUn_Re())
	{
		if(Last!=NULL && pManager->setRedo())
		{
			pOut->PrintMessage("Redo is done");
			check = true;
			return ;
		}
	}
	pOut->PrintMessage("No action because no more operations to redo");
	check = false;
}


bool RedoAction::Execute(bool read)
{
	if(read)
	ReadActionParameters();
	if(check)
		Last->Redo();
	return check;
}
bool RedoAction::checkUn_Re()
{return true;}