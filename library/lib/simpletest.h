/*
 * ++C - C++ introduction
 * Copyright (C) 2013, 2014, 2015, 2016, 2017 Wilhelm Meier <wilhelm.meier@hs-kl.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifdef _MSC_VER
#  pragma warning(push)
#  pragma warning(disable: 4996)
#  pragma warning(disable: 4573)
#endif

#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
#include <cmath>

#define CAT2(X, Y) X ## Y
#define CAT(X, Y) CAT2(X, Y)

#define SIMPLETEST(name) static PPC::SimpleTestCase CAT(SimpleTestCaseOnLine, __LINE__) = \
    PPC::SimpleTestCase(name, __FILE__, __LINE__) = []

namespace PPC {
    
    class SimpleTestCase final {
    public:
        inline explicit SimpleTestCase(const char* name, const char* file, int line) :
            mName{name}, mLine{line}, mFile{file} {}
        
        template <typename T>
        SimpleTestCase& operator=(T lambda)
        {
            bool noOutput = false;
            bool noTests = false;
            if (const char* env = getenv("SIMPLETEST")) {
                std::string envVar{env};
                if (envVar.find("nooutput") != std::string::npos) {
                    noOutput = true;
                }
                if (envVar.find("notests") != std::string::npos) {
                    noTests = true;
                }
            }
# ifndef NDEBUG
            if (!noOutput && !noTests) {
                std::cout << "Test(" << mName << "," << mFile << "," << mLine << ")";
            }
# endif
            if (!noTests) {
                ++mTestCount;
                if (lambda()) {
# ifndef NDEBUG
                    if (!noOutput) {
                        std::cout << " ok " << "(" << mTestCount << "/" << mFailureCount << ")" << std::endl;
                    }
# endif
                }
                else {
                    ++mFailureCount;
# ifndef NDEBUG
                    if (!noOutput) {
                        std::cout << " failed " << "(" << mTestCount << "/" << mFailureCount << ")" << std::endl;
                    }
                    else {
                        std::cerr << "Test(" << mName << "," << mFile << "," << mLine << ") failed " << "(" << mTestCount << "/" << mFailureCount << ")" << std::endl;
                    }
# endif
                }
            }
            return *this;
        }
        inline static bool equal(double a, double b)  {
            if (a == b) {
                return true;
            }
            double diff = std::fabs(a - b);
            double max = std::max(fabs(a), fabs(b));
            double rdiff = diff / max;
            return rdiff <= std::numeric_limits<double>::epsilon();
        }
        
    private:
        const char* mName = "undefined";
        const int mLine = 0;
        const char* mFile = "undefined";
        inline static size_t mTestCount = 0;
        inline static size_t mFailureCount = 0;
    };
}
#ifdef _MSC_VER
#  pragma warning(pop)
#endif

