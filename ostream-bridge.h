#ifndef OSTREAM_BRIDGE_H
#define OSTREAM_BRIDGE_H

#include "ios-bridge.h"

#include <utility> // for std::forward

namespace stream
{
  struct setw            { streamsize Sz; };
  struct setprecision    { streamsize P; };
  struct setfill         { char       C; };
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
      void print(const char*     str);
      void print(setw            sw) { width    (sw.Sz); }
      void print(setprecision    sp) { precision(sp.P);  }
      void print(ostream& (*manip)(ostream&)) { manip(*this); }
      void print(setfill         sf);


      void       put      (char       c);
      void       flush    (void);
  };

  template<typename T>
  ostream& operator<<(ostream& os, T&& v)
  {
      os.print(std::forward<T>(v));
      return os;
  }

  ostream& endl     (ostream&);
  ostream& hex      (ostream&);
  ostream& boolalpha(ostream&);
}



#endif // OSTREAM-BRIDGE_H
