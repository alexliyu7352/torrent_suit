



aux_source_directory(. SRC_PROTO)

add_library(
        pb_conf
        ${SRC_PROTO}
)


INSTALL(TARGETS pb_conf ARCHIVE DESTINATION lib)



