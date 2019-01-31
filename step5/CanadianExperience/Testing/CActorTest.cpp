/**
* \file CActorTest.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Actor.h"

using namespace Gdiplus;
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

		TEST_METHOD(TestCActorConstructor)
		{
			// This is an empty test just to ensure the system is working
			CActor actor(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), actor.GetName());
		}
		TEST_METHOD(TestCActorEnabledDefaultValue)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(true, actor.IsEnabled());
			actor.SetEnabled(false);
			Assert::AreEqual(false, actor.IsEnabled());
		}
		TEST_METHOD(TestCActorClickableDefaultValue)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(true, actor.IsClickable());
			actor.SetClickable(false);
			Assert::AreEqual(false, actor.IsClickable());
		}
		TEST_METHOD(TestCActorPositionValue)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(0, actor.GetPosition().X);
			Assert::AreEqual(0, actor.GetPosition().Y);
			Gdiplus::Point newValue = Gdiplus::Point(120, 120);
			actor.SetPosition(newValue);
			Assert::AreEqual(120, actor.GetPosition().X);
			Assert::AreEqual(120, actor.GetPosition().Y);
		}

	};
}