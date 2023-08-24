#include "LoadAction.h"
#include"GUI\Output.h"
#include "GUI\input.h"
#include"Figures/CFigure.h"
#include"Figures/CCircle.h"
#include"Figures/CHexagon.h"
#include"Figures/CSquare.h"
#include"Figures/CRectangle.h"
#include"Figures/CTriangle.h"
LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}

void LoadAction::ReadActionParameters()//read the load of save file
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("enter the name of load file ");
	fileName = pIn->GetSrting(pOut);
}
color LoadAction::ConvertStringToColor(string s)
{
	if (s == "GREEN")
		return GREEN;
	else if (s == "BLUE")
		return BLUE;
	else if (s == "BLACK")
		return BLACK;
	else if (s == "RED")
		return RED;
	else if (s == "ORANGE")
		return ORANGE;
	else if (s == "YELLOW")
		return YELLOW;

}
bool LoadAction::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
	string s;
	if(read)
	ReadActionParameters();
	pOut->ClearDrawArea();
	//pManager->delet_all_figure();
	input_file.open(fileName, ios::in);
	input_file >> s;
	pOut->set_crnt_draw_color(ConvertStringToColor(s));
	input_file >> s;
	pOut->set_crnt_fill_color(ConvertStringToColor(s));
	int n;
	input_file >> n;
	CFigure* myfig = NULL;
	string type;
	for (int i = 0; i < n; i++)
	{
		input_file >> type;

		if (type == "CIRC")
			myfig = new CCircle;
		else if (type == "RECT")
			myfig = new CRectangle;
		else if (type == "HEXA")
			myfig = new CHexagon;
		else if (type == "SQUARE")
			myfig = new CSquare;
		else if (type == "TRING")
			myfig = new CTriangle;
		myfig->Load(input_file);
		pManager->AddFigure(myfig);
	}
	//pManager->UpdateInterface();
	input_file.close();
	delete myfig;
	return 1;
}