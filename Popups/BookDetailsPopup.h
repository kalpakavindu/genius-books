#pragma once

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
	public:
		BookDetailsPopup(void)
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
		~BookDetailsPopup()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titleLabel;
	protected:

	private: System::Windows::Forms::Label^ authorLabel;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ isbnLabel;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ genreLabel;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ addedDateLabel;


	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::LinkLabel^ supplierLink;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ publisherLabel;
	private: System::Windows::Forms::Label^ priceLabel;



	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ inStockLabel;
	private: System::Windows::Forms::Label^ soldOutLabel;
	private: System::Windows::Forms::Label^ orderedLabel;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;




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
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->authorLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->isbnLabel = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->genreLabel = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->addedDateLabel = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->supplierLink = (gcnew System::Windows::Forms::LinkLabel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->publisherLabel = (gcnew System::Windows::Forms::Label());
			this->priceLabel = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->inStockLabel = (gcnew System::Windows::Forms::Label());
			this->soldOutLabel = (gcnew System::Windows::Forms::Label());
			this->orderedLabel = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
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
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(14, 136);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Genre";
			// 
			// genreLabel
			// 
			this->genreLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->genreLabel->Location = System::Drawing::Point(124, 136);
			this->genreLabel->Name = L"genreLabel";
			this->genreLabel->Size = System::Drawing::Size(228, 22);
			this->genreLabel->TabIndex = 5;
			this->genreLabel->Text = L"Adventure";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(15, 172);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(90, 20);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Date added";
			// 
			// addedDateLabel
			// 
			this->addedDateLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addedDateLabel->Location = System::Drawing::Point(124, 170);
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
			this->label9->Location = System::Drawing::Point(15, 209);
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
			this->supplierLink->Location = System::Drawing::Point(124, 209);
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
			this->label10->Location = System::Drawing::Point(15, 248);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(74, 20);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Publisher";
			// 
			// publisherLabel
			// 
			this->publisherLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->publisherLabel->Location = System::Drawing::Point(124, 246);
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
			this->priceLabel->Location = System::Drawing::Point(12, 348);
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
			this->label13->Location = System::Drawing::Point(457, 328);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(64, 20);
			this->label13->TabIndex = 13;
			this->label13->Text = L"In Stock";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(457, 358);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(70, 20);
			this->label14->TabIndex = 14;
			this->label14->Text = L"Sold Out";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Mulish", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(457, 390);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(65, 20);
			this->label15->TabIndex = 15;
			this->label15->Text = L"Ordered";
			// 
			// inStockLabel
			// 
			this->inStockLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inStockLabel->Location = System::Drawing::Point(534, 328);
			this->inStockLabel->Name = L"inStockLabel";
			this->inStockLabel->Size = System::Drawing::Size(156, 20);
			this->inStockLabel->TabIndex = 16;
			this->inStockLabel->Text = L"10045";
			// 
			// soldOutLabel
			// 
			this->soldOutLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->soldOutLabel->Location = System::Drawing::Point(534, 358);
			this->soldOutLabel->Name = L"soldOutLabel";
			this->soldOutLabel->Size = System::Drawing::Size(156, 20);
			this->soldOutLabel->TabIndex = 17;
			this->soldOutLabel->Text = L"10045";
			// 
			// orderedLabel
			// 
			this->orderedLabel->Font = (gcnew System::Drawing::Font(L"Mulish Medium", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->orderedLabel->Location = System::Drawing::Point(534, 390);
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
			// BookDetailsPopup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Azure;
			this->ClientSize = System::Drawing::Size(702, 465);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->orderedLabel);
			this->Controls->Add(this->soldOutLabel);
			this->Controls->Add(this->inStockLabel);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->priceLabel);
			this->Controls->Add(this->publisherLabel);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->supplierLink);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->addedDateLabel);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->genreLabel);
			this->Controls->Add(this->label5);
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
	};
}
