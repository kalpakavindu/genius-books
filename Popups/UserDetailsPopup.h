#pragma once
#include "../Database.h";
#include "./EditUserPopup.h";

namespace GeniusBooks {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UserDetailsPopup
	/// </summary>
	public ref class UserDetailsPopup : public System::Windows::Forms::Form
	{
	private: Database^ conn;
	private: System::Windows::Forms::Label^ userLabel;
	private: int userId;
	private:EditUserPopup^ editUserPopup;

	public:
		UserDetailsPopup(int id)
		{
			InitializeComponent();
			conn = gcnew Database();
			editUserPopup = gcnew EditUserPopup();
			userId = id;
			loadData();
		}

		void loadData() {
			try {
				String^ query = "SELECT * FROM UsersTable WHERE id=" + userId;
				DataRow^ data = conn->GetData(query)->Rows[0];

				this->nameLabel->Text = safe_cast<String^>(data["first_name"]) + " " + safe_cast<String^>(data["last_name"]);
				this->emailLabel->Text = safe_cast<String^>(data["email"]);
				this->contactLabel->Text = safe_cast<String^>(data["contact"]);
				this->dobLabel->Text = data["dob"]->ToString();
				this->userLabel->Text = safe_cast<String^>(data["role"]);
			}
			catch (Exception^ e) {
				if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
					Application::Exit();
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserDetailsPopup()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ nameLabel;
	private: System::Windows::Forms::Label^ emailLabel;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ contactLabel;
	private: System::Windows::Forms::Label^ genderLabel;
	private: System::Windows::Forms::Label^ dobLabel;
	private: System::Windows::Forms::Button^ editBtn;
	private: System::Windows::Forms::Button^ delBtn;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;

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
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->emailLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->contactLabel = (gcnew System::Windows::Forms::Label());
			this->genderLabel = (gcnew System::Windows::Forms::Label());
			this->dobLabel = (gcnew System::Windows::Forms::Label());
			this->editBtn = (gcnew System::Windows::Forms::Button());
			this->delBtn = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->userLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Mulish ExtraBold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameLabel->Location = System::Drawing::Point(12, 27);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(186, 33);
			this->nameLabel->TabIndex = 0;
			this->nameLabel->Text = L"Kalpa Kavindu";
			// 
			// emailLabel
			// 
			this->emailLabel->AutoSize = true;
			this->emailLabel->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->emailLabel->Location = System::Drawing::Point(22, 234);
			this->emailLabel->Name = L"emailLabel";
			this->emailLabel->Size = System::Drawing::Size(202, 20);
			this->emailLabel->TabIndex = 1;
			this->emailLabel->Text = L"kalpadevonline@gmail.com";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 116);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 18);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Contact No.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 154);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 18);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Gender";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(23, 191);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(61, 18);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Birthday";
			// 
			// contactLabel
			// 
			this->contactLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->contactLabel->Location = System::Drawing::Point(119, 116);
			this->contactLabel->Name = L"contactLabel";
			this->contactLabel->Size = System::Drawing::Size(146, 18);
			this->contactLabel->TabIndex = 6;
			this->contactLabel->Text = L"+94712146553";
			// 
			// genderLabel
			// 
			this->genderLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->genderLabel->Location = System::Drawing::Point(119, 154);
			this->genderLabel->Name = L"genderLabel";
			this->genderLabel->Size = System::Drawing::Size(146, 18);
			this->genderLabel->TabIndex = 7;
			this->genderLabel->Text = L"Male";
			// 
			// dobLabel
			// 
			this->dobLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dobLabel->Location = System::Drawing::Point(119, 191);
			this->dobLabel->Name = L"dobLabel";
			this->dobLabel->Size = System::Drawing::Size(146, 18);
			this->dobLabel->TabIndex = 8;
			this->dobLabel->Text = L"21/05/2004";
			// 
			// editBtn
			// 
			this->editBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->editBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->editBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editBtn->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editBtn->ForeColor = System::Drawing::Color::Azure;
			this->editBtn->Location = System::Drawing::Point(330, 278);
			this->editBtn->Name = L"editBtn";
			this->editBtn->Size = System::Drawing::Size(166, 39);
			this->editBtn->TabIndex = 9;
			this->editBtn->Text = L"Edit Profile";
			this->editBtn->UseVisualStyleBackColor = false;
			this->editBtn->Click += gcnew System::EventHandler(this, &UserDetailsPopup::editBtn_Click);
			// 
			// delBtn
			// 
			this->delBtn->BackColor = System::Drawing::Color::Salmon;
			this->delBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->delBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delBtn->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delBtn->ForeColor = System::Drawing::Color::Azure;
			this->delBtn->Location = System::Drawing::Point(192, 278);
			this->delBtn->Name = L"delBtn";
			this->delBtn->Size = System::Drawing::Size(122, 39);
			this->delBtn->TabIndex = 10;
			this->delBtn->Text = L"Delete Profile";
			this->delBtn->UseVisualStyleBackColor = false;
			this->delBtn->Click += gcnew System::EventHandler(this, &UserDetailsPopup::delBtn_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel1->Location = System::Drawing::Point(271, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(125, 148);
			this->panel1->TabIndex = 11;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::LightCyan;
			this->panel2->Location = System::Drawing::Point(411, 154);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(85, 100);
			this->panel2->TabIndex = 12;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::AliceBlue;
			this->panel3->Location = System::Drawing::Point(411, 63);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(58, 71);
			this->panel3->TabIndex = 13;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::AliceBlue;
			this->panel4->Location = System::Drawing::Point(310, 183);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(86, 71);
			this->panel4->TabIndex = 14;
			// 
			// userLabel
			// 
			this->userLabel->AutoSize = true;
			this->userLabel->Location = System::Drawing::Point(15, 9);
			this->userLabel->Name = L"userLabel";
			this->userLabel->Size = System::Drawing::Size(42, 18);
			this->userLabel->TabIndex = 15;
			this->userLabel->Text = L"USER";
			// 
			// UserDetailsPopup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Azure;
			this->ClientSize = System::Drawing::Size(508, 329);
			this->Controls->Add(this->userLabel);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->delBtn);
			this->Controls->Add(this->editBtn);
			this->Controls->Add(this->dobLabel);
			this->Controls->Add(this->genderLabel);
			this->Controls->Add(this->contactLabel);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->emailLabel);
			this->Controls->Add(this->nameLabel);
			this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(524, 368);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(524, 368);
			this->Name = L"UserDetailsPopup";
			this->ShowInTaskbar = false;
			this->Text = L"UserDetailsPopup";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void editBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		editUserPopup->loadUserDetails(userId);
		editUserPopup->ShowDialog();
		this->Hide();
	}
	private: System::Void delBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ query = "DELETE FROM UsersTable WHERE id=" + userId;
			conn->SetData(query);
			this->Close();
		}
		catch (Exception^ e) {
			if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
				Application::Exit();
			}
		}
	}
};
}
