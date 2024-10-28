module;

#include <iostream>

// TEMP CODE
#include <optional>
// END TEMP CODE

export module serialize:stream_endpoint;

import :endpoint;

export class stream_sink final : public sink_interface
{
public:
    explicit stream_sink(std::ostream& os) : strm_{ os }
    {
        //easy_ensure_arg(stream);
    }

    std::ostream& stream() const
    {
        return strm_;
    }

private:
    void write_data_impl(void const* data, std::size_t size)
    {
        // TEMP CODE
        const std::optional<std::size_t> data_size{ size };
        // END TEMP CODE
        // FIX: Write in chunks instead of throwing?
        /*if (const auto data_size = easy::narrow_check<std::streamsize>(size);
            !data_size.has_value())
        {
            easy::throw_ex(easy::make_narrowing_error_ex<std::streamsize>(
                easy_variable(size)));
        }
        else*/
        {
            strm_.write(static_cast<char const*>(data), data_size.value());
        }
    }

    void flush_impl()
    {
        strm_.flush();
    }

    std::ostream& strm_;

    friend class sink_interface;
};

export class stream_source final : public source_interface
{
public:
    explicit stream_source(std::istream& is) : strm_{ is }
    {
        //easy_ensure_arg(stream);
    }

    std::istream& stream() const
    {
        return strm_;
    }

private:
    void read_data_impl(void* data, std::size_t size)
    {
        // TEMP CODE
        const std::optional<std::size_t> data_size{ size };
        // END TEMP CODE

        // FIX: Read in chunks instead of throwing?
        /*if (const auto dataSize = easy::narrow_check<std::streamsize>(size);
            !dataSize.has_value())
        {
            easy::throw_ex(easy::make_narrowing_error_ex<std::streamsize>(
                easy_variable(size)));
        }
        else*/
        {
            strm_.read(reinterpret_cast<char*>(data), data_size.value());
        }
    }

    std::istream& strm_;

    friend class source_interface;
};
