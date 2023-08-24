#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at center");
	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at Radius");
	//Read the Radius and store in point P1
	pIn->GetPointClicked(P2.x, P2.y);


	//my editing
	CircleGfxInfo.isFilled = pOut->getFilled();	//filling mode of drawing figure

	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
bool AddCircleAction::Execute(bool read)
{
	//This action needs to read some parameters first
	if (read)
	{
		ReadActionParameters();
	}
	//Create a circle with the parameters read from the user
	FigOfAct = new CCircle(P1,P2, CircleGfxInfo);
	if (pManager->sound == true)
		PlaySound(TEXT("Sound\\CircleAdded.wav"), NULL, SND_SYNC);
	//Add the circle to the list of figures
	pManager->AddFigure(FigOfAct);
	pManager->AddUndoAcion(this);
	return true;
}

//addition

void AddCircleAction::Undo() //undo the last opeartions
{
	if(FigOfAct==pManager->getSelFigure())
	{
		pManager->setSelFigure(NULL);
		FigOfAct->Unselect();
	}
	pManager->DeleteFig(FigOfAct);
}
void AddCircleAction::Redo()  //redo the undone opeartions
{
	pManager->AddFigure(FigOfAct);
}
