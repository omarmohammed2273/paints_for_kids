#include"FillColAction.h"
#include"..\ApplicationManager.h"

#include"..\GUI\Output.h"
#include "..\GUI\input.h"

FillColAction::FillColAction(ApplicationManager *pApp):Action(pApp)
{FigOfAct = pManager->getSelFigure();}

void FillColAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
 	pOut = pManager->GetOutput();
	pOut->PrintMessage("You clicked on fill color icon. Now, select the new filling color");
	if(FigOfAct==NULL)
	{
		pOut->PrintMessage("No selected figure");
		check = false;
		return ;
	}
	check = true;
	ActionType color = pManager->GetUserAction();
	switch(color)
	{
	case COL_BLACK:
		NewFillColor=BLACK; //new filling color is black
		pOut->PrintMessage("New filled color is black");
		break;
	case COL_BLUE:
		NewFillColor=BLUE; //new filling color is blue
		pOut->PrintMessage("New filled color is blue");
		break;
	case COL_YELLOW: //new filling color is yellow
		NewFillColor=YELLOW;
		pOut->PrintMessage("New filled color is yellow");
		break;
	case COL_ORANGE:
		NewFillColor=ORANGE; //new filling color is orange
		pOut->PrintMessage("New filled color is orange");
		break;
	case COL_GREEN:
		NewFillColor=GREEN; //new filling color is green
		pOut->PrintMessage("New filled color is green");
		break;
	case COL_RED:
		NewFillColor=RED; //new filling color is red
		pOut->PrintMessage("New filled color is red");
		break;
	default:
		pOut->PrintMessage("No selected color");
		check = false;
		break;
	}

}


bool FillColAction::Execute(bool read)
{
	if(read)
	ReadActionParameters() ;
	if(check)
	{
		OldFillCol = UI.FillColor;
		UI.FillColor = NewFillColor;
		pOut->setFilled(true); //change the filling mode for new figures
		FigOfAct->SetSelected(false);
		FigOfAct->ChngDrawClr(FigOfAct->getmyDraw());
		FigOfAct->ChngFillClr(UI.FillColor, true); //unselect selected figure with new filling color and his drawing color
		pManager->setSelFigure(NULL);
		pManager->AddUndoAcion(this);
	}
	return check;
}


void FillColAction::Undo() //undo the last opeartions
{
	UI.FillColor = OldFillCol;
	pOut->setFilled(false);
	FigOfAct->ChngFillClr(UI.FillColor, false);
}
void FillColAction::Redo()  //redo the undone opeartions
{
	UI.FillColor = NewFillColor;
	pOut->setFilled(true);
	FigOfAct->ChngFillClr(UI.FillColor, true);
}
