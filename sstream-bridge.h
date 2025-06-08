#ifndef SSTREAM_BRIDGE_H
#define SSTREAM_BRIDGE_H

//  app

    #include "ostream-bridge.h"


//  c++

    #include <utility> // for std::forward
    #include <string>


namespace stream
{
  class OSStreamImpl;
  class ostringstream : public ostream
  {
    private :
      OSStreamImpl* Impl;
      ostringstream(OSStreamImpl* impl);
    public  :  
      ostringstream(void);
     ~ostringstream(void);
      ostringstream(const std::string& str);
      ostringstream           (const ostringstream& os) = delete;
      ostringstream& operator=(const ostringstream& os) = delete;
      ostringstream           (ostringstream&& os)      = delete;
      ostringstream& operator=(ostringstream&& os)      = delete;
      
      std::string str(void) const;
  };

  template<typename T>
  ostringstream& operator<<(ostringstream& os, T&& v)
  {
      os.print(std::forward<T>(v));
      return os;
  }
}



#endif // STRINGSTREAM-BRIDGE_H
