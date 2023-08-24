#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions/AddSquareAction.h"
#include "Actions/AddTriangleAction.h"
#include "Actions/AddHexagonAction.h"
#include "Actions/AddCircleAction.h"
#include"Actions/SelectAction.h"
#include"Actions/DrawColAction.h"
#include"Actions/FillColAction.h"
#include"Actions/DeleteAction.h"
#include"Actions/SetFilledAction.h"
#include"Actions/MoveAction.h"
#include"Actions/UndoAction.h"
#include"Actions/RedoAction.h"
#include"Actions/ClrAllAction.h"
#include"Actions/SaveAction.h"
#include "Figures/CFigure.h"
#include "Figures\CCircle.h"
#include "Figures\CHexagon.h"
#include "Figures\CRectangle.h"
#include "Figures\CSquare.h"
#include "Figures\CTriangle.h"
#include "PickAndHide.h"
#include"LoadAction.h"
#include"StartRecordAction.h"
#include"StopRecordAction.h"
#include"PlayRecordAction.h"
//#include "FigureFillColor.h"
//#include "FigureTypeAndFillColor.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	FigCount = 0;
	sound = false;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
	//addition
	LastAct = NULL;
	UnREActCount = 0;
	//Create an array of Action pointers and set them to NULL		
	for(int i=0; i<MaxUn_REAct; i++)
		UndoRedoList[i] = NULL;	
	ActUndo_Redo= NULL;
	ActTotcount = 0;
	//Create an array of Action pointers and set them to NULL		
	for(int i=0; i<MaxActTot; i++)
		ActTotlist[i] = NULL;	
	DelFigcount=0;
	for(int i=0;i<MaxDelFig;i++)
		DelFiglist[i]=NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_TRI:
		pAct = new AddTriangleAction(this);
		//first create triangle class and then call its constructor
		break;
	case DRAW_SQ:
		pAct = new AddSquareAction(this);
		//first create Square class and then call its constructor
		break;
	case DRAW_CIRC:
		pAct = new AddCircleAction(this);
		//first create Circle class and then call its constructor
		break;
	case DRAW_HEX:
		pAct = new AddHexagonAction(this);
		//first create Hexagon class and then call its constructor
		break;

	case SELECT_ONE:
		pAct = new SelectAction(this);
		//first create select class and then call its constructor
		break;

	case DRAW_COL:
		pAct=new DrawColAction(this);
		//first create draw color class and then call its constructor
		break;

	case FILL_COL:
		pAct=new FillColAction(this);
		//first create fill color class and then call its constructor
		break;

	case SET_FILLED:
		pAct = new SetFilledAction(this);
		//first create filling mode class and then call its constructor
		break;

	case MOVE:
		pAct = new MoveAction(this);
		//first create move class and then call its constructor
		break;

	case DEL:
		pAct = new DeleteAction(this);
		//first create delete class and then call its constructor
		break;

	case MAKE_UNDO:
		pAct = new UndoAction(this); //first create undo class and then call its constructor
		break;

	case MAKE_REDO:
		pAct = new RedoAction(this); //first create redo class and then call its constructor
		break;

	case CLR:
		pAct = new ClrAllAction(this);
		break;

	case SAVE_GRAPH:
		pAct = new SaveAction(this);
		break;
	case FIGURE_TYPE:
		//pAct = new FigureType(this);
		pAct = new PickAndHide(this,Type);
		break;
	case FIGURE_FILL_COLOR:
		//pAct = new FigureFillColor(this);
		pAct = new PickAndHide(this, FillColor);
		break;
	case FIGURE_TYPE_AND_FILL_COLOR:
		//pAct = new FigureTypeAndFillColor(this);
		pAct = new PickAndHide(this, TypeAndFillColor);
	case TO_PLAY:
		UI.InterfaceMode = MODE_PLAY;
		pOut->ClearToolBar();
		pOut->CreatePlayToolBar();
		if (sound == true)
			PlaySound(TEXT("Sound\\SwitchToPlayMode.wav"), NULL, SND_SYNC);
		break;
	case TO_DRAW:
		UI.InterfaceMode = MODE_DRAW;
		pOut->ClearToolBar();
		pOut->CreateDrawToolBar();
		if (sound == true)
			PlaySound(TEXT("Sound\\SwitchToDrawMode.wav"), NULL, SND_SYNC);
		break;
	case LOAD_GRAPH:
		pAct = new LoadAction(this);
		break;
	case START_RECORDING:
		pAct = new StartRecordAction(this);
		break;
	case STOP_RECORDING:
		pAct = new StopRecordAction(this);
		break;
	case PLAY_RECORDING:
		pAct = new PlayRecordAction(this);
		break;
	case EXIT:
		ClearAll();
		///create ExitAction here

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		if (pAct->Execute())//Execute
		{
			beginning_of_program = 0;// not at the beginning of the program
			LastAct = pAct;

			if (stop_record == 0)//start recording
				record(pAct, ActType);
			ActTotlist[ActTotcount++] = pAct;
		}
		else
			delete pAct;
		// for start recording action 
		if (ActType == CLR)// show if user use start recording after clear all or not 
			after_clear_all = 1;
		else
			after_clear_all = 0;

	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
	{
		FigList[FigCount++] = pFig;	
		//my edition
		pFig->setId(FigCount);//set id 
		int i=0;
		bool check = false;
		while(i<DelFigcount && !check)
		{
			if(pFig == DelFiglist[i]) //when reach to selected figure in figure list
				check = true;
			i++;
		}
		if(check)
			DelFiglist[--DelFigcount] = NULL;
	}

}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for(int i=FigCount-1;i>=0;i--)
		if(FigList[i]->CheckFigure(x,y))
			return FigList[i];
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	//شرح
	int i;
	pOut->ClearDrawArea();
	/*
	pOut->ClearToolBar();
	if(UI.InterfaceMode==MODE_DRAW)
	pOut->CreateDrawToolBar(); 
	else
	pOut->CreatePlayToolBar(); 
	*/
	for(i=0;FigList[i]!=NULL; i++)
		if(FigList[i]!=NULL)
		{
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
}


