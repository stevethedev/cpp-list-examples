#ifndef __SD__NODES__SINGLY_LINKED_NODE_INTERFACE__
#define __SD__NODES__SINGLY_LINKED_NODE_INTERFACE__

#include "NodeInterface.hpp"

namespace SD::Nodes {
    template<typename T>
    class SinglyLinkedNodeInterface : public NodeInterface<T>
    {
    public:
        NodeInterface<T>* getNextNode();

        NodeInterface<T>& setNextNode(NodeInterface<T>* node);
    };
}

#endif
