#include "EditorEventListener.h"
#include "EditorUI.h"

#include <iostream>

using namespace EnvironmentEditor;

EditorEventListener::EditorEventListener(EditorUI ^ hmi)
{
	this->hmi = hmi;
}

EditorEventListener::~EditorEventListener()
{
}

void EditorEventListener::onCellClicked(int x, int y)
{	
	std::cout << "Clic sur [" << x << ";" << y << "]" << std::endl;
	hmi->editCell(x, y);
}

void EditorEventListener::onCellHover(int x, int y)
{

}