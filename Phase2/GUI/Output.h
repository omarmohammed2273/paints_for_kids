#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window

	//my addition
	int sizeSqu; //size of hexagon
	int sizeHex; //size of square
	bool Filled; //mode of filling


public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void  set_crnt_draw_color(color c);//set current draw color 
	void  set_crnt_fill_color(color c);//set current fill color 
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolBar() const;

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	
	///TODO:Make similar functions for drawing all other figure types.
	void DrawSqu(Point P1, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a sqaure
	void DrawTri(Point P1,Point P2,Point P3, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a tringle
	void DrawHex(Point P1, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a hexagon
	void DrawCir(Point P1,Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a circle

	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();


	//my addition
	int getsizeSqu();//get size of square
	int getsizeHex();//get size of hexagon
	void setFilled(bool change);//change mode of filling
	bool getFilled();//get mode of filling
};

#endif