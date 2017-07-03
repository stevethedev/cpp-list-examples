#ifndef __SD__NODES__NODE_INTERFACE__
#define __SD__NODES__NODE_INTERFACE__

namespace SD::Nodes {
    template<typename T>
    class NodeInterface
    {
        NodeInterface<T>& setValue(T value);
        T getValue();
    };
}

#endif
