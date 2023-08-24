#include"DrawColAction.h"
#include"..\ApplicationManager.h"

#include"..\GUI\Output.h"
#include "..\GUI\input.h"

DrawColAction::DrawColAction(ApplicationManager *pApp):Action(pApp)
{FigOfAct = pManager->getSelFigure();}

void DrawColAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetOutput();
	pOut->PrintMessage("You clicked on draw color icon. Now,select the new drawing color");
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
		NewDrawCol=BLACK; //new drawing color is black
		pOut->PrintMessage("New drawing color is black");
		break;
	case COL_BLUE:
		NewDrawCol=BLUE; //new drawing color is blue
		pOut->PrintMessage("New drawing color is blue");
		break;
	case COL_YELLOW:
		NewDrawCol=YELLOW; //new drawing color is yellow
		pOut->PrintMessage("New drawing color is yellow");
		break;
	case COL_ORANGE:
		NewDrawCol=ORANGE; //new drawing color is orange
		pOut->PrintMessage("New drawing color is orange");
		break;
	case COL_GREEN:
		NewDrawCol=GREEN; //new drawing color is green
		pOut->PrintMessage("New drawing color is green");
		break;
	case COL_RED:
		NewDrawCol=RED; //new drawing color is red
		pOut->PrintMessage("New drawing color is red");
		break;
	default:
		pOut->PrintMessage("No selected color");
		check = false;
		break;
	}

}


bool DrawColAction::Execute(bool read)
{
	if(read)
	ReadActionParameters() ;
	if(check)
	{
		OldDrawCol=UI.DrawColor;
		UI.DrawColor=NewDrawCol;
		FigOfAct->SetSelected(false); 
		FigOfAct->ChngDrawClr(UI.DrawColor); //unselect selected figure with new drawing color
		pManager->setSelFigure(NULL);
		pManager->AddUndoAcion(this);
	}
	return check;
}



void DrawColAction::Undo() //undo the last opeartions
{
	UI.DrawColor = OldDrawCol;
	FigOfAct->ChngDrawClr(FigOfAct->getmyDraw());
}
void DrawColAction::Redo()  //redo the undone opeartions
{
	UI.DrawColor = NewDrawCol;
	FigOfAct->ChngDrawClr(NewDrawCol);
}
