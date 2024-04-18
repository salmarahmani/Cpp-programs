/* 
 * Description: This C++ program gets a text from the user of up to 100 words and 700 characters 
 *              and then prints the same text in alphabetical order of its words.
 *              An example output is as follows:
 *              Give a text of no more than 100 words and 700 characters:
 *              [User input text]
 *              Ordered text is:
 *              [Text in alphabetical order]
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

// Function to convert a word to lowercase
std::string toLowercase(const std::string& word) {
    std::string result = word;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {
    std::string text;
    std::cout << "Enter text: ";
    std::getline(std::cin, text);

    // Tokenize the input text into words
    std::istringstream iss(text);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        // Convert each word to lowercase and add it to the vector
        words.push_back(toLowercase(word));
    }

    // Sort the words alphabetically ignoring case
    std::sort(words.begin(), words.end());

    // Print the ordered text
    std::cout << "Ordered text:\n";
    for (const auto& w : words) {
        std::cout << w << " ";
    }
    std::cout << std::endl;

    return 0;
}
