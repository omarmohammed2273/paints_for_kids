#include "AddTriangleAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Tringle: Click at vetrex 1");
	//Read the 1st vertex and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Tringle: Click at vetrex 2");
	//Read the 2nd vertex and store in point P1
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Tringle: Click at vetrex 3");
	//Read the 3rd vertex and store in point P1
	pIn->GetPointClicked(P3.x, P3.y);


	//my editing
	TriangleGfxInfo.isFilled = pOut->getFilled();	//filling mode of drawing figure


	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
bool AddTriangleAction::Execute(bool read)
{
	//This action needs to read some parameters first
	if(read)
	ReadActionParameters();

	//Create a square with the parameters read from the user
	FigOfAct = new CTriangle(P1,P2,P3, TriangleGfxInfo);
	if (pManager->sound == true)
		PlaySound(TEXT("Sound\\TriangleAdded.wav"), NULL, SND_SYNC);
	//Add the rectangle to the list of figures
	pManager->AddFigure(FigOfAct);
	pManager->AddUndoAcion(this);
	return true;
}



void AddTriangleAction::Undo() //undo the last opeartions
{
	if(FigOfAct==pManager->getSelFigure())
	{
		pManager->setSelFigure(NULL);
		FigOfAct->Unselect();
	}
	pManager->DeleteFig(FigOfAct);
}
void AddTriangleAction::Redo()  //redo the undone opeartions
{
	pManager->AddFigure(FigOfAct);
}
