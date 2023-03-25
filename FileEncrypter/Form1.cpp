#include "pch.h"
#include "Form1.h"
#include "AditionalFunctions.h"
#include <fstream>
#include <vector>
#include <msclr/marshal_cppstd.h>
#include <algorithm>
#include <sstream>

using namespace System::IO;
using namespace System;
using namespace msclr::interop;

inline System::Void FormsProject::Form1::openFileButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Set the filter for the open file dialog to accept any file type.
	openFileDialog->Filter = "Any Files|*.*";

	// Show the open file dialog and wait for the user to select a file.
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		// If the user selects a file, then store the file path in the 'filePath' variable.
		filePath = openFileDialog->FileName;

		// Set the text of the 'textBoxPath' control to display the selected file path.
		textBoxPath->Text = filePath;
	}
}

inline System::Void FormsProject::Form1::buttonEncrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Check if the 'filePath' variable is not null. 
	//If yes, clear the items from the 'listBox1' and add the paths 
	//from the file to the 'listBox1'.
	if (filePath)
	{
		
		std::string key;
		if (textBoxKeyEncrypt->Text == L"Enter Key")
		{
			textBoxKeyEncrypt->Text = nullptr;
		}
		if (textBoxKeyEncrypt->Text!="")
		{
			listBox1->Items->Clear();
			listBox1->Items->AddRange(AddPathToFile(L"<ENCRYPTED>" + filePath, "encrypted.rar")->ToArray());

			// Convert the System::String filePath to std::string std_stringPath.
			String^ System_StringPath = filePath;
			std::string std_stringPath = marshal_as<std::string>(System_StringPath);

			// Open the input file in binary mode, read its contents into a vector buffer,
			//and convert the buffer to a std::string fileContent.
			std::ifstream file_in(std_stringPath, std::ios::binary);
			std::vector<char> buffer((std::istreambuf_iterator<char>(file_in)), std::istreambuf_iterator<char>());
			file_in.close();
			std::string fileContent(buffer.begin(), buffer.end());

			// Encode the fileContent in base64 and store the result in encodedContent.
			std::string encodedContent = base64_encode(fileContent.c_str(), fileContent.length());

			// Initialize an empty string 'key', and check if the 'textBoxKeyEncrypt' 
			//is empty or not. If it's empty, set it to the current time.
			key = marshal_as<std::string>(textBoxKeyEncrypt->Text);

			// Encrypt the encodedContent using the encryptAlgo function and the 'key', 
			//store the result in encryptedContent.
			std::string encryptedContent = encryptAlgo(encodedContent, key);

			// Open the output file in binary mode, write the encryptedContent 
			//to the file, and close the file.
			std::ofstream file_out(std_stringPath + ".crypt", std::ios::binary);
			file_out.write(encryptedContent.c_str(), encryptedContent.size());
			file_out.close();

			// Delete the original unencrypted file.
			File::Delete(System_StringPath);
		}
		else
		{
			MessageBox::Show("Please enter a key!", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
			textBoxKeyEncrypt->Text = nullptr;
			textBoxKeyEncrypt->ForeColor = System::Drawing::Color::Black;
			textBoxKeyEncrypt->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point);			
		}
	}

	// If the 'filePath' variable is null, show a message box informing 
	//the user to browse for a file to encrypt.
	else
		MessageBox::Show("Please browse for a file to encrypt","",MessageBoxButtons::OK,MessageBoxIcon::Information);
}

inline System::Void FormsProject::Form1::Form1_Load(System::Object^ sender, System::EventArgs^ e)
{

	List<String^>^ pathList = gcnew List<String^>();
	StreamReader^ file_in = gcnew StreamReader("encrypted.rar");
	while (!file_in->EndOfStream)
	{
		pathList->Add(file_in->ReadLine());
	}
	file_in->Close();
	pathList->Reverse();
	listBox1->Items->Clear();
	listBox1->Items->AddRange(pathList->ToArray());
}

