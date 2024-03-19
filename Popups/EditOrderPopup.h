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
	public ref class EditOrderPopup : public System::Windows::Forms::Form
	{
	private: Database^ conn;
	private: int editId;
	private: int supplierId;

	private: void loadComboData() {
		try {
			String^ query = "SELECT id,title FROM BooksTable";
			DataTable^ booksData = conn->GetData(query);
			if (booksData->Rows->Count > 0) {
				for each (DataRow ^ r in booksData->Rows) {
					bookInput->Items->Add(gcnew ComboItem(safe_cast<String^>(r["title"]), safe_cast<int>(r["id"])));
				}
			}

			query = "SELECT id,name FROM SuppliersTable";
			DataTable^ suppliersData = conn->GetData(query);
			if (suppliersData->Rows->Count > 0) {
				for each (DataRow ^ r in suppliersData->Rows) {
					supplierInput->Items->Add(gcnew ComboItem(safe_cast<String^>(r["name"]), safe_cast<int>(r["id"])));
				}
			}
		}
		catch (Exception^ e) {
			if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
				Application::Exit();
			}
		}
	} 

	public: void setData(int id) {
		try {
			editId = id;
			String^ query = "SELECT * FROM OrdersTable WHERE id=" + id;
			DataRow^ orderData = conn->GetData(query)->Rows[0];

			query = "SELECT id,name FROM SuppliersTable WHERE id=" + orderData["supplier"];
			DataRow^ supplierData = conn->GetData(query)->Rows[0];
			supplierInput->SelectedItem = gcnew ComboItem(safe_cast<String^>(supplierData["name"]), safe_cast<int>(supplierData["id"]));
			supplierInput->Text = supplierData["name"]->ToString();

			query = "SELECT id,title FROM BooksTable WHERE id=" + orderData["book"];
			DataRow^ bookData = conn->GetData(query)->Rows[0];
			bookInput->SelectedItem = gcnew ComboItem(safe_cast<String^>(bookData["title"]), safe_cast<int>(bookData["id"]));
			bookInput->Text = bookData["title"]->ToString();

			qtyInput->Text = safe_cast<String^>(orderData["qty"]->ToString());
			remarkInput->Text = safe_cast<String^>(orderData["remark"]);
			if (safe_cast<int>(orderData["status"]) == 0) {
				statusInput->Text = "PENDING";
			}
			else {
				statusInput->Text = "COMPLETED";
			}
		}
		catch (Exception^ e) {
			if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
				Application::Exit();
			}
		}
	}
	
	public: void setSupplier(int id) {
		try {
			supplierId = id;
			String^ query = "SELECT name FROM SuppliersTable WHERE id=" + supplierId;
			DataRow^ supplier = conn->GetData(query)->Rows[0];
			supplierInput->SelectedItem = gcnew ComboItem(supplier["name"]->ToString(), supplierId);
			supplierInput->Text = supplier["name"]->ToString();
			supplierInput->Enabled = false;
		}
		catch (Exception^ e) {
			if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
				Application::Exit();
			}
		}
	}

	public:
		EditOrderPopup(void)
		{
			InitializeComponent();
			conn = gcnew Database();
			loadComboData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditOrderPopup()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ bookInput;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ supplierInput;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ qtyInput;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ remarkInput;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ statusInput;
	public: System::Windows::Forms::Button^ saveBtn;
	private: System::Windows::Forms::Button^ cancelBtn;
	public: System::Windows::Forms::Button^ addBtn;
	public: System::Windows::Forms::Button^ delBtn;

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
			this->bookInput = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->supplierInput = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->qtyInput = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->remarkInput = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->statusInput = (gcnew System::Windows::Forms::ComboBox());
			this->saveBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->addBtn = (gcnew System::Windows::Forms::Button());
			this->delBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Book title";
			// 
			// bookInput
			// 
			this->bookInput->FormattingEnabled = true;
			this->bookInput->Location = System::Drawing::Point(15, 30);
			this->bookInput->Name = L"bookInput";
			this->bookInput->Size = System::Drawing::Size(402, 26);
			this->bookInput->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 170);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Supplier name";
			// 
			// supplierInput
			// 
			this->supplierInput->FormattingEnabled = true;
			this->supplierInput->Location = System::Drawing::Point(15, 191);
			this->supplierInput->Name = L"supplierInput";
			this->supplierInput->Size = System::Drawing::Size(402, 26);
			this->supplierInput->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 78);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 18);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Qty";
			// 
			// qtyInput
			// 
			this->qtyInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->qtyInput->Location = System::Drawing::Point(15, 99);
			this->qtyInput->Name = L"qtyInput";
			this->qtyInput->Size = System::Drawing::Size(402, 24);
			this->qtyInput->TabIndex = 5;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 238);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(61, 18);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Remarks";
			// 
			// remarkInput
			// 
			this->remarkInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->remarkInput->Location = System::Drawing::Point(15, 259);
			this->remarkInput->Multiline = true;
			this->remarkInput->Name = L"remarkInput";
			this->remarkInput->Size = System::Drawing::Size(402, 77);
			this->remarkInput->TabIndex = 9;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 370);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(48, 18);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Status";
			// 
			// statusInput
			// 
			this->statusInput->FormattingEnabled = true;
			this->statusInput->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"PENDING", L"COMPLETED" });
			this->statusInput->Location = System::Drawing::Point(15, 391);
			this->statusInput->Name = L"statusInput";
			this->statusInput->Size = System::Drawing::Size(182, 26);
			this->statusInput->TabIndex = 11;
			// 
			// saveBtn
			// 
			this->saveBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->saveBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveBtn->ForeColor = System::Drawing::Color::Azure;
			this->saveBtn->Location = System::Drawing::Point(15, 437);
			this->saveBtn->Name = L"saveBtn";
			this->saveBtn->Size = System::Drawing::Size(101, 39);
			this->saveBtn->TabIndex = 12;
			this->saveBtn->Text = L"Save Details";
			this->saveBtn->UseVisualStyleBackColor = false;
			this->saveBtn->Click += gcnew System::EventHandler(this, &EditOrderPopup::saveBtn_Click);
			// 
			// cancelBtn
			// 
			this->cancelBtn->BackColor = System::Drawing::Color::Azure;
			this->cancelBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cancelBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelBtn->ForeColor = System::Drawing::Color::Black;
			this->cancelBtn->Location = System::Drawing::Point(330, 437);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(87, 39);
			this->cancelBtn->TabIndex = 13;
			this->cancelBtn->Text = L"Cancel";
			this->cancelBtn->UseVisualStyleBackColor = false;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &EditOrderPopup::cancelBtn_Click);
			// 
			// addBtn
			// 
			this->addBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->addBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addBtn->ForeColor = System::Drawing::Color::Azure;
			this->addBtn->Location = System::Drawing::Point(15, 437);
			this->addBtn->Name = L"addBtn";
			this->addBtn->Size = System::Drawing::Size(101, 39);
			this->addBtn->TabIndex = 14;
			this->addBtn->Text = L"Add Order";
			this->addBtn->UseVisualStyleBackColor = false;
			this->addBtn->Click += gcnew System::EventHandler(this, &EditOrderPopup::addBtn_Click);
			// 
			// delBtn
			// 
			this->delBtn->BackColor = System::Drawing::Color::Salmon;
			this->delBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delBtn->ForeColor = System::Drawing::Color::Azure;
			this->delBtn->Location = System::Drawing::Point(134, 437);
			this->delBtn->Name = L"delBtn";
			this->delBtn->Size = System::Drawing::Size(101, 39);
			this->delBtn->TabIndex = 15;
			this->delBtn->Text = L"Delete Order";
			this->delBtn->UseVisualStyleBackColor = false;
			this->delBtn->Click += gcnew System::EventHandler(this, &EditOrderPopup::delBtn_Click);
			// 
			// EditOrderPopup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Azure;
			this->ClientSize = System::Drawing::Size(429, 488);
			this->Controls->Add(this->delBtn);
			this->Controls->Add(this->addBtn);
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->saveBtn);
			this->Controls->Add(this->statusInput);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->remarkInput);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->qtyInput);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->supplierInput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->bookInput);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(445, 481);
			this->Name = L"EditOrderPopup";
			this->ShowInTaskbar = false;
			this->Text = L"Edit Order Details";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void saveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			int supplier = safe_cast<ComboItem^>(supplierInput->SelectedItem)->GetValue();
			int book = safe_cast<ComboItem^>(bookInput->SelectedItem)->GetValue();
			String^ qty = qtyInput->Text;
			String^ remarks = remarkInput->Text;
			int status = statusInput->Text == "COMPLETED" ? 1 : 0;

			if (qty == "") {
				MessageBox::Show("Quantity is required.", "Error", MessageBoxButtons::OK);
			}
			else {
				String^ query = "UPDATE OrdersTable SET supplier=" + supplier + ", book=" + book + ", qty=" + qty + ", status=" + status + ", remark='" + remarks + "' WHERE id=" + editId;
				conn->SetData(query);
				this->Close();
			}
		}
		catch (Exception^ e) {
			if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
				Application::Exit();
			}
		}
	}

	private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			int book = safe_cast<ComboItem^>(bookInput->SelectedItem)->GetValue();
			int supplier = safe_cast<ComboItem^>(supplierInput->SelectedItem)->GetValue();
			String^ qty = qtyInput->Text;
			String^ remark = remarkInput->Text;
			int status = statusInput->Text == "COMPLETED" ? 1 : 0;

			if (qty == "") {
				MessageBox::Show("Quantity is required.", "Error", MessageBoxButtons::OK);
			}
			else {
				DateTime^ currentDate = DateTime::Now;
				String^ createdAt = currentDate->ToString("yyyy-MM-dd");

				String^ query = "INSERT INTO OrdersTable VALUES(" + supplier + "," + book + "," + qty + "," + status + ",'" + createdAt + "','" + remark + "')";
				conn->SetData(query);
				this->Close();
			}
		}
		catch (Exception^ e) {
			if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
				Application::Exit();
			}
		}
	}
	
	private: System::Void delBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ query = "DELETE FROM OrdersTable WHERE id=" + editId;
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
