#pragma once

#include <string>
#include <variant>

namespace EMessages
{
	struct SuccessMessage
	{
		
	};

	struct RerouteMessage
	{
		std::string URL;
	};
}

using EMessage = std::variant<EMessages::SuccessMessage, EMessages::RerouteMessage>;

template <typename... Ts> struct Overloaded : Ts... { using Ts::operator()...; };
template <typename... Ts> Overloaded(Ts...) -> Overloaded<Ts...>;

template <typename V, typename... Handlers>
void Match(V enumVariant, Handlers... handlers)
{
	visit( Overloaded{std::forward<Handlers>(handlers)...}, enumVariant);
}