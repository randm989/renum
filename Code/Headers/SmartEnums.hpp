/*****
 * Author: Josh Rutz
 * Date: May 24, 2024
 * Description: Smart Enum utility class
*/

#pragma once

#include <string>
#include <variant>
#include <iostream>
#include <typeinfo>

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

// Macro for 5 parameters
#define DECLARE_SMART_ENUM_FiveParams(EnumName, FirstOptionName, FirstOptionBody, SecondOptionName, SecondOptionBody, ThirdOptionName, ThirdOptionBody, FourthOptionName, FourthOptionBody, FifthOptionName, FifthOptionBody) \
struct EnumName { \
    struct FirstOptionName FirstOptionBody; \
    struct SecondOptionName SecondOptionBody; \
    struct ThirdOptionName ThirdOptionBody; \
    struct FourthOptionName FourthOptionBody; \
    struct FifthOptionName FifthOptionBody; \
    using VariantType = std::variant<FirstOptionName, SecondOptionName, ThirdOptionName, FourthOptionName, FifthOptionName>; \
    template <typename T, typename = std::enable_if_t<!std::is_same_v<std::decay_t<T>, EnumName>>> \
	EnumName(T&& v) : Variant(std::forward<T>(v)) {} \
    operator VariantType() const { return Variant; } \
private: \
    VariantType Variant; \
};

// Macro for 6 parameters
#define DECLARE_SMART_ENUM_SixParams(EnumName, FirstOptionName, FirstOptionBody, SecondOptionName, SecondOptionBody, ThirdOptionName, ThirdOptionBody, FourthOptionName, FourthOptionBody, FifthOptionName, FifthOptionBody, SixthOptionName, SixthOptionBody) \
struct EnumName { \
    struct FirstOptionName FirstOptionBody; \
    struct SecondOptionName SecondOptionBody; \
    struct ThirdOptionName ThirdOptionBody; \
    struct FourthOptionName FourthOptionBody; \
    struct FifthOptionName FifthOptionBody; \
    struct SixthOptionName SixthOptionBody; \
    using VariantType = std::variant<FirstOptionName, SecondOptionName, ThirdOptionName, FourthOptionName, FifthOptionName, SixthOptionName>; \
    template <typename T, typename = std::enable_if_t<!std::is_same_v<std::decay_t<T>, EnumName>>> \
	EnumName(T&& v) : Variant(std::forward<T>(v)) {} \
    operator VariantType() const { return Variant; } \
private: \
    VariantType Variant; \
};

// Macro for 7 parameters
#define DECLARE_SMART_ENUM_SevenParams(EnumName, FirstOptionName, FirstOptionBody, SecondOptionName, SecondOptionBody, ThirdOptionName, ThirdOptionBody, FourthOptionName, FourthOptionBody, FifthOptionName, FifthOptionBody, SixthOptionName, SixthOptionBody, SeventhOptionName, SeventhOptionBody) \
struct EnumName { \
    struct FirstOptionName FirstOptionBody; \
    struct SecondOptionName SecondOptionBody; \
    struct ThirdOptionName ThirdOptionBody; \
    struct FourthOptionName FourthOptionBody; \
    struct FifthOptionName FifthOptionBody; \
    struct SixthOptionName SixthOptionBody; \
    struct SeventhOptionName SeventhOptionBody; \
    using VariantType = std::variant<FirstOptionName, SecondOptionName, ThirdOptionName, FourthOptionName, FifthOptionName, SixthOptionName, SeventhOptionName>; \
    template <typename T, typename = std::enable_if_t<!std::is_same_v<std::decay_t<T>, EnumName>>> \
	EnumName(T&& v) : Variant(std::forward<T>(v)) {} \
    operator VariantType() const { return Variant; } \
private: \
    VariantType Variant; \
};

// Macro for 8 parameters
#define DECLARE_SMART_ENUM_EightParams(EnumName, FirstOptionName, FirstOptionBody, SecondOptionName, SecondOptionBody, ThirdOptionName, ThirdOptionBody, FourthOptionName, FourthOptionBody, FifthOptionName, FifthOptionBody, SixthOptionName, SixthOptionBody, SeventhOptionName, SeventhOptionBody, EighthOptionName, EighthOptionBody) \
struct EnumName { \
    struct FirstOptionName FirstOptionBody; \
    struct SecondOptionName SecondOptionBody; \
    struct ThirdOptionName ThirdOptionBody; \
    struct FourthOptionName FourthOptionBody; \
    struct FifthOptionName FifthOptionBody; \
    struct SixthOptionName SixthOptionBody; \
    struct SeventhOptionName SeventhOptionBody; \
    struct EighthOptionName EighthOptionBody; \
    using VariantType = std::variant<FirstOptionName, SecondOptionName, ThirdOptionName, FourthOptionName, FifthOptionName, SixthOptionName, SeventhOptionName, EighthOptionName>; \
    template <typename T, typename = std::enable_if_t<!std::is_same_v<std::decay_t<T>, EnumName>>> \
	EnumName(T&& v) : Variant(std::forward<T>(v)) {} \
    operator VariantType() const { return Variant; } \
private: \
    VariantType Variant; \
};

