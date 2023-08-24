#include "CCircle.h"
#include<fstream>
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = P2;
	TypeID = circle;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCir(Center,Radius, FigGfxInfo, Selected);
	
}

//my addition
void CCircle::PrintInfo(Output* pOut) //print info
{
	//get strings from variables
	string id=to_string(ID);
	string centerX=to_string(Center.x);
	string centerY=to_string(Center.y);
	int radius = sqrt(pow(Center.x-Radius.x,2)+pow(Center.y-Radius.y,2));
	string Sradius = to_string(radius);
	pOut->PrintMessage("The id of this figure is "+id+", The center coordinates are ("+centerX+", "+centerY+
		"), The radius is "+Sradius);
}

bool CCircle::CheckFigure(int x,int y) //check if point belong to circle
{
	if(sqrt(pow(x-Center.x,2)+pow(y-Center.y,2))<=sqrt(pow(Center.x-Radius.x,2)+pow(Center.y-Radius.y,2)))
		return true;
	else
		return false;
}

Point CCircle::NewCoor(int x,int y) //set new coordinate
{
	Point old = Center;
	int a = Center.x-Radius.x;
	int b = Center.y-Radius.y;
	Center.x = x;
	Center.y = y;
	Radius.x = x+a;
	Radius.y = y+b;
	return old;
}
void  CCircle::Save(ofstream& OutFile)// save circle's information 
{
	
	OutFile << "CIRC" << "\t";
	CFigure::Save(OutFile);
	OutFile << Center.x << "\t" << Center.y << "\t" << Radius.x << "\t" << Radius.y << "\t";
	OutFile << get_draw_color(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << get_draw_color(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;

	

}

bool CCircle::IsFromMe(int i)
{
	if (this->TypeID == i)
		return true;
	return false;
}


CCircle::CCircle(CCircle*& c) :CFigure(c->FigGfxInfo)
{
	Center = c->Center;
	Radius = c->Radius;
	ID = c->ID;
	Selected = c->Selected;
	myDraw = c->myDraw;
	TypeID = c->TypeID;
}
void CCircle::Load(ifstream& Infile)
{
	
	CFigure::Load(Infile);
	string s;
	Infile >> Center.x >> Center.y >> Radius.x >> Radius.y;
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
	pOut->DrawCir(Center,  Radius, FigGfxInfo , 1);

}
CCircle::CCircle()//default constructor for load action 
{}