module;

#include <cstdio>
//#include <easy/exception/ensure.h>
//#include "ptcore/io/file_exception.h"
//#include "ptcore/serialization/endpoint/sink.h"

export module serialize:file_endpoint;

import :endpoint;

export class file_sink final : public sink_interface
{
public:
    explicit file_sink(FILE* file) : file_{ file }
    {
        //easy_ensure_arg(file);
    }

    FILE* file() const
    {
        return file_;
    }

private:
    void write_data_impl(void const* data, std::size_t size)
    {
        const std::size_t elements_to_write = 1;

        if (const auto elements_written = fwrite(data, size, elements_to_write,
            file_); elements_written != elements_to_write)
        {
            //easy::throw_ex(ptcore::io::make_file_exception_ex(
              //  ptcore::io::write_failed_message, file_));
        }
    }

    void flush_impl()
    {
        if (const auto result = fflush(file_); result != 0)
        {
            //easy::throw_ex(ptcore::io::make_file_exception_ex(
              //  ptcore::io::flush_failed_message, file_));
        }
    }

    FILE* file_{ nullptr };

    friend class sink_interface;
};

export class file_source final : public source_interface
{
public:
    explicit file_source(FILE* file) : file_{ file }
    {
        //easy_ensure_arg(file);
    }

    FILE* file() const
    {
        return file_;
    }

private:
    void read_data_impl(void* data, std::size_t size)
    {
        const std::size_t elements_to_read = 1;

        if (const auto elements_read = fread(data, size, elements_to_read,
            file_); elements_read != elements_to_read)
        {
            //easy::throw_ex(ptcore::io::make_file_exception_ex(
              //  ptcore::io::read_failed_message, file_));
        }
    }

private:
    FILE* file_{ nullptr };

    friend class source_interface;
};
