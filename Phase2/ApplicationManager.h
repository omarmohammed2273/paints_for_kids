#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Actions\Action.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures


	//addition
	enum { MaxUn_REAct = 5 };
	enum { MaxActTot = 200 };
	enum { MaxDelFig = 200 };
	enum { Type = 1, FillColor, TypeAndFillColor };
	enum { Max_Recording = 20 };
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	//recording actions
	Action* record_list[Max_Recording];
	int record_count;
	bool start_action;
	bool beginning_of_program;// to know if the user use the start recording at the beginning of the program or not 
	bool after_clear_all;// to know if user use the start recording immediately after a clear all or not 
	int stop_record;// to stop recording action 
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	//addition
	Action *LastAct;

	Action* UndoRedoList[MaxUn_REAct];
	int UnREActCount; //Actual number of actions can be undo
	Action *ActUndo_Redo; //pointer of action in undo and redo list

	Action *ActTotlist[MaxActTot];
	int ActTotcount;

	int DelFigcount;
	CFigure *DelFiglist[MaxDelFig];

public:	
	ApplicationManager(); 
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	//my addition
	void ClearAll();
	void setSelFigure(CFigure *ptr); //set the pointer of selected figure
	CFigure* getSelFigure(); //get the pointer of selected figure
	void DeleteFig(CFigure* Dele); //delete the selected figure and update the figure list

	void AddUndoAcion(Action *last);  //add action to undo list
	bool setUndo();  //set the pointer of action which will be undo
	bool setRedo();  //set the pointer of action which will be redo
	Action *getUndo();  //get pointer of action will be undo
	Action *getRedo();  //get pointer of action will be redo

	Action *getLastAct();
	void delet_all_figure();
	void SaveAll(ofstream& OutFile);//save all fiqures
	int get_figcount();
	CFigure* GetFigure(int index);
	string GetFigureName(int index);
	string GetFigureColor(int index);
	int GetCountColor(color c);
	bool ISFigFilled();
	int GetFigure_ColorCounr(color c, int id);


	int getCountPlayMode(int type);
	void ReMakeCopy(int Count);
	//Rocordings action 
	bool get_beginning_of_program();
	bool get_immediatel_after_clear_all();
	void set_stop_recording(int flag);// to show when user use the stop action 
	void record(Action* t, ActionType type_t);
	void play_recording();
	void set_start_action(bool l);//show user  start recording 
	bool  get_start_action();
	int get_stop_record();
	bool sound;
};

#endif