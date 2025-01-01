#include "app.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(app);

bool app::OnInit() {
	MainFrame* mainFrame = new MainFrame("Calculator");
	mainFrame->SetClientSize(250, 275);
	mainFrame->SetMaxClientSize(wxSize(250, 275));
	mainFrame->SetMinClientSize(wxSize(250, 275));
	mainFrame->SetBackgroundColour(wxColour(160, 160, 160));
	mainFrame->Center();
	mainFrame->Show();
	return true;
}
