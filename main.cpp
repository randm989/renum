#include <iostream>
#include <vector>

#include "Code/Headers/SmartEnums.hpp"

using namespace std;

DECLARE_SMART_ENUM(FActorMessage,
	Death, {},
	Damage, {int amount;},
	Stunned, {float duration;},
	ReceiveMoney, {std::string sourceName; int amount;})


DECLARE_SMART_ENUM(FWebMessage,
	Success, {},
	Failure, {std::string reason;},
	Reroute, {std::string URL;},
	Retry, {int attempts;})

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
		[](FActorMessage::Stunned msg) { cout << "Stunned: " << msg.duration << endl; });
	
	SmartEnum::Match(FWebMessage{FWebMessage::Reroute{"www.kagi.com"}},
		[](FWebMessage::Success) { cout << "Success" << endl; },
		[](FWebMessage::Failure msg) { cout << "Failure: " << msg.reason << endl; },
		[](FWebMessage::Retry msg) {cout << "Retry count: " << msg.attempts << endl; },
		[](FWebMessage::Reroute msg) { cout << "Reroute to: " << msg.URL << endl; });

	std::cout << "Hello world" << std::endl;
}
