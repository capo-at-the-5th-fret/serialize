module;

#include <cstddef>

export module serialize:endpoint;

export class sink_interface
{
public:
    template <typename Self>
    void write_data(this Self&& self, void const* data, std::size_t size)
    {
        self.write_data_impl(data, size);
    }

    template <typename Self>
    void flush(this Self&& self)
    {
        self.flush_impl();
    }

protected:
    sink_interface() = default;
};

export class source_interface
{
public:
    template <typename Self>
    void read_data(this Self&& self, void* data, std::size_t size)
    {
        self.read_data_impl(data, size);
    }

protected:
    source_interface() = default;
};