inline System::Void FormsProject::Form1::buttonDecrypt_Click(System::Object^ sender, System::EventArgs^ e) 
{
	// Get the selected item from a listbox named 'listBox1' 
	//and store it in a variable named 'selected_Item'.
	String^ selected_Item = dynamic_cast<String^>(listBox1->SelectedItem);
	// Check if 'selected_Item' is not null.
	if (selected_Item)
	{
		// Check if the textbox named 'textBoxKeyDecrypt' has the default value of 
		// "Enter Key", if yes then set its value to null.
		if (textBoxKeyDecrypt->Text == L"Enter Key")
		{
			textBoxKeyDecrypt->Text = nullptr;
		}
		// Convert the value of 'textBoxKeyDecrypt' to a std::string named 'key'.
		std::string key = marshal_as<std::string>(textBoxKeyDecrypt->Text);
		if(key!="")
		{
			// Remove the encrypted path from the file named "encrypted.rar" 
			//using a function named 'RemovePathFromFile' 
			//with parameters 'selected_Item' and "encrypted.rar".
			RemovePathFromFile(selected_Item, "encrypted.rar");

			// Remove the selected item from the listbox.
			listBox1->Items->Remove(listBox1->SelectedItem);

			// Remove the "<ENCRYPTED>" header	 from the selected item and store it in a variable named 'System_StringPath'.
			selected_Item = selected_Item->Remove(0, 11);
			String^ System_StringPath = selected_Item;

			// Convert 'System_StringPath' to a std::string named 'std_stringPath'.
			std::string std_stringPath = marshal_as<std::string>(System_StringPath);

			// Append ".crypt" to 'std_stringPath' to get the encrypted file 
			//path and store it in a variable named 'encryptedPath'.
			std::string encryptedPath = std_stringPath + ".crypt";

			// Remove the ".crypt" extension from 'std_stringPath' to get the original file path.
			std_stringPath = std_stringPath.substr(0, std_stringPath.find(".crypt"));

			// Open the encrypted file for reading in binary mode 
			// and store its contents in a vector of chars named 'buffer'.
			std::ifstream file_in(encryptedPath, std::ios::binary);
			std::vector<char> buffer((std::istreambuf_iterator<char>(file_in)), std::istreambuf_iterator<char>());
			file_in.close();

			// Convert the contents of 'buffer' to a std::string named 'str'.
			std::string str(buffer.begin(), buffer.end());

			// Decrypt the contents of 'str' using a function named 'decryptAlgo' 
			// with parameters 'str' and 'key', and store the result in a 
			// std::string named 'decryptedContent'.
			std::string decryptedContent = decryptAlgo(str, key);

			// Decode the base64-encoded content of 'decryptedContent' using a function named 
			//'base64_decode', and store the result in a std::string named 'decodedContent'.
			std::string decodedContent = base64_decode(decryptedContent.c_str());

			// Open the original file for writing in binary mode and write the decoded content to it.
			std::ofstream file_out(std_stringPath, std::ios::binary);
			file_out.write(decodedContent.c_str(), decodedContent.size());
			file_out.close();

			// Delete the encrypted file.
			File::Delete(System_StringPath + ".crypt");
		}
		else
		{
			MessageBox::Show("Please enter the key for this item to decrypt", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
			textBoxKeyDecrypt->Text = nullptr;
			textBoxKeyDecrypt->ForeColor = System::Drawing::Color::Black;
			textBoxKeyDecrypt->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point);
		}
	}
	else
		MessageBox::Show("Please select an item from the list to decrypt", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

inline System::Void FormsProject::Form1::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	if (checkBox1->Checked == true)
	{
		buttonDecrypt->Enabled = true;
		textBoxKeyDecrypt->Enabled = true;
		pictureBox1->Image = System::Drawing::Image::FromFile("Warning.png");
		label1->Visible = true;
		label2->Visible = true;
	}
	else
	{
		buttonDecrypt->Enabled = false;
		textBoxKeyDecrypt->Enabled = false;
		pictureBox1->Image = nullptr;
		label1->Visible = false;
		label2->Visible = false;

	}
}

System::Void FormsProject::Form1::textBoxKeyEncrypt_Enter(System::Object^ sender, System::EventArgs^ e)
{
	if (textBoxKeyEncrypt->Text == L"Enter Key")
	{
		textBoxKeyEncrypt->Text = nullptr;
		textBoxKeyEncrypt->ForeColor = System::Drawing::Color::Black;
		textBoxKeyEncrypt->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point);
	}
}

inline System::Void FormsProject::Form1::textBoxKeyEncrypt_Leave(System::Object^ sender, System::EventArgs^ e) 
{
	if (textBoxKeyEncrypt->Text == L"")
	{
		textBoxKeyEncrypt->ForeColor = System::Drawing::Color::Gray;
		textBoxKeyEncrypt->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point);
		textBoxKeyEncrypt->Text = L"Enter Key";
	}
}

inline System::Void FormsProject::Form1::textBoxKeyDecrypt_Enter(System::Object^ sender, System::EventArgs^ e)
{

	if (textBoxKeyDecrypt->Text == L"Enter Key")
	{
		textBoxKeyDecrypt->Text = nullptr;
		textBoxKeyDecrypt->ForeColor = System::Drawing::Color::Black;
		textBoxKeyDecrypt->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point);
	}
}
inline System::Void FormsProject::Form1::textBoxKeyDecrypt_Leave(System::Object^ sender, System::EventArgs^ e) 
{
	if (textBoxKeyDecrypt->Text == L"")
	{
		textBoxKeyDecrypt->ForeColor = System::Drawing::Color::Gray;
		textBoxKeyDecrypt->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point);
		textBoxKeyDecrypt->Text = L"Enter Key";
	}
}