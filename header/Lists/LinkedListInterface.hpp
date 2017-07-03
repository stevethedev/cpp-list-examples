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
 *
 * @author      Steven Jimenez
 * @copyright   2017 Steven Jimenez
 * @license     MIT
 */

#ifndef __SD__LISTS__LINKED_LIST_INTERFACE__
#define __SD__LISTS__LINKED_LIST_INTERFACE__

#include <Nodes/Node.hpp>

namespace SD::Lists {

    using SD::Nodes::Node;

    /**
     * @class   LinkedListInterface
     * @brief   The basic list interface that all linked lists will inherit from.
     *
     * The ListInterface class provides a contract for how lists should
     * behave. This includes the creation, reading, updating, and deletion
     * of nodes.
     */
    template<typename T>
    class LinkedListInterface
    {
    protected:
        /**
         * @brief   Get a node from the chain
         * @param   index   index of the node to retrieve
         * @return  the node at the given index
         */
        Node<T>& getNode(unsigned int index);

        /**
         * @brief   Creates a new node
         * @param   value   value of the node
         * @return  a newly created node
         */
        Node<T>& createNode(T value);
    };
}

#endif
