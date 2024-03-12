#pragma once

namespace GeniusBooks {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AuthForm
	/// </summary>
	public ref class AuthForm : public System::Windows::Forms::Form
	{
	public:
		AuthForm(void)
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
		~AuthForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ mainPanel;
	private: System::Windows::Forms::Label^ labelQue;
	private: System::Windows::Forms::LinkLabel^ signupLink;
	private: System::Windows::Forms::Panel^ panel1;
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
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->labelQue = (gcnew System::Windows::Forms::Label());
			this->signupLink = (gcnew System::Windows::Forms::LinkLabel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainPanel
			// 
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->mainPanel->Location = System::Drawing::Point(0, 0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(784, 337);
			this->mainPanel->TabIndex = 0;
			// 
			// labelQue
			// 
			this->labelQue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelQue->AutoSize = true;
			this->labelQue->Location = System::Drawing::Point(3, 6);
			this->labelQue->Name = L"labelQue";
			this->labelQue->Size = System::Drawing::Size(153, 18);
			this->labelQue->TabIndex = 1;
			this->labelQue->Text = L"Don\'t have an account \?";
			// 
			// signupLink
			// 
			this->signupLink->AutoSize = true;
			this->signupLink->Location = System::Drawing::Point(163, 6);
			this->signupLink->Name = L"signupLink";
			this->signupLink->Size = System::Drawing::Size(55, 18);
			this->signupLink->TabIndex = 2;
			this->signupLink->TabStop = true;
			this->signupLink->Text = L"Sign Up";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->labelQue);
			this->panel1->Controls->Add(this->signupLink);
			this->panel1->Location = System::Drawing::Point(274, 343);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(221, 30);
			this->panel1->TabIndex = 3;
			// 
			// AuthForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 411);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->mainPanel);
			this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(800, 450);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(800, 450);
			this->Name = L"AuthForm";
			this->Text = L"Authentication";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
