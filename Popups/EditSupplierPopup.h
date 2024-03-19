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
	/// Summary for EditSupplierPopup
	/// </summary>
	public ref class EditSupplierPopup : public System::Windows::Forms::Form
	{
		private: Database^ conn;
		private: int editId = 0;

		public:void setData(int id) {
			try {
				editId = id;

				String^ query = "SELECT * FROM SuppliersTable WHERE id=" + id;
				DataRow^ supplierData = conn->GetData(query)->Rows[0];

				nameInput->Text = safe_cast<String^>(supplierData["name"]);
				addressInput->Text = safe_cast<String^>(supplierData["address"]);
				mailInput->Text = safe_cast<String^>(supplierData["email"]);
				contactInput->Text = safe_cast<String^>(supplierData["contact"]);
			}
			catch (Exception^ e) {
				if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
					Application::Exit();
				}
			}
		}

		public:
			EditSupplierPopup(void)
			{
				InitializeComponent();
				conn = gcnew Database();
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~EditSupplierPopup()
			{
				if (components)
				{
					delete components;
				}
			}

		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::TextBox^ nameInput;
		protected:

		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::TextBox^ addressInput;

		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::TextBox^ mailInput;

		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::TextBox^ contactInput;


		public: System::Windows::Forms::Button^ saveBtn;
		private: System::Windows::Forms::Button^ cancelBtn;
		public: System::Windows::Forms::Button^ addBtn;
		private:


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
			this->nameInput = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->addressInput = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mailInput = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->contactInput = (gcnew System::Windows::Forms::TextBox());
			this->saveBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Supplier name";
			// 
			// nameInput
			// 
			this->nameInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->nameInput->Location = System::Drawing::Point(15, 30);
			this->nameInput->Name = L"nameInput";
			this->nameInput->Size = System::Drawing::Size(320, 24);
			this->nameInput->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Supplier address";
			// 
			// addressInput
			// 
			this->addressInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->addressInput->Location = System::Drawing::Point(15, 96);
			this->addressInput->Multiline = true;
			this->addressInput->Name = L"addressInput";
			this->addressInput->Size = System::Drawing::Size(320, 55);
			this->addressInput->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 18);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Supplier email";
			// 
			// mailInput
			// 
			this->mailInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mailInput->Location = System::Drawing::Point(15, 188);
			this->mailInput->Name = L"mailInput";
			this->mailInput->Size = System::Drawing::Size(320, 24);
			this->mailInput->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 237);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(106, 18);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Supplier contact";
			// 
			// contactInput
			// 
			this->contactInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->contactInput->Location = System::Drawing::Point(15, 258);
			this->contactInput->Name = L"contactInput";
			this->contactInput->Size = System::Drawing::Size(320, 24);
			this->contactInput->TabIndex = 7;
			// 
			// saveBtn
			// 
			this->saveBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->saveBtn->FlatAppearance->BorderColor = System::Drawing::Color::RoyalBlue;
			this->saveBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveBtn->ForeColor = System::Drawing::Color::Azure;
			this->saveBtn->Location = System::Drawing::Point(237, 302);
			this->saveBtn->Name = L"saveBtn";
			this->saveBtn->Size = System::Drawing::Size(98, 30);
			this->saveBtn->TabIndex = 8;
			this->saveBtn->Text = L"Save Details";
			this->saveBtn->UseVisualStyleBackColor = false;
			this->saveBtn->Click += gcnew System::EventHandler(this, &EditSupplierPopup::saveBtn_Click);
			// 
			// cancelBtn
			// 
			this->cancelBtn->BackColor = System::Drawing::Color::Azure;
			this->cancelBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelBtn->ForeColor = System::Drawing::Color::Black;
			this->cancelBtn->Location = System::Drawing::Point(122, 302);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(98, 30);
			this->cancelBtn->TabIndex = 9;
			this->cancelBtn->Text = L"Cancel";
			this->cancelBtn->UseVisualStyleBackColor = false;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &EditSupplierPopup::cancelBtn_Click);
			// 
			// addBtn
			// 
			this->addBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->addBtn->FlatAppearance->BorderColor = System::Drawing::Color::RoyalBlue;
			this->addBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addBtn->ForeColor = System::Drawing::Color::Azure;
			this->addBtn->Location = System::Drawing::Point(237, 302);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(98, 30);
			this->addBtn->TabIndex = 10;
			this->addBtn->Text = L"Add Supplier";
			this->addBtn->UseVisualStyleBackColor = false;
			this->addBtn->Click += gcnew System::EventHandler(this, &EditSupplierPopup::addBtn_Click);
			// 
			// EditSupplierPopup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Azure;
			this->ClientSize = System::Drawing::Size(352, 344);
			this->Controls->Add(this->addBtn);
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->saveBtn);
			this->Controls->Add(this->contactInput);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->mailInput);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->addressInput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->nameInput);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(368, 383);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(368, 383);
			this->Name = L"EditSupplierPopup";
			this->ShowInTaskbar = false;
			this->Text = L"Edit Supplier Details";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		private: System::Void saveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				String^ name = nameInput->Text;
				String^ address = addressInput->Text;
				String^ email = mailInput->Text;
				String^ contact = contactInput->Text;

				if (name == "" || address == "" || email == "" || contact == "") {
					MessageBox::Show("Required field not provided.", "Error", MessageBoxButtons::OK);
				}
				else {
					if (contact->Length > 15) {
						MessageBox::Show("Contact number must be valid contact number.", "Error", MessageBoxButtons::OK);
					}
					else {
						DateTime^ currentDate = DateTime::Now;
						String^ createdAt = currentDate->ToString("yyyy-MM-dd");

						String^ query = "UPDATE SuppliersTable SET name='" + name + "',address='" + address + "',email='" + email + "',contact='" + contact + "',created_at='" + createdAt + "' WHERE id=" + editId;
						conn->SetData(query);
						this->Close();
					}
				}
			}
			catch (Exception^ e) {
				if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
					Application::Exit();
				}
			}
		}

	private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ name = nameInput->Text;
			String^ address = addressInput->Text;
			String^ email = mailInput->Text;
			String^ contact = contactInput->Text;

			if (name == "" || address == "" || email == "" || contact == "") {
				MessageBox::Show("Required field not provided.", "Error", MessageBoxButtons::OK);
			}
			else {
				if (contact->Length > 15) {
					MessageBox::Show("Contact number must be valid contact number.", "Error", MessageBoxButtons::OK);
				}
				else {
					DateTime^ currentDate = DateTime::Now;
					String^ createdAt = currentDate->ToString("yyyy-MM-dd");

					String^ query = "INSERT INTO SuppliersTable VALUES('" + name + "','" + address + "','" + email + "','" + contact + "','" + createdAt + "')";
					conn->SetData(query);
					this->Close();
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
