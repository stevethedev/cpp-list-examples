#ifndef __SD__NODES__NODE__
#define __SD__NODES__NODE__

#include <Nodes/NodeInterface.hpp>

namespace SD::Nodes {
    template<typename T>
    class Node : public NodeInterface<T>
    {
    public:
        Node(T value) : value(value)
        {
            // empty constructor
        }

        /**
         * Retrieves the value contained within the node
         * @return T
         */
        T getValue()
        {
            return this->value;
        }

        /**
         * Sets the value contained within the node
         * @param T value value to carry
         * @return *this
         */
        Node<T>& setValue(T value)
        {
            this->value = value;
            return *this;
        }

    protected:
       T value;
    };
}

#endif
