#ifndef OSTREAM_BRIDGE_H
#define OSTREAM_BRIDGE_H

#include "ios-bridge.h"

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
      void print(ostream& (*manip)(ostream&)) { manip(*this); }

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
  ostream& flush(ostream& os) { os.flush(); return os; }
  ostream& endl (ostream&);
}



#endif // OSTREAM-BRIDGE_H
