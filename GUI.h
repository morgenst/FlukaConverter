#pragma once

#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "MyForm.h"
#include "PredefinedConverters.h"
using namespace std;
namespace FlukaConverter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  ConvertButton;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  lblInput;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lblOutput;

	private: System::Windows::Forms::Button^  btnOpenOutFile;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  flukaConverterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;






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
			this->ConvertButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->lblInput = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblOutput = (gcnew System::Windows::Forms::Label());
			this->btnOpenOutFile = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->flukaConverterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ConvertButton
			// 
			this->ConvertButton->Location = System::Drawing::Point(340, 201);
			this->ConvertButton->Name = L"ConvertButton";
			this->ConvertButton->Size = System::Drawing::Size(75, 23);
			this->ConvertButton->TabIndex = 1;
			this->ConvertButton->Text = L"convert";
			this->ConvertButton->UseVisualStyleBackColor = true;
			this->ConvertButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->ShowHelp = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(340, 46);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Open";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// lblInput
			// 
			this->lblInput->AutoSize = true;
			this->lblInput->Location = System::Drawing::Point(133, 56);
			this->lblInput->Name = L"lblInput";
			this->lblInput->Size = System::Drawing::Size(0, 13);
			this->lblInput->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Inputfile";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(48, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Outputfile";
			// 
			// lblOutput
			// 
			this->lblOutput->AutoSize = true;
			this->lblOutput->Location = System::Drawing::Point(151, 110);
			this->lblOutput->Name = L"lblOutput";
			this->lblOutput->Size = System::Drawing::Size(0, 13);
			this->lblOutput->TabIndex = 6;
			// 
			// btnOpenOutFile
			// 
			this->btnOpenOutFile->Location = System::Drawing::Point(340, 110);
			this->btnOpenOutFile->Name = L"btnOpenOutFile";
			this->btnOpenOutFile->Size = System::Drawing::Size(75, 23);
			this->btnOpenOutFile->TabIndex = 7;
			this->btnOpenOutFile->Text = L"Open";
			this->btnOpenOutFile->UseVisualStyleBackColor = true;
			this->btnOpenOutFile->Click += gcnew System::EventHandler(this, &MyForm::btnOpenOutFile_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->flukaConverterToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(606, 24);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// flukaConverterToolStripMenuItem
			// 
			this->flukaConverterToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->closeToolStripMenuItem });
			this->flukaConverterToolStripMenuItem->Name = L"flukaConverterToolStripMenuItem";
			this->flukaConverterToolStripMenuItem->Size = System::Drawing::Size(99, 20);
			this->flukaConverterToolStripMenuItem->Text = L"FlukaConverter";
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::closeToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(606, 512);
			this->Controls->Add(this->btnOpenOutFile);
			this->Controls->Add(this->lblOutput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblInput);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->ConvertButton);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"FlukaConverter";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		System::String^ fInput;
		System::String^ fOutput;

#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 FConverter::ResnucTabExcelConverter converter(msclr::interop::marshal_as<std::string>(fInput->ToString()),
					 msclr::interop::marshal_as<std::string>(fOutput->ToString()));
				 converter.convert();
				 MyForm1^ formSuccess = gcnew MyForm1;
				 formSuccess->Show();
	}

	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
				 openFileDialog1->ShowHelp = true;
				 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					 fInput = openFileDialog1->FileName;
					 lblInput->Text = openFileDialog1->FileName;
				 }
	}

	private: System::Void btnOpenOutFile_Click(System::Object^  sender, System::EventArgs^  e) {
				 SaveFileDialog ^ saveFileDialog = gcnew SaveFileDialog();
				 saveFileDialog->AddExtension = "xml";
				 saveFileDialog->OverwritePrompt = true;
				 saveFileDialog->CheckFileExists = true;
				 saveFileDialog->CreatePrompt = true;
				 saveFileDialog->ShowHelp = true;
				 if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					 fOutput = saveFileDialog->FileName;
					 lblOutput->Text = saveFileDialog->FileName;
				 }
	}
	private: System::Void closeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 exit(0);
	}
};
}
