module;

#include <cstdint>
#include <format>
#include <bit>
#include <print>
#include <array>

export module serialize:writer;

export class writer_interface
{
public:
    template <typename Self, typename T>
    void write(this Self&& self, const T& value)
    {
        if constexpr (std::integral<T>)
        {
            self.write_integral(value);
        }
    }
};

export enum class endian_order
{
    little,
    big
};

export template <std::integral T>
T from_little_endian(const std::array<unsigned char, sizeof(T)>& bytes)
{
    if constexpr (std::same_as<T, std::uint8_t>)
    {
        return bytes[0];
    }
    else
    {
        if constexpr (std::same_as<T, std::uint16_t>)
        {
            return (bytes[0]<<0) | (bytes[1]<<8);
        }
        else if constexpr (std::same_as<T, std::uint32_t>)
        {
            return
                (bytes[0]<<0) |
                (bytes[1]<<8) |
                (bytes[2]<<16) |
                (bytes[3]<<24);
        }
        else if constexpr (std::same_as<T, std::uint64_t>)
        {
            return
                (static_cast<std::uint64_t>(bytes[0])<<0) |
                (static_cast<std::uint64_t>(bytes[1])<<8) |
                (static_cast<std::uint64_t>(bytes[2])<<16) |
                (static_cast<std::uint64_t>(bytes[3])<<24) |
                (static_cast<std::uint64_t>(bytes[4])<<32) |
                (static_cast<std::uint64_t>(bytes[5])<<40) |
                (static_cast<std::uint64_t>(bytes[6])<<48) |
                (static_cast<std::uint64_t>(bytes[7])<<56);
        }
        else
        {
            static_assert(false, "Unsupported type");
        }
    }
};

export template <std::integral T>
T from_big_endian(T value)
{
    if constexpr (std::same_as<T, std::uint8_t>)
    {
        return value;
    }
    else
    {
        const auto bytes =
            std::bit_cast<std::array<unsigned char, sizeof(T)>>(value);

        if constexpr (std::same_as<T, std::uint16_t>)
        {
            return (bytes[1]<<0) | (bytes[0]<<8);
        }
        else if constexpr (std::same_as<T, std::uint32_t>)
        {
            return
                (bytes[3]<<0) |
                (bytes[2]<<8) |
                (bytes[1]<<16) |
                (bytes[0]<<24);
        }
        else if constexpr (std::same_as<T, std::uint64_t>)
        {
            return
                (static_cast<std::uint64_t>(bytes[7])<<0) |
                (static_cast<std::uint64_t>(bytes[6])<<8) |
                (static_cast<std::uint64_t>(bytes[5])<<16) |
                (static_cast<std::uint64_t>(bytes[4])<<24) |
                (static_cast<std::uint64_t>(bytes[3])<<32) |
                (static_cast<std::uint64_t>(bytes[2])<<40) |
                (static_cast<std::uint64_t>(bytes[1])<<48) |
                (static_cast<std::uint64_t>(bytes[0])<<56);
        }
        else
        {   
            static_assert(false, "Unsupported type");
        }
    }
}

export template <endian_order EndianOrder>
class binary_writer : public writer_interface
{
public:
    void write_integral(std::uint16_t value)
    {
        if constexpr (EndianOrder == endian_order::big)
        {
            std::println("write_integral({})", static_cast<int>(value));
        }
        else
        {
            std::println("write_integral({})", static_cast<int>(value));
        }
    }

    void write_integral(std::uint32_t value)
    {
        std::println("write_integral({})", static_cast<int>(value));
    }
};

using little_endian_writer = binary_writer<endian_order::little>;
using big_endian_writer = binary_writer<endian_order::big>;

#if 0
#endif

#if 0
// a CRTP trait
struct add_postfix_increment
{
    template<typename Self>
    auto operator++(this Self&& self, int)
    {
        auto tmp = self; // Self deduces to "some_type"
        ++self;
        return tmp;
    }
};
 
struct some_type : add_postfix_increment
{
    some_type& operator++() { ... }
};
#endif
