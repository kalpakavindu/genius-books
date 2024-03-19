#pragma once
#include "../Database.h";

namespace GeniusBooks {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegisterPanel
	/// </summary>
	public ref class RegisterPanel : public System::Windows::Forms::Form
	{
		private: Database^ conn;

		public:
			RegisterPanel(void)
			{
				InitializeComponent();
				conn = gcnew Database();
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~RegisterPanel()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^ label1;




		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::TextBox^ emailInput;
		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::TextBox^ passwordInput;
		private: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::TextBox^ cpasswordInput;
		private: System::Windows::Forms::Button^ submitBtn;
		protected:

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
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->emailInput = (gcnew System::Windows::Forms::TextBox());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->passwordInput = (gcnew System::Windows::Forms::TextBox());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->cpasswordInput = (gcnew System::Windows::Forms::TextBox());
				this->submitBtn = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// label1
				// 
				this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
					| System::Windows::Forms::AnchorStyles::Right));
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Mulish ExtraBold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label1->Location = System::Drawing::Point(257, 75);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(258, 28);
				this->label1->TabIndex = 1;
				this->label1->Text = L"Sign up to your account";
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(207, 133);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(92, 18);
				this->label4->TabIndex = 6;
				this->label4->Text = L"Email address";
				// 
				// emailInput
				// 
				this->emailInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->emailInput->Location = System::Drawing::Point(210, 154);
				this->emailInput->Name = L"emailInput";
				this->emailInput->Size = System::Drawing::Size(375, 24);
				this->emailInput->TabIndex = 7;
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Location = System::Drawing::Point(207, 200);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(98, 18);
				this->label5->TabIndex = 8;
				this->label5->Text = L"New Password";
				// 
				// passwordInput
				// 
				this->passwordInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->passwordInput->Location = System::Drawing::Point(210, 221);
				this->passwordInput->Name = L"passwordInput";
				this->passwordInput->Size = System::Drawing::Size(180, 24);
				this->passwordInput->TabIndex = 9;
				this->passwordInput->UseSystemPasswordChar = true;
				// 
				// label6
				// 
				this->label6->AutoSize = true;
				this->label6->Location = System::Drawing::Point(402, 200);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(117, 18);
				this->label6->TabIndex = 10;
				this->label6->Text = L"Confirm Password";
				// 
				// cpasswordInput
				// 
				this->cpasswordInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->cpasswordInput->Location = System::Drawing::Point(405, 221);
				this->cpasswordInput->Name = L"cpasswordInput";
				this->cpasswordInput->Size = System::Drawing::Size(180, 24);
				this->cpasswordInput->TabIndex = 11;
				this->cpasswordInput->UseSystemPasswordChar = true;
				// 
				// submitBtn
				// 
				this->submitBtn->BackColor = System::Drawing::Color::RoyalBlue;
				this->submitBtn->Cursor = System::Windows::Forms::Cursors::Hand;
				this->submitBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->submitBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->submitBtn->ForeColor = System::Drawing::Color::White;
				this->submitBtn->Location = System::Drawing::Point(210, 270);
				this->submitBtn->Name = L"submitBtn";
				this->submitBtn->Size = System::Drawing::Size(375, 32);
				this->submitBtn->TabIndex = 12;
				this->submitBtn->Text = L"Sign up";
				this->submitBtn->UseVisualStyleBackColor = false;
				this->submitBtn->Click += gcnew System::EventHandler(this, &RegisterPanel::submitBtn_Click);
				// 
				// RegisterPanel
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::Azure;
				this->ClientSize = System::Drawing::Size(784, 337);
				this->Controls->Add(this->submitBtn);
				this->Controls->Add(this->cpasswordInput);
				this->Controls->Add(this->label6);
				this->Controls->Add(this->passwordInput);
				this->Controls->Add(this->label5);
				this->Controls->Add(this->emailInput);
				this->Controls->Add(this->label4);
				this->Controls->Add(this->label1);
				this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				this->Margin = System::Windows::Forms::Padding(4);
				this->MaximizeBox = false;
				this->MinimizeBox = false;
				this->Name = L"RegisterPanel";
				this->ShowIcon = false;
				this->ShowInTaskbar = false;
				this->Text = L"RegisterPanel";
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion


		private: System::Void submitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (emailInput->Text == "" || passwordInput->Text == "" || cpasswordInput->Text == "") {
					MessageBox::Show("You need to fillout all the fields in the form to continue forward.", "Error", MessageBoxButtons::OK);
				}
				else {
					if (passwordInput->Text != cpasswordInput->Text) {
						MessageBox::Show("Passwords are not the same", "Error", MessageBoxButtons::OK);
					}
					else {
						String^ query = "SELECT * FROM UsersTable WHERE email='" + emailInput->Text + "'";
						DataTable^ userData = conn->GetData(query);
						if (userData->Rows->Count == 0) {
							MessageBox::Show("Email not found! Contact your admin to signup.", "Error", MessageBoxButtons::OK);
						}
						else {
							query = "UPDATE UsersTable SET password='" + passwordInput->Text + "' WHERE email='" + emailInput->Text + "'";
							conn->SetData(query);
							this->Close();
						}
					}
				}
			}
			catch (Exception^ e) {
				if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
					Application::Exit();
				}
			}
		}
	};
}
