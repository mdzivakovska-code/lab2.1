#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2.1/Number.h"
#include "../lab2.1/Number.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTestNumber)
    {
    public:

        
        TEST_METHOD(TestDefaultConstructor)
        {
            Number n;
            Assert::AreEqual(0.0, n.GetFirst(), 0.0001);
            Assert::AreEqual(0.0, n.GetSecond(), 0.0001);
        }

        
        TEST_METHOD(TestInitConstructorValid)
        {
            Number n(15, 0.45);
            Assert::AreEqual(15.0, n.GetFirst(), 0.0001);
            Assert::AreEqual(0.45, n.GetSecond(), 0.0001);
        }

        
        TEST_METHOD(TestValidationInvalidData)
        {
            Number n(12.34, 1.5);
            Assert::AreEqual(0.0, n.GetFirst(), 0.0001);
            Assert::AreEqual(0.0, n.GetSecond(), 0.0001);
        }

       
    };
}