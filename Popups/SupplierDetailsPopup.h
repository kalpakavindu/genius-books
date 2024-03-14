#pragma once

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
	public:
		SupplierDetailsPopup(void)
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
		~SupplierDetailsPopup()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ nameLabel;
	protected:

	private: System::Windows::Forms::Label^ addressLabel;
	protected:

	private: System::Windows::Forms::Label^ emailLabel;

	private: System::Windows::Forms::Label^ contactLabel;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ currentOrdersBtn;
	private: System::Windows::Forms::DataGridView^ ordersGrid;
	private: System::Windows::Forms::Button^ completedOrdersBtn;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;



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
			this->currentOrdersBtn = (gcnew System::Windows::Forms::Button());
			this->completedOrdersBtn = (gcnew System::Windows::Forms::Button());
			this->ordersGrid = (gcnew System::Windows::Forms::DataGridView());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
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
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::PaleTurquoise;
			this->panel2->Location = System::Drawing::Point(477, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(88, 100);
			this->panel2->TabIndex = 7;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::LightCyan;
			this->panel3->Location = System::Drawing::Point(581, 75);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(65, 66);
			this->panel3->TabIndex = 8;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::AliceBlue;
			this->panel4->Location = System::Drawing::Point(505, 121);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(60, 20);
			this->panel4->TabIndex = 9;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::AliceBlue;
			this->panel5->Location = System::Drawing::Point(581, 32);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(38, 34);
			this->panel5->TabIndex = 10;
			// 
			// SupplierDetailsPopup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Azure;
			this->ClientSize = System::Drawing::Size(658, 428);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
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
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(674, 467);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(674, 467);
			this->Name = L"SupplierDetailsPopup";
			this->Text = L"SupplierDetailsPopup";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
