#ifndef OSTREAM_BRIDGE_H
#define OSTREAM_BRIDGE_H

//  app

    #include "ios-bridge.h"
    #include "string-fwd.h"


//  c++

    #include <type_traits>


namespace stream
{

  class  OStreamImpl;

  class  ostream : public virtual basic_ios
  {
    private :
      // ostream does not own Impl hence we do not implement a destructor
      OStreamImpl* Impl;
      friend basic_ios;
    public  :
      ostream(OStreamImpl* impl);

      OStreamImpl& impl(void) { return *Impl; }
      void print(char              );
      void print(bool              );
      void print(int               );
      void print(float             );
      void print(size_t            );
      void print(long              );
      void print(long long         );
      void print(unsigned          );
      void print(const void*       );
      void print(const char*       );
      void print(const std::string&);

      template <typename T>
      typename std::enable_if_t<std::is_base_of_v<basic_ios, T>>
      print(T& (*manip)(T&))
      {
          manip(*this);
      }

      ostream& put  (char c);
      char     fill (char c);
      void     flush(void);
  };

  template<typename T>
  ostream& operator<<(ostream& os, const T& v)
  {
      os.print(v);
      return os;
  }
  inline ostream& flush(ostream& os) { os.flush(); return os; }
  ostream& endl (ostream&);
}



#endif // OSTREAM-BRIDGE_H
