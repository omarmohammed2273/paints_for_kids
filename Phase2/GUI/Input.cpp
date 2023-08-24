#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_SQ;
			case ITM_TRIANGLE: return DRAW_TRI;
			case ITM_CIRCLE: return DRAW_CIRC;
			case ITM_HEXAGON: return DRAW_HEX;

			case ITM_SELECT: return SELECT_ONE;
			case ITM_DRAWING_COLOR: return DRAW_COL;
			case ITM_FILLING_COLOR: return FILL_COL;

			//my addition
			case ITM_SETFILLED: return SET_FILLED;

			case ITM_DELETE: return DEL;
			case ITM_MOVE: return MOVE;
				//RECORDING
			case ITM_START_RECORDING: return START_RECORDING;
			case ITM_STOP_RECORDING: return STOP_RECORDING;
			case ITM_PLAY_RECORDING: return PLAY_RECORDING;
				//GRAPH
			case ITM_SAVE_GRAPH: return SAVE_GRAPH;
			case ITM_LOAD_GRAPH: return LOAD_GRAPH;
			case ITM_SWITCH_PLAY_MOOD: return (UI.InterfaceMode == MODE_DRAW) ? TO_PLAY : TO_DRAW;
				//COLORS
			case ITM_BLACK: return COL_BLACK;
			case ITM_BLUE: return COL_BLUE;
			case ITM_YELLOW: return COL_YELLOW;
			case ITM_ORANGE: return COL_ORANGE;
			case ITM_GREEN: return COL_GREEN;
			case ITM_RED: return COL_RED;


				//UNDO AND REDO
			case ITM_UNDO: return MAKE_UNDO;
			case ITM_REDO: return MAKE_REDO;
			case ITM_CLEAR_ALL: return CLR;
			case ITM_EXIT: return EXIT;	
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action

		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_FIGURE_TYPE: return FIGURE_TYPE;
			case ITM_FIGURE_FILL_COLOR: return FIGURE_FILL_COLOR;
			case ITM_FIGURE_TYPE_AND_FILL_COLOR: return FIGURE_TYPE_AND_FILL_COLOR;
			case ITM_SWITCH_PLAY_MOOD_PLAY: return (UI.InterfaceMode == MODE_DRAW) ? TO_PLAY : TO_DRAW;
			case ITM_EXIT_PLAY: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		//return TO_PLAY;	//just for now. This should be updated
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