// Macro for 9 parameters
#define DECLARE_SMART_ENUM_NineParams(EnumName, FirstOptionName, FirstOptionBody, SecondOptionName, SecondOptionBody, ThirdOptionName, ThirdOptionBody, FourthOptionName, FourthOptionBody, FifthOptionName, FifthOptionBody, SixthOptionName, SixthOptionBody, SeventhOptionName, SeventhOptionBody, EighthOptionName, EighthOptionBody, NinthOptionName, NinthOptionBody) \
struct EnumName { \
    struct FirstOptionName FirstOptionBody; \
    struct SecondOptionName SecondOptionBody; \
    struct ThirdOptionName ThirdOptionBody; \
    struct FourthOptionName FourthOptionBody; \
    struct FifthOptionName FifthOptionBody; \
    struct SixthOptionName SixthOptionBody; \
    struct SeventhOptionName SeventhOptionBody; \
    struct EighthOptionName EighthOptionBody; \
    struct NinthOptionName NinthOptionBody; \
    using VariantType = std::variant<FirstOptionName, SecondOptionName, ThirdOptionName, FourthOptionName, FifthOptionName, SixthOptionName, SeventhOptionName, EighthOptionName, NinthOptionName>; \
    template <typename T, typename = std::enable_if_t<!std::is_same_v<std::decay_t<T>, EnumName>>> \
	EnumName(T&& v) : Variant(std::forward<T>(v)) {} \
    operator VariantType() const { return Variant; } \
private: \
    VariantType Variant; \
};


// Helper macro to select the correct macro based on the number of parameters
// The number of arguments in get macro should be equal to the number of params we can handle multiplied by 2, and add 1 more for the smart enum event name
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,NAME,...) NAME
#define DECLARE_SMART_ENUM(...) GET_MACRO(__VA_ARGS__, \
			DECLARE_SMART_ENUM_NineParams, _, \
			DECLARE_SMART_ENUM_EightParams, _, \
			DECLARE_SMART_ENUM_SevenParams, _, \
			DECLARE_SMART_ENUM_SixParams, _, \
			DECLARE_SMART_ENUM_FiveParams, _, \
			DECLARE_SMART_ENUM_FourParams, _, \
			DECLARE_SMART_ENUM_ThreeParams, _, \
			DECLARE_SMART_ENUM_TwoParams, _, \
			DECLARE_SMART_ENUM_OneParam)(__VA_ARGS__)

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

#ifndef CPP20_OR_LATER

	// this is a deduction guide, a new paradigm introduced in C++17
	// it's giving helpful instructions to the compiler. this one is saying that 
	// When the Overloaded struct is being constructed with a list of parameters (represented by Ts...)
	// then the appropriate return type is Overloaded<Ts...>
	// I've never seen this used outside of this paradigm, and I hear that it's unnecessary in C++20
	template <typename... Ts> Overloaded(Ts...) -> Overloaded<Ts...>;

	// Trait to detect if a type has a nested type named VariantType
	template <typename T, typename = void>
	struct has_variant_type : std::false_type {};

	// this uses SFINAE to return a constexpr member type called value underneath
	// true_type or false_type which can be used in an if constexpr() block
	template <typename T>
	struct has_variant_type<T, std::void_t<typename T::VariantType>> : std::true_type {};

	template <typename T>
	constexpr bool has_variant_type_v = has_variant_type<T>::value;

#else
	// C++ 20 introduces concepts which negates the need for
	// the SFINAE pattern used in C++17
	template <typename T>
	concept has_variant_type_v = requires { typename T::VariantType; };
#endif

	template <typename Event, typename... Handlers>
	auto Match(Event&& event, Handlers... handlers) -> decltype(auto)
	{
		using EventType = std::decay_t<Event>;
		if constexpr (has_variant_type_v<EventType>) 
		{
			using VariantType = typename EventType::VariantType;
			return std::visit(Overloaded{std::forward<Handlers>(handlers)...}, static_cast<VariantType>(std::forward<Event>(event)));
		} 
		else 
		{
			return std::visit(Overloaded{std::forward<Handlers>(handlers)...}, std::variant<EventType>(std::forward<Event>(event)));
		}
	}	
}