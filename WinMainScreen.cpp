#include "WinMainScreen.h"

WinMainScreen::WinMainScreen(LiquidCrystal *lcd, Sensors *sensors, Settings *settings) 
: Window(lcd,sensors,settings) {}

WinMainScreen::WinMainScreen(const WinMainScreen &other) : Window(other) {}
WinMainScreen& WinMainScreen::operator=(const WinMainScreen &other) {
	_lcd = other._lcd;
	_sensors = other._sensors;
	_settings = other._settings;
	return *this;
}

WinMainScreen::~WinMainScreen() {}
	
Window::Screen WinMainScreen::getType() const {
	return Window::MainScreen;
}

void WinMainScreen::draw() {
	_lcd->clear();
	_lcd->setCursor(0,0);
	
	_lcd->print(_sensors->getTemp(),1);
	_lcd->print(pmChar(celsStr));
	_lcd->print(" LVL:");
	_lcd->print(_sensors->getWaterLevel());
	_lcd->print(pmChar(percentSign));
	_lcd->setCursor(0,1);
	_lcd->print("pH:");
	//TODO: Implement real sensor data
	_lcd->print(_sensors->getPH());
	_lcd->print(" EC:");
	_lcd->print("300mS");
}

//Refreshes minimun or redraws if status of system has changed
void WinMainScreen::update() {
	_lcd->setCursor(0,0);
	_lcd->print(_sensors->getTemp(),1);
	_lcd->setCursor(10,0);
	_lcd->print(_sensors->getWaterLevel());
	_lcd->print("%");
	_lcd->setCursor(3,1);
	//pH
	_lcd->setCursor(12,1);
	//EC
	//_lcd->print("mS");
}

Window::Screen WinMainScreen::processTouch(int but) { 
	//Select
	if (but == 5)
		return WateringCycle;
	//else if (but == 1)
		//return TimeDate; 
	else
		return None;
}