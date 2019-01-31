/**
 * \file MachineFactory1.cpp
 *
 * \author Daewoo Maurya
 */

#include "stdafx.h"
#include "MachineFactory1.h"
#include "Shape.h"
#include "Motor.h"
#include "Pulley.h"
#include "Cam.h"

using namespace std;

CMachineFactory1::CMachineFactory1()
{
}


CMachineFactory1::~CMachineFactory1()
{
}

/**
 * Create a machine object
 * \returns Object of type CMachine
 */
std::shared_ptr<CWorkingMachine> CMachineFactory1::CreateMachine()
{
	// The machine itself
	auto machine = make_shared<CWorkingMachine>();


	// The base
	auto base = make_shared<CShape>();
	int wid = 550;
	base->Rectangle(-wid / 2, 0, wid, 40);
	base->SetImage(L"images/base.png");
	machine->AddComponent(base);

	auto post1 = make_shared<CShape>();
	post1->Rectangle(-210, -40, 20, 120);
	post1->SetColor(Gdiplus::Color::DarkBlue);
	machine->AddComponent(post1);


	auto motor = make_shared<CMotor>(20);
	motor->SetPosition(Gdiplus::Point(-150, -78));

	// The pulley driven by the motor
	// Radius=15pixels
	auto pulley1 = make_shared<CPulley>(15);
	pulley1->SetImage(L"images/pulley2.png");
	pulley1->SetPosition(Gdiplus::Point(-150, -78 - motor->GetRadius()/2));
	pulley1->SetPhase(0.1);	// Rotate it a little bit
	machine->AddComponent(pulley1);

	// Post to hold the first pulley
	// Must be added before the motor pulley so it draws behind the belt

	


	

	// The pulley driven by the motor
	// Radius=15pixels
	auto pulley2 = make_shared<CPulley>(40);
	pulley2->SetImage(L"images/pulley2.png");
	pulley2->SetPosition(Gdiplus::Point(-200, -150));
	pulley2->SetPhase(0.1);	// Rotate it a little bit
	machine->AddComponent(pulley2);

	motor->GetSource()->AddSink(pulley1->GetSink());

	pulley1->Drive(pulley2);
	pulley1->GetSource()->AddSink(pulley2->GetSink());
	
	// The flag
	auto flag = make_shared<CShape>();
	flag->AddPoint(-50, 0);
	flag->AddPoint(-50, -100);
	flag->AddPoint(5, -100);
	flag->AddPoint(5, 0);
	flag->SetImage(L"images/flag.png");
	flag->SetPosition(Gdiplus::Point(pulley2->GetPosition().X, pulley2->GetPosition().Y));
	machine->AddComponent(flag);

	pulley2->GetSource()->AddSink(flag->GetSink());

	auto pulley3 = make_shared<CPulley>(15);
	pulley3->SetImage(L"images/pulley2.png");
	pulley3->SetPosition(Gdiplus::Point(-200, -150));
	pulley3->SetPhase(0.1);	// Rotate it a little bit
	machine->AddComponent(pulley3);

	pulley2->Drive(pulley3);
	pulley2->GetSource()->AddSink(pulley3->GetSink());
	
	machine->AddMotor(motor);

	auto drivePulley = pulley3;

	int pulleyDistance[] = { -90, -20, 50, 120, 190 };

	// A cam
	//auto cam = make_shared<CCam>(70, 24);
	//cam->SetImage(L"images/chrome.png", true);
	//cam->SetPhase(-0.25);
	//cam->SetPosition(Gdiplus::Point(-100, -80));
	//cam->SetPinSize(15);

	//cam->AddPin(1);
	//cam->AddPin(2);
	//cam->AddPin(4);
	//cam->Build();
	//machine->AddComponent(cam);
	//pulley2->GetSource()->AddSink(cam->GetSink());


	for (int i = 0; i < 5; i++)
	{
		int pulleyPos = pulleyDistance[i];

		auto post = make_shared<CShape>();
		post->Rectangle(pulleyPos - 10, -40, 20, 120);
		post->SetColor(Gdiplus::Color::Brown);
		machine->AddComponent(post);

		//8888888
		// A pulley that is driven by the previous stage
		// Radius=35pixels
		auto drivenPulley = make_shared<CPulley>(35);
		drivenPulley->SetImage(L"images/pulley.png");
		drivenPulley->SetPosition(Gdiplus::Point(pulleyPos, -150));
		machine->AddComponent(drivenPulley);

		drivePulley->Drive(drivenPulley);

		// A pulley to drive the next stage
		drivePulley = make_shared<CPulley>(35);
		drivePulley->SetImage(L"images/pulley.png");
		drivePulley->SetPosition(Gdiplus::Point(pulleyPos, -150));
		drivePulley->SetPhase(0.1);
		machine->AddComponent(drivePulley);

		drivenPulley->GetSource()->AddSink(drivePulley->GetSink());

		// A cam
		auto cam = make_shared<CCam>(20, 16);
		cam->SetImage(L"images/hammered-copper1.png", true);
		//cam->SetPhase(0.25);
		cam->SetPosition(drivePulley->GetPosition());

		machine->AddComponent(cam);
		drivePulley->GetSource()->AddSink(cam->GetSink());

		cam->AddPin(1);
		cam->AddPin(2);
		cam->AddPin(4);
		cam->Build();

		auto roller = make_shared<CRoller>(5, 0.25);
		roller->SetImage(L"images/roller.png");
		cam->AddRoller(roller);
		machine->AddComponent(roller);

		// The mallet that is driven by the roller
		auto mallet = make_shared<CShape>();
		wid = 8;
		mallet->Rectangle(-wid / 2, 0, wid, 100);
		mallet->SetImage(L"images/mallet.png");
		machine->AddComponent(mallet);
		roller->AddPositionSink(mallet);


		//8888888
	}


	return machine;
}
