#include <print>
import serialize;

int main()
{
    f("abc");

    const std::uint16_t w = 0x01'02u;
    const auto bytes =
        std::bit_cast<std::array<unsigned char, sizeof(std::uint16_t)>>(w);
    //std::println("byte 0 = 0x{:04x}, byte 1 = 0x{:04x}", bytes[0], bytes[1]);

    auto v = from_little_endian<std::uint16_t>(bytes);
    auto u = from_big_endian(w);
    std::println("little endian = 0x{:04x}, big endian = 0x{:04x}", v, u);

    binary_writer<endian_order::little> writer;
    writer.write(w);

    return 0;

    /*const std::uint32_t x = 0x01020304u;
    auto y = to_little_endian(x);
    auto z = to_big_endian(x);
    std::println("little endian = 0x{:x}, big endian = 0x{:x}", y, z);

    const std::uint64_t a = 0x0102030405060708ull;
    auto b = to_little_endian(a);
    auto c = to_big_endian(a);
    std::println("little endian = 0x{:x}, big endian = 0x{:x}", b, c);*/
}
