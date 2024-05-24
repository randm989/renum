#pragma once

#include <string>
#include <variant>

#if __cplusplus >= 202002L
#define CPP20_OR_LATER
#endif

// Macro for 1 parameter
#define DECLARE_SMART_ENUM_OneParam(EnumName, FirstOptionName, FirstOptionBody) \
struct EnumName { \
    struct FirstOptionName FirstOptionBody; \
    using VariantType = std::variant<FirstOptionName>; \
    template<typename T> EnumName(T&& v) : Variant(std::move(v)) {} \
    operator VariantType() const { return Variant; } \
private: \
    VariantType Variant; \
};

// Macro for 2 parameters
#define DECLARE_SMART_ENUM_TwoParams(EnumName, FirstOptionName, FirstOptionBody, SecondOptionName, SecondOptionBody) \
struct EnumName { \
    struct FirstOptionName FirstOptionBody; \
    struct SecondOptionName SecondOptionBody; \
    using VariantType = std::variant<FirstOptionName, SecondOptionName>; \
    template<typename T> EnumName(T&& v) : Variant(std::move(v)) {} \
    operator VariantType() const { return Variant; } \
private: \
    VariantType Variant; \
};

// Macro for 3 parameters
#define DECLARE_SMART_ENUM_ThreeParams(EnumName, FirstOptionName, FirstOptionBody, SecondOptionName, SecondOptionBody, ThirdOptionName, ThirdOptionBody) \
struct EnumName { \
    struct FirstOptionName FirstOptionBody; \
    struct SecondOptionName SecondOptionBody; \
    struct ThirdOptionName ThirdOptionBody; \
    using VariantType = std::variant<FirstOptionName, SecondOptionName, ThirdOptionName>; \
    template<typename T> EnumName(T&& v) : Variant(std::move(v)) {} \
    operator VariantType() const { return Variant; } \
private: \
    VariantType Variant; \
};

// Macro for 4 parameters
#define DECLARE_SMART_ENUM_FourParams(EnumName, FirstOptionName, FirstOptionBody, SecondOptionName, SecondOptionBody, ThirdOptionName, ThirdOptionBody, FourthOptionName, FourthOptionBody) \
struct EnumName { \
    struct FirstOptionName FirstOptionBody; \
    struct SecondOptionName SecondOptionBody; \
    struct ThirdOptionName ThirdOptionBody; \
    struct FourthOptionName FourthOptionBody; \
    using VariantType = std::variant<FirstOptionName, SecondOptionName, ThirdOptionName, FourthOptionName>; \
    template <typename T, typename = std::enable_if_t<!std::is_same_v<std::decay_t<T>, EnumName>>> \
	EnumName(T&& v) : Variant(std::forward<T>(v)) {} \
    operator VariantType() const { return Variant; } \
private: \
    VariantType Variant; \
};

// Helper macro to select the correct macro based on the number of parameters
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,NAME,...) NAME
#define DECLARE_SMART_ENUM(...) GET_MACRO(__VA_ARGS__, DECLARE_SMART_ENUM_FourParams, _, DECLARE_SMART_ENUM_ThreeParams, _, DECLARE_SMART_ENUM_TwoParams, _, DECLARE_SMART_ENUM_OneParam)(__VA_ARGS__)

// Example usage:
DECLARE_SMART_ENUM(MessageEvent,
    EmptyMessage, { int x; },
    TextMessage, { std::string data; },
    NumberMessage, { int data; }
)

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

	template <typename V, typename... Handlers>
	void Match(V&& enumVariant, Handlers... handlers)
	{
		using VariantType = typename std::decay_t<V>::VariantType;

		auto unknownTypeHandler = [](auto&& arg) {
			using T = std::decay_t<decltype(arg)>;
			std::cout << "Unhandled type: " << typeid(T).name() << std::endl;
		};
		std::visit( Overloaded{unknownTypeHandler, std::forward<Handlers>(handlers)...}, static_cast<VariantType>(enumVariant));
	}	
}