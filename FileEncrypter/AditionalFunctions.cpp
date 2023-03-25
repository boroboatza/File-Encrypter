#include "pch.h"
#include "AditionalFunctions.h"
#include "Form1.h"
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace System::IO;
using namespace System;
using namespace System::Collections::Generic;
using namespace std;
using namespace System::Text;
List<String^>^ AddPathToFile(String^ strPath, String^ fileName)
{
    // Check if the input parameters strPath and fileName are null or empty, if yes then throw an exception.
    if (String::IsNullOrEmpty(strPath))
    {
        throw gcnew ArgumentException("strPath cannot be null or empty.");
    }

    if (String::IsNullOrEmpty(fileName))
    {
        throw gcnew ArgumentException("fileName cannot be null or empty.");
    }

    // Create a new list to store the paths from the file.
    List<String^>^ paths = gcnew List<String^>();

    // Initialize two boolean variables checkPath and duplicate to false.
    bool checkPath = false;
    bool duplicate = false;

    try
    {
        // Create a new StreamReader to read the file with the provided file name.
        StreamReader^ In = gcnew StreamReader(fileName);

        int i = 0;
        // Read the file line by line and add each line to the paths list.
        while (!In->EndOfStream)
        {
            paths->Add(In->ReadLine());

            // Check if the path in the current line contains the provided path strPath, if yes then set duplicate to true.
            checkPath = paths[i]->Contains(strPath);
            i++;
            if (checkPath)
                duplicate = true;
        }

        // Close the StreamReader.
        In->Close();
    }
    catch (Exception^ e)
    {
        // If there is an exception while reading the file, then throw a new IOException with a message including the file name and the exception details.
        throw gcnew IOException("Error reading file " + fileName, e);
    }

    // If duplicate is false, then add the provided path strPath to the paths list.
    if (!duplicate)
    {
        paths->Add(strPath);
    }

    try
    {
        // Create a new StreamWriter to write to the file with the provided file name, overwrite the file if it already exists.
        StreamWriter^ Out = gcnew StreamWriter(fileName, false);

        // Write each path in the paths list to the file.
        for (int i = 0; i < paths->Count; i++)
        {
            Out->WriteLine(paths[i]);
        }

        // Close the StreamWriter.
        Out->Close();
    }
    catch (Exception^ e)
    {
        // If there is an exception while writing to the file, then throw a new IOException with a message including the file name and the exception details.
        throw gcnew IOException("Error writing file " + fileName, e);
    }

    // Reverse the order of the paths in the paths list and return the list.
    paths->Reverse();
    return paths;
}

void RemovePathFromFile(System::String^ path, System::String^ fileName)
{
    //Checks if the input parameters 'path' and 'fileName' 
    //are null or empty strings, and if so, throws an ArgumentException 
    //with a corresponding error message.
    if (String::IsNullOrEmpty(path))
    {
        throw gcnew ArgumentException("path cannot be null or empty.");
    }

    if (String::IsNullOrEmpty(fileName))
    {
        throw gcnew ArgumentException("fileName cannot be null or empty.");
    }

    try
    {
        // Open the file in read-write mode
        FileStream^ fileStream = gcnew FileStream(fileName, FileMode::Open, FileAccess::ReadWrite);

        // Create a stream reader to read the file
        StreamReader^ reader = gcnew StreamReader(fileStream);

        // Create a stream writer to write the temporary file
        StreamWriter^ writer = gcnew StreamWriter(gcnew FileStream("temp.txt", FileMode::Create));

        int lineCount = 0;
        String^ line;

        // Read each line from the file
        while ((line = reader->ReadLine()) != nullptr)
        {
            //Increment the number of lines
            lineCount++;

            // Check if it's the line we want to delete
            if (line == path)
            {
                continue; // Go to the next line
            }

            // Write the current line to the temporary file
            writer->WriteLine(line);
        }

        // Close the files
        fileStream->Close();
        writer->Close();
        reader->Close();

        // Delete the original file and rename the temporary file
        File::Delete(fileName);
        File::Move("temp.txt", fileName);
    }
    catch (Exception^ e)
    {
        // Log the error message and re-throw or throw a new exception with more details
        Console::WriteLine("Error removing path from file: " + e->Message);
        throw gcnew IOException("Error removing path '" + path + "' from file " + fileName, e);
    }
}

