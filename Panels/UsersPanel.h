#pragma once
#include "../Database.h"
#include "../Popups/EditUserPopup.h"
#include "../Popups/UserDetailsPopup.h"

namespace GeniusBooks {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UsersPanel
	/// </summary>
	public ref class UsersPanel : public System::Windows::Forms::Form
	{
	private:
		EditUserPopup^ editUserPopup;
		UserDetailsPopup^ viewUserPopup;
		Database^ conn;
		int currentTab = 0;

		void loadData() {
			try {
				String^ query;
				if (currentTab == 0) {
					this->pendingBtn->BackColor = System::Drawing::Color::Azure;
					this->registeredBtn->BackColor = System::Drawing::Color::PaleTurquoise;
					query = "SELECT * FROM UsersTable WHERE password IS NOT NULL";
				}
				else {
					this->pendingBtn->BackColor = System::Drawing::Color::PaleTurquoise;
					this->registeredBtn->BackColor = System::Drawing::Color::Azure;
					query = "SELECT * FROM UsersTable WHERE password IS NULL";
				}
				DataTable^ userDetials = conn->GetData(query);
				dataGrid->DataSource = userDetials;
			}
			catch (Exception^ e) {
				if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
					Application::Exit();
				}
			}
		}

		void openAddUserPopup() {
			editUserPopup->Text = "Add New User";
			editUserPopup->saveBtn->Hide();
			editUserPopup->addBtn->Show();
			editUserPopup->passwordInput->Hide();
			editUserPopup->label7->Hide();
			editUserPopup->ShowDialog();
		}

		void openEditUserPopup() {
			editUserPopup->Text = "Edit User Details";
			editUserPopup->saveBtn->Show();
			editUserPopup->addBtn->Hide();
			editUserPopup->ShowDialog();
		}

	public:
		UsersPanel(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			conn = gcnew Database();
			editUserPopup = gcnew EditUserPopup();
			editUserPopup->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &UsersPanel::formClosed);
			loadData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UsersPanel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ addBtn;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ mainPanel;

	private: System::Windows::Forms::Button^ registeredBtn;
	private: System::Windows::Forms::Button^ pendingBtn;
	private: System::Windows::Forms::DataGridView^ dataGrid;

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
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->registeredBtn = (gcnew System::Windows::Forms::Button());
			this->pendingBtn = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->mainPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->addBtn);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(798, 66);
			this->panel1->TabIndex = 3;
			// 
			// addBtn
			// 
			this->addBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->addBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->addBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addBtn->FlatAppearance->BorderColor = System::Drawing::Color::RoyalBlue;
			this->addBtn->FlatAppearance->BorderSize = 2;
			this->addBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addBtn->ForeColor = System::Drawing::Color::Azure;
			this->addBtn->Location = System::Drawing::Point(699, 18);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(87, 32);
			this->addBtn->TabIndex = 2;
			this->addBtn->Text = L"Add User";
			this->addBtn->UseVisualStyleBackColor = false;
			this->addBtn->Click += gcnew System::EventHandler(this, &UsersPanel::addBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Mulish Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Manage Users";
			// 
			// mainPanel
			// 
			this->mainPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mainPanel->BackColor = System::Drawing::Color::LightCyan;
			this->mainPanel->Controls->Add(this->dataGrid);
			this->mainPanel->Location = System::Drawing::Point(12, 105);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(774, 444);
			this->mainPanel->TabIndex = 4;
			// 
			// dataGrid
			// 
			this->dataGrid->AllowUserToAddRows = false;
			this->dataGrid->AllowUserToDeleteRows = false;
			this->dataGrid->AllowUserToOrderColumns = true;
			this->dataGrid->BackgroundColor = System::Drawing::Color::LightCyan;
			this->dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGrid->Location = System::Drawing::Point(0, 0);
			this->dataGrid->Name = L"dataGrid";
			this->dataGrid->ReadOnly = true;
			this->dataGrid->Size = System::Drawing::Size(774, 444);
			this->dataGrid->TabIndex = 0;
			this->dataGrid->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &UsersPanel::dataGrid_CellMouseDoubleClick);
			// 
			// registeredBtn
			// 
			this->registeredBtn->BackColor = System::Drawing::Color::PaleTurquoise;
			this->registeredBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->registeredBtn->FlatAppearance->BorderSize = 0;
			this->registeredBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->registeredBtn->Font = (gcnew System::Drawing::Font(L"Mulish SemiBold", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->registeredBtn->Location = System::Drawing::Point(12, 73);
			this->registeredBtn->Name = L"registeredBtn";
			this->registeredBtn->Size = System::Drawing::Size(101, 31);
			this->registeredBtn->TabIndex = 5;
			this->registeredBtn->Text = L"Registered";
			this->registeredBtn->UseVisualStyleBackColor = false;
			this->registeredBtn->Click += gcnew System::EventHandler(this, &UsersPanel::registeredBtn_Click);
			// 
			// pendingBtn
			// 
			this->pendingBtn->BackColor = System::Drawing::Color::Azure;
			this->pendingBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pendingBtn->FlatAppearance->BorderSize = 0;
			this->pendingBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->pendingBtn->Font = (gcnew System::Drawing::Font(L"Mulish SemiBold", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pendingBtn->Location = System::Drawing::Point(113, 73);
			this->pendingBtn->Name = L"pendingBtn";
			this->pendingBtn->Size = System::Drawing::Size(101, 31);
			this->pendingBtn->TabIndex = 6;
			this->pendingBtn->Text = L"Pending";
			this->pendingBtn->UseVisualStyleBackColor = false;
			this->pendingBtn->Click += gcnew System::EventHandler(this, &UsersPanel::pendingBtn_Click);
			// 
			// UsersPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightCyan;
			this->ClientSize = System::Drawing::Size(798, 561);
			this->Controls->Add(this->pendingBtn);
			this->Controls->Add(this->registeredBtn);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(798, 561);
			this->Name = L"UsersPanel";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"UsersPanel";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->mainPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void pendingBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		currentTab = 1;
		loadData();
	}

	private: System::Void registeredBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		currentTab = 0;
		loadData();
	}
	private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		openAddUserPopup();
	}

	private: System::Void formClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		loadData();
	}

	private: System::Void dataGrid_CellMouseDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
		int userId = safe_cast<int>(dataGrid->Rows[e->RowIndex]->Cells[0]->Value);
		viewUserPopup = gcnew UserDetailsPopup(userId);
		viewUserPopup->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &UsersPanel::formClosed);
		viewUserPopup->ShowDialog();
	}
};
}
