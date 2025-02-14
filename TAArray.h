#ifndef TAARRAY_H
#define TAARRAY_H
#include "TextArea.h"
#include "defs.h"

class TAArray {
private:
    TextArea** arr;
    int capacity;
    int size;

    void resize(); 

public:
    TAArray(int capacity = 10); 
    ~TAArray(); 
    TextArea* get(const std::string& id) const; 
    TextArea* remove(const std::string& id);         

    void add(TextArea* ta);
    bool add(TextArea* ta, int index);
    TextArea* get(int index) const; 
    TextArea* remove(int index); 
    int getSize() const; 
};

#endif
