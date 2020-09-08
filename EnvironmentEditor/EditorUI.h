#pragma once

#include <SFML/Graphics.hpp>
#include <IsometricRenderer.h>
#include <BaseCharacterModel.h>
#include <Environment.h>
#include <vector>

namespace EnvironmentEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de EditorUI
	/// </summary>
	public ref class EditorUI : public System::Windows::Forms::Form
	{
		sf::RenderWindow * window;
		tw::IsometricRenderer * renderer;
		tw::Environment * environment;
		std::vector<tw::BaseCharacterModel*>  * characters;


	public:
		EditorUI(void)
		{
			InitializeComponent();

			window = new sf::RenderWindow((sf::WindowHandle)sfmlRenderingSurface->Handle.ToInt32());
			renderer = new tw::IsometricRenderer(window);
			environment = new tw::Environment(20, 20);
			environment->getMapData(1, 1)->setIsObstacle(true);
			environment->getMapData(2, 2)->setIsWalkable(false);
			characters = new std::vector<tw::BaseCharacterModel*>();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~EditorUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  sfmlRenderingSurface;
	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->sfmlRenderingSurface = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// sfmlRenderingSurface
			// 
			this->sfmlRenderingSurface->Location = System::Drawing::Point(316, 12);
			this->sfmlRenderingSurface->Name = L"sfmlRenderingSurface";
			this->sfmlRenderingSurface->Size = System::Drawing::Size(774, 535);
			this->sfmlRenderingSurface->TabIndex = 0;
			this->sfmlRenderingSurface->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &EditorUI::sfmlRenderingSurface_Paint);
			// 
			// EditorUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1102, 559);
			this->Controls->Add(this->sfmlRenderingSurface);
			this->Name = L"EditorUI";
			this->Text = L"EditorUI";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void sfmlRenderingSurface_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		window->clear();
		renderer->render(environment, *characters);
		window->display();
	}
	};
}
