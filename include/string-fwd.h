#ifndef STRING_FWD_H
#define STRING_FWD_H


namespace std
{
    template<class CharT> class char_traits;
    template<class T>     class allocator;
    template<
        class CharT,
        class Traits,
        class Allocator>  class basic_string;
    using string=basic_string<char,char_traits<char>,allocator<char>>;
}



#endif // STRING-FWD_H
