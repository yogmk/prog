/**
 ** Implementation of Tokeniser class. This is a replacement to the
 ** Rogue Wave's RWTokenizer class.
 **/

# include <stdlib.h>
# include <iostream>
# include "Tokeniser.h"

using namespace std;
namespace bnym
{
    Tokeniser::~Tokeniser () {}

    Tokeniser::Tokeniser() {}   //default constructor
    
    Tokeniser::Tokeniser (string s const)
    {
        _s =  new string(s);  // make a pvt copy.
        next_pos = 0;
    }
    
    string Tokeniser::tokenised_str (const string& token)
    {
        string retVal;
        char *tmp = NULL;
    
        if (!_s->empty())
        {
            if (!next_pos)
            {
                if ((tmp = strtok ((char*)_s->c_str(), (char*)token.c_str())) != NULL )
                {
                retVal = string(tmp);
                next_pos++;           // as of now.
            }
        }
        else
        {
            if ((tmp = strtok (NULL, (char*)token.c_str())) != NULL)
            {
                 retVal = string(tmp);
            }
        }
        }
        else
        {
            retVal = "";
        }
    
        return retVal;
    }
    
    string Tokeniser::operator() ()
    {
        return tokenised_str (string(" \t\n\0"));

    }
    
    string Tokeniser::operator (const string& tokens)
    {
        if (! tokens.empty())
            return tokenised_str (tokens);
        else
            return this->operator ();
    }

} // namespace
