#ifndef IOMANIP_BRIDGE_H
#define IOMANIP_BRIDGE_H

#include "ios-bridge.h"

namespace stream
{
  class ostream;
  struct setw        { streamsize Sz; };
  struct setprecision{ streamsize P;  };
  struct setfill     { char       C;  };

  ostream& operator<<(ostream& os, const setw        &);
  ostream& operator<<(ostream& os, const setprecision&);
  ostream& operator<<(ostream& os, const setfill     &);
}

#endif // IOMANIP-BRIDGE_H
