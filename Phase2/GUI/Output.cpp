#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1450;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();


	//my addition
	sizeSqu = 140; //size of square
	sizeHex = 140; //size of hexagon
	Filled = false; //mode of filling
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}
void  Output::set_crnt_draw_color(color c)//set current draw color 
{
	UI.DrawColor = c;
}


void  Output::set_crnt_fill_color(color c)//set current fill color
{
	UI.FillColor = c;

}
//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Tringle.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_HHH.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circle.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_DRAWING_COLOR] = "images\\MenuItems\\Menu_drawing_color.jpg";
	MenuItemImages[ITM_FILLING_COLOR] = "images\\MenuItems\\Menu_filling_color.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_Orange.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";

	//my addition
	MenuItemImages[ITM_SETFILLED] = "images\\MenuItems\\set_filled.jpg";


	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delet.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImages[ITM_CLEAR_ALL] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImages[ITM_START_RECORDING] = "images\\MenuItems\\Menu_Start.jpg";
	MenuItemImages[ITM_STOP_RECORDING] = "images\\MenuItems\\Menu_Stop.jpg";
	MenuItemImages[ITM_PLAY_RECORDING] = "images\\MenuItems\\Menu_Play_record.jpg";
	MenuItemImages[ITM_SAVE_GRAPH] = "images\\MenuItems\\Menu_Save_graph.jpg";
	MenuItemImages[ITM_LOAD_GRAPH] = "images\\MenuItems\\Menu_Load_graph.jpg";
	MenuItemImages[ITM_SWITCH_PLAY_MOOD] = "images\\MenuItems\\Menu_Switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string PlayModeItem[PLAY_ITM_COUNT];
	PlayModeItem[ITM_FIGURE_TYPE] = "images\\PlayModeItem\\Menu_figure_type.jpg";
	PlayModeItem[ITM_FIGURE_FILL_COLOR] = "images\\PlayModeItem\\Menu_fill_color.jpg";
	PlayModeItem[ITM_FIGURE_TYPE_AND_FILL_COLOR] = "images\\PlayModeItem\\Menu_figure_type_and_fill_clolr.jpg";
	PlayModeItem[ITM_SWITCH_PLAY_MOOD_PLAY] = "images\\PlayModeItem\\Menu_Switch.jpg";
	PlayModeItem[ITM_EXIT_PLAY] = "images\\PlayModeItem\\Menu_Exit.jpg";
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayModeItem[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawSqu(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;


	pWind->DrawRectangle((P1.x)-(sizeSqu/2), (P1.y)-(sizeSqu/2), (P1.x)+(sizeSqu/2), (P1.y)+(sizeSqu/2), style);

}
void Output::DrawTri(Point P1,Point P2,Point P3, GfxInfo RectGfxInfo, bool selected) const  //Draw a tringle
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	pWind->DrawTriangle(P1.x,P1.y,P2.x,P2.y,P3.x,P3.y,style);
}
void Output::DrawHex(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	int arrX[6];
	int arrY[6];
	{
		arrX[0]=P1.x-.5*sizeHex;     arrY[0]=P1.y-.5*sizeHex*sqrt(3);
		arrX[1]=P1.x+.5*sizeHex;     arrY[1]=P1.y-.5*sizeHex*sqrt(3);
		arrX[2]=P1.x+sizeHex;     arrY[2]=P1.y;
		arrX[3]=P1.x+.5*sizeHex;     arrY[3]=P1.y+.5*sizeHex*sqrt(3);
		arrX[4]=P1.x-.5*sizeHex;     arrY[4]=P1.y+.5*sizeHex*sqrt(3);
		arrX[5]=P1.x-sizeHex;     arrY[5]=P1.y;
	}
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	pWind->DrawPolygon(arrX,arrY,6,style);

}
void Output::DrawCir(Point P1,Point P2, GfxInfo RectGfxInfo, bool selected) const  //Draw a circle
{
	float r=sqrt(pow(P1.x-P2.x,2)+pow(P1.y-P2.y,2));
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	pWind->DrawCircle(P1.x,P1.y,r,style);

}




//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}



//my addition
int Output::getsizeSqu()//get size of square
{return sizeSqu;}

int Output::getsizeHex() //get size of hexagon
{return sizeHex;}


void Output::setFilled(bool change) //change mode of filling
{Filled = change;}

bool Output::getFilled() //get mode of filling
{return Filled;}

