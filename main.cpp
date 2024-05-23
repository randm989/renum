#include <iostream>
#include <vector>

#include "Code/Headers/SmartEnums.hpp"

using namespace std;

int main()
{
	vector<FActorMessage> Msgs = 
		{
			FActorMessage::Death{},
			FActorMessage::Damage{32},
			FActorMessage::Stunned{45.5},
			FActorMessage::ReceiveMoney{"admin", 10000}
		};

	for (const auto& Msg : Msgs)
		SmartEnum::Match(Msg,
		[](FActorMessage::Death) { cout << "Death!" << endl; },
		[](FActorMessage::Damage msg) { cout << "Damage: " << msg.amount << endl; },
		[](FActorMessage::Stunned msg) { cout << "Stunned: " << msg.duration << endl; },
		[](FActorMessage::ReceiveMoney msg) { cout << "ReceiveMoney: " << msg.sourceName << " " << msg.amount << endl; });

	
	SmartEnum::Match(FWebMessage{FWebMessage::Reroute{"www.kagi.com"}},
		[](FWebMessage::Success) { cout << "Success" << endl; },
		[](FWebMessage::Failure msg) { cout << "Failure: " << msg.reason << endl; },
		[](FWebMessage::Retry msg) {cout << "Retry count: " << msg.attempts << endl; },
		[](FWebMessage::Reroute msg) { cout << "Reroute to: " << msg.URL << endl; });

	std::cout << "Hello world" << std::endl;
}
