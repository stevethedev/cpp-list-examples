/**
 * MIT License
 *
 * Copyright (c) 2017 Steven Jimenez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
