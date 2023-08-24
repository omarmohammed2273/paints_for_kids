#include "CFigure.h"
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	myDraw = UI.DrawColor;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}
CFigure::CFigure()//default constructor for load action
{}
void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	
	//my addition
	if(Dclr==UI.HighlightColor)
		myDraw = FigGfxInfo.DrawClr;//store its original color
	FigGfxInfo.DrawClr = Dclr; 
}

void CFigure::ChngFillClr(color Fclr, bool change)
{	
	FigGfxInfo.isFilled = change;
	FigGfxInfo.FillClr = Fclr; 
}


//my addition
float CFigure::area(int x1, int y1, int x2, int y2, int x3, int y3) //get area of triangle
{
	return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

void CFigure::setId(int id) //set id
{ID = id;}

color CFigure::getmyDraw() //return original color
{return myDraw;}


color CFigure::GetFillColor()
{

	return FigGfxInfo.FillClr;
}

bool CFigure::IsFilled()
{
	if (this != NULL)
		return this->FigGfxInfo.isFilled;
	else return NULL;
}

void CFigure::select() //select figure by changing drawing color to highlighted
{
	SetSelected(true);
	ChngDrawClr(UI.HighlightColor);
}

void CFigure::Unselect() //unselect by return to its original color
{
	SetSelected(false);
	ChngDrawClr(getmyDraw());
}
// save &load
void  CFigure::Save(ofstream& OutFile)// save the figure's id 
{
	OutFile << ID<<"\t" ;
}
string  CFigure::get_draw_color(color c)//convert draw_color to string
{
	if (c == GREEN)
		return "Green";
	else if (c == BLUE)
		return "BULE";
	else if (c == BLACK)
		return "BLACK";
	else if (c == RED)
		return "RED";
	else if (c == ORANGE)
		return "ORANGE";
	else if (c == YELLOW)
		return "YELLOW";

}
string CFigure::get_fill_color(color c)//convert fill_color to string
{
	if (c == GREEN)
		return "Green";
	else if (c == BLUE)
		return "BULE";
	else if (c == BLACK)
		return "BLACK";
	else if (c == RED)
		return "RED";
	else if (c == ORANGE)
		return "ORANGE";
	else if (c == YELLOW)
		return "YELLOW";

}
void CFigure::Load(ifstream& Infile)
{
	Infile >> ID;
}
color CFigure::convert_string_to_color(string s)
{
	if (s == "GREEN")
		return GREEN;
	else if (s == "BLUE")
		return BLUE;
	else if (s == "BLACK")
		return BLACK;
	else if (s == "RED")
		return RED;
	else if (s == "ORANGE")
		return ORANGE;
	else if (s == "YELLOW")
		return YELLOW;
}