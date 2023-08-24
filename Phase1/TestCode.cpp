#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2,P3;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearDrawArea();

	/// 2.2- Square Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Square, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Square, Normal and Highlighted

	// 2.2.1 - Drawing non-filled square
	pOut->PrintMessage("Drawing a Square ==> non-filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawSqu(P1, gfxInfo, false);

	// 2.2.2 - Drawing highlighted non-filled square
	pOut->PrintMessage("Drawing a Square ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawSqu(P1, gfxInfo, true);

	// 2.2.3 - Drawing a filled square
	pOut->PrintMessage("Drawing a Square ==> filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawSqu(P1, gfxInfo, false);


	// 2.2.4 - Drawing a highlighted filled square
	pOut->PrintMessage("Drawing a Square ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawSqu(P1, gfxInfo, true);


	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearDrawArea();

	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Triangle in all possible states

	// 2.3.1 - Drawing non-filled Triangle
	pOut->PrintMessage("Drawing a Triangle ==> non-filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawTri( P1, P2, P3,  gfxInfo, false);

	// 2.3.2 - Drawing highlighted non-filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawTri( P1, P2, P3,  gfxInfo, true);

	// 2.3.3 - Drawing a filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> filled,  Click three points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawTri( P1, P2, P3,  gfxInfo, false);


	// 2.3.4 - Drawing a highlighted filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawTri( P1, P2, P3,  gfxInfo, true);



	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearDrawArea();

	/// 2.4- Hexagon Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Hexagon in all possible states

	// 2.4.1 - Drawing non-filled Hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> non-filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawHex( P1, gfxInfo, false);

	// 2.4.2 - Drawing highlighted non-filled Hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawHex( P1, gfxInfo, true);

	// 2.4.3 - Drawing a filled hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawHex( P1,  gfxInfo, false);

	// 2.4.4 - Drawing a highlighted filled hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawHex( P1, gfxInfo, true);


	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearDrawArea();

	/// 2.5- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Circle in all possible states

	// 2.5.1 - Drawing non-filled Circle
	pOut->PrintMessage("Drawing a Circle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawCir( P1,P2, gfxInfo, false);

	// 2.5.2 - Drawing highlighted non-filled circle
	pOut->PrintMessage("Drawing a Circle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawCir( P1,P2, gfxInfo, true);

	// 2.5.3 - Drawing a filled circle
	pOut->PrintMessage("Drawing a Circle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawCir(P1,P2,gfxInfo,false);

	// 2.5.4 - Drawing a highlighted filled circle
	pOut->PrintMessage("Drawing a Circle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawCir(P1,P2,gfxInfo,true);


	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered" then print the string

	string test= pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	pOut->PrintMessage("You Entered "+test);

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();
		switch (ActType)
		{
		case DRAW_RECT:
			pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
			break;
		case DRAW_TRI:
			pOut->PrintMessage("Action: Draw a Triangle , Click anywhere");
			break;
		case DRAW_SQ:
			pOut->PrintMessage("Action: Draw a Square , Click anywhere");
			break;
		case DRAW_CIRC:
			pOut->PrintMessage("Action: Draw a Circle , Click anywhere");
			break;
		case DRAW_HEX:
			pOut->PrintMessage("Action: Draw a Hexagon , Click anywhere");
			break;




		case SELECT_ONE:
			pOut->PrintMessage("Action: Select Icon , Click anywhere");
			break;
		case DRAW_COL:
			pOut->PrintMessage("Action: Draw Color Icon , Click anywhere");
			break;
		case FILL_COL:
			pOut->PrintMessage("Action: Fill Color Icon , Click anywhere");
			break;

		case DEL:
			pOut->PrintMessage("Action: Delete Icon , Click anywhere");
			break;
		case MOVE:
			pOut->PrintMessage("Action: Move Icon , Click anywhere");
			break;

		case START_RECORDING:
			pOut->PrintMessage("Action: Start Recordig Icon , Click anywhere");
			break;
		case STOP_RECORDING:
			pOut->PrintMessage("Action: Stop Recording Icon , Click anywhere");
			break;
		case PLAY_RECORDING:
			pOut->PrintMessage("Action: Play Recording Icon , Click anywhere");
			break;
		case SAVE_GRAPH:
			pOut->PrintMessage("Action: Save Graph Icon , Click anywhere");
			break;
		case LOAD_GRAPH:
			pOut->PrintMessage("Action: Load Graph Icon , Click anywhere");
			break;

			/*case SWITCH_DRAW_PLAY_MODE:
			pOut->PrintMessage("Action: Switch Draw-Play Mode Icon , Click anywhere");
			/*if (UI.InterfaceMode == MODE_DRAW)
			{
			pOut->CreatePlayToolBar();
			}
			else
			{
			pOut->CreateDrawToolBar();
			}
			break;
			*/




		case COL_BLACK:
			pOut->PrintMessage("Action: Black Color Area , Click anywhere");
			break;
		case COL_BLUE:
			pOut->PrintMessage("Action: Blue Color Area , Click anywhere");
			break;
		case COL_YELLOW:
			pOut->PrintMessage("Action: Yellow Color Area , Click anywhere");
			break;
		case COL_ORANGE:
			pOut->PrintMessage("Action: Orange Color Area , Click anywhere");
			break;
		case COL_GREEN:
			pOut->PrintMessage("Action: Green Color Area , Click anywhere");
			break;
		case COL_RED:
			pOut->PrintMessage("Action: Red Color Areae , Click anywhere");
			break;


		case MAKE_UNDO:
			pOut->PrintMessage("Action: Undo , Click anywhere");
			break;
		case MAKE_REDO:
			pOut->PrintMessage("Action: Redo , Click anywhere");
			break;
		case CLR:
			pOut->PrintMessage("Action: Clear All , Click anywhere");
			break;
		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case TO_DRAW:
			pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
			pOut->ClearToolBar();
			pOut->CreateDrawToolBar();
			break;

		case TO_PLAY:
			pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
			pOut->ClearToolBar();
			pOut->CreatePlayToolBar();
			break;
		case FIGURE_TYPE:
			pOut->PrintMessage("Action: figure Type Icon, Click anywhere");
			break;
		case FIGURE_FILL_COLOR:
			pOut->PrintMessage("Action: figure Fill Color Icon, Click anywhere");
			break;
		case FIGURE_TYPE_AND_FILL_COLOR:
			pOut->PrintMessage("Action: figure Type And Fill Color Icon, Click anywhere");
			break;


			///TODO: Add more cases for the other action types


		case EXIT:				
			break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}

