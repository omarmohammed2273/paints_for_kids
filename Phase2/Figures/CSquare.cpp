#include "CSquare.h"
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	TypeID = square;
}
CSquare::CSquare()//default constructor for load action
{}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSqu(Center, FigGfxInfo, Selected);
}


//my addition
void CSquare::PrintInfo(Output* pOut)
{
	//get strings from variables
	size= pOut->getsizeSqu();
	string sizestr = to_string(size);
	string id=to_string(ID);
	string centerX=to_string(Center.x);
	string centerY=to_string(Center.y);

	pOut->PrintMessage("The id of this figure is "+id+", The center coordinates are ("+centerX+", "+centerY+"), The width is "+sizestr);

}
bool CSquare::CheckFigure(int x,int y) //check if this point belong to this figure
{
	if(x>=(Center.x-70) && x<=(Center.x+70))
		if(y>=(Center.y-70) && y<=(Center.y+70))
			return true;
	return false;

}

Point CSquare::NewCoor(int x, int y) //set new coordinate
{
	Point old = Center;
	Center.x = x;
	Center.y = y;
	return old;
}
void   CSquare::Save(ofstream& OutFile)//save the hexagon's information 
{
	OutFile << "SQUARE" << "\t";
	CFigure::Save(OutFile);
	OutFile << Center.x << "\t" << Center.y << "\t";
	OutFile << get_draw_color(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << get_draw_color(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;




}

bool CSquare::IsFromMe(int i)
{
	if (TypeID == i)
		return true;
	return false;
}

CSquare::CSquare(CSquare*& s) :CFigure(s->FigGfxInfo)
{
	Center = s->Center;
	size = s->size;
	ID = s->ID;
	Selected = s->Selected;
	myDraw = s->myDraw;
	TypeID = s->TypeID;
}
void CSquare::Load(ifstream& Infile)// load Square from save file 
{
	CFigure::Load(Infile);
	string s;
	Infile >> Center.x >> Center.y;
	Infile >> s;
	FigGfxInfo.DrawClr = convert_string_to_color(s);
	Infile >> s;
	if (s == "NO_FILL")
		FigGfxInfo.isFilled = 0;
	else
	{
		FigGfxInfo.isFilled = 1;
		FigGfxInfo.FillClr = convert_string_to_color(s);
	}

	Output* pOut;
	pOut->DrawSqu(Center, FigGfxInfo, 1);
}