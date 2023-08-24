#include "CHexagon.h"
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	TypeID = hexagon;
}
CHexagon::CHexagon() //default constructor for load action 
{}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a Hexagon on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}


//my addition
void CHexagon::PrintInfo(Output* pOut) //print all figure info on the status bar
{
	//get strings from variables
	size= pOut->getsizeHex();
	string sizestr = to_string(size);
	string id=to_string(ID);
	string centerX=to_string(Center.x);
	string centerY=to_string(Center.y);
	pOut->PrintMessage("The id of this figure is "+id+", The center coordinates are ("+centerX+", "+centerY+"), The width is "+sizestr);

}


bool CHexagon::CheckFigure(int x,int y) //check if this point belong to this figure
{
	//divide the hexagon to one rectangle and two triangles
	if(x>=(Center.x-70) && x<=(Center.x+70))
	{
		if(y>=(Center.y-70*sqrt(3)) && y<=(Center.y+70*sqrt(3))) //check if point belongs to rectangle
			return true;
	}else if(x<(Center.x-70))
	{
		float Area = area(Center.x-140,Center.y,Center.x-70,Center.y-70*sqrt(3),Center.x-70,Center.y+70*sqrt(3));
		float Area1 = area(x,y,Center.x-70,Center.y-70*sqrt(3),Center.x-70,Center.y+70*sqrt(3));
		float Area2 = area(Center.x-140,Center.y,x,y,Center.x-70,Center.y+70*sqrt(3));
		float Area3 = area(Center.x-140,Center.y,Center.x-70,Center.y-70*sqrt(3),x,y);
		if(Area == (Area1+Area2+Area3)) //check if point belongs to triangle
			return true;
	}else if(x>(Center.x+70)){
		float Area = area(Center.x+140,Center.y,Center.x+70,Center.y-70*sqrt(3),Center.x+70,Center.y+70*sqrt(3));
		float Area1 = area(x,y,Center.x+70,Center.y-70*sqrt(3),Center.x+70,Center.y+70*sqrt(3));
		float Area2 = area(Center.x+140,Center.y,x,y,Center.x+70,Center.y+70*sqrt(3));
		float Area3 = area(Center.x+140,Center.y,Center.x+70,Center.y-70*sqrt(3),x,y);
		if(Area == (Area1+Area2+Area3)) //check if point belongs to triangle
			return true;

	}

	return false;

}

Point CHexagon::NewCoor(int x, int y) //set new coordinate
{
	Point old = Center;
	Center.x = x;
	Center.y = y;
	return old;
}
void  CHexagon::Save(ofstream& OutFile)//save the hexagon's information 
{
	OutFile << "HEXA" << "\t";
	CFigure::Save(OutFile);
	OutFile << Center.x << "\t" << Center.y << "\t";
	OutFile << get_draw_color(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << get_draw_color(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;

	
}

bool CHexagon::IsFromMe(int i)
{
	if (TypeID==i)
		return true;
	return false;
}

CHexagon::CHexagon(CHexagon*& h):CFigure(h->FigGfxInfo)
{
	Center = h->Center;
	size = h->size;
	ID = h->ID;
	Selected = h->Selected;
	myDraw = h->myDraw;
	TypeID = h->TypeID;
}
void CHexagon::Load(ifstream& Infile)// load hexagon from save file 
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
	pOut->DrawHex(Center, FigGfxInfo, 1);

}