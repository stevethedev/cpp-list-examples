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

#ifndef __SD__LISTS__SINGLY_LINKED_LIST__
#define __SD__LISTS__SINGLY_LINKED_LIST__

#include <stdexcept>

#include <Lists/ListInterface.hpp>
#include <Nodes/SinglyLinkedNode.hpp>

namespace SD::Lists {

    using SD::Nodes::SinglyLinkedNode;

    template<typename T>
    class SinglyLinkedList : ListInterface<T>
    {
    public:
        /**
         * Creates a singly-linked list data structure
         */
        SinglyLinkedList() : headNode(NULL)
        {
            // empty constructor
        }

        /**
         * Inserts a new value at the requested index. If no index is provided, then
         * assumes that the value should be inserted at the end of the data
         * structure.
         *
         * @param  T    value
         *
         * @return *this
         */
        SinglyLinkedList<T>& insert(T value)
        {
            if (NULL == this->headNode) {
                return this->insert(value, 0);
            }

            SinglyLinkedNode<T>& lastNode = this->getLastNode();
            SinglyLinkedNode<T>* node = new SinglyLinkedNode<T>(value);

            lastNode.setNextNode(node);

            return *this;
        }

        /**
         * Inserts a new value at the requested index. If no index is provided, then
         * assumes that the value should be inserted at the end of the data
         * structure.
         *
         * @param  T     value
         * @param  uint= index
         *
         * @return *this
         */
        SinglyLinkedList<T>& insert(T value, unsigned int index)
        {
            SinglyLinkedNode<T>* node = new SinglyLinkedNode<T>(value);

            if (0 == index) {
                node->setNextNode(this->headNode);
                this->headNode = node;
                return *this;
            }

            SinglyLinkedNode<T>& previousNode = this->getNode(index - 1);
            node->setNextNode(previousNode.getNextNode());
            previousNode.setNextNode(node);

            return *this;
        }

        /**
         * Retrieves a value from the identified index
         *
         * @param  uint  index
         * @return T    value stored at the index
         */
        T get(unsigned int index)
        {
            return this->getNode(index).getValue();
        }

        /**
         * Updates a value at the identified index
         *
         * @param  uint  index
         * @param  T     value
         *
         * @return *this
         */
        SinglyLinkedList<T>& set(unsigned int index, T value)
        {
            this->getNode(index).setValue(value);
            return *this;
        }

        /**
         * Removes "count" nodes, starting from the identified index
         *
         * @param  uint      index
         * @param  uint=1    count
         *
         * @return *this
         */
        SinglyLinkedList<T>& remove(unsigned int index, unsigned int count = 1)
        {
            SinglyLinkedNode<T>* nextNode = this->getNode(index + count - 1).getNextNode();
            if (0 == index) {
                this->headNode = nextNode;
                return *this;
            }

            this->getNode(index - 1).setNextNode(nextNode);
            return *this;
        }

        /**
         * Counts the number of nodes in the linked list
         *
         * @return uint
         */
        unsigned int count()
        {
            unsigned int count = 0;
            SinglyLinkedNode<T>* node = this->headNode;
            while (node) {
                node = node->getNextNode();
                ++count;
            }
            return count;
        }

    protected:
        /**
         * Retrieves the node at the identified index
         *
         * @param  uint index
         * @return SinglyLinkedNodeInterface&
         */
        SinglyLinkedNode<T>& getNode(unsigned int index)
        {
            SinglyLinkedNode<T>* node = this->headNode;
            for (unsigned int i = 0; i < index; ++i) {
                node = node->getNextNode();
                if (!node) {
                    throw new std::out_of_range("Expected index to be within length of list");
                }
            }

            return *node;
        }

        /**
         * Retrieves the last node in the structure
         *
         * @return SinglyLinkedNodeInterface&
         */
        SinglyLinkedNode<T>& getLastNode()
        {
            SinglyLinkedNode<T>* node = this->headNode;
            while (node && node->getNextNode()) {
                node = node->getNextNode();
            }
            if (!node) {
                throw new std::out_of_range("Expected index to be within length of list");
            }

            return *node;
        }

        SinglyLinkedNode<T>* headNode;
    };
}

#endif
