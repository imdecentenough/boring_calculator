#include "MainFrame.h"
#include "calculate.h"
#include <wx/wx.h>
#include <string>

enum {
	BUTTON_ZERO = 0,
	BUTTON_ONE = 1,
	BUTTON_TWO = 2,
	BUTTON_THREE = 3,
	BUTTON_FOUR = 4,
	BUTTON_FIVE = 5,
	BUTTON_SIX = 6,
	BUTTON_SEVEN = 7,
	BUTTON_EIGHT = 8,
	BUTTON_NINE = 9,
	BUTTON_ADD = 10,
	BUTTON_SUB = 11,
	BUTTON_MUL = 12,
	BUTTON_DIV = 13,
	BUTTON_EQUALS = 14,
	BUTTON_CLR = 15
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON_ZERO, MainFrame::add_zero)
	EVT_BUTTON(BUTTON_ONE, MainFrame::add_one)
	EVT_BUTTON(BUTTON_TWO, MainFrame::add_two)
	EVT_BUTTON(BUTTON_THREE, MainFrame::add_three)
	EVT_BUTTON(BUTTON_FOUR, MainFrame::add_four)
	EVT_BUTTON(BUTTON_FIVE, MainFrame::add_five)
	EVT_BUTTON(BUTTON_SIX, MainFrame::add_six)
	EVT_BUTTON(BUTTON_SEVEN, MainFrame::add_seven)
	EVT_BUTTON(BUTTON_EIGHT, MainFrame::add_eight)
	EVT_BUTTON(BUTTON_NINE, MainFrame::add_nine)
	EVT_BUTTON(BUTTON_ADD, MainFrame::add_add)
	EVT_BUTTON(BUTTON_EQUALS, MainFrame::equals)
	EVT_BUTTON(BUTTON_SUB, MainFrame::add_sub)
	EVT_BUTTON(BUTTON_MUL, MainFrame::add_mul)
	EVT_BUTTON(BUTTON_DIV, MainFrame::add_div)
	EVT_BUTTON(BUTTON_CLR, MainFrame::clearDisplay)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	display = new wxStaticText(panel, wxID_ANY, "", wxPoint(0, 25), wxSize(50, 20));
	display->SetFont(*displayFont);

	wxButton* button0 = new wxButton(panel, BUTTON_ZERO, "0", wxPoint(0, 225), wxSize(50, 50));
	wxButton* button1 = new wxButton(panel, BUTTON_ONE, "1", wxPoint(0, 175), wxSize(50, 50));
	wxButton* button2 = new wxButton(panel, BUTTON_TWO, "2", wxPoint(50, 175), wxSize(50, 50));
	wxButton* button3 = new wxButton(panel, BUTTON_THREE, "3", wxPoint(100, 175), wxSize(50, 50));
	wxButton* button4 = new wxButton(panel, BUTTON_FOUR, "4", wxPoint(0, 125), wxSize(50, 50));
	wxButton* button5 = new wxButton(panel, BUTTON_FIVE, "5", wxPoint(50, 125), wxSize(50, 50));
	wxButton* button6 = new wxButton(panel, BUTTON_SIX, "6", wxPoint(100, 125), wxSize(50, 50));
	wxButton* button7 = new wxButton(panel, BUTTON_SEVEN, "7", wxPoint(0, 75), wxSize(50, 50));
	wxButton* button8 = new wxButton(panel, BUTTON_EIGHT, "8", wxPoint(50, 75), wxSize(50, 50));
	wxButton* button9 = new wxButton(panel, BUTTON_NINE, "9", wxPoint(100, 75), wxSize(50, 50));

	wxButton* buttonDivide = new wxButton(panel, BUTTON_DIV, "/", wxPoint(150, 75), wxSize(100, 50));
	wxButton* buttonMultiply = new wxButton(panel, BUTTON_MUL, "X", wxPoint(150, 125), wxSize(100, 50));
	wxButton* buttonSubtract = new wxButton(panel, BUTTON_SUB, "-", wxPoint(150, 175), wxSize(100, 50));
	wxButton* buttonAdd = new wxButton(panel, BUTTON_ADD, "+", wxPoint(150, 225), wxSize(100, 50));
	wxButton* buttonEquals = new wxButton(panel, BUTTON_EQUALS, "=", wxPoint(50, 225), wxSize(50, 50));
	wxButton* buttonClear = new wxButton(panel, BUTTON_CLR, "CLEAR", wxPoint(100, 225), wxSize(50, 50));
}

void MainFrame::add_zero(wxCommandEvent& event) {changeDisplay(true, 0, '_');}
void MainFrame::add_one(wxCommandEvent& event) {changeDisplay(true, 1, '_');}
void MainFrame::add_two(wxCommandEvent& event) {changeDisplay(true, 2, '_');}
void MainFrame::add_three(wxCommandEvent& event) {changeDisplay(true, 3, '_');}
void MainFrame::add_four(wxCommandEvent& event) {changeDisplay(true, 4, '_');}
void MainFrame::add_five(wxCommandEvent& event) {changeDisplay(true, 5, '_');}
void MainFrame::add_six(wxCommandEvent& event) {changeDisplay(true, 6, '_');}
void MainFrame::add_seven(wxCommandEvent& event) {changeDisplay(true, 7, '_');}
void MainFrame::add_eight(wxCommandEvent& event) {changeDisplay(true, 8, '_');}
void MainFrame::add_nine(wxCommandEvent& event) {changeDisplay(true, 9, '_');}

void MainFrame::add_add(wxCommandEvent& event) {changeDisplay(false, 0, '+');}
void MainFrame::add_sub(wxCommandEvent& event) {changeDisplay(false, 0, '-');}
void MainFrame::add_mul(wxCommandEvent& event) {changeDisplay(false, 0, 'x');}
void MainFrame::add_div(wxCommandEvent& event) {changeDisplay(false, 0, '/');}

void MainFrame::clearDisplay(wxCommandEvent& event) {
	display->SetLabel("0");
}

void MainFrame::equals(wxCommandEvent& event) {
	wxString toCalculate = display->GetLabel();
	toCalculate.Append("=");
	wxString newstring = runCalculate.calculateFull(toCalculate);
	display->SetLabel(newstring);
}

void MainFrame::changeDisplay(bool x, int y, char z) {
	// if x is true, use number. else, use char. 
	wxString current = display->GetLabel();
	std::string dummy = "";
	if (x) {
		// use number. 
		dummy = std::to_string(y);
		wxString a(dummy);
		current = current + a;
	}
	else {
		current = current + z;
	}
	display->SetLabel(current);
}