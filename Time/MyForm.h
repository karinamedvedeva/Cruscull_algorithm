#pragma once

#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <string>

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Graphics^ gr;
		Pen^ pen, ^ penCruscullArray, ^ penCruscullTree;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	public:
		MyForm(void)
		{
			InitializeComponent();
			this->gr = CreateGraphics();
			this->pen = gcnew Pen(Color::Silver);
			this->penCruscullArray = gcnew Pen(Color::DarkOrange);
			this->penCruscullTree = gcnew Pen(Color::LightSeaGreen);
			this->penCruscullArray->Width = 5.0;
			this->penCruscullTree->Width = 5.0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
			}
		}


	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Papyrus", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::Color::DarkSlateGray;
			   this->label1->Location = System::Drawing::Point(1008, 484);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(59, 31);
			   this->label1->TabIndex = 2;
			   this->label1->Text = L"Ribs";
			   this->label1->Visible = false;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Papyrus", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->ForeColor = System::Drawing::Color::DarkSlateGray;
			   this->label2->Location = System::Drawing::Point(80, 62);
			   this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(54, 31);
			   this->label2->TabIndex = 3;
			   this->label2->Text = L"t, 1c";
			   this->label2->Visible = false;
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Papyrus", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->ForeColor = System::Drawing::Color::DarkSlateGray;
			   this->label3->Location = System::Drawing::Point(285, 635);
			   this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(146, 31);
			   this->label3->TabIndex = 5;
			   this->label3->Text = L"CruscullAray";
			   this->label3->Visible = false;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Papyrus", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->ForeColor = System::Drawing::Color::DarkSlateGray;
			   this->label4->Location = System::Drawing::Point(680, 635);
			   this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(145, 31);
			   this->label4->TabIndex = 7;
			   this->label4->Text = L"CruscullTree";
			   this->label4->Visible = false;
			   // 
			   // button1
			   // 
			   this->button1->BackColor = System::Drawing::Color::DarkKhaki;
			   this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->button1->Font = (gcnew System::Drawing::Font(L"Ink Free", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button1->ForeColor = System::Drawing::Color::DarkSlateGray;
			   this->button1->Location = System::Drawing::Point(505, 350);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(198, 74);
			   this->button1->TabIndex = 8;
			   this->button1->Text = L"Vertexes";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			   // 
			   // button2
			   // 
			   this->button2->BackColor = System::Drawing::Color::DarkKhaki;
			   this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->button2->Font = (gcnew System::Drawing::Font(L"Ink Free", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button2->ForeColor = System::Drawing::Color::DarkSlateGray;
			   this->button2->Location = System::Drawing::Point(505, 446);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(198, 69);
			   this->button2->TabIndex = 9;
			   this->button2->Text = L"Ribs";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Papyrus", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->ForeColor = System::Drawing::Color::DarkSlateGray;
			   this->label5->Location = System::Drawing::Point(1008, 484);
			   this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(99, 31);
			   this->label5->TabIndex = 10;
			   this->label5->Text = L"Vertexes";
			   this->label5->Visible = false;
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::AliceBlue;
			   this->ClientSize = System::Drawing::Size(1179, 814);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->label5);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"MyForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Cruscull Charts";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	button1->Visible = false;
	button2->Visible = false;
	label2->Visible = true;
	label3->Visible = true;
	label4->Visible = true;
	label5->Visible = true;

	//size of graph
	std::ifstream CruscullArrayData("../CruscullArrayVertexes.txt");
	std::ifstream CruscullTreeData ("../CruscullTreeVertexes.txt");
	const int max_length = 100;
	char CruscullArrayBuffer[max_length];
	char CruscullTreeBuffer[max_length];

	CruscullArrayData.getline(CruscullArrayBuffer, max_length, '\n');
	CruscullTreeData.getline(CruscullTreeBuffer, max_length, '\n');

	std::string curr_line;
	int elem = 0, min_vertexes = 0, max_vertexes = 0, step = 1;
	for (int i = 0; CruscullArrayBuffer[i] != '\0'; i++) {
		if (CruscullArrayBuffer[i] == ' ') {
			int count = atoi(curr_line.c_str());
			if (elem == 0) {
				max_vertexes = count;
			}
			else {
				if (elem == 1) {
					min_vertexes = count;
				}
			}
			curr_line.clear();
			elem++;
		} else {
			curr_line += CruscullArrayBuffer[i];
		}
	}
	step = atoi(curr_line.c_str());
	int vertexes = (max_vertexes - min_vertexes) / step;

	//coordinate system 
	gr->DrawLine(pen, 50, 400, 750, 400);
	gr->DrawLine(pen, 50, 400, 50, 50);
	gr->DrawLine(pen, 50, 50, 55, 55);
	gr->DrawLine(pen, 50, 50, 45, 55);
	gr->DrawLine(pen, 750, 400, 745, 395);
	gr->DrawLine(pen, 750, 400, 745, 405);

	int stepX = 700 / vertexes, stepY = 10;

	for (int i = 57; i < 745; i += stepX) {
		gr->DrawLine(pen, i, 398, i, 402);
	}

	for (int i = 390; i > 55; i -= stepY) {
		gr->DrawLine(pen, 48, i, 52, i);
	}

	this->pen->Width = 4.0;
	gr->DrawEllipse(pen, 48, 398, 4, 4);

	gr->DrawLine(penCruscullArray, 300, 530, 380, 530);
	gr->DrawLine(penCruscullTree, 645, 530, 705, 530);


	//chart
	int CruscullArrayLastX = 50, CruscullArrayLastY = 400;
	int	CruscullTreeLastX = 50, CruscullTreeLastY = 400;
	int	startPointY = 400;
	double CruscullArrayWorkingTime, CruscullTreeWorkingTime;
	int i = min_vertexes;

	while (!CruscullArrayData.eof() && !CruscullTreeData.eof()) {
		CruscullArrayData.getline(CruscullArrayBuffer, max_length, '\n');
		CruscullTreeData.getline(CruscullTreeBuffer, max_length, '\n');

		CruscullArrayWorkingTime = atof(CruscullArrayBuffer);
		CruscullTreeWorkingTime = atof(CruscullTreeBuffer);

		gr->DrawLine(penCruscullArray, CruscullArrayLastX, 
			CruscullArrayLastY, CruscullArrayLastX + stepX, startPointY - CruscullArrayWorkingTime * 10.);
		gr->DrawLine(penCruscullTree, CruscullTreeLastX, 
			CruscullTreeLastY, CruscullTreeLastX + stepX, startPointY - CruscullTreeWorkingTime * 10.);
		
		CruscullArrayLastX += stepX;
		CruscullTreeLastX += stepX;
		CruscullArrayLastY = startPointY - CruscullArrayWorkingTime * 10.;
		CruscullTreeLastY = startPointY - CruscullTreeWorkingTime * 10.;

		i += step;
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	button1->Visible = false;
	button2->Visible = false;
	label1->Visible = true;
	label2->Visible = true;
	label3->Visible = true;
	label4->Visible = true;

	//size of graph
	std::ifstream CruscullArrayData("../CruscullArayRibs.txt");
	std::ifstream CruscullTreeData("../CruscullTreeRibs.txt");
	const int max_length = 100;
	char CruscullArrayBuffer[max_length], CruscullTreeBuffer[max_length];

	CruscullArrayData.getline(CruscullArrayBuffer, max_length, '\n');
	CruscullTreeData.getline(CruscullTreeBuffer, max_length, '\n');

	std::string curr_line;
	int elem = 0, min_ribs = 0, max_ribs = 0, step = 1;
	for (int i = 0; CruscullArrayBuffer[i] != '\0'; i++) {
		if (CruscullArrayBuffer[i] == ' ') {
			int count = atoi(curr_line.c_str());
			if (elem == 1) {
				max_ribs = count;
			}
			else {
				if (elem == 2) {
					min_ribs = count;
				}
			}
			curr_line.clear();
			elem++;
		}
		else {
			curr_line += CruscullArrayBuffer[i];
		}
	}
	step = atoi(curr_line.c_str());

	int ribs = (max_ribs - min_ribs) / step;

	//coordinate system
	gr->DrawLine(pen, 50, 400, 750, 400);
	gr->DrawLine(pen, 50, 400, 50, 50);
	gr->DrawLine(pen, 50, 50, 55, 55);
	gr->DrawLine(pen, 50, 50, 45, 55);
	gr->DrawLine(pen, 750, 400, 745, 395);
	gr->DrawLine(pen, 750, 400, 745, 405);

	int stepX = 700 / ribs, stepY = 10;
	for (int i = 57; i < 745; i += stepX) {
		gr->DrawLine(pen, i, 398, i, 402);
	}

	for (int i = 390; i > 55; i -= stepY) {
		gr->DrawLine(pen, 48, i, 52, i);
	}

	this->pen->Width = 4.0;
	gr->DrawEllipse(pen, 48, 398, 4, 4);

	gr->DrawLine(penCruscullArray, 300, 530, 380, 530);
	gr->DrawLine(penCruscullTree, 645, 530, 705, 530);

	//chart
	int CruscullArrayLastX = 50, CruscullArrayLastY = 400;
	int	CruscullTreeLastX = 50, CruscullTreeLastY = 400;
	int	startPointY = 400;
	double CruscullArrayWorkingTime, CruscullTreeWorkingTime;
	int i = min_ribs;

	while (!CruscullArrayData.eof() && !CruscullTreeData.eof()) {
		CruscullArrayData.getline(CruscullArrayBuffer, max_length, '\n');
		CruscullTreeData.getline(CruscullTreeBuffer, max_length, '\n');

		CruscullArrayWorkingTime = atof(CruscullArrayBuffer);
		CruscullTreeWorkingTime = atof(CruscullTreeBuffer);

		gr->DrawLine(penCruscullArray, CruscullArrayLastX, CruscullArrayLastY, 
			CruscullArrayLastX + stepX, startPointY - CruscullArrayWorkingTime * 10.);
		gr->DrawLine(penCruscullTree, CruscullTreeLastX, CruscullTreeLastY, 
			CruscullTreeLastX + stepX, startPointY - CruscullTreeWorkingTime * 10.);

		CruscullArrayLastX += stepX;
		CruscullTreeLastX += stepX;
		CruscullArrayLastY = startPointY - CruscullArrayWorkingTime * 10.;
		CruscullTreeLastY = startPointY - CruscullTreeWorkingTime * 10.;

		i += step;
	}
}
};
}
