#include "CRectangle.h"
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	TypeID = rectangle;
}
CRectangle::CRectangle()//default constructor for load action 
{}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}


//my addition
void CRectangle::PrintInfo(Output* pOut)
{
	//get strings from variables
	string id=to_string(ID);
	string Xcorner1=to_string(Corner1.x);
	string Ycorner1=to_string(Corner1.y);
	string Xcorner2=to_string(Corner2.x);
	string Ycorner2=to_string(Corner2.y);
	string width =to_string(abs(Corner1.x-Corner2.x));
	string  hieght=to_string(abs(Corner1.y-Corner2.y));

	pOut->PrintMessage("The id of this figure is "+id+", The first corner coordinates are ("+Xcorner1+", "+Ycorner1+
		") and the second corner coordinates are ("+Xcorner2+", "+Ycorner2+"), The length and the width are "+width+" "+hieght);

}
bool CRectangle::CheckFigure(int x,int y) //check if this point belong to this figure
{
	int Xmax=Corner1.x;
	int Xmin=Corner2.x;
	if(Xmin>Xmax)
	{
		Xmin = Corner1.x;
		Xmax = Corner2.x;
	}
	int Ymax=Corner1.y;
	int Ymin=Corner2.y;
	if(Ymin>Ymax)
	{
		Ymin = Corner1.y;
		Ymax = Corner2.y;
	}

	if(x>=Xmin && x<=Xmax)
		if(y>=Ymin && y<=Ymax)
			return true;
	return false;

}

Point CRectangle::NewCoor(int x, int y) //set new coordinate
{
	Point old;
	old.x = (Corner1.x+Corner2.x)/2;
	old.y = (Corner1.y+Corner2.y)/2;
	int width = abs(Corner1.x-Corner2.x);
	int hieght = abs(Corner1.y-Corner2.y);
	Corner1.x = x-.5*width;
	Corner1.y = y-.5*hieght;
	Corner2.x = x+.5*width;
	Corner2.y = y+.5*hieght;
	return old;
}
void   CRectangle::Save(ofstream& OutFile)//save the hexagon's information 
{
	OutFile << "RECT" << "\t";
	CFigure::Save(OutFile);
	OutFile << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x<< "\t" << Corner1.y<< "\t";
	OutFile << get_draw_color(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << get_draw_color(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;

}

bool CRectangle::IsFromMe(int i)
{
	if (TypeID == i)
		return true;
	return false;
}


CRectangle::CRectangle(CRectangle*& r) :CFigure(r->FigGfxInfo)
{
	Corner1 = r->Corner1;
	Corner2 = r->Corner2;
	ID = r->ID;
	Selected = r->Selected;
	myDraw = r->myDraw;
	TypeID = r->TypeID;
}
void CRectangle::Load(ifstream& Infile)// load rectangel from save file 
{
	CFigure::Load(Infile);
	string s;
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
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
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, 1);

}