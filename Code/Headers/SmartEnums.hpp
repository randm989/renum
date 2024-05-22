#pragma once

#include <string>
#include <variant>

// namespace EMessages
// {
// 	struct SuccessMessage
// 	{
		
// 	};

// 	struct RerouteMessage
// 	{
// 		std::string URL;
// 	};
// }

// Macro to define an empty struct
#define DEFINE_ENUM_VALUE(Name) struct Name {}

// Macro to define a struct with parameters
#define DEFINE_ENUM_VALUE_WITH_PARAMS(Name, ...) struct Name { __VA_ARGS__; }

#define DEFINE_SMART_ENUM(NamespaceName, ...) \
namespace NamespaceName { \
    __VA_ARGS__ \
}

#define DECLARE_SMART_ENUM_INSTANCE_TYPE(Name, ...) \
using Name = std::variant<__VA_ARGS__>;

DEFINE_SMART_ENUM(EMessages,
	DEFINE_ENUM_VALUE(SuccessMessage);
    DEFINE_ENUM_VALUE_WITH_PARAMS(RerouteMessage, std::string URL);
    DEFINE_ENUM_VALUE_WITH_PARAMS(MultiMessage, std::string URL; int integer);
)
DECLARE_SMART_ENUM_INSTANCE_TYPE(EMessage, EMessages::SuccessMessage, EMessages::RerouteMessage, EMessages::MultiMessage)

template <typename... Ts> struct Overloaded : Ts... { using Ts::operator()...; };
template <typename... Ts> Overloaded(Ts...) -> Overloaded<Ts...>;

template <typename V, typename... Handlers>
void Match(V enumVariant, Handlers... handlers)
{
	visit( Overloaded{std::forward<Handlers>(handlers)...}, enumVariant);
}