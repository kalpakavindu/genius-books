#pragma once
#include "../Database.h"
#include "../Popups/EditBookPopup.h"
#include "../Popups/EditOrderPopup.h"
#include "../Popups/BookDetailsPopup.h"

namespace GeniusBooks {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BooksPanel
	/// </summary>
	public ref class BooksPanel : public System::Windows::Forms::Form
	{
		private: Database^ conn;
		private: int currentTab = 0;

		public: BooksPanel(void)
			{
				InitializeComponent();
				conn = gcnew Database();
				currentTab = 0;
				loadData();
			}

		private: 
			void loadData() {
				try {
					String^ query;
					if (this->currentTab == 0) {
						ordersBtn->BackColor = System::Drawing::Color::Azure;
						stockBtn->BackColor = System::Drawing::Color::PaleTurquoise;
						addOrderBtn->Hide();
						addBtn->Show();
						dataGrid2->Hide();
						dataGrid->Show();
						query = "SELECT * FROM BooksTable";
						DataTable^ bookDetails = conn->GetData(query);
						dataGrid->DataSource = bookDetails;
					}
					else {
						stockBtn->BackColor = System::Drawing::Color::Azure;
						ordersBtn->BackColor = System::Drawing::Color::PaleTurquoise;
						addBtn->Hide();
						addOrderBtn->Show();
						dataGrid->Hide();
						dataGrid2->Show();
						query = "SELECT * FROM OrdersTable";
						DataTable^ orderDetails = conn->GetData(query);
						dataGrid2->DataSource = orderDetails;
					}
				}
				catch (Exception^ e) {
					if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
						Application::Exit();
					}
				}
			}

