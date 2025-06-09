#ifndef SSTREAM_BRIDGE_H
#define SSTREAM_BRIDGE_H

//  app

    #include "istream-bridge.h"
    #include "ostream-bridge.h"


//  c++

    #include <utility> // for std::forward
    #include <string>


namespace stream
{
  class IStringStreamImpl;
  class istringstream : public istream
  {
    private :
      IStringStreamImpl* Impl;
      istringstream(IStringStreamImpl* impl);
    public  :  
      istringstream(void);
     ~istringstream(void);
      istringstream(std::string&& str);

      std::string str(void) const;
  };

  template<typename T>
  istringstream& operator>>(istringstream& os, T& v)
  {
      os.scan(v);
      return os;
  }

  class OStringStreamImpl;
  class ostringstream : public ostream
  {
    private :
      OStringStreamImpl* Impl;
      ostringstream(OStringStreamImpl* impl);
    public  :  
      ostringstream(void);
     ~ostringstream(void);
      ostringstream(std::string&& str);

      std::string str(void) const;
  };

  template<typename T>
  ostringstream& operator<<(ostringstream& os, T&& v)
  {
      os.print(std::forward<T>(v));
      return os;
  }

  class StringStreamImpl;
  class stringstream
    : public istream
    , public ostream
  {
    private :
      StringStreamImpl* Impl;
      stringstream(StringStreamImpl* impl);    
    public  :  
      stringstream(void);
      stringstream(std::string&& str);
     ~stringstream(void);

      std::string str(void) const;
  };

  template<typename T>
  stringstream& operator>>(stringstream& os, T& v)
  {
      os.scan(v);
      return os;
  }
  
  template<typename T>
  stringstream& operator<<(stringstream& os, T&& v)
  {
      os.print(std::forward<T>(v));
      return os;
  }
}



#endif // STRINGSTREAM-BRIDGE_H
