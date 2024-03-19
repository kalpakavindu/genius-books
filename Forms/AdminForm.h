#pragma once
#include "../Panels/DashboardPanel.h"
#include "../Panels/UsersPanel.h"
#include "../Panels/SuppliersPanel.h"
#include "../Panels/BooksPanel.h"

namespace GeniusBooks {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminForm
	/// </summary>
	public ref class AdminForm : public System::Windows::Forms::Form
	{
		private: DashboardPanel^ dashboardPanel;
		private: BooksPanel^ booksPanel;
		private: SuppliersPanel^ suppliersPanel;
		private: UsersPanel^ usersPanel;

		private: void setPanel(int number) {
				switch (number) {
				case 0:
					this->Text = "Manage Books";
					booksPanel = gcnew BooksPanel();
					booksPanel->TopLevel = false;
					booksPanel->Dock = System::Windows::Forms::DockStyle::Fill;
					this->dashboardBtn->BackColor = System::Drawing::Color::Azure;
					this->booksBtn->BackColor = System::Drawing::Color::LightCyan;
					this->supliersBtn->BackColor = System::Drawing::Color::Azure;
					this->usersBtn->BackColor = System::Drawing::Color::Azure;

					this->mainPanel->Controls->Clear();
					this->mainPanel->Controls->Add(booksPanel);
					booksPanel->Show();
					break;
				case 1:
					this->Text = "Manage Suppliers";
					suppliersPanel = gcnew SuppliersPanel();
					suppliersPanel->TopLevel = false;
					suppliersPanel->Dock = System::Windows::Forms::DockStyle::Fill;
					this->dashboardBtn->BackColor = System::Drawing::Color::Azure;
					this->booksBtn->BackColor = System::Drawing::Color::Azure;
					this->supliersBtn->BackColor = System::Drawing::Color::LightCyan;
					this->usersBtn->BackColor = System::Drawing::Color::Azure;

					this->mainPanel->Controls->Clear();
					this->mainPanel->Controls->Add(suppliersPanel);
					suppliersPanel->Show();
					break;
				case 2:
					this->Text = "Manage Users";
					usersPanel = gcnew UsersPanel();
					usersPanel->TopLevel = false;
					usersPanel->Dock = System::Windows::Forms::DockStyle::Fill;
					this->dashboardBtn->BackColor = System::Drawing::Color::Azure;
					this->booksBtn->BackColor = System::Drawing::Color::Azure;
					this->supliersBtn->BackColor = System::Drawing::Color::Azure;
					this->usersBtn->BackColor = System::Drawing::Color::LightCyan;

					this->mainPanel->Controls->Clear();
					this->mainPanel->Controls->Add(usersPanel);
					usersPanel->Show();
					break;
				default:
					this->Text = "Dashboard";
					dashboardPanel = gcnew DashboardPanel();
					dashboardPanel->TopLevel = false;
					dashboardPanel->Dock = System::Windows::Forms::DockStyle::Fill;
					this->dashboardBtn->BackColor = System::Drawing::Color::LightCyan;
					this->booksBtn->BackColor = System::Drawing::Color::Azure;
					this->supliersBtn->BackColor = System::Drawing::Color::Azure;
					this->usersBtn->BackColor = System::Drawing::Color::Azure;

					this->mainPanel->Controls->Clear();
					this->mainPanel->Controls->Add(dashboardPanel);
					dashboardPanel->Show();
					break;
				}
			}

		public:
			AdminForm(void)
			{
				InitializeComponent();
				setPanel(3);
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~AdminForm()
			{
				if (components)
				{
					delete components;
				}
			}

		private: System::Windows::Forms::Panel^ panel1;
		private: System::Windows::Forms::Button^ dashboardBtn;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Button^ usersBtn;
		private: System::Windows::Forms::Button^ supliersBtn;
		private: System::Windows::Forms::Button^ booksBtn;
		private: System::Windows::Forms::Button^ signOutBtn;
		private: System::Windows::Forms::Panel^ mainPanel;

		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->panel1 = (gcnew System::Windows::Forms::Panel());
				this->signOutBtn = (gcnew System::Windows::Forms::Button());
				this->usersBtn = (gcnew System::Windows::Forms::Button());
				this->supliersBtn = (gcnew System::Windows::Forms::Button());
				this->booksBtn = (gcnew System::Windows::Forms::Button());
				this->dashboardBtn = (gcnew System::Windows::Forms::Button());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->mainPanel = (gcnew System::Windows::Forms::Panel());
				this->panel1->SuspendLayout();
				this->SuspendLayout();
				// 
				// panel1
				// 
				this->panel1->Controls->Add(this->signOutBtn);
				this->panel1->Controls->Add(this->usersBtn);
				this->panel1->Controls->Add(this->supliersBtn);
				this->panel1->Controls->Add(this->booksBtn);
				this->panel1->Controls->Add(this->dashboardBtn);
				this->panel1->Controls->Add(this->label1);
				this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
				this->panel1->Location = System::Drawing::Point(0, 0);
				this->panel1->Name = L"panel1";
				this->panel1->Size = System::Drawing::Size(183, 561);
				this->panel1->TabIndex = 0;
				// 
				// signOutBtn
				// 
				this->signOutBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
					| System::Windows::Forms::AnchorStyles::Right));
				this->signOutBtn->BackColor = System::Drawing::Color::Azure;
				this->signOutBtn->Cursor = System::Windows::Forms::Cursors::Hand;
				this->signOutBtn->FlatAppearance->BorderSize = 0;
				this->signOutBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->signOutBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->signOutBtn->Location = System::Drawing::Point(3, 514);
				this->signOutBtn->Name = L"signOutBtn";
				this->signOutBtn->Size = System::Drawing::Size(177, 35);
				this->signOutBtn->TabIndex = 5;
				this->signOutBtn->Text = L"Sign out";
				this->signOutBtn->UseVisualStyleBackColor = false;
				this->signOutBtn->Click += gcnew System::EventHandler(this, &AdminForm::signOutBtn_Click);
				// 
				// usersBtn
				// 
				this->usersBtn->BackColor = System::Drawing::Color::Azure;
				this->usersBtn->Cursor = System::Windows::Forms::Cursors::Hand;
				this->usersBtn->FlatAppearance->BorderSize = 0;
				this->usersBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->usersBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->usersBtn->Location = System::Drawing::Point(3, 173);
				this->usersBtn->Name = L"usersBtn";
				this->usersBtn->Size = System::Drawing::Size(177, 35);
				this->usersBtn->TabIndex = 4;
				this->usersBtn->Text = L"Users";
				this->usersBtn->UseVisualStyleBackColor = false;
				this->usersBtn->Click += gcnew System::EventHandler(this, &AdminForm::usersBtn_Click);
				// 
				// supliersBtn
				// 
				this->supliersBtn->BackColor = System::Drawing::Color::Azure;
				this->supliersBtn->Cursor = System::Windows::Forms::Cursors::Hand;
				this->supliersBtn->FlatAppearance->BorderSize = 0;
				this->supliersBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->supliersBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->supliersBtn->Location = System::Drawing::Point(3, 132);
				this->supliersBtn->Name = L"supliersBtn";
				this->supliersBtn->Size = System::Drawing::Size(177, 35);
				this->supliersBtn->TabIndex = 3;
				this->supliersBtn->Text = L"Suppliers";
				this->supliersBtn->UseVisualStyleBackColor = false;
				this->supliersBtn->Click += gcnew System::EventHandler(this, &AdminForm::supliersBtn_Click);
				// 
				// booksBtn
				// 
				this->booksBtn->BackColor = System::Drawing::Color::Azure;
				this->booksBtn->Cursor = System::Windows::Forms::Cursors::Hand;
				this->booksBtn->FlatAppearance->BorderSize = 0;
				this->booksBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->booksBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->booksBtn->Location = System::Drawing::Point(3, 91);
				this->booksBtn->Name = L"booksBtn";
				this->booksBtn->Size = System::Drawing::Size(177, 35);
				this->booksBtn->TabIndex = 2;
				this->booksBtn->Text = L"Books";
				this->booksBtn->UseVisualStyleBackColor = false;
				this->booksBtn->Click += gcnew System::EventHandler(this, &AdminForm::booksBtn_Click);
				// 
				// dashboardBtn
				// 
				this->dashboardBtn->BackColor = System::Drawing::Color::Azure;
				this->dashboardBtn->Cursor = System::Windows::Forms::Cursors::Hand;
				this->dashboardBtn->FlatAppearance->BorderSize = 0;
				this->dashboardBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->dashboardBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->dashboardBtn->Location = System::Drawing::Point(3, 50);
				this->dashboardBtn->Name = L"dashboardBtn";
				this->dashboardBtn->Size = System::Drawing::Size(177, 35);
				this->dashboardBtn->TabIndex = 1;
				this->dashboardBtn->Text = L"Dashboard";
				this->dashboardBtn->UseVisualStyleBackColor = false;
				this->dashboardBtn->Click += gcnew System::EventHandler(this, &AdminForm::dashboardBtn_Click);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Mulish ExtraBold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label1->Location = System::Drawing::Point(25, 9);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(136, 26);
				this->label1->TabIndex = 0;
				this->label1->Text = L"Genius Books";
				// 
				// mainPanel
				// 
				this->mainPanel->AutoSize = true;
				this->mainPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->mainPanel->BackColor = System::Drawing::Color::LightCyan;
				this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
				this->mainPanel->Location = System::Drawing::Point(183, 0);
				this->mainPanel->MinimumSize = System::Drawing::Size(798, 561);
				this->mainPanel->Name = L"mainPanel";
				this->mainPanel->Size = System::Drawing::Size(801, 561);
				this->mainPanel->TabIndex = 1;
				// 
				// AdminForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::Azure;
				this->ClientSize = System::Drawing::Size(984, 561);
				this->Controls->Add(this->mainPanel);
				this->Controls->Add(this->panel1);
				this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Margin = System::Windows::Forms::Padding(4);
				this->MaximizeBox = false;
				this->MaximumSize = System::Drawing::Size(1000, 600);
				this->MinimumSize = System::Drawing::Size(1000, 600);
				this->Name = L"AdminForm";
				this->Text = L"AdminForm";
				this->panel1->ResumeLayout(false);
				this->panel1->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion

		private: System::Void booksBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			setPanel(0);
		}
		private: System::Void supliersBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			setPanel(1);
		}
		private: System::Void usersBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			setPanel(2);
		}
		private: System::Void dashboardBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			setPanel(3);
		}
		private: System::Void signOutBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
