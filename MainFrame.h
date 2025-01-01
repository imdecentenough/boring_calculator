#include <wx/wx.h>
#include "calculate.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	int taskCount = 0;
	wxPanel* panel = new wxPanel(this);
	wxStaticText* display;
	wxFont* displayFont = new wxFont(15, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_SEMIBOLD);

	void add_zero(wxCommandEvent& event); // all of these events just use the changeDisplay operation for simplicity. 
	void add_one(wxCommandEvent& event);
	void add_two(wxCommandEvent& event);
	void add_three(wxCommandEvent& event);
	void add_four(wxCommandEvent& event);
	void add_five(wxCommandEvent& event);
	void add_six(wxCommandEvent& event);
	void add_seven(wxCommandEvent& event);
	void add_eight(wxCommandEvent& event);
	void add_nine(wxCommandEvent& event);
	void add_add(wxCommandEvent& event);
	void add_sub(wxCommandEvent& event);
	void add_mul(wxCommandEvent& event);
	void add_div(wxCommandEvent& event);
	void equals(wxCommandEvent& event); // runs the calculate's calculateFull's operation based on the display.
	void clearDisplay(wxCommandEvent& event);

	void changeDisplay(bool x, int y, char z);

	calculate runCalculate;

	wxDECLARE_EVENT_TABLE();
};

