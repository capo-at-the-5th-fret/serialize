#include <doctest/doctest.h>
#include <cstdio>
#include <string_view>

import serialize;

TEST_CASE("file_endpoint")
{
    constexpr std::string_view text_out = { "This is a test" };

    {
        FILE* file = nullptr;
        auto result = fopen_s(&file, "file_endpoint_tests.bin", "wb");

        file_sink fs{ file };

        fs.write_data(text_out.data(), text_out.size());

        fclose(file);
    }

    {
        FILE* file = nullptr;
        auto result = fopen_s(&file, "file_endpoint_tests.bin", "rb");

        file_source fs{ file };

        std::array<char, text_out.size()> buffer = {};
        fs.read_data(buffer.data(), text_out.size());

        std::string text_in{ buffer.data(), text_out.size() };
        REQUIRE(text_in == text_out);
    }

}
