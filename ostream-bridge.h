#ifndef OSTREAM_BRIDGE_H
#define OSTREAM_BRIDGE_H

//  app

    #include "ios-bridge.h"


//  c++

    #include <type_traits>


namespace stream
{

  class  OStreamImpl;

  class  ostream : public virtual base
  {
    private :
      // ostream does not own Impl hence we do not implement a destructor
      OStreamImpl* Impl;
    public  :
      ostream(OStreamImpl* impl);

      OStreamImpl& impl(void) { return *Impl; }
      void print(char      );
      void print(bool      );
      void print(int       );
      void print(float     );
      void print(size_t    );
      void print(long      );
      void print(long long );
      void print(unsigned  );
      void print(const void*);
      void print(const char*);
      
      template <typename T>
      typename std::enable_if_t<std::is_base_of_v<base, T>>
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
