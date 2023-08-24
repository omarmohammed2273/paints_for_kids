#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,
	DRAW_SQ,
	DRAW_CIRC,
	DRAW_HEX,

	//SELECT AND COLORS
	SELECT_ONE,
	DRAW_COL,
	FILL_COL,
	COL_BLACK,
	COL_BLUE,
	COL_YELLOW,
	COL_ORANGE,
	COL_GREEN,
	COL_RED,
	SET_FILLED,
	
	//Delete and Remove
	DEL,
	MOVE,
	//Recording and Save and Switch
	START_RECORDING,
	STOP_RECORDING,
	PLAY_RECORDING,
	SAVE_GRAPH,
	LOAD_GRAPH,
	SWITCH_DRAW_PLAY_MODE,
	//UNDO AND REDO 
	MAKE_UNDO,
	MAKE_REDO,
	CLR,
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,		//A click on the status bar
	FIGURE_TYPE,
	FIGURE_FILL_COLOR,
	FIGURE_TYPE_AND_FILL_COLOR
	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif