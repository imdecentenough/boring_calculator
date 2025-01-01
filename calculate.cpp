#include "calculate.h"
#include <wx/wx.h>

const bool calculate::notSymbol(char a) { 
	// returns false if the char provided is a symbol (+, -, x, /, =)
	// returns true if else.
	switch (a) {
	case '+':
		return false;
		break;
	case '-':
		return false;
		break;
	case 'x':
		return false;
		break;
	case '/':
		return false;
		break;
	case '=':
		return false;
		break;
	default:
		return true;
		break;
	}
}

int calculate::twoDigits(int b, int c, char d) {
	// the full calculation of two ints, and a method, provided by the char. 
	switch (d) {
	case '+':
		b = b + c;
		break;
	case '-':
		b = b - c;
		break;
	case 'x':
		b = b * c;
		break;
	case '/':
		if (c != 0) {
			// if c is not equal to 0 (valid denominator)
			b = b / c;
		}
		else {
			// c = 0; invalid denominator, display an error, and clear the calculator.
			b = 0;
			wxMessageBox("Cannot divide by 0.", "Error", wxOK | wxICON_INFORMATION);
		}
		break;
	default:
		break;
	}
	return b;
}

wxString calculate::calculateFull(wxString a) {
	// the method that takes a wxString and calculates it. 
	std::string text = std::string(a.mb_str()); // uses a std::string for compatibility.
	int size = a.size();						// for the for loop.
	int b = 0;									// the big number that C is added to, subtracted from, multiplied by, or divided by.
	int c = 0;                                  // the small number that is used on B.
	char d = '_';                               // the sign of the operation. '_' denotes an empty char, that with no sign. 
	for (int i = 0; i < size; i++) {            // do this for the length of the wxString. 
		char x = text.at(i);
		if (notSymbol(x)) {
			int current = x - '0';
			if (d == '_') {
				if (b != 0) {
					b = b * 10;
				}
				b = b + current;
			}
			else {
				if (c != 0) {
					c = c * 10;
				}
				c = c + current;
			}
		}
		else {
			if (d == '_') {
				d = x;
			}
			else {
				b = twoDigits(b, c, d);
				c = 0;
				d = x;
			}
		}
	}
	std::string final = std::to_string(b);
	a.clear();
	a.append(final);
	return a;
}