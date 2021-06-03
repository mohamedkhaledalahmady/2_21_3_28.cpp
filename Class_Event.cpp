#pragma once
#include<iostream>
using namespace std;

class Event
{
private:
	char EventName[20];
	char CustomerName[20];
	int GuestCount;
	float EventDuration;
	int NumberOfWaiters;
	float CostPerWaiter;
	float FoodCost;
	float TotalCost;
	float DepositAmount;
	bool over_name, over_customer;

public:
	Event();
	void getEventName();
	void getCustomerName();
	void getGuestCount();
	void getEventDuration();
	void CalcualteCost();
	void PrintInfo();
	~Event();
};

Event::Event()
{
	cout << "\t\t------------ Welcome To Our Program ------------\n\n\n";
	//initial values
	strcpy_s(EventName, " any string ");
	strcpy_s(CustomerName, " any string ");
	GuestCount = 0;
	EventDuration = 0.0;
	NumberOfWaiters = 0;
	CostPerWaiter = 0.0;
	FoodCost = 0.0;
	TotalCost = 0.0;
	DepositAmount = 0.0;
	over_name = over_customer = 0;
}

void Event::getEventName()
{
	cout << "Enter name of event: ";
	//if EventName grater than max size over_name will contain 1
	over_name = !(bool(cin.getline(EventName, 20)));
}

void Event::getCustomerName()
{
	if (over_name)
	{
		cin.clear(); //to clear the error flags which are set when cin fails to interpret the input.
		cin.ignore(1000, '\n'); //  to remov the input contents that could caused the read failure.
	}
	cout << "Enter name of customer: ";
	//if CustomerName grater than max size over_customer will contain 1
	over_customer = !(bool(cin.getline(CustomerName, 20)));
}

void Event::getGuestCount()
{
	if (over_customer)
	{
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cout << "Enter number of guests: ";
	float temp;
	while (!(cin >> temp && int(temp) > 0 && int(temp) == temp))
	{
		cout << "\n\tInvalid input please enter intrger positive numbers !!\n\n";
		cout << "Enter number of guests: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	GuestCount = int(temp);
	cin.clear();
	cin.ignore(1000, '\n');
}

void Event::getEventDuration()
{
	cout << "Enter event duration in minutes: ";
	while (!(cin >> EventDuration && EventDuration > 0))
	{
		cout << "\n\tInvalid input please enter  positive numbers !!\n\n";
		cout << "Enter event duration in minutes: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
}

void Event::CalcualteCost()
{
	NumberOfWaiters = ceil(GuestCount / 20.0);
	if (EventDuration >= 60)
	{
		int num_hours = EventDuration / 60; //to store number of hours
		CostPerWaiter = 46.5 * num_hours + EventDuration - (num_hours * 60.0);
	}
	else
	{
		CostPerWaiter = 46.5 * (EventDuration / 60);
	}
	FoodCost = GuestCount * 54.5;
	TotalCost = CostPerWaiter + FoodCost;
	DepositAmount = TotalCost * 0.25;
}

void Event::PrintInfo()
{
	cout << "\n\n\t\t\t--------- Results -------\n\n";
	cout << "Event: " << EventName << "\n\n";
	cout << "Customer Name: " << CustomerName << "\n\n";
	cout << "Number of Waiters: " << NumberOfWaiters << "\n\n";
	cout << "The Cost per Waiter: " << CostPerWaiter << "\n\n";
	cout << "The Cost for Food: " << FoodCost << "\n\n";
	cout << "The Total Cost: " << TotalCost << "\n\n";
	cout << "The Deposit needed is: " << DepositAmount << "\n\n";
}

Event::~Event()
{
	cout << "\n\n\t\t\t------------ Good Event ------------\n\n";
}

//main function
int main()
{
	Event E;
	E.getEventName();
	E.getCustomerName();
	E.getGuestCount();
	E.getEventDuration();
	E.CalcualteCost();
	E.PrintInfo();

	return 0;
}