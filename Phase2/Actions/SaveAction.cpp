#include "SaveAction.h"
#include"..\ApplicationManager.h"

#include"..\GUI\Output.h"
#include "..\GUI\input.h"

SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{}
void SaveAction::ReadActionParameters()//read the name of save file
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("enter the name of save file ");
	file_name = pIn->GetSrting(pOut);

}
bool SaveAction::Execute(bool read)
{
	if(read)
	ReadActionParameters();
	output_file.open(file_name, ios::out);
	output_file << "BLUE" << "\t" << "GREEN" << endl;
	output_file << pManager->get_figcount() << endl;
	pManager->SaveAll(output_file);
	output_file.close();

	/////
	return true;
}
