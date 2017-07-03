#ifndef __SD__NODES__SINGLY_LINKED_NODE__
#define __SD__NODES__SINGLY_LINKED_NODE__

#include <Nodes/Node.hpp>
#include <Nodes/SinglyLinkedNodeInterface.hpp>

namespace SD::Nodes {
    template<typename T>
    class SinglyLinkedNode :
        public SinglyLinkedNodeInterface<T>,
        public Node<T>
    {
    public:
        /**
         * SinglyLinkedNode Constructor
         * @param T value   Value to hold within the node
         */
        SinglyLinkedNode(T value) :
            Node<T>(value),
            nextNode(NULL)
        {
            // empty constructor
        }

        /**
         * Gets the next node in the chain
         * @return SinglyLinkedNode&
         */
        SinglyLinkedNode<T>* getNextNode()
        {
            return this->nextNode;
        }

        /**
         * Sets the next node in the chain
         * @param SinglyLinkedNode* node
         */
        SinglyLinkedNode<T>& setNextNode(SinglyLinkedNode<T>* node)
        {
            this->nextNode = node;
            return *this;
        }

        /**
         * Retrieves the value contained within the node
         * @return T
         */
        T getValue()
        {
            return Node<T>::getValue();
        }

        /**
         * Sets the value contained within the node
         * @param T value value to carry
         * @return *this
         */
        SinglyLinkedNode<T>& setValue(T value)
        {
            Node<T>::setValue(value);
            return *this;
        }

    protected:
       SinglyLinkedNode<T>* nextNode;
    };
}

#endif
