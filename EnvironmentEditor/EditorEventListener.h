#pragma once
#include <msclr/gcroot.h>
#include "RendererEventListener.h"

namespace EnvironmentEditor
{
	ref class EditorUI;
	class EditorEventListener : public tw::RendererEventListener
	{
		msclr::gcroot<EditorUI ^> hmi;
	public:
		EditorEventListener(EditorUI ^ hmi);
		~EditorEventListener();

		virtual void onCellClicked(int x, int y);
		virtual void onCellHover(int x, int y);
	};
}