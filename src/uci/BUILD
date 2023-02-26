load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "uci",
    srcs = ["uci.cpp"],
    hdrs = ["uci.hpp"],
    visibility = ["//main:__pkg__"],
    deps = [
        "@boost//:algorithm",
        "@boost//:tokenizer",
    ],
)

cc_test(
    name = "uci_test",
    size = "small",
    srcs = ["uci_test.cpp"],
    deps = [
        ":uci",
        "@com_google_googletest//:gtest_main",
    ],
)
