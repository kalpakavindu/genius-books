#pragma once

namespace GeniusBooks {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginPanel
	/// </summary>
	public ref class LoginPanel : public System::Windows::Forms::Form
	{
	public:
		LoginPanel(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginPanel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ emailInput;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ passwordInput;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->emailInput = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->passwordInput = (gcnew System::Windows::Forms::TextBox());
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
			this->label1->Location = System::Drawing::Point(257, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(251, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign in to your account";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(207, 120);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Email address";
			// 
			// emailInput
			// 
			this->emailInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->emailInput->Location = System::Drawing::Point(210, 141);
			this->emailInput->Name = L"emailInput";
			this->emailInput->Size = System::Drawing::Size(375, 24);
			this->emailInput->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(207, 188);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 18);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Password";
			// 
			// passwordInput
			// 
			this->passwordInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->passwordInput->Location = System::Drawing::Point(210, 209);
			this->passwordInput->Name = L"passwordInput";
			this->passwordInput->Size = System::Drawing::Size(375, 24);
			this->passwordInput->TabIndex = 4;
			this->passwordInput->UseSystemPasswordChar = true;
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
			this->submitBtn->TabIndex = 13;
			this->submitBtn->Text = L"Sign in";
			this->submitBtn->UseVisualStyleBackColor = false;
			// 
			// LoginPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 337);
			this->Controls->Add(this->submitBtn);
			this->Controls->Add(this->passwordInput);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->emailInput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->Name = L"LoginPanel";
			this->Text = L"LoginPanel";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
