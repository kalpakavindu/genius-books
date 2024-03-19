#pragma once

#include "../Database.h"
#include "../Popups/EditSupplierPopup.h"
#include "../Popups/EditOrderPopup.h"

namespace GeniusBooks {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SupplierDetailsPopup
	/// </summary>
	public ref class SupplierDetailsPopup : public System::Windows::Forms::Form
	{
	private: EditSupplierPopup^ editSupplierPopup;
	private: EditOrderPopup^ editOrderPopup;
	private: Database^ conn;
	private: int supplierId;
	private: int currentTab = 0;

	private: void loadData() {
		try {
			String^ query = "SELECT * FROM SuppliersTable WHERE id=" + supplierId;
			DataRow^ supplierData = conn->GetData(query)->Rows[0];

			nameLabel->Text = safe_cast<String^>(supplierData["name"]);
			addressLabel->Text = safe_cast<String^>(supplierData["address"]);
			emailLabel->Text = safe_cast<String^>(supplierData["email"]);
			contactLabel->Text = safe_cast<String^>(supplierData["contact"]);

			if (currentTab == 0) {
				query = "SELECT * FROM OrdersTable WHERE supplier=" + supplierId + " AND status=0";
				DataTable^ currentOrders = conn->GetData(query);
				ordersGrid->DataSource = currentOrders;
			}
			else {
				query = "SELECT * FROM OrdersTable WHERE supplier=" + supplierId + " AND status=1";
				DataTable^ pastOrders = conn->GetData(query);
				ordersGrid->DataSource = pastOrders;
			}
		}
		catch (Exception^ e) {
			if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
				Application::Exit();
			}
		}
	}

