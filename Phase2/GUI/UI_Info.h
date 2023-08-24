#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_SQUARE,    //Square item in menu
	ITM_TRIANGLE,	//Tringle item in menu
	ITM_HEXAGON,    //Hexagon item in menu
	ITM_CIRCLE,     //Circle item in menu
	ITM_SELECT, //Select item in menu
	ITM_DRAWING_COLOR,
	ITM_FILLING_COLOR,
	ITM_BLACK,     //Black item in menu
	ITM_YELLOW,
	ITM_ORANGE,
	ITM_RED,
	ITM_GREEN,
	ITM_BLUE,
	ITM_SETFILLED,

	ITM_DELETE,
	ITM_MOVE,
	ITM_UNDO,
	ITM_REDO,
	ITM_CLEAR_ALL,
	ITM_START_RECORDING,
	ITM_STOP_RECORDING,
	ITM_PLAY_RECORDING,
	ITM_SAVE_GRAPH,
	ITM_LOAD_GRAPH,
	ITM_SWITCH_PLAY_MOOD,
	ITM_EXIT,
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here

	ITM_FIGURE_TYPE,
	ITM_FIGURE_FILL_COLOR,
	ITM_FIGURE_TYPE_AND_FILL_COLOR,
	ITM_SWITCH_PLAY_MOOD_PLAY,
	ITM_EXIT_PLAY,
	//TODO: Add more items names here

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif