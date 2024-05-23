#pragma once

#include <string>
#include <variant>

#if __cplusplus >= 202002L
#define CPP20_OR_LATER
#endif

struct FActorMessage
{
public:
	struct Death {};
	struct Damage {int amount;};
	struct Stunned {float duration;};
	struct ReceiveMoney {std::string sourceName; int amount;};

	using Variant = std::variant<Death, Damage, Stunned, ReceiveMoney>;
	operator Variant() const { return _variant; }

	template <typename T>
	FActorMessage(T&& init) : _variant(init) {} 
private:
	Variant _variant;
};

struct FWebMessage
{
public:
	struct Success {};
	struct Failure {std::string reason;};
	struct Reroute {std::string URL;};
	struct Retry {int attempts;};

	using Variant = std::variant<Success, Failure, Reroute, Retry>;
	operator Variant() const { return _variant; }

	template <typename T>
		requires std::is_same_v<T, Success> ||
				std::is_same_v<T, Failure> ||
				std::is_same_v<T, Reroute> ||
				std::is_same_v<T, Retry>
	FWebMessage(T&& init) : _variant(std::forward<T>(init)) {} 
private:
	Variant _variant;
};

namespace SmartEnum
{
	// Defines a struct that inherits from a list of types, and inherits all of their respective () operators
	template <typename... Ts> struct Overloaded : Ts... { using Ts::operator()...; };

	// this is a deduction guide, a new paradigm introduced in C++17
	// it's giving helpful instructions to the compiler. this one is saying that 
	// When the Overloaded struct is being constructed with a list of parameters (represented by Ts...)
	// then the appropriate return type is Overloaded<Ts...>
	// I've never seen this used outside of this paradigm, and I hear that it's unnecessary in C++20
#ifndef CPP20_OR_LATER
	template <typename... Ts> Overloaded(Ts...) -> Overloaded<Ts...>;
#endif

	template <typename... Handlers>
	void Match(FWebMessage::Variant enumVariant, Handlers... handlers)
	{
		std::visit( Overloaded{std::forward<Handlers>(handlers)...}, enumVariant);
	}

	template <typename V, typename... Handlers>
	void Match(V enumVariant, Handlers... handlers)
	{
		using Variant = typename std::decay_t<V>::Variant;
		std::visit( Overloaded{std::forward<Handlers>(handlers)...}, static_cast<Variant>(enumVariant));
	}	
}