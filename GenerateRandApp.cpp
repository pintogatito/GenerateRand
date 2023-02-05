/***************************************************************
 * Name:      GenerateRandApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-02-05
 * Copyright:  ()
 * License:
 **************************************************************/

#include "GenerateRandApp.h"

//(*AppHeaders
#include "GenerateRandMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(GenerateRandApp);

bool GenerateRandApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	GenerateRandFrame* Frame = new GenerateRandFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
