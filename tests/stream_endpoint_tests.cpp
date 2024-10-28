#include <doctest/doctest.h>
#include <fstream>
#include <string_view>

import serialize;

TEST_CASE("stream_endpoint")
{
    constexpr std::string_view text_out = { "This is a test" };

    {
        std::ofstream os;
        os.open("stream_endpoint_tests.bin", std::ios::binary);

        stream_sink fs{ os };

        fs.write_data(text_out.data(), text_out.size());

        os.close();
    }

    {
        std::ifstream is;
        is.open("stream_endpoint_tests.bin", std::ios::binary);

        stream_source fs{ is };

        std::array<char, text_out.size()> buffer = {};
        fs.read_data(buffer.data(), text_out.size());

        std::string text_in{ buffer.data(), text_out.size() };
        REQUIRE(text_in == text_out);
    }

}
