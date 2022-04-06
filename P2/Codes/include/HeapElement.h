#ifndef _HeapElement_H_
#define _HeapElement_H_


#define ElementType HeapElement
class HeapElement
{
public:
    int vertex;
    int distance;
    bool operator< (ElementType& a){
        return this->distance < a.distance;
    }
    bool operator> (ElementType& a){
        return this->distance > a.distance;
    }
};

#endif