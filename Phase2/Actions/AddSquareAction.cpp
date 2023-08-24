#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at center");

	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	//my editing
	SquareGfxInfo.isFilled = pOut->getFilled(); //filling mode of drawing figure

	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
bool AddSquareAction::Execute(bool read)
{
	//This action needs to read some parameters first
	if(read)
	ReadActionParameters();

	//Create a square with the parameters read from the user
	FigOfAct = new CSquare(P1, SquareGfxInfo);
	if (pManager->sound == true)
		PlaySound(TEXT("Sound\\SquareAdded.wav"), NULL, SND_SYNC);
	//Add the rectangle to the list of figures
	pManager->AddFigure(FigOfAct);
	pManager->AddUndoAcion(this);
	return true;
}


void AddSquareAction::Undo() //undo the last opeartions
{
	if(FigOfAct==pManager->getSelFigure())
	{
		pManager->setSelFigure(NULL);
		FigOfAct->Unselect();
	}
	pManager->DeleteFig(FigOfAct);
}
void AddSquareAction::Redo()  //redo the undone opeartions
{
	pManager->AddFigure(FigOfAct);
}