//my addition
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::ClearAll()
{
	for(int i=0;i<FigCount;i++)
	{
		delete FigList[i];
		FigList[i]=NULL;
	}
	FigCount = 0;
	for(int i=0;i<ActTotcount;i++)
	{
		delete ActTotlist[i];
		ActTotlist[i]=NULL;
	}
	ActTotcount = 0;
	for(int i=0;i<UnREActCount;i++)
		UndoRedoList[i]=NULL;
	UnREActCount = 0;
	for(int i=0;i<DelFigcount;i++)
	{
		delete DelFiglist[i];
		DelFiglist[i]=NULL;
	}
	DelFigcount=0;
}
void ApplicationManager::setSelFigure(CFigure* ptr) //set the pointer of selected figure
{SelectedFig = ptr;}

CFigure* ApplicationManager::getSelFigure() //get the pointer of selected figure
{return SelectedFig;}


void ApplicationManager::DeleteFig(CFigure* Dele) //delete the selected figure and update the figure list
{
	int i=0;
	bool check = false;
	while(i<FigCount && !check)
	{
		if(Dele == FigList[i]) //when reach to selected figure in figure list
		{
			check = true;
			DelFiglist[DelFigcount++] = Dele;
		}
		i++;

	}
	while(i<FigCount)
	{
		FigList[i-1] = FigList[i]; //shifting
		FigList[i]->setId(i); //set new id
		i++;
	}
	FigList[--FigCount] = NULL;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::AddUndoAcion(Action *last)  //add action to undo list
{
	if(UnREActCount < MaxUn_REAct)
	{
		if(UndoRedoList[UnREActCount]==NULL)
			UndoRedoList[UnREActCount++] = last; //add action to list
		else{
			for(int i=UnREActCount;i<MaxUn_REAct;i++)
				UndoRedoList[i]=NULL;
			UndoRedoList[UnREActCount++] = last;
		}
	}
	else{
		for(int i=1;i<MaxUn_REAct;i++)
			UndoRedoList[i-1] = UndoRedoList[i];
		UndoRedoList[MaxUn_REAct-1] = last;
	}
}
////////////////////////////////////////////////////////////////////////////////////
bool ApplicationManager::setUndo()   //set the pointer of action which will be undo
{
	if(UnREActCount!=0)
	{
		UnREActCount--;
		return true;
	}
	else
		return false;
}
////////////////////////////////////////////////////////////////////////////////////
bool ApplicationManager::setRedo()  //set the pointer of action which will be redo
{
	if(UnREActCount<MaxUn_REAct)
	{
		if(UndoRedoList[UnREActCount]!=NULL)
		{
			UnREActCount++;
			return true;
		}else
			return false;
	}else
		return false;
}
////////////////////////////////////////////////////////////////////////////////////
Action *ApplicationManager::getUndo()  //get pointer of action will be undo
{
	ActUndo_Redo = UndoRedoList[UnREActCount-1];
	return ActUndo_Redo;
}
Action *ApplicationManager::getRedo()  //get pointer of action will be redo
{
	ActUndo_Redo = UndoRedoList[UnREActCount];
	return ActUndo_Redo;
}
////////////////////////////////////////////////////////////////////////////////////
Action *ApplicationManager::getLastAct()
{return LastAct;}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SaveAll(ofstream& OutFile)//save all figures
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}

}
int ApplicationManager::get_figcount()
{
	return FigCount;
}

