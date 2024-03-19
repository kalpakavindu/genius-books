#pragma once
#include "../Database.h"
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
	/// Summary for DashboardPanel
	/// </summary>
	public ref class DashboardPanel : public System::Windows::Forms::Form
	{
	private:
		Database^ conn;

		void loadData() {
			try {
				String^ query = "SELECT * FROM OrdersTable WHERE status=0 ORDER BY created_at DESC";
				DataTable^ latestOrders = conn->GetData(query);
				ordersGrid->DataSource = latestOrders;

				query = "SELECT * FROM BooksTable ORDER BY created_at DESC";
				DataTable^ latestBooks = conn->GetData(query);
				titlesGrid->DataSource = latestBooks;
			}
			catch (Exception^ e) {
				if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
					Application::Exit();
				}
			}
		}

	public:
		DashboardPanel(void)
		{
			InitializeComponent();
			conn = gcnew Database();
			loadData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DashboardPanel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::DataGridView^ ordersGrid;
	private: System::Windows::Forms::DataGridView^ titlesGrid;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->ordersGrid = (gcnew System::Windows::Forms::DataGridView());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->titlesGrid = (gcnew System::Windows::Forms::DataGridView());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersGrid))->BeginInit();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->titlesGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(798, 66);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Mulish Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Dashboard";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Aquamarine;
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(17, 72);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 156);
			this->panel2->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Mulish", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(79, 97);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(111, 28);
			this->label6->TabIndex = 4;
			this->label6->Text = L"50";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Mulish", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(79, 60);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(111, 28);
			this->label5->TabIndex = 3;
			this->label5->Text = L"50";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 105);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 18);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Genres";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 18);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Titles";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 33);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Books";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Aquamarine;
			this->panel3->Controls->Add(this->label7);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label10);
			this->panel3->Controls->Add(this->label11);
			this->panel3->Location = System::Drawing::Point(237, 72);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(200, 156);
			this->panel3->TabIndex = 5;
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Mulish", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(79, 97);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(111, 28);
			this->label7->TabIndex = 4;
			this->label7->Text = L"50";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Mulish", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(79, 60);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(111, 28);
			this->label8->TabIndex = 3;
			this->label8->Text = L"50";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(15, 105);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 18);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Orders";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(15, 68);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(38, 18);
			this->label10->TabIndex = 1;
			this->label10->Text = L"Total";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(12, 11);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(129, 33);
			this->label11->TabIndex = 0;
			this->label11->Text = L"Suppliers";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Aquamarine;
			this->panel4->Controls->Add(this->label12);
			this->panel4->Controls->Add(this->label13);
			this->panel4->Controls->Add(this->label14);
			this->panel4->Controls->Add(this->label15);
			this->panel4->Controls->Add(this->label16);
			this->panel4->Location = System::Drawing::Point(456, 72);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(200, 156);
			this->panel4->TabIndex = 6;
			// 
			// label12
			// 
			this->label12->Font = (gcnew System::Drawing::Font(L"Mulish", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(79, 97);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(111, 28);
			this->label12->TabIndex = 4;
			this->label12->Text = L"50";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label13
			// 
			this->label13->Font = (gcnew System::Drawing::Font(L"Mulish", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(79, 60);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(111, 28);
			this->label13->TabIndex = 3;
			this->label13->Text = L"50";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(15, 105);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(58, 18);
			this->label14->TabIndex = 2;
			this->label14->Text = L"Pending";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(15, 68);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(38, 18);
			this->label15->TabIndex = 1;
			this->label15->Text = L"Total";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(12, 11);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(84, 33);
			this->label16->TabIndex = 0;
			this->label16->Text = L"Users";
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->Controls->Add(this->ordersGrid);
			this->panel5->Location = System::Drawing::Point(12, 269);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(415, 280);
			this->panel5->TabIndex = 7;
			// 
			// ordersGrid
			// 
			this->ordersGrid->AllowUserToAddRows = false;
			this->ordersGrid->AllowUserToDeleteRows = false;
			this->ordersGrid->AllowUserToOrderColumns = true;
			this->ordersGrid->BackgroundColor = System::Drawing::Color::LightCyan;
			this->ordersGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ordersGrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ordersGrid->Location = System::Drawing::Point(0, 0);
			this->ordersGrid->Name = L"ordersGrid";
			this->ordersGrid->ReadOnly = true;
			this->ordersGrid->Size = System::Drawing::Size(415, 280);
			this->ordersGrid->TabIndex = 0;
			this->ordersGrid->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DashboardPanel::ordersGrid_CellDoubleClick);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Mulish ExtraBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(13, 244);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(122, 22);
			this->label17->TabIndex = 8;
			this->label17->Text = L"Recent Orders";
			// 
			// panel6
			// 
			this->panel6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel6->Controls->Add(this->titlesGrid);
			this->panel6->Location = System::Drawing::Point(442, 269);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(344, 280);
			this->panel6->TabIndex = 8;
			// 
			// titlesGrid
			// 
			this->titlesGrid->AllowUserToAddRows = false;
			this->titlesGrid->AllowUserToDeleteRows = false;
			this->titlesGrid->AllowUserToOrderColumns = true;
			this->titlesGrid->BackgroundColor = System::Drawing::Color::LightCyan;
			this->titlesGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->titlesGrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->titlesGrid->Location = System::Drawing::Point(0, 0);
			this->titlesGrid->Name = L"titlesGrid";
			this->titlesGrid->ReadOnly = true;
			this->titlesGrid->Size = System::Drawing::Size(344, 280);
			this->titlesGrid->TabIndex = 0;
			this->titlesGrid->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DashboardPanel::titlesGrid_CellDoubleClick);
			// 
			// label18
			// 
			this->label18->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Mulish ExtraBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(438, 244);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(109, 22);
			this->label18->TabIndex = 9;
			this->label18->Text = L"Recent Titles";
			// 
			// DashboardPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::LightCyan;
			this->ClientSize = System::Drawing::Size(798, 561);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(798, 561);
			this->Name = L"DashboardPanel";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"DashboardPanel";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersGrid))->EndInit();
			this->panel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->titlesGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ordersGrid_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int orderId = safe_cast<int>(ordersGrid->Rows[e->RowIndex]->Cells[0]->Value);
		EditOrderPopup^ editOrderPopup = gcnew EditOrderPopup();
		editOrderPopup->setData(orderId);
		editOrderPopup->addBtn->Hide();
		editOrderPopup->saveBtn->Show();
		editOrderPopup->delBtn->Show();
		editOrderPopup->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &DashboardPanel::formClosed);
		editOrderPopup->ShowDialog();
	}

	private: System::Void formClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		loadData();
	}
	
	private: System::Void titlesGrid_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int bookId = safe_cast<int>(titlesGrid->Rows[e->RowIndex]->Cells[0]->Value);
		BookDetailsPopup^ bookDataPopup = gcnew BookDetailsPopup(bookId);
		bookDataPopup->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &DashboardPanel::formClosed);
		bookDataPopup->ShowDialog();
	}
};
}
