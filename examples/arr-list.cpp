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

#include <iostream>

#include <Lists/ArrayList.hpp>

using SD::Lists::ArrayList;

int main(int argc, char const *argv[]) {
    ArrayList<std::string> list;
    list.insert("world").insert("hello", 0);
    std::cout << list.get(0) << " " << list.get(1) << "!" << std::endl;
    std::cout << list.remove(1).get(0) << "!" << std::endl;
    std::cout << "count: " << list.count() << std::endl;
    std::cout << list.set(0, "goodbye!").get(0) << "!" << std::endl;
    return 0;
}
