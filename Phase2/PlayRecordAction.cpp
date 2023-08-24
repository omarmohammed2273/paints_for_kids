#include "PlayRecordAction.h"
#include"GUI\Output.h"
#include "GUI\input.h"
#include"ApplicationManager.h"
PlayRecordAction::PlayRecordAction(ApplicationManager* pApp) : Action(pApp)
{}
void PlayRecordAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("play recording");
}
bool PlayRecordAction::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->get_stop_record() == -1)
	{
		pOut->PrintMessage("you didn't record anything");
		return 0;
	}
	else if (pManager->get_stop_record() == 0)
	{
		pOut->PrintMessage("you didn't stop recording yet");
		return 0;
	}
	if(read)
	ReadActionParameters();
	pOut->ClearDrawArea();
	pManager->delet_all_figure();
	pManager->play_recording();
	return 1;
}