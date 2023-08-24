#include "AddHexagonAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddHexagonAction::AddHexagonAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexagonAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at center");

	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	//my editing
	HexagonGfxInfo.isFilled = pOut->getFilled(); //filling mode of drawing figure

	//get drawing, filling colors and pen width from the interface
	HexagonGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexagonGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
bool AddHexagonAction::Execute(bool read)
{
	//This action needs to read some parameters first
	if(read)
	ReadActionParameters();

	//Create a Hexagon with the parameters read from the user
	FigOfAct = new CHexagon(P1, HexagonGfxInfo);
	if (pManager->sound == true)
		PlaySound(TEXT("Sound\\HexagonAdded.wav"), NULL, SND_SYNC);
	//Add the rectangle to the list of figures
	pManager->AddFigure(FigOfAct);
	pManager->AddUndoAcion(this);
	return true;
}



void AddHexagonAction::Undo() //undo the last opeartions
{
	if(FigOfAct==pManager->getSelFigure())
	{
		pManager->setSelFigure(NULL);
		FigOfAct->Unselect();
	}
	pManager->DeleteFig(FigOfAct);
}
void AddHexagonAction::Redo()  //redo the undone opeartions
{
	pManager->AddFigure(FigOfAct);
}
