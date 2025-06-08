#ifndef OSTREAM_BRIDGE_H
#define OSTREAM_BRIDGE_H

#include <utility> // for std::forward

namespace stream
{
  using streamsize=long long;
  
  struct setw         { streamsize Sz; };
  struct setprecision { streamsize P; };
  struct setfill      { char       C; };
  struct endlStruct   {};
  struct hexStruct    {};
  class  OStreamImpl;

  class  ostream
  {
    private :
      // ostream does not own Impl hence we do not implement a destructor
      OStreamImpl* Impl;
    public  :
      ostream(OStreamImpl* impl)
        :Impl(impl)
      {
      }
      ostream           (const ostream& os) = delete;
      ostream& operator=(const ostream& os) = delete;
      ostream           (ostream&& os)      = delete;
      ostream& operator=(ostream&& os)      = delete;
      
      void print(bool      );
      void print(int       );
      void print(float     );
      void print(size_t    );
      void print(long      );
      void print(long long );
      void print(unsigned  );
      void print(const void*);
      void print(const char* str);
      void print(setw         sw) { width    (sw.Sz); }
      void print(setprecision sp) { precision(sp.P);  }
      void print(endlStruct   eL);
      void print(hexStruct    h);
      void print(setfill      sf);
      
      streamsize width    (streamsize w);
      streamsize precision(streamsize p);
      void       put      (char       c);
      void       flush    (void);
  };

  template<typename T>
  ostream& operator<<(ostream& os, T&& v)
  {
      os.print(std::forward<T>(v));
      return os;
  }
  
  constexpr inline endlStruct endl;
  constexpr inline hexStruct  hex;
}



#endif // OSTREAM-BRIDGE_H
