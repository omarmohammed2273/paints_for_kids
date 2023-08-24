#include "StartRecordAction.h"
#include "ApplicationManager.h"
#include"GUI\Output.h"
#include "GUI\input.h"
StartRecordAction::StartRecordAction(ApplicationManager* pApp) : Action(pApp)
{}
void StartRecordAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("start recording");
}
bool StartRecordAction::Execute(bool read)
{
	Output* pOut = pManager->GetOutput();
	if (pManager->get_immediatel_after_clear_all() || pManager->get_beginning_of_program())
	{
		pManager->set_start_action(1);
		pManager->set_stop_recording(0);
		if(read)
		ReadActionParameters();
		return 1;
	}
	else

	{
		pOut->PrintMessage(" error you can not do this action ");
		return 0;
	}



}