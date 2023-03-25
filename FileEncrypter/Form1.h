#pragma once

namespace FormsProject 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ openFileButton;
	private: System::Windows::Forms::TextBox^ textBoxPath;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
		/// <summary>
		/// Required designer variable.
		/// </summary>
	private: String^ filePath;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Button^ buttonEncrypt;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ buttonDecrypt;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxKeyEncrypt;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxKeyDecrypt;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileButton = (gcnew System::Windows::Forms::Button());
			this->textBoxPath = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->buttonEncrypt = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->buttonDecrypt = (gcnew System::Windows::Forms::Button());
			this->textBoxKeyDecrypt = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBoxKeyEncrypt = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileButton
			// 
			this->openFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->openFileButton->Location = System::Drawing::Point(12, 21);
			this->openFileButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->openFileButton->Name = L"openFileButton";
			this->openFileButton->Size = System::Drawing::Size(165, 26);
			this->openFileButton->TabIndex = 0;
			this->openFileButton->Text = L"Open File";
			this->openFileButton->UseVisualStyleBackColor = true;
			this->openFileButton->Click += gcnew System::EventHandler(this, &Form1::openFileButton_Click);
			// 
			// textBoxPath
			// 
			this->textBoxPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxPath->Location = System::Drawing::Point(183, 21);
			this->textBoxPath->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxPath->Name = L"textBoxPath";
			this->textBoxPath->Size = System::Drawing::Size(958, 30);
			this->textBoxPath->TabIndex = 1;
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog1";
			// 
			// buttonEncrypt
			// 
			this->buttonEncrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonEncrypt->Location = System::Drawing::Point(692, 61);
			this->buttonEncrypt->Margin = System::Windows::Forms::Padding(4);
			this->buttonEncrypt->Name = L"buttonEncrypt";
			this->buttonEncrypt->Size = System::Drawing::Size(190, 26);
			this->buttonEncrypt->TabIndex = 2;
			this->buttonEncrypt->Text = L"Encrypt";
			this->buttonEncrypt->UseVisualStyleBackColor = true;
			this->buttonEncrypt->Click += gcnew System::EventHandler(this, &Form1::buttonEncrypt_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(12, 61);
			this->listBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(664, 372);
			this->listBox1->TabIndex = 4;
			// 
			// buttonDecrypt
			// 
			this->buttonDecrypt->Enabled = false;
			this->buttonDecrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDecrypt->Location = System::Drawing::Point(3, 3);
			this->buttonDecrypt->Name = L"buttonDecrypt";
			this->buttonDecrypt->Size = System::Drawing::Size(190, 26);
			this->buttonDecrypt->TabIndex = 5;
			this->buttonDecrypt->Text = L"Decrypt";
			this->buttonDecrypt->UseVisualStyleBackColor = true;
			this->buttonDecrypt->Click += gcnew System::EventHandler(this, &Form1::buttonDecrypt_Click);
			// 
			// textBoxKeyDecrypt
			// 
			this->textBoxKeyDecrypt->Enabled = false;
			this->textBoxKeyDecrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxKeyDecrypt->ForeColor = System::Drawing::Color::Gray;
			this->textBoxKeyDecrypt->Location = System::Drawing::Point(229, 3);
			this->textBoxKeyDecrypt->Name = L"textBoxKeyDecrypt";
			this->textBoxKeyDecrypt->Size = System::Drawing::Size(220, 30);
			this->textBoxKeyDecrypt->TabIndex = 6;
			this->textBoxKeyDecrypt->Text = L"Enter Key";
			this->textBoxKeyDecrypt->Enter += gcnew System::EventHandler(this, &Form1::textBoxKeyDecrypt_Enter);
			this->textBoxKeyDecrypt->Leave += gcnew System::EventHandler(this, &Form1::textBoxKeyDecrypt_Leave);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(3, 3);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(161, 24);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"Enable Decryptor";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->tableLayoutPanel1);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Location = System::Drawing::Point(683, 94);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(470, 184);
			this->panel1->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Orange;
			this->label2->Location = System::Drawing::Point(2, 123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(554, 25);
			this->label2->TabIndex = 11;
			this->label2->Text = L"If you enter the wrong key, your data will be lost forever !";
			this->label2->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Orange;
			this->label1->Location = System::Drawing::Point(52, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 25);
			this->label1->TabIndex = 10;
			this->label1->Text = L"! WARNING !";
			this->label1->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(6, 73);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(40, 35);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->buttonDecrypt, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBoxKeyDecrypt, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(6, 30);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(452, 37);
			this->tableLayoutPanel1->TabIndex = 9;
			// 
			// textBoxKeyEncrypt
			// 
			this->textBoxKeyEncrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxKeyEncrypt->ForeColor = System::Drawing::Color::Gray;
			this->textBoxKeyEncrypt->Location = System::Drawing::Point(915, 61);
			this->textBoxKeyEncrypt->Name = L"textBoxKeyEncrypt";
			this->textBoxKeyEncrypt->Size = System::Drawing::Size(226, 30);
			this->textBoxKeyEncrypt->TabIndex = 9;
			this->textBoxKeyEncrypt->Text = L"Enter Key";
			this->textBoxKeyEncrypt->Enter += gcnew System::EventHandler(this, &Form1::textBoxKeyEncrypt_Enter);
			this->textBoxKeyEncrypt->Leave += gcnew System::EventHandler(this, &Form1::textBoxKeyEncrypt_Leave);
			// 
			// Form1
			// 
			this->ClientSize = System::Drawing::Size(1165, 455);
			this->Controls->Add(this->textBoxKeyEncrypt);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->buttonEncrypt);
			this->Controls->Add(this->textBoxPath);
			this->Controls->Add(this->openFileButton);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openFileButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonEncrypt_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonDecrypt_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxKeyEncrypt_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxKeyEncrypt_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxKeyDecrypt_Enter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxKeyDecrypt_Leave(System::Object^ sender, System::EventArgs^ e);
	};
}
