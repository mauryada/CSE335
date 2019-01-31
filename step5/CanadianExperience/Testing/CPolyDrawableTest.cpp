/**
* \file CDrawableTest.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include "CppUnitTest.h"
#include "PolyDrawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(EmptyTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCPolyDrawableConstructor)
		{
			// This is an empty test just to ensure the system is working
			CPolyDrawable drawable(L"drawing");
			Assert::AreEqual(std::wstring(L"drawing"), drawable.GetName());
		}
		TEST_METHOD(TestCPolyDrawableColor)
		{
			CPolyDrawable drawable(L"drawing");
			Gdiplus::Color defColor = Gdiplus::Color::Black;
			Assert::AreEqual(defColor.GetValue(), drawable.GetColor().GetValue());
			Gdiplus::Color newColor = Gdiplus::Color::Red;
			drawable.SetColor(newColor);
			Assert::AreEqual(newColor.GetValue(), drawable.GetColor().GetValue());

		}

	};
}