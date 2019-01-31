/**
* \file CDrawableTest.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Drawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	class CDrawableMock : public CDrawable
	{
	public:
		CDrawableMock(const std::wstring &name) : CDrawable(name) {}

		virtual void Draw(Gdiplus::Graphics *graphics) override {}
		virtual bool HitTest(Gdiplus::Point pos) override { return false; }

	};

	TEST_CLASS(EmptyTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCDrawableConstructor)
		{
			// This is an empty test just to ensure the system is working
			CDrawableMock drawable(L"drawing");
			Assert::AreEqual(std::wstring(L"drawing"), drawable.GetName());
		}
		TEST_METHOD(TestCDrawablePositionDefaultValue)
		{
			CDrawableMock drawable(L"drawing");
			Assert::AreEqual(0, drawable.GetPosition().X);
			Assert::AreEqual(0, drawable.GetPosition().Y);
			Gdiplus::Point newValue = Gdiplus::Point(120, 120);
			drawable.SetPosition(newValue);
			Assert::AreEqual(120, drawable.GetPosition().X);
			Assert::AreEqual(120, drawable.GetPosition().Y);
		}
		TEST_METHOD(TestCDrawableRotationDefaultValue)
		{
			CDrawableMock drawable(L"drawing");
			Assert::AreEqual(0.0, drawable.GetRotation());
			double a = 0.333;
			double b = acos(cos(a));
			drawable.SetRotation(b);
			Assert::AreEqual(a, drawable.GetRotation(), 0.000000001);
		}
		TEST_METHOD(TestCDrawableAssociation)
		{
			CDrawableMock body(L"Body");
			auto arm = std::make_shared<CDrawableMock>(L"Arm");
			auto leg = std::make_shared<CDrawableMock>(L"Leg");

			Assert::IsNull(arm->GetParent());
			Assert::IsNull(leg->GetParent());

			body.AddChild(arm);
			body.AddChild(leg);

			Assert::IsTrue(arm->GetParent() == &body);
			Assert::IsTrue(leg->GetParent() == &body);
		}

	};
}