#ifndef __SD__LISTS__LIST_INTERFACE__
#define __SD__LISTS__LIST_INTERFACE__

namespace SD::Lists {
    template<typename T>
    class ListInterface
    {
    public:
        ListInterface<T>& insert(T value);
        ListInterface<T>& insert(T value, unsigned int index);
        T get(unsigned int index);
        ListInterface<T>& set(unsigned int index, T value);
        ListInterface<T>& remove(unsigned int index, unsigned int count = 1);
        unsigned int count();
    };
}

#endif
