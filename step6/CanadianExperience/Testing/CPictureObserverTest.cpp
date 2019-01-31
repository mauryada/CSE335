/**
* \file CPictureObserverTest.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Picture.h"
#include "PictureObserver.h"
#include <memory>

using namespace std;
using namespace Gdiplus;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	class CPictureObserverMock : public CPictureObserver
	{
	public:
		bool mUpdated = false;
		CPictureObserverMock() : CPictureObserver() {}
		virtual void UpdateObserver() override { mUpdated = true; }

	};

	TEST_CLASS(CPictureObserverTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCPictureObserverConstruct)
		{
			// This is an empty test just to ensure the system is working
			CPictureObserverMock observer;
		}
		TEST_METHOD(TestCPictureSize)
		{
			CPicture picture;
			Assert::AreEqual(800, picture.GetSize().Width);
			Assert::AreEqual(600, picture.GetSize().Height);

			picture.SetSize(Size(123, 456));

			Assert::AreEqual(123, picture.GetSize().Width);
			Assert::AreEqual(456, picture.GetSize().Height);
		}
		TEST_METHOD(TestCPictureObserverOneObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);

			picture->UpdateObservers();

			Assert::IsTrue(observer.mUpdated);
		}
		TEST_METHOD(TestCPictureObserverGetObserver)
		{
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			observer.SetPicture(picture);

			Assert::IsTrue(picture == observer.GetPicture());
		}
		TEST_METHOD(TestCPictureObserverTwoObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture1 = make_shared<CPicture>();
			shared_ptr<CPicture> picture2 = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer1;
			CPictureObserverMock observer2;


			// And set it for the observer:
			observer1.SetPicture(picture1);
			observer2.SetPicture(picture2);

			picture1->UpdateObservers();
			picture2->UpdateObservers();

			Assert::IsTrue(observer1.mUpdated);
			Assert::IsTrue(observer2.mUpdated);
		}
		TEST_METHOD(TestCPictureObserverCreatedDestroyed)
		{
			
			shared_ptr<CPicture> picture = make_shared<CPicture>();
			{
				CPictureObserverMock observer2;
				// And set it for the observer:
				observer2.SetPicture(picture);
			}
		}
		

	};
}