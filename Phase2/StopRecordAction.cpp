#include "StopRecordAction.h"
#include "ApplicationManager.h"
#include"GUI\Output.h"
#include "GUI\input.h"
StopRecordAction::StopRecordAction(ApplicationManager* pApp) : Action(pApp)
{}
void StopRecordAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("stop recording");
}
bool StopRecordAction::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->get_start_action())
	{
		if(read)
		ReadActionParameters();
		pManager->set_stop_recording(1);
		return 1;
	}
	else
	{
		pOut->PrintMessage("you aren't recording ");
		return 0;

	}
}