# include <sstream>
# include <string>
# include <iostream>

int
main(void)
{
   int m_Len = 42;
   std::string s;
   std::stringstream ss;

   ss << m_Len;

   s = ss.str();
   std::cout << s;
   return 0;
}

