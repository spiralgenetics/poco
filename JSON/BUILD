cc_library(
    name = "JSON",
    srcs = glob([
        "src/*.h",
        "src/*.inc",
        "src/*.cpp",
        "src/*.c",
    ]),
    hdrs = glob(["include/**/*.h"]),
    copts = [
        "-Wno-sign-compare",
        "-Wno-unknown-pragmas",
        "-Wno-format-truncation",
        "-D_XOPEN_SOURCE=500",
        "-D_REENTRANT",
        "-D_THREAD_SAFE",
        "-D_FILE_OFFSET_BITS=64",
        "-D_LARGEFILE64_SOURCE",
        "-DPOCO_HAVE_FD_EPOLL",
    ],
    includes = ["include"],
    visibility = ["//visibility:public"],
    deps = ["//Foundation"],
)
