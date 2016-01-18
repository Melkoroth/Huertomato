// #############################################################################
//
// # Name       : WinWater
// # Version    : 0.5
//
// # Author     : Juan L. Perez Diez <ender.vs.melkor at gmail>
// # Date       : 18.01.2016
//
// # Description: Water cycle configuration window
//
// #  This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// #############################################################################


#ifndef WINWATER_H_
#define WINWATER_H_

#include "Window.h"

const char riegoTxt[] PROGMEM = "Riego cada:";
const char duranteTxt[] PROGMEM = "Durante:";

class WinWater: public Window {
	public:
		WinWater(LiquidCrystal *lcd, Sensors *sensors, Settings *settings);
		WinWater(const WinWater &other);
		WinWater& operator=(const WinWater &other);
		~WinWater();
		Screen getType() const;
		void draw();
		void update();
		Window::Screen processTouch(int);
	
	protected:
		//Tracks position of cursor
		uint8_t  _line, _column;
		//Internal variables
		//boolean _waterTimed;
		uint8_t _waterHour, _waterMin, _floodMin;
		//Tracks change to update settings or not
		boolean _modified;
};

#endif