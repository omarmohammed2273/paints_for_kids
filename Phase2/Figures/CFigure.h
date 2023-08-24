#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include<fstream>
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	
	/// Add more parameters if needed.
	//my addition
	color myDraw; //original color
	enum{circle=0,hexagon,rectangle,square,triangle};
	
public:
	//virtual CFigure(CFigure*&)
	int TypeID;
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();//default constructor for load action 
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr, bool change);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	//save & load 
	virtual void Save(ofstream &OutFile) ;	//Save the figure's ID
	virtual void Load(ifstream& Infile);	//Load the figure parameters to the file
	color convert_string_to_color(string s);
	string get_draw_color(color c);//convert draw_color to string
	string get_fill_color(color c);//convert fill_color to string

	//my addition
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual bool CheckFigure(int x,int y)=0;    //check if this point belong to this figure
	void select(); //select figure by changing drawing color to highlighted
	void Unselect(); //unselect by return to its original color
	float area(int x1, int y1, int x2, int y2, int x3, int y3);  //get the area of triangle
	void setId(int id); //to set ID
	color getmyDraw();  //return original color
	virtual Point NewCoor(int x,int y)=0; //set new coordinate
	virtual bool IsFromMe(int i)=0;
	color GetFillColor();
	bool IsFilled();

	
};

#endif