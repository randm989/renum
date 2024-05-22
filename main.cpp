#include <iostream>
#include <vector>

#include "Code/Headers/SmartEnums.hpp"

using namespace std;

int main()
{
	vector<EMessage> Msgs = 
		{
			EMessages::RerouteMessage{"ReroutedURL"},
			EMessages::RerouteMessage{"Rerouted2"},
			EMessages::SuccessMessage{},
			EMessages::MultiMessage{"google?", 42560}
		};

	for (const auto& Msg : Msgs)
		Match(Msg,
		[](EMessages::SuccessMessage) { cout << "Success!" << endl; },
		[](EMessages::RerouteMessage msg) { cout << "Reroute: " << msg.URL << endl; },
		[](EMessages::MultiMessage msg) { cout << "MultiMessage: " << msg.integer << " " << msg.URL << endl; });

	std::cout << "Hello world" << std::endl;
}