std::string base64_encode(const char* buf, unsigned int bufLen)
{
    // Define the base64 encoding table.
    const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    // Create a stringstream to store the encoded string.
    std::stringstream ss; 
    unsigned int i = 0;

    // Create an array to store 3 bytes at a time.
    unsigned char array3[3]{}; 

    // Create an array to store 4 encoded characters.
    unsigned char array4[4]{}; 
    while (bufLen--)
    {
        // Read one byte at a time from the input buffer and store it in the array3.
        array3[i++] = *(buf++);
        if (i == 3) 
        {
            // Get the first 6 bits of the first byte.
            array4[0] = (array3[0] & 0xfc) >> 2; 

            // Get the last 2 bits of the first byte and the first 4 bits of the second byte.
            array4[1] = ((array3[0] & 0x03) << 4) + ((array3[1] & 0xf0) >> 4);

            // Get the last 4 bits of the second byte and the first 2 bits of the third byte.
            array4[2] = ((array3[1] & 0x0f) << 2) + ((array3[2] & 0xc0) >> 6); 

            // Get the last 6 bits of the third byte.
            array4[3] = array3[2] & 0x3f;
            for (i = 0; i < 4; i++)
            {
                // Write the four encoded characters to the stringstream.
                ss << base64_table[array4[i]];
            }
            i = 0;
        }
    }
    if (i)
    {
        for (unsigned int j = i; j < 3; j++)
        {
            // If the remaining byte(s) is/are less than 3, set them to 0.
            array3[j] = '\0'; 
        }

        // Get the first 6 bits of the first byte.
        array4[0] = (array3[0] & 0xfc) >> 2;

        // Get the last 2 bits of the first byte and the first 4 bits of the second byte.
        array4[1] = ((array3[0] & 0x03) << 4) + ((array3[1] & 0xf0) >> 4);

        // Get the last 4 bits of the second byte and the first 2 bits of the third byte.
        array4[2] = ((array3[1] & 0x0f) << 2) + ((array3[2] & 0xc0) >> 6); 

        // Get the last 6 bits of the third byte.
        array4[3] = array3[2] & 0x3f; 

        for (unsigned int j = 0; j < i + 1; j++)
        {
            // Write the encoded characters to the stringstream.
            ss << base64_table[array4[j]];
        }

        while (i++ < 3)
        {
            /* If there is only one remaining byte, append two padding 
            characters to the output.If there are two remaining bytes, 
            append one padding character to the output.*/
            ss << '=';
        }
    }

    // Return the base64 encoded string.
    return ss.str(); 
}

std::string base64_decode(const std::string& encoded_string)
{
    // Define a string containing all the base64 characters.
    const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    // Initialize an empty string to store the decoded string.
    std::string decoded_string;

    // Get the length of the input encoded string.
    int in_len = encoded_string.size();
    int i = 0;

    // Loop through each character in the input string, and decode them until the end of the string is reached or a padding character '=' is found.
    while (in_len-- && (encoded_string[i] != L'=') && is_base64(encoded_string[i]))
    {
        // Get the four base64 characters to decode.
        char c1 = encoded_string[i++];
        char c2 = encoded_string[i++];
        char c3 = encoded_string[i++];
        char c4 = encoded_string[i++];

        // Find the position of each base64 character in the base64_chars string.
        char b1 = base64_chars.find(c1);
        char b2 = base64_chars.find(c2);
        char b3 = base64_chars.find(c3);
        char b4 = base64_chars.find(c4);

        // Decode the base64 characters into three bytes.
        char decoded_char1 = (b1 << 2) | (b2 >> 4);
        char decoded_char2 = ((b2 & 0x0f) << 4) | (b3 >> 2);
        char decoded_char3 = ((b3 & 0x03) << 6) | b4;

        // Add the decoded bytes to the decoded string.
        decoded_string += decoded_char1;

        // If c3 is not a padding character '=', then add the second decoded byte to the decoded string.
        if (c3 != '=')
        {
            decoded_string += decoded_char2;
        }

        // If c4 is not a padding character '=', then add the third decoded byte to the decoded string.
        if (c4 != '=')
        {
            decoded_string += decoded_char3;
        }
    }

    // Return the decoded string.
    return decoded_string;
}

bool is_base64(unsigned char c)
{
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string encryptAlgo(const std::string& input, const std::string& key)
{
    // Check if the input string is empty, if yes then throw 
    //an exception with an error message.
    if (input.empty())
    {
        throw std::invalid_argument("Input string is empty.");
    }

    // Check if the key string is empty, if yes then throw an exception with
    //an error message.
    if (key.empty())
    {
        throw std::invalid_argument("Key string is empty.");
    }

    // Initialize an empty std::string variable 'result' to store the encrypted output.
    std::string result;

    // Initialize an integer variable 'keych' to 0, this will be used to 
    //calculate the key for encryption.
    int keych = 0;

    // Calculate the key by adding the ASCII value of each character in the key string.
    for (int j = 0; j < key.size(); j++)
    {
        keych += static_cast<int>(key[j]);
    }

    // Loop through each character in the input string and add the keych 
    //value to each character, and then add the result to the 'result' variable.
    for (int i = 0; i < input.size(); i++)
    {
        result += static_cast<char>(input[i] + keych);
    }

    // Return the encrypted output stored in the 'result' variable.
    return result;
}

std::string decryptAlgo(const std::string& input, const std::string& key)
{
    // Check if the input string is empty, 
    //if yes then throw an exception with an error message.
    if (input.empty())
    {
        throw std::invalid_argument("Input string is empty.");
    }

    // Check if the key string is empty, 
    //if yes then throw an exception with an error message.
    if (key.empty())
    {
        throw std::invalid_argument("Key string is empty.");
    }
    // Initialize a char variable 'keych' to 0, 
    //this will be used to calculate the key for decryption.
    char keych = 0;

    // Initialize an empty std::string variable 'result' 
    //to store the decrypted output.
    std::string result;

    // Calculate the key by adding the value of each character in the key string.
    for (int j = 0; j < key.size(); j++)
    {
        keych += key[j];
    }

    // Loop through each character in the input string 
    //and subtract the keych value from each character, 
    //and then add the result to the 'result' variable.
    for (int i = 0; i < input.size(); i++)
    {
        result += static_cast<char>(input[i] - keych);
    }

    // Return the decrypted output stored in the 'result' variable.
    return result;
}
