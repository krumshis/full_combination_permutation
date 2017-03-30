// Five Dwarves ( Gimli Fili Ilif Ilmig and Mark) met at the Prancing Pony and played

// a word game to determine which combinations of their names resulted in a palindrome.

// Write a program in that prints out all of those combinations.



#include <iostream>

#include <algorithm>

#include <map>

#include <vector>

#include <string>



using namespace std;



class AllCombinations {

 public:

    AllCombinations(int n, std::vector<string>* words)

    : n_size(n), m_input_words(words) {};


    
~AllCombinations() {};


    bool IsPalindrome(const string& line) {

        int len = line.length();

        int half_len = len >> 1;

        if (len < 2) {

            return true;

        } else {

            for (int i = 0; i < half_len; i++) {

                if (line[i] != line[len - 1 - i])

                    return false;

            }

            // If we finished the loop, it must be a palindrome!

            return true;

        }

        return false;

    }


    
void CreateCombinations(int r) {

        std::vector<string> current_combination;

        current_combination.resize(r);

        MakeSingleCombination(&current_combination, 0, r, r);

    }


    void MakeSingleCombination(std::vector<string>* current_combination, /* combination of words */
                                                       /* index in input vector, where we can start looking for next word */

                               int start,

                               int r_left,  /* number of words in combination we still need to fill */

                               int r /* size of combination */) {

        // Current combination is ready to be processed for permutations and possible palindromes.

        if (r_left == 0) {

            // Now that we have a unique set of r words and we need to examine all permutations

            // of this set and determine if there are any palindromes. The set is already sorted

            // in ascendig order (m_input_words was sorted) so we can use std::next_permutation.

            do {

                string possible_palindrome = "";

                for (auto word : *current_combination) {

                    possible_palindrome += word;

                }

                std::transform(possible_palindrome.begin(), possible_palindrome.end(),

                               possible_palindrome.begin(), ::tolower);

                if (IsPalindrome(possible_palindrome)) {

                    n_palindromes++;

                    cout << n_palindromes << ". ";

                    for (const auto word : *current_combination) {

                        cout << word << " ";

                    }

                    cout << "\n";

                }

            } while (std::next_permutation(current_combination->begin(), current_combination->end()));

            return;

        } else if (start + r_left <= n_size) {

            for (int i = start; i < n_size; i++) {

                current_combination->at(r - r_left) = m_input_words->at(i);

                MakeSingleCombination(current_combination, i + 1, r_left - 1, r);

            }

        } else {

            // Can't move forward - return.

            return;

        }

    }


    
int GetPalindromeNumber() { return n_palindromes; }

    int GetInputSize() { return n_size; }

    std::vector<string>* GetInputWords() { return m_input_words; }

    
 
 private:

    int n_size;  // full size of the input

    std::vector<string>* m_input_words; // input words;

    int n_palindromes = 0;   // number of found palindromes

};


// Input is taken from stdin and results are written to stdout.



int main() {

    int n;  // number of words in the intput;

    cin >> n;

    string input_word = "";

    std::vector<string> words;

    for (int i = 0; i < n; i++) {

        cin >> input_word;

        words.push_back(input_word);

    }

    // Sort element of input into ascending order.

    std::sort(words.begin(), words.end());


    auto all_combinations = AllCombinations(n, &words);

    for (int r = 1; r <= n; r++) {

        all_combinations.CreateCombinations(r);

    }

    cout << "Num of palindromes: " << all_combinations.GetPalindromeNumber();



    return 0;

}
