#ifndef VISITOR_H
#define VISITOR_H

#include "Jaeger.h"
#include "Kaiju.h"

/* a visitor can visit any of my specific data types */
class Visitor {
  public:
    virtual void visit(Kaiju *e) = 0;
    virtual void visit(Jaeger *e) = 0;
};
#endif

