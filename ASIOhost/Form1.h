#pragma once

#include <stdio.h>
#include <string.h>

#include "host.h"
#include "decode.h"
#include "encode.h"
#include "asiolist.h"


namespace ASIOmarker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;


	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			getASIODeviceItems(driverList);
		}



	protected:

		~Form1()
		{
			

			if (components)
			{
				delete components;
			}

		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  bStart;

	private: System::Windows::Forms::Button^  bASIOOptions;
	private: System::Windows::Forms::GroupBox^  groupBox1;



	private: System::Windows::Forms::ComboBox^  driverList;

	protected:

		void getASIODeviceItems(System::Windows::Forms::ComboBox^ comboBox);
		void initASIO(char *name);

	private:

		System::ComponentModel::Container ^components;


#pragma region properties

	private:
		boolean _processing;

	public:
		property boolean Processing
		{
			boolean get()
			{

				return _processing;
			}
			void set(boolean value)
			{
				if (_processing != value) {
					if (value)
						_processing = ASIOHostRun(true);
					else
					{
						ASIOHostRun(false);
						_processing = false;
					}

					if (_processing)
						bStart->Text = "Stop";
					else
						bStart->Text = "Start";

				}

			}
		}
#pragma endregion		

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bStart = (gcnew System::Windows::Forms::Button());
			this->driverList = (gcnew System::Windows::Forms::ComboBox());
			this->bASIOOptions = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(78, 149);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// bStart
			// 
			this->bStart->Location = System::Drawing::Point(507, 29);
			this->bStart->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->bStart->Name = L"bStart";
			this->bStart->Size = System::Drawing::Size(118, 35);
			this->bStart->TabIndex = 1;
			this->bStart->Text = L"Start";
			this->bStart->UseVisualStyleBackColor = true;
			this->bStart->Click += gcnew System::EventHandler(this, &Form1::bStart_Click);
			// 
			// driverList
			// 
			this->driverList->FormattingEnabled = true;
			this->driverList->Location = System::Drawing::Point(9, 29);
			this->driverList->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->driverList->Name = L"driverList";
			this->driverList->Size = System::Drawing::Size(366, 28);
			this->driverList->TabIndex = 2;
			this->driverList->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::driverList_SelectedIndexChanged);
			// 
			// bASIOOptions
			// 
			this->bASIOOptions->Location = System::Drawing::Point(386, 29);
			this->bASIOOptions->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->bASIOOptions->Name = L"bASIOOptions";
			this->bASIOOptions->Size = System::Drawing::Size(112, 35);
			this->bASIOOptions->TabIndex = 3;
			this->bASIOOptions->Text = L"Options...";
			this->bASIOOptions->UseVisualStyleBackColor = true;
			this->bASIOOptions->Click += gcnew System::EventHandler(this, &Form1::bASIOOptions_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->bASIOOptions);
			this->groupBox1->Controls->Add(this->bStart);
			this->groupBox1->Controls->Add(this->driverList);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(18, 18);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Size = System::Drawing::Size(646, 85);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ASIO Device";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(698, 395);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"DAVID marker";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

#pragma region Events


	private: System::Void bASIOOptions_Click(System::Object^  sender, System::EventArgs^  e) {

		ASIOControlPanel();
	}
	private: System::Void driverList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {


		char* pChars = (char*)Marshal::StringToHGlobalAnsi(driverList->SelectedItem->ToString()).ToPointer();
		initASIO(pChars);

	}
	private: System::Void bStart_Click(System::Object^  sender, System::EventArgs^  e) {

		Processing = !Processing;

	}


	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

		Processing = false;
	}

#pragma endregion
	};
};
