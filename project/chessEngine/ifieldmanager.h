#ifndef IFIELDMANAGER_H
#define IFIELDMANAGER_H

class Field;
class FieldCoordinate;

class IFieldManager {
    public:
        virtual Field* getField(FieldCoordinate c)=0;

};


#endif // IFIELDMANAGER_H
