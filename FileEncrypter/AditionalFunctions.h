#pragma once
#include<string>
System::Collections::Generic::List<System::String^>^ AddPathToFile(System::String^ strPath, System::String^ fileName);
void RemovePathFromFile(System::String^ strPath, System::String^ fileName);
std::string base64_encode(const char* buf, unsigned int bufLen);
std::string base64_decode(const std::string& encoded_string);
bool is_base64(unsigned char c);
std::string encryptAlgo(const std::string& input, const std::string& key);
std::string decryptAlgo(const std::string& input, const std::string& key);