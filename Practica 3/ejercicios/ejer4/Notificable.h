
#ifndef NOTIFICABLE_H
#define NOTIFICABLE_H

using namespace std;

class Notificable {
public:
    virtual void notificar() = 0;
    virtual ~Notificable() {}
};

#endif 
