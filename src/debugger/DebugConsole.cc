// $Id$

#include <iostream>
#include "Views.hh"
#include "DebugConsole.hh"

DebugConsole* DebugConsole::instance()
{
	static DebugConsole oneInstance;
	return &oneInstance;
}

DebugConsole::DebugConsole()
	: debuggerSetting("debugger", "turns the debugger on or off", false)
{
	debuggerSetting.addListener(this);
	for (int i = 0; i < 20; i++) {
		lines.push_back(" ");
	}
	addView (0, 0, 50, 6, DUMPVIEW);
}

DebugConsole::~DebugConsole()
{
	map<int, ViewStruct*>::const_iterator it;
	for (it = viewList.begin(); it != viewList.end(); ++it) {
		if (it->second != NULL) {
			delete it->second->view;
			delete it->second;
		}
	}
	debuggerSetting.removeListener(this);
}

void DebugConsole::update(const SettingLeafNode *setting)
{
	assert(setting == &debuggerSetting);
}

bool DebugConsole::signalEvent(SDL_Event &event)
{
	if (!isVisible()) {
		return true;
	}
	return false; // don't send anything to the MSX if visible
}

int DebugConsole::addView(int cursorX, int cursorY, int columns, int rows,
                          ViewType viewType)
{
	ViewStruct* viewData = new ViewStruct();
	viewData->cursorX = cursorX;
	viewData->cursorY = cursorY;
	viewData->columns = columns;
	viewData->rows = rows;
	viewData->view = NULL;
	// determen view to create
	
	switch (viewType) {
	case DUMPVIEW:
		viewData->view = new DumpView(rows, columns, true);
		break;
	default:
		break;
	}
	
	if (viewData->view) {
		viewData->view->fill();
	}
	
	//finally, determen which number to take for it
	map<int, ViewStruct*>::iterator it;
	for (it = viewList.begin(); it != viewList.end(); ++it) {
		if (it->second == NULL) {
			it->second = viewData;
			return it->first;
		}
	}
	int size=viewList.size();
	viewList[size] = viewData;
	return size;
}

bool DebugConsole::removeView(int id)
{
	map<int, ViewStruct*>::iterator it;
	for (it = viewList.begin(); it != viewList.end(); ++it) {
		if ((it->first == id) && (it->second != NULL)) {
			delete it->second->view;
			delete it->second;
			it->second = NULL;
			return true;
		}
	}
	return false;
}

void DebugConsole::buildLayout()
{
	map<int, ViewStruct*>::const_iterator it;
	for (it = viewList.begin(); it != viewList.end(); ++it) {
		for (int i = it->second->cursorY; 
		     i < it->second->cursorY + it->second->rows - 1;
		     ++i) {
			if (i < debugRows) {
				if (lines[debugRows - 1 - i].size() <
				    (unsigned)it->second->cursorX + it->second->columns) {
					string temp(it->second->cursorX +
					            it->second->columns - 
						    lines[debugRows - 1 - i].size(), ' ');
					lines[debugRows - 1 - i] += temp;
				}
				lines[debugRows - 1 - i].replace(
				  it->second->cursorX, it->second->columns,
				  it->second->view->getLine(i - it->second->cursorY));
			}
		}
	}
}

void DebugConsole::loadLayout()
{
	// TODO
}

void DebugConsole::saveLayout()
{
	// TODO
}

void DebugConsole::resizeView(int cursorX, int cursorY, int columns, int rows, int id)
{
	map<int, ViewStruct*>::const_iterator it;
	for (it = viewList.begin(); it != viewList.end(); ++it) {
		if ((it->first == id) && (it->second != NULL)) {
			it->second->view->resize(columns, rows);
			it->second->cursorX = cursorX;
			it->second->cursorY = cursorY;
			buildLayout();
			return;
		}
	}
}

void DebugConsole::updateViews()
{
	map<int, ViewStruct*>::const_iterator it;
	for (it = viewList.begin(); it != viewList.end(); ++it) {
		if (it->second != NULL) {
			it->second->view->update();
		}
	}
}

void DebugConsole::getCursorPosition(int *xPosition, int *yPosition)
{
	*xPosition = 0;
	*yPosition = 0;
} 

void DebugConsole::setCursorPosition(int xPosition, int yPosition)
{
}

void DebugConsole::setCursorPosition(CursorXY pos)
{
	setCursorPosition(pos.x, pos.y);
}

const string& DebugConsole::getLine(unsigned line)
{
	static string EMPTY;
	return (unsigned)line < lines.size() ? lines[line] : EMPTY;
}

bool DebugConsole::isVisible()
{
	return debuggerSetting.getValue();
}

void DebugConsole::setConsoleDimensions(int columns, int rows)
{
	debugColumns = columns;
	debugRows = rows;
	buildLayout();
}
