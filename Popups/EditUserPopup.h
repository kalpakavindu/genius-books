#pragma once

#include "../Database.h"

namespace GeniusBooks {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditUserPopup
	/// </summary>
	public ref class EditUserPopup : public System::Windows::Forms::Form
	{
	private: Database^ conn;
	private: int editId;
	public:
		EditUserPopup(void)
		{
			InitializeComponent();
			conn = gcnew Database();
		}

		void loadUserDetails(int id) {
			try {
				editId = id;
				String^ query = "SELECT * FROM UsersTable WHERE id=" + id;
				System::Data::DataRow^ data = conn->GetData(query)->Rows[0];

				fnameInput->Text = safe_cast<String^>(data["first_name"]);
				lnameInput->Text = safe_cast<String^>(data["last_name"]);
				mailInput->Text = safe_cast<String^>(data["email"]);
				contactInput->Text = safe_cast<String^>(data["contact"]);
				genderInput->Text = safe_cast<String^>(data["gender"]);
				roleInput->Text = safe_cast<String^>(data["role"]);
				dateTimePicker1->Value = safe_cast<System::DateTime>(data["dob"]);

				try {
					passwordInput->Text = safe_cast<String^>(data["password"]);
				}
				catch (Exception^ ex) {
					passwordInput->Text = "";
				}
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
		~EditUserPopup()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ fnameInput;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ lnameInput;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ mailInput;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ genderInput;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ contactInput;
	public: System::Windows::Forms::Button^ saveBtn;
	private: System::Windows::Forms::Button^ cancelBtn;
	public: System::Windows::Forms::TextBox^ passwordInput;
	public: System::Windows::Forms::Label^ label7;
	public: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ roleInput;
	public: System::Windows::Forms::Button^ addBtn;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->fnameInput = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lnameInput = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mailInput = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->genderInput = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->contactInput = (gcnew System::Windows::Forms::TextBox());
			this->saveBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->passwordInput = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->roleInput = (gcnew System::Windows::Forms::ComboBox());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"First name";
			// 
			// fnameInput
			// 
			this->fnameInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->fnameInput->Location = System::Drawing::Point(15, 30);
			this->fnameInput->Name = L"fnameInput";
			this->fnameInput->Size = System::Drawing::Size(188, 24);
			this->fnameInput->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(217, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Last name";
			// 
			// lnameInput
			// 
			this->lnameInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lnameInput->Location = System::Drawing::Point(220, 30);
			this->lnameInput->Name = L"lnameInput";
			this->lnameInput->Size = System::Drawing::Size(188, 24);
			this->lnameInput->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 18);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Email address";
			// 
			// mailInput
			// 
			this->mailInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mailInput->Location = System::Drawing::Point(15, 94);
			this->mailInput->Name = L"mailInput";
			this->mailInput->Size = System::Drawing::Size(393, 24);
			this->mailInput->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 142);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 18);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Gender";
			// 
			// genderInput
			// 
			this->genderInput->FormattingEnabled = true;
			this->genderInput->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Male", L"Female" });
			this->genderInput->Location = System::Drawing::Point(15, 163);
			this->genderInput->Name = L"genderInput";
			this->genderInput->Size = System::Drawing::Size(188, 26);
			this->genderInput->TabIndex = 7;
			this->genderInput->Text = "Male";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(217, 142);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 18);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Date of birth";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(220, 165);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(188, 24);
			this->dateTimePicker1->TabIndex = 9;
			this->dateTimePicker1->Value = System::DateTime(2024, 3, 15, 0, 0, 0, 0);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 212);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(79, 18);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Contact No.";
			// 
			// contactInput
			// 
			this->contactInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->contactInput->Location = System::Drawing::Point(15, 233);
			this->contactInput->Name = L"contactInput";
			this->contactInput->Size = System::Drawing::Size(188, 24);
			this->contactInput->TabIndex = 11;
			// 
			// saveBtn
			// 
			this->saveBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->saveBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveBtn->ForeColor = System::Drawing::Color::Azure;
			this->saveBtn->Location = System::Drawing::Point(291, 280);
			this->saveBtn->Name = L"saveBtn";
			this->saveBtn->Size = System::Drawing::Size(117, 38);
			this->saveBtn->TabIndex = 12;
			this->saveBtn->Text = L"Save Details";
			this->saveBtn->UseVisualStyleBackColor = false;
			this->saveBtn->Click += gcnew System::EventHandler(this, &EditUserPopup::saveBtn_Click);
			// 
			// cancelBtn
			// 
			this->cancelBtn->BackColor = System::Drawing::Color::Azure;
			this->cancelBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelBtn->ForeColor = System::Drawing::Color::Black;
			this->cancelBtn->Location = System::Drawing::Point(159, 280);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(117, 38);
			this->cancelBtn->TabIndex = 13;
			this->cancelBtn->Text = L"Cancel";
			this->cancelBtn->UseVisualStyleBackColor = false;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &EditUserPopup::cancelBtn_Click);
			// 
			// passwordInput
			// 
			this->passwordInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->passwordInput->Location = System::Drawing::Point(220, 233);
			this->passwordInput->Name = L"passwordInput";
			this->passwordInput->Size = System::Drawing::Size(188, 24);
			this->passwordInput->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(217, 212);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 18);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Password";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(16, 271);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(34, 18);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Role";
			// 
			// roleInput
			// 
			this->roleInput->FormattingEnabled = true;
			this->roleInput->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"USER", L"ADMIN", L"MODERATOR" });
			this->roleInput->Location = System::Drawing::Point(15, 292);
			this->roleInput->Name = L"roleInput";
			this->roleInput->Size = System::Drawing::Size(126, 26);
			this->roleInput->TabIndex = 17;
			this->roleInput->Text = "USER";
			// 
			// addBtn
			// 
			this->addBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->addBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addBtn->ForeColor = System::Drawing::Color::Azure;
			this->addBtn->Location = System::Drawing::Point(291, 280);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(117, 38);
			this->addBtn->TabIndex = 18;
			this->addBtn->Text = L"Add User";
			this->addBtn->UseVisualStyleBackColor = false;
			this->addBtn->Click += gcnew System::EventHandler(this, &EditUserPopup::addBtn_Click);
			// 
			// EditUserPopup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Azure;
			this->ClientSize = System::Drawing::Size(424, 334);
			this->Controls->Add(this->addBtn);
			this->Controls->Add(this->roleInput);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->passwordInput);
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->saveBtn);
			this->Controls->Add(this->contactInput);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->genderInput);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->mailInput);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lnameInput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->fnameInput);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(440, 373);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(440, 373);
			this->Name = L"EditUserPopup";
			this->ShowInTaskbar = false;
			this->Text = L"Edit User Details";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		private: System::Void saveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				String^ fname = fnameInput->Text;
				String^ lname = lnameInput->Text;
				String^ email = mailInput->Text;
				String^ password = passwordInput->Text;
				String^ contact = contactInput->Text;
				String^ gender = genderInput->Text;
				String^ role = roleInput->Text;
				dateTimePicker1->Format = DateTimePickerFormat::Custom;
				dateTimePicker1->CustomFormat = "yyyy-MM-dd";
				String^ dob = dateTimePicker1->Value.Date.ToString("yyyy-MM-dd");

				if (password == "") {
					password = "null";
				}
				else {
					password = "'" + password + "'";
				}

				String^ query = "UPDATE UsersTable SET first_name='" + fname + "',last_name='" + lname + "',email='" + email + "',password=" + password + ",dob='" + dob + "',gender='" + gender + "',contact='" + contact + "',role='" + role + "' WHERE id=" + editId;

				conn->SetData(query);
				this->Close();
			}
			catch (Exception^ e) {
				if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
					Application::Exit();
				}
			}
		}

		private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				String^ fname = fnameInput->Text;
				String^ lname = lnameInput->Text;
				String^ email = mailInput->Text;
				String^ password = passwordInput->Text;
				String^ contact = contactInput->Text;
				String^ gender = genderInput->Text;
				String^ role = roleInput->Text;
				dateTimePicker1->Format = DateTimePickerFormat::Custom;
				dateTimePicker1->CustomFormat = "yyyy-MM-dd";
				String^ dob = dateTimePicker1->Value.Date.ToString("yyyy-MM-dd");

				DateTime^ currentDate = DateTime::Now;
				String^ createdAt = currentDate->ToString("yyyy-MM-dd");
				if (password == "") {
					password = "null";
				}
				else {
					password = "'" + password + "'";
				}

				String^ query = "INSERT INTO UsersTable VALUES('" + fname + "','" + lname + "','" + email + "'," + password + ",'" + dob + "','" + gender + "','" + contact + "','" + role + "','" + createdAt + "')";

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