			void openAddBookModel() {
				EditBookPopup^ editBookPopup = gcnew EditBookPopup();
				editBookPopup->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &BooksPanel::formClosed);
				editBookPopup->Text = "Add New Book";
				editBookPopup->saveBtn->Hide();
				editBookPopup->addBtn->Show();
				editBookPopup->ShowDialog();
			}

			void openAddOrderModel() {
				EditOrderPopup^ editOrderPopup = gcnew EditOrderPopup();
				editOrderPopup->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &BooksPanel::formClosed);
				editOrderPopup->Text = "Add New Order";
				editOrderPopup->saveBtn->Hide();
				editOrderPopup->addBtn->Show();
				editOrderPopup->delBtn->Hide();
				editOrderPopup->ShowDialog();
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~BooksPanel()
			{
				if (components)
				{
					delete components;
				}
			}

		private: System::Windows::Forms::DataGridView^ dataGrid2;
		private: System::Windows::Forms::Button^ addOrderBtn;
		private: System::Windows::Forms::Panel^ panel1;
		private: System::Windows::Forms::Button^ addBtn;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Button^ ordersBtn;
		private: System::Windows::Forms::Button^ stockBtn;
		private: System::Windows::Forms::Panel^ mainPanel;
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
				this->addOrderBtn = (gcnew System::Windows::Forms::Button());
				this->addBtn = (gcnew System::Windows::Forms::Button());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->ordersBtn = (gcnew System::Windows::Forms::Button());
				this->stockBtn = (gcnew System::Windows::Forms::Button());
				this->mainPanel = (gcnew System::Windows::Forms::Panel());
				this->dataGrid2 = (gcnew System::Windows::Forms::DataGridView());
				this->dataGrid = (gcnew System::Windows::Forms::DataGridView());
				this->panel1->SuspendLayout();
				this->mainPanel->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid2))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->BeginInit();
				this->SuspendLayout();
				// 
				// panel1
				// 
				this->panel1->Controls->Add(this->addOrderBtn);
				this->panel1->Controls->Add(this->addBtn);
				this->panel1->Controls->Add(this->label1);
				this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
				this->panel1->Location = System::Drawing::Point(0, 0);
				this->panel1->Name = L"panel1";
				this->panel1->Size = System::Drawing::Size(798, 66);
				this->panel1->TabIndex = 4;
				// 
				// addOrderBtn
				// 
				this->addOrderBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
				this->addOrderBtn->BackColor = System::Drawing::Color::RoyalBlue;
				this->addOrderBtn->Cursor = System::Windows::Forms::Cursors::Hand;
				this->addOrderBtn->FlatAppearance->BorderColor = System::Drawing::Color::RoyalBlue;
				this->addOrderBtn->FlatAppearance->BorderSize = 2;
				this->addOrderBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->addOrderBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->addOrderBtn->ForeColor = System::Drawing::Color::Azure;
				this->addOrderBtn->Location = System::Drawing::Point(699, 18);
				this->addOrderBtn->Name = L"addOrderBtn";
				this->addOrderBtn->Size = System::Drawing::Size(87, 32);
				this->addOrderBtn->TabIndex = 3;
				this->addOrderBtn->Text = L"Add Order";
				this->addOrderBtn->UseVisualStyleBackColor = false;
				this->addOrderBtn->Click += gcnew System::EventHandler(this, &BooksPanel::addOrderBtn_Click);
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
				this->addBtn->Text = L"Add Book";
				this->addBtn->UseVisualStyleBackColor = false;
				this->addBtn->Click += gcnew System::EventHandler(this, &BooksPanel::addBtn_Click);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Mulish Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label1->Location = System::Drawing::Point(12, 19);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(169, 28);
				this->label1->TabIndex = 0;
				this->label1->Text = L"Manage Books";
				// 
				// ordersBtn
				// 
				this->ordersBtn->BackColor = System::Drawing::Color::Azure;
				this->ordersBtn->Cursor = System::Windows::Forms::Cursors::Hand;
				this->ordersBtn->FlatAppearance->BorderSize = 0;
				this->ordersBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->ordersBtn->Font = (gcnew System::Drawing::Font(L"Mulish SemiBold", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->ordersBtn->Location = System::Drawing::Point(113, 72);
				this->ordersBtn->Name = L"ordersBtn";
				this->ordersBtn->Size = System::Drawing::Size(101, 31);
				this->ordersBtn->TabIndex = 9;
				this->ordersBtn->Text = L"Orders";
				this->ordersBtn->UseVisualStyleBackColor = false;
				this->ordersBtn->Click += gcnew System::EventHandler(this, &BooksPanel::ordersBtn_Click);
				// 
				// stockBtn
				// 
				this->stockBtn->BackColor = System::Drawing::Color::PaleTurquoise;
				this->stockBtn->Cursor = System::Windows::Forms::Cursors::Hand;
				this->stockBtn->FlatAppearance->BorderSize = 0;
				this->stockBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->stockBtn->Font = (gcnew System::Drawing::Font(L"Mulish SemiBold", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->stockBtn->Location = System::Drawing::Point(12, 72);
				this->stockBtn->Name = L"stockBtn";
				this->stockBtn->Size = System::Drawing::Size(101, 31);
				this->stockBtn->TabIndex = 8;
				this->stockBtn->Text = L"Stock";
				this->stockBtn->UseVisualStyleBackColor = false;
				this->stockBtn->Click += gcnew System::EventHandler(this, &BooksPanel::stockBtn_Click);
				// 
				// mainPanel
				// 
				this->mainPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					| System::Windows::Forms::AnchorStyles::Left)
					| System::Windows::Forms::AnchorStyles::Right));
				this->mainPanel->BackColor = System::Drawing::Color::LightCyan;
				this->mainPanel->Controls->Add(this->dataGrid2);
				this->mainPanel->Controls->Add(this->dataGrid);
				this->mainPanel->Location = System::Drawing::Point(12, 104);
				this->mainPanel->Name = L"mainPanel";
				this->mainPanel->Size = System::Drawing::Size(774, 444);
				this->mainPanel->TabIndex = 7;
				// 
				// dataGrid2
				// 
				this->dataGrid2->AllowUserToAddRows = false;
				this->dataGrid2->AllowUserToDeleteRows = false;
				this->dataGrid2->AllowUserToOrderColumns = true;
				this->dataGrid2->BackgroundColor = System::Drawing::Color::LightCyan;
				this->dataGrid2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGrid2->Dock = System::Windows::Forms::DockStyle::Fill;
				this->dataGrid2->Location = System::Drawing::Point(0, 0);
				this->dataGrid2->Name = L"dataGrid2";
				this->dataGrid2->ReadOnly = true;
				this->dataGrid2->Size = System::Drawing::Size(774, 444);
				this->dataGrid2->TabIndex = 1;
				this->dataGrid2->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &BooksPanel::dataGrid2_CellDoubleClick);
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
				this->dataGrid->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &BooksPanel::dataGrid_CellDoubleClick);
				// 
				// BooksPanel
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::LightCyan;
				this->ClientSize = System::Drawing::Size(798, 561);
				this->Controls->Add(this->ordersBtn);
				this->Controls->Add(this->stockBtn);
				this->Controls->Add(this->mainPanel);
				this->Controls->Add(this->panel1);
				this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				this->Margin = System::Windows::Forms::Padding(4);
				this->MinimizeBox = false;
				this->MinimumSize = System::Drawing::Size(798, 561);
				this->Name = L"BooksPanel";
				this->ShowIcon = false;
				this->ShowInTaskbar = false;
				this->Text = L"BooksPanel";
				this->panel1->ResumeLayout(false);
				this->panel1->PerformLayout();
				this->mainPanel->ResumeLayout(false);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid2))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->EndInit();
				this->ResumeLayout(false);

			}
	#pragma endregion

		private: void ordersBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			currentTab = 1;
			loadData();
		}
		private: System::Void stockBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			currentTab = 0;
			loadData();
		}
		private: System::Void addBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			openAddBookModel();
		}
		private: void formClosed(System::Object ^sender, System::Windows::Forms::FormClosedEventArgs ^e){
			loadData();
		}
		private: System::Void addOrderBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			openAddOrderModel();
		}
		private: System::Void dataGrid_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			int bookId = safe_cast<int>(dataGrid->Rows[e->RowIndex]->Cells[0]->Value);
			BookDetailsPopup^ bookDetailsPopup = gcnew BookDetailsPopup(bookId);
			bookDetailsPopup->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &BooksPanel::formClosed);
			bookDetailsPopup->ShowDialog();
		}
		private: System::Void dataGrid2_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			int orderId = safe_cast<int>(dataGrid2->Rows[e->RowIndex]->Cells[0]->Value);
			EditOrderPopup^ editOrderPopup = gcnew EditOrderPopup();
			editOrderPopup->setData(orderId);
			editOrderPopup->saveBtn->Show();
			editOrderPopup->delBtn->Show();
			editOrderPopup->addBtn->Hide();
			editOrderPopup->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &BooksPanel::formClosed);
			editOrderPopup->ShowDialog();
		}
};
}
