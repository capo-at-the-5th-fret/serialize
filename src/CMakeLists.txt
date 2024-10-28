add_library(serialize STATIC)

target_sources(serialize
    PUBLIC
        FILE_SET CXX_MODULES
        FILES
            serialize.cxx
            writer.cxx

            endpoint/endpoint.cxx
            endpoint/file_endpoint.cxx
            endpoint/stream_endpoint.cxx
    )
target_compile_features(serialize PUBLIC cxx_std_23)
