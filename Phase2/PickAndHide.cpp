#include "PickAndHide.h"
#include"ApplicationManager.h"
#include <time.h>
#include "GUI\input.h"
#include "GUI\Output.h"
PickAndHide::PickAndHide(ApplicationManager* pApp,int s) :Action(pApp)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	CorrectAns = 0;
	InCorrectAns = 0;
	DelCount = 0;
	Selector = s;
}

bool PickAndHide::IsThereFilled()
{
	if (pManager->ISFigFilled())
		return true;
	else
		pOut->PrintMessage("There no any filled figures, you must have at least one filled figure");
	return false;
}

void PickAndHide::ReadActionParameters()
{
	srand(time(0));
	int index = rand() % pManager->get_figcount();
	FigOfAct = pManager->GetFigure(index);
	switch (Selector)
	{
	case Type:
		figurename = pManager->GetFigureName(index);
		break;
	case FillColor:
		do
		{
			if (FigOfAct->IsFilled())
				colorname = pManager->GetFigureColor(index);
		} while (!(FigOfAct->IsFilled()));
		break;
	case TypeAndFillColor:
		figurename = pManager->GetFigureName(index);
		do
		{
			if (FigOfAct->IsFilled())
				colorname = pManager->GetFigureColor(index);
		} while (!(FigOfAct->IsFilled()));
	}
}

void PickAndHide::UpdateGameWindow()
{  
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
	pManager->UpdateInterface();
}

void PickAndHide::ReturnToDrawMode()
{
	pOut->CreateDrawToolBar();
	pManager->ReMakeCopy(DelCount);
	pManager->UpdateInterface();
}
void PickAndHide::PrintAnswer()
{
	msg = to_string(CorrectAns);
	msg += " Correct Answers ------ ";
	msg += to_string(InCorrectAns);
	msg += " InCorrect Answers";
	pOut->PrintMessage(msg);
}

void PickAndHide::PrintQuestion()
{
	switch (Selector)
	{
	case Type:
		msg = "Pick all ";
		msg += figurename;
		pOut->PrintMessage(msg);
		break;
	case FillColor:
		
		msg = "Pick all ";
		msg += colorname;
		msg += " Figures";
		pOut->PrintMessage(msg);
		break;
	case TypeAndFillColor:
		msg = "Pick all ";
		msg += colorname;
		msg += " ";
		msg += figurename;
		pOut->PrintMessage(msg);
		break;
	}
}

void PickAndHide::calculateCount()
{
	switch (Selector)
	{
	case Type:
		FigType = FigOfAct->TypeID;
		count = pManager->getCountPlayMode(FigType);
		break;
	case FillColor:
		clr = FigOfAct->GetFillColor();
		count = pManager->GetCountColor(clr);
		break;
	case TypeAndFillColor:
		FigType = FigOfAct->TypeID;
		clr = FigOfAct->GetFillColor();
		count = pManager->GetFigure_ColorCounr(clr, FigType);
		break;
	}
}

void PickAndHide::GetClick()
{
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage(msg);
	PickedFigure = pManager->GetFigure(P1.x, P1.y);
}

bool PickAndHide::Execute(bool read)
{
	switch (Selector)
	{
	case Type:
		if(read)
		ReadActionParameters();
		if (pManager->sound == true)
			PlaySound(TEXT("Sound\\FigureType.wav"), NULL, SND_SYNC);
		PrintQuestion();
		calculateCount();
		while (count)
		{
			GetClick();
			if (!PickedFigure)
			{
				pOut->PrintMessage("You have picked on empty drawing area,You must pick on a figure");
				continue;
			}
			if (PickedFigure->IsFromMe(FigType))
			{
				count--;
				CorrectAns++;
			}
			else
				InCorrectAns++;
			pManager->DeleteFig(PickedFigure);
			DelCount++;
			UpdateGameWindow();
		}
		PrintAnswer();

		ReturnToDrawMode();
		break;
	case FillColor:
		if (IsThereFilled())
		{
			if(read)
			ReadActionParameters();
			if (pManager->sound == true)
				PlaySound(TEXT("Sound\\FigureFillColor.wav"), NULL, SND_SYNC);
			PrintQuestion();
			calculateCount();
			while (count)
			{
				GetClick();
				if (!PickedFigure)
				{
					pOut->PrintMessage("You have picked on empty drawing area,You must pick on a figure");
					continue;
				}
				if (PickedFigure->GetFillColor() == clr && PickedFigure->IsFilled())
				{
					count--;
					CorrectAns++;
				}
				else
					InCorrectAns++;
				pManager->DeleteFig(PickedFigure);
				DelCount++;
				UpdateGameWindow();
			}
			PrintAnswer();
			ReturnToDrawMode();
		}else
		{
			pOut->PrintMessage("To Play this Game,You must have at least one Color-Filled Figure.Fill one of them and try again! ");
			ReturnToDrawMode();
		}
		break;
	case TypeAndFillColor:
		if (IsThereFilled())
		{
			if(read)
			ReadActionParameters();
			if (pManager->sound == true)
				PlaySound(TEXT("Sound\\FigureTypeAndFillColor.wav"), NULL, SND_SYNC);
			PrintQuestion();
			calculateCount();
			while (count)
			{
				GetClick();
				if (!PickedFigure)
				{
					pOut->PrintMessage("You have picked on empty drawing area,You must pick on a figure");
					continue;
				}
				if (PickedFigure->GetFillColor() == clr && PickedFigure->IsFromMe(FigType) && PickedFigure->IsFilled())
				{
					count--;
					CorrectAns++;
				}
				else
					InCorrectAns++;
				pManager->DeleteFig(PickedFigure);
				DelCount++;
				UpdateGameWindow();
			}
			PrintAnswer();
			if (pManager->sound == true)
				PlaySound(TEXT("Sound\\SwitchToDrawMode.wav"), NULL, SND_SYNC);
			ReturnToDrawMode();
		}
		else
		{
			pOut->PrintMessage("To Play this Game,You must have at least one Color-Filled Figure.Fill one of them and try again! ");
			if (pManager->sound == true)
				PlaySound(TEXT("Sound\\SwitchToDrawMode.wav"), NULL, SND_SYNC);
			ReturnToDrawMode();
		}
	}
	return true;
}