CFigure* ApplicationManager::GetFigure(int index)
{
	return FigList[index];
}

string ApplicationManager::GetFigureName(int index)
{
	//FigList[0]->GetFillColor();
	CCircle* pc = dynamic_cast<CCircle*>( FigList[index]);
	CRectangle* pr = dynamic_cast<CRectangle*>(FigList[index]);
	CHexagon* ph = dynamic_cast<CHexagon*>(FigList[index]);
	CSquare* ps = dynamic_cast<CSquare*>(FigList[index]);
	CTriangle* pt = dynamic_cast<CTriangle*>(FigList[index]);
	if (pc != NULL)
		return "Circles";
	else if (pr != NULL)
		return "Rectangles";
	else if (ph != NULL)
		return "Hexagons";
	else if (ps != NULL)
		return "Squares";
	else 
		return "Triangles";
}

string ApplicationManager::GetFigureColor(int index)
{
	color c = FigList[index]->GetFillColor();

	return FigList[index]->get_fill_color(c);
}

int ApplicationManager::GetCountColor(color c)
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if ((FigList[i]->GetFillColor() == c)&& FigList[i]->IsFilled())
			count++;
	}
	return count;
}

bool ApplicationManager::ISFigFilled()
{

	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsFilled())
			return true;
	}
	return false;
}

int ApplicationManager::GetFigure_ColorCounr(color c, int id)
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetFillColor() == c && FigList[i]->TypeID==id && FigList[i]->IsFilled())
			count++;
	}
	return count;
}


int ApplicationManager::getCountPlayMode(int type)
{
	int counter = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->TypeID == type)
			counter++;
	}
	return counter;
}

void ApplicationManager::ReMakeCopy(int Count)
{
	int DelFig = DelFigcount;
	for (int i=DelFig-1; i>=DelFig-Count; i--)
	{
		AddFigure(DelFiglist[i]);
	}
}

// recordings action 
bool ApplicationManager::get_beginning_of_program()// show if user use the record action at the beginning of the program 
{
	return beginning_of_program;
}
bool ApplicationManager::get_immediatel_after_clear_all()// show if user use the record action after clear all or not 
{
	return after_clear_all;
}
void ApplicationManager::set_stop_recording(int flag)
{
	stop_record = flag;
}
void ApplicationManager::set_start_action(bool l)//show user  start recording 
{
	start_action = l;
}
bool   ApplicationManager::get_start_action()
{
	return start_action;
}
int ApplicationManager::get_stop_record()
{
	return stop_record;
}
void ApplicationManager::record(Action* t, ActionType type_t)
{

	if ((type_t != START_RECORDING) && (type_t != STOP_RECORDING) && (type_t != PLAY_RECORDING) && (type_t != SAVE_GRAPH) && (type_t != LOAD_GRAPH) && (type_t != SWITCH_DRAW_PLAY_MODE) && (type_t != EXIT))
		if (record_count < Max_Recording)
		{
			record_list[record_count] = t;
			record_count++;
		}
}
void ApplicationManager::delet_all_figure()//delete figures from figlist
{
	if (FigCount < MaxFigCount)
	{
		for (int i = 0; i < FigCount; i++)
		{

			FigList[i] = NULL;
		}
		FigCount = 0;
	}
}
void ApplicationManager::play_recording()
{

	bool t;
	for (int i = 0; i < record_count; i++)
	{
		t = record_list[i]->Execute(0);
		Sleep(1000);

	}


}