#pragma once

namespace WordCounterApp {

	using namespace System;

	public ref class WordCounterForm : public System::Windows::Forms::Form
	{
	public:
		WordCounterForm(void)
		{
			InitializeComponent();
		}

	protected:
		~WordCounterForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(218, 34);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(93, 16);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Enter your text:";
			   // 
			   // textBox1
			   // 
			   this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(64)));
			   this->textBox1->Location = System::Drawing::Point(221, 53);
			   this->textBox1->Multiline = true;
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(710, 155);
			   this->textBox1->TabIndex = 1;
			   // 
			   // button1
			   // 
			   this->button1->BackColor = System::Drawing::Color::PaleGreen;
			   this->button1->Location = System::Drawing::Point(367, 223);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(438, 43);
			   this->button1->TabIndex = 2;
			   this->button1->Text = L"Count Words";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &WordCounterForm::button1_Click);
			   // 
			   // textBox2
			   // 
			   this->textBox2->BackColor = System::Drawing::SystemColors::HotTrack;
			   this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox2->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			   this->textBox2->Location = System::Drawing::Point(472, 282);
			   this->textBox2->Multiline = true;
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(210, 56);
			   this->textBox2->TabIndex = 4;
			   this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   this->textBox2->TextChanged += gcnew System::EventHandler(this, &WordCounterForm::textBox2_TextChanged);
			   // 
			   // WordCounterForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Gray;
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(1239, 445);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->label1);
			   this->Name = L"WordCounterForm";
			   this->Text = L"Word Count";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	public: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ inputText = textBox1->Text;
		int wordCount = CountWords(inputText);
		textBox2->Text = "Word Count: " + wordCount;
	}

	private: int CountWords(String^ input) {
		array<Char>^ delimiters = { ' ', '\t', '\n' };
		int wordCount = 0;
		int length = input->Length;

		for (int i = 0; i < length; i++) {
			if (Array::IndexOf(delimiters, input[i]) != -1) {
				// A delimiter is found, check if it's a word separator.
				// Increment word count only if the previous character was not a delimiter.
				if (i > 0 && Array::IndexOf(delimiters, input[i - 1]) == -1) {
					wordCount++;
				}
			}
		}

		// Increment word count if the last character is not a delimiter.
		if (length > 0 && Array::IndexOf(delimiters, input[length - 1]) == -1) {
			wordCount++;
		}

		return wordCount;
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
