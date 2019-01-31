/**
* \file FishBeta.h
*
* \author Jaiwant Bhushan
*
* Class the implements a Beta fish
*/


#pragma once
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Item.h"
#include "Aquarium.h"
#include "FishBeta.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{

	/** Mock class for testing CItem */
	class CItemMock : public CItem
	{
	public:
		virtual void Draw(Gdiplus::Graphics *graphics) {}
		CItemMock(CAquarium *aquarium) : CItem(aquarium) {}
	};

	TEST_CLASS(CFishBetaHitTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TwoImagesOnTopHitTest)
		{
			// Create a fish to test
			CAquarium aquarium;

			//Make the two fish the same location
			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish2);
	

			// It should return the first fish
			Assert::IsTrue(aquarium.HitTest(100, 200) == fish1);
		}

	};
}