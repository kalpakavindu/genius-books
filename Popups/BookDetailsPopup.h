#pragma once
#include <string>
#include "../Database.h"
#include "../Popups/EditBookPopup.h"


namespace GeniusBooks {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BookDetailsPopup
	/// </summary>
	public ref class BookDetailsPopup : public System::Windows::Forms::Form
	{
		private: int bookId;
		private: Database^ conn;
		private: void openEditBookPopup(int id) {
			EditBookPopup^ editBookPopup = gcnew EditBookPopup();
			editBookPopup->addBtn->Hide();
			editBookPopup->setData(id);
			editBookPopup->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &BookDetailsPopup::formClosed);
			editBookPopup->ShowDialog();
		}
		private: void loadData() {
			try {
				String^ query = "SELECT * FROM BooksTable WHERE id=" + bookId;
				DataRow^ data = conn->GetData(query)->Rows[0];

				titleLabel->Text = data["title"]->ToString();
				authorLabel->Text = "by " + data["author"]->ToString();
				publisherLabel->Text = data["publisher"]->ToString();
				isbnLabel->Text = data["isbn"]->ToString();
				addedDateLabel->Text = data["created_at"]->ToString();

				query = "SELECT name FROM SuppliersTable WHERE id=" + safe_cast<int>(data["supplier"]);
				DataRow^ supplier = conn->GetData(query)->Rows[0];
				supplierLink->Text = supplier["name"]->ToString();

				priceLabel->Text = data["unit_price"]->ToString();
				inStockLabel->Text = data["stock_qty"]->ToString();

				query = "SELECT qty FROM OrdersTable WHERE book=" + bookId + " AND status=0";
				int c = 0;
				DataTable^ ordersData = conn->GetData(query);
				for each (DataRow ^ r in ordersData->Rows) {
					c += safe_cast<int>(r["qty"]);
				}
				String^ ordersCount = "" + ordersData->Rows->Count;
				String^ orderedCount = "" + c;
				orderedLabel->Text = orderedCount + " - " + ordersCount;
			}
			catch (Exception^ e) {
				if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
					Application::Exit();
				}
			}
		}

		public:
			BookDetailsPopup(int id)
			{
				InitializeComponent();
				conn = gcnew Database();
				bookId = id;
				loadData();
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~BookDetailsPopup()
			{
				if (components)
				{
					delete components;
				}
			}

		private: System::Windows::Forms::Label^ titleLabel;
		private: System::Windows::Forms::Label^ authorLabel;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::Label^ isbnLabel;
		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::Label^ addedDateLabel;
		private: System::Windows::Forms::Label^ label9;
		private: System::Windows::Forms::LinkLabel^ supplierLink;
		private: System::Windows::Forms::Label^ label10;
		private: System::Windows::Forms::Label^ publisherLabel;
		private: System::Windows::Forms::Label^ priceLabel;
		private: System::Windows::Forms::Label^ label13;
		private: System::Windows::Forms::Label^ label15;
		private: System::Windows::Forms::Label^ inStockLabel;
		private: System::Windows::Forms::Label^ orderedLabel;
		private: System::Windows::Forms::Panel^ panel1;
		private: System::Windows::Forms::Panel^ panel2;
		private: System::Windows::Forms::Panel^ panel3;
		private: System::Windows::Forms::Panel^ panel4;
		private: System::Windows::Forms::Button^ editBtn;
		private: System::Windows::Forms::Button^ delBtn;

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
				this->titleLabel = (gcnew System::Windows::Forms::Label());
				this->authorLabel = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->isbnLabel = (gcnew System::Windows::Forms::Label());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->addedDateLabel = (gcnew System::Windows::Forms::Label());
				this->label9 = (gcnew System::Windows::Forms::Label());
				this->supplierLink = (gcnew System::Windows::Forms::LinkLabel());
				this->label10 = (gcnew System::Windows::Forms::Label());
				this->publisherLabel = (gcnew System::Windows::Forms::Label());
				this->priceLabel = (gcnew System::Windows::Forms::Label());
				this->label13 = (gcnew System::Windows::Forms::Label());
				this->label15 = (gcnew System::Windows::Forms::Label());
				this->inStockLabel = (gcnew System::Windows::Forms::Label());
				this->orderedLabel = (gcnew System::Windows::Forms::Label());
				this->panel1 = (gcnew System::Windows::Forms::Panel());
				this->panel2 = (gcnew System::Windows::Forms::Panel());
				this->panel3 = (gcnew System::Windows::Forms::Panel());
				this->panel4 = (gcnew System::Windows::Forms::Panel());
				this->editBtn = (gcnew System::Windows::Forms::Button());
				this->delBtn = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// titleLabel
				// 
				this->titleLabel->AutoSize = true;
				this->titleLabel->Font = (gcnew System::Drawing::Font(L"Mulish ExtraBold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->titleLabel->Location = System::Drawing::Point(12, 9);
				this->titleLabel->Name = L"titleLabel";
				this->titleLabel->Size = System::Drawing::Size(436, 33);
				this->titleLabel->TabIndex = 0;
				this->titleLabel->Text = L"The Adventures of Huckleberry Finn";
				// 
				// authorLabel
				// 
				this->authorLabel->AutoSize = true;
				this->authorLabel->Font = (gcnew System::Drawing::Font(L"Mulish", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->authorLabel->Location = System::Drawing::Point(15, 51);
				this->authorLabel->Name = L"authorLabel";
				this->authorLabel->Size = System::Drawing::Size(120, 22);
				this->authorLabel->TabIndex = 1;
				this->authorLabel->Text = L"by Mark Twain";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(531, 54);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(41, 18);
				this->label3->TabIndex = 2;
				this->label3->Text = L"ISBN:";
				// 
				// isbnLabel
				// 
				this->isbnLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
				this->isbnLabel->Location = System::Drawing::Point(578, 54);
				this->isbnLabel->Name = L"isbnLabel";
				this->isbnLabel->Size = System::Drawing::Size(112, 18);
				this->isbnLabel->TabIndex = 3;
				this->isbnLabel->Text = L"1234567564356";
				// 
				// label7
				// 
				this->label7->AutoSize = true;
				this->label7->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label7->Location = System::Drawing::Point(15, 113);
				this->label7->Name = L"label7";
				this->label7->Size = System::Drawing::Size(90, 20);
				this->label7->TabIndex = 6;
				this->label7->Text = L"Date added";
				// 
				// addedDateLabel
				// 
				this->addedDateLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->addedDateLabel->Location = System::Drawing::Point(124, 111);
				this->addedDateLabel->Name = L"addedDateLabel";
				this->addedDateLabel->Size = System::Drawing::Size(228, 22);
				this->addedDateLabel->TabIndex = 7;
				this->addedDateLabel->Text = L"24/07/2024";
				// 
				// label9
				// 
				this->label9->AutoSize = true;
				this->label9->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label9->Location = System::Drawing::Point(15, 150);
				this->label9->Name = L"label9";
				this->label9->Size = System::Drawing::Size(66, 20);
				this->label9->TabIndex = 8;
				this->label9->Text = L"Supplier";
				// 
				// supplierLink
				// 
				this->supplierLink->Cursor = System::Windows::Forms::Cursors::Hand;
				this->supplierLink->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->supplierLink->LinkBehavior = System::Windows::Forms::LinkBehavior::NeverUnderline;
				this->supplierLink->LinkColor = System::Drawing::Color::RoyalBlue;
				this->supplierLink->Location = System::Drawing::Point(124, 150);
				this->supplierLink->Name = L"supplierLink";
				this->supplierLink->Size = System::Drawing::Size(224, 20);
				this->supplierLink->TabIndex = 9;
				this->supplierLink->TabStop = true;
				this->supplierLink->Text = L"Saliya distributers";
				// 
				// label10
				// 
				this->label10->AutoSize = true;
				this->label10->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label10->Location = System::Drawing::Point(15, 189);
				this->label10->Name = L"label10";
				this->label10->Size = System::Drawing::Size(74, 20);
				this->label10->TabIndex = 10;
				this->label10->Text = L"Publisher";
				// 
				// publisherLabel
				// 
				this->publisherLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->publisherLabel->Location = System::Drawing::Point(124, 187);
				this->publisherLabel->Name = L"publisherLabel";
				this->publisherLabel->Size = System::Drawing::Size(228, 22);
				this->publisherLabel->TabIndex = 11;
				this->publisherLabel->Text = L"Imashi Publications";
				// 
				// priceLabel
				// 
				this->priceLabel->AutoSize = true;
				this->priceLabel->Font = (gcnew System::Drawing::Font(L"Mulish", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->priceLabel->Location = System::Drawing::Point(12, 277);
				this->priceLabel->Name = L"priceLabel";
				this->priceLabel->Size = System::Drawing::Size(158, 33);
				this->priceLabel->TabIndex = 12;
				this->priceLabel->Text = L"2345.45 LKR";
				// 
				// label13
				// 
				this->label13->AutoSize = true;
				this->label13->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label13->Location = System::Drawing::Point(14, 355);
				this->label13->Name = L"label13";
				this->label13->Size = System::Drawing::Size(64, 20);
				this->label13->TabIndex = 13;
				this->label13->Text = L"In Stock";
				// 
				// label15
				// 
				this->label15->AutoSize = true;
				this->label15->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label15->Location = System::Drawing::Point(14, 391);
				this->label15->Name = L"label15";
				this->label15->Size = System::Drawing::Size(65, 20);
				this->label15->TabIndex = 15;
				this->label15->Text = L"Ordered";
				// 
				// inStockLabel
				// 
				this->inStockLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->inStockLabel->Location = System::Drawing::Point(91, 355);
				this->inStockLabel->Name = L"inStockLabel";
				this->inStockLabel->Size = System::Drawing::Size(156, 20);
				this->inStockLabel->TabIndex = 16;
				this->inStockLabel->Text = L"10045";
				// 
				// orderedLabel
				// 
				this->orderedLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->orderedLabel->Location = System::Drawing::Point(91, 391);
				this->orderedLabel->Name = L"orderedLabel";
				this->orderedLabel->Size = System::Drawing::Size(156, 20);
				this->orderedLabel->TabIndex = 18;
				this->orderedLabel->Text = L"10045";
				// 
				// panel1
				// 
				this->panel1->BackColor = System::Drawing::Color::PaleTurquoise;
				this->panel1->Location = System::Drawing::Point(377, 90);
				this->panel1->Name = L"panel1";
				this->panel1->Size = System::Drawing::Size(177, 139);
				this->panel1->TabIndex = 19;
				// 
				// panel2
				// 
				this->panel2->BackColor = System::Drawing::Color::LightCyan;
				this->panel2->Location = System::Drawing::Point(569, 209);
				this->panel2->Name = L"panel2";
				this->panel2->Size = System::Drawing::Size(121, 101);
				this->panel2->TabIndex = 20;
				// 
				// panel3
				// 
				this->panel3->BackColor = System::Drawing::Color::AliceBlue;
				this->panel3->Location = System::Drawing::Point(569, 129);
				this->panel3->Name = L"panel3";
				this->panel3->Size = System::Drawing::Size(74, 63);
				this->panel3->TabIndex = 21;
				// 
				// panel4
				// 
				this->panel4->BackColor = System::Drawing::Color::AliceBlue;
				this->panel4->Location = System::Drawing::Point(480, 246);
				this->panel4->Name = L"panel4";
				this->panel4->Size = System::Drawing::Size(74, 63);
				this->panel4->TabIndex = 22;
				// 
				// editBtn
				// 
				this->editBtn->BackColor = System::Drawing::Color::RoyalBlue;
				this->editBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->editBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->editBtn->ForeColor = System::Drawing::Color::Azure;
				this->editBtn->Location = System::Drawing::Point(542, 348);
				this->editBtn->Name = L"editBtn";
				this->editBtn->Size = System::Drawing::Size(148, 36);
				this->editBtn->TabIndex = 23;
				this->editBtn->Text = L"Edit Book";
				this->editBtn->UseVisualStyleBackColor = false;
				this->editBtn->Click += gcnew System::EventHandler(this, &BookDetailsPopup::editBtn_Click);
				// 
				// delBtn
				// 
				this->delBtn->BackColor = System::Drawing::Color::Salmon;
				this->delBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->delBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->delBtn->ForeColor = System::Drawing::Color::Azure;
				this->delBtn->Location = System::Drawing::Point(542, 401);
				this->delBtn->Name = L"delBtn";
				this->delBtn->Size = System::Drawing::Size(148, 36);
				this->delBtn->TabIndex = 24;
				this->delBtn->Text = L"Delete Book";
				this->delBtn->UseVisualStyleBackColor = false;
				this->delBtn->Click += gcnew System::EventHandler(this, &BookDetailsPopup::delBtn_Click);
				// 
				// BookDetailsPopup
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::Azure;
				this->ClientSize = System::Drawing::Size(702, 465);
				this->Controls->Add(this->delBtn);
				this->Controls->Add(this->editBtn);
				this->Controls->Add(this->panel4);
				this->Controls->Add(this->panel3);
				this->Controls->Add(this->panel2);
				this->Controls->Add(this->panel1);
				this->Controls->Add(this->orderedLabel);
				this->Controls->Add(this->inStockLabel);
				this->Controls->Add(this->label15);
				this->Controls->Add(this->label13);
				this->Controls->Add(this->priceLabel);
				this->Controls->Add(this->publisherLabel);
				this->Controls->Add(this->label10);
				this->Controls->Add(this->supplierLink);
				this->Controls->Add(this->label9);
				this->Controls->Add(this->addedDateLabel);
				this->Controls->Add(this->label7);
				this->Controls->Add(this->isbnLabel);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->authorLabel);
				this->Controls->Add(this->titleLabel);
				this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				this->Margin = System::Windows::Forms::Padding(4);
				this->MaximizeBox = false;
				this->MaximumSize = System::Drawing::Size(718, 504);
				this->MinimizeBox = false;
				this->MinimumSize = System::Drawing::Size(718, 504);
				this->Name = L"BookDetailsPopup";
				this->ShowInTaskbar = false;
				this->Text = L"BookDetailsPopup";
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion

		private: System::Void formClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
			loadData();
		}
	
		private: System::Void editBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			openEditBookPopup(bookId);
		}
	
		private: System::Void delBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				String^ query = "DELETE FROM OrdersTable WHERE book=" + bookId;
				conn->SetData(query);

				query = "DELETE FROM BooksTable WHERE id=" + bookId;
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
