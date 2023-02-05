/***************************************************************
 * Name:      GenerateRandMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-02-05
 * Copyright:  ()
 * License:
 **************************************************************/

#include "GenerateRandMain.h"
#include <wx/msgdlg.h>
#include <fstream>
#include "inc/Generator.hpp"

//(*InternalHeaders(GenerateRandFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(GenerateRandFrame)
const long GenerateRandFrame::ID_TOGGLEBUTTON1 = wxNewId();
const long GenerateRandFrame::ID_STATICTEXT1 = wxNewId();
const long GenerateRandFrame::ID_STATICTEXT2 = wxNewId();
const long GenerateRandFrame::ID_STATICTEXT3 = wxNewId();
const long GenerateRandFrame::ID_TEXTCTRL1 = wxNewId();
const long GenerateRandFrame::ID_TEXTCTRL2 = wxNewId();
const long GenerateRandFrame::idMenuQuit = wxNewId();
const long GenerateRandFrame::idMenuAbout = wxNewId();
const long GenerateRandFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GenerateRandFrame,wxFrame)
    //(*EventTable(GenerateRandFrame)
    //*)
END_EVENT_TABLE()

GenerateRandFrame::GenerateRandFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GenerateRandFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(800,600));
    ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("Generar"), wxPoint(336,256), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Generador de texto"), wxPoint(320,80), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Cantidad de caracteres por linea"), wxPoint(128,128), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Cantidad de lineas:"), wxPoint(200,176), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(320,120), wxSize(144,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(320,176), wxSize(144,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&GenerateRandFrame::OnToggleButton1Toggle);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GenerateRandFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GenerateRandFrame::OnAbout);
    //*)
}

GenerateRandFrame::~GenerateRandFrame()
{
    //(*Destroy(GenerateRandFrame)
    //*)
}

void GenerateRandFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void GenerateRandFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void GenerateRandFrame::OnToggleButton1Toggle(wxCommandEvent& event)
{
    Generator g;
    string text;
    int SizeText,NumLines;
    TextCtrl1->GetValue().ToInt(&SizeText);
    TextCtrl2->GetValue().ToInt(&NumLines);

    ofstream fich("cadena.txt");
    for (int i = 0; i < NumLines; ++i)
    {
        text = g.GenRandText(SizeText);
        fich << text << endl;
    }
}
