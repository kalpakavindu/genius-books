#pragma once
#include "../Database.h"
#include "../ComboItem.h"

namespace GeniusBooks {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditBookPopup
	/// </summary>
	public ref class EditBookPopup : public System::Windows::Forms::Form
	{
	private: Database^ conn;
	private: int editId;

	private:void loadComboData(){
		try {
			String^ query = "SELECT id,name FROM SuppliersTable";
			DataTable^ suppliers = conn->GetData(query);
			for each (DataRow ^ r in suppliers->Rows) {
				supplierInput->Items->Add(gcnew ComboItem(safe_cast<String^>(r["name"]), safe_cast<int>(r["id"])));
			}
		}
		catch (Exception^ e) {
			if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
				Application::Exit();
			}
		}
	}

	public:
		EditBookPopup(void)
		{
			InitializeComponent();
			conn = gcnew Database();
			loadComboData();
		}

		void setData(int id) {
			try {
				editId = id;
				String^ query = "SELECT * FROM BooksTable WHERE id=" + editId;
				DataRow^ bookData = conn->GetData(query)->Rows[0];

				titleInput->Text = safe_cast<String^>(bookData["title"]);
				isbnInput->Text = safe_cast<String^>(bookData["isbn"]);
				authorInput->Text = safe_cast<String^>(bookData["author"]);
				publisherInput->Text = safe_cast<String^>(bookData["publisher"]);
				priceInput->Text = safe_cast<String^>(bookData["unit_price"]);
				stockInput->Text = bookData["stock_qty"]->ToString();

				query = "SELECT id,name FROM SuppliersTable WHERE id=" + safe_cast<int>(bookData["supplier"]);
				DataRow^ supplier = conn->GetData(query)->Rows[0];
				supplierInput->SelectedItem = gcnew ComboItem(safe_cast<String^>(supplier["name"]), safe_cast<int>(supplier["id"]));
				supplierInput->Text = safe_cast<String^>(supplier["name"]);
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
		~EditBookPopup()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ titleInput;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ isbnInput;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ authorInput;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ supplierInput;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ publisherInput;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ priceInput;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ stockInput;
	private: System::Windows::Forms::Label^ label9;
	public: System::Windows::Forms::Button^ saveBtn;
	private: System::Windows::Forms::Button^ cancelBtn;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label11;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->titleInput = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->isbnInput = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->authorInput = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->supplierInput = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->publisherInput = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->stockInput = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->priceInput = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->saveBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Book title";
			// 
			// titleInput
			// 
			this->titleInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->titleInput->Location = System::Drawing::Point(15, 30);
			this->titleInput->Name = L"titleInput";
			this->titleInput->Size = System::Drawing::Size(351, 24);
			this->titleInput->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(408, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 18);
			this->label3->TabIndex = 3;
			this->label3->Text = L"ISBN";
			// 
			// isbnInput
			// 
			this->isbnInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->isbnInput->Location = System::Drawing::Point(411, 30);
			this->isbnInput->Name = L"isbnInput";
			this->isbnInput->Size = System::Drawing::Size(351, 24);
			this->isbnInput->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 18);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Author";
			// 
			// authorInput
			// 
			this->authorInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->authorInput->Location = System::Drawing::Point(15, 94);
			this->authorInput->Name = L"authorInput";
			this->authorInput->Size = System::Drawing::Size(351, 24);
			this->authorInput->TabIndex = 6;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 141);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(58, 18);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Supplier";
			// 
			// supplierInput
			// 
			this->supplierInput->FormattingEnabled = true;
			this->supplierInput->Location = System::Drawing::Point(15, 162);
			this->supplierInput->Name = L"supplierInput";
			this->supplierInput->Size = System::Drawing::Size(351, 26);
			this->supplierInput->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(408, 141);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(64, 18);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Publisher";
			// 
			// publisherInput
			// 
			this->publisherInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->publisherInput->Location = System::Drawing::Point(411, 162);
			this->publisherInput->Name = L"publisherInput";
			this->publisherInput->Size = System::Drawing::Size(351, 24);
			this->publisherInput->TabIndex = 13;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightCyan;
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->stockInput);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->priceInput);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Location = System::Drawing::Point(10, 218);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(247, 208);
			this->panel1->TabIndex = 14;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(204, 34);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(32, 18);
			this->label11->TabIndex = 17;
			this->label11->Text = L"LKR";
			// 
			// stockInput
			// 
			this->stockInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->stockInput->Location = System::Drawing::Point(11, 97);
			this->stockInput->Name = L"stockInput";
			this->stockInput->Size = System::Drawing::Size(223, 24);
			this->stockInput->TabIndex = 14;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(8, 76);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(55, 18);
			this->label9->TabIndex = 13;
			this->label9->Text = L"In Stock";
			// 
			// priceInput
			// 
			this->priceInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->priceInput->Location = System::Drawing::Point(11, 32);
			this->priceInput->Name = L"priceInput";
			this->priceInput->Size = System::Drawing::Size(187, 24);
			this->priceInput->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(8, 11);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(65, 18);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Unit Price";
			// 
			// saveBtn
			// 
			this->saveBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->saveBtn->FlatAppearance->BorderColor = System::Drawing::Color::RoyalBlue;
			this->saveBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveBtn->ForeColor = System::Drawing::Color::Azure;
			this->saveBtn->Location = System::Drawing::Point(626, 393);
			this->saveBtn->Name = L"saveBtn";
			this->saveBtn->Size = System::Drawing::Size(136, 33);
			this->saveBtn->TabIndex = 15;
			this->saveBtn->Text = L"Save Details";
			this->saveBtn->UseVisualStyleBackColor = false;
			this->saveBtn->Click += gcnew System::EventHandler(this, &EditBookPopup::saveBtn_Click);
			// 
			// cancelBtn
			// 
			this->cancelBtn->BackColor = System::Drawing::Color::Azure;
			this->cancelBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelBtn->ForeColor = System::Drawing::Color::Black;
			this->cancelBtn->Location = System::Drawing::Point(475, 393);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(136, 33);
			this->cancelBtn->TabIndex = 16;
			this->cancelBtn->Text = L"Cancel";
			this->cancelBtn->UseVisualStyleBackColor = false;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &EditBookPopup::cancelBtn_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel2->Location = System::Drawing::Point(418, 218);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(193, 104);
			this->panel2->TabIndex = 17;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::LightCyan;
			this->panel3->Location = System::Drawing::Point(626, 283);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(136, 80);
			this->panel3->TabIndex = 18;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::AliceBlue;
			this->panel4->Location = System::Drawing::Point(626, 243);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(78, 27);
			this->panel4->TabIndex = 19;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::AliceBlue;
			this->panel5->Location = System::Drawing::Point(517, 336);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(94, 27);
			this->panel5->TabIndex = 20;
			// 
			// addBtn
			// 
			this->addBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->addBtn->FlatAppearance->BorderColor = System::Drawing::Color::RoyalBlue;
			this->addBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addBtn->ForeColor = System::Drawing::Color::Azure;
			this->addBtn->Location = System::Drawing::Point(626, 393);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(136, 33);
			this->addBtn->TabIndex = 21;
			this->addBtn->Text = L"Add Book";
			this->addBtn->UseVisualStyleBackColor = false;
			this->addBtn->Click += gcnew System::EventHandler(this, &EditBookPopup::addBtn_Click);
			// 
			// EditBookPopup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Azure;
			this->ClientSize = System::Drawing::Size(776, 441);
			this->Controls->Add(this->addBtn);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->saveBtn);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->publisherInput);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->supplierInput);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->authorInput);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->isbnInput);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->titleInput);
			this->Controls->Add(this->label2);
			this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(792, 480);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(792, 480);
			this->Name = L"EditBookPopup";
			this->ShowInTaskbar = false;
			this->Text = L"Edit Book Details";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

	private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void saveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ title = titleInput->Text;
			String^ isbn = isbnInput->Text;
			String^ author = authorInput->Text;
			int supplier = safe_cast<ComboItem^>(supplierInput->SelectedItem)->GetValue();
			String^ publisher = publisherInput->Text;
			String^ unitPrice = priceInput->Text;
			String^ inStock = stockInput->Text;

			if (title == "" || isbn == "" || author == "" || publisher == "" || unitPrice == "" || inStock == "" || supplierInput->Text == "") {
				MessageBox::Show("All fields must be provided.", "Error", MessageBoxButtons::OK);
			}
			else {
				if (isbn->Length > 13) {
					MessageBox::Show("ISBN must be a valid input.", "Error", MessageBoxButtons::OK);
				}
				else {
					String^ query = "UPDATE BooksTable SET title='" + title + "', author='" + author + "', publisher='" + publisher + "', unit_price=" + unitPrice + ", stock_qty=" + inStock + ", supplier=" + supplier;
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
			String^ title = titleInput->Text;
			String^ isbn = isbnInput->Text;
			String^ author = authorInput->Text;
			int supplier = safe_cast<ComboItem^>(supplierInput->SelectedItem)->GetValue();
			String^ publisher = publisherInput->Text;
			String^ unitPrice = priceInput->Text;
			String^ inStock = stockInput->Text;

			if (title == "" || isbn == "" || author == "" || publisher == "" || unitPrice == "" || inStock == "" || supplierInput->Text == "") {
				MessageBox::Show("All fields must be provided.", "Error", MessageBoxButtons::OK);
			}
			else {
				if (isbn->Length > 13) {
					MessageBox::Show("ISBN must be a valid input.", "Error", MessageBoxButtons::OK);
				}
				else {
					DateTime^ currentDate = DateTime::Now;
					String^ createdAt = currentDate->ToString("yyyy-MM-dd");

					String^ query = "INSERT INTO BooksTable VALUES(" + isbn + ",'" + title + "','" + author + "','" + publisher + "','" + unitPrice + "'," + inStock + "," + supplier + ",'" + createdAt + "')";
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
