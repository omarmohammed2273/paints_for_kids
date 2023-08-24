#include"SelectAction.h"
#include"..\ApplicationManager.h"

#include"..\GUI\Output.h"
#include "..\GUI\input.h"


SelectAction::SelectAction(ApplicationManager *pApp):Action(pApp)
{lastsele = pManager->getSelFigure();}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();
	pOut->PrintMessage("You clicked on select icon. Now,select the figure");
	pIn->GetPointClicked(P.x,P.y); //get the point
	FigOfAct = pManager->GetFigure(P.x,P.y); //get the figure which point belongs to
	if(FigOfAct!=NULL) //check if there is figure
	{
		check = true;
		FigOfAct->PrintInfo(pOut); // print the info (id,center,corners,length,width)
	}else{
		pOut->PrintMessage("No figure is selected");
		check = false;
	}

}
bool SelectAction::Execute(bool read)
{
	if(read)
	ReadActionParameters();
	if(check)
	{
		if(lastsele!=NULL && lastsele!=FigOfAct)
			lastsele->Unselect();
		if(FigOfAct->IsSelected())
		{
			FigOfAct->Unselect(); // unselect the selected figure by return to its drawing color
			pManager->setSelFigure(NULL);
		}else{
			FigOfAct->select();// select the figure by change the drawing color to highlighted
			pManager->setSelFigure(FigOfAct);
		}
	}
	return check;
}


