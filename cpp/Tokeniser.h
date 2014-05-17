/**
 ** Replacement class for Rogue Wave's RWTokenizer
 **
 ** Date written: 18-03-2010
 **
 ** The comments are copied from Rogue Wave documentation and
 ** are used as guidelines to implement the functions.
 **/


# ifndef _BNYM_TOKENISER_H_
# define _BNYM_TOKENISER_H_

# include <string>

namespace bnym {

    class Tokeniser
    {
        public:
          Tokeniser ();

          // Constructs a tokenizer to lex the std::string s.

          Tokeniser (const std::string str);

          ~Tokeniser ();

          // Advances to the next token and return it as a substring.
          // The tokens are delimited by any of the four characters in
          // " \t\n\0" (space, tab, newline and null).

          std::string operator() ();

          // Advances to the next token and return it as a substring.
          // The tokens are delimited by any character in s, or any embedded null.

          std::string operator() (const std::string& s);

          // Advances to the next token and return it as a substring.
          // The tokens are delimited by any of the first num characters in s.
          // Buffer s may contain nulls, and must contain at least num  characters.
          // Tokens will not be delimited by nulls unless s  contains nulls.

          std::string operator() (const std::string& s, size_t num);

          // Returns true if the last token from the search string has been extracted.
          // If the last token has not been extracted, it will return false. When using
          // the function call operator interface, this is the same as the last non-empty
          // token having been returned.

          bool done () const;

          /** Following nextToken() methods may return an empty token if there are
           ** consecutive occurrences of any delimiter character in the search string.
           **/

          // Returns the next token using a default set of delimiter characters.

          std::string nextToken ();

          // Returns the next token using a specified std::string of delimiter characters.

          std::string nextToken (const std::string& s);

          // Returns the next token using the first num code units from the given
          // std::string str of delimiter characters

          std::string nextToken (const std::string& s, size_t num);

        private:

          // heart of this class. This function actually uses standard C library
          // function strtok() to do its job

          std::string tokenised_str (const std::string& token);

          // our pvt copy of the data std::string to be tokenised.
          // strtok() modifies the original std::string, so we copy on this & use.

          std::string* _s;

          size_t next_pos;
    };
}

# endif
