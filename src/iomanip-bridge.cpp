//  self

    #include "iomanip-bridge.h"


//  app

    #include "ostream-bridge.h"


namespace stream
{

  ostream& operator<<(ostream& os, const setw        & sw)
  {
    os.width(sw.Sz);
    return os;
  }

  ostream& operator<<(ostream& os, const setprecision& sp)
  {
    os.precision(sp.P);
    return os;
  }

  ostream& operator<<(ostream& os, const setfill     & sf)
  {
    os.fill(sf.C);
    return os;
  }
}