	private: void openEditSupplierPopup() {
		editSupplierPopup = gcnew EditSupplierPopup();
		editSupplierPopup->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SupplierDetailsPopup::close);
		editSupplierPopup->setData(supplierId);
		editSupplierPopup->saveBtn->Show();
		editSupplierPopup->addBtn->Hide();
		editSupplierPopup->ShowDialog();
	}
	
	private: void openAddOrderPopup() {
		editOrderPopup = gcnew EditOrderPopup();
		editOrderPopup->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SupplierDetailsPopup::close);
		editOrderPopup->saveBtn->Hide();
		editOrderPopup->addBtn->Show();
		editOrderPopup->delBtn->Hide();
		editOrderPopup->Text = "Place New Order";
		editOrderPopup->setSupplier(supplierId);
		editOrderPopup->ShowDialog();
	}
	
	private: void openOrderDetailsPopup(int id) {
		editOrderPopup = gcnew EditOrderPopup();
		editOrderPopup->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SupplierDetailsPopup::close);
		editOrderPopup->setData(id);
		editOrderPopup->addBtn->Hide();
		editOrderPopup->delBtn->Show();
		editOrderPopup->saveBtn->Show();
		editOrderPopup->ShowDialog();
	}

	public:
		SupplierDetailsPopup(int id)
		{
			InitializeComponent();
			conn = gcnew Database();
			supplierId = id;
			currentTab = 0;
			loadData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SupplierDetailsPopup()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ nameLabel;
	private: System::Windows::Forms::Label^ addressLabel;
	private: System::Windows::Forms::Label^ emailLabel;
	private: System::Windows::Forms::Label^ contactLabel;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ currentOrdersBtn;
	private: System::Windows::Forms::DataGridView^ ordersGrid;
	private: System::Windows::Forms::Button^ completedOrdersBtn;
	private: System::Windows::Forms::Button^ placeOrderBtn;
	private: System::Windows::Forms::Button^ deleteBtn;
	private: System::Windows::Forms::Button^ editBtn;

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
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->addressLabel = (gcnew System::Windows::Forms::Label());
			this->emailLabel = (gcnew System::Windows::Forms::Label());
			this->contactLabel = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ordersGrid = (gcnew System::Windows::Forms::DataGridView());
			this->currentOrdersBtn = (gcnew System::Windows::Forms::Button());
			this->completedOrdersBtn = (gcnew System::Windows::Forms::Button());
			this->placeOrderBtn = (gcnew System::Windows::Forms::Button());
			this->deleteBtn = (gcnew System::Windows::Forms::Button());
			this->editBtn = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// nameLabel
			// 
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Mulish ExtraBold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameLabel->Location = System::Drawing::Point(12, 9);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(450, 33);
			this->nameLabel->TabIndex = 0;
			this->nameLabel->Text = L"Saliya Distributers";
			// 
			// addressLabel
			// 
			this->addressLabel->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addressLabel->Location = System::Drawing::Point(14, 54);
			this->addressLabel->Name = L"addressLabel";
			this->addressLabel->Size = System::Drawing::Size(448, 24);
			this->addressLabel->TabIndex = 1;
			this->addressLabel->Text = L"123/A, Malwaththa Road, Town Hall, Colombo 10.";
			// 
			// emailLabel
			// 
			this->emailLabel->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->emailLabel->Location = System::Drawing::Point(14, 88);
			this->emailLabel->Name = L"emailLabel";
			this->emailLabel->Size = System::Drawing::Size(448, 20);
			this->emailLabel->TabIndex = 2;
			this->emailLabel->Text = L"contact@saliyadistributers.com";
			// 
			// contactLabel
			// 
			this->contactLabel->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->contactLabel->Location = System::Drawing::Point(14, 121);
			this->contactLabel->Name = L"contactLabel";
			this->contactLabel->Size = System::Drawing::Size(448, 20);
			this->contactLabel->TabIndex = 3;
			this->contactLabel->Text = L"+94725674589";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightCyan;
			this->panel1->Controls->Add(this->ordersGrid);
			this->panel1->Location = System::Drawing::Point(18, 182);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(628, 234);
			this->panel1->TabIndex = 4;
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
			this->ordersGrid->Size = System::Drawing::Size(628, 234);
			this->ordersGrid->TabIndex = 0;
			this->ordersGrid->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SupplierDetailsPopup::ordersGrid_CellDoubleClick);
			// 
			// currentOrdersBtn
			// 
			this->currentOrdersBtn->BackColor = System::Drawing::Color::LightCyan;
			this->currentOrdersBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->currentOrdersBtn->FlatAppearance->BorderSize = 0;
			this->currentOrdersBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->currentOrdersBtn->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->currentOrdersBtn->Location = System::Drawing::Point(18, 153);
			this->currentOrdersBtn->Name = L"currentOrdersBtn";
			this->currentOrdersBtn->Size = System::Drawing::Size(138, 28);
			this->currentOrdersBtn->TabIndex = 5;
			this->currentOrdersBtn->Text = L"Current orders";
			this->currentOrdersBtn->UseVisualStyleBackColor = false;
			this->currentOrdersBtn->Click += gcnew System::EventHandler(this, &SupplierDetailsPopup::currentOrdersBtn_Click);
			// 
			// completedOrdersBtn
			// 
			this->completedOrdersBtn->BackColor = System::Drawing::Color::AliceBlue;
			this->completedOrdersBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->completedOrdersBtn->FlatAppearance->BorderSize = 0;
			this->completedOrdersBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->completedOrdersBtn->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->completedOrdersBtn->Location = System::Drawing::Point(156, 153);
			this->completedOrdersBtn->Name = L"completedOrdersBtn";
			this->completedOrdersBtn->Size = System::Drawing::Size(138, 28);
			this->completedOrdersBtn->TabIndex = 6;
			this->completedOrdersBtn->Text = L"Completed orders";
			this->completedOrdersBtn->UseVisualStyleBackColor = false;
			this->completedOrdersBtn->Click += gcnew System::EventHandler(this, &SupplierDetailsPopup::completedOrdersBtn_Click);
			// 
			// placeOrderBtn
			// 
			this->placeOrderBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->placeOrderBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->placeOrderBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->placeOrderBtn->ForeColor = System::Drawing::Color::Azure;
			this->placeOrderBtn->Location = System::Drawing::Point(545, 143);
			this->placeOrderBtn->Name = L"placeOrderBtn";
			this->placeOrderBtn->Size = System::Drawing::Size(101, 34);
			this->placeOrderBtn->TabIndex = 11;
			this->placeOrderBtn->Text = L"Place Order";
			this->placeOrderBtn->UseVisualStyleBackColor = false;
			this->placeOrderBtn->Click += gcnew System::EventHandler(this, &SupplierDetailsPopup::placeOrderBtn_Click);
			// 
			// deleteBtn
			// 
			this->deleteBtn->BackColor = System::Drawing::Color::Salmon;
			this->deleteBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteBtn->ForeColor = System::Drawing::Color::Azure;
			this->deleteBtn->Location = System::Drawing::Point(535, 54);
			this->deleteBtn->Name = L"deleteBtn";
			this->deleteBtn->Size = System::Drawing::Size(111, 34);
			this->deleteBtn->TabIndex = 12;
			this->deleteBtn->Text = L"Delete Supplier";
			this->deleteBtn->UseVisualStyleBackColor = false;
			this->deleteBtn->Click += gcnew System::EventHandler(this, &SupplierDetailsPopup::deleteBtn_Click);
			// 
			// editBtn
			// 
			this->editBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->editBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editBtn->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editBtn->ForeColor = System::Drawing::Color::Azure;
			this->editBtn->Location = System::Drawing::Point(535, 13);
			this->editBtn->Name = L"editBtn";
			this->editBtn->Size = System::Drawing::Size(111, 34);
			this->editBtn->TabIndex = 13;
			this->editBtn->Text = L"Edit Supplier";
			this->editBtn->UseVisualStyleBackColor = false;
			this->editBtn->Click += gcnew System::EventHandler(this, &SupplierDetailsPopup::editBtn_Click);
			// 
			// SupplierDetailsPopup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Azure;
			this->ClientSize = System::Drawing::Size(658, 428);
			this->Controls->Add(this->editBtn);
			this->Controls->Add(this->deleteBtn);
			this->Controls->Add(this->placeOrderBtn);
			this->Controls->Add(this->completedOrdersBtn);
			this->Controls->Add(this->currentOrdersBtn);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->contactLabel);
			this->Controls->Add(this->emailLabel);
			this->Controls->Add(this->addressLabel);
			this->Controls->Add(this->nameLabel);
			this->Font = (gcnew System::Drawing::Font(L"Mulish", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(674, 467);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(674, 467);
			this->Name = L"SupplierDetailsPopup";
			this->ShowInTaskbar = false;
			this->Text = L"SupplierDetailsPopup";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void editBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		openEditSupplierPopup();
	}

	private: System::Void placeOrderBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		openAddOrderPopup();
	}

	private: System::Void completedOrdersBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		completedOrdersBtn->BackColor = System::Drawing::Color::LightCyan;
		currentOrdersBtn->BackColor = System::Drawing::Color::AliceBlue;
		currentTab = 1;
		loadData();
	}

	private: System::Void currentOrdersBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		completedOrdersBtn->BackColor = System::Drawing::Color::AliceBlue;
		currentOrdersBtn->BackColor = System::Drawing::Color::LightCyan;
		currentTab = 0;
		loadData();
	}

	private: System::Void ordersGrid_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int orderId = safe_cast<int>(ordersGrid->Rows[e->RowIndex]->Cells[0]->Value);
		openOrderDetailsPopup(orderId);
	}

	private: System::Void deleteBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ query = "DELETE FROM OrdersTable WHERE supplier=" + supplierId;
			conn->SetData(query);

			query = "DELETE FROM SuppliersTable WHERE id=" + supplierId;
			conn->SetData(query);
			this->Close();
		}
		catch (Exception^ e) {
			if (MessageBox::Show(e->Message, "Unexpected Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK) {
				Application::Exit();
			}
		}
	}

	private: System::Void close(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		loadData();
	}
};
}
