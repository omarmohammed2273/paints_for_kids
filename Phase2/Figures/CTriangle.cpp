#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertex1 = P1;
	Vertex2 = P2;
	Vertex3 = P3;
	TypeID = triangle;
}
CTriangle::CTriangle()//default constructor for load action
{}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a rectangle on the screen	
	pOut->DrawTri(Vertex1, Vertex2, Vertex3, FigGfxInfo, Selected);
}



//my addition
void CTriangle::PrintInfo(Output* pOut)  //print all figure info on the status bar
{
	//get strings from variables
	string id=to_string(ID);
	string Xfirst1=to_string(Vertex1.x);
	string Yfirst1=to_string(Vertex1.y);
	string Xfirst2=to_string(Vertex2.x);
	string Yfirst2=to_string(Vertex2.y);
	string Xfirst3=to_string(Vertex3.x);
	string Yfirst3=to_string(Vertex3.y);

	pOut->PrintMessage("The id of this figure is "+id+", The corners coordinates are ("+Xfirst1+","+Yfirst1+"), ("+Xfirst2+","+Yfirst2+"),("
		+Xfirst3+","+Yfirst3+")");

}

bool CTriangle::CheckFigure(int x,int y) //check if this point belong to this figure
{
	float Area = area(Vertex1.x,Vertex1.y,Vertex2.x,Vertex2.y,Vertex3.x,Vertex3.y);
	float Area1 = area(x,y,Vertex2.x,Vertex2.y,Vertex3.x,Vertex3.y);
	float Area2 = area(Vertex1.x,Vertex1.y,x,y,Vertex3.x,Vertex3.y);
	float Area3 = area(Vertex1.x,Vertex1.y,Vertex2.x,Vertex2.y,x,y);
	if(Area == (Area1+Area2+Area3))
		return true;
	return false;
}

Point CTriangle::NewCoor(int x,int y) //set new coordinate
{
	Point Center;
	Center.x = (Vertex1.x+Vertex2.x+Vertex3.x)/3;
	Center.y = (Vertex1.y+Vertex2.y+Vertex3.y)/3;
	Point old = Center;
	x -= Center.x;
	y -= Center.y;

	Vertex1.x += x;
	Vertex1.y += y;
	Vertex2.x += x;
	Vertex2.y += y;
	Vertex3.x += x;
	Vertex3.y += y;
	return old;

}

void   CTriangle::Save(ofstream& OutFile)//save the hexagon's information 
{
	OutFile << "TRING" << "\t";
	CFigure::Save(OutFile);
	OutFile << Vertex1.x << "\t" << Vertex1.y << "\t" << Vertex2.x<<"\t"<< Vertex2.y<< "\t" << Vertex3.x << "\t" <<Vertex3.y<< "\t";
	OutFile << get_draw_color(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << get_draw_color(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;


}

bool CTriangle::IsFromMe(int i)
{
	if (TypeID == i)
		return true;
	return false;
}

CTriangle::CTriangle(CTriangle*& t) :CFigure(t->FigGfxInfo)
{
	Vertex1 = t->Vertex1;
	Vertex2 = t->Vertex2;
	Vertex3 = t->Vertex3;
	ID = t->ID;
	Selected = t->Selected;
	myDraw = t->myDraw;
	TypeID = t->TypeID;
}
void CTriangle::Load(ifstream& Infile)// load triangle from save file 
{
	CFigure::Load(Infile);
	string s;
	Infile >> Vertex1.x >> Vertex1.y >> Vertex2.x >> Vertex2.y >> Vertex3.x >> Vertex3.y;
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
	pOut->DrawTri(Vertex1, Vertex2, Vertex3, FigGfxInfo, 1);
}