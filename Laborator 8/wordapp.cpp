#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

// Convert string to lowercase
std::string to_lower(const std::string& str)
{
    std::string result;
    result.reserve(str.length());
    std::transform(str.begin(), str.end(), std::back_inserter(result), ::tolower);
    return result;
}

// Compare two pairs (word, count) for the priority queue
struct WordCompare
{
    bool operator()(const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs) const
    {
        if (lhs.second == rhs.second) {
            return lhs.first < rhs.first; // lexicographical order if same count
        }
        return lhs.second < rhs.second; // order by count
    }
};

int main()
{
    std::string filename = "textfile.txt"; // replace with your file name
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cout << "Error opening file\n";
        return 1;
    }

    // Read the file into a string
    std::string text((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());

    // Split the string into words
    std::string separators = " ,.?!"; // space, comma, period, question mark, exclamation mark
    std::string word;
    std::map<std::string, int> word_counts;
    for (size_t pos = 0, endpos = 0; pos < text.length(); pos = endpos + 1)
    {
        endpos = text.find_first_of(separators, pos);
        if (endpos == std::string::npos) {
            endpos = text.length();
        }
        word = text.substr(pos, endpos - pos);
        if (!word.empty()) {
            word_counts[to_lower(word)]++; // add to map, case-insensitive
        }
    }

    // Create a priority queue of (word, count) pairs
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, WordCompare> word_queue;
    for (const auto& pair : word_counts) {
        word_queue.push(pair);
    }

    // Print the sorted words
    while (!word_queue.empty()) {
        std::pair<std::string, int> word_count = word_queue.top();
        word_queue.pop();
        std::cout << word_count.first << " => " << word_count.second << std::endl;
    }

    return 0;
}
