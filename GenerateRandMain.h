/***************************************************************
 * Name:      GenerateRandMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-02-05
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef GENERATERANDMAIN_H
#define GENERATERANDMAIN_H

//(*Headers(GenerateRandFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
//*)

class GenerateRandFrame: public wxFrame
{
    public:

        GenerateRandFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GenerateRandFrame();

    private:

        //(*Handlers(GenerateRandFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnToggleButton1Toggle(wxCommandEvent& event);
        //*)

        //(*Identifiers(GenerateRandFrame)
        static const long ID_TOGGLEBUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(GenerateRandFrame)
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxToggleButton* ToggleButton1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GENERATERANDMAIN_H
